#include "ConversationalCallsignReporter.hpp"

#include "Radio.hpp"

#include <QRegularExpression>
#include <QStringList>

#include <algorithm>
#include <cmath>

namespace
{
  QRegularExpression const base_call_re {
    QStringLiteral (R"(^(?:[A-Z]{0,2}|[A-Z][0-9]|[0-9][A-Z])[0-9]{1,2}[A-Z]{1,4}$)")};
  QRegularExpression const compound_call_re {QStringLiteral (R"(^[A-Z0-9/]{3,11}$)")};
  QRegularExpression const grid_re {
    QStringLiteral (R"(\A(?![Rr]{2}73)[A-Ra-r]{2}[0-9]{2}([A-Xa-x]{2}){0,1}\z)")};
  QRegularExpression const report_re {QStringLiteral (R"(^[1-5][1-9][1-9]$)")};
  QRegularExpression const report_n_re {QStringLiteral (R"(^[1-5][1-9]N$)")};
  QRegularExpression const report_5nn_re {QStringLiteral (R"(^5NN$)")};
  QRegularExpression const suffix_re {QStringLiteral (R"(^([0-9]{1,2})([A-Z]{1,4})$)" )};

  bool is_upper_letter (QChar c)
  {
    return c >= QLatin1Char ('A') && c <= QLatin1Char ('Z');
  }

  bool is_digit (QChar c)
  {
    return c >= QLatin1Char ('0') && c <= QLatin1Char ('9');
  }

  bool is_blocked_word (QString const& token)
  {
    static QStringList const blocked {
      QStringLiteral ("CQ"), QStringLiteral ("QRZ"), QStringLiteral ("DE"),
      QStringLiteral ("DX"), QStringLiteral ("TEST"), QStringLiteral ("TU"),
      QStringLiteral ("73"), QStringLiteral ("88"), QStringLiteral ("R"),
      QStringLiteral ("RR"), QStringLiteral ("K"), QStringLiteral ("KN"),
      QStringLiteral ("BK"), QStringLiteral ("AR"), QStringLiteral ("SK"),
      QStringLiteral ("QSL"), QStringLiteral ("QTH"), QStringLiteral ("QRP"),
      QStringLiteral ("QSY"), QStringLiteral ("AGN"), QStringLiteral ("PSE"),
      QStringLiteral ("UR"), QStringLiteral ("ES"), QStringLiteral ("FB"),
      QStringLiteral ("GE"), QStringLiteral ("GM"), QStringLiteral ("GA"),
      QStringLiteral ("HSC"), QStringLiteral ("CMT"), QStringLiteral ("LP"),
      QStringLiteral ("RST"), QStringLiteral ("NA"), QStringLiteral ("EU"),
      QStringLiteral ("AS"), QStringLiteral ("AF"), QStringLiteral ("SA"),
      QStringLiteral ("OC"), QStringLiteral ("LOW"), QStringLiteral ("HIGH"),
      QStringLiteral ("UP"), QStringLiteral ("DOWN"), QStringLiteral ("PORT"),
      QStringLiteral ("MOBILE"), QStringLiteral ("MM"), QStringLiteral ("AM"),
      QStringLiteral ("CQDX"), QStringLiteral ("CQTEST")
    };
    return blocked.contains (token);
  }

  bool is_report (QString const& token)
  {
    return report_re.match (token).hasMatch ()
      || report_n_re.match (token).hasMatch ()
      || report_5nn_re.match (token).hasMatch ();
  }

  bool is_valid_prefix (QString const& prefix)
  {
    if (prefix.isEmpty ()) return true;
    if (prefix.size () == 1) return is_upper_letter (prefix[0]);
    if (prefix.size () != 2) return false;
    QChar const first = prefix[0];
    QChar const second = prefix[1];
    return (is_upper_letter (first) && is_upper_letter (second))
      || (is_upper_letter (first) && is_digit (second))
      || (is_digit (first) && is_upper_letter (second));
  }

  bool parse_base_call (QString const& base, QString& prefix,
                        QString& number_group, QString& suffix)
  {
    for (int length = 2; length >= 0; --length) {
      QString const candidate_prefix = base.left (length);
      if (!is_valid_prefix (candidate_prefix)) continue;
      auto const match = suffix_re.match (base.mid (length));
      if (match.hasMatch ()) {
        prefix = candidate_prefix;
        number_group = match.captured (1);
        suffix = match.captured (2);
        return true;
      }
    }
    return false;
  }

  bool is_valid_base_call (QString const& base)
  {
    if (base.size () < 3) return false;
    if (!base_call_re.match (base).hasMatch ()) return false;
    if (is_blocked_word (base) || is_report (base)) return false;
    QString prefix;
    QString number_group;
    QString suffix;
    return parse_base_call (base, prefix, number_group, suffix);
  }

  QStringList tokenize (QString const& text)
  {
    QStringList result;
    for (auto const& token : Conversational::CallsignReporter::normalizeText (text).split (QLatin1Char (' '))) {
      if (!token.isEmpty ()) result.append (token);
    }
    return result;
  }

  double suffix_similarity (QString const& lhs, QString const& rhs)
  {
    if (lhs == rhs) return 1.0;
    if (lhs.isEmpty () || rhs.isEmpty ()) return 0.0;
    if (lhs.startsWith (rhs) || rhs.startsWith (lhs)) return 1.0;

    int const rows = lhs.size () + 1;
    int const cols = rhs.size () + 1;
    QVector<int> previous (cols);
    QVector<int> current (cols);
    for (int column = 0; column < cols; ++column) previous[column] = column;

    for (int row = 1; row < rows; ++row) {
      current[0] = row;
      for (int column = 1; column < cols; ++column) {
        int const substitution = previous[column - 1]
          + (lhs[row - 1] == rhs[column - 1] ? 0 : 1);
        current[column] = std::min ({previous[column] + 1,
                                     current[column - 1] + 1,
                                     substitution});
      }
      previous = current;
    }

    int const distance = previous[cols - 1];
    return 1.0 - double (distance) / double (std::max (lhs.size (), rhs.size ()));
  }

  double recency_weight (QDateTime const& time, QDateTime const& newest)
  {
    if (!time.isValid () || !newest.isValid ()) return 1.0;
    qint64 const seconds = std::max<qint64> (0, time.secsTo (newest));
    return 1.0 / (1.0 + double (seconds) / 60.0);
  }

  struct ClusterChoice
  {
    QString call;
    QString suffix;
    int support {0};
    double score {0.0};
  };

  ClusterChoice choose_cluster (QVector<Conversational::Observation> const& recent,
                                Conversational::Observation const& current)
  {
    QVector<Conversational::Observation> members;
    for (auto const& observation : recent) {
      if (observation.prefix != current.prefix
          || observation.numberGroup != current.numberGroup) continue;
      if (suffix_similarity (observation.suffix, current.suffix) < 0.6) continue;
      members.append (observation);
    }

    ClusterChoice choice;
    for (auto const& member : members) {
      choice.support += member.occurrences;
      choice.score += member.score * recency_weight (member.time, current.time);
    }
    if (members.isEmpty ()) return choice;

    Conversational::Observation best;
    int best_count = 0;
    double best_value = -1.0;
    for (auto const& candidate : members) {
      double value = 0.0;
      for (auto const& other : members) {
        value += suffix_similarity (candidate.suffix, other.suffix) * other.score;
      }
      int count = 0;
      for (auto const& other : members) {
        if (other.raw == candidate.raw) count += other.occurrences;
      }

      bool better = value > best_value + 1.0e-9;
      if (!better && std::abs (value - best_value) <= 1.0e-9) {
        if (candidate.score > best.score + 1.0e-9) better = true;
        else if (std::abs (candidate.score - best.score) <= 1.0e-9) {
          if (count > best_count) better = true;
          else if (count == best_count) {
            if (candidate.suffix.size () > best.suffix.size ()) better = true;
            else if (candidate.suffix.size () == best.suffix.size ()
                     && candidate.time < best.time) better = true;
          }
        }
      }

      if (better) {
        best = candidate;
        best_count = count;
        best_value = value;
      }
    }

    int representative_length = best.suffix.size ();
    for (auto const& candidate : members) {
      if (candidate.suffix.size () <= representative_length) continue;
      int count = 0;
      for (auto const& other : members) {
        if (other.raw == candidate.raw) count += other.occurrences;
      }
      if (count >= 2) {
        best = candidate;
        best_count = count;
        representative_length = candidate.suffix.size ();
      }
    }

    choice.call = best.raw;
    choice.suffix = best.suffix;
    return choice;
  }

  bool single_shot_eligible (Conversational::Observation const& observation)
  {
    if (observation.suffix.size () < 2) return false;
    if (!observation.cqContext && !observation.deContext) return false;
    if (observation.twoDigit && Conversational::CallsignReporter::isValidGrid (observation.raw)) {
      return false;
    }
    if (observation.snr < 2 && observation.occurrences < 2) return false;
    return !observation.longerPrefixCandidate;
  }

  struct Mention
  {
    QString raw;
    QString base;
    QString prefix;
    QString numberGroup;
    QString suffix;
    QString grid;
    int occurrences {1};
  };

  QVector<Mention> extract_mentions (QString const& text, QString const& myCall)
  {
    QVector<Mention> mentions;
    QStringList const tokens = tokenize (text);
    QString const my_base = Radio::base_callsign (myCall.trimmed ().toUpper ());

    for (auto const& token : tokens) {
      QString base;
      if (!Conversational::CallsignReporter::isValidCallsign (token, &base)) continue;
      if (!my_base.isEmpty () && base == my_base) continue;

      auto known = std::find_if (mentions.begin (), mentions.end (),
                                 [&token] (Mention const& mention) {
                                   return mention.raw == token;
                                 });
      if (known != mentions.end ()) {
        ++known->occurrences;
        continue;
      }

      QString prefix;
      QString number_group;
      QString suffix;
      if (!parse_base_call (base, prefix, number_group, suffix)) continue;

      Mention mention;
      mention.raw = token;
      mention.base = base;
      mention.prefix = prefix;
      mention.numberGroup = number_group;
      mention.suffix = suffix;
      for (auto const& other : tokens) {
        if (other != token
            && Conversational::CallsignReporter::isValidGrid (other)) {
          mention.grid = other;
          break;
        }
      }
      mentions.append (mention);
    }
    return mentions;
  }

  double support_score (Mention const& mention, int snr)
  {
    double score = 0.35;
    if (mention.suffix.size () >= 2) score += 0.20;
    double const normalized_snr = std::max (0.0, std::min (1.0, (double (snr) + 20.0) / 40.0));
    score += 0.15 * normalized_snr;
    if (!Conversational::CallsignReporter::isValidGrid (mention.raw)) score += 0.10;
    if (mention.occurrences >= 2) score += 0.05;
    return score;
  }
}

namespace Conversational
{
  CallsignReporter::CallsignReporter () = default;

  void CallsignReporter::reset ()
  {
    tracks_.clear ();
  }

  bool CallsignReporter::isValidGrid (QString const& token)
  {
    return grid_re.match (token).hasMatch ();
  }

  QString CallsignReporter::normalizeText (QString const& text)
  {
    QString normalized;
    normalized.reserve (text.size ());
    for (auto const character : text.toUpper ()) {
      if ((character >= QLatin1Char ('A') && character <= QLatin1Char ('Z'))
          || (character >= QLatin1Char ('0') && character <= QLatin1Char ('9'))
          || character == QLatin1Char ('/')) {
        normalized.append (character);
      } else {
        normalized.append (QLatin1Char (' '));
      }
    }
    return normalized.simplified ();
  }

  bool CallsignReporter::isValidCallsign (QString const& token, QString * base)
  {
    QString const candidate = token.trimmed ().toUpper ();
    if (candidate.isEmpty ()) return false;

    if (candidate.contains (QLatin1Char ('/'))) {
      if (!compound_call_re.match (candidate).hasMatch ()) return false;
      QStringList parts = candidate.split (QLatin1Char ('/'));
      for (auto const& part : parts) {
        if (part.isEmpty ()) return false;
      }

      QString base_call;
      QString const radio_choice = Radio::base_callsign (candidate);
      if (!radio_choice.contains (QLatin1Char ('/')) && is_valid_base_call (radio_choice)) {
        base_call = radio_choice;
      }
      if (base_call.isEmpty ()) {
        std::stable_sort (parts.begin (), parts.end (),
                          [] (QString const& lhs, QString const& rhs) {
                            return lhs.size () > rhs.size ();
                          });
        for (auto const& part : parts) {
          if (is_valid_base_call (part)) {
            base_call = part;
            break;
          }
        }
      }
      if (base_call.isEmpty ()) return false;
      if (base) *base = base_call;
      return true;
    }

    if (!is_valid_base_call (candidate)) return false;
    if (base) *base = candidate;
    return true;
  }

  QVector<Observation> CallsignReporter::extractObservations (
    QString const& text, float frequency, int snr, QDateTime const& time,
    QString const& myCall, QString const& mode)
  {
    QVector<Observation> result;
    QStringList const tokens = tokenize (text);
    if (tokens.isEmpty ()) return result;

    QString source;
    bool cq_context = false;
    bool de_context = false;
    bool structured = false;

    if (mode == QLatin1String ("JTTY") && tokens.size () >= 2) {
      QString const& first = tokens[0];
      QString const& second = tokens[1];
      bool const first_is_context = first == QLatin1String ("CQ")
        || first == QLatin1String ("QRZ") || first == QLatin1String ("DE");
      if ((first_is_context || isValidCallsign (first)) && isValidCallsign (second)) {
        source = second;
        cq_context = first == QLatin1String ("CQ") || first == QLatin1String ("QRZ");
        de_context = first == QLatin1String ("DE")
          || (!cq_context && isValidCallsign (first));
        structured = true;
      }
    }

    if (!structured) {
      int const de_index = tokens.indexOf (QStringLiteral ("DE"));
      if (de_index >= 0) {
        for (int index = de_index + 1; index < tokens.size (); ++index) {
          if (isValidCallsign (tokens[index])) {
            source = tokens[index];
            de_context = true;
            break;
          }
        }
        cq_context = tokens.contains (QStringLiteral ("CQ"))
          || tokens.contains (QStringLiteral ("QRZ"));
      } else {
        int start = -1;
        for (int index = 0; index < tokens.size (); ++index) {
          if (tokens[index] == QLatin1String ("CQ")
              || tokens[index] == QLatin1String ("QRZ")) {
            start = index;
            break;
          }
        }
        if (start >= 0) {
          cq_context = true;
          for (int index = start + 1; index < tokens.size (); ++index) {
            if (isValidCallsign (tokens[index])) {
              source = tokens[index];
              break;
            }
          }
        }
      }
    }

    if (source.isEmpty ()) return result;

    QString base_call;
    if (!isValidCallsign (source, &base_call)) return result;

    QString const my_base = Radio::base_callsign (myCall.trimmed ().toUpper ());
    if (!my_base.isEmpty () && base_call == my_base) return result;

    QString prefix;
    QString number_group;
    QString suffix;
    if (!parse_base_call (base_call, prefix, number_group, suffix)) return result;

    QString grid;
    for (auto const& token : tokens) {
      if (token != source && isValidGrid (token)) {
        grid = token;
        break;
      }
    }

    bool longer_prefix_candidate = false;
    for (auto const& token : tokens) {
      if (token == source) continue;
      QString other_base;
      if (isValidCallsign (token, &other_base)
          && token.startsWith (source) && token.size () > source.size ()) {
        longer_prefix_candidate = true;
        break;
      }
    }

    int occurrences = 0;
    for (auto const& token : tokens) {
      if (token == source) ++occurrences;
    }

    Observation observation;
    observation.raw = source;
    observation.base = base_call;
    observation.prefix = prefix;
    observation.numberGroup = number_group;
    observation.suffix = suffix;
    observation.frequency = frequency;
    observation.snr = snr;
    observation.cqContext = cq_context;
    observation.deContext = de_context;
    observation.grid = grid;
    observation.gridPresent = !grid.isEmpty ();
    observation.twoDigit = number_group.size () == 2;
    observation.cannotBeGrid = !isValidGrid (source);
    observation.longerPrefixCandidate = longer_prefix_candidate;
    observation.occurrences = occurrences;
    observation.time = time;

    double score = 0.35;
    if (suffix.size () >= 2) score += 0.20;
    if (cq_context) score += 0.25;
    if (de_context) score += 0.20;
    double const normalized_snr = std::max (0.0, std::min (1.0, (double (snr) + 20.0) / 40.0));
    score += 0.15 * normalized_snr;
    if (!grid.isEmpty ()) score += 0.05;
    if (observation.cannotBeGrid) score += 0.10;
    if (isValidGrid (source) && !cq_context && !de_context) score -= 0.10;
    if (occurrences >= 2) score += 0.05;
    observation.score = score;

    result.append (observation);
    return result;
  }

  QVector<Report> CallsignReporter::process (
    QString const& mode, QVector<DecodedMessage> const& messages, QString const& myCall)
  {
    QVector<Report> reports;

    for (auto const& message : messages) {
      if (!message.complete || message.text.trimmed ().isEmpty ()) continue;

      QDateTime const now = message.time.isValid ()
        ? message.time : QDateTime::currentDateTimeUtc ();
      for (int index = tracks_.size () - 1; index >= 0; --index) {
        if (tracks_[index].lastSeen.isValid ()
            && tracks_[index].lastSeen.secsTo (now) > 60) {
          tracks_.removeAt (index);
        }
      }

      auto const observations = extractObservations (
        message.text, message.frequency, message.snr, now, myCall, mode);
      QString source_base;
      if (!observations.isEmpty ()) source_base = observations.first ().base;

      for (auto const& observation : observations) {
        Track * track = nullptr;
        double nearest = 75.0;
        for (auto& candidate : tracks_) {
          if (candidate.mode != mode) continue;
          double const distance = std::abs (candidate.frequency - double (observation.frequency));
          if (distance <= nearest) {
            nearest = distance;
            track = &candidate;
          }
        }

        if (!track) {
          Track new_track;
          new_track.mode = mode;
          new_track.frequency = observation.frequency;
          tracks_.append (new_track);
          track = &tracks_.last ();
        } else {
          track->frequency = 0.8 * track->frequency + 0.2 * double (observation.frequency);
        }

        track->lastSeen = now;
        track->sourceConfirmed = true;
        if (!observation.grid.isEmpty ()) track->sourceGrid = observation.grid;
        track->recent.append (observation);
        while (track->recent.size () > 5) track->recent.removeFirst ();

        if (mode == QLatin1String ("JTTY")) {
          Report report;
          report.call = observation.raw;
          report.grid = observation.grid;
          report.frequency = observation.frequency;
          report.snr = observation.snr;
          report.time = observation.time;
          report.mode = mode;
          reports.append (report);
          continue;
        }

        ClusterChoice const cluster = choose_cluster (track->recent, observation);
        if (cluster.call.isEmpty ()) continue;

        bool const reliable = single_shot_eligible (observation)
          || cluster.support >= 3
          || (cluster.support >= 2 && cluster.score >= 1.5);
        if (!reliable) continue;
        if (cluster.suffix.size () == 1 && cluster.support < 3) continue;

        Report report;
        report.call = cluster.call;
        report.grid = observation.grid;
        report.frequency = observation.frequency;
        report.snr = observation.snr;
        report.time = observation.time;
        report.mode = mode;
        reports.append (report);
      }

      if (mode == QLatin1String ("JTTY")) continue;

      auto const mentions = extract_mentions (message.text, myCall);
      for (auto const& mention : mentions) {
        if (!source_base.isEmpty () && mention.base == source_base) continue;

        Track * track = nullptr;
        double nearest = 75.0;
        for (auto& candidate : tracks_) {
          if (candidate.mode != mode || !candidate.sourceConfirmed) continue;
          double const distance = std::abs (candidate.frequency - double (message.frequency));
          if (distance > nearest) continue;

          bool matches = false;
          for (auto const& observation : candidate.recent) {
            if (observation.prefix == mention.prefix
                && observation.numberGroup == mention.numberGroup
                && suffix_similarity (observation.suffix, mention.suffix) >= 0.6) {
              matches = true;
              break;
            }
          }
          if (!matches) continue;

          nearest = distance;
          track = &candidate;
        }

        if (!track) continue;

        Observation support;
        support.raw = mention.raw;
        support.base = mention.base;
        support.prefix = mention.prefix;
        support.numberGroup = mention.numberGroup;
        support.suffix = mention.suffix;
        support.frequency = message.frequency;
        support.snr = message.snr;
        support.grid = mention.grid;
        support.gridPresent = !mention.grid.isEmpty ();
        support.twoDigit = mention.numberGroup.size () == 2;
        support.cannotBeGrid = !isValidGrid (mention.raw);
        support.occurrences = mention.occurrences;
        support.time = now;
        support.score = support_score (mention, message.snr);

        track->frequency = 0.8 * track->frequency + 0.2 * double (message.frequency);
        track->lastSeen = now;
        track->recent.append (support);
        while (track->recent.size () > 5) track->recent.removeFirst ();

        ClusterChoice const cluster = choose_cluster (track->recent, support);
        if (cluster.call.isEmpty ()) continue;

        bool const reliable = cluster.support >= 3
          || (cluster.support >= 2 && cluster.score >= 1.5);
        if (!reliable) continue;
        if (cluster.suffix.size () == 1 && cluster.support < 3) continue;

        Report report;
        report.call = cluster.call;
        report.grid = mention.grid.isEmpty () ? track->sourceGrid : mention.grid;
        report.frequency = message.frequency;
        report.snr = message.snr;
        report.time = now;
        report.mode = mode;
        reports.append (report);
      }
    }

    return reports;
  }
}
