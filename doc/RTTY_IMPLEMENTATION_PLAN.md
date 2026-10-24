# WSJT-X RTTY Integration Implementation Plan

## 1. Overview and Objectives

The objective is to introduce complete, native Baudot RTTY (45.45 baud, 170 Hz shift) support into WSJT-X, utilizing the proven digital signal processing (DSP) modems from **fldigi**, integrated seamlessly with WSJT-X's audio pipelines, transceiver CAT controls, waterfall displays, and conversational UI controls.

The architecture is designed to establish a generalized **Conversational Mode Engine** in WSJT-X that will support JTTY, RTTY, and upcoming modes such as PSK31 without code duplication.

---

## 2. Phased Implementation Plan

### Phase 1: Porting & Decoupling fldigi RTTY DSP into `lib/rtty/`
Target directory: `lib/rtty/`

1. **`lib/rtty/rtty_gfft.hpp`**:
   - Port fldigi's template `g_fft` class for standalone, self-contained FFT computation.
2. **`lib/rtty/rtty_fftfilt.hpp` & `.cpp`**:
   - Overlap-add FFT convolution filter implementing the optimal raised-cosine RTTY matched filter.
3. **`lib/rtty/rtty_filters.hpp` & `.cpp`**:
   - Moving average filter `Cmovavg`, `rcos` raised-cosine pulse functions, and FIR helpers.
4. **`lib/rtty/rtty_baudot.hpp` & `.cpp`**:
   - Baudot ITA2 encoding and decoding tables (Letters and Figures shift states).
   - Unshift-On-Space (UOS) support for both TX and RX.
   - Character formatting, uppercase normalization, and didle generation.
5. **`lib/rtty/rtty_shaper.hpp` & `.cpp`**:
   - 6-integrator raised-cosine pulse shaper (`SymbolShaper`) and dual NCO oscillators (`Oscillator`) for splatter-free AFSK generation.
6. **`lib/rtty/rtty_modem.hpp` & `.cpp`**:
   - Single-channel RTTY modem (clean decoupling of `rtty.cxx` / `rtty.h`).
   - Heterodyne mixer, dual matched filters, optimal ATC bit slicer, start/stop bit validation, Baudot decoding, and AFC frequency error detection.
   - Configured for **12000 Hz RX** (264 samples/symbol) and **48000 Hz TX** (1056 samples/symbol).
7. **`lib/rtty/rtty_multi_demod.hpp` & `.cpp`**:
   - Multi-channel panoramic demodulator (clean decoupling of `view_rtty.cxx` / `view_rtty.h`).
   - Tracks up to 30 active RTTY carriers simultaneously across the 200–2800 Hz audio spectrum.

---

### Phase 2: WSJT-X RTTY Bridge Classes
Target directory: Root / `widgets/` / `Modulator/`

1. **`RttyDecoder.hpp` & `.cpp`**:
   - C++ RAII class managing both the single-channel demodulator (`rtty_modem` on `RxFreq`) and panoramic demodulator (`rtty_multi_demod` across the band).
   - Consumes 12 kHz PCM blocks from `Detector`.
   - Produces standard `ReceiveUpdate` records compatible with `ReceiveResultController`.
2. **`RttyTxStream.hpp` & `.cpp`**:
   - Transmit controller converting typed/macro text into Baudot bit sequences, inserting preamble/didles during typing pauses, synthesizing 48 kHz shaped AFSK audio, and enqueuing PCM into `TxAudioQueue`.
3. **`widgets/RttyMessages.hpp`**:
   - Helper methods for RTTY text expansion, macro parsing, and Baudot sanitization.

---

### Phase 3: Transceiver, Audio Pipeline, and Waterfall Integration

1. **Audio Input Pipeline**:
   - In `JttyReceiveAudio.hpp` and `Detector.hpp`/`.cpp`, generalize `ReceivePolicy` to support continuous 12 kHz streaming for RTTY.
   - Ensure `Detector` feeds `RttyDecoder` when RTTY is selected.
2. **Audio Output Pipeline**:
   - Integrate `RttyTxStream` with `SoundOutput` and `TCITransceiver`.
   - Ensure rig CAT PTT asserts on TX start, maintains through didles during typing pauses, and releases cleanly upon TX completion or abort.
3. **Waterfall (`WideGraph` & `CPlotter`)**:
   - Update `CPlotter::DrawOverlay()` to render dual Mark/Space frequency marker bars (170 Hz spacing) at the configured `RxFreq` and `TxFreq` when in RTTY mode.
   - Support click-to-tune on the waterfall in RTTY mode.

---

### Phase 4: MainWindow UI, Macros, and Settings Integration

1. **Mode Selection**:
   - Add `Mode | RTTY` action (`actionRTTY`) to the main menu and `Modes` model.
   - Implement `MainWindow::on_actionRTTY_triggered()`.
2. **UI Controls**:
   - Activate conversational panel (`controls_stack_widget` page 1 / `page_4`).
   - Connect `Tx_Message` for live typing and batch sending.
   - Enable keyboard shortcuts (`Ctrl+K` send now, `Alt+J` live stream, `Alt+K` signoff, `Ctrl+H` opener).
   - Connect F1–F8 macro buttons configured with contest templates (`%M`, `%H`, `%R` 599, `%N` serial, `%G` grid, `%E` exchange).
3. **Decodes Presentation**:
   - Connect single-channel decodes to the Right-Hand pane (QSO Frequency).
   - Connect panoramic multi-channel decodes to the Left-Hand pane (Band Activity).
   - Double-clicking a decoded callsign in either pane populates `hisCall` and prepares the contest response.
4. **Settings & Persistence**:
   - Store RTTY specific configuration (default shift 170 Hz, baud rate 45.45, UOS enabled, reverse polarity) in `QSettings`.
5. **MMTTY / N1MM Integration**:
   - Hook `MMTTYIF` socket bridge to route RTTY text between N1MM Logger+ and WSJT-X.

---

### Phase 5: Build Configuration & Test Suite

1. **CMake Build Integration**:
   - Update `CMake/Sources.cmake` to compile `lib/rtty/` files and WSJT-X RTTY bridge sources.
2. **Unit Tests**:
   - Create unit tests in `tests/unit/rtty/`:
     - `test_rtty_baudot`: Test ITA2 encode/decode, case shifts, UOS.
     - `test_rtty_modem`: Round-trip modulator and demodulator test with synthesized AFSK audio.
     - `test_rtty_multi_demod`: Multi-channel panoramic demodulator verification.
     - `test_rtty_txstream`: TX PCM FIFO enqueue, didle generation, and drain verification.

---

### Phase 6: Verification & Status Reporting

1. Verify end-to-end operation against existing WSJT-X test harnesses.
2. Maintain and update `doc/RTTY_IMPLEMENTATION_STATUS.md`.

---

## 3. PSK31 Integration Implementation Plan

### 3.1 Overview
PSK31 (31.25 baud BPSK with Varicode) is an ultra-narrowband conversational digital mode designed by Peter Martinez (G3PLX). By leveraging the conversational UI, macros, audio queues, and panoramic decoding framework established during the RTTY implementation, PSK31 can be integrated natively into WSJT-X Improved without architectural duplication.

### 3.2 Evaluation of fldigi PSK31 Implementation
Analysis of `fldigi`'s implementation (`psk.cxx`, `pskvaricode.cxx`, `pskcoeff.cxx`, `viewpsk.cxx`):
1. **Varicode Encoding/Decoding (`pskvaricode.cxx`)**:
   - Variable-length Huffman code where frequently used characters are assigned fewer bits (e.g. `'e'` = `"11"`).
   - Characters never contain consecutive zero bits (`"00"`).
   - The sequence `"00"` acts strictly as an inter-character delimiter.
   - Decode is table-driven using a 256-entry lookup table (`varicodetab2`).
2. **Modulation & Pulse Shaping (`psk.cxx`)**:
   - Symbol rate is $31.25\text{ baud}$ ($T_s = 32\text{ ms}$).
   - Bit `1`: 0° phase shift. Bit `0`: 180° ($\pi$ rad) phase shift.
   - Raised-cosine amplitude shaping: On phase reversals, the envelope smoothly attenuates to 0 via $A(t) = 0.5(1 + \cos(\pi t / T_s))$, yielding an occupied bandwidth of only ~31.25 Hz with minimal spectral splatter.
3. **Demodulation & Timing Recovery (`psk.cxx` / `viewpsk.cxx`)**:
   - Heterodyne down-conversion of input audio to baseband I/Q.
   - Matched filtering with raised-cosine FIR filters (`fir1`, `fir2`).
   - G3PLX symbol clock recovery: 16-sample circular envelope buffer (`syncbuf`) comparing symmetry between first and second halves of the symbol period to adjust `bitclk`.
   - Differential phase detection: $\Delta\phi = \arg(z_k \cdot z_{k-1}^*)$. If $|\Delta\phi| > \pi/2 \implies 0$; else $\implies 1$.
   - Squelch / DCD: Measures phase coherence $Q = |\langle e^{j 2\Delta\phi} \rangle|^2$.

### 3.3 Phased Implementation Steps
1. **Phase 1: DSP Engine (`lib/psk/`)** [Completed]:
   - [x] `lib/psk/psk_varicode.hpp` / `.cpp`: Clean, standalone Varicode encode and decode functions.
   - [x] `lib/psk/psk_modem.hpp` / `.cpp`: Single-carrier BPSK31 modem (48 kHz TX synthesis, 12 kHz RX demodulation, NCO, matched FIR filtering, symbol timing recovery, phase slicer, DCD squelch, and AFC).
   - [x] `lib/psk/psk_multi_demod.hpp` / `.cpp`: Panoramic multi-channel demodulator tracking simultaneous PSK31 signals across the band with Channel 0 QSO tracking and OpenMP parallelization.
2. **Phase 2: Qt Decoder Bridge (`PskDecoder.hpp` / `.cpp`)** [Completed]:
   - [x] Adapts `PskMultiDemod` to Qt, processing incremental 12 kHz audio slices and emitting non-mutating FT8-style completed decodes (`Jtty::MessageUpdate`).
3. **Phase 3: GUI & Mode Wiring** [Completed]:
   - [x] Add `PSK31` to `Modes::Mode` in `models/Modes.hpp` / `Modes.cpp`.
   - [x] Add `actionPSK31` to main menu (`mainwindow.ui`).
   - [x] Add `"PSK31"` to `is_conversational_mode()` in `TxStartPolicy.hpp` and `mainwindow.h`.
   - [x] Add waterfall goalpost markers in `widgets/plotter.cpp` centered at $f_0 \pm 15.6\text{ Hz}$.
   - [x] Route audio streaming through `psk_decode()` and TX generation through `execute_psk_tx()` in `widgets/mainwindow_jtty.cpp`.
   - [x] Wire F1–F8 macros with tag expansion for PSK31.
4. **Phase 4: Unit Testing** [Completed]:
   - [x] `test_psk_varicode`: Varicode encode/decode validation across the full ASCII set.
   - [x] `test_psk_modem`: End-to-end loopback test feeding 48 kHz modulated audio into the 12 kHz demodulator.

---

## 4. Anticipated Pitfalls, RTTY Learnings, and Technical Solutions

During the native Baudot RTTY implementation, several subtle DSP and architectural issues were encountered and resolved. The following table and breakdown details how to avoid repeating these pitfalls when implementing PSK31:

### 4.1 Summary of Pitfalls & Solutions

| Area | Pitfall Experienced in RTTY | Risk in PSK31 Port | Engineered Solution |
| :--- | :--- | :--- | :--- |
| **Audio Slicing** | Passing full audio buffer (`dec_data.d2`) every 40 ms caused $O(N^2)$ CPU spike and froze GUI. | PSK31 FIR filters and timing clock `bitclk` will corrupt or freeze under full re-processing. | Pass only incremental audio slices (`d2 + last_k`, ~480–1200 samples) to `psk_decode()`, keeping `last_k` monotonic. |
| **State Reset** | Filter re-initialization inside audio loops reset FFT/filter states, dropping characters. | Resetting FIR filters or NCO `phaseacc` causes catastrophic phase discontinuities. | Guard all filter and frequency setters with change-detection checks (`if (freq != lastFreq)`). Never reset state per audio buffer. |
| **Multi-Channel CPU** | Panoramic 30-channel demodulator consumed excessive CPU on single thread. | 30 complex FIR filters and NCOs will cause buffer overruns on low-power CPUs (e.g. Raspberry Pi). | Parallelize channel processing loop in `PskMultiDemod::rxProcess()` with OpenMP (`#pragma omp parallel for`). |
| **AFC Stability** | Scale factor and derivative errors in AFC formula caused center frequency to bounce. | PSK31 bandwidth is only 31.25 Hz; aggressive AFC will jump to adjacent signals or oscillate wildly. | Clamp AFC step size to $\pm \text{baud}/4$ ($\pm 7.8\text{ Hz}$), require confirmed DCD lock, and apply heavy exponential smoothing (`decayavg`). |
| **TX Postamble** | Abrupt carrier shutdown or trailing space created trailing phantom `'H'` character artifact. | Receiver triggers on `"00"`. Abrupt carrier drop leaves unresolved phase, generating random garbage characters. | Append 28–32 bits of unmodulated carrier / pad bits, ramp down amplitude to 0 with raised-cosine taper, and cleanly flush before releasing PTT. |
| **TxStartPolicy** | Missing mode check in `TxStartPolicy.hpp` caused 100ms abort loop due to missing FT8 message payload. | Transmission fails to start; transceiver PTT clicks off immediately after assertion. | Include `"PSK31"` in `is_conversational_mode()` within `TxStartPolicy.hpp` and add corresponding unit test in `test_tx_start_policy.cpp`. |
| **Status Bar Display** | `guiUpdate()` wiped conversational status bar message with spaces every 100 ms. | Live TX text does not display on the bottom status bar. | Ensure `MainWindow::guiUpdate()` guards conversational modes (`isConversationalMode()`), preventing FT8 block logic from clearing `m_currentMessage`. |
| **Frequency Standard** | Ambiguity between Mark tone and Center frequency caused waterfall marker offset. | PSK31 center carrier must match waterfall marker center, GUI spinner, and decode logs. | Adopt Center Frequency ($f_0$) universally across GUI spinners, narrow goalpost markers ($f_0 \pm 15.6\text{ Hz}$), and decode reporting. |
| **Squelch / Ghosting** | Raw noise triggered false decodes, generating single-character fragments. | Random phase changes in background noise easily mimic valid Varicode bit patterns. | Require vector coherence metric $Q > \text{threshold}$, confirm DCD state over multiple symbols, and discard fragments $< 3$ characters. |

---

## 5. Conversational Submodes & Parameter Controls Plan (RTTY & PSK)

### 5.1 Objectives & Architectural Decisions
Introduce mode-specific submode selection (flat dropdown) and streamlined parameter controls for both RTTY and PSK conversational modes:
- **RTTY Submodes**:
  - `RTTY-45` (45.45 baud, 170 Hz shift) [Default]
  - `RTTY-50` (50.00 baud, 170 Hz shift)
  - `RTTY-75N` (75.00 baud, 170 Hz shift)
  - `RTTY-75W` (75.00 baud, 850 Hz shift)
  - `RTTY-100` (100.00 baud, 170 Hz shift)
- **PSK Submodes**:
  - BPSK: `PSK31` (31.25 baud), `PSK63` (62.5 baud), `PSK125` (125 baud), `PSK250` (250 baud)
  - QPSK (FEC with $K=5$, polynomials $0x17$/$0x19$, Viterbi): `QPSK31`, `QPSK63`, `QPSK125`, `QPSK250`
- **Control Rules & Simplifications**:
  - **UOS (Unshift-On-Space)**: **Hard-enabled** (always active for RTTY TX/RX; no UI toggle).
  - **AFC (Automatic Frequency Control)**: **Hard-enabled** (always active for both RTTY and PSK; no UI toggle).
  - **F Tol**: **Not needed** for either RTTY or PSK (hidden in conversational UI when RTTY/PSK active).
  - **Rev (Reverse)**: User-configurable checkbox/toggle for inverting polarity (Mark/Space for RTTY, phase for PSK).
  - **Squelch (Sql)**: User-configurable threshold in dB (0–30 dB, default 5 dB).

### 5.2 Known Open Issues & Bugs
- **QSO Pane Highlighting Bleed**: Yellow TX highlighting still sometimes bleeds over into subsequent RX messages displayed in the right-hand QSO history pane. Needs tag/format isolation when appending new incoming text.
