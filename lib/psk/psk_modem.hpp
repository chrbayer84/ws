#ifndef PSK_MODEM_HPP
#define PSK_MODEM_HPP

#include <vector>
#include <complex>
#include <string>
#include <memory>
#include <cstdint>

namespace Psk {

using cmplx = std::complex<double>;

class PskModem {
public:
    static constexpr double BAUD = 31.25;
    static constexpr int SAMPLE_RATE_TX = 48000;
    static constexpr int SAMPLE_RATE_RX = 12000;
    static constexpr int SAMPLES_PER_SYMBOL_TX = SAMPLE_RATE_TX / BAUD;  // 1536
    static constexpr int SAMPLES_PER_SYMBOL_RX = SAMPLE_RATE_RX / BAUD;  // 384
    static constexpr int FIR_LENGTH = 64;
    static constexpr int SYNC_BUF_SIZE = 16;

    PskModem(double rxSampleRate = SAMPLE_RATE_RX, double txSampleRate = SAMPLE_RATE_TX);
    ~PskModem();

    void setFrequency(double freq);
    void setReverse(bool rev) { reverse_ = rev; }
    void setSquelch(double s) { squelch_ = s; }

    void rxInit();
    void txInit();

    int rxProcess(const int16_t* samples, int count);
    std::vector<int16_t> modulateText(const std::string& text, double f0);
    void modulatePostamble(double f0);

    bool hasOutput() const { return !rxChars_.empty(); }
    std::string takeOutput();

    double getFrequency() const { return frequency_; }
    double getAFC() const { return freqError_; }
    double getSNR() const { return snr_; }
    bool isDCD() const { return dcd_; }

private:
    struct FirFilter {
        std::vector<double> coeffs;
        std::vector<double> buf_real;
        std::vector<double> buf_imag;
        int decimation = 1;
        int phase = 0;
        int buf_idx = 0;

        FirFilter() = default;
        FirFilter(const std::vector<double>& c, int dec);
        void reset();
        bool process(const cmplx& in, cmplx& out);
    };

    void buildFilters();
    void buildTxShape();
    void rxSymbol(const cmplx& symbol);
    void rxBit(int bit);
    void updateAFC();
    void updateSyncScope();

    double frequency_ = 1500.0;
    double rxSampleRate_;
    double txSampleRate_;
    bool reverse_ = false;
    double squelch_ = 5.0;

    double phaseAcc_ = 0.0;
    double phaseInc_ = 0.0;
    cmplx prevSymbol_ = cmplx(1.0, 0.0);

    FirFilter fir1_;
    FirFilter fir2_;

    std::vector<double> txShape_;
    std::vector<double> syncBuf_;
    double bitClk_ = 0.0;

    uint32_t shreg_ = 0;
    uint32_t dcdShreg_ = 0;
    int dcdBits_ = 32;
    bool dcd_ = false;
    int acquire_ = 0;

    double qualityCos_ = 0.0;
    double qualitySin_ = 0.0;
    double quality_ = 0.0;
    double avgAmp_ = 0.0;
    double freqError_ = 0.0;
    double snr_ = 0.0;

    std::string rxChars_;
    std::vector<int16_t> txBuffer_;
};

} // namespace Psk

#endif // PSK_MODEM_HPP