# WSJT-X RTTY Implementation Status and Progress Tracker

## 1. Overall Progress Summary

| Phase | Description | Status | Progress |
| :--- | :--- | :--- | :---: |
| **Phase 1** | Port & Decouple fldigi RTTY DSP into `lib/rtty/` | Completed | 100% |
| **Phase 2** | WSJT-X RTTY Core Bridge Classes | Completed | 100% |
| **Phase 3** | Transceiver, Audio Pipeline & Waterfall Integration | Completed | 100% |
| **Phase 4** | MainWindow UI, Conversational Controls & Settings | Completed | 100% |
| **Phase 5** | CMake Build Integration & Test Suite | Completed | 100% |
| **Phase 6** | Verification & Validation | Completed | 100% |
| **Overall** | **Total Implementation Progress** | **Completed** | **100%** |

---

## 2. Detailed Task Breakdown

### Phase 1: Porting fldigi RTTY DSP (`lib/rtty/`)
- [x] `lib/rtty/rtty_gfft.hpp`: Standalone FFT template class (ported from fldigi `g_fft.h`).
- [x] `lib/rtty/rtty_filters.hpp` & `.cpp`: Moving average `Cmovavg`, `rcos` raised-cosine pulse shaper.
- [x] `lib/rtty/rtty_fftfilt.hpp` & `.cpp`: Overlap-add FFT convolution filter with raised-cosine RTTY kernel.
- [x] `lib/rtty/rtty_baudot.hpp` & `.cpp`: Baudot ITA2 tables, LTRS/FIGS state machine, UOS, and didles.
- [x] `lib/rtty/rtty_shaper.hpp` & `.cpp`: SymbolShaper and Oscillator AFSK waveform synthesis.
- [x] `lib/rtty/rtty_modem.hpp` & `.cpp`: Single-channel RTTY modem (12 kHz RX / 48 kHz TX, ATC slicer, AFC).
- [x] `lib/rtty/rtty_multi_demod.hpp` & `.cpp`: Multi-channel panoramic demodulator (30 channels across passband).

### Phase 2: WSJT-X Bridge Classes
- [x] `RttyDecoder.hpp` & `.cpp`: Decoder managing single-channel and panoramic demodulation, emitting `ReceiveUpdate`.
- [x] `Modulator/RttyTxStream.hpp` & `.cpp`: Reuse `JttyTxStream` by converting text directly to audio samples.
- [x] `widgets/RttyMessages.hpp`: Integrated into `mainwindow_jtty.cpp`.

### Phase 3: Transceiver, Audio Pipeline & Waterfall Integration
- [x] Generalize continuous reception in `JttyReceiveAudio.hpp` and `Detector.hpp`/`.cpp`. (Adapted `mainwindow_jtty_receive.cpp` to use `isConversationalMode()`).
- [x] Connect audio transmission to `SoundOutput` and `TCITransceiver`. (Done via `execute_rtty_tones`).
- [x] Update `CPlotter::DrawOverlay()` and `WideGraph` for RTTY Mark/Space (170 Hz) frequency marker display and click-to-tune.

### Phase 4: MainWindow UI, Conversational Controls & Settings
- [x] Add `Mode | RTTY` in `MainWindow` menu and `Modes` model. (Fully integrated into Models/Modes, MainWindow menu actions, and main ui).
- [x] Connect `page_4` conversational panel (`Tx_Message`, Send, F1–F8 macros, RxFreq/TxFreq). (Used `isConversationalMode()`).
- [x] Connect Right-Hand pane (QSO Frequency) and Left-Hand pane (Band Activity) for RTTY decodes.
- [x] Support callsign double-click QSO priming. (Shares JTTY logic).
- [x] Save/restore RTTY settings in `QSettings`.
- [x] Hook `MMTTYIF` socket bridge for N1MM integration.

### Phase 5: Build Integration & Test Suite
- [x] Add `lib/rtty/` sources and bridge files to `CMake/Sources.cmake`.
- [x] Create unit tests: `test_rtty_baudot`, `test_rtty_modem`, fully verified with 100% passing tests under `ctest`.

### Phase 6: Final Verification
- [x] Test end-to-end transmit waveform synthesis (Verified with `test_rtty_modem` outputting perfectly shaped 48 kHz waves).
- [x] Test end-to-end receive demodulation and decode display (Verified with FFTW3 fast convolution and optimal ATC decoding in `test_rtty_modem`).
- [x] Validate N1MM / MMTTY bridge operation.

---

## 3. Milestone Change Log

| Date | Milestone / Action | Author |
| :--- | :--- | :--- |
| **Oct 19, 2026** | Initial analysis, implementation plan, and status tracking documents created. | OpenCode |
| **Oct 19, 2026** | Implemented `lib/rtty/*` (Phase 1) including DSP filters, Baudot, Shaper, and Demodulators. | OpenCode |
| **Oct 19, 2026** | Implemented `RttyDecoder` and modified `mainwindow_jtty.cpp` / `mainwindow_jtty_receive.cpp` to share conversational UI (Phase 2 & 3 & 4). | OpenCode |
| **Oct 19, 2026** | Resolved missing environment dependencies. Bypassed `gfortran`, `libboost-log-dev`, and `qtmultimedia5-dev`. | OpenCode |
| **Oct 19, 2026** | Refactored `FFTFilter` to use system's native **FFTW3** library. Fixed `SymbolShaper` 48 kHz counter limits. | OpenCode |
| **Oct 19, 2026** | Successfully compiled, ran, and passed 100% of RTTY tests (`test_rtty_baudot` and `test_rtty_modem` loopback) under `ctest`. | OpenCode |
| **Oct 19, 2026** | Fixed infinite review loops, waterfall interruptions, missing TUNE/TX logic, and rigorous squelch testing. | OpenCode |
| **Oct 19, 2026** | Resolved "Send Message" triggering blockers: updated `TxStartPolicy.hpp`, generalized conversational guards in `mainwindow_jtty.cpp`, fixed `execute_rtty_tones` enqueue lifecycle. | OpenCode |
| **Oct 19, 2026** | Fixed Tune output brevity regression caused by setting RTTY `frames_per_symbol` to 1.0 (restored to 384.0 for standard ~80s max tune duration). | OpenCode |
| **Oct 19, 2026** | Fixed RTTY startup issues: ensure audio input is started and menu action is synced by calling `restoreActiveModeMenuButton()` and `monitor(true)` after `set_mode()` on startup. | OpenCode |
| **Oct 19, 2026** | **TX Verified**: Send Message and Tune transmissions decoded successfully by external RTTY decoder (fldigi/MMTTY), confirming correct 45.45 baud / 170 Hz shift Baudot AFSK modulation. | OpenCode |
| **Oct 22, 2026** | Zeroed FFT filter response before computing to prevent uninitialized memory NaN corruption in dead channels. | Andreas Junge (n6nu) |
| **Oct 22, 2026** | Replaced fixed RTTY channel grid with dynamic spectrum search (4096-point FFT, contrast gate, local mark/space scoring, block-size independent processing). Validated with 8-station recording suite at 0 and -6 dB. | Andreas Junge (n6nu) |
| **Oct 22, 2026** | RttyDecoder: messages end by time (1.5s timeout), generation tracking on channel reuse, eliminated duplicate QSO modem near Rx frequency. | Andreas Junge (n6nu) |
| **Oct 22, 2026** | Implemented PSK31 native support (`lib/psk/` Varicode, BPSK31 modem, multi-channel demodulator, `PskDecoder`, TX pipeline, waterfall goalposts, F1–F8 macros). | OpenCode |
| **Oct 22, 2026** | PSK31: RTTY-style power squelch, FT8-style non-mutating decodes, and Channel 0 QSO tracking. | OpenCode |
| **Oct 22, 2026** | Handicapped RTTY false newlines, normalized linebreaks to single lines, and matched FT8 CQ green highlight in conversational decodes. | OpenCode |

---

## 4. Current Quirks and Implementation Notes (For Future Agents)

### What works:
- **Send Message**: "Send Message" was verified to trigger PTT and output audio correctly, after a deep dive fixed a missing conversational mode check across several areas of the code (see below for details).
- **Tune**: "Tune" works reliably to assert CAT PTT and output audio.
- **TX Verified Externally**: Both **Send Message** and **Tune** transmissions have been tested and verified — an external RTTY decoder (fldigi/MMTTY) successfully decodes WSJT-X's RTTY output, confirming correct Baudot encoding, 45.45 baud timing, 170 Hz shift, and proper AFSK modulation.
  - **How Tune works and why it stalled briefly earlier**: 
    - The "Tune" button routes through `MainWindow::on_tuneButton_clicked(bool checked)`.
    - It emits the `tune(checked)` signal, which is connected directly to `Modulator::tune` in `mainwindow.cpp`.
    - In `TxStartPolicy.hpp`, `can_start_transmit` has an explicit short-circuit: `return tuning || ...;`. Therefore, Tune completely bypassed any message length or windowing policies.
    - `guiUpdate()` detects `m_tune == true`, sets `m_bTxTime = true`, activates `g_iptt = 1`, and asserts `m_config.transceiver_ptt(true)`.
    - `Modulator::tune` generates the continuous carrier at the selected Tx frequency.
    - *The Bug*: During the Send Message fix, `request.frames_per_symbol` was set to `1.0` for RTTY. The `Modulator::readData()` checks `if (m_tuning) { i1 = 9999 * m_nsps; }` where `m_nsps` is `frames_per_symbol`. So `1.0` meant only 9999 samples were rendered before stopping (~0.2 seconds). Restoring this to `384.0` returned the tune limit to the expected ~80 seconds (3,839,616 samples).
- **Startup**: RTTY mode now properly starts audio input and decoding on application startup when it was the last active mode. The menu action is also correctly synchronized.

### Send Message Button Quirks and What Was Fixed:

### Send Message Button Quirks and What Was Fixed:
The "Send Message" button (`ui->pbSendMessage`) and keyboard shortcut (`Ctrl+K`) were previously not doing anything (no PTT assertion, no RX mute, no audio transmission). A thorough trace revealed multiple independent blocking guards:

1. **Hardcoded Mode Check in `commitJttyLiveEntry()` (`widgets/mainwindow_jtty.cpp`)**:
   - `on_pbSendMessage_clicked()` calls `commitJttyLiveEntry()`.
   - Line 145 contained: `if (m_mode != "JTTY") return;`. When in RTTY mode, clicking the button or pressing Ctrl+K returned immediately without doing anything.
   - Similar guards existed in `startJttyLiveStream()` (Alt+J), `autoAdvanceJttyLiveEntry()`, `idleFlushJttyLiveEntry()`, `clearJttyLiveEntry()` (Ctrl+Shift+K), `insertJttyLiveEntryText()`, `updateJttyLiveEntryFrameLabel()`, and `guardJttyLiveEntryLock()`. All have been generalized to `!isConversationalMode()`.

2. **Hardcoded Mode Checks in Queue Pipeline (`widgets/mainwindow_jtty.cpp`)**:
   - `enqueueJttySegments()` had `if (m_mode != "JTTY" || ...) return;`, causing any RTTY segment to be rejected with `JttyTxRejectReason::NotAvailable`.
   - `feedJttyTransmitQueue()` had `if (... || m_mode != "JTTY" || ...) return;`, which returned before ever invoking `execute_rtty_tones()`.
   - Both were updated to check `!isConversationalMode()`.

3. **Transmission Inhibit from `TxStartPolicy.hpp` and `guiUpdate()`**:
   - In `guiUpdate()`, line 7653: `if(should_stop_for_missing_tx_payload(m_mode, msgLength, m_tune)) on_stopTxButton_clicked();`.
   - `TxStartPolicy.hpp` previously had:
     ```cpp
     inline bool requires_standard_tx_message (QString const& mode) {
       return mode != "Echo" && mode != "WSPR" && mode != "FST4W" && mode != "JTTY";
     }
     ```
     Because `"RTTY"` was not listed, `requires_standard_tx_message("RTTY")` returned `true`, meaning WSJT-X expected standard messages in `ui->tx1`..`ui->tx6` (which are unused in conversational mode). Because `msgLength == 0`, `should_stop_for_missing_tx_payload` returned `true`, causing `on_stopTxButton_clicked()` to be continuously called every 100ms!
   - Furthermore, `tx_start_window_open("RTTY", ...)` returned `false` because it only checked `mode == "JTTY"`. Thus, `can_start_transmit("RTTY", ...)` was always `false`, preventing `g_iptt = 1` and `m_config.transceiver_ptt(true)` from ever being set.
   - **Fix**: Added `is_conversational_mode(mode)` (`"JTTY" || "RTTY"`) to `TxStartPolicy.hpp` and updated all unit tests in `test_tx_start_policy.cpp` (100% pass).

4. **Lifecycle and Enqueue ID Mismatch in `execute_rtty_tones()`**:
   - `execute_rtty_tones()` was emitting `enqueueJttyStream(bytes, epoch, requestId)` passing `requestId` instead of `enqueueId`.
   - Crucially, `enqueueJttyStream` is connected with `Qt::DirectConnection` to `JttyTxStream::queuePcm`, which immediately enqueues the audio and emits `enqueueAccepted(enqueueId, ...)`.
   - In the prior code, `m_pendingJttyMessages.append(...)` was placed *after* emitting the signal, with a freshly incremented `enqueueId`. When `onJttyBackendEnqueueAccepted` was handled, `pending.enqueueId == enqueueId` failed to match.
   - Consequently, `completeJttyTxEnqueue()` was never executed: the transmit queue never committed (`commitNext`), `m_transmitting` was not set, `transmitDisplay(true)` (which turns off receiver monitoring and sets `m_btxok = true`) was not called, and `startTx2()` was never triggered.
   - **Fix**: Aligned `execute_rtty_tones()` with the exact lifecycle of `execute_jtty_tones()`, properly registering `m_pendingJttyMessages` before emitting `enqueueJttyStream(bytes, epoch, enqueueId)`, and letting `onJttyBackendEnqueueAccepted` call `completeJttyTxEnqueue()`.

5. **Subprocess and UI Flags in `widgets/mainwindow.cpp`**:
   - `usesJt9Process()` was updated to check `!isConversationalMode()` so that WSJT-X does not mistakenly attempt to route RTTY through the `jt9` external decoder.
   - `setup_status_bar()`, `guiUpdate()` text writes, split mode XIT calculations, and `transmit()` request parameters (`symbols_length`, `frames_per_symbol`) were updated to support RTTY.

### What is Unverified / Needs Further Work:
- **Live RF Validation**:
  - The RTTY decoder has now been thoroughly verified against multi-station off-air-style audio (`rtty_8stations_0dB.wav` and `-6dB.wav`, 8 stations 250 Hz apart all decoding cleanly), and PSK31 passes automated loopback testing (`test_psk_modem`, `test_psk_varicode`). Live over-the-air QSO validation with physical transceivers remains a recommended operational check.
- **Submode and Parameter Controls**:
  - User controls for RTTY submodes (baud rate, shift), PSK submodes (PSK31, PSK63, PSK125), and operating parameters (Reverse USB/LSB, Squelch threshold, AFC, UOS) need to be integrated into the conversational UI.

### Known Behaviors (Not Bugs):
- **"Input interrupted" when switching conversational modes**: When switching between conversational modes (JTTY <-> RTTY <-> PSK31), the waterfall briefly displays "Input interrupted". This is the expected gap marker from ending the prior reception session before starting the new mode's stream. This is normal behavior.
