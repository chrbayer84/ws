#include "PskDecoder.hpp"
#include "psk_carrier_detector.hpp"
#include "psk_modem.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string>
#include <utility>
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
    rx_audio.reserve (tx_audio.size () / 4 + 48000);
    for (std::size_t i = 0; i < tx_audio.size (); i += 4) {
      rx_audio.push_back (tx_audio[i]);
    }
    rx_audio.resize (rx_audio.size () + 48000, 0);
    return rx_audio;
  }

  std::vector<int16_t> mix (std::vector<std::vector<int16_t>> const & sources)
  {
    std::size_t length = 0;
    for (auto const & signal : sources) length = std::max (length, signal.size ());
    length += 48000;

    std::vector<int32_t> sum (length, 0);
    for (auto const & signal : sources) {
      for (std::size_t i = 0; i < signal.size (); ++i) {
        sum[i] += signal[i] / static_cast<int32_t> (sources.size ());
      }
    }

    std::vector<int16_t> result (length, 0);
    for (std::size_t i = 0; i < length; ++i) {
      result[i] = static_cast<int16_t> (std::max (-32768L,
        std::min (32767L, static_cast<long> (sum[i]))));
    }
    return result;
  }

  struct Decoded
  {
    Decoded (double f, std::string t) : frequency {f}, text {std::move (t)} {}
    double frequency;
    std::string text;
  };

  std::vector<Decoded> decode (std::vector<int16_t> const & audio,
                                double center, bool dynamic)
  {
    Psk::Decoder decoder;
    decoder.configureBrowser (true, 30, dynamic);
    decoder.begin (1, 0, 0);
    decoder.setSubmode (QStringLiteral ("PSK31"));
    decoder.setSquelch (5.0);

    std::vector<Decoded> completed;
    for (std::size_t offset = 0; offset < audio.size (); offset += 480) {
      int const count = int (std::min<std::size_t> (480, audio.size () - offset));
      decoder.process (audio.data () + offset, count, qint64 (offset),
                       0, 1000, 200, 2800, float (center), 50.0f);
      for (auto const & update : decoder.takeUpdates ()) {
        if (update.complete && update.text.trimmed ().size () >= 3) {
          completed.push_back (Decoded {double (update.frequency),
                                      update.text.toStdString ()});
        }
      }
    }
    return completed;
  }

  std::string joined (std::vector<Decoded> const & decoded)
  {
    std::string text;
    for (auto const & item : decoded) text += item.text;
    return text;
  }
}

int main ()
{
  std::string const first_call = "WA4YA";
  std::string const second_call = "K1JT";

  {
    auto const audio = make_audio ("CQ " + first_call + " CQ", 1000.0);
    Psk::CarrierDetector detector;
    detector.setPassband (200, 2800);
    for (std::size_t offset = 0; offset < audio.size (); offset += 480) {
      int const count = int (std::min<std::size_t> (480, audio.size () - offset));
      detector.process (audio.data () + offset, count);
      if (offset > 16000) break;
    }
    Psk::CarrierCandidate candidate;
    check (detector.peakInRange (950.0, 1050.0, candidate),
           "detector should find the PSK carrier");
    check (std::abs (candidate.frequency - 1000.0) < 2.0,
           "detector carrier estimate should be within 2 Hz");
  }

  {
    auto const audio = mix ({
      make_audio ("CQ " + first_call + " CQ", 500.0),
      make_audio ("CQ " + second_call + " CQ", 2400.0)});
    std::string const text = joined (decode (audio, 1500.0, false));
    check (text.find (first_call) != std::string::npos,
           "fixed-slot browser should decode a signal at 500 Hz");
    check (text.find (second_call) != std::string::npos,
           "fixed-slot browser should decode a signal at 2400 Hz");
  }

  {
    auto const audio = mix ({
      make_audio ("CQ " + first_call + " CQ", 500.0),
      make_audio ("CQ " + second_call + " CQ", 2400.0)});
    std::string const text = joined (decode (audio, 1500.0, true));
    check (text.find (first_call) != std::string::npos,
           "dynamic browser should decode a signal at 500 Hz");
    check (text.find (second_call) != std::string::npos,
           "dynamic browser should decode a signal at 2400 Hz");
  }

  {
    auto const audio = make_audio ("CQ " + first_call + " CQ", 1000.0);
    std::string const text = joined (decode (audio, 1000.0, false));
    check (text.find (first_call) != std::string::npos,
           "selected-tone primary decoder should work independently");
  }
  {
    std::vector<std::string> const messages {
      "CQ " + first_call + " CQ",
      "TESTING TESTING TESTING " + first_call,
      "CQ " + first_call + " CQ",
      "TESTING TESTING TESTING " + first_call,
      "CQ " + first_call + " CQ"};
    std::vector<int16_t> audio;
    for (auto const & message : messages) {
      auto const part = make_audio (message, 1427.0);
      audio.insert (audio.end (), part.begin (), part.end ());
    }
    auto const fixed = decode (audio, 1427.0, false);
    check (fixed.size () == messages.size (),
           "fixed browser should emit one completion per repeated transmission");
    for (std::size_t i = 0; i < fixed.size () && i < messages.size (); ++i) {
      if (fixed[i].text != messages[i]) {
        std::printf ("fixed[%zu] = '%s' expected '%s'\n", i,
                     fixed[i].text.c_str (), messages[i].c_str ());
      }
      check (fixed[i].text == messages[i],
             "fixed browser should decode repeated messages without stale state");
    }

    auto const dynamic = decode (audio, 1427.0, true);
    check (dynamic.size () == messages.size (),
           "dynamic browser should emit one completion per repeated transmission");
    for (std::size_t i = 0; i < dynamic.size () && i < messages.size (); ++i) {
      if (dynamic[i].text != messages[i]) {
        std::printf ("dynamic[%zu] = '%s' expected '%s'\n", i,
                     dynamic[i].text.c_str (), messages[i].c_str ());
      }
      check (dynamic[i].text == messages[i],
             "dynamic browser should decode repeated messages without stale state");
    }
  }


  {
    auto const audio = mix ({
      make_audio ("CQ " + first_call + " CQ", 1000.0),
      make_audio ("CQ " + second_call + " CQ", 1100.0)});
    std::string const text = joined (decode (audio, 1500.0, true));
    check (text.find (first_call) != std::string::npos,
           "dynamic browser should decode the lower of two close signals");
    check (text.find (second_call) != std::string::npos,
           "dynamic browser should decode the upper of two close signals");
  }

  if (failures) {
    std::printf ("test_psk_multichannel: %d checks failed\n", failures);
    return 1;
  }
  std::printf ("test_psk_multichannel: all checks passed\n");
  return 0;
}
