#include "cw_gtdemod.hpp"

#include <algorithm>
#include <cstring>
#include <unordered_set>

// GridTracker2 CW decoder DSP core (see lib/cw/gt/gt_cwdecoder.c).
extern "C" {
int cw_init(double rate, double span);
void cw_retune(void);
void cw_set_decode(int on);
void cw_set_range(double minHz, double maxHz);
void cw_set_init_wpm(double wpm);
float* cw_input(void);
int cw_process(int n);
float* cw_channels(void);
int cw_max_channels(void);
int* cw_events(void);
int cw_event_count(void);
void cw_events_clear(void);
}

namespace Cw {

namespace {
constexpr int kMaxChannels = 64;
constexpr int kChannelFields = 8;
constexpr int kInputMax = 4096;

template <typename T>
inline T clamp_val(T v, T lo, T hi) {
    return std::max(lo, std::min(v, hi));
}
} // namespace

CwGtDemod::CwGtDemod() {
    slot_owner_.assign(kMaxChannels, -1);
}
CwGtDemod::~CwGtDemod() = default;

void CwGtDemod::setWpm(int wpm) {
    // RX is adaptive; keep the value only for API parity / initial seed.
    wpm_ = clamp_val(wpm, 5, 50);
}

void CwGtDemod::setBandwidth(int hz) {
    bandwidth_ = clamp_val(hz, 20, 500);
}

void CwGtDemod::setSquelch(float db) {
    squelch_db_ = clamp_val(db, 0.0f, 30.0f);
}

void CwGtDemod::setReverse(bool rev) {
    reverse_ = rev;
}

void CwGtDemod::setAdaptive(bool adaptive) {
    // The GridTracker timing engine is always adaptive.
    (void)adaptive;
    adaptive_ = true;
}

void CwGtDemod::setToneFrequency(float hz) {
    tone_freq_hz_ = hz;
}

void CwGtDemod::setRange(int lowHz, int highHz) {
    if (lowHz < 0) lowHz = 0;
    if (highHz <= lowHz) highHz = lowHz + 100;
    rangeLow_ = lowHz;
    rangeHigh_ = highHz;
    rangeSet_ = true;
    if (inited_) {
        cw_set_range(static_cast<double>(rangeLow_), static_cast<double>(rangeHigh_));
    }
}

void CwGtDemod::ensure_init() {
    if (!inited_) rx_init();
}

void CwGtDemod::rx_init() {
    // Span wide enough for the whole conversational waterfall. cw_init clamps
    // it to what the sample rate can carry.
    span_ = 5400.0f;
    cw_init(static_cast<double>(SAMPLE_RATE), static_cast<double>(span_));
    cw_set_init_wpm(static_cast<double>(wpm_));
    cw_set_decode(1);
    if (rangeSet_) {
        cw_set_range(static_cast<double>(rangeLow_), static_cast<double>(rangeHigh_));
    } else {
        cw_retune();
        cw_set_range(150.0, static_cast<double>(span_));
    }
    states_.clear();
    reset_slots();
    inited_ = true;
}

void CwGtDemod::reset() {
    inited_ = false;
    rx_init();
}

void CwGtDemod::rx_process(const float* samples, int count, float /*center_freq_hz*/) {
    if (count <= 0) return;
    ensure_init();
    if (rangeSet_) {
        cw_set_range(static_cast<double>(rangeLow_), static_cast<double>(rangeHigh_));
    }
    float* in = cw_input();
    int off = 0;
    while (off < count) {
        int chunk = std::min(count - off, kInputMax);
        std::memcpy(in, samples + off, static_cast<size_t>(chunk) * sizeof(float));
        cw_process(chunk);
        off += chunk;
    }
}

void CwGtDemod::reset_slots() {
    id_to_slot_.clear();
    slot_owner_.assign(kMaxChannels, -1);
}

CwGtDemod::ChanState& CwGtDemod::state_for(int id) {
    auto it = states_.find(id);
    if (it != states_.end()) return it->second;

    ChanState st;
    for (int i = 0; i < kMaxChannels; ++i) {
        if (slot_owner_[i] < 0) {
            slot_owner_[i] = id;
            id_to_slot_[id] = i;
            st.slot = i;
            break;
        }
    }
    if (st.slot < 0) {
        // All 64 slots busy (engine can't exceed that); fall back, but this
        // should not happen.
        st.slot = ((id % kMaxChannels) + kMaxChannels) % kMaxChannels;
    }

    states_[id] = st;
    return states_[id];
}

void CwGtDemod::free_slot(int id) {
    auto it = id_to_slot_.find(id);
    if (it == id_to_slot_.end()) return;
    const int slot = it->second;
    if (slot >= 0 && slot < kMaxChannels && slot_owner_[slot] == id) {
        slot_owner_[slot] = -1;
    }
    id_to_slot_.erase(it);
}

void CwGtDemod::update_station(int id, float freq, float snr, int wpm) {
    ChanState& st = state_for(id);
    if (freq > 0.0f) st.frequency = freq;
    if (snr > 0.0f) st.snr = snr;
    if (wpm > 0) st.wpm = wpm;
}

void CwGtDemod::emit_channel(std::vector<CwDecodeResult>& out, int id, bool complete) {
    auto it = states_.find(id);
    if (it == states_.end()) return;

    ChanState& st = it->second;
    if (st.text.empty() && !complete) return;

    if (!st.text.empty() && st.snr > 0.0f && st.snr < squelch_db_) {
        st.text.clear();
        return;
    }

    CwDecodeResult r;
    r.text = st.text;
    r.frequency_hz = st.frequency > 0.0f ? st.frequency : tone_freq_hz_;
    r.snr_db = st.snr;
    r.wpm = st.wpm > 0 ? st.wpm : wpm_;
    r.channel = st.slot >= 0 ? st.slot : 0;
    r.complete = complete;
    out.push_back(r);
    st.text.clear();
}

void CwGtDemod::release_closed(std::vector<CwDecodeResult>& out) {
    std::unordered_set<int> live;
    float* tbl = cw_channels();
    const int rows = std::min(cw_max_channels(), kMaxChannels);
    for (int i = 0; i < rows; ++i) {
        const float* row = tbl + i * kChannelFields;
        if (row[5] != 0.0f) {
            live.insert(static_cast<int>(row[0]));
        }
    }

    for (auto it = states_.begin(); it != states_.end();) {
        if (live.count(it->first)) {
            ++it;
            continue;
        }
        emit_channel(out, it->first, true);
        free_slot(it->first);
        it = states_.erase(it);
    }
}

std::vector<CwDecodeResult> CwGtDemod::get_results() {
    std::vector<CwDecodeResult> out;
    ensure_init();

    // Refresh per-channel frequency/SNR/WPM from the engine table.
    float* tbl = cw_channels();
    const int rows = std::min(cw_max_channels(), kMaxChannels);
    for (int i = 0; i < rows; ++i) {
        const float* row = tbl + i * kChannelFields;
        if (row[5] != 0.0f) {
            const int id = static_cast<int>(row[0]);
            update_station(id, row[1], row[3], static_cast<int>(row[2]));
        }
    }

    const int n = cw_event_count();
    int* ev = cw_events();
    for (int i = 0; i < n; ++i) {
        const int id = ev[i * 2];
        const int code = ev[i * 2 + 1];
        if (code < 0) continue; // revision; the append-only display keeps live text

        if (code == 1) {
            // A new transmission on this channel: the previous one is done.
            emit_channel(out, id, true);
            continue;
        }
        if (code > 1) {
            ChanState& st = state_for(id);
            st.text.push_back(static_cast<char>(code));
            // A word boundary completes a line promptly (not only on idle).
            if (code == ' ' && st.text.size() >= 2) {
                emit_channel(out, id, true);
            }
        }
    }
    cw_events_clear();

    // Channels that went away: flush whatever text remains as complete.
    release_closed(out);

    // Emit remaining partial text so the caller can accumulate it live.
    for (auto& kv : states_) {
        if (!kv.second.text.empty()) emit_channel(out, kv.first, false);
    }

    return out;
}

} // namespace Cw
