# PSK31 Multichannel Decoder Implementation Plan

Status: implemented locally. Phase 1 is an fldigi-style fixed-slot browser.
Phase 2 evolves the same detector into a dynamic carrier tracker.

Implementation defaults now used by the code:

- `PskBrowser` in `lib/psk/psk_browser.cpp` owns the primary decoder and a
  sparse set of browser channels.
- Default mode is `FixedSlots`, 30 equal slots across the waterfall passband.
- Browser defaults on; UI exposes `Browser`, `Ch` and `Dynamic`.
- Carrier detection uses an 8192-point FFTW frame and a 31.25 Hz moving
  average; frequency is the centre of the shaped spectral group.
- Acquisition uses a sparse probe bank around each detected carrier and then
  keeps one `PskModem` per active carrier.
- Dynamic mode uses local-maximum candidates, valley-split groups,
  frequency-sorted association, and a 32-carrier cap.
- The selected RX tone is always decoded by channel 0 and is not retired by
  browser timeouts.
- Tests: `test_psk_decoder` and `test_psk_multichannel`.

Audience: an agent/developer with the WSJT-X/WS source, basic PSK DSP
knowledge, and access to the local `fldigi/` checkout in this repository.

## 1. Problem statement

PSK31 reception in WS currently has two failure modes:

1. A single decoder must be tuned close to the signal. `PskModem` needs the
   carrier within roughly +/-0.5 Hz for a full decode; its AFC does not recover
   reliably from a 10 Hz error.
2. The old `PskMultiDemod` used 128 fixed channels over the whole waterfall
   (0–5000 Hz). That gives ~39 Hz channel spacing, so most PSK31 signals fall
   between channels. The result is one partial decode followed by garbage, or
   only garbage.
3. A temporary narrow ±10 Hz bank fixed the offset problem but reduced the
   decoder to one signal region. That is not acceptable: WS needs true
   passband multichannel reception.

The decoder must find and decode multiple PSK31 signals anywhere in the audio
passband without instantiating thousands of demodulators.

## 2. Current WS code and constraints

Relevant files:

- `PskDecoder.hpp/.cpp`
  - Public wrapper used by `MainWindow::psk_decode()`.
  - Owns text/update state, completion buffering, rewind and dedup.
- `lib/psk/psk_multi_demod.hpp/.cpp`
  - Current fixed 128-channel grid.
- `lib/psk/psk_modem.hpp/.cpp`
  - PSK31/QPSK demodulator. RX sample rate: 12 kHz. TX: 48 kHz.
  - Needs a close carrier estimate; AFC is limited.
- `lib/psk/psk_varicode.*`, `psk_viterbi.*`
  - Character/FEC decoding.
- `widgets/mainwindow_jtty.cpp`
  - `psk_decode()`, `on_actionPSK31_triggered()`, PSK mode UI/reset,
    callsign reporting and QSO/All Decodes rendering.
- `widgets/mainwindow.h`
  - PSK decoder, TX streaming and session state.
- `tests/unit/psk/`
  - `test_psk_modem.cpp`, `test_psk_varicode.cpp`, `test_psk_decoder.cpp`.

Current key design decisions to preserve:

- RX audio is 12 kHz.
- TX audio is 48 kHz.
- `Psk::Decoder::rewind()` must keep DSP state across a decode-period sample
  wrap. Do not revert to a full reset per period.
- `Psk::Decoder` completion buffering selects the best duplicate completion.
- PSK mode entry and replay reset the decoder session.
- The selected RX tone must always have a decoder so the QSO pane continues to
  work even while the browser searches the passband.
- `psk_decode()` feeds all decoder updates into All Decodes; the QSO pane
  filters by selected RX frequency.
- Callsign reporting consumes completed `Jtty::MessageUpdate`s.

Starting-state warning:

- Commit `eef9995` contains a temporary ±10 Hz narrow PSK range.
- The working tree may already contain the revert to:
  ```cpp
  int const nfa = m_wideGraph->nStartFreq();
  int const nfb = m_wideGraph->Fmax();
  ```
- If starting from `eef9995`, revert that specific change first. The browser
  must receive the full waterfall range.

## 3. What fldigi does

Local checkout: `fldigi/`.

Key files:

- `fldigi/src/psk/viewpsk.cxx`
- `fldigi/src/include/viewpsk.h`
- `fldigi/src/psk/pskeval.cxx`
- `fldigi/src/widgets/psk_browser.cxx`
- `fldigi/src/include/configuration.h`

Facts from the code:

- The main fldigi PSK modem is a single-signal decoder at the waterfall
  cursor.
- The PSK **Signal Browser** is a separate true multichannel decoder.
- `viewpsk.cxx` comments: complete audio spectrum, equal 100 Hz channels,
  up to 30 channels.
- `MAXCHANNELS = 30`.
- Default `VIEWERchannels = 30`; `pskbrowser_on = true`.
- The browser scans `LowFreqCutoff` to `HighFreqCutoff` (defaults 0–3000 Hz,
  commonly configured around 300–3000 Hz).
- Per channel:
  - independent NCO/mixer,
  - FIR filters,
  - bit clock,
  - DCD/squelch,
  - AFC,
  - Varicode/Viterbi decoding,
  - timeout/reset state.
- `rx_process()` processes only channels whose `frequency != NULLFREQ`.
- `findsignals()`:
  - examines one 100 Hz slot at a time,
  - calls `pskeval::peak()` on waterfall FFT power,
  - estimates the carrier frequency inside the slot,
  - rejects detections inside the neighboring channel's bandwidth,
  - assigns the frequency and starts acquisition.
- `afc()` clamps tracking to the slot boundaries.
- `timeout_check()` retires inactive channels.
- `VIEWER_psksquelch` controls the browser squelch.
- `pskbrowser_on` exists specifically so slow CPUs can disable multichannel
  decoding.

This is the proven first implementation to copy conceptually.

## 4. CPU facts measured on the Pi 5

Measured with the existing `PskMultiDemod` and synthetic PSK-like audio:

| Active `PskModem` channels | Approx. CPU on Pi 5 |
|---:|---:|
| 1 | ~0.06% of one core |
| 30 | ~2% |
| 60 | ~4% |
| 128 | ~8–10% |
| 512 | ~30–40% |
| 10,000 | ~600% (not viable) |

Therefore:

- A fixed 30-slot browser is cheap on a Pi 5.
- 60 slots at 50 Hz spacing is still affordable.
- A dense full-passband static grid is not viable.
- Detection must be sparse/active-channel based.

## 5. Phase 1: fldigi-style fixed-slot browser

### 5.1 Goal

Cover the full PSK passband with 30 coarse slots (default 100 Hz each), detect
one real signal per slot, and run one `PskModem` only for active slots. Keep
the selected RX tone as a separate primary decoder.

Default layout:

```text
primary decoder: selected RX tone (always active)
browser slots:   30 slots x 100 Hz across [lowFrequency, highFrequency]
```

Optionally make this configurable:

```text
browser channels: 30 (default), 60 possible
slot width:       100 Hz (default), 50 Hz possible
```

A slot is not a decoder. A slot is only a search region. A `PskModem` exists
only after a carrier is detected.

### 5.2 Components

Add:

#### `lib/psk/psk_carrier_detector.hpp/.cpp`

Self-contained carrier detector. Qt-free. Use FFTW single precision.

Proposed interface:

```cpp
namespace Psk {

struct CarrierCandidate {
    double frequency;   // Hz
    double power;       // linear or dB, implementation-specific
    double metric;      // peak above local noise floor
};

class CarrierDetector {
public:
    CarrierDetector(double sampleRate = 12000.0);
    ~CarrierDetector();

    void configure(int fftSize = 4096, int hopSize = 2048,
                   double noiseDecay = 0.05);
    void reset();

    // Feed audio. Retains an internal history/overlap buffer.
    void process(const int16_t* samples, int count);

    // Returns candidates for the most recent analysis window.
    // Phase 1 policy: at most one candidate per caller-defined slot.
    std::vector<CarrierCandidate> candidates() const;

    // Peak finder usable by both phases.
    bool peakInRange(double lowHz, double highHz,
                     CarrierCandidate& result) const;
};

}
```

Implementation:

1. Maintain a ring buffer of at least `fftSize` samples.
2. Apply a Hann window.
3. Optionally zero-pad 2x or 4x before FFTW to improve frequency
   interpolation.
4. Compute magnitude/power.
5. Maintain an adaptive noise floor:
   - median of a quiet subset, or
   - exponential average of per-bin/background power.
6. For a frequency range:
   - find the maximum bin,
   - require it above the local noise floor by the configured threshold,
   - parabolic interpolation around the peak for a sub-bin frequency
     estimate,
   - return frequency/power/metric.

Target frequency accuracy for Phase 1:

- Ideally < 0.5 Hz so one `PskModem` can lock.
- With 4096 samples at 12 kHz and zero padding/interpolation this is
  achievable.
- If it is not reliable, use the fine-acquisition fallback below.

FFTW portability:

- Reuse the same single-precision header pattern already used by DeepCW:
  ```cpp
  #if defined(__has_include)
  #  if __has_include(<fftw3f.h>)
  #    include <fftw3f.h>
  #  else
  #    include <fftw3.h>
  #  endif
  #else
  #  include <fftw3.h>
  #endif
  ```
- `find_package(FFTW3 COMPONENTS single REQUIRED)` is already used by the
  project.
- Add the detector source to the executable and test source lists.

#### `lib/psk/psk_slot_browser.hpp/.cpp`

Browser/slot manager. It owns:

```cpp
struct BrowserSlot {
    double slotLow;
    double slotHigh;
    double frequency;       // detected/assigned frequency
    bool active;
    std::unique_ptr<PskModem> modem;
    qint64 lastSignalSample;
    double bestMetric;
};

class SlotBrowser {
public:
    void configure(double sampleRate, int lowHz, int highHz,
                   int channels, double slotWidthHz);
    void setBaud(double baud);
    void setQpsk(bool qpsk);
    void setReverse(bool reverse);
    void setSquelch(double squelch);
    void reset();

    void process(const int16_t* samples, int count);

    struct Result {
        int slot;
        double frequency;
        std::string text;
        double snr;
        bool complete;
    };
    std::vector<Result> takeResults();

    std::vector<double> activeFrequencies() const;
};
```

Slot behavior:

1. `configure()` computes `channels` slots across the passband:
   - `slotWidth = (high - low) / channels` unless explicitly supplied.
   - default 30 slots, 100 Hz.
2. On each audio chunk:
   - Run `CarrierDetector::process()` at a controlled rate
     (e.g. every 1024 or 2048 samples).
   - For each slot:
     - If a modem is active, feed it every audio chunk and track AFC.
     - If inactive and no neighbor modem owns this signal, search for a
       peak inside the slot.
     - On a valid peak:
       - estimate frequency,
       - create/reinitialize a `PskModem`,
       - set baud/QPSK/reverse/squelch,
       - set frequency and `rxInit()`,
       - mark active and set acquisition/hang counters.
     - If active but no output/SNR for the timeout period, retire.
3. Neighbor suppression:
   - If an adjacent slot has an active modem whose frequency is within
     `signalBandwidth` (PSK31 ~31.25 Hz), do not start another.
4. Do not process inactive slots.
5. Keep maximum active channels bounded by the slot count.

#### Fine acquisition fallback

Because WS `PskModem` needs a close carrier, add a deterministic fallback:

- When a peak is detected, run **probe modems** at:
  - estimated frequency,
  - estimated ±2.5 Hz,
  - estimated ±5 Hz.
- Run each probe for ~0.5 s (or a fixed number of symbols).
- Choose the probe with the highest `metric()/SNR`, then keep only that modem
  as the slot decoder.
- This costs at most a few modems for a short acquisition window and avoids
  permanently allocating a dense fine bank.

Do not run the probe bank forever. Once locked, use one modem per slot.

### 5.3 Keep the primary selected-tone decoder

`Psk::Decoder` must always decode `centerFrequency` independently of browser
slots.

Implementation options:

Preferred:

- `Psk::Decoder` owns:
  - one primary `ChannelState` + primary `PskModem`,
  - one `SlotBrowser`.
- Primary channel ID = 0.
- Browser results are mapped to internal channel IDs `1..N`.
- Primary is fed every chunk and is never retired by browser timeout.

This preserves the QSO pane and gives the user a guaranteed decoder on the
tuned signal.

### 5.4 Integration with `Psk::Decoder`

Keep the existing public API:

```cpp
void begin(...);
void rewind(qint64 firstSearch = 0);
void setSubmode(...);
void setReverse(...);
void setSquelch(...);
int process(...);
QVector<Jtty::MessageUpdate> takeUpdates();
```

Changes:

- Replace the single `PskMultiDemod` ownership with:
  - primary `PskModem`,
  - `SlotBrowser browser_`,
  - combined channel state vector.
- `process()`:
  1. Feed the primary modem at `centerFrequency`.
  2. Feed the browser with the same audio.
  3. Merge results into the existing `ChannelState` / completion-buffer path.
  4. Preserve `rewind()` semantics: continue state; do not reset.
- `setSubmode()` applies baud/QPSK to both primary and browser.
- `setReverse()` / `setSquelch()` apply to both.
- `begin()` / reset clears primary, browser, completion buffer and text state.
- `takeUpdates()` remains unchanged in shape.

Keep `text_quality()` and completion buffering. Browser dedup must select one
completion per signal region; `flushCompleted()` remains useful.

Important: browser slots may produce partial/garbage text while searching.
Only emit completed text after the existing idle window, then apply quality
selection.

### 5.5 MainWindow integration

In `widgets/mainwindow_jtty.cpp`:

- Ensure `psk_decode()` passes the **full** waterfall range:
  ```cpp
  int const nfa = m_wideGraph->nStartFreq();
  int const nfb = m_wideGraph->Fmax();
  ```
- Keep `m_lastPskK`, `m_pskForceReset`, windowed reset, replay reset.
- PSK mode entry resets the decoder.
- All Decodes receives all channels through existing update loop.
- QSO pane continues to filter by selected RX frequency.
- Callsign reporting receives all completed channels; no special UI action.

Settings:

Add to the PSK configuration/settings group:

```text
PSK_Multichannel=true
PSK_BrowserChannels=30
PSK_SlotWidthHz=100
PSK_BrowserSquelch=<existing/default>
```

UI:

- Add a small "Browser" checkbox and channel-count/width control in the PSK
  submode strip, or reuse the existing PSK controls area.
- Tooltip should warn that multichannel decoding costs CPU.
- If disabled, run only the primary selected-tone decoder.

Do not enable full-passband browser unless PSK mode is active.

### 5.6 Display and reporting policy

- All Decodes: one line per completed message, with its detected frequency.
- QSO pane: only messages near selected RX frequency, as today.
- If browser is disabled: only primary updates.
- Use the existing `text_quality` completion selection to avoid garbage lines.
- Callsign reporting must continue to suppress replay/windowed spots and use
  the actual detected audio frequency.

### 5.7 Phase 1 limitations

Document these explicitly:

- One signal per 100 Hz slot.
- Two PSK31 signals in the same 100 Hz slot are not both decoded.
- 30-slot default covers roughly 3 kHz.
- Frequency estimate/phase-noise may need the fine-probe fallback.
- Weak signals below the detector threshold will not be discovered; the
  selected-tone primary channel remains the fallback.

## 6. Phase 2: dynamic carrier tracker (modern delta)

Phase 2 replaces fixed one-signal-per-slot allocation with a dynamic active
carrier list. It keeps the same detector and `PskModem`, but allows multiple
signals close together and arbitrary frequencies.

### 6.1 Goals

- Decode multiple PSK31 signals in the same 100 Hz region if they are
  separated by more than the practical resolution (~20–30 Hz).
- Track carriers across frequency drift.
- Avoid static slot boundaries.
- Keep active demodulators bounded (e.g. 32–64).
- Retain the selected-tone primary decoder.

### 6.2 Detector changes

`CarrierDetector` is extended to return **all local maxima** above threshold,
not one candidate per slot:

```cpp
struct CarrierCandidate {
    double frequency;
    double power;
    double prominence;       // peak above local floor
    double bandwidthEstimate;
};

std::vector<CarrierCandidate> detectAll() const;
```

Processing:

1. Find all local maxima with prominence above threshold.
2. Non-maximum suppression:
   - remove peaks within `minSeparationHz` of a stronger peak;
   - start with `minSeparationHz = 20–25 Hz` for PSK31;
   - make this configurable/testable.
3. Frequency interpolation for sub-bin estimates.
4. Optionally refine using:
   - phase difference between adjacent FFT frames,
   - a short fine probe bank around each candidate,
   - PskModem AFC after lock.

### 6.3 Active carrier tracker

Replace `BrowserSlot` with:

```cpp
struct ActiveCarrier {
    int id;
    double frequency;
    double lastDetectionFrequency;
    std::unique_ptr<PskModem> modem;
    qint64 lastTextSample;
    qint64 lastDetectionSample;
    double bestMetric;
    int misses;
    bool acquiring;
};
```

Per detector update:

1. Get all candidates.
2. Match candidates to existing carriers:
   - nearest frequency within e.g. 8–10 Hz;
   - or predicted frequency using previous AFC/drift;
   - one candidate per carrier.
3. Update matched carriers:
   - adjust detector frequency/EMA;
   - keep modem state;
   - reset miss counter.
4. Spawn new carriers for unmatched candidates if:
   - no existing carrier within `minSeparationHz`,
   - active count < cap,
   - candidate passes threshold.
5. Retire carriers with no detections/text for a timeout.
6. Neighbor suppression uses estimated bandwidth (~31 Hz for PSK31).

Matching can be greedy nearest or a small Hungarian assignment. With <=64
carriers, greedy is sufficient and simpler.

### 6.4 Close-signal handling

The detector's ability to separate two PSK31 signals depends on FFT window
length and carrier separation.

Baseline target:

- reliably separate signals separated by **>= 25–30 Hz**;
- allow closer separations only when SNR/window length supports it;
- do not promise arbitrarily close signals.

Increase FFT window / zero-padding if tests show insufficient resolution.
Do not solve close-signal separation by adding thousands of permanent
channels.

### 6.5 CPU policy

- Primary carrier: always active.
- Max active carriers: default 32, configurable to 64.
- Retire aggressively.
- Skip detector/FFT work when no PSK mode or browser disabled.
- Benchmark on Pi 5:
  - 1, 8, 16, 32, 64 active carriers;
  - one/two/three simultaneous signals;
  - detector enabled/disabled.

Targets:

- 30 fixed slots <= 3% of one Pi 5 core.
- 64 active carriers <= 5–6%.
- No unbounded allocation per detected peak.

### 6.6 Phase 2 tests

- Two PSK31 carriers 25 Hz apart: both decode.
- Two carriers 10 Hz apart: document expected limitation.
- Three or more simultaneous carriers at different frequencies.
- Carrier frequency drift across frames: no duplicate decode, no lost text.
- New carrier appears/disappears; tracker retires correctly.
- Same candidate detected by adjacent FFT frames does not spawn duplicates.
- Cap enforcement: more candidates than cap -> strongest/oldest retained.
- Selected-tone primary still decodes independently.
- CPU benchmark on Pi 5.

## 7. Files and build changes

New files:

```text
lib/psk/psk_carrier_detector.hpp
lib/psk/psk_carrier_detector.cpp
lib/psk/psk_slot_browser.hpp
lib/psk/psk_slot_browser.cpp
lib/psk/psk_active_tracker.hpp      (phase 2)
lib/psk/psk_active_tracker.cpp      (phase 2)
```

Modified files:

```text
PskDecoder.hpp
PskDecoder.cpp
lib/psk/psk_multi_demod.hpp/.cpp   (retire or replace after migration)
widgets/mainwindow.h
widgets/mainwindow_jtty.cpp
CMakeLists.txt                     (add detector/browser sources)
tests/unit/psk/CMakeLists.txt
tests/unit/psk/test_psk_decoder.cpp
```

Add new tests:

```text
tests/unit/psk/test_psk_carrier_detector.cpp
tests/unit/psk/test_psk_browser.cpp
tests/unit/psk/test_psk_multichannel.cpp
```

CMake:

- Add detector/browser sources to `wsjtx_CXXSRCS`.
- Link `FFTW3` single precision for detector sources.
- Add test executables to `tests/unit/psk/CMakeLists.txt`.
- Add test source files with `git add -f` if the repository's
  `test_*` ignore rule hides them.

## 8. Test fixtures and helper design

Create a shared test helper (header-only or small .cpp):

```cpp
std::vector<int16_t> make_psk_audio(
    std::string const& text,
    double audioHz,
    double baud = 31.25,
    bool qpsk = false,
    int silenceSamples = 96000);

std::vector<int16_t> mix_at(
    std::vector<std::vector<int16_t>> const& signals);
```

Generation:

1. `Psk::PskModem::modulateText()` at 48 kHz.
2. Decimate 4:1 to 12 kHz.
3. Append silence (>= 6 s for completion flush tests).
4. To create multiple signals, generate each separately then sum with
   clipping/headroom.

Tests must not depend on wall-clock timers.

## 9. Acceptance criteria

Phase 1:

- Two PSK31 signals at e.g. 500 Hz and 2400 Hz decode simultaneously.
- A selected-tone signal still decodes when not found by the browser.
- No signal -> no completion output.
- One completed message per signal, no adjacent-slot duplicate lines.
- Long message across rewind remains intact.
- Browser can be disabled; only primary decoder runs.
- Pi 5 CPU <= ~3% one core with 30 slots.

Phase 2:

- Two PSK31 signals 25 Hz apart decode simultaneously.
- Three or more simultaneous signals decode.
- Dynamic carrier tracking handles drift without duplicate/lost messages.
- Active carrier count remains bounded.
- Pi 5 CPU <= ~6% one core at 64 active carriers.
- Document the minimum reliable separation and any signal-level limits.

## 10. Implementation order

1. Revert narrow ±10 Hz PSK range to full waterfall range (if still present).
2. Add `CarrierDetector` with FFTW and unit tests.
3. Add `SlotBrowser` with 30 fixed 100 Hz slots; primary decoder separate.
4. Integrate `SlotBrowser` into `Psk::Decoder`; preserve rewind, completion
   buffering, mode reset and replay reset.
5. Add PSK settings/UI for browser enable, channel count and slot width.
6. Add two-signal/multichannel tests and Pi 5 benchmark.
7. Remove or isolate the old 128-channel fixed-grid path.
8. Phase 2: replace slot policy with dynamic active-carrier tracker and
   close-signal detector; keep the same `PskModem`/UI/update paths.
9. Add close-spacing tests, tracking tests and final Pi 5 benchmark.

## 11. Pitfalls

- Do not rely on a 100 Hz slot alone. `PskModem` needs a fine carrier estimate
  or a short fine-probe acquisition.
- Do not run 10,000 demodulators. Detection must precede demodulation.
- Do not let inactive slots run filters.
- Do not use a full reset at period boundaries; use `rewind()`.
- Do not emit every slot's partial text. Buffer completions and select by
  quality.
- Do not let browser garbage into PSKReporter/UDP: complete updates only,
  quality selection, replay suppression.
- Do not let the browser steal the selected-tone primary channel.
- Do not use `QString`/Qt in the DSP detector unless necessary; keep it
  testable as a plain C++ component.
- Do not add a dense static grid as a shortcut.
- Recheck CPU on the Pi 5 after any detector/FFT/window-size change.
- Preserve existing TX behavior and long-PSK-TX streaming.

## 12. References

WS:

- `PskDecoder.cpp/.hpp`
- `lib/psk/psk_multi_demod.cpp/.hpp`
- `lib/psk/psk_modem.cpp/.hpp`
- `widgets/mainwindow_jtty.cpp` (`psk_decode`, mode entry/reset)
- `widgets/mainwindow.h` (PSK session/TX members)
- `tests/unit/psk/test_psk_decoder.cpp`

fldigi:

- `fldigi/src/psk/viewpsk.cxx`
- `fldigi/src/include/viewpsk.h`
- `fldigi/src/psk/pskeval.cxx`
- `fldigi/src/widgets/psk_browser.cxx`
- `fldigi/src/include/configuration.h`

fldigi is the reference for Phase 1. WS Phase 2 is the modern extension:
sparse detection, dynamic active carriers, bounded CPU, and multiple signals
inside a coarse region when they are separable.
