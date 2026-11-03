#ifndef CW_DEEPCW_DECODER_HPP
#define CW_DEEPCW_DECODER_HPP

#include "deepcw_types.hpp"

#include <condition_variable>
#include <cstdint>
#include <chrono>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

namespace Cw {
namespace DeepCw {

class Session;
class Frontend;
class PosteriorStitcher;

struct Settings {
    std::string model_path;
    std::string model_narrow_path;
    int max_segment_seconds = 12;
    int cadence_ms = 1000;
    int min_pending_ms = 2000;
    int idle_finalize_ms = 1500;
    int intra_threads = 2;
    bool multi_channel = true;
    int max_channels = 5;
    int range_low_hz = 150;
    int range_high_hz = 4000;
};

// Asynchronous single-channel DeepCW decoder. Audio is appended with
// process(); a worker runs the model on rolling windows and queues committed
// text for take_results().
class Decoder {
public:
    Decoder();
    ~Decoder();

    Decoder(Decoder const&) = delete;
    Decoder& operator=(Decoder const&) = delete;

    bool start(Settings const& settings, std::string& error);
    void stop();
    bool running() const;

    void reset();
    void set_center_frequency(double hz);
    void process(float const* samples, int count);

    std::vector<DecodeResult> take_results();
    std::string last_error() const;

    // Synchronous whole-buffer decode (tests / explicit final flush).
    bool decode_all(float const* samples, int count, double center_hz,
                    std::vector<DecodeResult>& results, std::string& error);

private:
    struct Track {
        int slot = 0;
        double frequency = 0.0;
        float snr = 0.0f;
        std::chrono::steady_clock::time_point first_seen;
        std::chrono::steady_clock::time_point last_seen;
        bool emitted_any = false;
        std::unique_ptr<PosteriorStitcher> stitcher;
    };

    bool run_window(float const* samples, int length,
                    int start_frame, bool is_final, double center_hz,
                    std::string& committed, std::string& error);
    bool run_narrow_window(float const* samples, int length,
                           int start_frame, bool is_final, double frequency_hz,
                           PosteriorStitcher& stitcher, bool& emitted_any,
                           std::string& committed, std::string& error);
    bool finalize_buffer(float const* samples, int count, double center_hz,
                         std::vector<DecodeResult>& results, std::string& error);
    void worker_loop();
    void update_tracks(float const* samples, int count, double center_hz,
                       std::chrono::steady_clock::time_point now);
    void release_tracks(std::chrono::steady_clock::time_point now,
                        std::vector<DecodeResult>& out);
    int allocate_slot();
    void free_slot(int slot);

    Settings settings_;
    std::unique_ptr<Session> session_;
    std::unique_ptr<Session> narrow_session_;
    std::unique_ptr<Frontend> frontend_;
    std::unique_ptr<PosteriorStitcher> stitcher_;

    std::map<int, Track> tracks_;
    int next_track_id_ = 1;
    std::vector<bool> used_slots_;

    std::vector<float> audio_;
    double center_hz_ = 800.0;
    bool emitted_any_ = false;

    mutable std::mutex mutex_;
    std::mutex decode_mutex_; // serializes model/stitcher use with reset()
    std::condition_variable wake_;
    std::thread worker_;
    bool running_ = false;
    bool stop_ = false;
    bool new_audio_ = false;
    std::uint64_t generation_ = 0;
    std::vector<DecodeResult> results_;
    std::string error_;
};

} // namespace DeepCw
} // namespace Cw

#endif // CW_DEEPCW_DECODER_HPP
