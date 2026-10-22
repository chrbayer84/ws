"""Synthesise 45.45 Bd / 170 Hz RTTY (ITA2) at 12 kHz, independent of the code under test.

usage: python rttysynth.py out.wav SNR_dB  "f_center:start_s:TEXT" ...
f_center = midpoint of mark and space (audio Hz); mark = upper tone (USB).
SNR is per signal in 2500 Hz bandwidth (the WSJT-X convention).
"""
import sys, wave
import numpy as np

FS = 12000
BAUD = 45.45
SHIFT = 170.0
LTRS = {'A': 3, 'B': 25, 'C': 14, 'D': 9, 'E': 1, 'F': 13, 'G': 26, 'H': 20, 'I': 6, 'J': 11,
        'K': 15, 'L': 18, 'M': 28, 'N': 12, 'O': 24, 'P': 22, 'Q': 23, 'R': 10, 'S': 5, 'T': 16,
        'U': 7, 'V': 30, 'W': 19, 'X': 29, 'Y': 21, 'Z': 17, ' ': 4, '\r': 8, '\n': 2}
FIGS = {'1': 23, '2': 19, '3': 1, '4': 10, '5': 16, '6': 21, '7': 7, '8': 6, '9': 24, '0': 22,
        '-': 3, '?': 25, ':': 14, '$': 9, '!': 13, '&': 26, '#': 20, '(': 15, ')': 18, '.': 28,
        ',': 12, "'": 5, '/': 29, '"': 17, ';': 30, ' ': 4, '\r': 8, '\n': 2}
LTRS_CODE, FIGS_CODE = 31, 27


def codes(text):
    out, shift = [LTRS_CODE, LTRS_CODE], 'L'
    for ch in text.upper():
        if ch in LTRS and ch not in ' \r\n':
            if shift != 'L': out.append(LTRS_CODE); shift = 'L'
            out.append(LTRS[ch])
        elif ch in FIGS and ch not in ' \r\n':
            if shift != 'F': out.append(FIGS_CODE); shift = 'F'
            out.append(FIGS[ch])
        elif ch in LTRS:
            out.append(LTRS[ch])
            if ch == ' ': shift = 'L'         # unshift on space: senders re-send FIGS
    return out


def bits(text):
    """(mark?, duration in bits): idle mark, start 0, 5 data LSB first, 1.5 stop."""
    seq = [(1, 8.0)]                          # some idle mark first
    for c in codes(text):
        seq.append((0, 1.0))
        for i in range(5): seq.append(((c >> i) & 1, 1.0))
        seq.append((1, 1.5))
    seq.append((1, 4.0))
    return seq


def signal(fc, text, rng):
    sps = FS / BAUD
    freqs = []
    t = 0.0
    for mark, nb in bits(text):
        n_end = int(round((t + nb) * sps)); n_start = int(round(t * sps))
        freqs += [fc + (SHIFT / 2 if mark else -SHIFT / 2)] * (n_end - n_start)
        t += nb
    phase = 2 * np.pi * np.cumsum(np.array(freqs)) / FS + rng.uniform(0, 2 * np.pi)
    return np.cos(phase)                      # amplitude 1 -> power 0.5


def main():
    out, snr = sys.argv[1], float(sys.argv[2])
    rng = np.random.default_rng(7)
    specs = []
    for s in sys.argv[3:]:
        fc, start, text = s.split(':', 2)
        specs.append((float(fc), float(start), text))
    sigs = [(fc, int(st * FS), signal(fc, txt, rng)) for fc, st, txt in specs]
    total = max(st + len(x) for _, st, x in sigs) + FS
    y = np.zeros(total)
    for _, st, x in sigs: y[st:st + len(x)] += x
    # noise power in 2500 Hz such that each signal (power 0.5) has the given SNR
    pn_2500 = 0.5 / 10 ** (snr / 10)
    sigma = np.sqrt(pn_2500 * (FS / 2) / 2500)
    y += rng.normal(0, sigma, total)
    y *= 8000 / max(1e-9, np.percentile(np.abs(y), 99.9))
    with wave.open(out, 'wb') as w:
        w.setnchannels(1); w.setsampwidth(2); w.setframerate(FS)
        w.writeframes(np.clip(y, -32767, 32767).astype(np.int16).tobytes())
    print(f"{out}: {total / FS:.1f} s, {len(specs)} signals, SNR {snr} dB")


main()
