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
