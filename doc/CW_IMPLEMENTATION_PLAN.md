# CW Modem Implementation Plan

## Overview

Integrate the fldigi CW (Morse code) modem into wsjtx as a conversational mode alongside RTTY and PSK31, using the same UI pattern (submode dropdown, Rev checkbox, Squelch spinbox) and macro/freeform text system. Additionally, port the CW decoder from gridtracker2 to wsjtx as an alternative decoder implementation, selectable via a dropdown in the CW screen.

## Current State Analysis

### fldigi CW Modem (`fldigi/src/cw_rtty/`)

**Files:**
- `cw.h` / `cw.cxx` — Main modem class `cw : public modem`
- `view_cw.h` / `view_cw.cxx` — Waterfall/scope view (not needed for wsjtx)

**Key Features:**
- **Sample rate**: Fixed 8000 Hz internal (`CW_SAMPLERATE`)
- **TX/RX**: Full duplex with QSK (full break-in) support
- **Modulation**: On-off keying with shaped edges (cosine rise/fall)
- **RX detection**: FFT matched filter (`fftfilt`) + FIR fallback
- **Decoding**: Weight-based pattern matching against `som_table` (Morse codebook)
- **Adaptive speed**: Auto WPM tracking (dot/dash length estimation)
- **Prosigns**: Full support (SK, AR, KN, etc.)
- **Farnsworth**: Configurable character vs inter-character spacing

**Configurable Parameters:**
- `cw_speed` / `cw_send_speed` / `cw_receive_speed` — WPM (5-50)
- `cw_bandwidth` — RX filter bandwidth (50-500 Hz)
- `cw_squelch` — Noise threshold (0-30 dB)
- `cw_reverse` — Invert mark/space (for inverted keying)
- `usedefaultWPM` — Use fixed vs adaptive speed

### wsjtx CW Port — Largely Complete

**Ported Library (`lib/cw/`)** — Already adapted from fldigi:
- `cw_modem.hpp/.cpp` — TX modem: generate shaped CW tones at configurable WPM
- `cw_demod.hpp/.cpp` — RX demodulator: FFT bandpass + envelope detection + pattern matching
- `cw_multi_demod.hpp/.cpp` — Multi-channel demod (waterfall decoding)
- `cw_morse_table.hpp` — Morse codebook (som_table equivalent) with prosigns (SK, AR, KN, etc.)
- Unit tests: `test_cw_morse_table`, `test_cw_modem`, `test_cw_demod` — all pass
- CMake integrated into main wsjtx build

**CwDecoder** (`CwDecoder.hpp/.cpp`) — Wraps `CwMultiDemod` / `CwGtDemod`:
- `begin(sessionId, gridOrigin, firstSearch, samplesPerSymbol)` — Initialize
- `process(samples, count, ...)` — Process audio, return decoded text via `MessageUpdate`
- `setSubmode()`, `setReverse()`, `setSquelch()` — Runtime config
- Now supports two decoder types: fldigi (default) and gridtracker (selectable via UI)
- Can be switched at runtime via `setDecoderType(DecoderType)`

**Gridtracker2 CW Decoder Port** (`lib/cw/cw_gtdemod.cpp/.hpp`):
- Native C++ port of gridtracker2's WASM CW decoder DSP core
- Same 12 kHz sample rate as wsjtx conversational modes
- Uses weight-based Morse pattern matching (same `cw_morse_table.hpp`)
- Adaptive WPM tracking with dot/dah length estimation
- 2nd order Butterworth bandpass filter
- Envelope detection with fast attack, slow release
- Element detection (dit/dah) with squelch threshold
- Shares `cw_morse_table.hpp` with the fldigi-based decoder

**What's Different from fldigi:**
- Sample rate: 12000 Hz (wsjtx standard) vs 8000 Hz (fldigi) — already adapted
- No fldigi dependencies: removed `fl_digi.h`, `waterfall.h`, `ptt.h`, etc.
- Modernized: uses `std::vector`, `std::array`, C++17
- Pattern matching: weight-based `som_table` approach kept (proven, fast)
- No QSK hardware keying: wsjtx handles TX audio generation separately
- No WinKeyer, CAT control, calibration
- Shares Morse codebook with fldigi port (same `cw_morse_table.hpp`)

### gridtracker2 CW Decoder (for reference)

The gridtracker2 WebAssembly CW decoder (`src/wasm/cwdecoder/cwdecoder.c`) uses:
- kissFFT for spectrum waterfall
- Decimation filter (Blackman-windowed sinc)
- Channel tracking with adaptive thresholds
- Timing engine with dit/dah tracking and speed learning
- Weight-based Morse pattern matching (same approach as wsjtx port)

**Key differences:**
- gridtracker2: Runs in AudioWorklet (JavaScript/WASM), uses `requestAnimationFrame` for waterfall rows
- wsjtx: Native C++, integrates with `CwDemod`/`CwMultiDemod` class hierarchy, runs per-audio-buffer in `process()`
- Both use 12 kHz sample rate
- Both use weight-based pattern matching against Morse codebook
- gridtracker2 has more extensive channel management (multi-signal tracking, regression, etc.)
- wsjtx port is simpler: focused on conversational mode QSOs, integrates with existing wsjtx facilities

## Implementation Plan (Updated)

### Phase 1: Core Library (`lib/cw/`)

Already complete — includes both fldigi-adapted and gridtracker-ported code:

**Files in `lib/cw/`:**
| File | Purpose |
|------|---------|
| `cw_modem.hpp/.cpp` | TX modem: generate shaped CW tones at configurable WPM |
| `cw_demod.hpp/.cpp` | RX demodulator: FFT bandpass + envelope detection + pattern matching |
| `cw_multi_demod.hpp/.cpp` | Multi-channel demod (waterfall decoding) |
| `cw_morse_table.hpp` | Morse codebook (som_table equivalent) with prosigns |
| `cw_gtdemod.hpp/.cpp` | **Gridtracker-style RX demodulator** (new) |

**Adaptations from fldigi:**
1. **Sample rate**: 12000 Hz (wsjtx standard) — both fldigi and gridtracker variants
2. **Remove fldigi dependencies**: Already done for fldigi variant
3. **Simplify**: Remove QSK hardware keying — wsjtx handles TX audio generation
4. **Modernize**: Uses `std::vector`, `std::array`, C++17
5. **Pattern matching**: Keep weight-based `som_table` approach; proven in both implementations

### Phase 2: Decoder Class (`CwDecoder.hpp/.cpp`)

**Updated to support two decoder types:**

```cpp
namespace Cw {
enum class DecoderType { Fldigi, Gridtracker };

class Decoder {
public:
  void setDecoderType(DecoderType type);  // switch at runtime
  DecoderType decoderType() const;
  // ... rest of existing interface
private:
  DecoderType decoder_type_ = DecoderType::Fldigi;
  CwMultiDemod multiDemod_fldigi_;
  std::unique_ptr<CwGtDemod> multiDemod_gt_;
};
}
```

### Phase 3: UI Integration

**1. Add decoder selection dropdown in CW screen:**
- In `updateConversationalSubmodeControls()`: Add "CW (fldigi)" and "CW (gridtracker)" as first two items in the submode dropdown for CW mode
- In `on_comboBoxSubmode_currentIndexChanged()`: Handle index 0 (fldigi) and index 1 (gridtracker) to switch decoder type
- Display the selected decoder type in the UI status

**2. Add member variables to MainWindow:**
```cpp
DecoderType m_cwDecoderType = DecoderType::Fldigi;  // or Gridtracker
```

**3. Handle decoder type switching:**
- When user selects "CW (fldigi)": Reinitialize decoder with fldigi implementation
- When user selects "CW (gridtracker)": Reinitialize decoder with gridtracker implementation
- Preserve WPM, reverse, and squelch settings across decoder switches

### Phase 4: TX Path

No changes needed — TX uses `Cw::CwModem` which is shared between both decoder types.

### Phase 5: Waterfall/Graph Integration

No changes needed — WideGraph's `setCwWpm()` works with both decoder types.

### Phase 6: Build System

**CMakeLists.txt additions:**
- `lib/cw/CMakeLists.txt`: Already includes `cw_gtdemod.cpp` in the `cw_modem` library
- Main CMakeLists.txt: Added `target_include_directories(wsjtx PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/gridtracker_cw)` for the gridtracker_cw header

### Phase 7: Testing

**Unit tests:**
- `test_cw_morse_table.cpp` — Codebook encode/decode roundtrip (existing, passes)
- `test_cw_modem.cpp` — TX generates correct tone timing at various WPM (existing, passes)
- `test_cw_demod.cpp` — RX decodes known signals (loopback with AWGN) (existing, passes)
- New: Gridtracker decoder integration test — verify decoded text matches fldigi output for same input

**Integration test:**
- CW ↔ CW loopback at 20 WPM using both decoder types, verify text recovery
- Compare fldigi vs gridtracker decoder output for same audio input
- Test with noise (SNR -5 to +10 dB)
- Test adaptive WPM tracking with both decoder types

## Similarities to RTTY/PSK

| Aspect | RTTY | PSK | CW (both decoder types) |
|--------|------|-----|------------------------|
| Sample rate | 12 kHz | 12 kHz | 12 kHz |
| Submode control | Baud/shift | Baud/QPSK | WPM |
| Reverse | Mark/space | Phase | Mark/space |
| Squelch | SNR threshold | SNR threshold | SNR threshold |
| TX modem | `RttyModem` | `PskModem` | `CwModem` (shared) |
| RX demod | `RttyMultiDemod` | `PskMultiDemod` | `CwMultiDemod` / `CwGtDemod` |
| Decoder class | `RttyDecoder` | `PskDecoder` | `CwDecoder` (supports both) |
| UI strip | ✓ | ✓ | ✓ |
| Macros/freeform | ✓ | ✓ | ✓ |

## Differences from RTTY/PSK

| Aspect | RTTY/PSK | CW |
|--------|----------|-----|
| Modulation | FSK / PSK | OOK (on-off keying) |
| Symbol timing | Fixed baud | Variable (WPM adaptive) |
| FEC | None / Viterbi (QPSK) | None (inherent redundancy) |
| Bandwidth | 170-850 Hz | 50-200 Hz (configurable) |
| Decoding | Symbol sync + lookup | Edge detection + pattern match |
| Speed tracking | Fixed | Adaptive (optional) |
| Prosigns/abbrevs | No | Yes (SK, AR, KN, etc.) |

## Effort Estimate (Updated)

| Phase | Effort | Notes |
|-------|--------|-------|
| Phase 1: Core library | 3-4 days | Port fldigi CW modem + gridtracker port |
| Phase 2: Decoder class | 1 day | Add DecoderType support, reinit |
| Phase 3: UI integration | 1 day | Add decoder dropdown, handle switching |
| Phase 4: TX path | — | No changes needed (shared CwModem) |
| Phase 5: Graph integration | — | No changes needed (shared setCwWpm) |
| Phase 6: Build system | 0.5 day | Add gridtracker_cw include dir |
| Phase 7: Testing | 2 days | Unit + integration, compare decoder outputs |
| **Total** | **~7-9 days** | |

## Risks & Mitigations

| Risk | Mitigation |
|------|------------|
| fldigi CW uses 8 kHz sample rate | Both variants use 12 kHz — already adapted |
| Adaptive WPM may conflict with fixed submode | Make adaptive optional; submode sets *initial* WPM |
| Morse pattern matching vs Varicode | Keep weight-based approach; proven in both implementations |
| QSK / hardware keying not needed | Strip out; wsjtx generates audio directly |
| License (GPLv3) | fldigi is GPLv3; wsjtx is GPLv3 — compatible |
| Gridtracker DSP differences | Both use weight-based pattern matching; shared codebook |

## Dependencies

- **fldigi source**: Available at `/home/christian/temp/wsjtx/build/ws/fldigi/` (already cloned)
- **gridtracker2 source**: Available at `/home/christian/temp/wsjtx/build/ws/gridtracker2/` (already cloned)
- **No new external deps**: Uses existing FFTW, Qt, wsjtx infrastructure
- **New**: `lib/gridtracker_cw/` — gridtracker CW decoder port (header + implementation)

## References

- fldigi CW implementation: `fldigi/src/cw_rtty/cw.cxx`, `fldigi/src/include/cw.h`
- RTTY implementation: `lib/rtty/`, `RttyDecoder.hpp/.cpp`
- PSK implementation: `lib/psk/`, `PskDecoder.hpp/.cpp`
- UI pattern: `widgets/mainwindow_jtty.cpp` — `updateConversationalSubmodeControls()`
- Mode enum: `models/Modes.hpp`
- Gridtracker2 CW decoder: `gridtracker2/src/wasm/cwdecoder/cwdecoder.c`
- Gridtracker2 tools: `gridtracker2/tools/build_cw_wasm.js`