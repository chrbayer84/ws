# CW Modem Implementation Plan

## Overview

Integrate the fldigi CW (Morse code) modem into wsjtx as a conversational mode alongside RTTY and PSK31, using the same UI pattern (submode dropdown, Rev checkbox, Squelch spinbox) and macro/freeform text system.

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

### wsjtx RTTY/PSK Architecture

**Library Structure:**
```
lib/rtty/          lib/psk/
├── rtty_modem.hpp     ├── psk_modem.hpp
├── rtty_multi_demod.hpp  ├── psk_multi_demod.hpp
└── ...                  ├── psk_viterbi.hpp (QPSK FEC)
```

**Decoder Classes:**
- `RttyDecoder` / `PskDecoder` — Wrap modem + multi_demod, manage message state
- `begin(sessionId, gridOrigin, firstSearch, samplesPerSymbol)` — Initialize
- `process(samples, count, ...)` — Process audio, return decoded text
- `setSubmode()`, `setReverse()`, `setSquelch()` — Runtime config

**UI Controls (mainwindow_jtty.cpp):**
- `comboBoxSubmode` — Submode dropdown (RTTY-45/50/75N/75W/100, PSK31/63/125/250/QPSK...)
- `cbReverse` — Reverse checkbox
- `sbSquelch` — Squelch spinbox (0-30)
- `updateConversationalSubmodeControls()` — Shows/hides strip, populates submodes

**Mode Enum (models/Modes.hpp):**
```cpp
enum Mode { ALL, JT65, JT9, ..., RTTY, JTTY, PSK31, MODES_END_SENTINAL_AND_COUNT };
```

## Implementation Plan

### Phase 1: Core Library (`lib/cw/`)

Create new directory `lib/cw/` with wsjtx-native CW modem adapted from fldigi:

**Files to create:**
| File | Purpose |
|------|---------|
| `cw_modem.hpp/.cpp` | TX modem: generate shaped CW tones at configurable WPM |
| `cw_demod.hpp/.cpp` | RX demodulator: FFT matched filter + pattern matching |
| `cw_multi_demod.hpp/.cpp` | Multi-channel demod (waterfall decoding) |
| `cw_morse_table.hpp` | Morse codebook (som_table equivalent) |

**Adaptations from fldigi:**
1. **Sample rate**: Convert from 8000 Hz → 12000 Hz (wsjtx standard for conversational modes)
2. **Remove fldigi dependencies**: `fl_digi.h`, `waterfall.h`, `ptt.h`, `serial.h`, `main.h`, `winkeyer.h`, `nanoIO.h`, `KYkeying.h`, `ICOMkeying.h`, `YAESUkeying.h`, `audio_alert.h`, `qrunner.h`
3. **Simplify**: Remove QSK hardware keying, calibration, WinKeyer, CAT control — wsjtx handles TX audio generation separately
4. **Modernize**: Use `std::vector`, `std::array`, C++17; replace `Cmovavg` with simple IIR
5. **Pattern matching**: Keep weight-based `som_table` approach; it's fast and accurate

**CW Modem Interface:**
```cpp
class CwModem {
public:
  void setWpm(int wpm);
  void setBandwidth(int hz);
  void setReverse(bool rev);
  void setFarnsworth(int wpm);  // optional
  void tx_init();
  int tx_process(float* output, int max_samples, const QString& text);
  void rx_init();
  int rx_process(const qint16* samples, int count, float center_freq);
  // Returns decoded text segments with timing/frequency info
};
```

**Submodes (WPM presets):**
- CW-5, CW-10, CW-15, CW-20, CW-25, CW-30, CW-35, CW-40
- Default: CW-20

### Phase 2: Decoder Class (`CwDecoder.hpp/.cpp`)

Mirror `RttyDecoder` / `PskDecoder`:

```cpp
namespace Cw {
class Decoder {
public:
  Decoder();
  ~Decoder();
  bool valid() const { return true; }
  void begin(qint64 sessionId, qint64 gridOrigin, qint64 firstSearch, int samplesPerSymbol = 384);
  void setSubmode(const QString& submode);  // "CW-20" etc.
  void setReverse(bool rev);
  void setSquelch(double s);
  int process(qint16 const* samples, int count, qint64 firstSample,
              qint64 stopSample, int maxSteps, int lowFrequency,
              int highFrequency, float centerFrequency, float tolerance);
  qint64 nextRequiredSample() const;
  QVector<Jtty::MessageUpdate> takeUpdates();
private:
  // Same pattern as RttyDecoder: ChannelState, messageId tracking, etc.
  CwMultiDemod multiDemod_;
  // ...
};
}
```

### Phase 3: UI Integration

**1. Add CW to Mode Enum (models/Modes.hpp):**
```cpp
enum Mode {
  ...
  PSK31,
  CW,           // <-- ADD
  MODES_END_SENTINAL_AND_COUNT
};
```

**2. Update `updateConversationalSubmodeControls()` (mainwindow_jtty.cpp):**
```cpp
bool const isCw = (m_mode == "CW");
bool const showStrip = isRtty || isPsk || isCw;
// ...
if (isCw) {
  ui->comboBoxSubmode->addItem("CW-5");
  ui->comboBoxSubmode->addItem("CW-10");
  // ... up to CW-40
  m_cwSubmode = m_settings->value("CW_Submode", "CW-20").toString();
  m_cwReverse = m_settings->value("CW_Reverse", false).toBool();
  m_cwSquelch = m_settings->value("CW_Squelch", 5).toInt();
  // Apply to decoder
}
```

**3. Add handler cases in `on_comboBoxSubmode_currentIndexChanged()`, `on_cbReverse_toggled()`, `on_sbSquelch_valueChanged()`**

**4. Add member variables to MainWindow:**
```cpp
QString m_cwSubmode {"CW-20"};
int m_cwWpm {20};
bool m_cwReverse {false};
int m_cwSquelch {5};
std::unique_ptr<Cw::CwModem> m_cwTxModem;
Cw::Decoder m_cwDecoder;
```

**5. Mode switching (`switch_mode()`, `isConversationalMode()`):**
- Add `"CW"` to `isConversationalMode()`
- Handle CW in `switch_mode()` for decoder init

### Phase 4: TX Path

**In `execute_jtty_tx()` or new `execute_cw_tx()`:**
```cpp
void MainWindow::execute_cw_tx(qint64 requestId, QString message) {
  if (!m_cwTxModem) m_cwTxModem = std::make_unique<Cw::CwModem>();
  m_cwTxModem->setWpm(m_cwWpm);
  m_cwTxModem->setReverse(m_cwReverse);
  // Generate audio, enqueue via m_jttyTxQueue
}
```

**Macro expansion:** Reuse existing `jtty_msg_expand()` — works for CW freeform text.

### Phase 5: Waterfall/Graph Integration

**WideGraph updates:**
- Add `setCwWpm(int wpm)` for goalpost/bandwidth display
- CW uses narrow filter (~50-200 Hz), show as vertical marker pair

### Phase 6: Build System

**CMakeLists.txt additions:**
```cmake
# In lib/ section
add_subdirectory(cw)

# In main target sources
target_sources(wsjtx PRIVATE
  CwDecoder.cpp
  lib/cw/cw_modem.cpp
  lib/cw/cw_demod.cpp
  lib/cw/cw_multi_demod.cpp
)
```

### Phase 7: Testing

**Unit tests (`tests/unit/cw/`):**
- `test_cw_morse_table.cpp` — Codebook encode/decode roundtrip
- `test_cw_modem.cpp` — TX generates correct tone timing at various WPM
- `test_cw_demod.cpp` — RX decodes known signals (loopback with AWGN)
- `test_cw_adaptive_speed.cpp` — Speed tracking convergence

**Integration test:**
- CW ↔ CW loopback at 20 WPM, verify text recovery
- CW with noise (SNR -5 to +10 dB)

## Similarities to RTTY/PSK

| Aspect | RTTY | PSK | CW (planned) |
|--------|------|-----|--------------|
| Sample rate | 12 kHz | 12 kHz | 12 kHz |
| Submode control | Baud/shift | Baud/QPSK | WPM |
| Reverse | Mark/space | Phase | Mark/space |
| Squelch | SNR threshold | SNR threshold | SNR threshold |
| TX modem | `RttyModem` | `PskModem` | `CwModem` |
| RX demod | `RttyMultiDemod` | `PskMultiDemod` | `CwMultiDemod` |
| Decoder class | `RttyDecoder` | `PskDecoder` | `CwDecoder` |
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

## Effort Estimate

| Phase | Effort | Notes |
|-------|--------|-------|
| Phase 1: Core library | 3-4 days | Port/adapt fldigi CW modem |
| Phase 2: Decoder class | 1 day | Boilerplate similar to RTTY/PSK |
| Phase 3: UI integration | 1 day | Extend existing conversational strip |
| Phase 4: TX path | 1 day | Reuse JTTY TX queue |
| Phase 5: Graph integration | 0.5 day | Minor WideGraph update |
| Phase 6: Build system | 0.5 day | CMake additions |
| Phase 7: Testing | 2 days | Unit + integration |
| **Total** | **~9-10 days** | |

## Risks & Mitigations

| Risk | Mitigation |
|------|------------|
| fldigi CW uses 8 kHz sample rate | Resample or redesign filters for 12 kHz; use polyphase resampler |
| Adaptive WPM may conflict with fixed submode | Make adaptive optional; submode sets *initial* WPM |
| Morse pattern matching vs Varicode | Keep weight-based approach; it's proven in fldigi |
| QSK / hardware keying not needed | Strip out; wsjtx generates audio directly |
| License (GPLv3) | fldigi is GPLv3; wsjtx is GPLv3 — compatible |

## Dependencies

- **fldigi source**: Available at `/home/christian/temp/wsjtx/build/ws/fldigi/` (already cloned)
- **No new external deps**: Uses existing FFTW, Qt, wsjtx infrastructure

## References

- fldigi CW implementation: `fldigi/src/cw_rtty/cw.cxx`, `fldigi/src/include/cw.h`
- RTTY implementation: `lib/rtty/`, `RttyDecoder.hpp/.cpp`
- PSK implementation: `lib/psk/`, `PskDecoder.hpp/.cpp`
- UI pattern: `widgets/mainwindow_jtty.cpp` — `updateConversationalSubmodeControls()`
- Mode enum: `models/Modes.hpp`