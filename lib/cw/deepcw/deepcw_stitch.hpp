#ifndef CW_DEEPCW_STITCH_HPP
#define CW_DEEPCW_STITCH_HPP

#include "deepcw_types.hpp"

#include <string>
#include <vector>

namespace Cw {
namespace DeepCw {

// Accumulates overlapping window posteriors (as in the reference
// PosteriorStitcher) and commits text only where it is stable: at word-space
// spans, guarded by a frozen tail.
class PosteriorStitcher {
public:
    explicit PosteriorStitcher(ModelSpec const& spec, int max_segment_seconds = 12);

    void reset();

    void add_window(int start_frame, float const* logits, int frames, bool is_final);

    struct Taken {
        bool committed = false;
        std::string text;
        bool prepend_space = false;
        std::string pending;
    };

    Taken take(bool final);

    int context_start_frame() const;
    int window_start_frame(int end_sample) const;
    int max_segment_samples() const;
    int committed_end() const { return committed_end_; }
    int covered_end() const { return covered_end_; }

private:
    void ensure_rows(int end_frame);
    void drop_rows_before(int frame);
    std::vector<float> read_scores(int start_frame, int end_frame) const;

    ModelSpec spec_;
    int classes_;
    int space_index_;
    int blank_index_;
    double fps_;
    int max_segment_samples_;
    int left_context_frames_;
    int freeze_guard_frames_;
    int word_boundary_frames_;
    int output_hop_;

    int row_base_ = 0;
    std::vector<float> sums_; // rows * classes
    std::vector<float> weights_;

    int covered_end_ = 0;
    int frozen_end_ = 0;
    int committed_end_ = 0;
    std::string previous_symbol_ = "none";
    int blank_frames_ = 0;
    bool has_committed_text_ = false;
};

} // namespace DeepCw
} // namespace Cw

#endif // CW_DEEPCW_STITCH_HPP
