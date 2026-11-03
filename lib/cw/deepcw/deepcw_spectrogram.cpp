#include "deepcw_spectrogram.hpp"

#include <algorithm>
#include <cmath>

namespace Cw {
namespace DeepCw {

namespace {

constexpr double kNoiseQuantile = 0.9;
constexpr double kNoiseMinRelativeToPeak = 1e-3;
constexpr double kNoiseMin = 1e-5;
constexpr double kSidebandMaskHz = 150.0;
constexpr double kSidebandMaskDb = 18.0;

int bin_for_hz(double hz) {
    return static_cast<int>(std::llround(hz / kBinHz));
}

} // namespace

void normalize_noise_q90_log1p(std::vector<float>& spectrogram,
                               std::vector<float> const& noise_values) {
    if (spectrogram.empty() || noise_values.empty()) return;

    std::vector<float> sorted(noise_values);
    std::sort(sorted.begin(), sorted.end());

    const double rayleigh_factor = std::sqrt(-2.0 * std::log(1.0 - kNoiseQuantile));
    const size_t index = static_cast<size_t>(std::floor(
        kNoiseQuantile * static_cast<double>(sorted.size() - 1)));
    const double noise_level = std::max({
        static_cast<double>(sorted[index]) / rayleigh_factor,
        static_cast<double>(sorted.back()) * kNoiseMinRelativeToPeak,
        kNoiseMin,
    });

    for (float& value : spectrogram) {
        value = static_cast<float>(std::log1p(static_cast<double>(value) / noise_level));
    }
}

Frontend::Frontend()
    : stft_(kFftLength, kHopLength)
    , detect_stft_(kFftLength, kDetectHopLength) {
}

bool Frontend::standard(float const* samples, int count,
                        std::vector<float>& out, int& frames) const {
    frames = stft_.frame_count(count);
    if (frames <= 0) return false;

    const ModelSpec& spec = standard_spec();
    const int total_bins = kFftLength / 2 + 1;
    int start_bin = static_cast<int>(std::ceil(spec.min_freq_hz / kBinHz));
    int stop_bin = static_cast<int>(std::floor(spec.max_freq_hz / kBinHz)) + 1;
    start_bin = std::max(0, std::min(start_bin, total_bins));
    stop_bin = std::max(start_bin, std::min(stop_bin, total_bins));
    if (stop_bin - start_bin != spec.frequency_bins) return false;

    if (!stft_.magnitudes(samples, count, 0, frames, start_bin, stop_bin, out)) {
        frames = 0;
        return false;
    }
    normalize_noise_q90_log1p(out, out);
    return true;
}

bool Frontend::shifted(float const* samples, int count, double target_hz,
                       double bandwidth_hz, std::vector<float>& out, int& frames) const {
    frames = stft_.frame_count(count);
    if (frames <= 0) return false;

    const ModelSpec& spec = standard_spec();
    const int total_bins = kFftLength / 2 + 1;
    const int out_bins = spec.frequency_bins;
    const int center_out = bin_for_hz(0.5 * (spec.min_freq_hz + spec.max_freq_hz))
        - static_cast<int>(std::ceil(spec.min_freq_hz / kBinHz)); // 800 Hz -> index 32

    const int target_bin = bin_for_hz(target_hz);
    const int half_width = std::max(0, static_cast<int>(
        std::ceil(0.5 * bandwidth_hz / kBinHz)));

    const int src_lo = std::max(0, target_bin - half_width);
    const int src_hi = std::min(total_bins, target_bin + half_width + 1);
    if (src_hi <= src_lo) return false;
    const int src_bins = src_hi - src_lo;

    std::vector<float> mags;
    if (!stft_.magnitudes(samples, count, 0, frames, src_lo, src_hi, mags)) {
        frames = 0;
        return false;
    }

    out.assign(static_cast<size_t>(frames) * out_bins, 0.0f);
    const int dest_lo = std::max(0, center_out - half_width);
    const int dest_hi = std::min(out_bins, center_out + half_width + 1);
    std::vector<float> noise;
    noise.reserve(static_cast<size_t>(frames) * std::max(0, dest_hi - dest_lo));

    for (int f = 0; f < frames; ++f) {
        const float* src = mags.data() + static_cast<size_t>(f) * src_bins;
        float* dst = out.data() + static_cast<size_t>(f) * out_bins;
        for (int s = src_lo; s < src_hi; ++s) {
            const int dest = center_out + (s - target_bin);
            if (dest < 0 || dest >= out_bins) continue;
            const float value = src[s - src_lo];
            dst[dest] = value;
            if (dest >= dest_lo && dest < dest_hi) noise.push_back(value);
        }
    }

    normalize_noise_q90_log1p(out, noise);
    return true;
}

bool Frontend::narrow(float const* samples, int count, double target_hz,
                      std::vector<float>& out, int& frames) const {
    frames = stft_.frame_count(count);
    if (frames <= 0) return false;

    const ModelSpec& spec = narrow_spec();
    const int total_bins = kFftLength / 2 + 1;
    const int target_bin = bin_for_hz(target_hz);
    const int center = spec.frequency_bins / 2;

    const int src_lo = target_bin - center;
    const int src_hi = target_bin + (spec.frequency_bins - center);
    if (src_lo < 0 || src_hi > total_bins) {
        // Pad out-of-range bins with silence rather than rejecting valid tones
        // at the band edges.
        std::vector<float> mags;
        if (!stft_.magnitudes(samples, count, 0, frames,
                              std::max(0, src_lo), std::min(total_bins, src_hi), mags)) {
            frames = 0;
            return false;
        }
        const int got_lo = std::max(0, src_lo);
        const int got_bins = std::min(total_bins, src_hi) - got_lo;
        out.assign(static_cast<size_t>(frames) * spec.frequency_bins, 0.0f);
        for (int f = 0; f < frames; ++f) {
            for (int b = 0; b < spec.frequency_bins; ++b) {
                const int src = src_lo + b;
                if (src < got_lo || src >= got_lo + got_bins) continue;
                out[static_cast<size_t>(f) * spec.frequency_bins + b] =
                    mags[static_cast<size_t>(f) * got_bins + (src - got_lo)];
            }
        }
        normalize_noise_q90_log1p(out, out);
        return true;
    }

    if (!stft_.magnitudes(samples, count, 0, frames, src_lo, src_hi, out)) {
        frames = 0;
        return false;
    }
    normalize_noise_q90_log1p(out, out);
    return true;
}

Frontend::Detection Frontend::detect(float const* samples, int count,
                                     double min_hz, double max_hz) const {
    Detection result;
    const int frames = detect_stft_.frame_count(count);
    if (frames <= 0) return result;

    const int total_bins = kFftLength / 2 + 1;
    const int min_bin = std::max(0, static_cast<int>(
        std::ceil(std::max(0.0, min_hz) / kBinHz)));
    const int max_bin = std::min(total_bins - 1, static_cast<int>(
        std::floor(std::min(kInputRate / 2.0, max_hz) / kBinHz)));
    if (max_bin < min_bin) return result;

    const int bin_count = max_bin - min_bin + 1;
    std::vector<float> mags;
    if (!detect_stft_.magnitudes(samples, count, 0, frames, min_bin, max_bin + 1, mags)) {
        return result;
    }

    std::vector<float> powers(static_cast<size_t>(bin_count) * frames);
    // Keep the working set bin-major (bin * frames + frame) for the per-bin
    // percentile pass below; the model tensors remain frame-major.
    for (int f = 0; f < frames; ++f) {
        const float* mag_row = mags.data() + static_cast<size_t>(f) * bin_count;
        for (int b = 0; b < bin_count; ++b) {
            const float m = mag_row[b];
            powers[static_cast<size_t>(b) * frames + f] = m * m;
        }
    }

    std::vector<float> all(powers);
    std::sort(all.begin(), all.end());
    const float peak_power = all.back();
    // A quiet band (or synthetic zero-noise audio) has a near-zero median;
    // clamp the floor relative to the peak so silence doesn't look like a
    // band full of 70 dB carriers.
    const float noise_power = std::max({
        all[all.size() / 2],
        peak_power * 1e-6f,
        1e-12f,
    });

    std::vector<float> snr(bin_count);
    std::vector<float> scratch;
    scratch.reserve(frames);
    for (int b = 0; b < bin_count; ++b) {
        scratch.assign(powers.begin() + static_cast<size_t>(b) * frames,
                       powers.begin() + static_cast<size_t>(b + 1) * frames);
        std::sort(scratch.begin(), scratch.end());
        const float on = scratch[static_cast<size_t>(0.9 * (frames - 1))];
        snr[b] = 10.0f * std::log10(std::max(on, 1e-12f) / noise_power);
    }

    const int mask_bins = static_cast<int>(std::llround(kSidebandMaskHz / kBinHz));
    std::vector<float> masked(snr);
    for (int b = 0; b < bin_count; ++b) {
        const int lo = std::max(0, b - mask_bins);
        const int hi = std::min(bin_count - 1, b + mask_bins);
        for (int other = lo; other <= hi; ++other) {
            if (snr[other] - snr[b] > kSidebandMaskDb) {
                masked[b] = 0.0f;
                break;
            }
        }
    }

    result.frequencies.resize(bin_count);
    result.snr_db.resize(bin_count);
    for (int b = 0; b < bin_count; ++b) {
        result.frequencies[b] = (min_bin + b) * kBinHz;
        result.snr_db[b] = masked[b];
    }
    return result;
}

} // namespace DeepCw
} // namespace Cw
