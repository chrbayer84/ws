#include "deepcw_session.hpp"

#include "ort/onnxruntime_c_api.h"

#include <cstdint>
#include <iostream>
#include <mutex>
#include <streambuf>

namespace Cw {
namespace DeepCw {

namespace {

// Some distro ONNX Runtime builds double-register the ONNX operator schemas
// and dump hundreds of "Schema error: ... already registered" lines to
// std::cerr on the first CreateSession(). Redirect cerr to a null buffer for
// that one call; real failures are still returned through OrtStatus.
class NullStreambuf : public std::streambuf {
protected:
    int overflow(int c) override { return c; }
};

std::mutex& cerr_mutex() {
    static std::mutex mutex;
    return mutex;
}

// One ONNX Runtime environment per process (recommended by ORT; avoids
// re-registering the ONNX schemas for every decoder instance). Never released.
OrtEnv* shared_env(OrtApi const* api, std::string& error) {
    static std::once_flag once;
    static OrtEnv* env = nullptr;
    static std::string failure;

    std::call_once(once, [api]() {
        if (!api) {
            failure = "ONNX Runtime API is not available";
            return;
        }
        OrtStatus* status = api->CreateEnv(ORT_LOGGING_LEVEL_FATAL, "wsjtx-deepcw", &env);
        if (status) {
            char const* message = api->GetErrorMessage(status);
            failure = message ? message : "CreateEnv failed";
            api->ReleaseStatus(status);
            env = nullptr;
        }
    });

    if (!env) error = failure;
    return env;
}

} // namespace

struct Session::Impl {
    const OrtApi* api = nullptr;
    OrtEnv* env = nullptr;
    OrtSession* session = nullptr;
    OrtMemoryInfo* memory = nullptr;
    std::string input_name;
    std::string output_name;
    std::string last_error;

    ~Impl() { release(); }

    bool status_ok(OrtStatus* status, std::string& error) {
        if (!status) return true;
        const char* message = api ? api->GetErrorMessage(status) : nullptr;
        error = message ? message : "ONNX Runtime error";
        last_error = error;
        if (api) api->ReleaseStatus(status);
        return false;
    }

    void release() {
        if (!api) return;
        if (session) { api->ReleaseSession(session); session = nullptr; }
        if (memory) { api->ReleaseMemoryInfo(memory); memory = nullptr; }
        // The OrtEnv is shared process-wide and intentionally not released.
    }
};

Session::Session()
    : impl_(new Impl()) {
    impl_->api = OrtGetApiBase()->GetApi(ORT_API_VERSION);
}

Session::~Session() = default;

bool Session::valid() const {
    return impl_->session != nullptr;
}

bool Session::load(std::string const& model_path, int intra_threads, std::string& error) {
    Impl& impl = *impl_;
    if (!impl.api) {
        error = "ONNX Runtime API is not available";
        return false;
    }

    impl.env = shared_env(impl.api, error);
    if (!impl.env) return false;

    OrtStatus* status = nullptr;
    OrtSessionOptions* options = nullptr;
    status = impl.api->CreateSessionOptions(&options);
    if (!impl.status_ok(status, error)) return false;

    status = impl.api->SetIntraOpNumThreads(options, intra_threads > 0 ? intra_threads : 1);
    if (!impl.status_ok(status, error)) {
        impl.api->ReleaseSessionOptions(options);
        return false;
    }
    status = impl.api->SetSessionGraphOptimizationLevel(options, ORT_ENABLE_ALL);
    if (!impl.status_ok(status, error)) {
        impl.api->ReleaseSessionOptions(options);
        return false;
    }

#ifdef _WIN32
    std::wstring wide(model_path.begin(), model_path.end());
    {
        static NullStreambuf null_buf;
        std::lock_guard<std::mutex> quiet(cerr_mutex());
        std::streambuf* old = std::cerr.rdbuf(&null_buf);
        status = impl.api->CreateSession(impl.env, wide.c_str(), options, &impl.session);
        std::cerr.rdbuf(old);
    }
#else
    {
        static NullStreambuf null_buf;
        std::lock_guard<std::mutex> quiet(cerr_mutex());
        std::streambuf* old = std::cerr.rdbuf(&null_buf);
        status = impl.api->CreateSession(impl.env, model_path.c_str(), options, &impl.session);
        std::cerr.rdbuf(old);
    }
#endif
    impl.api->ReleaseSessionOptions(options);
    if (!impl.status_ok(status, error)) return false;

    OrtAllocator* allocator = nullptr;
    status = impl.api->GetAllocatorWithDefaultOptions(&allocator);
    if (!impl.status_ok(status, error)) return false;

    char* input_name = nullptr;
    status = impl.api->SessionGetInputName(impl.session, 0, allocator, &input_name);
    if (!impl.status_ok(status, error)) return false;
    impl.input_name = input_name ? input_name : "";
    status = impl.api->AllocatorFree(allocator, input_name);
    if (!impl.status_ok(status, error)) return false;

    char* output_name = nullptr;
    status = impl.api->SessionGetOutputName(impl.session, 0, allocator, &output_name);
    if (!impl.status_ok(status, error)) return false;
    impl.output_name = output_name ? output_name : "";
    status = impl.api->AllocatorFree(allocator, output_name);
    if (!impl.status_ok(status, error)) return false;

    status = impl.api->CreateCpuMemoryInfo(OrtArenaAllocator, OrtMemTypeDefault, &impl.memory);
    if (!impl.status_ok(status, error)) return false;

    return true;
}

bool Session::run(float const* spectrogram, int time, int bins,
                  std::vector<float>& log_probs, int& out_frames, int& classes,
                  std::string& error) {
    Impl& impl = *impl_;
    if (!impl.session || !impl.memory) {
        error = "DeepCW model is not loaded";
        return false;
    }
    if (!spectrogram || time <= 0 || bins <= 0) {
        error = "Empty spectrogram";
        return false;
    }

    const int64_t dims[4] = {1, 1, time, bins};
    const size_t element_count = static_cast<size_t>(time) * static_cast<size_t>(bins);
    const size_t bytes = element_count * sizeof(float);

    OrtValue* input = nullptr;
    OrtStatus* status = impl.api->CreateTensorWithDataAsOrtValue(
        impl.memory, const_cast<float*>(spectrogram), bytes, dims, 4,
        ONNX_TENSOR_ELEMENT_DATA_TYPE_FLOAT, &input);
    if (!impl.status_ok(status, error)) return false;

    const char* input_names[1] = {impl.input_name.c_str()};
    const char* output_names[1] = {impl.output_name.c_str()};
    OrtValue* output = nullptr;
    status = impl.api->Run(impl.session, nullptr, input_names, &input, 1,
                           output_names, 1, &output);
    impl.api->ReleaseValue(input);
    if (!impl.status_ok(status, error)) return false;

    OrtTensorTypeAndShapeInfo* info = nullptr;
    status = impl.api->GetTensorTypeAndShape(output, &info);
    if (!impl.status_ok(status, error)) {
        impl.api->ReleaseValue(output);
        return false;
    }

    size_t dimensions = 0;
    status = impl.api->GetDimensionsCount(info, &dimensions);
    int64_t shape[3] = {1, 0, 0};
    size_t count = 0;
    if (impl.status_ok(status, error)) {
        if (dimensions >= 1 && dimensions <= 3) {
            status = impl.api->GetDimensions(info, shape, dimensions);
        }
        if (impl.status_ok(status, error)) {
            status = impl.api->GetTensorShapeElementCount(info, &count);
        }
    }
    impl.api->ReleaseTensorTypeAndShapeInfo(info);
    if (!impl.status_ok(status, error)) {
        impl.api->ReleaseValue(output);
        return false;
    }

    float* data = nullptr;
    status = impl.api->GetTensorMutableData(output, reinterpret_cast<void**>(&data));
    if (!impl.status_ok(status, error)) {
        impl.api->ReleaseValue(output);
        return false;
    }

    if (dimensions == 3) {
        out_frames = static_cast<int>(shape[1]);
        classes = static_cast<int>(shape[2]);
    } else {
        out_frames = 0;
        classes = 0;
    }
    if (out_frames <= 0 || classes <= 0
        || static_cast<size_t>(out_frames) * classes > count) {
        impl.api->ReleaseValue(output);
        error = "Unexpected model output shape";
        return false;
    }

    log_probs.assign(data, data + static_cast<size_t>(out_frames) * classes);
    impl.api->ReleaseValue(output);
    return true;
}

} // namespace DeepCw
} // namespace Cw
