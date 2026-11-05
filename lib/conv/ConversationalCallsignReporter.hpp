#ifndef CONVERSATIONAL_CALLSIGN_REPORTER_HPP_
#define CONVERSATIONAL_CALLSIGN_REPORTER_HPP_

#include <QDateTime>
#include <QString>
#include <QVector>

namespace Conversational
{
  struct DecodedMessage
  {
    qint64 messageId {0};
    float frequency {0.f};
    QString text;
    QDateTime time;
    int snr {-10};
    bool complete {false};
  };

  struct Observation
  {
    QString raw;
    QString base;
    QString prefix;
    QString numberGroup;
    QString suffix;
    float frequency {0.f};
    int snr {-10};
    bool cqContext {false};
    bool deContext {false};
    bool gridPresent {false};
    QString grid;
    bool twoDigit {false};
    bool cannotBeGrid {false};
    bool longerPrefixCandidate {false};
    int occurrences {1};
    QDateTime time;
    double score {0.0};
  };

  struct Report
  {
    QString call;
    QString grid;
    float frequency {0.f};
    int snr {-10};
    QDateTime time;
    QString mode;

    QString udpMessageText () const
    {
      return grid.isEmpty () ? QStringLiteral ("CQ ") + call
        : QStringLiteral ("CQ ") + call + QLatin1Char (' ') + grid;
    }
  };

  class CallsignReporter
  {
  public:
    CallsignReporter ();

    void reset ();

    QVector<Report> process (QString const& mode,
                             QVector<DecodedMessage> const& messages,
                             QString const& myCall);

    static bool isValidCallsign (QString const& token, QString * base = nullptr);
    static bool isValidGrid (QString const& token);
    static QString normalizeText (QString const& text);

    static QVector<Observation> extractObservations (QString const& text,
                                                     float frequency, int snr,
                                                     QDateTime const& time,
                                                     QString const& myCall,
                                                     QString const& mode = {});

  private:
    struct Track
    {
      QString mode;
      double frequency {0.0};
      QVector<Observation> recent;
      QDateTime lastSeen;
      bool sourceConfirmed {false};
      QString sourceGrid;
    };

    QVector<Track> tracks_;
  };
}

#endif
