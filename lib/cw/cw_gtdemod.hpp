#ifndef CW_GT_DEMOD_HPP
#define CW_GT_DEMOD_HPP

#include "cw_demod.hpp"
#include <string>
#include <unordered_map>
#include <vector>

namespace Cw {

// GridTracker2 CW decoder, adapted from gridtracker2/src/wasm/cwdecoder/cwdecoder.c.
//
// Unlike the simple single-tone CwDemod, this is a full multi-channel decoder:
// it builds a spectrum, finds the narrow carriers that stand out of each bin's
// own noise floor, opens a channel per carrier, mixes each down to 0 Hz,
// filters it with boxcars, reads the key against an adaptive (QSB-following)
// threshold and decodes the timing with a speed-learning Morse engine. All
// channels are decoded at once. Reception speed is always adaptive; the WPM
// setting only seeds the timing engine and is used for TX elsewhere.
class CwGtDemod {
public:
    static constexpr int SAMPLE_RATE = 12000;
    static constexpr int FFT_SIZE = 2048;

    CwGtDemod();
    ~CwGtDemod();

    // RX speed is adaptive. setWpm only seeds the timing engine.
    void setWpm(int wpm);
    void setBandwidth(int hz);      // retained for API parity; GT uses fixed boxcars
    void setSquelch(float db);      // gate emissions on per-channel SNR (dB)
    void setReverse(bool rev);      // retained for API parity
    void setAdaptive(bool adaptive);// always adaptive
    void setToneFrequency(float hz);// retained for API parity

    // Audio band to scan (Hz). Carriers outside it are ignored.
    void setRange(int lowHz, int highHz);

    void rx_init();
    void rx_process(const float* samples, int count, float center_freq_hz);
    std::vector<CwDecodeResult> get_results();

    void reset();

    int getWpm() const { return wpm_; }
    int getBandwidth() const { return bandwidth_; }
    float getSquelch() const { return squelch_db_; }
    bool getReverse() const { return reverse_; }
    bool getAdaptive() const { return adaptive_; }

private:
    struct ChanState {
        std::string text;
        float frequency = 0.0f;
        float snr = 0.0f;
        int wpm = 0;
        int slot = -1;
        bool have = false;
    };

    int wpm_ = 20;
    int bandwidth_ = 50;
    float squelch_db_ = 5.0f;
    bool reverse_ = false;
    bool adaptive_ = true;
    float tone_freq_hz_ = 600.0f;

    int rangeLow_ = 150;
    int rangeHigh_ = 5400;
    bool rangeSet_ = false;

    bool inited_ = false;
    float span_ = 5400.0f;

    // GridTracker hands out a monotonically increasing channel id (it grows
    // past 64 over time), so key our per-channel text by that id and map it to
    // a collision-free display slot (0..63).
    std::unordered_map<int, ChanState> states_;
    std::unordered_map<int, int> id_to_slot_;
    std::vector<int> slot_owner_; // 64 entries; -1 when free

    void ensure_init();
    ChanState& state_for(int id);
    void free_slot(int id);
    void reset_slots();
    void emit_channel(std::vector<CwDecodeResult>& out, int id, bool complete);
    void release_closed(std::vector<CwDecodeResult>& out);
    void update_station(int id, float freq, float snr, int wpm);
};

} // namespace Cw

#endif // CW_GT_DEMOD_HPP
