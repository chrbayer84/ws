#include "deepcw_ctc.hpp"

#include <algorithm>
#include <cctype>

namespace Cw {
namespace DeepCw {

GreedyResult decode_greedy(float const* scores, int frames, int classes,
                           ModelSpec const& spec,
                           std::string const& previous_symbol,
                           int blank_frames,
                           int word_boundary_frames) {
    GreedyResult result;
    if (!scores || frames <= 0 || classes <= 0) return result;

    result.argmax.resize(static_cast<size_t>(frames));
    for (int t = 0; t < frames; ++t) {
        float best = -1e30f;
        int best_index = 0;
        const float* row = scores + static_cast<size_t>(t) * classes;
        for (int c = 0; c < classes; ++c) {
            if (row[c] > best) {
                best = row[c];
                best_index = c;
            }
        }
        result.argmax[t] = best_index;
    }

    const int space = space_index(spec);
    const int blank = spec.blank_index;

    if (space >= 0) {
        int previous = -1;
        if (previous_symbol == "char") {
            previous = -2;
        } else if (previous_symbol == "space") {
            previous = space;
        }

        int frame = 0;
        while (frame < frames) {
            if (result.argmax[frame] != blank) {
                previous = result.argmax[frame];
                ++frame;
                continue;
            }

            const int run_start = frame;
            while (frame < frames && result.argmax[frame] == blank) {
                ++frame;
            }
            const int following = (frame < frames) ? result.argmax[frame] : -1;
            const int run_length = (frame - run_start) + (run_start == 0 ? blank_frames : 0);
            if (run_length >= word_boundary_frames
                && previous != -1 && previous != space
                && following >= 0 && following != space) {
                for (int i = run_start; i < frame; ++i) {
                    result.argmax[i] = space;
                }
            }
        }
    }

    int previous_index = -1;
    int active = -1;
    for (int t = 0; t < frames; ++t) {
        const int index = result.argmax[t];
        if (index == blank) {
            previous_index = -1;
            active = -1;
            continue;
        }
        if (index == previous_index) {
            if (active >= 0) {
                result.spans[active].end_frame = t;
            }
            continue;
        }
        previous_index = index;
        if (index < 0 || index >= spec.num_classes) {
            active = -1;
            continue;
        }
        Span span;
        span.ch = spec.chars[index][0];
        span.start_frame = t;
        span.end_frame = t;
        result.spans.push_back(span);
        active = static_cast<int>(result.spans.size()) - 1;
    }

    return result;
}

std::string lane_text(std::vector<Span> const& spans, bool prepend_space,
                      bool& has_leading_space) {
    std::string output;
    has_leading_space = prepend_space;
    bool pending_space = false;

    for (Span const& span : spans) {
        if (std::isspace(static_cast<unsigned char>(span.ch))) {
            if (output.empty()) {
                has_leading_space = true;
            } else {
                pending_space = true;
            }
            continue;
        }
        if (pending_space) {
            output.push_back(' ');
            pending_space = false;
        }
        output.push_back(span.ch);
    }

    return output;
}

} // namespace DeepCw
} // namespace Cw
