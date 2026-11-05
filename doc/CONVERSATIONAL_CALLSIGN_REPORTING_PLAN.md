# Conversational Callsign Detection & Reporting Plan

Status: **implemented** — extractor/aggregator in `lib/conv/ConversationalCallsignReporter.*`, integrated into RTTY/PSK31/CW/JTTY decode paths.

Scope: detect callsigns in free-text RTTY, PSK31, CW and JTTY decodes and
report them to PSKReporter and the WSJT-X local UDP interface.

## 1. Goals and decisions

### Modes

- RTTY
- PSK31
- CW
- JTTY (currently reports nothing)

### What to report

- `CQ <call>`
- `CQ DX <call>` / `CQ TEST <call>` / other CQ modifiers
- `CQ CQ DE <call>`
- `QRZ <call>` / `QRZ DE <call>`
- Directed exchanges: `<other> DE <me>` → spot the **DE call**, i.e. the
  first valid callsign **after** `DE` (the station transmitting)

Examples:

| Text | Spotted call |
|---|---|
| `CQ WA4YA` | `WA4YA` |
| `CQ DX K8S` | `K8S` |
| `CQ EA8/K1ABC` | `EA8/K1ABC` |
| `CQ CQ DE N0CALL` | `N0CALL` |
| `WA4YA DE AI5DD` | `AI5DD` |
| `QRZ DE K1ABC` | `K1ABC` |

No bare-call spotting.

A valid callsign has **at least 3 characters** (e.g. `K8S`) and a
**1- or 2-digit number group**. Two-digit groups are valid for special-event
calls (`DP75HSC`, `DP75HSIN`, `LP75HSC`) and must **not** be rejected: a
high-probability/high-score decode is likely correct. Use the Maidenhead
grid check as corroboration — those special-event calls cannot be valid
Maidenhead grids, which increases confidence in the callsign interpretation.
Compound calls (`EA8/K1ABC`, `W1AW/P`, `K1ABC/QRP`) are supported; the UDP
report carries the full compound string.

### Repeat policy

- Correctness is more important than avoiding duplicates.
- Every reliable occurrence of a callsign is reported again.
- **No local deduplication for the local UDP interface.**
- PSKReporter's existing 5-minute per-call cache is relied on for server-side
  repeat suppression.
- A weak/first observation is not reported unless it passes the high-confidence
  single-shot gate (section 6).

### UDP message format

Use the standard WSJT-X UDP `Decode` message (type 2), which is also what
JS8Call uses. `message_text` is synthesized as `CQ <CALL>` (optionally
`CQ <CALL> <GRID>`), so FT8-style consumers can parse the callsign in the
standard CQ position. The real top-level mode (`RTTY`, `PSK31`, `CW`, `JTTY`)
is carried in the message's `mode` field.

## 2. JTTY, JS8Call and upstream WSJT-X

### Upstream WSJT-X release/3.3

Upstream has a full JTTY receive path (`JttyDecoder`,
`JttyReceiveResultController`, `mainwindow_jtty_receive.cpp`, ...):

- JTTY **does** report to PSKReporter. `ReceiveResultController::apply()`
  emits a `Spot` when `terminal == Complete`, and
  `mainwindow_jtty_receive.cpp` calls:

  ```cpp
  m_psk_Reporter.addRemoteStation(spot.sender, spot.grid, spot.frequency,
                                  spot.mode, spot.snr, spot.time);
  ```

- JTTY does **not** send the WSJT-X UDP `Decode` message (there is no
  `MessageClient::decode` in the JTTY path).
- Upstream spot rule:
  - split the complete line;
  - `fields[0]` must be `CQ`, `DE`, or a standard callsign;
  - `fields[1]` must be a standard callsign;
  - spot `fields[1]` as the sender;
  - optional `fields[2]` is the grid if it matches the Maidenhead pattern;
  - frequency = `context.periodFrequency + update.frequency`;
  - time = `context.sequenceStart.toUTC()`;
  - self-spots filtered;
  - gated on `spot_to_psk_reporter()`.
- It uses `Radio::is_standard_callsign()`, which is strict: max 3-letter
  suffix, only `/R`/`/P`, rejects 2-digit number groups and compound
  prefixes such as `EA8/K1ABC`. **We do not adopt this gate**; see the
  reporting split below.
- No multi-period aggregation or fuzzy matching; JTTY text is treated as
  structured.

### JTTY in this tree

Our fork has an older/simplified JTTY receive path in `mainwindow_jtty.cpp`
and does not contain `mainwindow_jtty_receive.cpp` or
`ReceiveResultController`. It currently reports nothing.

Plan: port/adapt the upstream PSKReporter spot **mechanics** for JTTY, but
use our own callsign validation, and add the missing local UDP reporting.
The broader aggregator below is still needed for free-text RTTY/PSK31/CW.

### Reporting split (final)

**Design principle: all four modes use the same callsign validation and
reporting rules.** Upstream is a reference for JTTY line mechanics and
PSKReporter plumbing, not for callsign validity. We deliberately deviate
from upstream where our rules produce a better product: two-digit
special-event calls, compound calls and broader prefixes are all supported.

- **JTTY PSKReporter:** port upstream's structured spot mechanics — complete
  line, sender selection, optional grid, frequency/time, self-spot filter and
  `spot_to_psk_reporter()` gating — but validate the sender with our shared
  callsign rules, **not** `Radio::is_standard_callsign()`. Spot two-digit
  special-event and compound calls normally.
- **RTTY / PSK31 / CW PSKReporter:** reuse the upstream `PSKReporter`
  implementation and `pskPost()` gating as much as possible
  (`spot_to_psk_reporter()`, disk-data and self-spot checks). The callsign
  aggregator described in this document supplies the callsign, grid,
  frequency, mode, SNR and time. Validation is the same shared validator.
- **UDP (all modes):** synthesized `CQ <CALL>` message text, top-level mode,
  frequency, SNR, time. Compound calls are supported and the full compound
  string is emitted. No local deduplication.
- **JTTY UDP:** use the same structured sender detection plus the broader
  DE-call extractor for `<to> DE <from>` messages. Same validation as the
  JTTY PSKReporter path; there are no UDP-only callsign rules.
- **Compound calls:** accepted in all modes for both sinks (PSKReporter and
  UDP); the full compound string is reported.

### JS8Call reference

The referenced JS8Call commit adds the WSJT-X UDP protocol to JS8Call:

- `WSJTXMessageClient` implements the WSJT-X UDP messages.
- `WSJTXMessageMapper::sendDecode()` forwards JS8Call's `mode` and decoded
  message text through:

  ```cpp
  MessageClient::decode(is_new, time, snr, delta_time, delta_frequency,
                        mode, message_text, low_confidence, off_air);
  ```

The wire protocol is identical to WSJT-X's FT8 `Decode` message. The difference
is the `message_text` payload: JS8Call sends a structured JS8 frame, whereas
RTTY/PSK31/CW/JTTY text is free-form.

Comparison:

- Upstream JTTY reports PSKReporter only; JS8Call sends both PSKReporter (via
  its own path) and WSJT-X UDP `Decode`.
- Both use the same WSJT-X `PSKReporter` class and the same UDP `Decode` wire
  message.
- Our plan adds the UDP `Decode` reporting that upstream JTTY lacks, using a
  synthesized `CQ <CALL>` text.

## 3. CW Skimmer evaluation

Repository inspected: `https://github.com/JvanKatwijk/cwskimmer`

Findings:

- It is an experimental receiver that computes 48 CW bins and decodes Morse
  elements into letters.
- It contains **no callsign extraction, callsign tracking, fuzzy matching or
  spotting logic**.
- Its per-bin decoder is also weaker than the existing GridTracker/DeepCW
  decoders.

Conclusion: nothing to reuse for callsign detection. The algorithm below is
new.

## 4. Candidate extraction (per completed message)

Only run on a **completed** message (idle/gap completion), not on every
character/partial update.

### Normalization

1. Uppercase.
2. Strip `<>`, surrounding punctuation and redundant whitespace.
3. Tokenize on whitespace.

### Source-call selection

- Find the first valid callsign after `DE`, if a `DE` token exists.
- Otherwise find the first valid callsign after `CQ`/`QRZ`, skipping modifiers:
  `CQ`, `QRZ`, `DX`, `TEST`, `NA`, `EU`, `AS`, `AF`, `SA`, `OC`, `DE`, `QRP`,
  `LOW`, `HIGH`, `UP`, `DOWN`, `PORT`, `MOBILE`, `MM`, `AM`, ...
- If no CQ/QRZ/DE source is found, no candidate is produced.

The source call is the **transmitting station**:
- `CQ <call>` → `<call>`
- `CQ DE <call>` → `<call>`
- `<other> DE <call>` → `<call>`
- `QRZ DE <call>` → `<call>`

### Cheap validation gate

- A valid callsign needs **at least 3 characters** and a **1- or 2-digit
  number group**. Example: `K8S` (letter + `8` + letter).
- Prefix digits are allowed before the number group (`9A1A`, `2E0ABC`,
  `A45AA`, `4X4AA`).
- Suffix is 1–4 letters.
- Two-digit number groups are valid special-event calls and are **not**
  rejected. `DP75HSC`, `DP75HSIN` and `LP75HSC` are legitimate candidates.
- Compound calls are supported:
  - the full token must match `^[A-Z0-9/]{3,11}$`;
  - split on `/` and validate the base component using the same rule as
    `Radio::base_callsign()` (longest component);
  - report the **full compound string** (e.g. `EA8/K1ABC`, `W1AW/P`,
    `K1ABC/QRP`).
- Base regex (allowed prefix form, then a 1–2 digit number group, then 1–4
  suffix letters):

  ```
  ^(?:[A-Z]{0,2}|[A-Z][0-9]|[0-9][A-Z])[0-9]{1,2}[A-Z]{1,4}$
  ```

  The prefix is one of:
  - zero to two letters (`K`, `WA`, `VP`),
  - one letter followed by one digit (`A4`, `P2`, `T8`),
  - one digit followed by one letter (`9A`, `2E`, `3D`, `4X`).

  Accepts: `K8S`, `N0CALL`, `K6XX`, `WA4YA`, `AI5DD`, `JO2QOT`, `DP7S`,
  `9A1A`, `2E0ABC`, `3D2ABC`, `A45AA`, `4X4AA`, `VP2E`, `P29XX`,
  `DP75HSC`, `DP75HSIN`, `LP75HSC`.

  Rejects: bare prefixes with no suffix letter (e.g. `EA8`), pure reports
  and blocklisted words.

- Maidenhead grid corroboration:
  - Use the 4/6-character Maidenhead regex for grids.
  - A token that **cannot** be a valid grid (length > 6, or non-grid
    structure, e.g. `DP75HSC`, `DP75HSIN`, `LP75HSC`) gets a confidence
    boost as a callsign.
  - A token that also matches a valid 6-character grid (e.g. `DP75HS`) is
    ambiguous; context (CQ/DE) and the multi-message score decide.
  - Never emit a grid-pattern token as a grid and a callsign from the same
    occurrence.

- Reject RST/report forms: `599`, `5NN`, `57N`, `56N`, `55N`, … via
  `^[1-5][1-9][1-9]$`, `^[1-5][1-9]N$`, `^5NN$`.
- Reject blocklist words: `CQ`, `QRZ`, `DE`, `DX`, `TEST`, `TU`, `73`, `88`,
  `R`, `RR`, `K`, `KN`, `BK`, `AR`, `SK`, `QSL`, `QTH`, `QRP`, `QSY`, `AGN`,
  `PSE`, `UR`, `ES`, `FB`, `GE`, `GM`, `GA`, `HSC`, `CMT`, `LP`, `RST`, ...
- Reject my own call and `Radio::base_callsign(myCall)`.

The regex is only a **gate**. Correctness comes from multi-message
aggregation.

### Parsing a candidate

Parse from the right:

- `suffix`: trailing letters after the number group;
- `numberGroup`: the 1–2 digit number group before the suffix;
- `prefix`: everything before the number group.

To disambiguate calls where digits can belong to the prefix, choose the
**longest valid prefix form** first:
- zero to two letters (`K`, `WA`, `VP`),
- letter + digit (`A4`, `P2`, `T8`),
- digit + letter (`9A`, `2E`, `3D`, `4X`),

then take the following 1–2 digits as the number group.

Examples:

| Call | prefix | number group | suffix |
|---|---|---|---|
| `K8S` | `K` | `8` | `S` |
| `WA4YA` | `WA` | `4` | `YA` |
| `9A1A` | `9A` | `1` | `A` |
| `2E0ABC` | `2E` | `0` | `ABC` |
| `A45AA` | `A4` | `5` | `AA` |
| `VP2E` | `VP` | `2` | `E` |
| `P29XX` | `P2` | `9` | `XX` |
| `DP75HSC` | `DP` | `75` | `HSC` |

For compound calls, parse the base call for clustering and keep the full
raw call for reporting.

### Grid

Record the first token matching the Maidenhead regex as optional corroboration:

```
\A(?![Rr]{2}73)[A-Ra-r]{2}[0-9]{2}([A-Xa-x]{2}){0,1}\z
```

## 5. Per-frequency observation tracks

- One track per `mode + frequency`.
- Match a new observation to the nearest track within ~50–75 Hz; update the
  track frequency with an EMA.
- Separate tracks per mode (RTTY/PSK31/CW/JTTY).
- Keep the **last 5 completed messages/mentions** per track (maximum age ~60 s).
- Retire a track after ~60 s without observations.

Each observation stores:

```
raw call, prefix, number group, suffix,
audio frequency, SNR, context (CQ/QRZ or DE),
grid present, occurrence count, timestamp, observation score
```

## 6. Observation score and confidence

### Observation score

| Component | Contribution |
|---|---|
| Valid base call | 0.35 |
| Suffix length >= 2 (less likely truncation) | +0.20 |
| CQ/QRZ context | +0.25 |
| DE context | +0.20 |
| SNR normalized (-20…+20 dB) | up to +0.15 |
| Optional grid present elsewhere in the message | +0.05 |
| Cannot be a valid Maidenhead grid (e.g. length > 6) | +0.10 |
| Matches a valid 6-character grid (ambiguous) | -0.10 unless CQ/DE context |
| Same call repeated within the message | +0.05 and occurrence count |

Cluster score = recency-weighted sum of member observation scores.

### Single-shot high-confidence report

A first observation may be reported immediately only when all hold:

- the base call is valid (standard or two-digit special-event call);
- suffix length >= 2;
- CQ/QRZ or DE context;
- SNR >= 2 dB;
- a two-digit special-event call is not also a valid 6-character grid;
- the candidate is not a strict prefix of a longer candidate in the same
  message;
- or the same source call is repeated at least twice in the message with
  CQ/DE context (repetition substitutes for the SNR threshold, e.g.
  `CQ ... DE W1AW/4 W1AW/4`).

All other candidates wait for the 5-message/occurrence window.

### High confidence from aggregation

A cluster may be reported when:

- support >= 3 occurrences; or
- support >= 2 with a high cluster score; or
- the single-shot gate above is satisfied.

Support counts **every occurrence** of the call, including repeated occurrences
inside one completed message and occurrences in later messages. Bare calls are
not spotted on their own, but a bare occurrence at the same frequency that
matches a source-confirmed CQ/DE track adds support and can trigger the report.
This covers calls that cross message boundaries without allowing bare-only
spotting.

A 1-character suffix representative requires support >= 3 (truncation guard).
If a longer-suffix member of the same cluster has >= 2 observations, prefer the
longer member.

## 7. Fuzzy clustering and representative selection

### Clustering rule

- Cluster only when `prefix` and the 1–2 digit number group match
  **exactly**. This prevents merging different stations such as `WA4YA` and
  `WB4YA`.
- Fuzzy-match the `suffix` with Levenshtein distance.
- Similarity = `1 - edit_distance / max(length)`.
- Accept a cluster when similarity >= 0.6.
- Truncated/extended suffixes (`Y`, `YA`, `YAD`) cluster.

### Representative

Choose the cluster **medoid** — an actually decoded string, not a synthetic
consensus:

```
representative = argmax_o sum_p(similarity(o, p) * score(p))
```

Tie-break order:

1. higher individual score;
2. more observations;
3. longer suffix;
4. earlier observation.

### Worked example

Observations for one frequency:

| Observation | Score | Note |
|---|---|---|
| `WA4YA` | high | twice |
| `WA4YAD` | medium | once |
| `WA4Y` | medium | once |

All share prefix `WA`, digit `4`, and cluster on suffix `Y`/`YA`/`YAD`.
The medoid is **`WA4YA`**.

## 8. Reporting

Run once per decode batch, **not once per pane**, after `takeUpdates()`:

```cpp
reportConversationalDecodes(updates, mode, timeFn);
```

Process only `update.complete` updates.

For every completed message where a reliable representative is present:

### PSKReporter

- Skip if `m_diskData`.
- Skip if `!m_config.spot_to_psk_reporter()`.
- Skip my own call.

```cpp
m_psk_Reporter.addRemoteStation(
    representative,                     // call
    grid.isEmpty() ? QString{} : grid,  // grid, empty allowed
    m_freqNominalPeriod + audioFreq,    // dial + audio offset
    mode,                               // RTTY/PSK31/CW/JTTY
    snr,
    spotTime);
```

PSKReporter already suppresses repeats per call for 300 s.

Reporting source per mode:

- **JTTY:** use upstream's structured line mechanics on a complete line
  (`fields[0]` source context, spot the `fields[1]` sender, optional
  `fields[2]` grid), but validate with our shared rules. Do not apply
  upstream's strict `is_standard_callsign()` gate; two-digit special-event
  and compound calls are reported. Aggregation is not required for a
  complete JTTY line.
- **RTTY / PSK31 / CW:** use the aggregator's reliable representative as the
  call, with the optional grid from the message. Reuse the upstream
  `PSKReporter` class and the same gating and shared validation.
- **Compound calls:** pass the full compound string
  (e.g. `EA8/K1ABC`, `W1AW/P`) as the call in all modes.

### Local WSJT-X UDP

No local deduplication.

```cpp
m_messageClient->decode(
    true,                // is_new
    spotTime.time(),     // UTC
    snr,
    0.0f,                // delta_time
    audioFreq,           // delta_frequency
    mode,                // RTTY/PSK31/CW/JTTY
    "CQ " + representative + (grid.isEmpty() ? "" : " " + grid),
    false,               // low_confidence
    m_diskData);         // off_air
```

The synthesized `CQ <CALL>` text is FT8/WSJT-X-parser friendly and supports
compound calls (e.g. `CQ EA8/K1ABC`). If a JS8-style frame is ever required,
that needs a separate formatter.

### Fields

- **Time:** the completed message's start time, converted to UTC with the
  existing `jttyLineDateTimeUtc` lambdas.
- **Frequency:** `m_freqNominalPeriod + update.frequency` (the channel audio
  offset), matching `pskPost()`.
- **Mode:** top-level only: `RTTY`, `PSK31`, `CW`, `JTTY`.
- **SNR:** `update.snr`.

## 9. Integration points

Call the reporting helper once per decode batch:

- `rtty_decode()`
- `psk_decode()`
- `cw_decode()`
- `jtty_decode()`

Do not report inside the per-pane loops (All Decodes/QSO) to avoid duplicate
reports.

Skip replay/old lines and disk data for PSKReporter; set the UDP `off_air`
flag for disk data.

## 10. Data structures (suggested)

```cpp
struct CallObservation {
    QString raw;
    QString prefix;
    QString numberGroup;
    QString suffix;
    double frequency;
    int snr;
    bool cqContext;
    bool deContext;
    bool gridPresent;
    QDateTime time;
    double score;
};

struct CallCluster {
    QString prefix;
    QString numberGroup;
    QVector<CallObservation> observations;
    double score;
    QString representative;
};

struct FrequencyTrack {
    QString mode;
    double frequency;
    QVector<CallObservation> recent; // last 5 completed messages
    QDateTime lastSeen;
};
```

## 11. Tests

Extractor/aggregator unit tests (no network, mock reporting sinks):

- `WA4YA` / `WA4YAD` / `WA4Y` → `WA4YA`.
- `CQ WA4YA`
- `CQ DX K8S` → `K8S` (shortest valid call).
- `CQ CQ DE N0CALL`
- `WA4YA DE AI5DD` → `AI5DD` only.
- `QRZ DE K1ABC`
- Prefix digits: `9A1A`, `2E0ABC`, `A45AA`, `4X4AA` accepted.
- Two-digit special-event calls accepted: `DP75HSC`, `DP75HSIN`,
  `LP75HSC` (they cannot be valid Maidenhead grids; grid comparison boosts
  confidence).
- Ambiguous six-character token (`DP75HS`) matches a valid grid; context
  (CQ/DE) and aggregation decide.
- Report tokens rejected (`599`, `5NN`, `57N`).
- Blocklist words rejected (`HSC`, `CMT`, `TU`, `73`).
- Compound calls accepted and reported in full: `W1AW/P`, `EA8/K1ABC`,
  `K1ABC/QRP`.
- JTTY PSKReporter uses our rules, not upstream's strict check:
  `CQ K1ABC FN42` spots `K1ABC`; `CQ DP75HSC FN42` spots `DP75HSC`;
  `CQ EA8/K1ABC` is accepted and the full compound string is reported.
- UDP output carries the full compound call and two-digit special-event
  call in `CQ <CALL>` for all modes.
- Self-call rejection.
- Frequency-track separation: same call on two frequencies remains two tracks.
- Truncation guard: `WA4Y` alone does not single-shot report.
- 2 dB single-shot threshold: `CQ WA4YA` at 2 dB reports; at 1 dB it waits.
- Repeated source call below the SNR gate:
  `K CQ BISU DE W1AW/4 W1AW/4` reports `W1AW/4`.
- Occurrence support inside one message: `CQ WA4Y WA4Y WA4Y` reports after
  three occurrences without waiting for three cycles.
- Cross-boundary corroboration: a bare `W1AW/4` in a later message supports a
  source-confirmed `CQ W1AW/4` track and triggers the report.
- Bare-only calls are not spotted: `TU W1AW/4 W9APN` alone reports nothing.

Then:

- Build `wsjtx` / `jt9`.
- Run `ctest -R "cw|rtty|psk"`.
- Pi build and test.

## 12. Notes and risks

- Free-text spotting is noisier than FT8; the CQ/DE-only policy, the
  prefix + number-group exact clustering and the medoid consensus are the
  guardrails.
- Two-digit number groups are valid special-event calls and must not be
  rejected; use the Maidenhead grid comparison as corroboration.
- Compound calls are supported for extraction, PSKReporter and UDP
  reporting in all modes.
- We deliberately deviate from upstream JTTY's strict
  `Radio::is_standard_callsign()`: all modes use the broader shared
  validator, so JTTY PSKReporter also spots two-digit special-event and
  compound calls. Upstream would reject some of these.
- Do not report on a single weak/truncated observation unless the source
  call is repeated in a CQ/DE message or a later bare occurrence corroborates
  a source-confirmed track.
- Occurrence counts include repeats within one message, so support is not
  limited to one observation per decode cycle.
- PSKReporter accepts an empty grid (as FT8 CQ spots do).
- The UDP message text is synthetic `CQ <CALL>`; the real decoded text is not
  forwarded.
- JTTY currently has no reporting; this plan adds it.
- Keep the aggregator independent of the existing FT8 `DecodedText` path.
