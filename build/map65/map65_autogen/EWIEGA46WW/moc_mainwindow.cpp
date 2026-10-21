/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../map65/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[130];
    char stringdata0[2995];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "showSoundInError"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "errorMsg"
QT_MOC_LITERAL(4, 38, 17), // "showStatusMessage"
QT_MOC_LITERAL(5, 56, 9), // "statusMsg"
QT_MOC_LITERAL(6, 66, 8), // "dataSink"
QT_MOC_LITERAL(7, 75, 1), // "k"
QT_MOC_LITERAL(8, 77, 7), // "diskDat"
QT_MOC_LITERAL(9, 85, 16), // "disarmPastPeriod"
QT_MOC_LITERAL(10, 102, 16), // "decodePastPeriod"
QT_MOC_LITERAL(11, 119, 17), // "diskWriteFinished"
QT_MOC_LITERAL(12, 137, 12), // "freezeDecode"
QT_MOC_LITERAL(13, 150, 1), // "n"
QT_MOC_LITERAL(14, 152, 12), // "editor_error"
QT_MOC_LITERAL(15, 165, 9), // "guiUpdate"
QT_MOC_LITERAL(16, 175, 17), // "doubleClickOnCall"
QT_MOC_LITERAL(17, 193, 7), // "rawLine"
QT_MOC_LITERAL(18, 201, 4), // "ctrl"
QT_MOC_LITERAL(19, 206, 13), // "isDoubleClick"
QT_MOC_LITERAL(20, 220, 21), // "doubleClickOnMessages"
QT_MOC_LITERAL(21, 242, 2), // "t2"
QT_MOC_LITERAL(22, 245, 19), // "handleCallsignClick"
QT_MOC_LITERAL(23, 265, 4), // "call"
QT_MOC_LITERAL(24, 270, 8), // "freq_khz"
QT_MOC_LITERAL(25, 279, 7), // "is_jt65"
QT_MOC_LITERAL(26, 287, 4), // "grid"
QT_MOC_LITERAL(27, 292, 9), // "start_qso"
QT_MOC_LITERAL(28, 302, 26), // "handleBandMapCallsignClick"
QT_MOC_LITERAL(29, 329, 12), // "startDecoder"
QT_MOC_LITERAL(30, 342, 20), // "onDiskDecodeFinished"
QT_MOC_LITERAL(31, 363, 43), // "on_actionPast_periods_on_Wide..."
QT_MOC_LITERAL(32, 407, 1), // "b"
QT_MOC_LITERAL(33, 409, 19), // "onPastPeriodClicked"
QT_MOC_LITERAL(34, 429, 3), // "tag"
QT_MOC_LITERAL(35, 433, 16), // "onRunM65Finished"
QT_MOC_LITERAL(36, 450, 22), // "on_tx1_editingFinished"
QT_MOC_LITERAL(37, 473, 22), // "on_tx2_editingFinished"
QT_MOC_LITERAL(38, 496, 22), // "on_tx3_editingFinished"
QT_MOC_LITERAL(39, 519, 22), // "on_tx4_editingFinished"
QT_MOC_LITERAL(40, 542, 22), // "on_tx5_editingFinished"
QT_MOC_LITERAL(41, 565, 22), // "on_tx6_editingFinished"
QT_MOC_LITERAL(42, 588, 30), // "on_actionDeviceSetup_triggered"
QT_MOC_LITERAL(43, 619, 24), // "on_monitorButton_clicked"
QT_MOC_LITERAL(44, 644, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(45, 668, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(46, 693, 25), // "on_actionLinrad_triggered"
QT_MOC_LITERAL(47, 719, 26), // "on_actionCuteSDR_triggered"
QT_MOC_LITERAL(48, 746, 21), // "on_autoButton_clicked"
QT_MOC_LITERAL(49, 768, 23), // "on_stopTxButton_clicked"
QT_MOC_LITERAL(50, 792, 26), // "on_tolSpinBox_valueChanged"
QT_MOC_LITERAL(51, 819, 4), // "arg1"
QT_MOC_LITERAL(52, 824, 29), // "on_actionAstro_Data_triggered"
QT_MOC_LITERAL(53, 854, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(54, 876, 32), // "on_actionRelease_Notes_triggered"
QT_MOC_LITERAL(55, 909, 37), // "on_actionOnline_Users_Guide_t..."
QT_MOC_LITERAL(56, 947, 26), // "on_actionQSG_Q65_triggered"
QT_MOC_LITERAL(57, 974, 31), // "on_actionQSG_MAP65_v3_triggered"
QT_MOC_LITERAL(58, 1006, 47), // "on_actionQ65_Sensitivity_in_M..."
QT_MOC_LITERAL(59, 1054, 33), // "on_actionWide_Waterfall_trigg..."
QT_MOC_LITERAL(60, 1088, 27), // "on_actionBand_Map_triggered"
QT_MOC_LITERAL(61, 1116, 27), // "on_actionMessages_triggered"
QT_MOC_LITERAL(62, 1144, 44), // "on_actionOpen_MAP65_data_dire..."
QT_MOC_LITERAL(63, 1189, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(64, 1213, 41), // "on_actionOpen_next_in_directo..."
QT_MOC_LITERAL(65, 1255, 54), // "on_actionDecode_remaining_fil..."
QT_MOC_LITERAL(66, 1310, 50), // "on_actionDelete_all_tf2_files..."
QT_MOC_LITERAL(67, 1361, 46), // "on_actionErase_Band_Map_and_M..."
QT_MOC_LITERAL(68, 1408, 33), // "on_actionFind_Delta_Phi_trigg..."
QT_MOC_LITERAL(69, 1442, 30), // "on_actionF4_sets_Tx6_triggered"
QT_MOC_LITERAL(70, 1473, 33), // "on_actionOnly_EME_calls_trigg..."
QT_MOC_LITERAL(71, 1507, 39), // "on_actionNo_shorthands_if_Tx1..."
QT_MOC_LITERAL(72, 1547, 33), // "on_actionNo_Deep_Search_trigg..."
QT_MOC_LITERAL(73, 1581, 37), // "on_actionNormal_Deep_Search_t..."
QT_MOC_LITERAL(74, 1619, 41), // "on_actionAggressive_Deep_Sear..."
QT_MOC_LITERAL(75, 1661, 27), // "on_actionQ65_Fast_triggered"
QT_MOC_LITERAL(76, 1689, 29), // "on_actionQ65_Normal_triggered"
QT_MOC_LITERAL(77, 1719, 27), // "on_actionQ65_Deep_triggered"
QT_MOC_LITERAL(78, 1747, 23), // "on_actionNone_triggered"
QT_MOC_LITERAL(79, 1771, 27), // "on_actionSave_all_triggered"
QT_MOC_LITERAL(80, 1799, 37), // "on_actionKeyboard_shortcuts_t..."
QT_MOC_LITERAL(81, 1837, 41), // "on_actionSpecial_mouse_comman..."
QT_MOC_LITERAL(82, 1879, 57), // "on_actionAvailable_suffixes_a..."
QT_MOC_LITERAL(83, 1937, 23), // "on_DecodeButton_clicked"
QT_MOC_LITERAL(84, 1961, 6), // "decode"
QT_MOC_LITERAL(85, 1968, 10), // "decodeBusy"
QT_MOC_LITERAL(86, 1979, 22), // "on_EraseButton_clicked"
QT_MOC_LITERAL(87, 2002, 15), // "on_txb1_clicked"
QT_MOC_LITERAL(88, 2018, 31), // "on_txFirstCheckBox_stateChanged"
QT_MOC_LITERAL(89, 2050, 7), // "set_ntx"
QT_MOC_LITERAL(90, 2058, 15), // "on_txb2_clicked"
QT_MOC_LITERAL(91, 2074, 15), // "on_txb3_clicked"
QT_MOC_LITERAL(92, 2090, 15), // "on_txb4_clicked"
QT_MOC_LITERAL(93, 2106, 15), // "on_txb5_clicked"
QT_MOC_LITERAL(94, 2122, 15), // "on_txb6_clicked"
QT_MOC_LITERAL(95, 2138, 23), // "on_lookupButton_clicked"
QT_MOC_LITERAL(96, 2162, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(97, 2183, 26), // "on_setTxFreqButton_clicked"
QT_MOC_LITERAL(98, 2210, 26), // "on_dxCallEntry_textChanged"
QT_MOC_LITERAL(99, 2237, 26), // "on_dxGridEntry_textChanged"
QT_MOC_LITERAL(100, 2264, 11), // "selectCall2"
QT_MOC_LITERAL(101, 2276, 31), // "on_genStdMsgsPushButton_clicked"
QT_MOC_LITERAL(102, 2308, 6), // "bumpDF"
QT_MOC_LITERAL(103, 2315, 23), // "on_logQSOButton_clicked"
QT_MOC_LITERAL(104, 2339, 37), // "on_actionErase_map65_rx_log_t..."
QT_MOC_LITERAL(105, 2377, 37), // "on_actionErase_map65_tx_log_t..."
QT_MOC_LITERAL(106, 2415, 21), // "on_NBcheckBox_toggled"
QT_MOC_LITERAL(107, 2437, 7), // "checked"
QT_MOC_LITERAL(108, 2445, 24), // "on_actionJT65A_triggered"
QT_MOC_LITERAL(109, 2470, 24), // "on_actionJT65B_triggered"
QT_MOC_LITERAL(110, 2495, 24), // "on_actionJT65C_triggered"
QT_MOC_LITERAL(111, 2520, 24), // "on_NBslider_valueChanged"
QT_MOC_LITERAL(112, 2545, 5), // "value"
QT_MOC_LITERAL(113, 2551, 40), // "on_actionAdjust_IQ_Calibratio..."
QT_MOC_LITERAL(114, 2592, 39), // "on_actionApply_IQ_Calibration..."
QT_MOC_LITERAL(115, 2632, 25), // "on_actionAFMHot_triggered"
QT_MOC_LITERAL(116, 2658, 23), // "on_actionBlue_triggered"
QT_MOC_LITERAL(117, 2682, 33), // "on_actionFUNcube_Dongle_trigg..."
QT_MOC_LITERAL(118, 2716, 32), // "on_actionEdit_wsjt_log_triggered"
QT_MOC_LITERAL(119, 2749, 26), // "on_actionTx_Tune_triggered"
QT_MOC_LITERAL(120, 2776, 23), // "on_actionQ65A_triggered"
QT_MOC_LITERAL(121, 2800, 23), // "on_actionQ65B_triggered"
QT_MOC_LITERAL(122, 2824, 25), // "on_actionNoJT65_triggered"
QT_MOC_LITERAL(123, 2850, 24), // "on_actionNoQ65_triggered"
QT_MOC_LITERAL(124, 2875, 23), // "on_actionQ65C_triggered"
QT_MOC_LITERAL(125, 2899, 23), // "on_actionQ65D_triggered"
QT_MOC_LITERAL(126, 2923, 23), // "on_actionQ65E_triggered"
QT_MOC_LITERAL(127, 2947, 19), // "on_pbTxMode_clicked"
QT_MOC_LITERAL(128, 2967, 19), // "onSampleRateChanged"
QT_MOC_LITERAL(129, 2987, 7) // "newRate"

    },
    "MainWindow\0showSoundInError\0\0errorMsg\0"
    "showStatusMessage\0statusMsg\0dataSink\0"
    "k\0diskDat\0disarmPastPeriod\0decodePastPeriod\0"
    "diskWriteFinished\0freezeDecode\0n\0"
    "editor_error\0guiUpdate\0doubleClickOnCall\0"
    "rawLine\0ctrl\0isDoubleClick\0"
    "doubleClickOnMessages\0t2\0handleCallsignClick\0"
    "call\0freq_khz\0is_jt65\0grid\0start_qso\0"
    "handleBandMapCallsignClick\0startDecoder\0"
    "onDiskDecodeFinished\0"
    "on_actionPast_periods_on_Wide_Graph_toggled\0"
    "b\0onPastPeriodClicked\0tag\0onRunM65Finished\0"
    "on_tx1_editingFinished\0on_tx2_editingFinished\0"
    "on_tx3_editingFinished\0on_tx4_editingFinished\0"
    "on_tx5_editingFinished\0on_tx6_editingFinished\0"
    "on_actionDeviceSetup_triggered\0"
    "on_monitorButton_clicked\0"
    "on_actionExit_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionLinrad_triggered\0"
    "on_actionCuteSDR_triggered\0"
    "on_autoButton_clicked\0on_stopTxButton_clicked\0"
    "on_tolSpinBox_valueChanged\0arg1\0"
    "on_actionAstro_Data_triggered\0"
    "on_stopButton_clicked\0"
    "on_actionRelease_Notes_triggered\0"
    "on_actionOnline_Users_Guide_triggered\0"
    "on_actionQSG_Q65_triggered\0"
    "on_actionQSG_MAP65_v3_triggered\0"
    "on_actionQ65_Sensitivity_in_MAP65_3_0_triggered\0"
    "on_actionWide_Waterfall_triggered\0"
    "on_actionBand_Map_triggered\0"
    "on_actionMessages_triggered\0"
    "on_actionOpen_MAP65_data_directory_triggered\0"
    "on_actionOpen_triggered\0"
    "on_actionOpen_next_in_directory_triggered\0"
    "on_actionDecode_remaining_files_in_directory_triggered\0"
    "on_actionDelete_all_tf2_files_in_SaveDir_triggered\0"
    "on_actionErase_Band_Map_and_Messages_triggered\0"
    "on_actionFind_Delta_Phi_triggered\0"
    "on_actionF4_sets_Tx6_triggered\0"
    "on_actionOnly_EME_calls_triggered\0"
    "on_actionNo_shorthands_if_Tx1_triggered\0"
    "on_actionNo_Deep_Search_triggered\0"
    "on_actionNormal_Deep_Search_triggered\0"
    "on_actionAggressive_Deep_Search_triggered\0"
    "on_actionQ65_Fast_triggered\0"
    "on_actionQ65_Normal_triggered\0"
    "on_actionQ65_Deep_triggered\0"
    "on_actionNone_triggered\0"
    "on_actionSave_all_triggered\0"
    "on_actionKeyboard_shortcuts_triggered\0"
    "on_actionSpecial_mouse_commands_triggered\0"
    "on_actionAvailable_suffixes_and_add_on_prefixes_triggered\0"
    "on_DecodeButton_clicked\0decode\0"
    "decodeBusy\0on_EraseButton_clicked\0"
    "on_txb1_clicked\0on_txFirstCheckBox_stateChanged\0"
    "set_ntx\0on_txb2_clicked\0on_txb3_clicked\0"
    "on_txb4_clicked\0on_txb5_clicked\0"
    "on_txb6_clicked\0on_lookupButton_clicked\0"
    "on_addButton_clicked\0on_setTxFreqButton_clicked\0"
    "on_dxCallEntry_textChanged\0"
    "on_dxGridEntry_textChanged\0selectCall2\0"
    "on_genStdMsgsPushButton_clicked\0bumpDF\0"
    "on_logQSOButton_clicked\0"
    "on_actionErase_map65_rx_log_triggered\0"
    "on_actionErase_map65_tx_log_triggered\0"
    "on_NBcheckBox_toggled\0checked\0"
    "on_actionJT65A_triggered\0"
    "on_actionJT65B_triggered\0"
    "on_actionJT65C_triggered\0"
    "on_NBslider_valueChanged\0value\0"
    "on_actionAdjust_IQ_Calibration_triggered\0"
    "on_actionApply_IQ_Calibration_triggered\0"
    "on_actionAFMHot_triggered\0"
    "on_actionBlue_triggered\0"
    "on_actionFUNcube_Dongle_triggered\0"
    "on_actionEdit_wsjt_log_triggered\0"
    "on_actionTx_Tune_triggered\0"
    "on_actionQ65A_triggered\0on_actionQ65B_triggered\0"
    "on_actionNoJT65_triggered\0"
    "on_actionNoQ65_triggered\0"
    "on_actionQ65C_triggered\0on_actionQ65D_triggered\0"
    "on_actionQ65E_triggered\0on_pbTxMode_clicked\0"
    "onSampleRateChanged\0newRate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     109,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  559,    2, 0x0a /* Public */,
       4,    1,  562,    2, 0x0a /* Public */,
       6,    1,  565,    2, 0x0a /* Public */,
       8,    0,  568,    2, 0x0a /* Public */,
       9,    0,  569,    2, 0x0a /* Public */,
      10,    0,  570,    2, 0x0a /* Public */,
      11,    0,  571,    2, 0x0a /* Public */,
      12,    1,  572,    2, 0x0a /* Public */,
      14,    0,  575,    2, 0x0a /* Public */,
      15,    0,  576,    2, 0x0a /* Public */,
      16,    3,  577,    2, 0x0a /* Public */,
      20,    3,  584,    2, 0x0a /* Public */,
      22,    5,  591,    2, 0x0a /* Public */,
      28,    2,  602,    2, 0x0a /* Public */,
      29,    0,  607,    2, 0x0a /* Public */,
      30,    0,  608,    2, 0x08 /* Private */,
      31,    1,  609,    2, 0x08 /* Private */,
      33,    1,  612,    2, 0x08 /* Private */,
      35,    0,  615,    2, 0x08 /* Private */,
      36,    0,  616,    2, 0x08 /* Private */,
      37,    0,  617,    2, 0x08 /* Private */,
      38,    0,  618,    2, 0x08 /* Private */,
      39,    0,  619,    2, 0x08 /* Private */,
      40,    0,  620,    2, 0x08 /* Private */,
      41,    0,  621,    2, 0x08 /* Private */,
      42,    0,  622,    2, 0x08 /* Private */,
      43,    0,  623,    2, 0x08 /* Private */,
      44,    0,  624,    2, 0x08 /* Private */,
      45,    0,  625,    2, 0x08 /* Private */,
      46,    0,  626,    2, 0x08 /* Private */,
      47,    0,  627,    2, 0x08 /* Private */,
      48,    0,  628,    2, 0x08 /* Private */,
      49,    0,  629,    2, 0x08 /* Private */,
      50,    1,  630,    2, 0x08 /* Private */,
      52,    0,  633,    2, 0x08 /* Private */,
      53,    0,  634,    2, 0x08 /* Private */,
      54,    0,  635,    2, 0x08 /* Private */,
      55,    0,  636,    2, 0x08 /* Private */,
      56,    0,  637,    2, 0x08 /* Private */,
      57,    0,  638,    2, 0x08 /* Private */,
      58,    0,  639,    2, 0x08 /* Private */,
      59,    0,  640,    2, 0x08 /* Private */,
      60,    0,  641,    2, 0x08 /* Private */,
      61,    0,  642,    2, 0x08 /* Private */,
      62,    0,  643,    2, 0x08 /* Private */,
      63,    0,  644,    2, 0x08 /* Private */,
      64,    0,  645,    2, 0x08 /* Private */,
      65,    0,  646,    2, 0x08 /* Private */,
      66,    0,  647,    2, 0x08 /* Private */,
      67,    0,  648,    2, 0x08 /* Private */,
      68,    0,  649,    2, 0x08 /* Private */,
      69,    0,  650,    2, 0x08 /* Private */,
      70,    0,  651,    2, 0x08 /* Private */,
      71,    0,  652,    2, 0x08 /* Private */,
      72,    0,  653,    2, 0x08 /* Private */,
      73,    0,  654,    2, 0x08 /* Private */,
      74,    0,  655,    2, 0x08 /* Private */,
      75,    0,  656,    2, 0x08 /* Private */,
      76,    0,  657,    2, 0x08 /* Private */,
      77,    0,  658,    2, 0x08 /* Private */,
      78,    0,  659,    2, 0x08 /* Private */,
      79,    0,  660,    2, 0x08 /* Private */,
      80,    0,  661,    2, 0x08 /* Private */,
      81,    0,  662,    2, 0x08 /* Private */,
      82,    0,  663,    2, 0x08 /* Private */,
      83,    0,  664,    2, 0x08 /* Private */,
      84,    0,  665,    2, 0x08 /* Private */,
      85,    1,  666,    2, 0x08 /* Private */,
      86,    0,  669,    2, 0x08 /* Private */,
      87,    0,  670,    2, 0x08 /* Private */,
      88,    1,  671,    2, 0x08 /* Private */,
      89,    1,  674,    2, 0x08 /* Private */,
      90,    0,  677,    2, 0x08 /* Private */,
      91,    0,  678,    2, 0x08 /* Private */,
      92,    0,  679,    2, 0x08 /* Private */,
      93,    0,  680,    2, 0x08 /* Private */,
      94,    0,  681,    2, 0x08 /* Private */,
      95,    0,  682,    2, 0x08 /* Private */,
      96,    0,  683,    2, 0x08 /* Private */,
      97,    0,  684,    2, 0x08 /* Private */,
      98,    1,  685,    2, 0x08 /* Private */,
      99,    1,  688,    2, 0x08 /* Private */,
     100,    2,  691,    2, 0x08 /* Private */,
     101,    0,  696,    2, 0x08 /* Private */,
     102,    1,  697,    2, 0x08 /* Private */,
     103,    0,  700,    2, 0x08 /* Private */,
     104,    0,  701,    2, 0x08 /* Private */,
     105,    0,  702,    2, 0x08 /* Private */,
     106,    1,  703,    2, 0x08 /* Private */,
     108,    0,  706,    2, 0x08 /* Private */,
     109,    0,  707,    2, 0x08 /* Private */,
     110,    0,  708,    2, 0x08 /* Private */,
     111,    1,  709,    2, 0x08 /* Private */,
     113,    0,  712,    2, 0x08 /* Private */,
     114,    0,  713,    2, 0x08 /* Private */,
     115,    0,  714,    2, 0x08 /* Private */,
     116,    0,  715,    2, 0x08 /* Private */,
     117,    0,  716,    2, 0x08 /* Private */,
     118,    0,  717,    2, 0x08 /* Private */,
     119,    0,  718,    2, 0x08 /* Private */,
     120,    0,  719,    2, 0x08 /* Private */,
     121,    0,  720,    2, 0x08 /* Private */,
     122,    0,  721,    2, 0x08 /* Private */,
     123,    0,  722,    2, 0x08 /* Private */,
     124,    0,  723,    2, 0x08 /* Private */,
     125,    0,  724,    2, 0x08 /* Private */,
     126,    0,  725,    2, 0x08 /* Private */,
     127,    0,  726,    2, 0x08 /* Private */,
     128,    1,  727,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   21,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Double, QMetaType::Bool, QMetaType::QString, QMetaType::Bool,   23,   24,   25,   26,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   23,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  107,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  112,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  129,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showSoundInError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->showStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->dataSink((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->diskDat(); break;
        case 4: _t->disarmPastPeriod(); break;
        case 5: _t->decodePastPeriod(); break;
        case 6: _t->diskWriteFinished(); break;
        case 7: _t->freezeDecode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->editor_error(); break;
        case 9: _t->guiUpdate(); break;
        case 10: _t->doubleClickOnCall((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 11: _t->doubleClickOnMessages((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 12: _t->handleCallsignClick((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 13: _t->handleBandMapCallsignClick((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: _t->startDecoder(); break;
        case 15: _t->onDiskDecodeFinished(); break;
        case 16: _t->on_actionPast_periods_on_Wide_Graph_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->onPastPeriodClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->onRunM65Finished(); break;
        case 19: _t->on_tx1_editingFinished(); break;
        case 20: _t->on_tx2_editingFinished(); break;
        case 21: _t->on_tx3_editingFinished(); break;
        case 22: _t->on_tx4_editingFinished(); break;
        case 23: _t->on_tx5_editingFinished(); break;
        case 24: _t->on_tx6_editingFinished(); break;
        case 25: _t->on_actionDeviceSetup_triggered(); break;
        case 26: _t->on_monitorButton_clicked(); break;
        case 27: _t->on_actionExit_triggered(); break;
        case 28: _t->on_actionAbout_triggered(); break;
        case 29: _t->on_actionLinrad_triggered(); break;
        case 30: _t->on_actionCuteSDR_triggered(); break;
        case 31: _t->on_autoButton_clicked(); break;
        case 32: _t->on_stopTxButton_clicked(); break;
        case 33: _t->on_tolSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_actionAstro_Data_triggered(); break;
        case 35: _t->on_stopButton_clicked(); break;
        case 36: _t->on_actionRelease_Notes_triggered(); break;
        case 37: _t->on_actionOnline_Users_Guide_triggered(); break;
        case 38: _t->on_actionQSG_Q65_triggered(); break;
        case 39: _t->on_actionQSG_MAP65_v3_triggered(); break;
        case 40: _t->on_actionQ65_Sensitivity_in_MAP65_3_0_triggered(); break;
        case 41: _t->on_actionWide_Waterfall_triggered(); break;
        case 42: _t->on_actionBand_Map_triggered(); break;
        case 43: _t->on_actionMessages_triggered(); break;
        case 44: _t->on_actionOpen_MAP65_data_directory_triggered(); break;
        case 45: _t->on_actionOpen_triggered(); break;
        case 46: _t->on_actionOpen_next_in_directory_triggered(); break;
        case 47: _t->on_actionDecode_remaining_files_in_directory_triggered(); break;
        case 48: _t->on_actionDelete_all_tf2_files_in_SaveDir_triggered(); break;
        case 49: _t->on_actionErase_Band_Map_and_Messages_triggered(); break;
        case 50: _t->on_actionFind_Delta_Phi_triggered(); break;
        case 51: _t->on_actionF4_sets_Tx6_triggered(); break;
        case 52: _t->on_actionOnly_EME_calls_triggered(); break;
        case 53: _t->on_actionNo_shorthands_if_Tx1_triggered(); break;
        case 54: _t->on_actionNo_Deep_Search_triggered(); break;
        case 55: _t->on_actionNormal_Deep_Search_triggered(); break;
        case 56: _t->on_actionAggressive_Deep_Search_triggered(); break;
        case 57: _t->on_actionQ65_Fast_triggered(); break;
        case 58: _t->on_actionQ65_Normal_triggered(); break;
        case 59: _t->on_actionQ65_Deep_triggered(); break;
        case 60: _t->on_actionNone_triggered(); break;
        case 61: _t->on_actionSave_all_triggered(); break;
        case 62: _t->on_actionKeyboard_shortcuts_triggered(); break;
        case 63: _t->on_actionSpecial_mouse_commands_triggered(); break;
        case 64: _t->on_actionAvailable_suffixes_and_add_on_prefixes_triggered(); break;
        case 65: _t->on_DecodeButton_clicked(); break;
        case 66: _t->decode(); break;
        case 67: _t->decodeBusy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 68: _t->on_EraseButton_clicked(); break;
        case 69: _t->on_txb1_clicked(); break;
        case 70: _t->on_txFirstCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: _t->set_ntx((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 72: _t->on_txb2_clicked(); break;
        case 73: _t->on_txb3_clicked(); break;
        case 74: _t->on_txb4_clicked(); break;
        case 75: _t->on_txb5_clicked(); break;
        case 76: _t->on_txb6_clicked(); break;
        case 77: _t->on_lookupButton_clicked(); break;
        case 78: _t->on_addButton_clicked(); break;
        case 79: _t->on_setTxFreqButton_clicked(); break;
        case 80: _t->on_dxCallEntry_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 81: _t->on_dxGridEntry_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 82: _t->selectCall2((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 83: _t->on_genStdMsgsPushButton_clicked(); break;
        case 84: _t->bumpDF((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 85: _t->on_logQSOButton_clicked(); break;
        case 86: _t->on_actionErase_map65_rx_log_triggered(); break;
        case 87: _t->on_actionErase_map65_tx_log_triggered(); break;
        case 88: _t->on_NBcheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 89: _t->on_actionJT65A_triggered(); break;
        case 90: _t->on_actionJT65B_triggered(); break;
        case 91: _t->on_actionJT65C_triggered(); break;
        case 92: _t->on_NBslider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 93: _t->on_actionAdjust_IQ_Calibration_triggered(); break;
        case 94: _t->on_actionApply_IQ_Calibration_triggered(); break;
        case 95: _t->on_actionAFMHot_triggered(); break;
        case 96: _t->on_actionBlue_triggered(); break;
        case 97: _t->on_actionFUNcube_Dongle_triggered(); break;
        case 98: _t->on_actionEdit_wsjt_log_triggered(); break;
        case 99: _t->on_actionTx_Tune_triggered(); break;
        case 100: _t->on_actionQ65A_triggered(); break;
        case 101: _t->on_actionQ65B_triggered(); break;
        case 102: _t->on_actionNoJT65_triggered(); break;
        case 103: _t->on_actionNoQ65_triggered(); break;
        case 104: _t->on_actionQ65C_triggered(); break;
        case 105: _t->on_actionQ65D_triggered(); break;
        case 106: _t->on_actionQ65E_triggered(); break;
        case 107: _t->on_pbTxMode_clicked(); break;
        case 108: _t->onSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 109)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 109;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 109)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 109;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
