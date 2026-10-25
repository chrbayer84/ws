# CW Implementation Status

## Milestone Tracking

| Milestone | Status | Target Date | Notes |
|-----------|--------|-------------|-------|
| Phase 1: Core library (`lib/cw/`) | 🔴 Not started | | Port fldigi CW modem to wsjtx architecture |
| Phase 2: `CwDecoder` class | 🔴 Not started | | Mirror `RttyDecoder`/`PskDecoder` |
| Phase 3: UI integration | 🔴 Not started | | Extend `updateConversationalSubmodeControls()` |
| Phase 4: TX path | 🔴 Not started | | Reuse JTTY TX queue |
| Phase 5: Graph integration | 🔴 Not started | | WideGraph CW bandwidth display |
| Phase 6: Build system | 🔴 Not started | | CMakeLists.txt additions |
| Phase 7: Unit tests | 🔴 Not started | | Loopback + noise tests |
| Phase 8: Integration test | 🔴 Not started | | End-to-end CW QSO simulation |

## Architectural Decisions

| Decision | Rationale | Date |
|----------|-----------|------|
| Use 12 kHz sample rate (not fldigi's 8 kHz) | Consistency with RTTY/PSK; avoids resampling in decoder | |
| Submodes = WPM presets (5-40 WPM) | Matches operator expectations; simple UI | |
| Adaptive speed tracking: optional, default OFF | Submode sets initial WPM; user can enable adaptive | |
| Pattern matching: weight-based (fldigi approach) | Proven, fast, handles prosigns naturally | |
| No QSK hardware support in modem | wsjtx generates audio directly; keying handled at app layer | |
| Farnsworth spacing: configurable per submode | Standard CW practice; default 1:1 (no Farnsworth) | |

## Known Issues / Open Questions

1. **Sample rate conversion**: fldigi uses 8000 Hz; wsjtx conversational modes use 12000 Hz. Options:
   - Redesign filters for 12 kHz (preferred)
   - Add polyphase resampler at modem boundary
   - Run CW at 8 kHz internally, convert at decoder boundary

2. **Prosign handling**: fldigi has extensive prosign table (SK, AR, KN, AS, etc.). Decide:
   - Full prosign support in decoder output
   - Map to ASCII equivalents (e.g., `<SK>`, `<AR>`)
   - User-configurable prosign display

3. **Adaptive WPM vs fixed submode**: If user selects "CW-20" but sends at 15 WPM, should decoder:
   - Track and adapt (fldigi default)
   - Stay fixed at 20 WPM (simpler, matches submode semantics)
   - **Decision**: Default fixed; add checkbox "Auto WPM" if needed later

4. **TX shaping**: fldigi uses cosine-squared edges with configurable rise time. wsjtx needs:
   - Match fldigi's shaping for compatibility
   - Expose rise time as advanced setting (default 5 ms)

5. **License**: fldigi is GPLv3. wsjtx is GPLv3. Code ported from fldigi must retain GPLv3 headers.

## Files to Create

```
lib/cw/
├── CMakeLists.txt
├── cw_modem.hpp
├── cw_modem.cpp
├── cw_demod.hpp
├── cw_demod.cpp
├── cw_multi_demod.hpp
├── cw_multi_demod.cpp
├── cw_morse_table.hpp
└── test/
    ├── test_cw_morse_table.cpp
    ├── test_cw_modem.cpp
    └── test_cw_demod.cpp

CwDecoder.hpp
CwDecoder.cpp

# Modified existing:
models/Modes.hpp                    # Add CW to enum
widgets/mainwindow.h                # Add CwDecoder, CwModem members
widgets/mainwindow_jtty.cpp         # UI integration
widgets/widegraph.h/.cpp            # CW bandwidth display
CMakeLists.txt                      # Build rules
```

## Test Vectors (from fldigi)

| Test | Input | Expected |
|------|-------|----------|
| Basic letters | "HELLO WORLD" | Decoded text matches |
| Numerals | "12345 67890" | Decoded text matches |
| Prosigns | "SK AR KN" | `<SK> <AR> <KN>` or configured display |
| Mixed case | "CQ CQ DE K1JT" | Decoded text matches |
| With noise (0 dB SNR) | "TEST" + AWGN | >90% character accuracy |
| Speed change | Start 20 WPM, shift to 15 WPM | Adaptive tracks within 5 sec |

## Integration Checklist

- [ ] `Modes::Mode` enum includes `CW`
- [ ] `Modes::name(CW)` returns `"CW"`
- [ ] `Modes::value("CW")` returns `CW`
- [ ] `isConversationalMode()` returns true for `"CW"`
- [ ] `updateConversationalSubmodeControls()` shows strip for CW
- [ ] Submode dropdown populated with CW-5 through CW-40
- [ ] Reverse checkbox works for CW
- [ ] Squelch spinbox works for CW
- [ ] Settings persisted: `CW_Submode`, `CW_Reverse`, `CW_Squelch`
- [ ] `CwDecoder` processes audio and emits `MessageUpdate`
- [ ] TX generates correct CW audio at selected WPM
- [ ] Waterfall shows CW bandwidth markers
- [ ] Unit tests pass on x86_64 and aarch64

## Related Documents

- [CW Implementation Plan](CW_IMPLEMENTATION_PLAN.md)
- [RTTY Implementation Plan](RTTY_IMPLEMENTATION_PLAN.md)
- [RTTY Implementation Status](RTTY_IMPLEMENTATION_STATUS.md)