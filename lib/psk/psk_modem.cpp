#include "psk_modem.hpp"
#include "psk_varicode.hpp"
#include <cmath>
#include <algorithm>
#include <numeric>

namespace Psk {

static constexpr double M_PI_ = 3.14159265358979323846;
static constexpr double TWOPI = 2.0 * M_PI_;
static constexpr double HALF_PI = M_PI_ / 2.0;
static constexpr int FIRLEN = 64;
static constexpr int SQLDECAY = 50;

static inline double decayavg(double avg, double val, int decay) {
    return avg + (val - avg) / decay;
}

static inline double clamp(double v, double lo, double hi) {
    return std::max(lo, std::min(hi, v));
}

// 65-tap raised-cosine FIR (same as fldigi gmfir1c)
static std::vector<double> raisedcosfilt(int len) {
    std::vector<double> c(len + 1);
    for (int i = 0; i <= len; i++) {
        c[i] = (1.0 - std::cos(TWOPI * i / len)) / (2.0 * len);
    }
    return c;
}

// G3PLX 4-bit matched filter coefficients from fldigi (gmfir2c, unity gain)
static const double gmfir2c[FIRLEN + 1] = {
    0.000625000, 0.000820912, 0.001374651, 0.002188141, 0.003110600,
    0.003956273, 0.004526787, 0.004635947, 0.004134515, 0.002932456,
    0.001016352, -0.001539947, -0.004572751, -0.007834665, -0.011009254,
    -0.013733305, -0.015625000, -0.016315775, -0.015483216, -0.012882186,
    -0.008371423, -0.001933193, 0.006315933, 0.016124399, 0.027115485,
    0.038807198, 0.050640928, 0.062016866, 0.072333574, 0.081028710,
    0.087617820, 0.091728168, 0.093125000, 0.091728168, 0.087617820,
    0.081028710, 0.072333574, 0.062016866, 0.050640928, 0.038807198,
    0.027115485, 0.016124399, 0.006315933, -0.001933193, -0.008371423,
    -0.012882186, -0.015483216, -0.016315775, -0.015625000, -0.013733305,
    -0.011009254, -0.007834665, -0.004572751, -0.001539947, 0.001016352,
    0.002932456, 0.004134515, 0.004635947, 0.004526787, 0.003956273,
    0.003110600, 0.002188141, 0.001374651, 0.000820912, 0.000625000
};

PskModem::FirFilter::FirFilter(const std::vector<double>& c, int dec)
    : coeffs(c), decimation(dec), phase(0), buf_idx(0) {
    buf_real.resize(coeffs.size(), 0.0);
    buf_imag.resize(coeffs.size(), 0.0);
}

void PskModem::FirFilter::reset() {
    std::fill(buf_real.begin(), buf_real.end(), 0.0);
    std::fill(buf_imag.begin(), buf_imag.end(), 0.0);
    phase = 0;
    buf_idx = 0;
}

bool PskModem::FirFilter::process(const cmplx& in, cmplx& out) {
    buf_real[buf_idx] = in.real();
    buf_imag[buf_idx] = in.imag();
    buf_idx = (buf_idx + 1) % coeffs.size();

    phase = (phase + 1) % decimation;
    if (phase == 0) {
        double rsum = 0.0, isum = 0.0;
        int k = buf_idx;
        int const n = static_cast<int>(coeffs.size());
        for (int i = 0; i < n; ++i) {
            --k;
            if (k < 0) k += n;
            rsum += coeffs[i] * buf_real[k];
            isum += coeffs[i] * buf_imag[k];
        }
        out = cmplx(rsum, isum);
        return true;
    }
    return false;
}

PskModem::PskModem(double rxSampleRate, double txSampleRate)
    : rxSampleRate_(rxSampleRate), txSampleRate_(txSampleRate) {
    auto fir1c = raisedcosfilt(FIRLEN);
    std::vector<double> fir2c(gmfir2c, gmfir2c + FIRLEN + 1);
    fir1_ = FirFilter(fir1c, SAMPLES_PER_SYMBOL_RX / SYNC_BUF_SIZE);
    fir2_ = FirFilter(fir2c, 1);
    buildTxShape();
    syncBuf_.resize(SYNC_BUF_SIZE, 0.0);
}

PskModem::~PskModem() = default;

void PskModem::buildTxShape() {
    txShape_.resize(SAMPLES_PER_SYMBOL_TX);
    for (int i = 0; i < SAMPLES_PER_SYMBOL_TX; i++) {
        double phi = M_PI_ * i / SAMPLES_PER_SYMBOL_TX;
        txShape_[i] = 0.5 * (1.0 + std::cos(phi));
    }
}

void PskModem::setFrequency(double freq) {
    if (std::abs(frequency_ - freq) > 0.01) {
        frequency_ = freq;
        baseFrequency_ = freq;
        phaseInc_ = TWOPI * frequency_ / rxSampleRate_;
        freqError_ = 0.0;
    }
}

void PskModem::rxInit() {
    frequency_ = baseFrequency_;
    phaseAcc_ = 0.0;
    phaseInc_ = TWOPI * frequency_ / rxSampleRate_;
    prevSymbol_ = cmplx(1.0, 0.0);
    fir1_.reset();
    fir2_.reset();
    std::fill(syncBuf_.begin(), syncBuf_.end(), 0.0);
    bitClk_ = 0.0;
    shreg_ = 0;
    dcdShreg_ = 0;
    dcd_ = false;
    acquire_ = dcdBits_ * 2;
    hang_ = 0;
    inPwr_ = 0.0;
    sigPwr_ = 0.0;
    qualityCos_ = 0.0;
    qualitySin_ = 0.0;
    quality_ = 0.0;
    metric_ = 0.0;
    avgAmp_ = 0.0;
    freqError_ = 0.0;
    snr_ = 0.0;
    rxChars_.clear();
}

void PskModem::txInit() {
    txBuffer_.clear();
}

int PskModem::rxProcess(const int16_t* samples, int count) {
    if (!samples || count <= 0) return 0;

    int symbolsDecoded = 0;

    for (int i = 0; i < count; i++) {
        double sample = samples[i] / 32768.0;
        inPwr_ = decayavg(inPwr_, sample * sample, SAMPLES_PER_SYMBOL_RX);

        cmplx z(sample * std::cos(phaseAcc_), sample * std::sin(phaseAcc_));
        phaseAcc_ += phaseInc_;
        if (phaseAcc_ >= TWOPI) phaseAcc_ -= TWOPI;

        cmplx z1;
        if (fir1_.process(z, z1)) {
            cmplx z2;
            fir2_.process(z1, z2);

            int idx = static_cast<int>(bitClk_);
            if (idx < 0 || idx >= SYNC_BUF_SIZE) continue;
            double mag = std::abs(z2);
            if (std::isnan(mag) || std::isinf(mag)) continue;
            sigPwr_ = decayavg(sigPwr_, mag * mag, SYNC_BUF_SIZE * 2);
            syncBuf_[idx] = 0.8 * syncBuf_[idx] + 0.2 * mag;

            int symSteps = SYNC_BUF_SIZE / 2;
            double asym = 0.0, asum = 0.0;
            for (int k = 0; k < symSteps; k++) {
                asym += syncBuf_[k] - syncBuf_[k + symSteps];
                asum += syncBuf_[k] + syncBuf_[k + symSteps];
            }
            double err = (asum == 0) ? 0 : asym / asum;
            if (std::isnan(err) || std::isinf(err)) err = 0;
            bitClk_ -= err / (5.0 * SYNC_BUF_SIZE / 16.0);
            bitClk_ += 1.0;

            if (bitClk_ < 0) bitClk_ += SYNC_BUF_SIZE;
            if (bitClk_ >= SYNC_BUF_SIZE) {
                bitClk_ -= SYNC_BUF_SIZE;
                rxSymbol(z2);
                symbolsDecoded++;
            }
        }
    }
    return symbolsDecoded;
}

void PskModem::rxSymbol(const cmplx& symbol) {
    double phase = std::arg(std::conj(prevSymbol_) * symbol);
    prevSymbol_ = symbol;

    if (phase < 0) phase += TWOPI;

    // In BPSK, bits = 0 (no phase shift) or 2 (phase reversal)
    int bits = (((int)(phase / M_PI_ + 0.5)) & 1) << 1;

    // RTTY-style power concentration: ratio of 31Hz filtered carrier to wideband input
    double const concentration = sigPwr_ / (inPwr_ + 1e-9);
    double const concScale = clamp((concentration - 0.03) / 0.12, 0.0, 1.0);

    // Symmetric vector smoothing quality metric (same decay in all directions)
    double cval = std::cos(2.0 * phase);
    double sval = std::sin(2.0 * phase);
    qualityCos_ = decayavg(qualityCos_, cval, 32);
    qualitySin_ = decayavg(qualitySin_, sval, 32);
    double const coherence = std::max(0.0, qualityCos_ * qualityCos_ + qualitySin_ * qualitySin_);

    // Combined metric: requires both phase coherence AND power concentration (like RTTY)
    metric_ = clamp(100.0 * coherence * concScale, 0.0, 100.0);
    snr_ = metric_;

    // DCD tracking for preamble (0xAAAA / 0xAAAAAAAA) and carrier postamble (0x00000000)
    dcdShreg_ = (dcdShreg_ << 2) | bits;
    if ((dcdShreg_ & 0xFFFF) == 0xAAAA || dcdShreg_ == 0xAAAAAAAA) {
        dcd_ = true;
        hang_ = 32;
        qualityCos_ = 1.0;
        qualitySin_ = 0.0;
        metric_ = 100.0;
    } else if (dcdShreg_ == 0x00000000) {
        if (hang_ > 0) hang_--;
        if (hang_ <= 0) dcd_ = false;
    } else if (metric_ >= squelch_) {
        dcd_ = true;
        hang_ = 16;
    } else {
        if (hang_ > 0) {
            hang_--;
            dcd_ = true;
        } else {
            dcd_ = false;
        }
    }

    // Phase AFC: track carrier within +/- 20 Hz of nominal channel frequency
    if (afc_ && dcd_) {
        double idealPhase = (bits == 0) ? 0.0 : M_PI_;
        double phaseErr = phase - idealPhase;
        if (phaseErr > M_PI_) phaseErr -= TWOPI;
        if (phaseErr < -M_PI_) phaseErr += TWOPI;

        if (std::abs(phaseErr) < HALF_PI) {
            double ferr = (phaseErr / TWOPI) * BAUD;
            freqError_ = decayavg(freqError_, ferr, 12);
            double newFreq = frequency_ - freqError_ * 0.15;
            if (std::abs(newFreq - baseFrequency_) <= 20.0) {
                frequency_ = newFreq;
                phaseInc_ = TWOPI * frequency_ / rxSampleRate_;
            }
        }
    }

    // Varicode bit decode:
    // bits == 0 -> no phase change -> Varicode bit 1
    // bits == 2 -> 180 deg phase reversal -> Varicode bit 0
    int bit = (bits == 0) ? 1 : 0;
    if (reverse_) bit = 1 - bit;
    rxBit(bit);
}

void PskModem::rxBit(int bit) {
    shreg_ = (shreg_ << 1) | bit;
    if ((shreg_ & 3) == 0) {
        int c = Psk::varicode_decode(shreg_ >> 2);
        // Only accept printable ASCII (or \r, \n) while squelch is open (like RTTY)
        if (dcd_ && (metric_ >= squelch_ || squelch_ <= 0.0)) {
            if ((c >= 32 && c <= 126) || c == '\r' || c == '\n') {
                rxChars_.push_back(static_cast<char>(c));
            }
        }
        shreg_ = 0;
    }
}

std::string PskModem::takeOutput() {
    std::string result = rxChars_;
    rxChars_.clear();
    return result;
}

std::vector<int16_t> PskModem::modulateText(const std::string& text, double f0) {
    txInit();
    double txPhaseInc = TWOPI * f0 / txSampleRate_;
    double txPhase = 0.0;
    cmplx prevSym(1.0, 0.0);
    bool isFirstSymbol = true;

    auto sendSymbol = [&](int sym, bool isLastHalfTaper = false) {
        // Differential BPSK: 0 = 180 deg reversal, 1 = 0 deg
        cmplx currSym = (sym == 0) ? -prevSym : prevSym;

        for (int i = 0; i < SAMPLES_PER_SYMBOL_TX; i++) {
            // Raised cosine shaping from prevSym to currSym
            double shapeA = txShape_[i];             // 1.0 -> 0.0
            double shapeB = 1.0 - shapeA;           // 0.0 -> 1.0
            double ival = shapeA * prevSym.real() + shapeB * currSym.real();
            double qval = shapeA * prevSym.imag() + shapeB * currSym.imag();

            // Smooth cosine ramp-up on the first half of the first symbol (no click)
            if (isFirstSymbol && i < SAMPLES_PER_SYMBOL_TX / 2) {
                double taper = 0.5 * (1.0 - std::cos(TWOPI * i / SAMPLES_PER_SYMBOL_TX));
                ival *= taper;
                qval *= taper;
            }

            // Smooth cosine ramp-down on the second half of the last postamble symbol
            if (isLastHalfTaper && i >= SAMPLES_PER_SYMBOL_TX / 2) {
                double taper = 0.5 * (1.0 + std::cos(TWOPI * (i - SAMPLES_PER_SYMBOL_TX / 2) / SAMPLES_PER_SYMBOL_TX));
                ival *= taper;
                qval *= taper;
            }

            double out = ival * std::cos(txPhase) - qval * std::sin(txPhase);
            txBuffer_.push_back(static_cast<int16_t>(clamp(out * 32767.0, -32767.0, 32767.0)));
            txPhase += txPhaseInc;
            if (txPhase >= TWOPI) txPhase -= TWOPI;
        }
        prevSym = currSym;
        isFirstSymbol = false;
    };

    // PSK31 preamble: 64 phase reversals (symbol 0 = bit 0 = 180° shift)
    // Synchronizes symbol clock recovery and engages receiver DCD (0xAAAAAAAA)
    for (int i = 0; i < 64; i++) {
        sendSymbol(0);
    }

    // 3. Text data with Varicode and "00" inter-character delimiters
    for (unsigned char uc : text) {
        const char* code = Psk::varicode_encode(uc);
        for (int i = 0; code[i]; i++) {
            sendSymbol(code[i] - '0');
        }
        // Inter-character delimiter "00"
        sendSymbol(0);
        sendSymbol(0);
    }

    // 4. PSK31 postamble: 32 unmodulated carrier symbols (symbol 1 = bit 1 = 0° phase)
    // Matches fldigi standard BPSK31 postamble (dcdbits = 32)
    for (int i = 0; i < 31; i++) {
        sendSymbol(1);
    }
    // Last postamble symbol smoothly tapers second half to zero
    sendSymbol(1, true);

    // 5. 250ms silence pad (12,000 samples at 48 kHz) to ensure DAC flushes before PTT releases
    txBuffer_.insert(txBuffer_.end(), 12000, 0);

    return txBuffer_;
}

void PskModem::modulatePostamble(double f0) {
    (void)f0;
}

} // namespace Psk
