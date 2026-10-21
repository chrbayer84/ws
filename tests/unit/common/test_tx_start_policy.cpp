#include "TxStartPolicy.hpp"
#include <QtTest>

class TestTxStartPolicy : public QObject
{
  Q_OBJECT

private slots:
  void standardMessageModesRequireText ()
  {
    QVERIFY (requires_standard_tx_message ("FT8"));
    QVERIFY (requires_standard_tx_message ("FT4"));
    QVERIFY (requires_standard_tx_message ("JT9"));
    QVERIFY (requires_standard_tx_message ("JT65"));
    QVERIFY (requires_standard_tx_message ("Q65"));
    QVERIFY (requires_standard_tx_message ("MSK144"));
    QVERIFY (!requires_standard_tx_message ("Echo"));
    QVERIFY (!requires_standard_tx_message ("WSPR"));
    QVERIFY (!requires_standard_tx_message ("FST4W"));
    QVERIFY (!requires_standard_tx_message ("JTTY"));
    QVERIFY (!requires_standard_tx_message ("RTTY"));
  }

  void generatedPayloadModesDoNotRequireText ()
  {
    QVERIFY (!requires_standard_tx_message ("Echo"));
    QVERIFY (!requires_standard_tx_message ("WSPR"));
    QVERIFY (!requires_standard_tx_message ("FST4W"));
    QVERIFY (!requires_standard_tx_message ("JTTY"));
    QVERIFY (!requires_standard_tx_message ("RTTY"));
  }

  void unknownModesDefaultToStandardMessages ()
  {
    QVERIFY (requires_standard_tx_message ("UNKNOWN_MODE"));
  }

  void missingPayloadStopsOnlyStandardMessageModes ()
  {
    QVERIFY (should_stop_for_missing_tx_payload ("FT8", 0, false));
    QVERIFY (!should_stop_for_missing_tx_payload ("FT8", 1, false));
    QVERIFY (!should_stop_for_missing_tx_payload ("Echo", 0, false));
    QVERIFY (!should_stop_for_missing_tx_payload ("WSPR", 0, false));
    QVERIFY (!should_stop_for_missing_tx_payload ("FST4W", 0, false));
    QVERIFY (!should_stop_for_missing_tx_payload ("JTTY", 0, false));
    QVERIFY (!should_stop_for_missing_tx_payload ("RTTY", 0, false));
    QVERIFY (!should_stop_for_missing_tx_payload ("FT8", 0, true));
  }

  void canStartTransmitRequiresPayloadAndOpenWindow ()
  {
    QVERIFY (!can_start_transmit ("FT8", true, 0.5, 0, false));
    QVERIFY (can_start_transmit ("FT8", true, 0.5, 1, false));
    QVERIFY (!can_start_transmit ("FT8", true, 0.75, 1, false));
    QVERIFY (!can_start_transmit ("FT8", false, 0.5, 1, false));

    QVERIFY (can_start_transmit ("Echo", true, 0.5, 0, false));
    QVERIFY (!can_start_transmit ("Echo", false, 0.5, 0, false));
    QVERIFY (can_start_transmit ("WSPR", true, 0.5, 0, false));
    QVERIFY (can_start_transmit ("FST4W", true, 0.5, 0, false));

    QVERIFY (can_start_transmit ("JTTY", false, 0.95, 0, false));
    QVERIFY (can_start_transmit ("RTTY", false, 0.95, 0, false));
  }

  void generatedPayloadModesRespectStartWindow ()
  {
    QVERIFY (can_start_transmit ("Echo", true, 0.5, 0, false));
    QVERIFY (!can_start_transmit ("Echo", true, TxStartLatestPeriodFraction, 0, false));
    QVERIFY (!can_start_transmit ("Echo", true, 0.8, 0, false));
    QVERIFY (!can_start_transmit ("WSPR", true, TxStartLatestPeriodFraction, 0, false));
    QVERIFY (!can_start_transmit ("FST4W", true, 0.8, 0, false));
    QVERIFY (can_start_transmit ("JTTY", false, 0.95, 0, false));
    QVERIFY (can_start_transmit ("RTTY", false, 0.95, 0, false));
  }

  void tuningCanStartWithoutPayload ()
  {
    QVERIFY (can_start_transmit ("FT8", false, 0.95, 0, true));
  }

  void rejectedGeneratedMessageBlocksTransmit ()
  {
    QVERIFY (should_block_generated_transmit ("*** bad message ***", false));
    QVERIFY (should_block_generated_transmit (
      QStringLiteral ("*** bad message ***").leftJustified (37, ' '), false));

    QVERIFY (!should_block_generated_transmit ("*** bad message ***", true));
    QVERIFY (!should_block_generated_transmit ("TUNE", false));
    QVERIFY (!should_block_generated_transmit ("ECHO", false));
    QVERIFY (!should_block_generated_transmit (
      QStringLiteral ("K1ABC W9XYZ R-10").leftJustified (22, ' '), false));
    QVERIFY (!should_block_generated_transmit (
      QStringLiteral ("CQ K1ABC FN42").leftJustified (37, ' '), false));
  }
};

QTEST_MAIN (TestTxStartPolicy)

#include "test_tx_start_policy.moc"
