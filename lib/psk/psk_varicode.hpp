#ifndef PSK_VARICODE_HPP
#define PSK_VARICODE_HPP

#include <string>
#include <cstdint>

namespace Psk {

const char* varicode_encode(uint8_t c);
int varicode_decode(uint32_t symbol);

} // namespace Psk

#endif // PSK_VARICODE_HPP