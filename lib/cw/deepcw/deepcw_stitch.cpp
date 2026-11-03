#include "deepcw_stitch.hpp"

#include "deepcw_ctc.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

namespace Cw {
namespace DeepCw {

namespace {

constexpr double kLeftContextSeconds = 4.0;
constexpr double kFreezeGuardSeconds = 2.0;
constexpr double kLeftRampSeconds = 2.0;
constexpr double kRightRampSeconds = 1.0;
constexpr int kDilationFrames = 1;
constexpr int kWordBoundaryBlankHops = 134;
constexpr float kMinViewWeight = 1e-3f;
constexpr float kUncoveredLogProb = -30.0f;

float smoothstep(double value) {
    double t = std::max(0.0, std::min(1.0, value));
    return static_cast<float>(t * t * (3.0 - 2.0 * t));
}

void log_softmax_rows(std::vector<float>& values, int rows, int classes) {
    for (int r = 0; r < rows; ++r) {
        float* row = values.data() + static_cast<size_t>(r) * classes;
        float peak = row[0];
        for (int c = 1; c < classes; ++c) peak = std::max(peak, row[c]);
        double sum = 0.0;
        for (int c = 0; c < classes; ++c) sum += std::exp(static_cast<double>(row[c] - peak));
        const float log_sum = static_cast<float>(std::log(sum));
        for (int c = 0; c < classes; ++c) row[c] = row[c] - peak - log_sum;
    }
}

std::vector<float> to_dilated_log_probs(float const* logits, int frames, int classes,
                                        int blank_index) {
    std::vector<float> lp(static_cast<size_t>(frames) * classes);
    std::copy(logits, logits + lp.size(), lp.begin());
    log_softmax_rows(lp, frames, classes);

    std::vector<float> dilated(lp.size());
    for (int t = 0; t < frames; ++t) {
        const int lo = std::max(0, t - kDilationFrames);
        const int hi = std::min(frames - 1, t + kDilationFrames);
        float* dst = dilated.data() + static_cast<size_t>(t) * classes;
        for (int c = 0; c < classes; ++c) {
            if (c == blank_index) {
                dst[c] = lp[static_cast<size_t>(t) * classes + c];
            } else {
                float best = lp[static_cast<size_t>(lo) * classes + c];
                for (int q = lo + 1; q <= hi; ++q) {
                    best = std::max(best, lp[static_cast<size_t>(q) * classes + c]);
                }
                dst[c] = best;
            }
        }
    }

    log_softmax_rows(dilated, frames, classes);
    return dilated;
}

} // namespace

PosteriorStitcher::PosteriorStitcher(ModelSpec const& spec, int max_segment_seconds)
    : spec_(spec)
    , classes_(spec.num_classes)
    , space_index_(space_index(spec))
    , blank_index_(spec.blank_index)
    , fps_(static_cast<double>(kInputRate) / kOutputHopLength)
    , max_segment_samples_(std::max(2, max_segment_seconds) * kInputRate)
    , left_context_frames_(static_cast<int>(std::llround(kLeftContextSeconds * fps_)))
    , freeze_guard_frames_(static_cast<int>(std::llround(kFreezeGuardSeconds * fps_)))
    , word_boundary_frames_((kWordBoundaryBlankHops + kOutputTimeStride - 1) / kOutputTimeStride)
    , output_hop_(kOutputHopLength) {
}

void PosteriorStitcher::reset() {
    row_base_ = 0;
    sums_.clear();
    weights_.clear();
    covered_end_ = 0;
    frozen_end_ = 0;
    committed_end_ = 0;
    previous_symbol_ = "none";
    blank_frames_ = 0;
    has_committed_text_ = false;
}

int PosteriorStitcher::max_segment_samples() const {
    return max_segment_samples_;
}

int PosteriorStitcher::context_start_frame() const {
    return std::max(0, frozen_end_ - left_context_frames_);
}

int PosteriorStitcher::window_start_frame(int end_sample) const {
    const int excess = end_sample - max_segment_samples_;
    const int by_size = (excess <= 0)
        ? 0
        : (excess + output_hop_ - 1) / output_hop_;
    return std::max(context_start_frame(), by_size);
}

void PosteriorStitcher::ensure_rows(int end_frame) {
    const int missing = end_frame - row_base_ - static_cast<int>(weights_.size());
    if (missing <= 0) return;
    sums_.resize(sums_.size() + static_cast<size_t>(missing) * classes_, 0.0f);
    weights_.resize(weights_.size() + missing, 0.0f);
}

void PosteriorStitcher::drop_rows_before(int frame) {
    const int drop = std::min(frame - row_base_, static_cast<int>(weights_.size()));
    if (drop <= 0) return;
    sums_.erase(sums_.begin(), sums_.begin() + static_cast<size_t>(drop) * classes_);
    weights_.erase(weights_.begin(), weights_.begin() + drop);
    row_base_ += drop;
}

std::vector<float> PosteriorStitcher::read_scores(int start_frame, int end_frame) const {
    const int frames = end_frame - start_frame;
    std::vector<float> scores(static_cast<size_t>(frames) * classes_, 0.0f);
    for (int t = 0; t < frames; ++t) {
        float* row = scores.data() + static_cast<size_t>(t) * classes_;
        for (int c = 0; c < classes_; ++c) row[c] = kUncoveredLogProb;
        row[blank_index_] = 0.0f;

        const int abs_frame = start_frame + t;
        const int row_index = abs_frame - row_base_;
        if (row_index < 0 || row_index >= static_cast<int>(weights_.size())) continue;
        const float weight = weights_[row_index];
        if (weight <= 0.0f) continue;
        const float* src = sums_.data() + static_cast<size_t>(row_index) * classes_;
        for (int c = 0; c < classes_; ++c) row[c] = src[c] / weight;
    }
    return scores;
}

void PosteriorStitcher::add_window(int start_frame, float const* logits, int frames,
                                   bool is_final) {
    if (frames <= 0) {
        if (is_final) frozen_end_ = covered_end_;
        return;
    }

    const int end_frame = start_frame + frames;
    ensure_rows(end_frame);
    const std::vector<float> log_probs =
        to_dilated_log_probs(logits, frames, classes_, blank_index_);

    const int first = std::max(0, frozen_end_ - start_frame);
    for (int f = first; f < frames; ++f) {
        const double left_seconds = (start_frame == 0)
            ? std::numeric_limits<double>::infinity()
            : static_cast<double>(f) / fps_;
        const double right_seconds = is_final
            ? std::numeric_limits<double>::infinity()
            : static_cast<double>(frames - 1 - f) / fps_;
        const float weight = std::max(
            kMinViewWeight,
            smoothstep(left_seconds / kLeftRampSeconds)
                * smoothstep(right_seconds / kRightRampSeconds));

        const int row_index = start_frame + f - row_base_;
        float* sum = sums_.data() + static_cast<size_t>(row_index) * classes_;
        const float* lp = log_probs.data() + static_cast<size_t>(f) * classes_;
        for (int c = 0; c < classes_; ++c) sum[c] += weight * lp[c];
        weights_[row_index] += weight;
    }

    covered_end_ = std::max(covered_end_, end_frame);
    if (is_final) {
        frozen_end_ = covered_end_;
    } else {
        frozen_end_ = std::max(frozen_end_, end_frame - freeze_guard_frames_);
    }
}

PosteriorStitcher::Taken PosteriorStitcher::take(bool final) {
    Taken out;
    const int start_frame = committed_end_;
    if (covered_end_ - start_frame <= 0) return out;

    const bool starts_word = !has_committed_text_ || previous_symbol_ == "space";
    const std::vector<float> scores = read_scores(start_frame, covered_end_);
    const int frames = covered_end_ - start_frame;
    GreedyResult greedy = decode_greedy(scores.data(), frames, classes_, spec_,
                                        previous_symbol_, blank_frames_,
                                        word_boundary_frames_);
    std::vector<Span>& spans = greedy.spans;
    for (Span& span : spans) {
        span.start_frame += start_frame;
        span.end_frame += start_frame;
    }

    const double commit_limit = final
        ? std::numeric_limits<double>::infinity()
        : static_cast<double>(frozen_end_);

    int committed_count = 0;
    for (size_t i = 0; i < spans.size(); ++i) {
        if (static_cast<double>(spans[i].end_frame + 1) >= commit_limit) break;
        if (!std::isspace(static_cast<unsigned char>(spans[i].ch))) {
            committed_count = static_cast<int>(i) + 1;
        }
    }

    if (committed_count > 0) {
        bool leading = false;
        out.text = lane_text(std::vector<Span>(spans.begin(), spans.begin() + committed_count),
                             starts_word, leading);
        out.prepend_space = leading;
        out.committed = !out.text.empty();
        has_committed_text_ = true;
        committed_end_ = spans[static_cast<size_t>(committed_count - 1)].end_frame + 1;
        previous_symbol_ = "char";
        blank_frames_ = 0;
    }

    std::vector<Span> remaining(spans.begin() + committed_count, spans.end());
    const Span* next_character = nullptr;
    for (Span const& span : remaining) {
        if (!std::isspace(static_cast<unsigned char>(span.ch))) {
            next_character = &span;
            break;
        }
    }

    const int limit_end = final ? covered_end_ : frozen_end_;
    const int release_end = std::min(limit_end,
        next_character ? next_character->start_frame : limit_end) - 1;

    std::string previous_symbol = previous_symbol_;
    int blank_frames = blank_frames_;
    for (int frame = committed_end_; frame < release_end; ++frame) {
        const int index = greedy.argmax[static_cast<size_t>(frame - start_frame)];
        if (index == space_index_) {
            previous_symbol = "space";
            blank_frames = 0;
        } else {
            ++blank_frames;
        }
    }
    if (release_end > committed_end_) {
        previous_symbol_ = previous_symbol;
        blank_frames_ = blank_frames;
        committed_end_ = release_end;
    }

    drop_rows_before(committed_end_);

    std::vector<Span> pending_spans;
    for (Span const& span : remaining) {
        if (span.end_frame >= committed_end_) pending_spans.push_back(span);
    }
    bool pending_leading = false;
    out.pending = lane_text(pending_spans,
                            !has_committed_text_ || previous_symbol_ == "space",
                            pending_leading);
    return out;
}

} // namespace DeepCw
} // namespace Cw
