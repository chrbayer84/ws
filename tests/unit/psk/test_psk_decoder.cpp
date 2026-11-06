#include "PskDecoder.hpp"
#include "psk_modem.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

namespace
{
  int failures = 0;

  void check (bool condition, char const * what)
  {
    if (!condition) {
      ++failures;
      std::printf ("FAIL: %s\n", what);
    }
  }

  std::vector<int16_t> make_audio (std::string const & text, double frequency)
  {
    Psk::PskModem tx;
    std::vector<int16_t> const tx_audio = tx.modulateText (text, frequency);
    std::vector<int16_t> rx_audio;
    rx_audio.reserve (tx_audio.size () / 4 + 96000);
    for (std::size_t i = 0; i < tx_audio.size (); i += 4) {
      rx_audio.push_back (tx_audio[i]);
    }
    rx_audio.resize (rx_audio.size () + 96000, 0);
    return rx_audio;
  }

  QString decode (std::vector<int16_t> const & audio, double center,
                  std::size_t split = 0)
  {
    Psk::Decoder decoder;
    decoder.begin (1, 0, 0);
    decoder.setSubmode (QStringLiteral ("PSK31"));
    decoder.setSquelch (5.0);

    QString completed;
    auto feed = [&] (std::size_t begin, std::size_t end, bool rewind) {
      if (rewind) decoder.rewind (0);
      for (std::size_t offset = begin; offset < end; offset += 480) {
        int const count = int (std::min<std::size_t> (480, end - offset));
        decoder.process (audio.data () + offset, count, qint64 (offset - begin),
                         0, 1000, 200, 2800,
                         float (center), 50.0f);
        for (auto const & update : decoder.takeUpdates ()) {
          if (update.complete) completed += update.text;
        }
      }
    };

    if (split && split < audio.size ()) {
      feed (0, split, false);
      feed (split, audio.size (), true);
    } else {
      feed (0, audio.size (), false);
    }
    return completed;
  }
}

int main ()
{
  std::string const text = "CQ WA4YA CQ";

  for (double offset : {0.0, 5.0, 10.0, -5.0, -10.0}) {
    auto const audio = make_audio (text, 1000.0 + offset);
    QString const result = decode (audio, 1000.0);
    check (result.contains (QStringLiteral ("WA4YA")),
           "PSK31 should decode at a small carrier offset");
  }

  {
    auto const audio = make_audio (text, 1000.0);
    QString const result = decode (audio, 1000.0);
    check (result.contains (QStringLiteral ("WA4YA CQ")),
           "PSK31 narrow-bank decode should contain the message");
  }

  {
    std::string const long_text = "CQ WA4YA CQ LONG TEST 12345";
    auto const audio = make_audio (long_text, 1000.0);
    QString const result = decode (audio, 1000.0, audio.size () / 2);
    check (result.contains (QStringLiteral ("WA4YA")),
           "PSK31 rewind should preserve a message across a boundary");
    check (result.contains (QStringLiteral ("12345")),
           "PSK31 rewind should preserve the message tail");
  }

  {
    auto const audio = make_audio (text, 1000.0);
    Psk::Decoder decoder;
    decoder.begin (1, 0, 0);
    decoder.setSubmode (QStringLiteral ("PSK31"));
    decoder.setSquelch (5.0);
    int complete_count = 0;
    for (std::size_t offset = 0; offset < audio.size (); offset += 480) {
      int const count = int (std::min<std::size_t> (480, audio.size () - offset));
      decoder.process (audio.data () + offset, count, qint64 (offset),
                       0, 1000, 200, 2800, 1000.0f, 50.0f);
      for (auto const & update : decoder.takeUpdates ()) {
        if (update.complete && update.text.size () >= 3) {
          ++complete_count;
        }
      }
    }
    check (complete_count == 1, "PSK31 adjacent channels should emit one completion");
  }

  if (failures) {
    std::printf ("test_psk_decoder: %d checks failed\n", failures);
    return 1;
  }
  std::printf ("test_psk_decoder: all checks passed\n");
  return 0;
}
