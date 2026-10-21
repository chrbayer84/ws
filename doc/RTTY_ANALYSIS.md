# Conversational Digital Modes in WSJT-X: RTTY and PSK31 Analysis

## 1. Executive Summary

WSJT-X has traditionally focused on time-synchronized weak-signal modes (FT8, FT4, JT65, Q65, FST4, WSPR) characterized by fixed time blocks (typically 15s, 30s, or 60s) and strict protocol framing. Recently, WSJT-X introduced **JTTY**, an asynchronous, continuous conversational mode designed for fast keyboard-to-keyboard and contest exchanges.

This document presents a comprehensive technical analysis of integrating standard **RTTY** (Baudot ITA2, 45.45 baud, 170 Hz shift) and **PSK31** (BPSK, 31.25 baud Varicode) into WSJT-X by porting and adapting the proven digital signal processing (DSP) modems from **fldigi** into the WSJT-X source tree.

---

## 2. WSJT-X Architecture Analysis

### 2.1 The Conversational Paradigm (JTTY Baseline)
Unlike legacy WSJT-X modes that operate on 15-second period boundaries, conversational modes require:
- **Asynchronous Audio Intake**: Continuous audio streaming from the soundcard without fixed period boundaries.
- **Continuous Background Demodulation**: Running real-time sliding demodulators over audio as it arrives.
- **Dual Decodes Presentation**:
  - *Left-Hand Pane (Band Activity)*: Wideband panoramic reception showing all active stations across the audio passband (200–2800 Hz).
  - *Right-Hand Pane (QSO Frequency)*: Focused reception on the operator's active receive frequency (`RxFreq`).
- **Live Incremental Transmit Entry**: Typing in a text box (`Tx_Message`) that transmits immediately or with bounded word batching, visually distinguishing locked/sent text (yellow highlight), queued text (gray), and uncommitted text (plain).
- **Contest & Macro Support**: Function keys F1–F8 providing parameterized macros (`%M` MyCall, `%H` HisCall, `%R` Report, `%N` Serial, `%G` Grid, `%E` Contest Exchange).
- **External Logger Integration**: N1MM Logger+ integration via an emulated MMTTY socket interface (`MMTTYIF`).

### 2.2 Core WSJT-X Infrastructure
1. **Audio Input**:
   - `Detector` captures audio from the system soundcard at **48 kHz**.
   - A 4:1 polyphase FIR downsampling filter (`fil4_state_`) decimates audio to **12 kHz**.
   - When in continuous mode (`ReceivePolicy::Continuous`), audio blocks are pushed to `JttyReceivePublisher` and stored in `JttyReceiveMailbox`.
   - `MainWindow::JttyReceiveState` drains the mailbox and triggers the decoder.
2. **Audio Output**:
   - Audio is synthesized at **48 kHz** mono signed 16-bit PCM.
   - Handled via `TxAudioQueue` (a lock-free ring buffer supporting epoch invalidation and drain tracking).
   - An asynchronous `QIODevice` adapter (`JttyTxStream`) connects the queue to `SoundOutput`.
   - Playout drives CAT PTT on the rig, seamlessly filling typing pauses with idle signals (didles/fillers), and dropping PTT when the stream drains or is cancelled.
3. **UI Stack**:
   - `controls_stack_widget` page 1 (`page_4`) hosts the conversational UI controls: `Tx_Message`, `pbSendMessage`, F1–F8 macro buttons, message style selection, `TxFreqSpinBox_2`, `RxFreqSpinBox_2`, `sbFtol_2`, `pbR2T_2`, `pbT2R_2`, and `sbSerialNumber_2`.
4. **Waterfall Display**:
   - `WideGraph` and `CPlotter` render real-time FFT waterfall rows and overlay frequency markers for RX and TX channels.

---

## 3. fldigi RTTY Modem Architecture

In `fldigi/src/cw_rtty/`, the RTTY implementation comprises:
- `rtty.cxx` / `rtty.h`: Single-channel modem (`class rtty : public modem`).
- `view_rtty.cxx` / `view_rtty.h`: Multi-channel panoramic demodulator (`class view_rtty : public modem`).
- `fsk.cxx` / `fsk.h`: Hardware FSK keying.

### 3.1 Transmit Engine
- **Character Encoding**: ASCII characters are mapped to 5-bit Baudot ITA2 codes.
- **Shift States**: The transmitter tracks state between Letters (`LETTERS = 0x1F`) and Figures (`FIGURES = 0x1B`).
- **Unshift-On-Space (UOS)**: Transmitting a space automatically resets the shift state to Letters.
- **Asynchronous Framing**: Each character consists of 1 start bit (Space), 5 data bits (LSB first), and 1.5 stop bits (Mark).
- **Idle Generation**: Continuous Mark tone or LTRS/BLANK didles during typing pauses.
- **Pulse Shaping**: `SymbolShaper` implements a 6-integrator raised-cosine pulse shaper (`rcos(t, T, 1.0)`) and dual NCO oscillators (`Oscillator`) generating splatter-free shaped AFSK.

### 3.2 Receive Engine
- **Downconversion**: Analytic signal mixing converts Mark (`fc - shift/2`) and Space (`fc + shift/2`) tones to baseband complex analytic streams.
- **Matched Filtering**: Dual `fftfilt` overlap-add FFT convolution filters with raised-cosine frequency response (`f *= 1.4`).
- **Envelope & Noise Tracking**: Fast attack, slow decay envelope followers (`mark_env`, `space_env`) and noise floor trackers (`mark_noise`, `space_noise`).
- **Optimal Automatic Threshold Control (ATC)**: Non-linear slicer providing robust bit decisions under selective fading:
  $$v_3 = (m_{\text{clipped}} - n_0)(m_{\text{env}} - n_0) - (s_{\text{clipped}} - n_0)(s_{\text{env}} - n_0) - 0.25((m_{\text{env}} - n_0)^2 - (s_{\text{env}} - n_0)^2)$$
- **Bit Recovery & Framing**: Sliding bit buffer `bit_buf` detects mark-to-space start bit transitions, samples data bits at midpoint, and validates stop bit.
- **Baudot Decoding**: Tracks RX Letters/Figures shift state with RX UOS support.
- **AFC**: Phase argument of consecutive mark/space history estimates frequency error $\Delta f$.

### 3.3 Multi-Channel Demodulator (`view_rtty`)
- Instantiates an array of 30 demodulator channels (`RTTY_CHANNEL channel[30]`).
- Scans audio passband for active carrier pairs, tracks multiple frequencies simultaneously, and decodes incoming Baudot streams across the spectrum.

---

## 4. fldigi PSK31 Modem Architecture

In `fldigi/src/psk/`, the PSK modem comprises:
- `psk.cxx` / `psk.h`: Single-channel PSK modem (`class psk : public modem`).
- `viewpsk.cxx` / `viewpsk.h`: Multi-channel panoramic demodulator (`class viewpsk`).
- `pskvaricode.cxx` / `pskvaricode.h`: Varicode encoder and decoder tables.
- `pskcoeff.cxx` / `pskcoeff.h`: Matched FIR and raised-cosine filter coefficients.

### 4.1 Transmit Engine
- **Varicode Encoding**: ASCII characters are encoded into variable-length bit sequences. Common characters have shorter codes (e.g. space is `"1"`, `'e'` is `"11"`, `'t'` is `"101"`).
- **Framing**: Characters never contain `"00"` internally; `"00"` serves as the character delimiter.
- **BPSK Modulation**: Differential phase keying where bit `'1'` preserves phase ($0^\circ$) and bit `'0'` causes a $180^\circ$ phase reversal.
- **Amplitude Shaping**: Raised-cosine envelope shaping ($0.5\cos(\theta) + 0.5$) reduces carrier amplitude to zero during phase reversals, constraining RF bandwidth to ~31.25 Hz.

### 4.2 Receive Engine
- **Baseband Mixing**: NCO mixer shifts carrier $f_c$ to baseband complex samples.
- **Decimating Matched Filters**: Two-stage FIR filters (`fir1`, `fir2`) downsample and isolate the symbol envelope.
- **Bit Clock Recovery**: A 16-step circular accumulator `syncbuf[16]` rectifies signal magnitude and tracks symmetry error between early and late halves of the symbol period.
- **Differential Phase Slicing**: $\Delta\phi = \arg(\text{symbol} \cdot \text{prev\_symbol}^*)$. Phase changes near $180^\circ$ decode as `'0'`, changes near $0^\circ$ decode as `'1'`.
- **Varicode Assembler**: Bits shift into `shreg`. When `(shreg & 3) == 0`, `psk_varicode_decode` extracts the ASCII character.

---

## 5. Comparative Analysis: JTTY vs. RTTY vs. PSK31

| Dimension | JTTY (WSJT-X Native) | RTTY (from fldigi) | PSK31 (from fldigi) |
| :--- | :--- | :--- | :--- |
| **Modulation** | 4-GFSK (continuous phase) | 2-tone AFSK (Mark/Space) | 1-carrier BPSK (differential) |
| **Symbol Rate** | 31.25 baud | 45.45 baud | 31.25 baud |
| **Tone Shift / Separation** | 4 tones @ 31.25 Hz spacing | 2 tones @ 170 Hz spacing | N/A (single carrier) |
| **Bandwidth (Occupied)** | 127 Hz (99% power) | ~250 Hz | ~31.25 Hz (-3 dB), 62.5 Hz (nulls) |
| **Error Correction** | Rate-1/2 Tail-Biting CC (K=10) + CRC12 | None (unprotected) | None (unprotected in BPSK31) |
| **Source Coding** | STRUCT30 atoms + TEXT5 packed grammar | 5-bit Baudot (ITA2), LTRS/FIGS | Variable-length Varicode (ASCII) |
| **Framing Structure** | Synchronous 1.888s frames (59 symbols) | Asynchronous start-stop (7.5 bits) | Asynchronous bitstream ("00" delimiter) |
| **Idle Behavior** | Explicit filler frames (`<<<<<`) | Continuous Mark / LTRS didles | Continuous phase reversals ("000...") |
| **Demodulator Model** | Sliding FFT correlation + TBCC Viterbi | Dual BPFs + Envelope follower + ATC | Baseband NCO + FIR + Phase diff + Clock sync |
| **Panoramic Support** | Multi-slot auto-discovery across spectrum | Multi-channel `view_rtty` (30 channels) | Multi-channel `viewpsk` (30 channels) |
| **Waterfall Marking** | 4-tone bracket bar | Dual Mark/Space markers (170 Hz) | Single narrow carrier marker (31 Hz) |
| **N1MM / Logger Protocol** | Tagged & Literal MMTTY socket bridge | Standard MMTTY socket bridge | Text stream via socket bridge |

---

## 6. Sample Rate Arithmetic in WSJT-X

WSJT-X operates on fixed standard audio sampling rates:
- **RX Input**: 48 kHz downsampled 4:1 by `fil4_state_` to **12 kHz**.
- **TX Output**: 48 kHz mono signed 16-bit PCM.

### 6.1 RTTY Rates (45.4545 Baud)
- **RX**: $\frac{12000\text{ samples/sec}}{45.454545\text{ symbols/sec}} = \mathbf{264.0}\text{ samples/symbol}$ (exact integer).
- **TX**: $\frac{48000\text{ samples/sec}}{45.454545\text{ symbols/sec}} = \mathbf{1056.0}\text{ samples/symbol}$ (exact integer).

### 6.2 PSK31 Rates (31.25 Baud)
- **RX**: $\frac{12000\text{ samples/sec}}{31.25\text{ symbols/sec}} = \mathbf{384.0}\text{ samples/symbol}$ (exact integer, identical to JTTY `m_nsps = 384`).
- **TX**: $\frac{48000\text{ samples/sec}}{31.25\text{ symbols/sec}} = \mathbf{1536.0}\text{ samples/symbol}$ (exact integer).

**Key Architectural Insight**: Both RTTY and PSK31 map to exact integer samples per symbol at WSJT-X native rates (12 kHz RX and 48 kHz TX). No asynchronous sample rate converter is needed.

---

## 7. Decoupling Strategy for fldigi Code

fldigi modem source files contain tight couplings to the FLTK GUI, custom soundcard abstractions, and internal status globals. To port these modems into WSJT-X cleanly:

1. **Remove FLTK & UI Dependencies**: Replace FLTK callbacks (`put_rx_char`, `put_echo_char`, `show_status`) with thread-safe queues and C++ callback/signal interfaces.
2. **Remove Hardware IO**: Strip direct serial port access (`nanoIO`, `winkeyer`, `flrig`) in favor of WSJT-X's unified `Transceiver` and `TxAudioQueue` architecture.
3. **Encapsulate Math & DSP**: Port `g_fft.h`, `fftfilt.cxx`, `filters.cxx`, and `Cmovavg` into self-contained classes inside `lib/rtty/` and `lib/psk/`.
4. **Adapt to WSJT-X Data Structures**: Expose standard `ReceiveUpdate` records (`messageId`, `frequency`, `text`, `startSeconds`, `latestSeconds`, `terminal`, `snr`) to seamlessly drive `ReceiveResultController` and `DisplayText`.
