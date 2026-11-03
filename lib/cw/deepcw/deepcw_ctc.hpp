#ifndef CW_DEEPCW_CTC_HPP
#define CW_DEEPCW_CTC_HPP

#include "deepcw_types.hpp"

#include <string>
#include <vector>

namespace Cw {
namespace DeepCw {

struct Span {
    char ch = ' ';
    int start_frame = 0;
    int end_frame = 0;
};

struct GreedyResult {
    std::vector<Span> spans;
    std::vector<int> argmax;
};

// Greedy CTC over model log-probabilities [frames, classes], with the
// reference decoder's word-boundary insertion on long blank runs.
GreedyResult decode_greedy(float const* scores, int frames, int classes,
                           ModelSpec const& spec,
                           std::string const& previous_symbol,
                           int blank_frames,
                           int word_boundary_frames);

// Collapses spans to text, turning the model's space class into word breaks.
std::string lane_text(std::vector<Span> const& spans, bool prepend_space,
                      bool& has_leading_space);

} // namespace DeepCw
} // namespace Cw

#endif // CW_DEEPCW_CTC_HPP
