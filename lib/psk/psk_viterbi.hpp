#ifndef PSK_VITERBI_HPP
#define PSK_VITERBI_HPP

#include <vector>
#include <cstdint>

namespace Psk {

class Viterbi {
public:
    static constexpr int PATHMEM = 256;
    static constexpr int DEFAULT_K = 5;
    static constexpr int DEFAULT_POLY1 = 0x17;
    static constexpr int DEFAULT_POLY2 = 0x19;

    explicit Viterbi(int k = DEFAULT_K, int poly1 = DEFAULT_POLY1, int poly2 = DEFAULT_POLY2);
    ~Viterbi();

    Viterbi(const Viterbi&) = delete;
    Viterbi& operator=(const Viterbi&) = delete;

    void init();
    void reset();
    int setTraceback(int trace);
    int setChunkSize(int chunk);

    // Decode 2 soft channel symbols (0..255). Returns decoded chunk (e.g., 8 bits) or -1 if not ready.
    int decode(const uint8_t sym[2], int* metric = nullptr);

private:
    int traceback(int* metric);

    int k_;
    int poly1_;
    int poly2_;
    int nstates_;
    int outsize_;
    int tracebackLen_;
    int chunkSize_;
    unsigned int ptr_;

    std::vector<int> output_;
    int mettab_[2][256];
    std::vector<std::vector<int>> metrics_;
    std::vector<std::vector<int>> history_;
    int sequence_[PATHMEM];
};

class Encoder {
public:
    static constexpr int DEFAULT_K = 5;
    static constexpr int DEFAULT_POLY1 = 0x17;
    static constexpr int DEFAULT_POLY2 = 0x19;

    explicit Encoder(int k = DEFAULT_K, int poly1 = DEFAULT_POLY1, int poly2 = DEFAULT_POLY2);
    ~Encoder() = default;

    void init();
    void reset() { shreg_ = 0; }

    // Feeds 1 bit into the convolutional encoder and returns 2 output code bits (0..3)
    int encode(int bit);

private:
    int k_;
    int poly1_;
    int poly2_;
    uint32_t shreg_ {0};
    uint32_t shregmask_ {0};
    std::vector<int> output_;
};

} // namespace Psk

#endif // PSK_VITERBI_HPP
