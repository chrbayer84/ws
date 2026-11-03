#include "deepcw_decoder.hpp"

#include "deepcw_spectrogram.hpp"
#include "deepcw_stitch.hpp"
#include "deepcw_session.hpp"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstring>

namespace Cw {
namespace DeepCw {

namespace {
constexpr double kShiftBandwidthHz = 800.0;
constexpr int kStepSamples = kInputRate; // 1 s
constexpr int kMinPendingSamples = 2 * kInputRate;
constexpr int kAnalysisSeconds = 17; // 12 s window + 4 s context + margin
constexpr int kDetectSeconds = 8;
constexpr int kTrackConfirmMs = 400;
constexpr int kTrackHoldMs = 5000;
constexpr double kTrackMatchHz = 15.0;
constexpr double kTrackMinSeparationHz = 50.0;
constexpr double kTrackSkipNearCenterHz = 75.0;
constexpr float kTrackMinSnrDb = 12.0f;
constexpr int kSlotCount = 64; // Cw::Decoder's channels_ size

int ms_since(std::chrono::steady_clock::time_point a,
             std::chrono::steady_clock::time_point b) {
    return static_cast<int>(
        std::chrono::duration_cast<std::chrono::milliseconds>(a - b).count());
}
} // namespace

Decoder::Decoder() = default;

Decoder::~Decoder() {
    stop();
}

bool Decoder::running() const {
    return running_;
}

bool Decoder::start(Settings const& settings, std::string& error) {
    if (running_) return true;
    if (settings.model_path.empty()) {
        error = "DeepCW model path is empty";
        return false;
    }

    settings_ = settings;
    session_.reset(new Session());
    if (!session_->load(settings_.model_path, settings_.intra_threads, error)) {
        session_.reset();
        return false;
    }

    if (settings_.multi_channel && !settings_.model_narrow_path.empty()) {
        narrow_session_.reset(new Session());
        std::string narrow_error;
        if (!narrow_session_->load(settings_.model_narrow_path,
                                   settings_.intra_threads, narrow_error)) {
            narrow_session_.reset();
        }
    }

    frontend_.reset(new Frontend());
    stitcher_.reset(new PosteriorStitcher(standard_spec(), settings_.max_segment_seconds));

    {
        std::lock_guard<std::mutex> lock(mutex_);
        audio_.clear();
        results_.clear();
        error_.clear();
        emitted_any_ = false;
        stop_ = false;
        new_audio_ = false;
        tracks_.clear();
        used_slots_.assign(kSlotCount, false);
        next_track_id_ = 1;
    }

    running_ = true;
    worker_ = std::thread(&Decoder::worker_loop, this);
    return true;
}

void Decoder::stop() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!running_ && !worker_.joinable()) return;
        stop_ = true;
    }
    wake_.notify_all();
    if (worker_.joinable()) worker_.join();
    running_ = false;
    session_.reset();
    narrow_session_.reset();
}

void Decoder::reset() {
    std::lock_guard<std::mutex> decode_lock(decode_mutex_);
    std::lock_guard<std::mutex> lock(mutex_);
    audio_.clear();
    results_.clear();
    error_.clear();
    emitted_any_ = false;
    new_audio_ = false;
    ++generation_;
    tracks_.clear();
    used_slots_.assign(kSlotCount, false);
    next_track_id_ = 1;
    if (stitcher_) stitcher_->reset();
}

void Decoder::set_center_frequency(double hz) {
    std::lock_guard<std::mutex> lock(mutex_);
    center_hz_ = hz > 0.0 ? hz : 800.0;
}

void Decoder::process(float const* samples, int count) {
    if (!samples || count <= 0) return;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        audio_.insert(audio_.end(), samples, samples + count);
        new_audio_ = true;
    }
    wake_.notify_one();
}

std::vector<DecodeResult> Decoder::take_results() {
    std::lock_guard<std::mutex> lock(mutex_);
    std::vector<DecodeResult> out;
    out.swap(results_);
    return out;
}

std::string Decoder::last_error() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return error_;
}

int Decoder::allocate_slot() {
    for (int i = 1; i < kSlotCount; ++i) {
        if (!used_slots_[i]) {
            used_slots_[i] = true;
            return i;
        }
    }
    return 1;
}

void Decoder::free_slot(int slot) {
    if (slot > 0 && slot < kSlotCount) used_slots_[slot] = false;
}

bool Decoder::run_window(float const* samples, int length,
                         int start_frame, bool is_final, double center_hz,
                         std::string& committed, std::string& error) {
    committed.clear();
    if (!samples || length < kFftLength) return true;

    std::vector<float> spectrogram;
    int frames = 0;
    if (!frontend_->shifted(samples, length, center_hz,
                            kShiftBandwidthHz, spectrogram, frames)) {
        error = "DeepCW front-end failed";
        return false;
    }

    std::vector<float> log_probs;
    int out_frames = 0;
    int classes = 0;
    if (!session_->run(spectrogram.data(), frames, standard_spec().frequency_bins,
                       log_probs, out_frames, classes, error)) {
        return false;
    }

    stitcher_->add_window(start_frame, log_probs.data(), out_frames, is_final);
    PosteriorStitcher::Taken taken = stitcher_->take(is_final);
    if (taken.committed && !taken.text.empty()) {
        if (taken.prepend_space && emitted_any_) committed.push_back(' ');
        committed += taken.text;
        emitted_any_ = true;
    }
    return true;
}

bool Decoder::run_narrow_window(float const* samples, int length,
                                int start_frame, bool is_final, double frequency_hz,
                                PosteriorStitcher& stitcher, bool& emitted_any,
                                std::string& committed, std::string& error) {
    committed.clear();
    if (!narrow_session_ || !samples || length < kFftLength) return true;

    std::vector<float> spectrogram;
    int frames = 0;
    if (!frontend_->narrow(samples, length, frequency_hz, spectrogram, frames)) {
        error = "DeepCW narrow front-end failed";
        return false;
    }

    std::vector<float> log_probs;
    int out_frames = 0;
    int classes = 0;
    if (!narrow_session_->run(spectrogram.data(), frames, narrow_spec().frequency_bins,
                              log_probs, out_frames, classes, error)) {
        return false;
    }

    stitcher.add_window(start_frame, log_probs.data(), out_frames, is_final);
    PosteriorStitcher::Taken taken = stitcher.take(is_final);
    if (taken.committed && !taken.text.empty()) {
        if (taken.prepend_space && emitted_any) committed.push_back(' ');
        committed += taken.text;
        emitted_any = true;
    }
    return true;
}

bool Decoder::finalize_buffer(float const* samples, int count, double center_hz,
                              std::vector<DecodeResult>& results, std::string& error) {
    if (count <= 0) return true;

    int guard = 0;
    while (guard++ < 4096) {
        const int start_frame = stitcher_->context_start_frame();
        const int start_sample = start_frame * kOutputHopLength;
        const int end_sample = std::min(
            count, start_sample + stitcher_->max_segment_samples());
        const bool is_final = end_sample >= count;
        const int length = end_sample - start_sample;
        if (length <= 0) return true;

        std::string committed;
        if (!run_window(samples + start_sample, length, start_frame, is_final,
                        center_hz, committed, error)) {
            return false;
        }
        if (!committed.empty()) {
            DecodeResult result;
            result.text = committed;
            result.frequency_hz = static_cast<float>(center_hz);
            result.channel = 0;
            result.complete = true;
            results.push_back(result);
        }
        if (is_final) return true;
    }
    return true;
}

bool Decoder::decode_all(float const* samples, int count, double center_hz,
                         std::vector<DecodeResult>& results, std::string& error) {
    if (!session_ || !session_->valid()) {
        error = "DeepCW model is not loaded";
        return false;
    }
    if (!frontend_ || !stitcher_) {
        error = "DeepCW decoder is not ready";
        return false;
    }
    if (!samples || count <= 0) return true;

    std::lock_guard<std::mutex> decode_lock(decode_mutex_);
    stitcher_->reset();
    emitted_any_ = false;

    int end = std::min(count, kMinPendingSamples);
    while (end < count) {
        const int start_frame = stitcher_->window_start_frame(end);
        const int start_sample = start_frame * kOutputHopLength;
        const int length = end - start_sample;
        std::string committed;
        if (length > 0
            && !run_window(samples + start_sample, length, start_frame, false,
                           center_hz, committed, error)) {
            return false;
        }
        if (!committed.empty()) {
            DecodeResult result;
            result.text = committed;
            result.frequency_hz = static_cast<float>(center_hz);
            result.channel = 0;
            result.complete = true;
            results.push_back(result);
        }
        end += kStepSamples;
    }

    return finalize_buffer(samples, count, center_hz, results, error);
}

void Decoder::update_tracks(float const* samples, int count, double center_hz,
                            std::chrono::steady_clock::time_point now) {
    (void)center_hz;
    if (!narrow_session_ || !settings_.multi_channel) return;

    // Detect carriers on the most recent detection window.
    const int detect_count = std::min(count, kDetectSeconds * kInputRate);
    if (detect_count < kFftLength) return;
    float const* detect_samples = samples + (count - detect_count);
    Frontend::Detection detection = frontend_->detect(
        detect_samples, detect_count,
        static_cast<double>(settings_.range_low_hz),
        static_cast<double>(settings_.range_high_hz));
    if (detection.frequencies.empty()) return;

    struct Candidate {
        double frequency;
        float snr;
    };
    std::vector<Candidate> candidates;
    for (size_t i = 0; i < detection.frequencies.size(); ++i) {
        if (detection.snr_db[i] >= kTrackMinSnrDb) {
            candidates.push_back({detection.frequencies[i], detection.snr_db[i]});
        }
    }
    std::sort(candidates.begin(), candidates.end(),
              [](Candidate const& a, Candidate const& b) { return a.snr > b.snr; });

    std::vector<Candidate> picked;
    for (Candidate const& candidate : candidates) {
        if (static_cast<int>(picked.size()) >= settings_.max_channels) break;
        bool separated = true;
        for (Candidate const& other : picked) {
            if (std::abs(other.frequency - candidate.frequency) < kTrackMinSeparationHz) {
                separated = false;
                break;
            }
        }
        if (separated) picked.push_back(candidate);
    }

    // Match detections to existing tracks.
    std::vector<bool> matched(picked.size(), false);
    for (auto& entry : tracks_) {
        Track& track = entry.second;
        for (size_t i = 0; i < picked.size(); ++i) {
            if (matched[i]) continue;
            if (std::abs(track.frequency - picked[i].frequency) <= kTrackMatchHz) {
                track.frequency = track.frequency * 0.3 + picked[i].frequency * 0.7;
                track.snr = picked[i].snr;
                track.last_seen = now;
                matched[i] = true;
                break;
            }
        }
    }

    for (size_t i = 0; i < picked.size(); ++i) {
        if (matched[i]) continue;
        Track track;
        track.slot = allocate_slot();
        track.frequency = picked[i].frequency;
        track.snr = picked[i].snr;
        track.first_seen = now;
        track.last_seen = now;
        track.stitcher.reset(new PosteriorStitcher(narrow_spec(),
                                                   settings_.max_segment_seconds));
        tracks_[next_track_id_++] = std::move(track);
    }
}

void Decoder::release_tracks(std::chrono::steady_clock::time_point now,
                             std::vector<DecodeResult>& out) {
    if (tracks_.empty()) return;
    for (auto it = tracks_.begin(); it != tracks_.end();) {
        Track& track = it->second;
        if (ms_since(now, track.last_seen) <= kTrackHoldMs) {
            ++it;
            continue;
        }
        std::string trailing;
        if (track.stitcher) {
            PosteriorStitcher::Taken taken = track.stitcher->take(true);
            if (taken.committed && !taken.text.empty()) {
                if (taken.prepend_space && track.emitted_any) trailing.push_back(' ');
                trailing += taken.text;
            }
        }
        if (!trailing.empty()) {
            DecodeResult result;
            result.text = trailing;
            result.frequency_hz = static_cast<float>(track.frequency);
            result.snr_db = track.snr;
            result.channel = track.slot;
            result.complete = true;
            out.push_back(result);
        }
        free_slot(track.slot);
        it = tracks_.erase(it);
    }
}

void Decoder::worker_loop() {
    using clock = std::chrono::steady_clock;
    const auto idle = std::chrono::milliseconds(settings_.idle_finalize_ms);
    const auto cadence = std::chrono::milliseconds(settings_.cadence_ms);
    clock::time_point last_run;
    bool have_run = false;

    std::unique_lock<std::mutex> lock(mutex_);
    while (!stop_) {
        wake_.wait_for(lock, idle, [this] { return stop_ || new_audio_; });
        if (stop_) break;

        if (!new_audio_) {
            if (!audio_.empty()) {
                const int snapshot_len = static_cast<int>(audio_.size());
                const std::uint64_t generation = generation_;
                std::vector<float> snapshot(audio_);
                const double center = center_hz_;
                const auto now = clock::now();
                lock.unlock();
                std::vector<DecodeResult> finalized;
                std::string error;
                bool ok = false;
                {
                    std::lock_guard<std::mutex> decode_lock(decode_mutex_);
                    ok = finalize_buffer(snapshot.data(), snapshot_len,
                                         center, finalized, error);
                    release_tracks(now, finalized);
                }
                lock.lock();
                if (generation != generation_) continue;
                if (!ok) {
                    error_ = error;
                } else {
                    results_.insert(results_.end(), finalized.begin(), finalized.end());
                }
                const int drop = std::min(snapshot_len, static_cast<int>(audio_.size()));
                audio_.erase(audio_.begin(), audio_.begin() + drop);
                tracks_.clear();
                used_slots_.assign(kSlotCount, false);
                stitcher_->reset();
                emitted_any_ = false;
                have_run = false;
            }
            continue;
        }

        new_audio_ = false;
        if (have_run) {
            const auto now = clock::now();
            if (now - last_run < cadence) continue;
        }
        const int min_samples = settings_.min_pending_ms * kInputRate / 1000;
        if (static_cast<int>(audio_.size()) < min_samples) continue;

        const int end_sample = static_cast<int>(audio_.size());
        const int base_sample = std::max(0, end_sample - kAnalysisSeconds * kInputRate);
        const std::uint64_t generation = generation_;
        std::vector<float> snapshot(audio_.begin() + base_sample, audio_.end());
        const double center = center_hz_;
        const auto now = clock::now();
        lock.unlock();

        std::vector<DecodeResult> decoded;
        std::string error;
        bool ok = true;
        {
            std::lock_guard<std::mutex> decode_lock(decode_mutex_);

            // Primary lane: standard model on the selected RX tone.
            {
                const int start_frame = stitcher_->window_start_frame(end_sample);
                const int start_sample = start_frame * kOutputHopLength;
                const int offset = start_sample - base_sample;
                if (offset >= 0 && offset < static_cast<int>(snapshot.size())) {
                    std::string committed;
                    if (!run_window(snapshot.data() + offset,
                                    static_cast<int>(snapshot.size()) - offset,
                                    start_frame, false, center, committed, error)) {
                        ok = false;
                    } else if (!committed.empty()) {
                        DecodeResult result;
                        result.text = committed;
                        result.frequency_hz = static_cast<float>(center);
                        result.channel = 0;
                        result.complete = false;
                        decoded.push_back(result);
                    }
                }
            }

            // Multi-channel: detect carriers, then decode each with the narrow model.
            if (narrow_session_ && settings_.multi_channel) {
                update_tracks(snapshot.data(), static_cast<int>(snapshot.size()),
                              center, now);

                for (auto& entry : tracks_) {
                    Track& track = entry.second;
                    if (ms_since(now, track.first_seen) < kTrackConfirmMs) continue;
                    if (std::abs(track.frequency - center) <= kTrackSkipNearCenterHz) {
                        continue; // primary lane already covers this signal
                    }
                    const int start_frame = track.stitcher->window_start_frame(end_sample);
                    const int start_sample = start_frame * kOutputHopLength;
                    const int offset = start_sample - base_sample;
                    if (offset < 0 || offset >= static_cast<int>(snapshot.size())) continue;

                    std::string committed;
                    if (!run_narrow_window(snapshot.data() + offset,
                                           static_cast<int>(snapshot.size()) - offset,
                                           start_frame, false, track.frequency,
                                           *track.stitcher, track.emitted_any,
                                           committed, error)) {
                        ok = false;
                        break;
                    }
                    if (!committed.empty()) {
                        DecodeResult result;
                        result.text = committed;
                        result.frequency_hz = static_cast<float>(track.frequency);
                        result.snr_db = track.snr;
                        result.channel = track.slot;
                        result.complete = false;
                        decoded.push_back(result);
                    }
                }

                release_tracks(now, decoded);
            }
        }

        lock.lock();
        if (generation != generation_) continue;
        if (!ok) {
            error_ = error;
        } else {
            results_.insert(results_.end(), decoded.begin(), decoded.end());
        }
        last_run = clock::now();
        have_run = true;
    }
}

} // namespace DeepCw
} // namespace Cw
