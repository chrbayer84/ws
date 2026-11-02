// GridTracker Copyright © 2026 GridTracker.org
// All rights reserved.
// See LICENSE for more information.

// CW Decoder's DSP, built to src/renderer/lib/mmd/cwdecoder.wasm by tools/build_cw_wasm.js and run in the Multi-Mode Decoder's AudioWorklet
// (mmdWorklet.js). The audio in is brought down to about 12 kHz (for a span of 4 kHz or less; three times the span for a wider one, an
// SDR's); a spectrum (kissFFT, its bins about 6 Hz whatever the span) every ~43 ms feeds the waterfall and finds the carriers that stand
// out from the noise floor (each bin's own, so a band's slope doesn't matter). Each carrier found is a channel: mixed down to 0 Hz and
// filtered narrow, its level read every 4 ms against an adaptive threshold (signal and noise levels followed, for QSB), and the key-down
// and key-up times read as Morse by a timing engine that follows the sender's speed and weighting.
//
//   cw_init(rate, span):  the audio context's sample rate, and the audio to decode (Hz from 0; 4000 if not given, less than half the
//                         rate); true once ready
//   cw_span():            the span decoded (what was asked, or as much as the rate allows)
//   cw_max_channels():    how many signals are decoded at once (the rows of cw_channels)
//   cw_input():           where cw_process reads its samples from (CW_INPUT_MAX floats)
//   cw_process(n):        n samples in; true when a new waterfall row is out (cw_row, cw_row_bins long, one byte a bin)
//   cw_bin_hz():          the waterfall's hertz per bin
//   cw_channels():        CW_MAX_CHANNELS rows of CW_CHANNEL_FIELDS floats (cwChannelOut)
//   cw_events(), cw_event_count(), cw_events_clear(): the characters decoded since the last clear, as (channel id, character) pairs
//   cw_retune():          the rig moved: everything found so far is let go
//   cw_set_range(lo, hi): the audio decoded (Hz; Settings, Min Freq and Max Freq): signals outside it aren't
//   cw_set_decode(on):    CW decoded (1, as at the start) or not (0: the waterfall's rows only, for FT8 and SSTV)
//
// The events' characters: a character's code; 1, a channel's transmission starts (after a pause); below 0, the transmission so far read
// again with what has been learned since and come out differently: its whole text, in cw_revision_text(-c - 1), takes the place of
// what was sent for it

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "kissfft/kiss_fftr.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define CW_INPUT_MAX 4096
#define CW_TARGET_RATE 12000.0
#define CW_FIR_MAX 129
// The FFT: 2048 points at 12 kHz (5.9 Hz bins), more at a higher rate so the bins stay as narrow; a hop of a quarter of it (~43 ms)
#define CW_FFT_BASE 2048
#define CW_FFT_MAX 32768
// The span decoded by default, its widest (96 kHz: half of a 192 kHz stream), and the lowest audio decoded (under it is hum)
#define CW_MAX_HZ 4000.0
#define CW_SPAN_MAX 96000.0
#define CW_MIN_HZ 150.0
#define CW_BINS_MAX (CW_FFT_MAX / 2)
#define CW_FLOOR_BLOCK 32
#define CW_MAX_CHANNELS 64
#define CW_CHANNEL_FIELDS 8
// A channel's boxcars: 8 ms at up to 192 kHz
#define CW_BOX_MAX 1536
// Strong signals subtracted: a channel this far over its noise (dB), keyed (this many marks) and heard lately has its signal rebuilt and
// taken out of the audio the other channels decode (cw_process)
#define CW_SUB_SNR 15.0f
#define CW_SUB_MARKS 4
#define CW_EVENTS_MAX 2048
#define CW_SYMBOL_MAX 8
#define CW_RECENT 20
// A Farnsworth sender's space between characters is learned up to this many dits (9 units at 18/8 WPM)
#define CW_FARNSWORTH_DITS 12.0
// A transmission's marks and spaces kept to read it again (txRevise), its text, and the pause that ends it (ms; longer for a slow sender)
#define CW_TIMELINE 2048
#define CW_TX_TEXT 512
#define CW_TX_PAUSE_MS 2500.0
#define CW_REVISIONS_MAX 64
// Read again, each part of the transmission is judged by the timing of the marks and spaces around it (this many either side: about a
// dozen of each), so a sender who speeds up or slows down is read at each speed; a long one is only read again at its word ends
#define CW_LOCAL 24
#define CW_SPLIT_MAX 64
#define CW_REVISE_EACH_CHAR 1200

// A carrier is taken as one this far above its bin's noise floor (dB) in enough rows (CW_DETECT_HITS, each row it isn't there taking a
// third of one away: a keyed carrier is there about half the time, noise seldom twice in a row), and the strongest within this far
// (Hz) is the only channel there
#define CW_DETECT_DB 12.0f
#define CW_DETECT_HITS 3.0f
#define CW_CHANNEL_SPACING 40.0f
// A channel's carrier is there while its bin is this far over the floor (dB): its key is only read while it was there in the last
// CW_SEEN_MS (ms), and the channel is let go when it hasn't been for CW_CHANNEL_IDLE_MS
#define CW_SEEN_DB 10.0f
#define CW_SEEN_MS 1500.0
#define CW_WARMUP_TICKS 38
// The shortest dit (ms): 60 WPM
#define CW_DIT_MIN_MS 20.0
#define CW_CHANNEL_IDLE_MS 20000.0

typedef struct
{
  int used;
  int id;
  float freq;           // Hz in the audio
  float holdDb;         // its bin's peak-hold level, for telling its sidebands from another carrier
  double c, s, dc, ds;  // the mixer's phasor and its step
  int renorm;
  // Two boxcars in a row (each CW_BOX samples), I and Q
  float r1i[CW_BOX_MAX], r1q[CW_BOX_MAX], r2i[CW_BOX_MAX], r2q[CW_BOX_MAX];
  double s1i, s1q, s2i, s2q;
  int pos;
  // The measuring filter (the raw audio): its boxcars; the mixer's phasor turned back D samples (cD, sD: that turn); the signal rebuilt
  // at n - D (rec, 0 unless sub: a strong channel's, subtracted from the others')
  float m1i[CW_BOX_MAX], m1q[CW_BOX_MAX], m2i[CW_BOX_MAX], m2q[CW_BOX_MAX];
  double t1i, t1q, t2i, t2q;
  double cD, sD, pc, ps;
  float rec;
  int sub;
  int tick;
  // The adaptive threshold
  float sig, noise;
  int primed;
  int key;
  // The timing engine: states 0 up, 1 down, 2 up but maybe a dropout, 3 down but maybe a noise spike
  int state;
  double upMs, downMs, pendMs;
  double dit, dah, gap;
  double recent[CW_RECENT];  // the last marks' lengths (ms), split into dits and dahs again after each one
  int recentCount, recentPos;
  int shortRun;              // marks under half a dit in a row
  double charGap;            // the space between characters (ms); gap is the one within a character
  double gaps[CW_RECENT];    // the last spaces' lengths (ms), word spaces left out
  int gapCount, gapPos;
  char symbol[CW_SYMBOL_MAX + 1];
  int symLen;
  int charDone, wordDone;
  // The characters of the word under way, and the words of one character in a row: three of those in a row are a Farnsworth sender's
  // long spaces between characters taken for word spaces (spaceEnded)
  int wordChars, singleWords;
  double seenMs;        // since its carrier was last over the floor in the spectrum
  int marks;
  // The transmission under way: its marks (ms, above 0) and spaces (ms, below 0) in order, and its text as sent so far
  int txOpen;
  float timeline[CW_TIMELINE];
  int timelineLen;
  char txText[CW_TX_TEXT + 1];
  int txLen;
  int txUnknown;        // its characters whose marks made none
} CwChannel;

static double g_inRate = 48000.0;
static double g_fs = 12000.0;
static int g_dec = 4;
static int g_decPhase = 0;
static float g_fir[CW_FIR_MAX];
static int g_firLen = 1;
static float g_firHist[CW_FIR_MAX * 2];
static int g_firPos = 0;
// The span decoded (cw_init), and within it the audio decoded (cw_set_range): carriers are only found within that
static double g_span = CW_MAX_HZ;
static double g_minHz = CW_MIN_HZ;
static double g_maxHz = CW_MAX_HZ;
// Speed a channel starts with before the sender's own is learned (cw_set_init_wpm)
static double g_initWpm = 20.0;
// The spectrum's size and hop (grown with the span, for bins of about 6 Hz), and a channel's boxcar and tick (cw_init)
static int g_fftN = CW_FFT_BASE;
static int g_fftHop = CW_FFT_BASE / 4;
static int g_box = 96;
static int g_tickSamples = 48;
static double g_tickMs = 4.0;

static float g_input[CW_INPUT_MAX];
static float g_ring[CW_FFT_MAX];
static int g_ringPos = 0;
static int g_hopCount = 0;
static int g_rows = 0;
// The last of the audio (at the lower rate), its last 0.6 s replayed into a new channel: a carrier is found a few rows after it starts,
// and its first character isn't lost
#define CW_HISTORY 262144
static float g_history[CW_HISTORY];
static int g_historyPos = 0;
static int g_historyLen = 0;
static float g_window[CW_FFT_MAX];
static float g_fftIn[CW_FFT_MAX];
static kiss_fft_cpx g_fftOut[CW_FFT_MAX / 2 + 1];
static kiss_fftr_cfg g_fft = 0;
static int g_fftCfgN = 0;
static int g_bins = 0;
static float g_db[CW_BINS_MAX];
static float g_floor[CW_BINS_MAX];
static float g_hold[CW_BINS_MAX];
static float g_hits[CW_BINS_MAX];
static int g_floorPrimed = 0;
static unsigned char g_row[CW_BINS_MAX];
// CW is decoded (cw_set_decode): off (the viewer in another mode), only the waterfall's rows are made, no carrier found or channel run
static int g_decodeOn = 1;

static CwChannel g_ch[CW_MAX_CHANNELS];
static float g_chOut[CW_MAX_CHANNELS * CW_CHANNEL_FIELDS];
static int g_nextId = 1;
static int g_events[CW_EVENTS_MAX * 2];
static int g_eventCount = 0;
static char g_revText[CW_REVISIONS_MAX][CW_TX_TEXT + 1];
static int g_revCount = 0;

// ---- Morse

static const char *const MORSE_CODES[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..",
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
  ".-.-.-", "--..--", "..--..", "-..-.", "-...-", ".-.-.", "-....-", "---...", ".----.", "-.--.", "-.--.-", ".-..-.", ".--.-.", "-.-.--"
};
static const char MORSE_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?/=+-:'()\"@!";

static int morseLookup(const char *symbol)
{
  for (int i = 0; i < (int)(sizeof(MORSE_CODES) / sizeof(MORSE_CODES[0])); i++)
  {
    if (strcmp(symbol, MORSE_CODES[i]) == 0) return MORSE_CHARS[i];
  }
  return 0;
}

static void emit(CwChannel *ch, int c)
{
  if (g_eventCount >= CW_EVENTS_MAX) return;
  g_events[g_eventCount * 2] = ch->id;
  g_events[g_eventCount * 2 + 1] = c;
  g_eventCount++;
}

#ifdef CW_DEBUG
// A debug build only (not shipped): one channel's level, levels followed and key, each tick, for tuning offline
static float g_debug[4 * 65536];
static int g_debugCount = 0;
static float g_debugFreq = 0.0f;
void cw_debug_watch(float freq) { g_debugFreq = freq; g_debugCount = 0; }
float *cw_debug(void) { return g_debug; }
int cw_debug_count(void) { return g_debugCount; }
static void cwDebugTick(CwChannel *ch, float a)
{
  if (fabsf(ch->freq - g_debugFreq) > 20.0f || g_debugCount >= 65536) return;
  float *d = g_debug + g_debugCount * 4;
  d[0] = a;
  d[1] = ch->noise;
  d[2] = ch->sig;
  d[3] = (float)ch->key;
  g_debugCount++;
}
#endif

// ---- Setup

int cw_init(double rate, double span)
{
  if (!(rate >= 8000.0 && rate <= 384000.0)) return 0;
  g_inRate = rate;
  // The span: 4 kHz unless asked, at most what the rate carries (under half of it, for the filter's slope) and CW_SPAN_MAX
  if (!(span > 0.0)) span = CW_MAX_HZ;
  if (span > rate * 0.45) span = rate * 0.45;
  if (span > CW_SPAN_MAX) span = CW_SPAN_MAX;
  g_span = span;
  // About 12 kHz for a span up to 4 kHz (rounded, as it always was); for a wider one at least three times it (rounded down)
  double target = span <= CW_MAX_HZ ? CW_TARGET_RATE : 3.0 * span;
  g_dec = (int)floor(rate / target + (span <= CW_MAX_HZ ? 0.5 : 0.0));
  if (g_dec < 1) g_dec = 1;
  g_fs = rate / g_dec;
  g_decPhase = 0;
  g_firPos = 0;
  memset(g_firHist, 0, sizeof(g_firHist));

  // The decimation filter: a Blackman-windowed sinc cut off at 4.5 kHz (all a CW passband needs; a little over the span for a wider one),
  // 16 taps for each sample dropped
  if (g_dec == 1) g_firLen = 1;
  else
  {
    g_firLen = 16 * g_dec + 1;
    if (g_firLen > CW_FIR_MAX) g_firLen = CW_FIR_MAX | 1;
  }
  double cutoff = span * 1.125 > 4500.0 ? span * 1.125 : 4500.0;
  double fc = cutoff / rate;
  if (fc > 0.45 / g_dec) fc = 0.45 / g_dec;
  double sum = 0.0;
  for (int i = 0; i < g_firLen; i++)
  {
    double m = i - (g_firLen - 1) / 2.0;
    double sinc = m == 0.0 ? 2.0 * fc : sin(2.0 * M_PI * fc * m) / (M_PI * m);
    double w = g_firLen == 1 ? 1.0 : 0.42 - 0.5 * cos(2.0 * M_PI * i / (g_firLen - 1)) + 0.08 * cos(4.0 * M_PI * i / (g_firLen - 1));
    g_fir[i] = (float)(sinc * w);
    sum += g_fir[i];
  }
  for (int i = 0; i < g_firLen; i++) g_fir[i] = (float)(g_fir[i] / sum);

  // Each channel's filter: two 8 ms boxcars (first null 125 Hz out, about 90 Hz wide at -6 dB), read every 4 ms
  g_box = (int)floor(0.008 * g_fs + 0.5);
  if (g_box > CW_BOX_MAX) g_box = CW_BOX_MAX;
  if (g_box < 8) g_box = 8;
  g_tickSamples = (int)floor(0.004 * g_fs + 0.5);
  if (g_tickSamples < 1) g_tickSamples = 1;
  g_tickMs = 1000.0 * g_tickSamples / g_fs;

  // The FFT: bins about as narrow as 2048 points at 12 kHz make them, a quarter of it between rows
  g_fftN = CW_FFT_BASE;
  while (g_fs / g_fftN > (CW_TARGET_RATE / CW_FFT_BASE) * 1.5 && g_fftN < CW_FFT_MAX) g_fftN *= 2;
  g_fftHop = g_fftN / 4;
  if (g_fft && g_fftCfgN != g_fftN)
  {
    free(g_fft);
    g_fft = 0;
  }
  if (!g_fft) g_fft = kiss_fftr_alloc(g_fftN, 0, 0, 0);
  if (!g_fft) return 0;
  g_fftCfgN = g_fftN;
  for (int i = 0; i < g_fftN; i++) g_window[i] = (float)(0.5 - 0.5 * cos(2.0 * M_PI * i / (g_fftN - 1)));
  memset(g_ring, 0, sizeof(g_ring));
  g_ringPos = 0;
  g_hopCount = 0;
  g_rows = 0;
  g_historyPos = 0;
  g_historyLen = 0;
  g_bins = (int)floor(g_span / (g_fs / g_fftN));
  if (g_bins > CW_BINS_MAX) g_bins = CW_BINS_MAX;
  if (g_bins > g_fftN / 2) g_bins = g_fftN / 2;
  // All of the span is decoded until a range is set (cw_set_range)
  g_minHz = CW_MIN_HZ;
  g_maxHz = g_span;
  g_floorPrimed = 0;
  memset(g_hits, 0, sizeof(g_hits));
  memset(g_ch, 0, sizeof(g_ch));
  g_eventCount = 0;
  return 1;
}

float *cw_input(void) { return g_input; }
unsigned char *cw_row(void) { return g_row; }
int cw_row_bins(void) { return g_bins; }
double cw_bin_hz(void) { return g_fs / g_fftN; }
double cw_span(void) { return g_span; }
int cw_max_channels(void) { return CW_MAX_CHANNELS; }
float *cw_channels(void) { return g_chOut; }
int *cw_events(void) { return g_events; }
int cw_event_count(void) { return g_eventCount; }

// The speed a channel is seeded with (WPM) until the sender's own is learned
void cw_set_init_wpm(double wpm)
{
  if (wpm < 5.0) wpm = 5.0;
  if (wpm > 50.0) wpm = 50.0;
  g_initWpm = wpm;
}
char *cw_revision_text(int slot) { return slot >= 0 && slot < g_revCount ? g_revText[slot] : 0; }

void cw_events_clear(void)
{
  g_eventCount = 0;
  g_revCount = 0;
}

// The rig was retuned (or its mode changed): the passband holds other signals now. The channels are let go, and the noise floor, the
// peak-hold, the counts of rows and the audio kept for replay start again, as at the start
void cw_retune(void)
{
  memset(g_ch, 0, sizeof(g_ch));
  memset(g_chOut, 0, sizeof(g_chOut));
  memset(g_hits, 0, sizeof(g_hits));
  g_floorPrimed = 0;
  g_rows = 0;
  g_historyLen = 0;
}

// ---- Channels

static void channelTune(CwChannel *ch, float freq)
{
  ch->freq = freq;
  double w = 2.0 * M_PI * freq / g_fs;
  ch->dc = cos(w);
  ch->ds = sin(w);
  ch->cD = cos(w * (g_box - 1));
  ch->sD = sin(w * (g_box - 1));
}

static CwChannel *channelOpen(float freq, float holdDb)
{
  for (int i = 0; i < CW_MAX_CHANNELS; i++)
  {
    CwChannel *ch = &g_ch[i];
    if (ch->used) continue;
    memset(ch, 0, sizeof(*ch));
    ch->used = 1;
    ch->id = g_nextId++;
    ch->c = 1.0;
    ch->s = 0.0;
    channelTune(ch, freq);
    ch->holdDb = holdDb;
    // Seeded speed until the sender's own is learned; weighting 3:1
    ch->dit = 1200.0 / g_initWpm;
    ch->dah = ch->dit * 3.0;
    ch->gap = ch->dit;
    ch->charGap = ch->dit * 3.0;
    return ch;
  }
  return 0;
}

// Lengths split in two where the two groups stand furthest apart, on a log scale (so a 3:1 is a 3:1 at any speed): true when the groups
// are at least `ratio` apart, with each group's (geometric) mean; else false, with the mean of them all in *low
static int splitTwo(const double *lengths, int n, double ratio, double *low, double *high)
{
  double v[CW_SPLIT_MAX];
  if (n > CW_SPLIT_MAX) n = CW_SPLIT_MAX;
  for (int i = 0; i < n; i++)
  {
    double x = log(lengths[i]);
    int j = i;
    while (j > 0 && v[j - 1] > x)
    {
      v[j] = v[j - 1];
      j--;
    }
    v[j] = x;
  }
  double total = 0.0;
  for (int i = 0; i < n; i++) total += v[i];
  double best = -1.0, m1Best = 0.0, m2Best = 0.0, below = 0.0;
  for (int i = 1; i < n; i++)
  {
    below += v[i - 1];
    double m1 = below / i, m2 = (total - below) / (n - i);
    double score = (double)i * (n - i) * (m2 - m1) * (m2 - m1);
    if (score > best)
    {
      best = score;
      m1Best = m1;
      m2Best = m2;
    }
  }
  if (best > 0.0 && m2Best - m1Best >= log(ratio))
  {
    *low = exp(m1Best);
    *high = exp(m2Best);
    return 1;
  }
  *low = n > 0 ? exp(total / n) : 0.0;
  return 0;
}

// The sender's dit and dah from their last marks: two groups at least 2:1 apart are the dits and the dahs, whatever the fist's weighting;
// marks all of one length so far are dits when about as long as the spaces between them, dahs when longer, once a space has been measured
// (before that the starting guess stays: a fast sender's first dah taken for a dit against a guessed space would lock the speed far too
// slow, its spaces then read as dropouts). A new speed is learned within a few characters
static void speedLearn(CwChannel *ch)
{
  double low, high;
  if (splitTwo(ch->recent, ch->recentCount, 2.0, &low, &high))
  {
    ch->dit = low;
    ch->dah = high;
  }
  else if (ch->recentCount > 0 && ch->gapCount > 0)
  {
    if (low > 2.0 * ch->gap)
    {
      ch->dah = low;
      ch->dit = low / 3.0;
    }
    else
    {
      ch->dit = low;
      ch->dah = low * 3.0;
    }
  }
}

// The sender's spaces from their last ones (a word's space left out): between the marks of a character, and between characters. Two
// groups at least 1.7:1 apart are those; spaces all of one length so far are a character's own when under two dits, else between characters.
// Learned apart from the marks: a fist's spaces can be longer or shorter than its dits
static void gapLearn(CwChannel *ch)
{
  double low, high;
  if (splitTwo(ch->gaps, ch->gapCount, 1.7, &low, &high))
  {
    ch->gap = low;
    ch->charGap = high;
  }
  else if (ch->gapCount > 0)
  {
    if (low < 2.0 * ch->dit)
    {
      ch->gap = low;
      ch->charGap = low * 3.0;
    }
    else
    {
      ch->charGap = low;
      ch->gap = low / 3.0;
    }
  }
  if (ch->gap < ch->dit * 0.4) ch->gap = ch->dit * 0.4;
  if (ch->gap > ch->dit * 3.0) ch->gap = ch->dit * 3.0;
  if (ch->charGap < ch->gap * 1.7) ch->charGap = ch->gap * 1.7;
}

// ---- The transmission, kept to be read again as more is learned (txRevise)

// A mark of the transmission under way, the first one opening it (told with a 1); a timeline that is full starts another
static void txMark(CwChannel *ch, double d)
{
  if (ch->txOpen && ch->timelineLen >= CW_TIMELINE) ch->txOpen = 0;
  if (!ch->txOpen)
  {
    ch->txOpen = 1;
    ch->timelineLen = 0;
    ch->txLen = 0;
    ch->txText[0] = 0;
    ch->txUnknown = 0;
    emit(ch, 1);
  }
  ch->timeline[ch->timelineLen++] = (float)d;
}

// A space within the transmission (the pause before one isn't kept)
static void txSpace(CwChannel *ch, double s)
{
  if (ch->txOpen && ch->timelineLen < CW_TIMELINE) ch->timeline[ch->timelineLen++] = (float)-s;
}

// A character onto a transmission's text: one space between words, none first
static void txAppend(char *text, int *len, int c)
{
  if (c == ' ' && (*len == 0 || text[*len - 1] == ' ')) return;
  if (*len < CW_TX_TEXT)
  {
    text[*len] = (char)c;
    (*len)++;
  }
  text[*len] = 0;
}

// A character decoded as it comes: out, and onto the transmission's text
static void txEmit(CwChannel *ch, int c)
{
  txAppend(ch->txText, &ch->txLen, c);
  emit(ch, c);
}

// A mark that ended: learned from, unless it is under half a dit (a mark broken up by a fade) and not one of four such in a row (a sender
// who has sped up)
static void markEnded(CwChannel *ch, double d)
{
  ch->marks++;
  txMark(ch, d);
  ch->shortRun = ch->recentCount >= 4 && d < ch->dit * 0.5 ? ch->shortRun + 1 : 0;
  if (ch->shortRun == 0 || ch->shortRun >= 4)
  {
    ch->recent[ch->recentPos] = d;
    ch->recentPos = (ch->recentPos + 1) % CW_RECENT;
    if (ch->recentCount < CW_RECENT) ch->recentCount++;
    speedLearn(ch);
  }
  // 5 to 60 WPM
  if (ch->dit < CW_DIT_MIN_MS) ch->dit = CW_DIT_MIN_MS;
  if (ch->dit > 400.0) ch->dit = 400.0;
  if (ch->dah < ch->dit * 2.0) ch->dah = ch->dit * 2.0;
  if (ch->dah > ch->dit * 6.0) ch->dah = ch->dit * 6.0;
  int dah = d >= (ch->dit + ch->dah) / 2.0;
  if (ch->symLen < CW_SYMBOL_MAX) ch->symbol[ch->symLen] = dah ? '-' : '.';
  ch->symLen++;
  ch->charDone = 0;
  ch->wordDone = 0;
}

// The character's end: half way (on a log scale) between the sender's own space within a character and between characters; the word's
// at 1.6 times the space between characters (3 and 7 units: half way is 4.6)
static double charEndMs(CwChannel *ch)
{
  return sqrt(ch->gap * ch->charGap);
}

static double wordEndMs(CwChannel *ch)
{
  return ch->charGap * 1.6;
}

// A space that ended (the key down again after it): learned from, unless it was a word's space or a pause, or under half a dit (a
// dropout in a fade, not the sender's spacing)
static void spaceEnded(CwChannel *ch, double s)
{
  // A word's space isn't learned from, unless words of one character keep coming (a Farnsworth sender's long spaces between characters,
  // which would otherwise never be learned): then up to CW_FARNSWORTH_DITS
  if (s < ch->dit * 0.5) return;
  if (s >= wordEndMs(ch) && (ch->singleWords < 3 || s >= ch->dit * CW_FARNSWORTH_DITS)) return;
  ch->gaps[ch->gapPos] = s;
  ch->gapPos = (ch->gapPos + 1) % CW_RECENT;
  if (ch->gapCount < CW_RECENT) ch->gapCount++;
  gapLearn(ch);
}

// The sender's timing around one place in the transmission (pos, in the timeline): its dit and dah from the marks within CW_LOCAL either
// side, its spaces from the spaces there (a word's space, a pause and a dropout left out), as speedLearn and gapLearn learn them, the
// channel's own where there are too few. By the transmission's ends the window lies all on the one side, so the first characters are
// judged by what comes after them
typedef struct
{
  double dit, dah, gap, charGap;
} CwTiming;

static void txLocal(CwChannel *ch, int pos, CwTiming *t)
{
  t->dit = ch->dit;
  t->dah = ch->dah;
  t->gap = ch->gap;
  t->charGap = ch->charGap;
  int len = ch->timelineLen;
  if (len == 0) return;
  int from = pos - CW_LOCAL, to = pos + CW_LOCAL;
  if (from < 0)
  {
    to -= from;
    from = 0;
  }
  if (to > len - 1)
  {
    from -= to - (len - 1);
    to = len - 1;
    if (from < 0) from = 0;
  }
  // Marks under half the dit learned are left out, as markEnded leaves them out: marks broken up by a fade
  double marks[CW_SPLIT_MAX], spaces[CW_SPLIT_MAX];
  int nm = 0, ns = 0;
  for (int i = from; i <= to; i++)
  {
    if (ch->timeline[i] > 0.0f && nm < CW_SPLIT_MAX && ch->timeline[i] >= ch->dit * 0.5) marks[nm++] = ch->timeline[i];
    else if (ch->timeline[i] < 0.0f && ns < CW_SPLIT_MAX) spaces[ns++] = -ch->timeline[i];
  }
  double low, high;
  if (splitTwo(marks, nm, 2.0, &low, &high))
  {
    t->dit = low;
    t->dah = high;
  }
  else if (nm >= 3)
  {
    if (low > 2.0 * ch->gap)
    {
      t->dah = low;
      t->dit = low / 3.0;
    }
    else
    {
      t->dit = low;
      t->dah = low * 3.0;
    }
  }
  if (t->dit < CW_DIT_MIN_MS) t->dit = CW_DIT_MIN_MS;
  if (t->dit > 400.0) t->dit = 400.0;
  if (t->dah < t->dit * 2.0) t->dah = t->dit * 2.0;
  if (t->dah > t->dit * 6.0) t->dah = t->dit * 6.0;
  // A word's space is about 7 dits, a dropout under half of one
  int kept = 0;
  for (int i = 0; i < ns; i++)
  {
    if (spaces[i] < t->dit * 5.0 && spaces[i] >= t->dit * 0.5) spaces[kept++] = spaces[i];
    // A Farnsworth sender's spaces between characters, as the channel learned them (longer than 5 dits): kept
    else if (ch->charGap > ch->dit * 4.0 && spaces[i] < ch->charGap * 1.4 && spaces[i] >= t->dit * 0.5) spaces[kept++] = spaces[i];
  }
  if (splitTwo(spaces, kept, 1.7, &low, &high))
  {
    t->gap = low;
    t->charGap = high;
  }
  else if (kept >= 3)
  {
    if (low < 2.0 * t->dit)
    {
      t->gap = low;
      t->charGap = low * 3.0;
    }
    else
    {
      t->charGap = low;
      t->gap = low / 3.0;
    }
  }
  if (t->gap < t->dit * 0.4) t->gap = t->dit * 0.4;
  if (t->gap > t->dit * 3.0) t->gap = t->dit * 3.0;
  if (t->charGap < t->gap * 1.7) t->charGap = t->gap * 1.7;
}

// How unlikely a text looks: the marks that made no character, and the characters of one mark (E, T: what noise and broken timing make
// most)
static int txDoubt(const char *text, int len, int unknown)
{
  int doubt = unknown * 2;
  for (int i = 0; i < len; i++)
  {
    if (text[i] == 'E' || text[i] == 'T') doubt++;
  }
  return doubt;
}

// The transmission read again, each mark and space by the timing around it (txLocal), the space under way (trailingUp, ms) as its last:
// the rules of the characters decoded as they came (markEnded, upCheck), so it differs where the timing known now does. *unknown: the
// characters whose marks made none
static int txDecode(CwChannel *ch, double trailingUp, char *out, int *unknown)
{
  int n = 0;
  out[0] = 0;
  *unknown = 0;
  // At the 60 WPM limit what comes is noise's blips: no reading (-1), so what was decoded before them stays (txRevise)
  if (ch->dit <= CW_DIT_MIN_MS * 1.1) return -1;
  char symbol[CW_SYMBOL_MAX + 1];
  int symLen = 0;
  CwTiming t;
  for (int i = 0; i <= ch->timelineLen; i++)
  {
    double v = i < ch->timelineLen ? ch->timeline[i] : -trailingUp;
    txLocal(ch, i < ch->timelineLen ? i : ch->timelineLen - 1, &t);
    if (v > 0.0)
    {
      if (symLen < CW_SYMBOL_MAX) symbol[symLen] = v >= (t.dit + t.dah) / 2.0 ? '-' : '.';
      symLen++;
      continue;
    }
    // The character's and the word's ends as charEndMs and wordEndMs have them
    if (-v > sqrt(t.gap * t.charGap) && symLen > 0)
    {
      symbol[symLen < CW_SYMBOL_MAX ? symLen : CW_SYMBOL_MAX] = 0;
      int c = symLen <= CW_SYMBOL_MAX ? morseLookup(symbol) : 0;
      if (c) txAppend(out, &n, c);
      else (*unknown)++;
      symLen = 0;
      if (-v > t.charGap * 1.6) txAppend(out, &n, ' ');
    }
  }
  return n;
}
// The transmission read again: when it comes out differently from what was sent, and doesn't look less likely (txDoubt), its whole
// text is sent again in its place
static void txRevise(CwChannel *ch, double trailingUp)
{
  char out[CW_TX_TEXT + 1];
  int unknown;
  int n = txDecode(ch, trailingUp, out, &unknown);
  if (n < 0 || (n == ch->txLen && memcmp(out, ch->txText, n) == 0)) return;
  if (txDoubt(out, n, unknown) > txDoubt(ch->txText, ch->txLen, ch->txUnknown)) return;
  memcpy(ch->txText, out, n + 1);
  ch->txLen = n;
  ch->txUnknown = unknown;
  if (g_revCount >= CW_REVISIONS_MAX || g_eventCount >= CW_EVENTS_MAX) return;
  memcpy(g_revText[g_revCount], out, n + 1);
  emit(ch, -(g_revCount + 1));
  g_revCount++;
}

// While the key is up: the character and then the word end, at the sender's own spaces, and the transmission is read again with them;
// a long pause ends it (read once more)
static void upCheck(CwChannel *ch)
{
  int ended = 0, wordEnded = 0;
  if (!ch->charDone && ch->symLen > 0 && ch->upMs > charEndMs(ch))
  {
    ch->symbol[ch->symLen < CW_SYMBOL_MAX ? ch->symLen : CW_SYMBOL_MAX] = 0;
    int c = ch->symLen <= CW_SYMBOL_MAX ? morseLookup(ch->symbol) : 0;
    // Nothing out while the speed learned is at the 60 WPM limit: that is noise's blips, not a sender
    if (c && ch->dit > CW_DIT_MIN_MS * 1.1) txEmit(ch, c);
    else if (!c) ch->txUnknown++;
    ch->symLen = 0;
    ch->charDone = 1;
    ch->wordChars++;
    ended = 1;
  }
  if (ch->charDone && !ch->wordDone && ch->upMs > wordEndMs(ch))
  {
    txEmit(ch, ' ');
    ch->singleWords = ch->wordChars == 1 ? ch->singleWords + 1 : 0;
    ch->wordChars = 0;
    ch->wordDone = 1;
    ended = 1;
    wordEnded = 1;
  }
  // Read again at each character, a long transmission at its word ends only
  if (ended && ch->txOpen && (wordEnded || ch->timelineLen <= CW_REVISE_EACH_CHAR)) txRevise(ch, ch->upMs);
  double pause = wordEndMs(ch) * 2.0;
  if (pause < CW_TX_PAUSE_MS) pause = CW_TX_PAUSE_MS;
  if (ch->txOpen && ch->upMs > pause)
  {
    txRevise(ch, ch->upMs);
    ch->txOpen = 0;
  }
}

// Every 4 ms: the channel's level against its threshold, then the key's state into the timing engine. A key-up shorter than a third of a
// dit is a dropout (QSB, a noise hole) and the mark goes on; a key-down as short is a noise spike and the space goes on
static void channelTick(CwChannel *ch, float a)
{
  // The first 150 ms only measure the noise (their average), with the key up: a level started from one tick of noise would be read as
  // a signal over it for a while
  if (ch->primed < CW_WARMUP_TICKS)
  {
    ch->primed++;
    ch->noise += (a - ch->noise) / ch->primed;
    ch->sig = ch->noise;
    ch->seenMs += g_tickMs;
    return;
  }
  // The noise: the average level while the key is up (quicker down than up, so a carrier coming on doesn't lift it). The signal: the
  // average while it is down, rising quickly to a stronger mark (but not so quickly that a few ticks of a noise peak count as one) and
  // falling slowly through the spaces (QSB is followed both ways)
  if (!ch->key) ch->noise += (a - ch->noise) * (a < ch->noise ? 0.05f : 0.01f);
  if (a > ch->sig) ch->sig += (a - ch->sig) * 0.1f;
  else if (ch->key) ch->sig += (a - ch->sig) * 0.02f;
  // Past a word's space it falls back to the noise within a second: a sender who has stopped leaves no level for noise peaks to cross
  else if (ch->state == 0 && ch->upMs > wordEndMs(ch)) ch->sig += (ch->noise - ch->sig) * 0.01f;
  else ch->sig += (ch->noise - ch->sig) * 0.0015f;
  float span = ch->sig - ch->noise;
  int key = 0;
  // Under 8 dB between the signal and the noise there's nothing to read
  ch->seenMs += g_tickMs;
  if (ch->sig > ch->noise * 2.5f && ch->seenMs < CW_SEEN_MS)
  {
    float high = ch->noise + span * 0.55f;
    float low = ch->noise + span * 0.40f;
    key = ch->key ? a > low : a > high;
  }
  ch->key = key;
#ifdef CW_DEBUG
  cwDebugTick(ch, a);
#endif

  double glitch = ch->dit * 0.3;
  if (glitch < 10.0) glitch = 10.0;
  double ms = g_tickMs;
  switch (ch->state)
  {
    case 0:
      if (key)
      {
        ch->state = 3;
        ch->pendMs = ms;
      }
      else
      {
        ch->upMs += ms;
        upCheck(ch);
      }
      break;
    case 3:
      if (key)
      {
        ch->pendMs += ms;
        if (ch->pendMs >= glitch)
        {
          if (ch->marks > 0)
          {
            txSpace(ch, ch->upMs);
            spaceEnded(ch, ch->upMs);
          }
          ch->state = 1;
          ch->downMs = ch->pendMs;
        }
      }
      else
      {
        ch->state = 0;
        ch->upMs += ch->pendMs + ms;
        upCheck(ch);
      }
      break;
    case 1:
      if (key) ch->downMs += ms;
      else
      {
        ch->state = 2;
        ch->pendMs = ms;
      }
      break;
    case 2:
      if (key)
      {
        ch->state = 1;
        ch->downMs += ch->pendMs + ms;
      }
      else
      {
        ch->pendMs += ms;
        if (ch->pendMs >= glitch)
        {
          markEnded(ch, ch->downMs);
          ch->state = 0;
          ch->upMs = ch->pendMs;
        }
      }
      break;
  }
  // Its carrier gone for long: the channel is let go (its last character is out long before)
  if (ch->seenMs > CW_CHANNEL_IDLE_MS) ch->used = 0;
}

static void channelMeasure(CwChannel *ch, float x)
{
  // The mixer: the carrier to 0 Hz
  double c = ch->c * ch->dc - ch->s * ch->ds;
  double s = ch->s * ch->dc + ch->c * ch->ds;
  if (++ch->renorm >= 1024)
  {
    double m = 1.0 / sqrt(c * c + s * s);
    c *= m;
    s *= m;
    ch->renorm = 0;
  }
  ch->c = c;
  ch->s = s;
  float i = (float)(x * c);
  float q = (float)(-x * s);
  int p = ch->pos;
  ch->t1i += i - ch->m1i[p];
  ch->t1q += q - ch->m1q[p];
  ch->m1i[p] = i;
  ch->m1q[p] = q;
  float i1 = (float)ch->t1i;
  float q1 = (float)ch->t1q;
  ch->t2i += i1 - ch->m2i[p];
  ch->t2q += q1 - ch->m2q[p];
  ch->m2i[p] = i1;
  ch->m2q[p] = q1;
  // The phasor D samples back: the decoding filter's mixer, and the rebuilt signal's carrier
  ch->pc = c * ch->cD + s * ch->sD;
  ch->ps = s * ch->cD - c * ch->sD;
  if (ch->sub)
  {
    double scale = 2.0 / ((double)g_box * g_box);
    ch->rec = (float)((ch->t2i * ch->pc - ch->t2q * ch->ps) * scale);
  }
  else ch->rec = 0.0f;
}

static void channelDecode(CwChannel *ch, float x)
{
  float i = (float)(x * ch->pc);
  float q = (float)(-x * ch->ps);
  int p = ch->pos;
  ch->s1i += i - ch->r1i[p];
  ch->s1q += q - ch->r1q[p];
  ch->r1i[p] = i;
  ch->r1q[p] = q;
  float i1 = (float)ch->s1i;
  float q1 = (float)ch->s1q;
  ch->s2i += i1 - ch->r2i[p];
  ch->s2q += q1 - ch->r2q[p];
  ch->r2i[p] = i1;
  ch->r2q[p] = q1;
  ch->pos = p + 1 >= g_box ? 0 : p + 1;
  if (++ch->tick >= g_tickSamples)
  {
    ch->tick = 0;
    double scale = 1.0 / ((double)g_box * g_box);
    float a = (float)(sqrt(ch->s2i * ch->s2i + ch->s2q * ch->s2q) * scale);
    channelTick(ch, a);
  }
}

// The audio kept, k samples back from the newest (0: the newest)
static float historyAt(int k)
{
  if (k >= g_historyLen) return 0.0f;
  return g_history[(g_historyPos - 1 - k + 2 * CW_HISTORY) % CW_HISTORY];
}

// A new channel: the last 0.6 s of audio replayed into it, so the start of what found it isn't lost
static void channelReplay(CwChannel *ch)
{
  int n = (int)(0.6 * g_fs) < g_historyLen ? (int)(0.6 * g_fs) : g_historyLen;
  for (int j = n - 1; j >= 0; j--)
  {
    channelMeasure(ch, historyAt(j));
    channelDecode(ch, historyAt(j + g_box - 1));
  }
  ch->seenMs = 0.0;
}

// CW decoded or not (the viewer's mode: off in FT8 and SSTV, which decode their own audio): off, the channels are let go and only the
// waterfall's rows are made; on again, carriers are found afresh
void cw_set_decode(int on)
{
  on = on ? 1 : 0;
  if (on == g_decodeOn) return;
  g_decodeOn = on;
  memset(g_ch, 0, sizeof(g_ch));
  memset(g_chOut, 0, sizeof(g_chOut));
  memset(g_hits, 0, sizeof(g_hits));
  g_eventCount = 0;
  g_revCount = 0;
}

// The audio decoded (Settings, Min Freq and Max Freq; Hz): no carrier is found outside it, and the channels outside it are let go
void cw_set_range(double minHz, double maxHz)
{
  if (minHz < CW_MIN_HZ) minHz = CW_MIN_HZ;
  if (maxHz > g_span) maxHz = g_span;
  if (maxHz < minHz + 100.0) maxHz = minHz + 100.0;
  g_minHz = minHz;
  g_maxHz = maxHz;
  for (int i = 0; i < CW_MAX_CHANNELS; i++)
  {
    CwChannel *ch = &g_ch[i];
    if (ch->used && (ch->freq < g_minHz || ch->freq > g_maxHz)) ch->used = 0;
  }
}

// ---- Spectrum: the waterfall's row, each bin's noise floor, and the carriers found

static int floatCompare(const void *a, const void *b)
{
  float x = *(const float *)a, y = *(const float *)b;
  return (x > y) - (x < y);
}

static void spectrum(void)
{
  for (int i = 0; i < g_fftN; i++) g_fftIn[i] = g_ring[(g_ringPos + i) % g_fftN] * g_window[i];
  kiss_fftr(g_fft, g_fftIn, g_fftOut);
  for (int k = 0; k < g_bins; k++)
  {
    float p = g_fftOut[k].r * g_fftOut[k].r + g_fftOut[k].i * g_fftOut[k].i;
    g_db[k] = 10.0f * log10f(p + 1e-20f);
  }
  // Nothing is judged until the FFT's samples are all audio (the first rows are part silence, under any carrier or noise)
  if (++g_rows <= g_fftN / g_fftHop)
  {
    memset(g_row, 0, sizeof(g_row));
    return;
  }

  // Each block of bins' noise floor: its median (a carrier or two in it don't lift it), between the blocks' middles a straight line
  float level[CW_BINS_MAX / CW_FLOOR_BLOCK + 1];
  float sorted[CW_FLOOR_BLOCK];
  int blocks = (g_bins + CW_FLOOR_BLOCK - 1) / CW_FLOOR_BLOCK;
  for (int b = 0; b < blocks; b++)
  {
    int start = b * CW_FLOOR_BLOCK;
    int n = g_bins - start < CW_FLOOR_BLOCK ? g_bins - start : CW_FLOOR_BLOCK;
    memcpy(sorted, g_db + start, n * sizeof(float));
    qsort(sorted, n, sizeof(float), floatCompare);
    level[b] = sorted[n / 2];
  }
  for (int k = 0; k < g_bins; k++)
  {
    float pos = (float)k / CW_FLOOR_BLOCK - 0.5f;
    int b = (int)floorf(pos);
    float t = pos - b;
    if (b < 0)
    {
      b = 0;
      t = 0.0f;
    }
    if (b >= blocks - 1)
    {
      b = blocks - 1;
      t = 0.0f;
    }
    float f = b + 1 < blocks ? level[b] + (level[b + 1] - level[b]) * t : level[b];
    if (!g_floorPrimed)
    {
      g_floor[k] = f;
      g_hold[k] = g_db[k];
    }
    // A floor that rises 6 dB at once (the filter widened, the band opened, a retune) is followed at once; otherwise smoothly
    else if (f > g_floor[k] + 6.0f) g_floor[k] = f;
    else g_floor[k] += (f - g_floor[k]) * 0.1f;
    // The peak-hold falls 0.25 dB a row (about 6 dB a second), so a keyed carrier stays found between its marks
    g_hold[k] = g_db[k] > g_hold[k] - 0.25f ? g_db[k] : g_hold[k] - 0.25f;
    // The waterfall's row: 5 dB under the floor black, 40 dB over it full
    float v = (g_db[k] - g_floor[k] + 5.0f) * (255.0f / 45.0f);
    g_row[k] = v < 0.0f ? 0 : v > 255.0f ? 255 : (unsigned char)v;
  }
  g_floorPrimed = 1;
  // Not decoding CW: the row is all that is wanted
  if (!g_decodeOn) return;

  // Each channel's carrier still there: its bin or one either side over the floor, and narrow (over the bins 35 Hz either side as well:
  // static and a sloping floor are wide)
  double binHz = g_fs / g_fftN;
  int side = (int)ceil(35.0 / binHz);
  for (int i = 0; i < CW_MAX_CHANNELS; i++)
  {
    CwChannel *ch = &g_ch[i];
    if (!ch->used) continue;
    int k = (int)floor(ch->freq / binHz + 0.5);
    for (int j = k - 1; j <= k + 1; j++)
    {
      if (j < 0 || j >= g_bins || g_db[j] - g_floor[j] < CW_SEEN_DB) continue;
      if ((j - side < 0 || g_db[j] - g_db[j - side] >= 6.0f) && (j + side >= g_bins || g_db[j] - g_db[j + side] >= 6.0f)) ch->seenMs = 0.0;
    }
  }

  // A row with much of the passband over the floor at once is a crash of static or the rig changing (a retune, the filter, the AGC):
  // no carrier is counted in it
  int over = 0;
  for (int k = 0; k < g_bins; k++)
  {
    if (g_db[k] - g_floor[k] >= CW_DETECT_DB) over++;
  }
  int broadband = over > g_bins / 10;

  // Each bin's count of rows with a narrow carrier in it (or in a bin either side: a carrier between two bins), standing over the bins
  // 35 Hz either side as well: static and splatter are wide
  for (int k = 1; k < g_bins - 1; k++)
  {
    float above = g_db[k] - g_floor[k];
    if (g_db[k - 1] - g_floor[k - 1] > above) above = g_db[k - 1] - g_floor[k - 1];
    if (g_db[k + 1] - g_floor[k + 1] > above) above = g_db[k + 1] - g_floor[k + 1];
    float peak = g_db[k] > g_db[k - 1] ? g_db[k] : g_db[k - 1];
    if (g_db[k + 1] > peak) peak = g_db[k + 1];
    int narrow = (k - side < 0 || peak - g_db[k - side] >= 6.0f) && (k + side >= g_bins || peak - g_db[k + side] >= 6.0f);
    if (!broadband && narrow && above >= CW_DETECT_DB) g_hits[k] = g_hits[k] + 1.0f > 6.0f ? 6.0f : g_hits[k] + 1.0f;
    else g_hits[k] = g_hits[k] - 0.34f < 0.0f ? 0.0f : g_hits[k] - 0.34f;
  }

  // Carriers: a bin over its floor now, seen in enough rows, and the highest peak-hold within the channel spacing (a keyed carrier's
  // sidebands are under its own). One near a channel's frequency is that channel (whose frequency follows it slowly); another is a new one
  // Within the audio decoded (cw_set_range)
  int low = (int)ceil(g_minHz / binHz);
  int high = (int)floor(g_maxHz / binHz);
  int span = (int)ceil(CW_CHANNEL_SPACING / binHz);
  for (int k = low > 2 ? low : 2; k < g_bins - 2 && k <= high; k++)
  {
    if (g_db[k] - g_floor[k] < CW_DETECT_DB || g_hits[k] < CW_DETECT_HITS) continue;
    int top = 1;
    for (int j = k - span; j <= k + span && top; j++)
    {
      if (j >= 0 && j < g_bins && j != k && (g_hold[j] > g_hold[k] || (g_hold[j] == g_hold[k] && j < k))) top = 0;
    }
    if (!top) continue;
    float a = g_db[k - 1], b = g_db[k], c = g_db[k + 1];
    float denom = a - 2.0f * b + c;
    float offset = denom != 0.0f ? 0.5f * (a - c) / denom : 0.0f;
    if (offset > 0.5f || offset < -0.5f) offset = 0.0f;
    float freq = (float)((k + offset) * binHz);
    CwChannel *near = 0;
    for (int i = 0; i < CW_MAX_CHANNELS; i++)
    {
      CwChannel *ch = &g_ch[i];
      if (ch->used && fabsf(ch->freq - freq) < CW_CHANNEL_SPACING && (!near || fabsf(ch->freq - freq) < fabsf(near->freq - freq))) near = ch;
    }
    if (near)
    {
      if (fabsf(near->freq - freq) < 12.0f) channelTune(near, near->freq + (freq - near->freq) * 0.05f);
      near->holdDb = g_hold[k];
    }
    else
    {
      CwChannel *ch = channelOpen(freq, g_hold[k]);
      if (ch) channelReplay(ch);
    }
  }

  // Two channels that have drifted within the spacing of each other: the weaker goes
  for (int i = 0; i < CW_MAX_CHANNELS; i++)
  {
    for (int j = i + 1; j < CW_MAX_CHANNELS; j++)
    {
      CwChannel *x = &g_ch[i], *y = &g_ch[j];
      if (x->used && y->used && fabsf(x->freq - y->freq) < CW_CHANNEL_SPACING) (x->holdDb < y->holdDb ? x : y)->used = 0;
    }
  }

  // The channels' table out (cwChannelOut): id, frequency, WPM, SNR (dB), key down, in use, weighting (dah to dit), peak level (dB)
  for (int i = 0; i < CW_MAX_CHANNELS; i++)
  {
    CwChannel *ch = &g_ch[i];
    float *out = g_chOut + i * CW_CHANNEL_FIELDS;
    out[0] = (float)ch->id;
    out[1] = ch->freq;
    out[2] = (float)(1200.0 / ch->dit);
    out[3] = ch->noise > 0.0f ? 20.0f * log10f(ch->sig / ch->noise) : 0.0f;
    ch->sub = ch->used && ch->primed >= CW_WARMUP_TICKS && out[3] >= CW_SUB_SNR && ch->seenMs < CW_SEEN_MS && ch->marks >= CW_SUB_MARKS;
    out[4] = (float)ch->key;
    out[5] = (float)ch->used;
    out[6] = (float)(ch->dah / ch->dit);
    out[7] = ch->holdDb;
  }
}

// ---- The audio in

int cw_process(int n)
{
  int row = 0;
  if (n > CW_INPUT_MAX) n = CW_INPUT_MAX;
  for (int j = 0; j < n; j++)
  {
    // The decimation filter's history is kept twice over, so the taps read it in one straight run
    g_firHist[g_firPos] = g_input[j];
    g_firHist[g_firPos + g_firLen] = g_input[j];
    g_firPos = g_firPos + 1 >= g_firLen ? 0 : g_firPos + 1;
    if (++g_decPhase < g_dec) continue;
    g_decPhase = 0;
    float x = 0.0f;
    const float *h = g_firHist + g_firPos;
    for (int t = 0; t < g_firLen; t++) x += h[t] * g_fir[g_firLen - 1 - t];

    g_ring[g_ringPos] = x;
    g_ringPos = g_ringPos + 1 >= g_fftN ? 0 : g_ringPos + 1;
    g_history[g_historyPos] = x;
    g_historyPos = g_historyPos + 1 >= CW_HISTORY ? 0 : g_historyPos + 1;
    if (g_historyLen < CW_HISTORY) g_historyLen++;
    // Each channel's measuring filter on the audio now (and the strong ones' signals rebuilt D samples back); then each channel decodes
    // the audio D samples back with the strong signals taken out, all but its own. Not decoding CW: none
    if (g_decodeOn)
    {
      float total = 0.0f;
      for (int i = 0; i < CW_MAX_CHANNELS; i++)
      {
        if (!g_ch[i].used) continue;
        channelMeasure(&g_ch[i], x);
        total += g_ch[i].rec;
      }
      float xd = historyAt(g_box - 1);
      for (int i = 0; i < CW_MAX_CHANNELS; i++)
      {
        if (g_ch[i].used) channelDecode(&g_ch[i], xd - total + g_ch[i].rec);
      }
    }
    if (++g_hopCount >= g_fftHop)
    {
      g_hopCount = 0;
      spectrum();
      row = 1;
    }
  }
  return row;
}
