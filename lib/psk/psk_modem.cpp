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

static std::vector<double> raisedcosfilt(int len) {
    std::vector<double> c(len + 1);
    for (int i = 0; i <= len; i++) {
        c[i] = (1.0 - std::cos(TWOPI * i / len)) / (2.0 * len);
    }
    return c;
}

static std::vector<double> pskcore_filter(int len) {
    std::vector<double> c(len + 1);
    const double pi = M_PI_;
    for (int i = 0; i <= len; i++) {
        double x = (i - len/2.0) / (len/2.0);
        if (x == 0.0) {
            c[i] = 1.0;
        } else if (std::abs(x) == 0.5) {
            c[i] = 0.5;
        } else if (std::abs(x) == 1.0) {
            c[i] = 0.0;
        } else {
            double num = std::sin(pi * x) * std::cos(pi * x / 2.0);
            double den = pi * x * (1.0 - x * x);
            c[i] = num / den;
        }
    }
    return c;
}

PskModem::FirFilter::FirFilter(const std::vector<double>& c, int dec)
    : coeffs(c), decimation(dec), phase(0) {
    state_real.resize(coeffs.size() - 1, 0.0);
    state_imag.resize(coeffs.size() - 1, 0.0);
}

void PskModem::FirFilter::reset() {
    std::fill(state_real.begin(), state_real.end(), 0.0);
    std::fill(state_imag.begin(), state_imag.end(), 0.0);
    phase = 0;
}

bool PskModem::FirFilter::process(const cmplx& in, cmplx& out) {
    // Shift in new sample
    state_real.insert(state_real.begin(), in.real());
    state_imag.insert(state_imag.begin(), in.imag());
    if ((int)state_real.size() > (int)coeffs.size()) {
        state_real.pop_back();
        state_imag.pop_back();
    }

    double real_sum = 0.0, imag_sum = 0.0;
    for (size_t i = 0; i < coeffs.size(); i++) {
        double real_val = (i < state_real.size()) ? state_real[i] : 0.0;
        double imag_val = (i < state_imag.size()) ? state_imag[i] : 0.0;
        real_sum += coeffs[i] * real_val;
        imag_sum += coeffs[i] * imag_val;
    }

    phase = (phase + 1) % decimation;

    if (phase == 0) {
        out = cmplx(real_sum, imag_sum);
        return true;
    }
    return false;
}

PskModem::PskModem(double rxSampleRate, double txSampleRate)
    : rxSampleRate_(rxSampleRate), txSampleRate_(txSampleRate) {
    auto fir1c = raisedcosfilt(FIRLEN);
    auto fir2c = pskcore_filter(FIRLEN);
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
        phaseInc_ = TWOPI * frequency_ / rxSampleRate_;
    }
}

void PskModem::rxInit() {
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
    quality_ = 0.0;
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

        cmplx z(sample * std::cos(phaseAcc_), sample * std::sin(phaseAcc_));
        phaseAcc_ += phaseInc_;
        if (phaseAcc_ >= TWOPI) phaseAcc_ -= TWOPI;

        cmplx z1;
        if (fir1_.process(z, z1)) {
            cmplx z2;
            fir2_.process(z1, z2);

            int idx = static_cast<int>(bitClk_);
            if (idx < 0 || idx >= SYNC_BUF_SIZE) continue;
            double sum = std::abs(z2);
            if (std::isnan(sum) || std::isinf(sum)) continue;
            syncBuf_[idx] = 0.8 * syncBuf_[idx] + 0.2 * sum;

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

    int bit = (phase > HALF_PI && phase < 3.0 * HALF_PI) ? 0 : 1;
    if (reverse_) bit = 1 - bit;

    double sigAmp = std::norm(symbol);
    avgAmp_ = decayavg(avgAmp_, sigAmp, SQLDECAY);

    double softAmp = 1.0;
    if (sigAmp > 0 && avgAmp_ > 0) {
        softAmp = clamp(std::sqrt(avgAmp_ / sigAmp), 1.0, 1e6);
    }

    double alpha = phase / M_PI_;
    if (alpha > 1.0) alpha = 2.0 - alpha;
    double softAngle = 127.0 - 255.0 * alpha;
    unsigned char softBit = static_cast<unsigned char>(clamp(softAngle / (1.0 + softAmp / 2.0) + 128.0, 0.0, 255.0));
    (void)softBit;

    double cval = std::cos(2.0 * phase);
    double sval = std::sin(2.0 * phase);
    quality_ = decayavg(quality_, cval * cval + sval * sval, SQLDECAY);

    if (quality_ > squelch_ / 100.0) {
        dcd_ = true;
        acquire_ = dcdBits_ * 2;
    } else if (acquire_ > 0) {
        acquire_--;
        if (acquire_ == 0) dcd_ = false;
    }

    if (!dcd_) return;

    dcdShreg_ = (dcdShreg_ << 2) | (bit << 1) | 1;

    if ((dcdShreg_ & 3) == 0) {
        int c = Psk::varicode_decode(dcdShreg_ >> 2);
        if (c >= 0 && c < 256) {
            rxChars_.push_back(static_cast<char>(c));
        }
        dcdShreg_ = 0;
    }
}

void PskModem::rxBit(int bit) {
    shreg_ = (shreg_ << 1) | bit;
    if ((shreg_ & 3) == 0) {
        int c = Psk::varicode_decode(shreg_ >> 2);
        if (c >= 0 && c < 256) {
            rxChars_.push_back(static_cast<char>(c));
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

    auto sendSymbol = [&](int sym) {
        cmplx currSym = (sym == 0) ? cmplx(-1.0, 0.0) : cmplx(1.0, 0.0);
        currSym = prevSym * currSym;
        for (int i = 0; i < SAMPLES_PER_SYMBOL_TX; i++) {
            double shape = txShape_[i];
            double ival = shape * currSym.real() + (1.0 - shape) * prevSym.real();
            double qval = shape * currSym.imag() + (1.0 - shape) * prevSym.imag();
            double out = ival * std::cos(txPhase) - qval * std::sin(txPhase);
            txBuffer_.push_back(static_cast<int16_t>(clamp(out * 16000.0, -32767.0, 32767.0)));
            txPhase += txPhaseInc;
            if (txPhase >= TWOPI) txPhase -= TWOPI;
        }
        prevSym = currSym;
    };

    // PSK31 preamble: 32 phase reversals (symbol 0 = bit 0 = 180° shift)
    // Matches fldigi standard BPSK31 preamble (dcdbits = 32)
    for (int i = 0; i < 32; i++) {
        sendSymbol(0);
    }

    for (unsigned char uc : text) {
        const char* code = Psk::varicode_encode(uc);
        for (int i = 0; code[i]; i++) {
            sendSymbol(code[i] - '0');
        }
        // Inter-character delimiter "00"
        sendSymbol(0);
        sendSymbol(0);
    }

    // PSK31 postamble: 32 unmodulated carrier symbols (symbol 1 = bit 1 = 0° phase)
    // Matches fldigi standard BPSK31 postamble (dcdbits = 32)
    for (int i = 0; i < 32; i++) {
        sendSymbol(1);
    }

    // Final carrier ramp-down
    cmplx currSym(1.0, 0.0);
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < SAMPLES_PER_SYMBOL_TX; j++) {
            double out = currSym.real() * std::cos(txPhase) - currSym.imag() * std::sin(txPhase);
            double taper = 0.5 * (1.0 + std::cos(M_PI_ * i / 32.0));
            txBuffer_.push_back(static_cast<int16_t>(clamp(out * taper * 16000.0, -32767.0, 32767.0)));
            txPhase += txPhaseInc;
            if (txPhase >= TWOPI) txPhase -= TWOPI;
        }
    }
    txBuffer_.insert(txBuffer_.end(), 4800, 0);

    return txBuffer_;
}

void PskModem::modulatePostamble(double f0) {
    (void)f0;
    // Postamble is now handled inline in modulateText()
}

} // namespace Psk