#include "lib/conv/ConversationalCallsignReporter.hpp"

#include <QDate>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QTime>
#include <QVector>

#include <iostream>

namespace
{
  int failures = 0;

  void check (bool condition, QString const& what)
  {
    if (!condition) {
      ++failures;
      std::cerr << "FAIL: " << qPrintable (what) << '\n';
    }
  }

  QDateTime baseTime ()
  {
    return QDateTime (QDate (2026, 1, 1), QTime (12, 0), Qt::UTC);
  }

  QVector<Conversational::DecodedMessage> message (
    QString const& text, float frequency = 500.0f, int snr = 20,
    int seconds = 0, bool complete = true)
  {
    Conversational::DecodedMessage decoded;
    decoded.messageId = 1 + seconds;
    decoded.frequency = frequency;
    decoded.text = text;
    decoded.time = baseTime ().addSecs (seconds);
    decoded.snr = snr;
    decoded.complete = complete;
    return {decoded};
  }

  QVector<Conversational::Observation> extract (
    QString const& text, QString const& mode = QString ())
  {
    return Conversational::CallsignReporter::extractObservations (
      text, 500.0f, 20, baseTime (), QString (), mode);
  }

  QVector<Conversational::Report> process (
    Conversational::CallsignReporter& reporter, QString const& text,
    QString const& mode = QStringLiteral ("RTTY"), float frequency = 500.0f,
    int snr = 20, int seconds = 0, QString const& myCall = QString (),
    bool complete = true)
  {
    return reporter.process (mode, message (text, frequency, snr, seconds, complete), myCall);
  }
}

void testValidation ()
{
  for (auto const& call : QStringList {
         QStringLiteral ("K8S"), QStringLiteral ("N0CALL"), QStringLiteral ("K6XX"),
         QStringLiteral ("WA4YA"), QStringLiteral ("AI5DD"), QStringLiteral ("JO2QOT"),
         QStringLiteral ("DP7S"), QStringLiteral ("9A1A"), QStringLiteral ("2E0ABC"),
         QStringLiteral ("3D2ABC"), QStringLiteral ("A45AA"), QStringLiteral ("4X4AA"),
         QStringLiteral ("VP2E"), QStringLiteral ("P29XX"), QStringLiteral ("DP75HSC"),
         QStringLiteral ("DP75HSIN"), QStringLiteral ("LP75HSC")}) {
    check (Conversational::CallsignReporter::isValidCallsign (call),
           QStringLiteral ("valid callsign rejected: ") + call);
  }

  for (auto const& call : QStringList {
         QStringLiteral ("EA8"), QStringLiteral ("599"), QStringLiteral ("5NN"),
         QStringLiteral ("57N"), QStringLiteral ("HSC"), QStringLiteral ("CMT"),
         QStringLiteral ("TU"), QStringLiteral ("73"), QStringLiteral ("CQ"),
         QStringLiteral ("QRZ"), QStringLiteral ("DE"), QStringLiteral ("K"),
         QStringLiteral ("R"), QStringLiteral ("1A")}) {
    check (!Conversational::CallsignReporter::isValidCallsign (call),
           QStringLiteral ("invalid callsign accepted: ") + call);
  }

  QString base;
  check (Conversational::CallsignReporter::isValidCallsign (QStringLiteral ("W1AW/P"), &base)
         && base == QLatin1String ("W1AW"), QStringLiteral ("W1AW/P base"));
  check (Conversational::CallsignReporter::isValidCallsign (QStringLiteral ("EA8/K1ABC"), &base)
         && base == QLatin1String ("K1ABC"), QStringLiteral ("EA8/K1ABC base"));
  check (Conversational::CallsignReporter::isValidCallsign (QStringLiteral ("K1ABC/QRP"), &base)
         && base == QLatin1String ("K1ABC"), QStringLiteral ("K1ABC/QRP base"));
  check (Conversational::CallsignReporter::isValidCallsign (QStringLiteral ("K8S/QRP"), &base)
         && base == QLatin1String ("K8S"), QStringLiteral ("K8S/QRP base"));
}

void testGrid ()
{
  check (Conversational::CallsignReporter::isValidGrid (QStringLiteral ("FN42")),
         QStringLiteral ("FN42 grid"));
  check (Conversational::CallsignReporter::isValidGrid (QStringLiteral ("DP75HS")),
         QStringLiteral ("DP75HS grid"));
  check (!Conversational::CallsignReporter::isValidGrid (QStringLiteral ("DP75HSC")),
         QStringLiteral ("DP75HSC is not a grid"));
  check (!Conversational::CallsignReporter::isValidGrid (QStringLiteral ("DP75HSIN")),
         QStringLiteral ("DP75HSIN is not a grid"));
  check (!Conversational::CallsignReporter::isValidGrid (QStringLiteral ("RR73")),
         QStringLiteral ("RR73 is not a grid"));
}

void testExtraction ()
{
  auto observations = extract (QStringLiteral ("CQ WA4YA"));
  check (observations.size () == 1, QStringLiteral ("CQ WA4YA count"));
  if (observations.size () == 1) {
    check (observations[0].raw == QLatin1String ("WA4YA"), QStringLiteral ("CQ WA4YA call"));
    check (observations[0].cqContext, QStringLiteral ("CQ WA4YA context"));
  }

  observations = extract (QStringLiteral ("CQ DX K8S"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("K8S"),
         QStringLiteral ("CQ DX K8S"));

  observations = extract (QStringLiteral ("CQ EA8/K1ABC"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("EA8/K1ABC")
         && observations[0].base == QLatin1String ("K1ABC"),
         QStringLiteral ("compound CQ call"));

  observations = extract (QStringLiteral ("CQ CQ DE N0CALL"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("N0CALL"),
         QStringLiteral ("CQ CQ DE N0CALL"));

  observations = extract (QStringLiteral ("WA4YA DE AI5DD"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("AI5DD")
         && observations[0].deContext && !observations[0].cqContext,
         QStringLiteral ("directed DE call"));

  observations = extract (QStringLiteral ("QRZ DE K1ABC"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("K1ABC"),
         QStringLiteral ("QRZ DE call"));

  observations = extract (QStringLiteral ("CQ 9A1A"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("9A1A"),
         QStringLiteral ("prefix digit 9A1A"));

  observations = extract (QStringLiteral ("CQ 2E0ABC"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("2E0ABC"),
         QStringLiteral ("prefix digit 2E0ABC"));

  observations = extract (QStringLiteral ("CQ A45AA"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("A45AA"),
         QStringLiteral ("prefix digit A45AA"));

  observations = extract (QStringLiteral ("CQ 4X4AA"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("4X4AA"),
         QStringLiteral ("prefix digit 4X4AA"));

  observations = extract (QStringLiteral ("CQ DP75HSC FN42"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("DP75HSC")
         && observations[0].twoDigit && observations[0].cannotBeGrid
         && observations[0].grid == QLatin1String ("FN42"),
         QStringLiteral ("two-digit special-event call"));

  observations = extract (QStringLiteral ("CQ DP75HS"));
  check (observations.size () == 1 && observations[0].twoDigit
         && !observations[0].cannotBeGrid,
         QStringLiteral ("ambiguous call/grid token"));

  observations = extract (QStringLiteral ("WA4YA DE AI5DD"));
  check (observations.size () == 1 && observations[0].raw != QLatin1String ("WA4YA"),
         QStringLiteral ("do not report the addressee"));

  observations = extract (QStringLiteral ("CQ K1ABC"), QStringLiteral ("JTTY"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("K1ABC"),
         QStringLiteral ("JTTY structured CQ"));

  observations = extract (QStringLiteral ("CQ K1ABC FN42"), QStringLiteral ("JTTY"));
  check (observations.size () == 1 && observations[0].grid == QLatin1String ("FN42"),
         QStringLiteral ("JTTY structured grid"));

  observations = extract (QStringLiteral ("K1ABC W1AW FN42"), QStringLiteral ("JTTY"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("W1AW"),
         QStringLiteral ("JTTY structured sender"));

  observations = extract (QStringLiteral ("WA4YA DE AI5DD"), QStringLiteral ("JTTY"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("AI5DD"),
         QStringLiteral ("JTTY directed DE fallback"));

  observations = extract (QStringLiteral ("CQ DP75HSC FN42"), QStringLiteral ("JTTY"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("DP75HSC"),
         QStringLiteral ("JTTY two-digit call"));

  observations = extract (QStringLiteral ("CQ EA8/K1ABC"), QStringLiteral ("JTTY"));
  check (observations.size () == 1 && observations[0].raw == QLatin1String ("EA8/K1ABC"),
         QStringLiteral ("JTTY compound call"));
}

void testReporting ()
{
  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ WA4YA"));
    check (reports.size () == 1 && reports[0].call == QLatin1String ("WA4YA"),
           QStringLiteral ("report CQ WA4YA"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("WA4YA DE AI5DD"));
    check (reports.size () == 1 && reports[0].call == QLatin1String ("AI5DD"),
           QStringLiteral ("report directed DE"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ DP75HSC FN42"));
    check (reports.size () == 1 && reports[0].call == QLatin1String ("DP75HSC")
           && reports[0].udpMessageText () == QLatin1String ("CQ DP75HSC FN42"),
           QStringLiteral ("report two-digit call and UDP text"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ EA8/K1ABC"));
    check (reports.size () == 1 && reports[0].call == QLatin1String ("EA8/K1ABC")
           && reports[0].udpMessageText () == QLatin1String ("CQ EA8/K1ABC"),
           QStringLiteral ("report compound call and UDP text"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ DP75HS"));
    check (reports.isEmpty (), QStringLiteral ("ambiguous grid single-shot blocked"));
    reports = process (reporter, QStringLiteral ("CQ DP75HS"), QStringLiteral ("RTTY"),
                       500.0f, 20, 1);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("DP75HS"),
           QStringLiteral ("ambiguous grid reported after aggregation"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ WA4Y"));
    check (reports.isEmpty (), QStringLiteral ("truncation single-shot blocked"));
    process (reporter, QStringLiteral ("CQ WA4Y"), QStringLiteral ("RTTY"),
             500.0f, 20, 1);
    reports = process (reporter, QStringLiteral ("CQ WA4Y"), QStringLiteral ("RTTY"),
                       500.0f, 20, 2);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("WA4Y"),
           QStringLiteral ("truncation reported after three observations"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("K CQ BISU DE W1AW/4 W1AW/4"),
                            QStringLiteral ("CW"), 1213.0f, 0, 0);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("W1AW/4")
           && reports[0].udpMessageText () == QLatin1String ("CQ W1AW/4"),
           QStringLiteral ("repeated CQ DE call reports below SNR gate"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ WA4YA"),
                            QStringLiteral ("RTTY"), 500.0f, 2, 0);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("WA4YA"),
           QStringLiteral ("2 dB single-shot threshold"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ WA4YA"),
                            QStringLiteral ("RTTY"), 500.0f, 1, 0);
    check (reports.isEmpty (), QStringLiteral ("below 2 dB waits for aggregation"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ W1AW/4"),
                            QStringLiteral ("RTTY"), 500.0f, 0, 0);
    check (reports.isEmpty (), QStringLiteral ("single low-SNR CQ waits"));
    reports = process (reporter, QStringLiteral ("TU W1AW/4 W9APN"),
                       QStringLiteral ("RTTY"), 500.0f, 0, 1);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("W1AW/4"),
           QStringLiteral ("bare occurrence corroborates across message boundary"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("TU W1AW/4 W9APN"),
                            QStringLiteral ("RTTY"), 500.0f, 20, 0);
    check (reports.isEmpty (), QStringLiteral ("bare call alone is not spotted"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ WA4Y WA4Y WA4Y"),
                            QStringLiteral ("RTTY"), 500.0f, 20, 0);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("WA4Y"),
           QStringLiteral ("within-message occurrences count as support"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ WA4YA"),
                            QStringLiteral ("RTTY"), 500.0f, 0, 0);
    check (reports.isEmpty (), QStringLiteral ("low SNR waits for aggregation"));
    process (reporter, QStringLiteral ("CQ WA4YAD"), QStringLiteral ("RTTY"),
             500.0f, 0, 1);
    process (reporter, QStringLiteral ("CQ WA4Y"), QStringLiteral ("RTTY"),
             500.0f, 0, 2);
    reports = process (reporter, QStringLiteral ("CQ WA4YA"), QStringLiteral ("RTTY"),
                       500.0f, 0, 3);
    check (!reports.isEmpty () && reports.last ().call == QLatin1String ("WA4YA"),
           QStringLiteral ("medoid representative"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ K1ABC"),
                            QStringLiteral ("RTTY"), 500.0f, 20, 0,
                            QStringLiteral ("K1ABC"));
    check (reports.isEmpty (), QStringLiteral ("self call rejected"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ K1ABC FN42"),
                            QStringLiteral ("JTTY"), 500.0f, 0);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("K1ABC")
           && reports[0].grid == QLatin1String ("FN42"),
           QStringLiteral ("JTTY complete line reports immediately"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ DP75HSC FN42"),
                            QStringLiteral ("JTTY"), 500.0f, 0);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("DP75HSC"),
           QStringLiteral ("JTTY two-digit special call reports immediately"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ EA8/K1ABC"),
                            QStringLiteral ("JTTY"), 500.0f, 0);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("EA8/K1ABC"),
           QStringLiteral ("JTTY compound call reports immediately"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("WA4YA DE AI5DD"),
                            QStringLiteral ("JTTY"), 500.0f, 0);
    check (reports.size () == 1 && reports[0].call == QLatin1String ("AI5DD"),
           QStringLiteral ("JTTY directed DE call reports immediately"));
  }

  {
    Conversational::CallsignReporter reporter;
    for (int index = 0; index < 3; ++index) {
      process (reporter, QStringLiteral ("CQ WA4Y"), QStringLiteral ("RTTY"),
               500.0f, 20, index);
    }
    auto reports = process (reporter, QStringLiteral ("CQ WA4Y"), QStringLiteral ("RTTY"),
                            600.0f, 20, 3);
    check (reports.isEmpty (), QStringLiteral ("frequency track separation"));
  }

  {
    Conversational::CallsignReporter reporter;
    auto reports = process (reporter, QStringLiteral ("CQ WA4YA"),
                            QStringLiteral ("RTTY"), 500.0f, 20, 0, QString (),
                            false);
    check (reports.isEmpty (), QStringLiteral ("incomplete message ignored"));
  }
}

int main ()
{
  testValidation ();
  testGrid ();
  testExtraction ();
  testReporting ();

  if (failures) {
    std::cerr << "test_callsign_reporter: " << failures << " checks failed\n";
    return 1;
  }
  std::cout << "test_callsign_reporter: all checks passed\n";
  return 0;
}
