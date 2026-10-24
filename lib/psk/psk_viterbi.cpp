#include "psk_viterbi.hpp"
#include <climits>
#include <cstring>
#include <algorithm>

namespace Psk {

static inline int calcParity(unsigned int v) {
    return __builtin_parity(v);
}

Viterbi::Viterbi(int k, int poly1, int poly2)
    : k_(k), poly1_(poly1), poly2_(poly2),
      nstates_(1 << (k - 1)), outsize_(1 << k),
      tracebackLen_(k * 12), chunkSize_(8), ptr_(0) {
    output_.resize(outsize_, 0);
    metrics_.resize(PATHMEM, std::vector<int>(nstates_, 0));
    history_.resize(PATHMEM, std::vector<int>(nstates_, 0));
    std::memset(sequence_, 0, sizeof(sequence_));
    init();
}

Viterbi::~Viterbi() = default;

void Viterbi::init() {
    tracebackLen_ = k_ * 12;
    chunkSize_ = 8;

    for (int i = 0; i < outsize_; ++i) {
        output_[i] = calcParity(poly1_ & i) | (calcParity(poly2_ & i) << 1);
    }

    for (int i = 0; i < 256; ++i) {
        mettab_[0][i] = 128 - i;
        mettab_[1][i] = i - 128;
    }

    std::memset(sequence_, 0, sizeof(sequence_));
    reset();
}

void Viterbi::reset() {
    for (int i = 0; i < PATHMEM; ++i) {
        std::fill(metrics_[i].begin(), metrics_[i].end(), 0);
        std::fill(history_[i].begin(), history_[i].end(), 0);
    }
    ptr_ = 0;
}

int Viterbi::setTraceback(int trace) {
    if (trace < 0 || trace >= PATHMEM) return -1;
    tracebackLen_ = trace;
    return 0;
}

int Viterbi::setChunkSize(int chunk) {
    if (chunk < 1 || chunk > tracebackLen_) return -1;
    chunkSize_ = chunk;
    return 0;
}

int Viterbi::traceback(int* metric) {
    int bestmetric = INT_MIN;
    int beststate = 0;
    unsigned int p = (ptr_ - 1 + PATHMEM) % PATHMEM;

    for (int i = 0; i < nstates_; ++i) {
        if (metrics_[p][i] > bestmetric) {
            bestmetric = metrics_[p][i];
            beststate = i;
        }
    }

    sequence_[p] = beststate;
    for (int i = 0; i < tracebackLen_; ++i) {
        unsigned int prev = (p - 1 + PATHMEM) % PATHMEM;
        sequence_[prev] = history_[p][sequence_[p]];
        p = prev;
    }

    if (metric) {
        *metric = metrics_[p][sequence_[p]];
    }

    unsigned int c = 0;
    for (int i = 0; i < chunkSize_; ++i) {
        c = (c << 1) | (sequence_[p] & 1);
        p = (p + 1) % PATHMEM;
    }

    if (metric) {
        *metric = metrics_[p][sequence_[p]] - *metric;
    }

    return static_cast<int>(c);
}

int Viterbi::decode(const uint8_t sym[2], int* metric) {
    unsigned int currptr = ptr_;
    unsigned int prevptr = (currptr - 1 + PATHMEM) % PATHMEM;

    int met[4];
    met[0] = mettab_[0][sym[1]] + mettab_[0][sym[0]];
    met[1] = mettab_[0][sym[1]] + mettab_[1][sym[0]];
    met[2] = mettab_[1][sym[1]] + mettab_[0][sym[0]];
    met[3] = mettab_[1][sym[1]] + mettab_[1][sym[0]];

    for (int n = 0; n < nstates_; ++n) {
        int s0 = n;
        int s1 = n + nstates_;
        int p0 = s0 >> 1;
        int p1 = s1 >> 1;

        int m0 = metrics_[prevptr][p0] + met[output_[s0]];
        int m1 = metrics_[prevptr][p1] + met[output_[s1]];

        if (m0 > m1) {
            metrics_[currptr][n] = m0;
            history_[currptr][n] = p0;
        } else {
            metrics_[currptr][n] = m1;
            history_[currptr][n] = p1;
        }
    }

    ptr_ = (ptr_ + 1) % PATHMEM;

    int result = -1;
    if ((ptr_ % chunkSize_) == 0) {
        result = traceback(metric);
    }

    if (metrics_[currptr][0] > INT_MAX / 2) {
        for (int i = 0; i < PATHMEM; ++i) {
            for (int j = 0; j < nstates_; ++j) {
                metrics_[i][j] -= INT_MAX / 2;
            }
        }
    }

    if (metrics_[currptr][0] < INT_MIN / 2) {
        for (int i = 0; i < PATHMEM; ++i) {
            for (int j = 0; j < nstates_; ++j) {
                metrics_[i][j] += INT_MIN / 2;
            }
        }
    }

    return result;
}

Encoder::Encoder(int k, int poly1, int poly2)
    : k_(k), poly1_(poly1), poly2_(poly2) {
    init();
}

void Encoder::init() {
    int size = 1 << k_;
    output_.resize(size, 0);
    for (int i = 0; i < size; ++i) {
        output_[i] = calcParity(poly1_ & i) | (calcParity(poly2_ & i) << 1);
    }
    shreg_ = 0;
    shregmask_ = size - 1;
}

int Encoder::encode(int bit) {
    shreg_ = ((shreg_ << 1) | (bit ? 1 : 0)) & shregmask_;
    return output_[shreg_];
}

} // namespace Psk
