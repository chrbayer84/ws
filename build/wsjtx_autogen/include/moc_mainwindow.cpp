/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[465];
    char stringdata0[9557];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "initializeAudioOutputStream"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 16), // "QAudioDeviceInfo"
QT_MOC_LITERAL(4, 57, 8), // "channels"
QT_MOC_LITERAL(5, 66, 10), // "msBuffered"
QT_MOC_LITERAL(6, 77, 21), // "stopAudioOutputStream"
QT_MOC_LITERAL(7, 99, 21), // "startAudioInputStream"
QT_MOC_LITERAL(8, 121, 15), // "framesPerBuffer"
QT_MOC_LITERAL(9, 137, 12), // "AudioDevice*"
QT_MOC_LITERAL(10, 150, 4), // "sink"
QT_MOC_LITERAL(11, 155, 16), // "downSampleFactor"
QT_MOC_LITERAL(12, 172, 20), // "AudioDevice::Channel"
QT_MOC_LITERAL(13, 193, 23), // "suspendAudioInputStream"
QT_MOC_LITERAL(14, 217, 22), // "resumeAudioInputStream"
QT_MOC_LITERAL(15, 240, 13), // "startDetector"
QT_MOC_LITERAL(16, 254, 7), // "FFTSize"
QT_MOC_LITERAL(17, 262, 13), // "detectorClose"
QT_MOC_LITERAL(18, 276, 8), // "finished"
QT_MOC_LITERAL(19, 285, 17), // "transmitFrequency"
QT_MOC_LITERAL(20, 303, 18), // "endTransmitMessage"
QT_MOC_LITERAL(21, 322, 5), // "quick"
QT_MOC_LITERAL(22, 328, 4), // "tune"
QT_MOC_LITERAL(23, 333, 11), // "sendMessage"
QT_MOC_LITERAL(24, 345, 4), // "mode"
QT_MOC_LITERAL(25, 350, 13), // "symbolsLength"
QT_MOC_LITERAL(26, 364, 15), // "framesPerSymbol"
QT_MOC_LITERAL(27, 380, 9), // "frequency"
QT_MOC_LITERAL(28, 390, 11), // "toneSpacing"
QT_MOC_LITERAL(29, 402, 12), // "SoundOutput*"
QT_MOC_LITERAL(30, 415, 11), // "synchronize"
QT_MOC_LITERAL(31, 427, 8), // "fastMode"
QT_MOC_LITERAL(32, 436, 5), // "dBSNR"
QT_MOC_LITERAL(33, 442, 8), // "TRperiod"
QT_MOC_LITERAL(34, 451, 21), // "outAttenuationChanged"
QT_MOC_LITERAL(35, 473, 15), // "toggleShorthand"
QT_MOC_LITERAL(36, 489, 24), // "reset_audio_input_stream"
QT_MOC_LITERAL(37, 514, 21), // "report_dropped_frames"
QT_MOC_LITERAL(38, 536, 16), // "jttyTextAccepted"
QT_MOC_LITERAL(39, 553, 9), // "requestId"
QT_MOC_LITERAL(40, 563, 16), // "jttyTextRejected"
QT_MOC_LITERAL(41, 580, 18), // "JttyTxRejectReason"
QT_MOC_LITERAL(42, 599, 6), // "reason"
QT_MOC_LITERAL(43, 606, 17), // "jttyTextCompleted"
QT_MOC_LITERAL(44, 624, 18), // "jttySessionDrained"
QT_MOC_LITERAL(45, 643, 9), // "sessionId"
QT_MOC_LITERAL(46, 653, 15), // "startJttyStream"
QT_MOC_LITERAL(47, 669, 21), // "TxEvidence::TxRequest"
QT_MOC_LITERAL(48, 691, 13), // "endJttyStream"
QT_MOC_LITERAL(49, 705, 16), // "showSoundInError"
QT_MOC_LITERAL(50, 722, 8), // "errorMsg"
QT_MOC_LITERAL(51, 731, 17), // "showSoundOutError"
QT_MOC_LITERAL(52, 749, 17), // "showStatusMessage"
QT_MOC_LITERAL(53, 767, 9), // "statusMsg"
QT_MOC_LITERAL(54, 777, 8), // "dataSink"
QT_MOC_LITERAL(55, 786, 6), // "frames"
QT_MOC_LITERAL(56, 793, 8), // "fastSink"
QT_MOC_LITERAL(57, 802, 14), // "tci_mod_active"
QT_MOC_LITERAL(58, 817, 2), // "on"
QT_MOC_LITERAL(59, 820, 7), // "diskDat"
QT_MOC_LITERAL(60, 828, 12), // "freezeDecode"
QT_MOC_LITERAL(61, 841, 1), // "n"
QT_MOC_LITERAL(62, 843, 9), // "guiUpdate"
QT_MOC_LITERAL(63, 853, 17), // "doubleClickOnCall"
QT_MOC_LITERAL(64, 871, 21), // "Qt::KeyboardModifiers"
QT_MOC_LITERAL(65, 893, 18), // "doubleClickOnCall2"
QT_MOC_LITERAL(66, 912, 21), // "doubleClickOnFoxQueue"
QT_MOC_LITERAL(67, 934, 26), // "doubleClickOnFoxInProgress"
QT_MOC_LITERAL(68, 961, 9), // "modifiers"
QT_MOC_LITERAL(69, 971, 14), // "readFromStdout"
QT_MOC_LITERAL(70, 986, 16), // "p1ReadFromStdout"
QT_MOC_LITERAL(71, 1003, 6), // "setXIT"
QT_MOC_LITERAL(72, 1010, 9), // "Frequency"
QT_MOC_LITERAL(73, 1020, 4), // "base"
QT_MOC_LITERAL(74, 1025, 8), // "setFreq4"
QT_MOC_LITERAL(75, 1034, 6), // "rxFreq"
QT_MOC_LITERAL(76, 1041, 6), // "txFreq"
QT_MOC_LITERAL(77, 1048, 13), // "msgAvgDecode2"
QT_MOC_LITERAL(78, 1062, 8), // "fastPick"
QT_MOC_LITERAL(79, 1071, 2), // "x0"
QT_MOC_LITERAL(80, 1074, 2), // "x1"
QT_MOC_LITERAL(81, 1077, 1), // "y"
QT_MOC_LITERAL(82, 1079, 8), // "skedFreq"
QT_MOC_LITERAL(83, 1088, 2), // "sf"
QT_MOC_LITERAL(84, 1091, 16), // "initialize_fonts"
QT_MOC_LITERAL(85, 1108, 17), // "ScrollBarPosition"
QT_MOC_LITERAL(86, 1126, 22), // "overlayCallsignClicked"
QT_MOC_LITERAL(87, 1149, 4), // "call"
QT_MOC_LITERAL(88, 1154, 7), // "freq_hz"
QT_MOC_LITERAL(89, 1162, 19), // "decoded_even_period"
QT_MOC_LITERAL(90, 1182, 4), // "grid"
QT_MOC_LITERAL(91, 1187, 33), // "on_actionUse_Dark_Style_trigg..."
QT_MOC_LITERAL(92, 1221, 7), // "checked"
QT_MOC_LITERAL(93, 1229, 31), // "on_actionBand_Buttons_triggered"
QT_MOC_LITERAL(94, 1261, 34), // "on_actionVHF_UHF_Buttons_trig..."
QT_MOC_LITERAL(95, 1296, 16), // "on_pb160_clicked"
QT_MOC_LITERAL(96, 1313, 15), // "on_pb80_clicked"
QT_MOC_LITERAL(97, 1329, 15), // "on_pb60_clicked"
QT_MOC_LITERAL(98, 1345, 15), // "on_pb40_clicked"
QT_MOC_LITERAL(99, 1361, 15), // "on_pb30_clicked"
QT_MOC_LITERAL(100, 1377, 15), // "on_pb20_clicked"
QT_MOC_LITERAL(101, 1393, 15), // "on_pb17_clicked"
QT_MOC_LITERAL(102, 1409, 15), // "on_pb15_clicked"
QT_MOC_LITERAL(103, 1425, 15), // "on_pb12_clicked"
QT_MOC_LITERAL(104, 1441, 15), // "on_pb10_clicked"
QT_MOC_LITERAL(105, 1457, 14), // "on_pb8_clicked"
QT_MOC_LITERAL(106, 1472, 14), // "on_pb6_clicked"
QT_MOC_LITERAL(107, 1487, 14), // "on_pb2_clicked"
QT_MOC_LITERAL(108, 1502, 15), // "on_pb70_clicked"
QT_MOC_LITERAL(109, 1518, 15), // "on_pb50_clicked"
QT_MOC_LITERAL(110, 1534, 14), // "on_pb4_clicked"
QT_MOC_LITERAL(111, 1549, 16), // "on_pb144_clicked"
QT_MOC_LITERAL(112, 1566, 16), // "on_pb220_clicked"
QT_MOC_LITERAL(113, 1583, 16), // "on_pb432_clicked"
QT_MOC_LITERAL(114, 1600, 16), // "on_pb902_clicked"
QT_MOC_LITERAL(115, 1617, 15), // "on_pb23_clicked"
QT_MOC_LITERAL(116, 1633, 15), // "on_pb13_clicked"
QT_MOC_LITERAL(117, 1649, 14), // "on_pb9_clicked"
QT_MOC_LITERAL(118, 1664, 15), // "on_pb5G_clicked"
QT_MOC_LITERAL(119, 1680, 16), // "on_pb10G_clicked"
QT_MOC_LITERAL(120, 1697, 16), // "on_pb24G_clicked"
QT_MOC_LITERAL(121, 1714, 17), // "check_band_limits"
QT_MOC_LITERAL(122, 1732, 21), // "check_msk144_TRperiod"
QT_MOC_LITERAL(123, 1754, 18), // "check_button_color"
QT_MOC_LITERAL(124, 1773, 13), // "stopWRTimeout"
QT_MOC_LITERAL(125, 1787, 13), // "stopWCTimeout"
QT_MOC_LITERAL(126, 1801, 16), // "bandHoppingTimer"
QT_MOC_LITERAL(127, 1818, 11), // "bandHopping"
QT_MOC_LITERAL(128, 1830, 22), // "on_houndButton_clicked"
QT_MOC_LITERAL(129, 1853, 23), // "on_cbHoldTxFreq_clicked"
QT_MOC_LITERAL(130, 1877, 20), // "on_ft8Button_clicked"
QT_MOC_LITERAL(131, 1898, 20), // "on_ft4Button_clicked"
QT_MOC_LITERAL(132, 1919, 20), // "on_ft2Button_clicked"
QT_MOC_LITERAL(133, 1940, 23), // "on_msk144Button_clicked"
QT_MOC_LITERAL(134, 1964, 20), // "on_q65Button_clicked"
QT_MOC_LITERAL(135, 1985, 21), // "on_jt65Button_clicked"
QT_MOC_LITERAL(136, 2007, 21), // "on_echoButton_clicked"
QT_MOC_LITERAL(137, 2029, 16), // "on_pb15A_clicked"
QT_MOC_LITERAL(138, 2046, 16), // "on_pb15C_clicked"
QT_MOC_LITERAL(139, 2063, 16), // "on_pb30B_clicked"
QT_MOC_LITERAL(140, 2080, 16), // "on_pb60C_clicked"
QT_MOC_LITERAL(141, 2097, 16), // "on_pb60D_clicked"
QT_MOC_LITERAL(142, 2114, 16), // "on_pb60E_clicked"
QT_MOC_LITERAL(143, 2131, 22), // "on_tx1_editingFinished"
QT_MOC_LITERAL(144, 2154, 22), // "on_tx2_editingFinished"
QT_MOC_LITERAL(145, 2177, 22), // "on_tx3_editingFinished"
QT_MOC_LITERAL(146, 2200, 22), // "on_tx4_editingFinished"
QT_MOC_LITERAL(147, 2223, 25), // "on_tx5_currentTextChanged"
QT_MOC_LITERAL(148, 2249, 22), // "on_tx6_editingFinished"
QT_MOC_LITERAL(149, 2272, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(150, 2300, 24), // "on_monitorButton_clicked"
QT_MOC_LITERAL(151, 2325, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(152, 2350, 21), // "on_autoButton_clicked"
QT_MOC_LITERAL(153, 2372, 23), // "on_stopTxButton_clicked"
QT_MOC_LITERAL(154, 2396, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(155, 2418, 24), // "on_pbBandHopping_clicked"
QT_MOC_LITERAL(156, 2443, 43), // "on_actionAccept_QMAP_click_ev..."
QT_MOC_LITERAL(157, 2487, 32), // "on_actionRelease_Notes_triggered"
QT_MOC_LITERAL(158, 2520, 31), // "on_actionWS_Home_Page_triggered"
QT_MOC_LITERAL(159, 2552, 36), // "on_actionWSJT_X_User_Guide_tr..."
QT_MOC_LITERAL(160, 2589, 49), // "on_actionFT8_DXpedition_Mode_..."
QT_MOC_LITERAL(161, 2639, 38), // "on_actionSuperFox_User_Guide_..."
QT_MOC_LITERAL(162, 2678, 27), // "on_actionQSG_FST4_triggered"
QT_MOC_LITERAL(163, 2706, 26), // "on_actionQSG_Q65_triggered"
QT_MOC_LITERAL(164, 2733, 30), // "on_actionQSG_X250_M3_triggered"
QT_MOC_LITERAL(165, 2764, 59), // "on_actionQuick_Start_Guide_to..."
QT_MOC_LITERAL(166, 2824, 47), // "on_actionDownload_EME_Ephemer..."
QT_MOC_LITERAL(167, 2872, 37), // "on_actionKeyboard_shortcuts_t..."
QT_MOC_LITERAL(168, 2910, 41), // "on_actionSpecial_mouse_comman..."
QT_MOC_LITERAL(169, 2952, 45), // "on_actionRecommended_Audio_Se..."
QT_MOC_LITERAL(170, 2998, 37), // "on_actionRig_Control_Errors_t..."
QT_MOC_LITERAL(171, 3036, 35), // "on_actionCopyright_Notice_tri..."
QT_MOC_LITERAL(172, 3072, 32), // "on_actionSolve_FreqCal_triggered"
QT_MOC_LITERAL(173, 3105, 33), // "on_actionWide_Waterfall_trigg..."
QT_MOC_LITERAL(174, 3139, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(175, 3163, 41), // "on_actionOpen_next_in_directo..."
QT_MOC_LITERAL(176, 3205, 54), // "on_actionDecode_remaining_fil..."
QT_MOC_LITERAL(177, 3260, 50), // "on_actionDelete_all_wav_files..."
QT_MOC_LITERAL(178, 3311, 37), // "on_actionOpen_log_directory_t..."
QT_MOC_LITERAL(179, 3349, 23), // "on_actionNone_triggered"
QT_MOC_LITERAL(180, 3373, 27), // "on_actionSave_all_triggered"
QT_MOC_LITERAL(181, 3401, 40), // "on_actionDefault_event_loggin..."
QT_MOC_LITERAL(182, 3442, 34), // "on_actionDiagnostic_mode_trig..."
QT_MOC_LITERAL(183, 3477, 40), // "on_actionDisable_event_loggin..."
QT_MOC_LITERAL(184, 3518, 27), // "on_actionSWL_Mode_triggered"
QT_MOC_LITERAL(185, 3546, 23), // "on_DecodeButton_clicked"
QT_MOC_LITERAL(186, 3570, 6), // "decode"
QT_MOC_LITERAL(187, 3577, 10), // "decodeBusy"
QT_MOC_LITERAL(188, 3588, 1), // "b"
QT_MOC_LITERAL(189, 3590, 22), // "on_EraseButton_clicked"
QT_MOC_LITERAL(190, 3613, 21), // "band_activity_cleared"
QT_MOC_LITERAL(191, 3635, 29), // "rx_frequency_activity_cleared"
QT_MOC_LITERAL(192, 3665, 31), // "on_txFirstCheckBox_stateChanged"
QT_MOC_LITERAL(193, 3697, 4), // "arg1"
QT_MOC_LITERAL(194, 3702, 15), // "set_dateTimeQSO"
QT_MOC_LITERAL(195, 3718, 5), // "m_ntx"
QT_MOC_LITERAL(196, 3724, 7), // "set_ntx"
QT_MOC_LITERAL(197, 3732, 16), // "on_txrb1_toggled"
QT_MOC_LITERAL(198, 3749, 6), // "status"
QT_MOC_LITERAL(199, 3756, 22), // "on_txrb1_doubleClicked"
QT_MOC_LITERAL(200, 3779, 16), // "on_txrb2_toggled"
QT_MOC_LITERAL(201, 3796, 16), // "on_txrb3_toggled"
QT_MOC_LITERAL(202, 3813, 16), // "on_txrb4_toggled"
QT_MOC_LITERAL(203, 3830, 22), // "on_txrb4_doubleClicked"
QT_MOC_LITERAL(204, 3853, 16), // "on_txrb5_toggled"
QT_MOC_LITERAL(205, 3870, 22), // "on_txrb5_doubleClicked"
QT_MOC_LITERAL(206, 3893, 16), // "on_txrb6_toggled"
QT_MOC_LITERAL(207, 3910, 15), // "on_txb1_clicked"
QT_MOC_LITERAL(208, 3926, 21), // "on_txb1_doubleClicked"
QT_MOC_LITERAL(209, 3948, 15), // "on_txb2_clicked"
QT_MOC_LITERAL(210, 3964, 15), // "on_txb3_clicked"
QT_MOC_LITERAL(211, 3980, 15), // "on_txb4_clicked"
QT_MOC_LITERAL(212, 3996, 21), // "on_txb4_doubleClicked"
QT_MOC_LITERAL(213, 4018, 15), // "on_txb5_clicked"
QT_MOC_LITERAL(214, 4034, 21), // "on_txb5_doubleClicked"
QT_MOC_LITERAL(215, 4056, 15), // "on_txb6_clicked"
QT_MOC_LITERAL(216, 4072, 23), // "on_lookupButton_clicked"
QT_MOC_LITERAL(217, 4096, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(218, 4117, 23), // "on_ignoreButton_clicked"
QT_MOC_LITERAL(219, 4141, 23), // "on_comboBoxCQ_activated"
QT_MOC_LITERAL(220, 4165, 25), // "on_DX_Call_Button_clicked"
QT_MOC_LITERAL(221, 4191, 10), // "wheelEvent"
QT_MOC_LITERAL(222, 4202, 12), // "QWheelEvent*"
QT_MOC_LITERAL(223, 4215, 5), // "event"
QT_MOC_LITERAL(224, 4221, 15), // "mousePressEvent"
QT_MOC_LITERAL(225, 4237, 12), // "QMouseEvent*"
QT_MOC_LITERAL(226, 4250, 26), // "on_dxCallEntry_textChanged"
QT_MOC_LITERAL(227, 4277, 26), // "on_dxGridEntry_textChanged"
QT_MOC_LITERAL(228, 4304, 30), // "on_dxCallEntry_editingFinished"
QT_MOC_LITERAL(229, 4335, 28), // "on_dxCallEntry_returnPressed"
QT_MOC_LITERAL(230, 4364, 31), // "on_genStdMsgsPushButton_clicked"
QT_MOC_LITERAL(231, 4396, 23), // "on_logQSOButton_clicked"
QT_MOC_LITERAL(232, 4420, 10), // "read_txLog"
QT_MOC_LITERAL(233, 4431, 31), // "on_actionErase_Tx_Log_triggered"
QT_MOC_LITERAL(234, 4463, 15), // "read_ignoreList"
QT_MOC_LITERAL(235, 4479, 23), // "addCallsignToignoreList"
QT_MOC_LITERAL(236, 4503, 36), // "on_actionErase_Ignore_List_tr..."
QT_MOC_LITERAL(237, 4540, 13), // "read_ALLCALL7"
QT_MOC_LITERAL(238, 4554, 16), // "remove_old_files"
QT_MOC_LITERAL(239, 4571, 13), // "directoryPath"
QT_MOC_LITERAL(240, 4585, 7), // "daysOld"
QT_MOC_LITERAL(241, 4593, 22), // "on_actionJT9_triggered"
QT_MOC_LITERAL(242, 4616, 23), // "on_actionJT65_triggered"
QT_MOC_LITERAL(243, 4640, 22), // "on_actionJT4_triggered"
QT_MOC_LITERAL(244, 4663, 22), // "on_actionFT2_triggered"
QT_MOC_LITERAL(245, 4686, 22), // "on_actionFT4_triggered"
QT_MOC_LITERAL(246, 4709, 22), // "on_actionFT8_triggered"
QT_MOC_LITERAL(247, 4732, 23), // "on_actionFST4_triggered"
QT_MOC_LITERAL(248, 4756, 24), // "on_actionFST4W_triggered"
QT_MOC_LITERAL(249, 4781, 29), // "on_TxFreqSpinBox_valueChanged"
QT_MOC_LITERAL(250, 4811, 31), // "on_actionSave_decoded_triggered"
QT_MOC_LITERAL(251, 4843, 28), // "on_actionQuickDecode_toggled"
QT_MOC_LITERAL(252, 4872, 29), // "on_actionMediumDecode_toggled"
QT_MOC_LITERAL(253, 4902, 30), // "on_actionDeepestDecode_toggled"
QT_MOC_LITERAL(254, 4933, 32), // "on_actionDecFT8cycles1_triggered"
QT_MOC_LITERAL(255, 4966, 32), // "on_actionDecFT8cycles2_triggered"
QT_MOC_LITERAL(256, 4999, 32), // "on_actionDecFT8cycles3_triggered"
QT_MOC_LITERAL(257, 5032, 25), // "on_actionRXfLow_triggered"
QT_MOC_LITERAL(258, 5058, 28), // "on_actionRXfMedium_triggered"
QT_MOC_LITERAL(259, 5087, 26), // "on_actionRXfHigh_triggered"
QT_MOC_LITERAL(260, 5114, 32), // "on_actionClaimQmapClicks_toggled"
QT_MOC_LITERAL(261, 5147, 33), // "on_actionQmapSourceAuto_trigg..."
QT_MOC_LITERAL(262, 5181, 30), // "on_actionQmapSource1_triggered"
QT_MOC_LITERAL(263, 5212, 30), // "on_actionQmapSource2_triggered"
QT_MOC_LITERAL(264, 5243, 30), // "on_actionQmapSource3_triggered"
QT_MOC_LITERAL(265, 5274, 30), // "on_actionQmapSource4_triggered"
QT_MOC_LITERAL(266, 5305, 25), // "on_actionMTAuto_triggered"
QT_MOC_LITERAL(267, 5331, 22), // "on_actionMT1_triggered"
QT_MOC_LITERAL(268, 5354, 22), // "on_actionMT2_triggered"
QT_MOC_LITERAL(269, 5377, 22), // "on_actionMT3_triggered"
QT_MOC_LITERAL(270, 5400, 22), // "on_actionMT4_triggered"
QT_MOC_LITERAL(271, 5423, 22), // "on_actionMT5_triggered"
QT_MOC_LITERAL(272, 5446, 22), // "on_actionMT6_triggered"
QT_MOC_LITERAL(273, 5469, 22), // "on_actionMT7_triggered"
QT_MOC_LITERAL(274, 5492, 22), // "on_actionMT8_triggered"
QT_MOC_LITERAL(275, 5515, 22), // "on_actionMT9_triggered"
QT_MOC_LITERAL(276, 5538, 23), // "on_actionMT10_triggered"
QT_MOC_LITERAL(277, 5562, 23), // "on_actionMT11_triggered"
QT_MOC_LITERAL(278, 5586, 23), // "on_actionMT12_triggered"
QT_MOC_LITERAL(279, 5610, 27), // "on_actionFT8SensMin_toggled"
QT_MOC_LITERAL(280, 5638, 33), // "on_actionlowFT8thresholds_tog..."
QT_MOC_LITERAL(281, 5672, 27), // "on_actionFT8subpass_toggled"
QT_MOC_LITERAL(282, 5700, 30), // "on_actionStartTwoStage_toggled"
QT_MOC_LITERAL(283, 5731, 32), // "on_actionStartThreeStage_toggled"
QT_MOC_LITERAL(284, 5764, 27), // "on_actionStartEarly_toggled"
QT_MOC_LITERAL(285, 5792, 28), // "on_actionStartNormal_toggled"
QT_MOC_LITERAL(286, 5821, 26), // "on_actionStartLate_toggled"
QT_MOC_LITERAL(287, 5848, 40), // "on_actionFT8WidebandDXCallSea..."
QT_MOC_LITERAL(288, 5889, 48), // "on_actionUse_multithreaded_FT..."
QT_MOC_LITERAL(289, 5938, 8), // "bumpFqso"
QT_MOC_LITERAL(290, 5947, 32), // "on_actionErase_ALL_TXT_triggered"
QT_MOC_LITERAL(291, 5980, 38), // "on_reset_cabrillo_log_action_..."
QT_MOC_LITERAL(292, 6019, 38), // "on_actionErase_wsjtx_log_adi_..."
QT_MOC_LITERAL(293, 6058, 39), // "on_actionErase_WSPR_hashtable..."
QT_MOC_LITERAL(294, 6098, 44), // "on_actionErase_list_of_Q65_ca..."
QT_MOC_LITERAL(295, 6143, 38), // "on_actionExport_Cabrillo_log_..."
QT_MOC_LITERAL(296, 6182, 8), // "startTx2"
QT_MOC_LITERAL(297, 6191, 7), // "startP1"
QT_MOC_LITERAL(298, 6199, 6), // "stopTx"
QT_MOC_LITERAL(299, 6206, 7), // "stopTx2"
QT_MOC_LITERAL(300, 6214, 26), // "on_rptSpinBox_valueChanged"
QT_MOC_LITERAL(301, 6241, 8), // "killFile"
QT_MOC_LITERAL(302, 6250, 21), // "on_tuneButton_clicked"
QT_MOC_LITERAL(303, 6272, 16), // "on_pbR2T_clicked"
QT_MOC_LITERAL(304, 6289, 16), // "on_pbT2R_clicked"
QT_MOC_LITERAL(305, 6306, 9), // "acceptQSO"
QT_MOC_LITERAL(306, 6316, 9), // "dial_freq"
QT_MOC_LITERAL(307, 6326, 8), // "rpt_sent"
QT_MOC_LITERAL(308, 6335, 12), // "rpt_received"
QT_MOC_LITERAL(309, 6348, 8), // "tx_power"
QT_MOC_LITERAL(310, 6357, 8), // "comments"
QT_MOC_LITERAL(311, 6366, 4), // "name"
QT_MOC_LITERAL(312, 6371, 11), // "QSO_date_on"
QT_MOC_LITERAL(313, 6383, 13), // "operator_call"
QT_MOC_LITERAL(314, 6397, 7), // "my_call"
QT_MOC_LITERAL(315, 6405, 7), // "my_grid"
QT_MOC_LITERAL(316, 6413, 13), // "exchange_sent"
QT_MOC_LITERAL(317, 6427, 13), // "exchange_rcvd"
QT_MOC_LITERAL(318, 6441, 8), // "propmode"
QT_MOC_LITERAL(319, 6450, 9), // "satellite"
QT_MOC_LITERAL(320, 6460, 8), // "sat_mode"
QT_MOC_LITERAL(321, 6469, 6), // "freqRx"
QT_MOC_LITERAL(322, 6476, 4), // "ADIF"
QT_MOC_LITERAL(323, 6481, 35), // "on_bandComboBox_currentIndexC..."
QT_MOC_LITERAL(324, 6517, 5), // "index"
QT_MOC_LITERAL(325, 6523, 31), // "on_bandComboBox_editTextChanged"
QT_MOC_LITERAL(326, 6555, 4), // "text"
QT_MOC_LITERAL(327, 6560, 25), // "on_bandComboBox_activated"
QT_MOC_LITERAL(328, 6586, 19), // "on_readFreq_clicked"
QT_MOC_LITERAL(329, 6606, 29), // "on_RxFreqSpinBox_valueChanged"
QT_MOC_LITERAL(330, 6636, 30), // "on_outAttenuation_valueChanged"
QT_MOC_LITERAL(331, 6667, 7), // "rigOpen"
QT_MOC_LITERAL(332, 6675, 25), // "handle_transceiver_update"
QT_MOC_LITERAL(333, 6701, 29), // "Transceiver::TransceiverState"
QT_MOC_LITERAL(334, 6731, 26), // "handle_transceiver_failure"
QT_MOC_LITERAL(335, 6758, 22), // "handle_leavingSettings"
QT_MOC_LITERAL(336, 6781, 34), // "on_actionAstronomical_data_to..."
QT_MOC_LITERAL(337, 6816, 37), // "on_actionQSYMessage_Creator_t..."
QT_MOC_LITERAL(338, 6854, 30), // "on_actionQSY_Monitor_triggered"
QT_MOC_LITERAL(339, 6885, 15), // "alertQSYmessage"
QT_MOC_LITERAL(340, 6901, 61), // "on_actionShort_list_of_add_on..."
QT_MOC_LITERAL(341, 6963, 12), // "band_changed"
QT_MOC_LITERAL(342, 6976, 7), // "monitor"
QT_MOC_LITERAL(343, 6984, 10), // "end_tuning"
QT_MOC_LITERAL(344, 6995, 11), // "stop_tuning"
QT_MOC_LITERAL(345, 7007, 11), // "stopTuneATU"
QT_MOC_LITERAL(346, 7019, 12), // "auto_tx_mode"
QT_MOC_LITERAL(347, 7032, 36), // "on_actionMessage_averaging_tr..."
QT_MOC_LITERAL(348, 7069, 33), // "on_actionActiveStations_trigg..."
QT_MOC_LITERAL(349, 7103, 31), // "on_contest_log_action_triggered"
QT_MOC_LITERAL(350, 7135, 27), // "on_fox_log_action_triggered"
QT_MOC_LITERAL(351, 7163, 25), // "on_actionColors_triggered"
QT_MOC_LITERAL(352, 7189, 34), // "on_actionInclude_averaging_to..."
QT_MOC_LITERAL(353, 7224, 36), // "on_actionInclude_correlation_..."
QT_MOC_LITERAL(354, 7261, 33), // "on_actionEnable_AP_DXcall_tog..."
QT_MOC_LITERAL(355, 7295, 31), // "on_actionAuto_Clear_Avg_toggled"
QT_MOC_LITERAL(356, 7327, 20), // "VHF_features_enabled"
QT_MOC_LITERAL(357, 7348, 25), // "on_sbSubmode_valueChanged"
QT_MOC_LITERAL(358, 7374, 20), // "on_cbSendMsg_toggled"
QT_MOC_LITERAL(359, 7395, 19), // "on_cbShMsgs_toggled"
QT_MOC_LITERAL(360, 7415, 16), // "on_cbSWL_toggled"
QT_MOC_LITERAL(361, 7432, 16), // "on_cbTx6_toggled"
QT_MOC_LITERAL(362, 7449, 18), // "on_cbMenus_toggled"
QT_MOC_LITERAL(363, 7468, 19), // "on_cbCQonly_toggled"
QT_MOC_LITERAL(364, 7488, 20), // "on_cbAutoSeq_toggled"
QT_MOC_LITERAL(365, 7509, 12), // "networkError"
QT_MOC_LITERAL(366, 7522, 23), // "on_ClrAvgButton_clicked"
QT_MOC_LITERAL(367, 7546, 23), // "on_actionWSPR_triggered"
QT_MOC_LITERAL(368, 7570, 27), // "on_syncSpinBox_valueChanged"
QT_MOC_LITERAL(369, 7598, 38), // "on_TxPowerComboBox_currentInd..."
QT_MOC_LITERAL(370, 7637, 27), // "on_sbTxPercent_valueChanged"
QT_MOC_LITERAL(371, 7665, 29), // "on_cbUploadWSPR_Spots_toggled"
QT_MOC_LITERAL(372, 7695, 11), // "WSPR_config"
QT_MOC_LITERAL(373, 7707, 15), // "uploadWSPRSpots"
QT_MOC_LITERAL(374, 7723, 11), // "direct_post"
QT_MOC_LITERAL(375, 7735, 11), // "decode_text"
QT_MOC_LITERAL(376, 7747, 7), // "TxAgain"
QT_MOC_LITERAL(377, 7755, 14), // "uploadResponse"
QT_MOC_LITERAL(378, 7770, 8), // "response"
QT_MOC_LITERAL(379, 7779, 31), // "on_WSPRfreqSpinBox_valueChanged"
QT_MOC_LITERAL(380, 7811, 30), // "on_sbFST4W_RxFreq_valueChanged"
QT_MOC_LITERAL(381, 7842, 28), // "on_sbFST4W_FTol_valueChanged"
QT_MOC_LITERAL(382, 7871, 19), // "on_pbTxNext_clicked"
QT_MOC_LITERAL(383, 7891, 29), // "on_actionEcho_Graph_triggered"
QT_MOC_LITERAL(384, 7921, 23), // "on_actionEcho_triggered"
QT_MOC_LITERAL(385, 7945, 29), // "on_actionFast_Graph_triggered"
QT_MOC_LITERAL(386, 7975, 16), // "fast_decode_done"
QT_MOC_LITERAL(387, 7992, 45), // "on_actionMeasure_reference_sp..."
QT_MOC_LITERAL(388, 8038, 43), // "on_actionErase_reference_spec..."
QT_MOC_LITERAL(389, 8082, 41), // "on_actionMeasure_phase_respon..."
QT_MOC_LITERAL(390, 8124, 20), // "on_sbTR_valueChanged"
QT_MOC_LITERAL(391, 8145, 26), // "on_sbTR_FST4W_valueChanged"
QT_MOC_LITERAL(392, 8172, 22), // "on_sbFtol_valueChanged"
QT_MOC_LITERAL(393, 8195, 18), // "on_cbFast9_clicked"
QT_MOC_LITERAL(394, 8214, 26), // "on_sbCQTxFreq_valueChanged"
QT_MOC_LITERAL(395, 8241, 17), // "on_cbCQTx_toggled"
QT_MOC_LITERAL(396, 8259, 25), // "on_actionMSK144_triggered"
QT_MOC_LITERAL(397, 8285, 22), // "on_actionQ65_triggered"
QT_MOC_LITERAL(398, 8308, 26), // "on_actionFreqCal_triggered"
QT_MOC_LITERAL(399, 8335, 11), // "splash_done"
QT_MOC_LITERAL(400, 8347, 33), // "on_measure_check_box_stateCha..."
QT_MOC_LITERAL(401, 8381, 23), // "on_sbNlist_valueChanged"
QT_MOC_LITERAL(402, 8405, 24), // "on_sbNslots_valueChanged"
QT_MOC_LITERAL(403, 8430, 23), // "on_sbF_Low_valueChanged"
QT_MOC_LITERAL(404, 8454, 24), // "on_sbF_High_valueChanged"
QT_MOC_LITERAL(405, 8479, 19), // "chk_FST4_freq_range"
QT_MOC_LITERAL(406, 8499, 21), // "on_pbFoxReset_clicked"
QT_MOC_LITERAL(407, 8521, 21), // "on_pbFreeText_clicked"
QT_MOC_LITERAL(408, 8543, 8), // "FoxReset"
QT_MOC_LITERAL(409, 8552, 30), // "on_comboBoxHoundSort_activated"
QT_MOC_LITERAL(410, 8583, 22), // "not_GA_warning_message"
QT_MOC_LITERAL(411, 8606, 22), // "checkMSK144ContestType"
QT_MOC_LITERAL(412, 8629, 19), // "on_pbBestSP_clicked"
QT_MOC_LITERAL(413, 8649, 32), // "on_RoundRobin_currentTextChanged"
QT_MOC_LITERAL(414, 8682, 8), // "setTxMsg"
QT_MOC_LITERAL(415, 8691, 7), // "stdCall"
QT_MOC_LITERAL(416, 8699, 1), // "w"
QT_MOC_LITERAL(417, 8701, 16), // "remote_configure"
QT_MOC_LITERAL(418, 8718, 19), // "frequency_tolerance"
QT_MOC_LITERAL(419, 8738, 7), // "submode"
QT_MOC_LITERAL(420, 8746, 9), // "fast_mode"
QT_MOC_LITERAL(421, 8756, 9), // "tr_period"
QT_MOC_LITERAL(422, 8766, 5), // "rx_df"
QT_MOC_LITERAL(423, 8772, 7), // "dx_call"
QT_MOC_LITERAL(424, 8780, 7), // "dx_grid"
QT_MOC_LITERAL(425, 8788, 17), // "generate_messages"
QT_MOC_LITERAL(426, 8806, 10), // "callSandP2"
QT_MOC_LITERAL(427, 8817, 5), // "nline"
QT_MOC_LITERAL(428, 8823, 24), // "refreshHoundQueueDisplay"
QT_MOC_LITERAL(429, 8848, 23), // "queueActiveWindowHound2"
QT_MOC_LITERAL(430, 8872, 10), // "update_tx5"
QT_MOC_LITERAL(431, 8883, 8), // "qsy_text"
QT_MOC_LITERAL(432, 8892, 9), // "reply_tx5"
QT_MOC_LITERAL(433, 8902, 26), // "setQSYMessageCreatorStatus"
QT_MOC_LITERAL(434, 8929, 22), // "QSYMessageCreatorValue"
QT_MOC_LITERAL(435, 8952, 22), // "on_rbFixedTone_toggled"
QT_MOC_LITERAL(436, 8975, 24), // "on_rbEchoMessage_toggled"
QT_MOC_LITERAL(437, 9000, 19), // "on_rbEchoCW_toggled"
QT_MOC_LITERAL(438, 9020, 28), // "on_leEchoMessage_textChanged"
QT_MOC_LITERAL(439, 9049, 17), // "ARRL_Digi_Display"
QT_MOC_LITERAL(440, 9067, 23), // "on_actionJTTY_triggered"
QT_MOC_LITERAL(441, 9091, 23), // "on_actionRTTY_triggered"
QT_MOC_LITERAL(442, 9115, 24), // "on_cbIncludeTime_toggled"
QT_MOC_LITERAL(443, 9140, 40), // "on_comboBoxJttyStyle_currentI..."
QT_MOC_LITERAL(444, 9181, 31), // "on_RxFreqSpinBox_2_valueChanged"
QT_MOC_LITERAL(445, 9213, 31), // "on_TxFreqSpinBox_2_valueChanged"
QT_MOC_LITERAL(446, 9245, 24), // "on_sbFtol_2_valueChanged"
QT_MOC_LITERAL(447, 9270, 18), // "on_pbR2T_2_clicked"
QT_MOC_LITERAL(448, 9289, 18), // "on_pbT2R_2_clicked"
QT_MOC_LITERAL(449, 9308, 24), // "on_pbSendMessage_clicked"
QT_MOC_LITERAL(450, 9333, 27), // "on_Tx_Message_returnPressed"
QT_MOC_LITERAL(451, 9361, 15), // "on_pbF1_clicked"
QT_MOC_LITERAL(452, 9377, 15), // "on_pbF2_clicked"
QT_MOC_LITERAL(453, 9393, 15), // "on_pbF3_clicked"
QT_MOC_LITERAL(454, 9409, 15), // "on_pbF4_clicked"
QT_MOC_LITERAL(455, 9425, 15), // "on_pbF5_clicked"
QT_MOC_LITERAL(456, 9441, 15), // "on_pbF6_clicked"
QT_MOC_LITERAL(457, 9457, 15), // "on_pbF7_clicked"
QT_MOC_LITERAL(458, 9473, 15), // "on_pbF8_clicked"
QT_MOC_LITERAL(459, 9489, 5), // "Empty"
QT_MOC_LITERAL(460, 9495, 14), // "EncodingFailed"
QT_MOC_LITERAL(461, 9510, 9), // "QueueFull"
QT_MOC_LITERAL(462, 9520, 15), // "BackendRejected"
QT_MOC_LITERAL(463, 9536, 7), // "Aborted"
QT_MOC_LITERAL(464, 9544, 12) // "NotAvailable"

    },
    "MainWindow\0initializeAudioOutputStream\0"
    "\0QAudioDeviceInfo\0channels\0msBuffered\0"
    "stopAudioOutputStream\0startAudioInputStream\0"
    "framesPerBuffer\0AudioDevice*\0sink\0"
    "downSampleFactor\0AudioDevice::Channel\0"
    "suspendAudioInputStream\0resumeAudioInputStream\0"
    "startDetector\0FFTSize\0detectorClose\0"
    "finished\0transmitFrequency\0"
    "endTransmitMessage\0quick\0tune\0sendMessage\0"
    "mode\0symbolsLength\0framesPerSymbol\0"
    "frequency\0toneSpacing\0SoundOutput*\0"
    "synchronize\0fastMode\0dBSNR\0TRperiod\0"
    "outAttenuationChanged\0toggleShorthand\0"
    "reset_audio_input_stream\0report_dropped_frames\0"
    "jttyTextAccepted\0requestId\0jttyTextRejected\0"
    "JttyTxRejectReason\0reason\0jttyTextCompleted\0"
    "jttySessionDrained\0sessionId\0"
    "startJttyStream\0TxEvidence::TxRequest\0"
    "endJttyStream\0showSoundInError\0errorMsg\0"
    "showSoundOutError\0showStatusMessage\0"
    "statusMsg\0dataSink\0frames\0fastSink\0"
    "tci_mod_active\0on\0diskDat\0freezeDecode\0"
    "n\0guiUpdate\0doubleClickOnCall\0"
    "Qt::KeyboardModifiers\0doubleClickOnCall2\0"
    "doubleClickOnFoxQueue\0doubleClickOnFoxInProgress\0"
    "modifiers\0readFromStdout\0p1ReadFromStdout\0"
    "setXIT\0Frequency\0base\0setFreq4\0rxFreq\0"
    "txFreq\0msgAvgDecode2\0fastPick\0x0\0x1\0"
    "y\0skedFreq\0sf\0initialize_fonts\0"
    "ScrollBarPosition\0overlayCallsignClicked\0"
    "call\0freq_hz\0decoded_even_period\0grid\0"
    "on_actionUse_Dark_Style_triggered\0"
    "checked\0on_actionBand_Buttons_triggered\0"
    "on_actionVHF_UHF_Buttons_triggered\0"
    "on_pb160_clicked\0on_pb80_clicked\0"
    "on_pb60_clicked\0on_pb40_clicked\0"
    "on_pb30_clicked\0on_pb20_clicked\0"
    "on_pb17_clicked\0on_pb15_clicked\0"
    "on_pb12_clicked\0on_pb10_clicked\0"
    "on_pb8_clicked\0on_pb6_clicked\0"
    "on_pb2_clicked\0on_pb70_clicked\0"
    "on_pb50_clicked\0on_pb4_clicked\0"
    "on_pb144_clicked\0on_pb220_clicked\0"
    "on_pb432_clicked\0on_pb902_clicked\0"
    "on_pb23_clicked\0on_pb13_clicked\0"
    "on_pb9_clicked\0on_pb5G_clicked\0"
    "on_pb10G_clicked\0on_pb24G_clicked\0"
    "check_band_limits\0check_msk144_TRperiod\0"
    "check_button_color\0stopWRTimeout\0"
    "stopWCTimeout\0bandHoppingTimer\0"
    "bandHopping\0on_houndButton_clicked\0"
    "on_cbHoldTxFreq_clicked\0on_ft8Button_clicked\0"
    "on_ft4Button_clicked\0on_ft2Button_clicked\0"
    "on_msk144Button_clicked\0on_q65Button_clicked\0"
    "on_jt65Button_clicked\0on_echoButton_clicked\0"
    "on_pb15A_clicked\0on_pb15C_clicked\0"
    "on_pb30B_clicked\0on_pb60C_clicked\0"
    "on_pb60D_clicked\0on_pb60E_clicked\0"
    "on_tx1_editingFinished\0on_tx2_editingFinished\0"
    "on_tx3_editingFinished\0on_tx4_editingFinished\0"
    "on_tx5_currentTextChanged\0"
    "on_tx6_editingFinished\0"
    "on_actionSettings_triggered\0"
    "on_monitorButton_clicked\0"
    "on_actionAbout_triggered\0on_autoButton_clicked\0"
    "on_stopTxButton_clicked\0on_stopButton_clicked\0"
    "on_pbBandHopping_clicked\0"
    "on_actionAccept_QMAP_click_events_triggered\0"
    "on_actionRelease_Notes_triggered\0"
    "on_actionWS_Home_Page_triggered\0"
    "on_actionWSJT_X_User_Guide_triggered\0"
    "on_actionFT8_DXpedition_Mode_User_Guide_triggered\0"
    "on_actionSuperFox_User_Guide_triggered\0"
    "on_actionQSG_FST4_triggered\0"
    "on_actionQSG_Q65_triggered\0"
    "on_actionQSG_X250_M3_triggered\0"
    "on_actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP_triggered\0"
    "on_actionDownload_EME_Ephemeris_Chart_triggered\0"
    "on_actionKeyboard_shortcuts_triggered\0"
    "on_actionSpecial_mouse_commands_triggered\0"
    "on_actionRecommended_Audio_Settings_triggered\0"
    "on_actionRig_Control_Errors_triggered\0"
    "on_actionCopyright_Notice_triggered\0"
    "on_actionSolve_FreqCal_triggered\0"
    "on_actionWide_Waterfall_triggered\0"
    "on_actionOpen_triggered\0"
    "on_actionOpen_next_in_directory_triggered\0"
    "on_actionDecode_remaining_files_in_directory_triggered\0"
    "on_actionDelete_all_wav_files_in_SaveDir_triggered\0"
    "on_actionOpen_log_directory_triggered\0"
    "on_actionNone_triggered\0"
    "on_actionSave_all_triggered\0"
    "on_actionDefault_event_logging_triggered\0"
    "on_actionDiagnostic_mode_triggered\0"
    "on_actionDisable_event_logging_triggered\0"
    "on_actionSWL_Mode_triggered\0"
    "on_DecodeButton_clicked\0decode\0"
    "decodeBusy\0b\0on_EraseButton_clicked\0"
    "band_activity_cleared\0"
    "rx_frequency_activity_cleared\0"
    "on_txFirstCheckBox_stateChanged\0arg1\0"
    "set_dateTimeQSO\0m_ntx\0set_ntx\0"
    "on_txrb1_toggled\0status\0on_txrb1_doubleClicked\0"
    "on_txrb2_toggled\0on_txrb3_toggled\0"
    "on_txrb4_toggled\0on_txrb4_doubleClicked\0"
    "on_txrb5_toggled\0on_txrb5_doubleClicked\0"
    "on_txrb6_toggled\0on_txb1_clicked\0"
    "on_txb1_doubleClicked\0on_txb2_clicked\0"
    "on_txb3_clicked\0on_txb4_clicked\0"
    "on_txb4_doubleClicked\0on_txb5_clicked\0"
    "on_txb5_doubleClicked\0on_txb6_clicked\0"
    "on_lookupButton_clicked\0on_addButton_clicked\0"
    "on_ignoreButton_clicked\0on_comboBoxCQ_activated\0"
    "on_DX_Call_Button_clicked\0wheelEvent\0"
    "QWheelEvent*\0event\0mousePressEvent\0"
    "QMouseEvent*\0on_dxCallEntry_textChanged\0"
    "on_dxGridEntry_textChanged\0"
    "on_dxCallEntry_editingFinished\0"
    "on_dxCallEntry_returnPressed\0"
    "on_genStdMsgsPushButton_clicked\0"
    "on_logQSOButton_clicked\0read_txLog\0"
    "on_actionErase_Tx_Log_triggered\0"
    "read_ignoreList\0addCallsignToignoreList\0"
    "on_actionErase_Ignore_List_triggered\0"
    "read_ALLCALL7\0remove_old_files\0"
    "directoryPath\0daysOld\0on_actionJT9_triggered\0"
    "on_actionJT65_triggered\0on_actionJT4_triggered\0"
    "on_actionFT2_triggered\0on_actionFT4_triggered\0"
    "on_actionFT8_triggered\0on_actionFST4_triggered\0"
    "on_actionFST4W_triggered\0"
    "on_TxFreqSpinBox_valueChanged\0"
    "on_actionSave_decoded_triggered\0"
    "on_actionQuickDecode_toggled\0"
    "on_actionMediumDecode_toggled\0"
    "on_actionDeepestDecode_toggled\0"
    "on_actionDecFT8cycles1_triggered\0"
    "on_actionDecFT8cycles2_triggered\0"
    "on_actionDecFT8cycles3_triggered\0"
    "on_actionRXfLow_triggered\0"
    "on_actionRXfMedium_triggered\0"
    "on_actionRXfHigh_triggered\0"
    "on_actionClaimQmapClicks_toggled\0"
    "on_actionQmapSourceAuto_triggered\0"
    "on_actionQmapSource1_triggered\0"
    "on_actionQmapSource2_triggered\0"
    "on_actionQmapSource3_triggered\0"
    "on_actionQmapSource4_triggered\0"
    "on_actionMTAuto_triggered\0"
    "on_actionMT1_triggered\0on_actionMT2_triggered\0"
    "on_actionMT3_triggered\0on_actionMT4_triggered\0"
    "on_actionMT5_triggered\0on_actionMT6_triggered\0"
    "on_actionMT7_triggered\0on_actionMT8_triggered\0"
    "on_actionMT9_triggered\0on_actionMT10_triggered\0"
    "on_actionMT11_triggered\0on_actionMT12_triggered\0"
    "on_actionFT8SensMin_toggled\0"
    "on_actionlowFT8thresholds_toggled\0"
    "on_actionFT8subpass_toggled\0"
    "on_actionStartTwoStage_toggled\0"
    "on_actionStartThreeStage_toggled\0"
    "on_actionStartEarly_toggled\0"
    "on_actionStartNormal_toggled\0"
    "on_actionStartLate_toggled\0"
    "on_actionFT8WidebandDXCallSearch_toggled\0"
    "on_actionUse_multithreaded_FT8_decoder_triggered\0"
    "bumpFqso\0on_actionErase_ALL_TXT_triggered\0"
    "on_reset_cabrillo_log_action_triggered\0"
    "on_actionErase_wsjtx_log_adi_triggered\0"
    "on_actionErase_WSPR_hashtable_triggered\0"
    "on_actionErase_list_of_Q65_callers_triggered\0"
    "on_actionExport_Cabrillo_log_triggered\0"
    "startTx2\0startP1\0stopTx\0stopTx2\0"
    "on_rptSpinBox_valueChanged\0killFile\0"
    "on_tuneButton_clicked\0on_pbR2T_clicked\0"
    "on_pbT2R_clicked\0acceptQSO\0dial_freq\0"
    "rpt_sent\0rpt_received\0tx_power\0comments\0"
    "name\0QSO_date_on\0operator_call\0my_call\0"
    "my_grid\0exchange_sent\0exchange_rcvd\0"
    "propmode\0satellite\0sat_mode\0freqRx\0"
    "ADIF\0on_bandComboBox_currentIndexChanged\0"
    "index\0on_bandComboBox_editTextChanged\0"
    "text\0on_bandComboBox_activated\0"
    "on_readFreq_clicked\0on_RxFreqSpinBox_valueChanged\0"
    "on_outAttenuation_valueChanged\0rigOpen\0"
    "handle_transceiver_update\0"
    "Transceiver::TransceiverState\0"
    "handle_transceiver_failure\0"
    "handle_leavingSettings\0"
    "on_actionAstronomical_data_toggled\0"
    "on_actionQSYMessage_Creator_triggered\0"
    "on_actionQSY_Monitor_triggered\0"
    "alertQSYmessage\0"
    "on_actionShort_list_of_add_on_prefixes_and_suffixes_triggered\0"
    "band_changed\0monitor\0end_tuning\0"
    "stop_tuning\0stopTuneATU\0auto_tx_mode\0"
    "on_actionMessage_averaging_triggered\0"
    "on_actionActiveStations_triggered\0"
    "on_contest_log_action_triggered\0"
    "on_fox_log_action_triggered\0"
    "on_actionColors_triggered\0"
    "on_actionInclude_averaging_toggled\0"
    "on_actionInclude_correlation_toggled\0"
    "on_actionEnable_AP_DXcall_toggled\0"
    "on_actionAuto_Clear_Avg_toggled\0"
    "VHF_features_enabled\0on_sbSubmode_valueChanged\0"
    "on_cbSendMsg_toggled\0on_cbShMsgs_toggled\0"
    "on_cbSWL_toggled\0on_cbTx6_toggled\0"
    "on_cbMenus_toggled\0on_cbCQonly_toggled\0"
    "on_cbAutoSeq_toggled\0networkError\0"
    "on_ClrAvgButton_clicked\0on_actionWSPR_triggered\0"
    "on_syncSpinBox_valueChanged\0"
    "on_TxPowerComboBox_currentIndexChanged\0"
    "on_sbTxPercent_valueChanged\0"
    "on_cbUploadWSPR_Spots_toggled\0WSPR_config\0"
    "uploadWSPRSpots\0direct_post\0decode_text\0"
    "TxAgain\0uploadResponse\0response\0"
    "on_WSPRfreqSpinBox_valueChanged\0"
    "on_sbFST4W_RxFreq_valueChanged\0"
    "on_sbFST4W_FTol_valueChanged\0"
    "on_pbTxNext_clicked\0on_actionEcho_Graph_triggered\0"
    "on_actionEcho_triggered\0"
    "on_actionFast_Graph_triggered\0"
    "fast_decode_done\0"
    "on_actionMeasure_reference_spectrum_triggered\0"
    "on_actionErase_reference_spectrum_triggered\0"
    "on_actionMeasure_phase_response_triggered\0"
    "on_sbTR_valueChanged\0on_sbTR_FST4W_valueChanged\0"
    "on_sbFtol_valueChanged\0on_cbFast9_clicked\0"
    "on_sbCQTxFreq_valueChanged\0on_cbCQTx_toggled\0"
    "on_actionMSK144_triggered\0"
    "on_actionQ65_triggered\0"
    "on_actionFreqCal_triggered\0splash_done\0"
    "on_measure_check_box_stateChanged\0"
    "on_sbNlist_valueChanged\0"
    "on_sbNslots_valueChanged\0"
    "on_sbF_Low_valueChanged\0"
    "on_sbF_High_valueChanged\0chk_FST4_freq_range\0"
    "on_pbFoxReset_clicked\0on_pbFreeText_clicked\0"
    "FoxReset\0on_comboBoxHoundSort_activated\0"
    "not_GA_warning_message\0checkMSK144ContestType\0"
    "on_pbBestSP_clicked\0"
    "on_RoundRobin_currentTextChanged\0"
    "setTxMsg\0stdCall\0w\0remote_configure\0"
    "frequency_tolerance\0submode\0fast_mode\0"
    "tr_period\0rx_df\0dx_call\0dx_grid\0"
    "generate_messages\0callSandP2\0nline\0"
    "refreshHoundQueueDisplay\0"
    "queueActiveWindowHound2\0update_tx5\0"
    "qsy_text\0reply_tx5\0setQSYMessageCreatorStatus\0"
    "QSYMessageCreatorValue\0on_rbFixedTone_toggled\0"
    "on_rbEchoMessage_toggled\0on_rbEchoCW_toggled\0"
    "on_leEchoMessage_textChanged\0"
    "ARRL_Digi_Display\0on_actionJTTY_triggered\0"
    "on_actionRTTY_triggered\0"
    "on_cbIncludeTime_toggled\0"
    "on_comboBoxJttyStyle_currentIndexChanged\0"
    "on_RxFreqSpinBox_2_valueChanged\0"
    "on_TxFreqSpinBox_2_valueChanged\0"
    "on_sbFtol_2_valueChanged\0on_pbR2T_2_clicked\0"
    "on_pbT2R_2_clicked\0on_pbSendMessage_clicked\0"
    "on_Tx_Message_returnPressed\0on_pbF1_clicked\0"
    "on_pbF2_clicked\0on_pbF3_clicked\0"
    "on_pbF4_clicked\0on_pbF5_clicked\0"
    "on_pbF6_clicked\0on_pbF7_clicked\0"
    "on_pbF8_clicked\0Empty\0EncodingFailed\0"
    "QueueFull\0BackendRejected\0Aborted\0"
    "NotAvailable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     378,   14, // methods
       0,    0, // properties
       1, 2758, // enums/sets
       0,    0, // constructors
       0,       // flags
      29,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3, 1904,    2, 0x04 /* Private */,
       6,    0, 1911,    2, 0x04 /* Private */,
       7,    5, 1912,    2, 0x04 /* Private */,
      13,    0, 1923,    2, 0x04 /* Private */,
      14,    0, 1924,    2, 0x04 /* Private */,
      15,    1, 1925,    2, 0x04 /* Private */,
      16,    1, 1928,    2, 0x04 /* Private */,
      17,    0, 1931,    2, 0x04 /* Private */,
      18,    0, 1932,    2, 0x04 /* Private */,
      19,    1, 1933,    2, 0x04 /* Private */,
      20,    1, 1936,    2, 0x04 /* Private */,
      20,    0, 1939,    2, 0x24 /* Private | MethodCloned */,
      22,    1, 1940,    2, 0x04 /* Private */,
      22,    0, 1943,    2, 0x24 /* Private | MethodCloned */,
      23,   11, 1944,    2, 0x04 /* Private */,
      23,   10, 1967,    2, 0x24 /* Private | MethodCloned */,
      23,    9, 1988,    2, 0x24 /* Private | MethodCloned */,
      23,    8, 2007,    2, 0x24 /* Private | MethodCloned */,
      23,    7, 2024,    2, 0x24 /* Private | MethodCloned */,
      23,    6, 2039,    2, 0x24 /* Private | MethodCloned */,
      34,    1, 2052,    2, 0x04 /* Private */,
      35,    0, 2055,    2, 0x04 /* Private */,
      36,    1, 2056,    2, 0x04 /* Private */,
      38,    1, 2059,    2, 0x06 /* Public */,
      40,    2, 2062,    2, 0x06 /* Public */,
      43,    1, 2067,    2, 0x06 /* Public */,
      44,    1, 2070,    2, 0x06 /* Public */,
      46,    2, 2073,    2, 0x04 /* Private */,
      48,    0, 2078,    2, 0x04 /* Private */,

 // slots: name, argc, parameters, tag, flags
      49,    1, 2079,    2, 0x0a /* Public */,
      51,    1, 2082,    2, 0x0a /* Public */,
      52,    1, 2085,    2, 0x0a /* Public */,
      54,    1, 2088,    2, 0x0a /* Public */,
      56,    1, 2091,    2, 0x0a /* Public */,
      57,    1, 2094,    2, 0x0a /* Public */,
      59,    0, 2097,    2, 0x0a /* Public */,
      60,    1, 2098,    2, 0x0a /* Public */,
      62,    0, 2101,    2, 0x0a /* Public */,
      63,    1, 2102,    2, 0x0a /* Public */,
      65,    1, 2105,    2, 0x0a /* Public */,
      66,    1, 2108,    2, 0x0a /* Public */,
      67,    1, 2111,    2, 0x0a /* Public */,
      69,    0, 2114,    2, 0x0a /* Public */,
      70,    0, 2115,    2, 0x0a /* Public */,
      71,    2, 2116,    2, 0x0a /* Public */,
      71,    1, 2121,    2, 0x2a /* Public | MethodCloned */,
      74,    2, 2124,    2, 0x0a /* Public */,
      77,    0, 2129,    2, 0x0a /* Public */,
      78,    3, 2130,    2, 0x0a /* Public */,
      82,    1, 2137,    2, 0x0a /* Public */,
      84,    0, 2140,    2, 0x08 /* Private */,
      85,    1, 2141,    2, 0x08 /* Private */,
      86,    4, 2144,    2, 0x08 /* Private */,
      91,    1, 2153,    2, 0x08 /* Private */,
      93,    0, 2156,    2, 0x08 /* Private */,
      94,    0, 2157,    2, 0x08 /* Private */,
      95,    0, 2158,    2, 0x08 /* Private */,
      96,    0, 2159,    2, 0x08 /* Private */,
      97,    0, 2160,    2, 0x08 /* Private */,
      98,    0, 2161,    2, 0x08 /* Private */,
      99,    0, 2162,    2, 0x08 /* Private */,
     100,    0, 2163,    2, 0x08 /* Private */,
     101,    0, 2164,    2, 0x08 /* Private */,
     102,    0, 2165,    2, 0x08 /* Private */,
     103,    0, 2166,    2, 0x08 /* Private */,
     104,    0, 2167,    2, 0x08 /* Private */,
     105,    0, 2168,    2, 0x08 /* Private */,
     106,    0, 2169,    2, 0x08 /* Private */,
     107,    0, 2170,    2, 0x08 /* Private */,
     108,    0, 2171,    2, 0x08 /* Private */,
     109,    0, 2172,    2, 0x08 /* Private */,
     110,    0, 2173,    2, 0x08 /* Private */,
     111,    0, 2174,    2, 0x08 /* Private */,
     112,    0, 2175,    2, 0x08 /* Private */,
     113,    0, 2176,    2, 0x08 /* Private */,
     114,    0, 2177,    2, 0x08 /* Private */,
     115,    0, 2178,    2, 0x08 /* Private */,
     116,    0, 2179,    2, 0x08 /* Private */,
     117,    0, 2180,    2, 0x08 /* Private */,
     118,    0, 2181,    2, 0x08 /* Private */,
     119,    0, 2182,    2, 0x08 /* Private */,
     120,    0, 2183,    2, 0x08 /* Private */,
     121,    0, 2184,    2, 0x08 /* Private */,
     122,    0, 2185,    2, 0x08 /* Private */,
     123,    0, 2186,    2, 0x08 /* Private */,
     124,    0, 2187,    2, 0x08 /* Private */,
     125,    0, 2188,    2, 0x08 /* Private */,
     126,    0, 2189,    2, 0x08 /* Private */,
     127,    0, 2190,    2, 0x08 /* Private */,
     128,    1, 2191,    2, 0x08 /* Private */,
     129,    1, 2194,    2, 0x08 /* Private */,
     130,    0, 2197,    2, 0x08 /* Private */,
     131,    0, 2198,    2, 0x08 /* Private */,
     132,    0, 2199,    2, 0x08 /* Private */,
     133,    0, 2200,    2, 0x08 /* Private */,
     134,    0, 2201,    2, 0x08 /* Private */,
     135,    0, 2202,    2, 0x08 /* Private */,
     136,    0, 2203,    2, 0x08 /* Private */,
     137,    0, 2204,    2, 0x08 /* Private */,
     138,    0, 2205,    2, 0x08 /* Private */,
     139,    0, 2206,    2, 0x08 /* Private */,
     140,    0, 2207,    2, 0x08 /* Private */,
     141,    0, 2208,    2, 0x08 /* Private */,
     142,    0, 2209,    2, 0x08 /* Private */,
     143,    0, 2210,    2, 0x08 /* Private */,
     144,    0, 2211,    2, 0x08 /* Private */,
     145,    0, 2212,    2, 0x08 /* Private */,
     146,    0, 2213,    2, 0x08 /* Private */,
     147,    1, 2214,    2, 0x08 /* Private */,
     148,    0, 2217,    2, 0x08 /* Private */,
     149,    0, 2218,    2, 0x08 /* Private */,
     150,    1, 2219,    2, 0x08 /* Private */,
     151,    0, 2222,    2, 0x08 /* Private */,
     152,    1, 2223,    2, 0x08 /* Private */,
     153,    0, 2226,    2, 0x08 /* Private */,
     154,    0, 2227,    2, 0x08 /* Private */,
     155,    0, 2228,    2, 0x08 /* Private */,
     156,    0, 2229,    2, 0x08 /* Private */,
     157,    0, 2230,    2, 0x08 /* Private */,
     158,    0, 2231,    2, 0x08 /* Private */,
     159,    0, 2232,    2, 0x08 /* Private */,
     160,    0, 2233,    2, 0x08 /* Private */,
     161,    0, 2234,    2, 0x08 /* Private */,
     162,    0, 2235,    2, 0x08 /* Private */,
     163,    0, 2236,    2, 0x08 /* Private */,
     164,    0, 2237,    2, 0x08 /* Private */,
     165,    0, 2238,    2, 0x08 /* Private */,
     166,    0, 2239,    2, 0x08 /* Private */,
     167,    0, 2240,    2, 0x08 /* Private */,
     168,    0, 2241,    2, 0x08 /* Private */,
     169,    0, 2242,    2, 0x08 /* Private */,
     170,    0, 2243,    2, 0x08 /* Private */,
     171,    0, 2244,    2, 0x08 /* Private */,
     172,    0, 2245,    2, 0x08 /* Private */,
     173,    0, 2246,    2, 0x08 /* Private */,
     174,    0, 2247,    2, 0x08 /* Private */,
     175,    0, 2248,    2, 0x08 /* Private */,
     176,    0, 2249,    2, 0x08 /* Private */,
     177,    0, 2250,    2, 0x08 /* Private */,
     178,    0, 2251,    2, 0x08 /* Private */,
     179,    0, 2252,    2, 0x08 /* Private */,
     180,    0, 2253,    2, 0x08 /* Private */,
     181,    0, 2254,    2, 0x08 /* Private */,
     182,    0, 2255,    2, 0x08 /* Private */,
     183,    0, 2256,    2, 0x08 /* Private */,
     184,    1, 2257,    2, 0x08 /* Private */,
     185,    1, 2260,    2, 0x08 /* Private */,
     186,    0, 2263,    2, 0x08 /* Private */,
     187,    1, 2264,    2, 0x08 /* Private */,
     189,    0, 2267,    2, 0x08 /* Private */,
     190,    0, 2268,    2, 0x08 /* Private */,
     191,    0, 2269,    2, 0x08 /* Private */,
     192,    1, 2270,    2, 0x08 /* Private */,
     194,    1, 2273,    2, 0x08 /* Private */,
     196,    1, 2276,    2, 0x08 /* Private */,
     197,    1, 2279,    2, 0x08 /* Private */,
     199,    0, 2282,    2, 0x08 /* Private */,
     200,    1, 2283,    2, 0x08 /* Private */,
     201,    1, 2286,    2, 0x08 /* Private */,
     202,    1, 2289,    2, 0x08 /* Private */,
     203,    0, 2292,    2, 0x08 /* Private */,
     204,    1, 2293,    2, 0x08 /* Private */,
     205,    0, 2296,    2, 0x08 /* Private */,
     206,    1, 2297,    2, 0x08 /* Private */,
     207,    0, 2300,    2, 0x08 /* Private */,
     208,    0, 2301,    2, 0x08 /* Private */,
     209,    0, 2302,    2, 0x08 /* Private */,
     210,    0, 2303,    2, 0x08 /* Private */,
     211,    0, 2304,    2, 0x08 /* Private */,
     212,    0, 2305,    2, 0x08 /* Private */,
     213,    0, 2306,    2, 0x08 /* Private */,
     214,    0, 2307,    2, 0x08 /* Private */,
     215,    0, 2308,    2, 0x08 /* Private */,
     216,    0, 2309,    2, 0x08 /* Private */,
     217,    0, 2310,    2, 0x08 /* Private */,
     218,    0, 2311,    2, 0x08 /* Private */,
     219,    0, 2312,    2, 0x08 /* Private */,
     220,    1, 2313,    2, 0x08 /* Private */,
     221,    1, 2316,    2, 0x08 /* Private */,
     224,    1, 2319,    2, 0x08 /* Private */,
     226,    1, 2322,    2, 0x08 /* Private */,
     227,    1, 2325,    2, 0x08 /* Private */,
     228,    0, 2328,    2, 0x08 /* Private */,
     229,    0, 2329,    2, 0x08 /* Private */,
     230,    0, 2330,    2, 0x08 /* Private */,
     231,    0, 2331,    2, 0x08 /* Private */,
     232,    0, 2332,    2, 0x08 /* Private */,
     233,    0, 2333,    2, 0x08 /* Private */,
     234,    0, 2334,    2, 0x08 /* Private */,
     235,    0, 2335,    2, 0x08 /* Private */,
     236,    0, 2336,    2, 0x08 /* Private */,
     237,    0, 2337,    2, 0x08 /* Private */,
     238,    2, 2338,    2, 0x08 /* Private */,
     241,    0, 2343,    2, 0x08 /* Private */,
     242,    0, 2344,    2, 0x08 /* Private */,
     243,    0, 2345,    2, 0x08 /* Private */,
     244,    0, 2346,    2, 0x08 /* Private */,
     245,    0, 2347,    2, 0x08 /* Private */,
     246,    0, 2348,    2, 0x08 /* Private */,
     247,    0, 2349,    2, 0x08 /* Private */,
     248,    0, 2350,    2, 0x08 /* Private */,
     249,    1, 2351,    2, 0x08 /* Private */,
     250,    0, 2354,    2, 0x08 /* Private */,
     251,    1, 2355,    2, 0x08 /* Private */,
     252,    1, 2358,    2, 0x08 /* Private */,
     253,    1, 2361,    2, 0x08 /* Private */,
     254,    0, 2364,    2, 0x08 /* Private */,
     255,    0, 2365,    2, 0x08 /* Private */,
     256,    0, 2366,    2, 0x08 /* Private */,
     257,    0, 2367,    2, 0x08 /* Private */,
     258,    0, 2368,    2, 0x08 /* Private */,
     259,    0, 2369,    2, 0x08 /* Private */,
     260,    1, 2370,    2, 0x08 /* Private */,
     261,    0, 2373,    2, 0x08 /* Private */,
     262,    0, 2374,    2, 0x08 /* Private */,
     263,    0, 2375,    2, 0x08 /* Private */,
     264,    0, 2376,    2, 0x08 /* Private */,
     265,    0, 2377,    2, 0x08 /* Private */,
     266,    0, 2378,    2, 0x08 /* Private */,
     267,    0, 2379,    2, 0x08 /* Private */,
     268,    0, 2380,    2, 0x08 /* Private */,
     269,    0, 2381,    2, 0x08 /* Private */,
     270,    0, 2382,    2, 0x08 /* Private */,
     271,    0, 2383,    2, 0x08 /* Private */,
     272,    0, 2384,    2, 0x08 /* Private */,
     273,    0, 2385,    2, 0x08 /* Private */,
     274,    0, 2386,    2, 0x08 /* Private */,
     275,    0, 2387,    2, 0x08 /* Private */,
     276,    0, 2388,    2, 0x08 /* Private */,
     277,    0, 2389,    2, 0x08 /* Private */,
     278,    0, 2390,    2, 0x08 /* Private */,
     279,    1, 2391,    2, 0x08 /* Private */,
     280,    1, 2394,    2, 0x08 /* Private */,
     281,    1, 2397,    2, 0x08 /* Private */,
     282,    1, 2400,    2, 0x08 /* Private */,
     283,    1, 2403,    2, 0x08 /* Private */,
     284,    1, 2406,    2, 0x08 /* Private */,
     285,    1, 2409,    2, 0x08 /* Private */,
     286,    1, 2412,    2, 0x08 /* Private */,
     287,    1, 2415,    2, 0x08 /* Private */,
     288,    1, 2418,    2, 0x08 /* Private */,
     289,    1, 2421,    2, 0x08 /* Private */,
     290,    0, 2424,    2, 0x08 /* Private */,
     291,    0, 2425,    2, 0x08 /* Private */,
     292,    0, 2426,    2, 0x08 /* Private */,
     293,    0, 2427,    2, 0x08 /* Private */,
     294,    0, 2428,    2, 0x08 /* Private */,
     295,    0, 2429,    2, 0x08 /* Private */,
     296,    0, 2430,    2, 0x08 /* Private */,
     297,    0, 2431,    2, 0x08 /* Private */,
     298,    0, 2432,    2, 0x08 /* Private */,
     299,    0, 2433,    2, 0x08 /* Private */,
     300,    1, 2434,    2, 0x08 /* Private */,
     301,    0, 2437,    2, 0x08 /* Private */,
     302,    1, 2438,    2, 0x08 /* Private */,
     303,    0, 2441,    2, 0x08 /* Private */,
     304,    0, 2442,    2, 0x08 /* Private */,
     305,   21, 2443,    2, 0x08 /* Private */,
     323,    1, 2486,    2, 0x08 /* Private */,
     325,    1, 2489,    2, 0x08 /* Private */,
     327,    1, 2492,    2, 0x08 /* Private */,
     328,    0, 2495,    2, 0x08 /* Private */,
     329,    1, 2496,    2, 0x08 /* Private */,
     330,    1, 2499,    2, 0x08 /* Private */,
     331,    0, 2502,    2, 0x08 /* Private */,
     332,    1, 2503,    2, 0x08 /* Private */,
     334,    1, 2506,    2, 0x08 /* Private */,
     335,    0, 2509,    2, 0x08 /* Private */,
     336,    1, 2510,    2, 0x08 /* Private */,
     337,    0, 2513,    2, 0x08 /* Private */,
     338,    0, 2514,    2, 0x08 /* Private */,
     339,    0, 2515,    2, 0x08 /* Private */,
     340,    0, 2516,    2, 0x08 /* Private */,
     341,    1, 2517,    2, 0x08 /* Private */,
     342,    1, 2520,    2, 0x08 /* Private */,
     343,    0, 2523,    2, 0x08 /* Private */,
     344,    0, 2524,    2, 0x08 /* Private */,
     345,    0, 2525,    2, 0x08 /* Private */,
     346,    1, 2526,    2, 0x08 /* Private */,
     347,    0, 2529,    2, 0x08 /* Private */,
     348,    0, 2530,    2, 0x08 /* Private */,
     349,    0, 2531,    2, 0x08 /* Private */,
     350,    0, 2532,    2, 0x08 /* Private */,
     351,    0, 2533,    2, 0x08 /* Private */,
     352,    1, 2534,    2, 0x08 /* Private */,
     353,    1, 2537,    2, 0x08 /* Private */,
     354,    1, 2540,    2, 0x08 /* Private */,
     355,    1, 2543,    2, 0x08 /* Private */,
     356,    1, 2546,    2, 0x08 /* Private */,
     357,    1, 2549,    2, 0x08 /* Private */,
     358,    1, 2552,    2, 0x08 /* Private */,
     359,    1, 2555,    2, 0x08 /* Private */,
     360,    1, 2558,    2, 0x08 /* Private */,
     361,    1, 2561,    2, 0x08 /* Private */,
     362,    1, 2564,    2, 0x08 /* Private */,
     363,    1, 2567,    2, 0x08 /* Private */,
     364,    1, 2570,    2, 0x08 /* Private */,
     365,    1, 2573,    2, 0x08 /* Private */,
     366,    0, 2576,    2, 0x08 /* Private */,
     367,    0, 2577,    2, 0x08 /* Private */,
     368,    1, 2578,    2, 0x08 /* Private */,
     369,    1, 2581,    2, 0x08 /* Private */,
     370,    1, 2584,    2, 0x08 /* Private */,
     371,    1, 2587,    2, 0x08 /* Private */,
     372,    1, 2590,    2, 0x08 /* Private */,
     373,    2, 2593,    2, 0x08 /* Private */,
     373,    1, 2598,    2, 0x28 /* Private | MethodCloned */,
     373,    0, 2601,    2, 0x28 /* Private | MethodCloned */,
     376,    0, 2602,    2, 0x08 /* Private */,
     377,    1, 2603,    2, 0x08 /* Private */,
     379,    1, 2606,    2, 0x08 /* Private */,
     380,    1, 2609,    2, 0x08 /* Private */,
     381,    1, 2612,    2, 0x08 /* Private */,
     382,    1, 2615,    2, 0x08 /* Private */,
     383,    0, 2618,    2, 0x08 /* Private */,
     384,    0, 2619,    2, 0x08 /* Private */,
     385,    0, 2620,    2, 0x08 /* Private */,
     386,    0, 2621,    2, 0x08 /* Private */,
     387,    0, 2622,    2, 0x08 /* Private */,
     388,    0, 2623,    2, 0x08 /* Private */,
     389,    0, 2624,    2, 0x08 /* Private */,
     390,    1, 2625,    2, 0x08 /* Private */,
     391,    1, 2628,    2, 0x08 /* Private */,
     392,    1, 2631,    2, 0x08 /* Private */,
     393,    1, 2634,    2, 0x08 /* Private */,
     394,    1, 2637,    2, 0x08 /* Private */,
     395,    1, 2640,    2, 0x08 /* Private */,
     396,    0, 2643,    2, 0x08 /* Private */,
     397,    0, 2644,    2, 0x08 /* Private */,
     398,    0, 2645,    2, 0x08 /* Private */,
     399,    0, 2646,    2, 0x08 /* Private */,
     400,    1, 2647,    2, 0x08 /* Private */,
     401,    1, 2650,    2, 0x08 /* Private */,
     402,    1, 2653,    2, 0x08 /* Private */,
     403,    1, 2656,    2, 0x08 /* Private */,
     404,    1, 2659,    2, 0x08 /* Private */,
     405,    0, 2662,    2, 0x08 /* Private */,
     406,    0, 2663,    2, 0x08 /* Private */,
     407,    0, 2664,    2, 0x08 /* Private */,
     408,    1, 2665,    2, 0x08 /* Private */,
     409,    1, 2668,    2, 0x08 /* Private */,
     410,    0, 2671,    2, 0x08 /* Private */,
     411,    0, 2672,    2, 0x08 /* Private */,
     412,    0, 2673,    2, 0x08 /* Private */,
     413,    1, 2674,    2, 0x08 /* Private */,
     414,    1, 2677,    2, 0x08 /* Private */,
     415,    1, 2680,    2, 0x08 /* Private */,
     417,    9, 2683,    2, 0x08 /* Private */,
     426,    1, 2702,    2, 0x08 /* Private */,
     428,    0, 2705,    2, 0x08 /* Private */,
     429,    1, 2706,    2, 0x08 /* Private */,
     430,    1, 2709,    2, 0x08 /* Private */,
     432,    1, 2712,    2, 0x08 /* Private */,
     433,    1, 2715,    2, 0x08 /* Private */,
     435,    1, 2718,    2, 0x08 /* Private */,
     436,    1, 2721,    2, 0x08 /* Private */,
     437,    1, 2724,    2, 0x08 /* Private */,
     438,    0, 2727,    2, 0x08 /* Private */,
     439,    0, 2728,    2, 0x08 /* Private */,
     440,    0, 2729,    2, 0x08 /* Private */,
     441,    0, 2730,    2, 0x08 /* Private */,
     442,    1, 2731,    2, 0x08 /* Private */,
     443,    1, 2734,    2, 0x08 /* Private */,
     444,    1, 2737,    2, 0x08 /* Private */,
     445,    1, 2740,    2, 0x08 /* Private */,
     446,    1, 2743,    2, 0x08 /* Private */,
     447,    0, 2746,    2, 0x08 /* Private */,
     448,    0, 2747,    2, 0x08 /* Private */,
     449,    0, 2748,    2, 0x08 /* Private */,
     450,    0, 2749,    2, 0x08 /* Private */,
     451,    0, 2750,    2, 0x08 /* Private */,
     452,    0, 2751,    2, 0x08 /* Private */,
     453,    0, 2752,    2, 0x08 /* Private */,
     454,    0, 2753,    2, 0x08 /* Private */,
     455,    0, 2754,    2, 0x08 /* Private */,
     456,    0, 2755,    2, 0x08 /* Private */,
     457,    0, 2756,    2, 0x08 /* Private */,
     458,    0, 2757,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt, QMetaType::UInt,    2,    4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 9, QMetaType::UInt, 0x80000000 | 12,    2,    8,   10,   11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 29, 0x80000000 | 12, QMetaType::Bool, QMetaType::Bool, QMetaType::Double, QMetaType::Int,   24,   25,   26,   27,   28,    2,    2,   30,   31,   32,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 29, 0x80000000 | 12, QMetaType::Bool, QMetaType::Bool, QMetaType::Double,   24,   25,   26,   27,   28,    2,    2,   30,   31,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 29, 0x80000000 | 12, QMetaType::Bool, QMetaType::Bool,   24,   25,   26,   27,   28,    2,    2,   30,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 29, 0x80000000 | 12, QMetaType::Bool,   24,   25,   26,   27,   28,    2,    2,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 29, 0x80000000 | 12,   24,   25,   26,   27,   28,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 29,   24,   25,   26,   27,   28,    2,
    QMetaType::Void, QMetaType::QReal,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::LongLong,   39,
    QMetaType::Void, QMetaType::LongLong, 0x80000000 | 41,   39,   42,
    QMetaType::Void, QMetaType::LongLong,   39,
    QMetaType::Void, QMetaType::LongLong,   45,
    QMetaType::Void, 0x80000000 | 47, 0x80000000 | 29,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   53,
    QMetaType::Void, QMetaType::LongLong,   55,
    QMetaType::Void, QMetaType::LongLong,   55,
    QMetaType::Void, QMetaType::Bool,   58,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 64,    2,
    QMetaType::Void, 0x80000000 | 64,    2,
    QMetaType::Void, 0x80000000 | 64,    2,
    QMetaType::Void, 0x80000000 | 64,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 72,   61,   73,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   75,   76,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   79,   80,   81,
    QMetaType::Void, QMetaType::Double,   83,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QString,   87,   88,   89,   90,
    QMetaType::Void, QMetaType::Bool,   92,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,    2,
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
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
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
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  193,
    QMetaType::Void, QMetaType::Int,  195,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Bool,  198,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  198,
    QMetaType::Void, QMetaType::Bool,  198,
    QMetaType::Void, QMetaType::Bool,  198,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  198,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  198,
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
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, 0x80000000 | 222,  223,
    QMetaType::Void, 0x80000000 | 225,  223,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
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
    QMetaType::Void, QMetaType::QString, QMetaType::Int,  239,  240,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  193,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   92,
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
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Int,   61,
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
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, 0x80000000 | 72, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,    2,   87,   90,  306,   24,  307,  308,  309,  310,  311,  312,  313,  314,  315,  316,  317,  318,  319,  320,  321,  322,
    QMetaType::Void, QMetaType::Int,  324,
    QMetaType::Void, QMetaType::QString,  326,
    QMetaType::Void, QMetaType::Int,  324,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 333,    2,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 72,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,  374,  375,
    QMetaType::Void, QMetaType::Bool,  374,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  378,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::Int,  324,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  326,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Bool, QMetaType::QString,  416,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString, QMetaType::Bool, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   24,  418,  419,  420,  421,  422,  423,  424,  425,
    QMetaType::Void, QMetaType::Int,  427,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  326,
    QMetaType::Void, QMetaType::QString,  431,
    QMetaType::Void, QMetaType::QString,  431,
    QMetaType::Void, QMetaType::Bool,  434,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  188,
    QMetaType::Void, QMetaType::Int,  324,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,   61,
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

 // enums: name, alias, flags, count, data
      41,   41, 0x2,    6, 2763,

 // enum data: key, value
     459, uint(MainWindow::JttyTxRejectReason::Empty),
     460, uint(MainWindow::JttyTxRejectReason::EncodingFailed),
     461, uint(MainWindow::JttyTxRejectReason::QueueFull),
     462, uint(MainWindow::JttyTxRejectReason::BackendRejected),
     463, uint(MainWindow::JttyTxRejectReason::Aborted),
     464, uint(MainWindow::JttyTxRejectReason::NotAvailable),

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initializeAudioOutputStream((*reinterpret_cast< QAudioDeviceInfo(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 1: _t->stopAudioOutputStream(); break;
        case 2: _t->startAudioInputStream((*reinterpret_cast< const QAudioDeviceInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< AudioDevice*(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< AudioDevice::Channel(*)>(_a[5]))); break;
        case 3: _t->suspendAudioInputStream(); break;
        case 4: _t->resumeAudioInputStream(); break;
        case 5: _t->startDetector((*reinterpret_cast< AudioDevice::Channel(*)>(_a[1]))); break;
        case 6: _t->FFTSize((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: _t->detectorClose(); break;
        case 8: _t->finished(); break;
        case 9: _t->transmitFrequency((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->endTransmitMessage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->endTransmitMessage(); break;
        case 12: _t->tune((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->tune(); break;
        case 14: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< AudioDevice::Channel(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11]))); break;
        case 15: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< AudioDevice::Channel(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10]))); break;
        case 16: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< AudioDevice::Channel(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9]))); break;
        case 17: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< AudioDevice::Channel(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8]))); break;
        case 18: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< AudioDevice::Channel(*)>(_a[7]))); break;
        case 19: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6]))); break;
        case 20: _t->outAttenuationChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 21: _t->toggleShorthand(); break;
        case 22: _t->reset_audio_input_stream((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->jttyTextAccepted((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 24: _t->jttyTextRejected((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< JttyTxRejectReason(*)>(_a[2]))); break;
        case 25: _t->jttyTextCompleted((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 26: _t->jttySessionDrained((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 27: _t->startJttyStream((*reinterpret_cast< TxEvidence::TxRequest(*)>(_a[1])),(*reinterpret_cast< SoundOutput*(*)>(_a[2]))); break;
        case 28: _t->endJttyStream(); break;
        case 29: _t->showSoundInError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->showSoundOutError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->showStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->dataSink((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 33: _t->fastSink((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 34: _t->tci_mod_active((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->diskDat(); break;
        case 36: _t->freezeDecode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->guiUpdate(); break;
        case 38: _t->doubleClickOnCall((*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[1]))); break;
        case 39: _t->doubleClickOnCall2((*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[1]))); break;
        case 40: _t->doubleClickOnFoxQueue((*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[1]))); break;
        case 41: _t->doubleClickOnFoxInProgress((*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[1]))); break;
        case 42: _t->readFromStdout(); break;
        case 43: _t->p1ReadFromStdout(); break;
        case 44: _t->setXIT((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Frequency(*)>(_a[2]))); break;
        case 45: _t->setXIT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->setFreq4((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 47: _t->msgAvgDecode2(); break;
        case 48: _t->fastPick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 49: _t->skedFreq((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 50: _t->initialize_fonts(); break;
        case 51: _t->ScrollBarPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->overlayCallsignClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 53: _t->on_actionUse_Dark_Style_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->on_actionBand_Buttons_triggered(); break;
        case 55: _t->on_actionVHF_UHF_Buttons_triggered(); break;
        case 56: _t->on_pb160_clicked(); break;
        case 57: _t->on_pb80_clicked(); break;
        case 58: _t->on_pb60_clicked(); break;
        case 59: _t->on_pb40_clicked(); break;
        case 60: _t->on_pb30_clicked(); break;
        case 61: _t->on_pb20_clicked(); break;
        case 62: _t->on_pb17_clicked(); break;
        case 63: _t->on_pb15_clicked(); break;
        case 64: _t->on_pb12_clicked(); break;
        case 65: _t->on_pb10_clicked(); break;
        case 66: _t->on_pb8_clicked(); break;
        case 67: _t->on_pb6_clicked(); break;
        case 68: _t->on_pb2_clicked(); break;
        case 69: _t->on_pb70_clicked(); break;
        case 70: _t->on_pb50_clicked(); break;
        case 71: _t->on_pb4_clicked(); break;
        case 72: _t->on_pb144_clicked(); break;
        case 73: _t->on_pb220_clicked(); break;
        case 74: _t->on_pb432_clicked(); break;
        case 75: _t->on_pb902_clicked(); break;
        case 76: _t->on_pb23_clicked(); break;
        case 77: _t->on_pb13_clicked(); break;
        case 78: _t->on_pb9_clicked(); break;
        case 79: _t->on_pb5G_clicked(); break;
        case 80: _t->on_pb10G_clicked(); break;
        case 81: _t->on_pb24G_clicked(); break;
        case 82: _t->check_band_limits(); break;
        case 83: _t->check_msk144_TRperiod(); break;
        case 84: _t->check_button_color(); break;
        case 85: _t->stopWRTimeout(); break;
        case 86: _t->stopWCTimeout(); break;
        case 87: _t->bandHoppingTimer(); break;
        case 88: _t->bandHopping(); break;
        case 89: _t->on_houndButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 90: _t->on_cbHoldTxFreq_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 91: _t->on_ft8Button_clicked(); break;
        case 92: _t->on_ft4Button_clicked(); break;
        case 93: _t->on_ft2Button_clicked(); break;
        case 94: _t->on_msk144Button_clicked(); break;
        case 95: _t->on_q65Button_clicked(); break;
        case 96: _t->on_jt65Button_clicked(); break;
        case 97: _t->on_echoButton_clicked(); break;
        case 98: _t->on_pb15A_clicked(); break;
        case 99: _t->on_pb15C_clicked(); break;
        case 100: _t->on_pb30B_clicked(); break;
        case 101: _t->on_pb60C_clicked(); break;
        case 102: _t->on_pb60D_clicked(); break;
        case 103: _t->on_pb60E_clicked(); break;
        case 104: _t->on_tx1_editingFinished(); break;
        case 105: _t->on_tx2_editingFinished(); break;
        case 106: _t->on_tx3_editingFinished(); break;
        case 107: _t->on_tx4_editingFinished(); break;
        case 108: _t->on_tx5_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 109: _t->on_tx6_editingFinished(); break;
        case 110: _t->on_actionSettings_triggered(); break;
        case 111: _t->on_monitorButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 112: _t->on_actionAbout_triggered(); break;
        case 113: _t->on_autoButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 114: _t->on_stopTxButton_clicked(); break;
        case 115: _t->on_stopButton_clicked(); break;
        case 116: _t->on_pbBandHopping_clicked(); break;
        case 117: _t->on_actionAccept_QMAP_click_events_triggered(); break;
        case 118: _t->on_actionRelease_Notes_triggered(); break;
        case 119: _t->on_actionWS_Home_Page_triggered(); break;
        case 120: _t->on_actionWSJT_X_User_Guide_triggered(); break;
        case 121: _t->on_actionFT8_DXpedition_Mode_User_Guide_triggered(); break;
        case 122: _t->on_actionSuperFox_User_Guide_triggered(); break;
        case 123: _t->on_actionQSG_FST4_triggered(); break;
        case 124: _t->on_actionQSG_Q65_triggered(); break;
        case 125: _t->on_actionQSG_X250_M3_triggered(); break;
        case 126: _t->on_actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP_triggered(); break;
        case 127: _t->on_actionDownload_EME_Ephemeris_Chart_triggered(); break;
        case 128: _t->on_actionKeyboard_shortcuts_triggered(); break;
        case 129: _t->on_actionSpecial_mouse_commands_triggered(); break;
        case 130: _t->on_actionRecommended_Audio_Settings_triggered(); break;
        case 131: _t->on_actionRig_Control_Errors_triggered(); break;
        case 132: _t->on_actionCopyright_Notice_triggered(); break;
        case 133: _t->on_actionSolve_FreqCal_triggered(); break;
        case 134: _t->on_actionWide_Waterfall_triggered(); break;
        case 135: _t->on_actionOpen_triggered(); break;
        case 136: _t->on_actionOpen_next_in_directory_triggered(); break;
        case 137: _t->on_actionDecode_remaining_files_in_directory_triggered(); break;
        case 138: _t->on_actionDelete_all_wav_files_in_SaveDir_triggered(); break;
        case 139: _t->on_actionOpen_log_directory_triggered(); break;
        case 140: _t->on_actionNone_triggered(); break;
        case 141: _t->on_actionSave_all_triggered(); break;
        case 142: _t->on_actionDefault_event_logging_triggered(); break;
        case 143: _t->on_actionDiagnostic_mode_triggered(); break;
        case 144: _t->on_actionDisable_event_logging_triggered(); break;
        case 145: _t->on_actionSWL_Mode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 146: _t->on_DecodeButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 147: _t->decode(); break;
        case 148: _t->decodeBusy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 149: _t->on_EraseButton_clicked(); break;
        case 150: _t->band_activity_cleared(); break;
        case 151: _t->rx_frequency_activity_cleared(); break;
        case 152: _t->on_txFirstCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 153: _t->set_dateTimeQSO((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 154: _t->set_ntx((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 155: _t->on_txrb1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 156: _t->on_txrb1_doubleClicked(); break;
        case 157: _t->on_txrb2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 158: _t->on_txrb3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 159: _t->on_txrb4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 160: _t->on_txrb4_doubleClicked(); break;
        case 161: _t->on_txrb5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 162: _t->on_txrb5_doubleClicked(); break;
        case 163: _t->on_txrb6_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 164: _t->on_txb1_clicked(); break;
        case 165: _t->on_txb1_doubleClicked(); break;
        case 166: _t->on_txb2_clicked(); break;
        case 167: _t->on_txb3_clicked(); break;
        case 168: _t->on_txb4_clicked(); break;
        case 169: _t->on_txb4_doubleClicked(); break;
        case 170: _t->on_txb5_clicked(); break;
        case 171: _t->on_txb5_doubleClicked(); break;
        case 172: _t->on_txb6_clicked(); break;
        case 173: _t->on_lookupButton_clicked(); break;
        case 174: _t->on_addButton_clicked(); break;
        case 175: _t->on_ignoreButton_clicked(); break;
        case 176: _t->on_comboBoxCQ_activated(); break;
        case 177: _t->on_DX_Call_Button_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 178: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 179: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 180: _t->on_dxCallEntry_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 181: _t->on_dxGridEntry_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 182: _t->on_dxCallEntry_editingFinished(); break;
        case 183: _t->on_dxCallEntry_returnPressed(); break;
        case 184: _t->on_genStdMsgsPushButton_clicked(); break;
        case 185: _t->on_logQSOButton_clicked(); break;
        case 186: _t->read_txLog(); break;
        case 187: _t->on_actionErase_Tx_Log_triggered(); break;
        case 188: _t->read_ignoreList(); break;
        case 189: _t->addCallsignToignoreList(); break;
        case 190: _t->on_actionErase_Ignore_List_triggered(); break;
        case 191: _t->read_ALLCALL7(); break;
        case 192: _t->remove_old_files((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 193: _t->on_actionJT9_triggered(); break;
        case 194: _t->on_actionJT65_triggered(); break;
        case 195: _t->on_actionJT4_triggered(); break;
        case 196: _t->on_actionFT2_triggered(); break;
        case 197: _t->on_actionFT4_triggered(); break;
        case 198: _t->on_actionFT8_triggered(); break;
        case 199: _t->on_actionFST4_triggered(); break;
        case 200: _t->on_actionFST4W_triggered(); break;
        case 201: _t->on_TxFreqSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 202: _t->on_actionSave_decoded_triggered(); break;
        case 203: _t->on_actionQuickDecode_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 204: _t->on_actionMediumDecode_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 205: _t->on_actionDeepestDecode_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 206: _t->on_actionDecFT8cycles1_triggered(); break;
        case 207: _t->on_actionDecFT8cycles2_triggered(); break;
        case 208: _t->on_actionDecFT8cycles3_triggered(); break;
        case 209: _t->on_actionRXfLow_triggered(); break;
        case 210: _t->on_actionRXfMedium_triggered(); break;
        case 211: _t->on_actionRXfHigh_triggered(); break;
        case 212: _t->on_actionClaimQmapClicks_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 213: _t->on_actionQmapSourceAuto_triggered(); break;
        case 214: _t->on_actionQmapSource1_triggered(); break;
        case 215: _t->on_actionQmapSource2_triggered(); break;
        case 216: _t->on_actionQmapSource3_triggered(); break;
        case 217: _t->on_actionQmapSource4_triggered(); break;
        case 218: _t->on_actionMTAuto_triggered(); break;
        case 219: _t->on_actionMT1_triggered(); break;
        case 220: _t->on_actionMT2_triggered(); break;
        case 221: _t->on_actionMT3_triggered(); break;
        case 222: _t->on_actionMT4_triggered(); break;
        case 223: _t->on_actionMT5_triggered(); break;
        case 224: _t->on_actionMT6_triggered(); break;
        case 225: _t->on_actionMT7_triggered(); break;
        case 226: _t->on_actionMT8_triggered(); break;
        case 227: _t->on_actionMT9_triggered(); break;
        case 228: _t->on_actionMT10_triggered(); break;
        case 229: _t->on_actionMT11_triggered(); break;
        case 230: _t->on_actionMT12_triggered(); break;
        case 231: _t->on_actionFT8SensMin_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 232: _t->on_actionlowFT8thresholds_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 233: _t->on_actionFT8subpass_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 234: _t->on_actionStartTwoStage_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 235: _t->on_actionStartThreeStage_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 236: _t->on_actionStartEarly_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 237: _t->on_actionStartNormal_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 238: _t->on_actionStartLate_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 239: _t->on_actionFT8WidebandDXCallSearch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 240: _t->on_actionUse_multithreaded_FT8_decoder_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 241: _t->bumpFqso((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 242: _t->on_actionErase_ALL_TXT_triggered(); break;
        case 243: _t->on_reset_cabrillo_log_action_triggered(); break;
        case 244: _t->on_actionErase_wsjtx_log_adi_triggered(); break;
        case 245: _t->on_actionErase_WSPR_hashtable_triggered(); break;
        case 246: _t->on_actionErase_list_of_Q65_callers_triggered(); break;
        case 247: _t->on_actionExport_Cabrillo_log_triggered(); break;
        case 248: _t->startTx2(); break;
        case 249: _t->startP1(); break;
        case 250: _t->stopTx(); break;
        case 251: _t->stopTx2(); break;
        case 252: _t->on_rptSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 253: _t->killFile(); break;
        case 254: _t->on_tuneButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 255: _t->on_pbR2T_clicked(); break;
        case 256: _t->on_pbT2R_clicked(); break;
        case 257: _t->acceptQSO((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< Frequency(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QDateTime(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16])),(*reinterpret_cast< const QString(*)>(_a[17])),(*reinterpret_cast< const QString(*)>(_a[18])),(*reinterpret_cast< const QString(*)>(_a[19])),(*reinterpret_cast< const QString(*)>(_a[20])),(*reinterpret_cast< const QByteArray(*)>(_a[21]))); break;
        case 258: _t->on_bandComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 259: _t->on_bandComboBox_editTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 260: _t->on_bandComboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 261: _t->on_readFreq_clicked(); break;
        case 262: _t->on_RxFreqSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 263: _t->on_outAttenuation_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 264: _t->rigOpen(); break;
        case 265: _t->handle_transceiver_update((*reinterpret_cast< const Transceiver::TransceiverState(*)>(_a[1]))); break;
        case 266: _t->handle_transceiver_failure((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 267: _t->handle_leavingSettings(); break;
        case 268: _t->on_actionAstronomical_data_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 269: _t->on_actionQSYMessage_Creator_triggered(); break;
        case 270: _t->on_actionQSY_Monitor_triggered(); break;
        case 271: _t->alertQSYmessage(); break;
        case 272: _t->on_actionShort_list_of_add_on_prefixes_and_suffixes_triggered(); break;
        case 273: _t->band_changed((*reinterpret_cast< Frequency(*)>(_a[1]))); break;
        case 274: _t->monitor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 275: _t->end_tuning(); break;
        case 276: _t->stop_tuning(); break;
        case 277: _t->stopTuneATU(); break;
        case 278: _t->auto_tx_mode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 279: _t->on_actionMessage_averaging_triggered(); break;
        case 280: _t->on_actionActiveStations_triggered(); break;
        case 281: _t->on_contest_log_action_triggered(); break;
        case 282: _t->on_fox_log_action_triggered(); break;
        case 283: _t->on_actionColors_triggered(); break;
        case 284: _t->on_actionInclude_averaging_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 285: _t->on_actionInclude_correlation_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 286: _t->on_actionEnable_AP_DXcall_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 287: _t->on_actionAuto_Clear_Avg_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 288: _t->VHF_features_enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 289: _t->on_sbSubmode_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 290: _t->on_cbSendMsg_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 291: _t->on_cbShMsgs_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 292: _t->on_cbSWL_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 293: _t->on_cbTx6_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 294: _t->on_cbMenus_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 295: _t->on_cbCQonly_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 296: _t->on_cbAutoSeq_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 297: _t->networkError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 298: _t->on_ClrAvgButton_clicked(); break;
        case 299: _t->on_actionWSPR_triggered(); break;
        case 300: _t->on_syncSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 301: _t->on_TxPowerComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 302: _t->on_sbTxPercent_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 303: _t->on_cbUploadWSPR_Spots_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 304: _t->WSPR_config((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 305: _t->uploadWSPRSpots((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 306: _t->uploadWSPRSpots((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 307: _t->uploadWSPRSpots(); break;
        case 308: _t->TxAgain(); break;
        case 309: _t->uploadResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 310: _t->on_WSPRfreqSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 311: _t->on_sbFST4W_RxFreq_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 312: _t->on_sbFST4W_FTol_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 313: _t->on_pbTxNext_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 314: _t->on_actionEcho_Graph_triggered(); break;
        case 315: _t->on_actionEcho_triggered(); break;
        case 316: _t->on_actionFast_Graph_triggered(); break;
        case 317: _t->fast_decode_done(); break;
        case 318: _t->on_actionMeasure_reference_spectrum_triggered(); break;
        case 319: _t->on_actionErase_reference_spectrum_triggered(); break;
        case 320: _t->on_actionMeasure_phase_response_triggered(); break;
        case 321: _t->on_sbTR_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 322: _t->on_sbTR_FST4W_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 323: _t->on_sbFtol_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 324: _t->on_cbFast9_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 325: _t->on_sbCQTxFreq_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 326: _t->on_cbCQTx_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 327: _t->on_actionMSK144_triggered(); break;
        case 328: _t->on_actionQ65_triggered(); break;
        case 329: _t->on_actionFreqCal_triggered(); break;
        case 330: _t->splash_done(); break;
        case 331: _t->on_measure_check_box_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 332: _t->on_sbNlist_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 333: _t->on_sbNslots_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 334: _t->on_sbF_Low_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 335: _t->on_sbF_High_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 336: _t->chk_FST4_freq_range(); break;
        case 337: _t->on_pbFoxReset_clicked(); break;
        case 338: _t->on_pbFreeText_clicked(); break;
        case 339: _t->FoxReset((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 340: _t->on_comboBoxHoundSort_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 341: _t->not_GA_warning_message(); break;
        case 342: _t->checkMSK144ContestType(); break;
        case 343: _t->on_pbBestSP_clicked(); break;
        case 344: _t->on_RoundRobin_currentTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 345: _t->setTxMsg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 346: { bool _r = _t->stdCall((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 347: _t->remote_configure((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9]))); break;
        case 348: _t->callSandP2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 349: _t->refreshHoundQueueDisplay(); break;
        case 350: _t->queueActiveWindowHound2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 351: _t->update_tx5((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 352: _t->reply_tx5((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 353: _t->setQSYMessageCreatorStatus((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 354: _t->on_rbFixedTone_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 355: _t->on_rbEchoMessage_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 356: _t->on_rbEchoCW_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 357: _t->on_leEchoMessage_textChanged(); break;
        case 358: _t->ARRL_Digi_Display(); break;
        case 359: _t->on_actionJTTY_triggered(); break;
        case 360: _t->on_actionRTTY_triggered(); break;
        case 361: _t->on_cbIncludeTime_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 362: _t->on_comboBoxJttyStyle_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 363: _t->on_RxFreqSpinBox_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 364: _t->on_TxFreqSpinBox_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 365: _t->on_sbFtol_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 366: _t->on_pbR2T_2_clicked(); break;
        case 367: _t->on_pbT2R_2_clicked(); break;
        case 368: _t->on_pbSendMessage_clicked(); break;
        case 369: _t->on_Tx_Message_returnPressed(); break;
        case 370: _t->on_pbF1_clicked(); break;
        case 371: _t->on_pbF2_clicked(); break;
        case 372: _t->on_pbF3_clicked(); break;
        case 373: _t->on_pbF4_clicked(); break;
        case 374: _t->on_pbF5_clicked(); break;
        case 375: _t->on_pbF6_clicked(); break;
        case 376: _t->on_pbF7_clicked(); break;
        case 377: _t->on_pbF8_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioDeviceInfo >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioDevice::Channel >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioDeviceInfo >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioDevice::Channel >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 6:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioDevice::Channel >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 6:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioDevice::Channel >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 6:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioDevice::Channel >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 6:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioDevice::Channel >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 6:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioDevice::Channel >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxEvidence::TxRequest >(); break;
            }
            break;
        case 265:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Transceiver::TransceiverState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QAudioDeviceInfo , unsigned  , unsigned  ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initializeAudioOutputStream)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::stopAudioOutputStream)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QAudioDeviceInfo const & , int , AudioDevice * , unsigned  , AudioDevice::Channel ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startAudioInputStream)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::suspendAudioInputStream)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::resumeAudioInputStream)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(AudioDevice::Channel ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startDetector)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(unsigned  ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::FFTSize)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::detectorClose)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::finished)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(double ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::transmitFrequency)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::endTransmitMessage)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::tune)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , unsigned  , double , double , double , SoundOutput * , AudioDevice::Channel , bool , bool , double , int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendMessage)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(qreal ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::outAttenuationChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::toggleShorthand)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::reset_audio_input_stream)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(qint64 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::jttyTextAccepted)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(qint64 , JttyTxRejectReason ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::jttyTextRejected)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(qint64 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::jttyTextCompleted)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(qint64 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::jttySessionDrained)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(TxEvidence::TxRequest , SoundOutput * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startJttyStream)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::endJttyStream)) {
                *result = 28;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<MultiGeometryWidget<3,QMainWindow>::staticMetaObject>(),
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
    return MultiGeometryWidget<3,QMainWindow>::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MultiGeometryWidget<3,QMainWindow>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 378)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 378;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 378)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 378;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::initializeAudioOutputStream(QAudioDeviceInfo _t1, unsigned  _t2, unsigned  _t3)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::stopAudioOutputStream()const
{
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::startAudioInputStream(QAudioDeviceInfo const & _t1, int _t2, AudioDevice * _t3, unsigned  _t4, AudioDevice::Channel _t5)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::suspendAudioInputStream()const
{
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::resumeAudioInputStream()const
{
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::startDetector(AudioDevice::Channel _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::FFTSize(unsigned  _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::detectorClose()const
{
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainWindow::finished()const
{
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MainWindow::transmitFrequency(double _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::endTransmitMessage(bool _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 10, _a);
}

// SIGNAL 12
void MainWindow::tune(bool _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 12, _a);
}

// SIGNAL 14
void MainWindow::sendMessage(QString _t1, unsigned  _t2, double _t3, double _t4, double _t5, SoundOutput * _t6, AudioDevice::Channel _t7, bool _t8, bool _t9, double _t10, int _t11)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 14, _a);
}

// SIGNAL 20
void MainWindow::outAttenuationChanged(qreal _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainWindow::toggleShorthand()const
{
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void MainWindow::reset_audio_input_stream(bool _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainWindow::jttyTextAccepted(qint64 _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 23, _a);
}

// SIGNAL 24
void MainWindow::jttyTextRejected(qint64 _t1, JttyTxRejectReason _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 24, _a);
}

// SIGNAL 25
void MainWindow::jttyTextCompleted(qint64 _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 25, _a);
}

// SIGNAL 26
void MainWindow::jttySessionDrained(qint64 _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 26, _a);
}

// SIGNAL 27
void MainWindow::startJttyStream(TxEvidence::TxRequest _t1, SoundOutput * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void MainWindow::endJttyStream()const
{
    QMetaObject::activate(const_cast< MainWindow *>(this), &staticMetaObject, 28, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
