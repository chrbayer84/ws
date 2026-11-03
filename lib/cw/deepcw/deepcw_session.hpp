#ifndef CW_DEEPCW_SESSION_HPP
#define CW_DEEPCW_SESSION_HPP

#include <memory>
#include <string>
#include <vector>

namespace Cw {
namespace DeepCw {

// Minimal ONNX Runtime session for the DeepCW models. Keeps the ORT C API out
// of the public header.
class Session {
public:
    Session();
    ~Session();

    Session(Session const&) = delete;
    Session& operator=(Session const&) = delete;

    bool load(std::string const& model_path, int intra_threads, std::string& error);
    bool run(float const* spectrogram, int time, int bins,
             std::vector<float>& log_probs, int& out_frames, int& classes,
             std::string& error);

    bool valid() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace DeepCw
} // namespace Cw

#endif // CW_DEEPCW_SESSION_HPP
