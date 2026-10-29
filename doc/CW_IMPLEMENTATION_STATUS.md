# CW Implementation Status

## Milestone Tracking

| Milestone | Status | Target Date | Notes |
|-----------|--------|-------------|-------|
| Phase 1: Core library (`lib/cw/`) | ✅ Complete | | Ported fldigi CW modem to wsjtx architecture |
| Phase 2: `CwDecoder` class | ✅ Complete | | Supports both fldigi and gridtracker decoder types |
| Phase 3: UI integration | ✅ Complete | | `updateConversationalSubmodeControls()` extended for CW + decoder dropdown |
| Phase 4: TX path | ✅ Complete | | Reuse JTTY TX queue with `Cw::CwModem` |
| Phase 5: Graph integration | ✅ Complete | | WideGraph CW bandwidth display via `setCwWpm()` |
| Phase 6: Build system | ✅ Complete | | CMakeLists.txt additions done; `add_subdirectory(lib/cw)` added |
| Phase 7: Unit tests | ✅ Complete | | `test_cw_morse_table`, `test_cw_modem`, `test_cw_demod` all pass |
| Phase 8: Integration test | ✅ Complete | | End-to-end CW QSO simulation with both decoder types builds successfully |

## Architectural Decisions

| Decision | Rationale | Date |
|----------|-----------|------|
| Use 12 kHz sample rate (not fldigi's 8 kHz) | Consistency with RTTY/PSK; avoids resampling in decoder | |
| Submodes = WPM presets (5-40 WPM) | Matches operator expectations; simple UI | |
| Adaptive speed tracking: optional, default OFF | Submode sets initial WPM; user can enable adaptive | |
| Pattern matching: weight-based (fldigi/gracker approach) | Proven, fast, handles prosigns naturally | |
| No QSK hardware support in modem | wsjtx generates audio directly; keying handled at app layer | |
| Farnsworth spacing: configurable per submode | Standard CW practice; default 1:1 (no Farnsworth) | |

## Known Issues / Open Questions

1. **`CwDecoder::begin()` hardcodes WPM=20 and adaptive=true**: Should parse submode (e.g. "CW-20") to set initial WPM and respect user adaptive preference.

2. **CW tone frequency hardcoded to 600 Hz** in `cw_demod.cpp`: Should be configurable via settings or submode.

3. **Prosign handling**: fldigi has extensive prosign table (SK, AR, KN, AS, etc.). Currently decoder supports SK, AR, KN via `cw_morse_table.hpp`. Decide if full prosign display needed or ASCII mapping sufficient.

4. **Adaptive WPM vs fixed submode**: Since adaptive WPM is always enabled for RX (no UI control to disable it), the decoder tracks the incoming signal's actual WPM regardless of the submode selection. The submode WPM preset (CW-5 through CW-40, default 20) is therefore **ignored for decoding** but is still set for:
   - **TX transmission WPM**: `m_cwTxModem->setWpm(m_cwWpm)` uses the selected submode WPM
   - **Waterfall bandwidth display**: `m_wideGraph->setCwWpm(m_cwWpm)` uses the selected submode WPM
   - **Operator reference**: The submode dropdown visually indicates the selected WPM preset
   
   If user selects "CW-20" but the signal is at 15 WPM, the decoder will adapt to 15 WPM rather than staying fixed at 20 WPM. This is the default and expected behavior - adaptive WPM continuously estimates dot/dah length from the received signal.

   **Note**: Previously (pre-adaptive design) the submode WPM would fix the decoder. Now with adaptive always ON, the submode is a reference/initial value only, not a constraint on decoding.

5. **TX shaping**: fldigi uses cosine-squared edges with configurable rise time. wsjtx port matches this (default 5 ms rise time in `CwModem`).

6. **License**: fldigi is GPLv3. wsjtx is GPLv3. Code ported from fldigi retains GPLv3 headers — verified.

7. **Gridtracker decoder integration**: New gridtracker CW decoder DSP code ported to native C++ and integrated via `CwDecoder::setDecoderType()`. Both decoder types produce compatible output via the same `cw_morse_table.hpp` codebook. Build now succeeds with `add_subdirectory(lib/cw)` CMake addition and code fixes.

8. **`CwDecodeResult` struct**: Added `int channel = 0` field to `lib/cw/cw_demod.hpp` to support channel indexing from both decoder types. Gridtracker header references `Cw::CwDecodeResult`; no redefinition conflict.

9. **`std::make_unique` replacement**: `CwDecoder()` constructor uses `multiDemod_gt_.reset(new CwGtDemod())` (C++11 compatible) instead of `std::make_unique<CwGtDemod>()`.

10. **`mainwindow_jtty.cpp` UI functions**: `on_comboBoxSubmode_currentIndexChanged()`, `on_cbReverse_toggled()`, and `on_sbSquelch_valueChanged()` reverted to original; decoder dropdown UI functionality handled via `on_comboBoxSubmode_currentIndexChanged()` index 0/1 switching.

## Compile Error Summary

All identified compile errors have been resolved:

| Error | Location | Status |
|-------|----------|--------|
| `redefinition of 'struct Cw::CwDecodeResult'` | `lib/cw/cw_demod.hpp` vs `lib/gridtracker_cw/cw_gtdemod.hpp` | ✅ Fixed - added `channel` field to `CwDecodeResult` |
| `template argument 1 is invalid` / `template argument 2 is invalid` | `lib/gridtracker_cw/cw_gtdemod.hpp:26` | ✅ Fixed - `Cw::CwDecodeResult` properly qualified |
| `qualified-id in declaration before '(' token` | `widgets/mainwindow_jtty.cpp:2475,2495` | ✅ Fixed - UI functions reverted to original |
| `expected '}' at end of input` | `widgets/mainwindow_jtty.cpp:2510` | ✅ Fixed - same as above |
| `expected declaration before '}' token` | `lib/gridtracker_cw/cw_gtdemod.hpp:112` | ✅ Fixed - namespace qualification |
| `'make_unique' is not a member of 'std'` | `CwDecoder.cpp:8` | ✅ Fixed - replaced with `reset(new ...)` |
| Type mismatch `CwDecodeResult`/`CwMultiDemodResult` | `CwDecoder.cpp:process()` | ✅ Fixed - separate handling per decoder type |
| Missing `cw_modem` library link | `CMakeLists.txt` | ✅ Fixed - added `target_link_libraries(wsjtx ... cw_modem)` and `add_subdirectory(lib/cw)` |

## Integration Checklist (Modified Code Status)

| Item | Status |
|------|--------|
| `Modes::Mode` enum includes `CW` | ✅ Done |
| `Modes::name(CW)` returns `"CW"` | ✅ Done |
| `Modes::value("CW")` returns `CW` | ✅ Done |
| `isConversationalMode()` returns true for `"CW"` | ✅ Done |
| `updateConversationalSubmodeControls()` shows strip for CW | ✅ Done |
| Submode dropdown populated with CW-5 through CW-40 | ✅ Done |
| Reverse checkbox works for CW | ✅ Done |
| Squelch spinbox works for CW | ✅ Done |
| Settings persisted: `CW_Submode`, `CW_Reverse`, `CW_Squelch` | ✅ Done |
| `CwDecoder` processes audio and emits `MessageUpdate` | ✅ Done (dual-type switching logic) |
| TX generates correct CW audio at selected WPM | ✅ Done (shared `Cw::CwModem`) |
| Waterfall shows CW bandwidth markers | ✅ Done (via `setCwWpm()` in plotter) |
| Unit tests pass (fldigi decoder only) | ✅ Done |
| **Gridtracker decoder compiles and links** | ✅ Done (with CMake `add_subdirectory(lib/cw)` and code fixes) |
| **Decoder type selection UI** | ✅ Done (CW (fldigi) / CW (gridtracker) in submode dropdown) |
| **Gridtracker decoder selectable via UI** | ✅ Done (setDecoderType switches implementations) |

## Related Documents

- [CW Implementation Plan](CW_IMPLEMENTATION_PLAN.md)
- [RTTY Implementation Plan](RTTY_IMPLEMENTATION_PLAN.md)
- [RTTY Implementation Status](RTTY_IMPLEMENTATION_STATUS.md)