RTTY test recordings for the RTTY decoder (lib/rtty)

12 kHz mono WAV, 8.5 s, made with rttysynth.py (an RTTY generator written
independently of lib/rtty, so it tests the decoder, not itself): eight
stations 45.45 Bd / 170 Hz, 250 Hz apart from 600 to 2350 Hz (centre of
mark and space; mark is the upper tone), starting 0.2-2.5 s in:

   600  CQ TEST DL1ABC DL1ABC K        1600  TU K1ABC TEST
   850  W9XYZ 599 123 123 TU           1850  QRZ DE OH2BH OH2BH
  1100  CQ CQ DE K1ABC K1ABC PSE K     2100  5NN 0123 TU
  1350  UA3DX 599 014 014              2350  CQ WPX G4ABC G4ABC

rtty_8stations_0dB.wav    each station at 0 dB SNR (2500 Hz reference):
                          all eight should decode, give or take a stray
                          character at the start or end
rtty_8stations_-6dB.wav   at -6 dB, the RTTY limit: partly readable

In WS: Mode > RTTY, then File > Open. Regenerate or make others with e.g.
  python rttysynth.py out.wav 0 "1500:0.5:CQ TEST N6NU N6NU K" "1800:1:..."
(f_centre:start_s:text; needs numpy).
