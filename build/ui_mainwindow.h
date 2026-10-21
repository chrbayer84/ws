/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgets/BandComboBox.hpp"
#include "widgets/DoubleClickablePushButton.hpp"
#include "widgets/DoubleClickableRadioButton.hpp"
#include "widgets/HintedSpinBox.hpp"
#include "widgets/LettersSpinBox.hpp"
#include "widgets/RestrictedSpinBox.hpp"
#include "widgets/displaytext.h"
#include "widgets/signalmeter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionWide_Waterfall;
    QAction *actionOpen;
    QAction *actionOpen_next_in_directory;
    QAction *actionDecode_remaining_files_in_directory;
    QAction *actionDelete_all_wav_files_in_SaveDir;
    QAction *actionQuickDecode;
    QAction *actionNone;
    QAction *actionSave_all;
    QAction *actionRemove_after_30days;
    QAction *actionWSJT_X_User_Guide;
    QAction *actionKeyboard_shortcuts;
    QAction *actionSpecial_mouse_commands;
    QAction *actionJT9;
    QAction *actionSave_decoded;
    QAction *actionMediumDecode;
    QAction *actionDeepestDecode;
    QAction *actionErase_ALL_TXT;
    QAction *actionErase_wsjtx_log_adi;
    QAction *actionErase_Tx_Log;
    QAction *actionErase_Ignore_List;
    QAction *actionJT65;
    QAction *actionAstronomical_data;
    QAction *actionShort_list_of_add_on_prefixes_and_suffixes;
    QAction *actionSettings;
    QAction *actionLocal_User_Guide;
    QAction *actionOpen_log_directory;
    QAction *actionJT4;
    QAction *actionMessage_averaging;
    QAction *actionInclude_averaging;
    QAction *actionInclude_correlation;
    QAction *actionWSPR;
    QAction *actionEcho_Graph;
    QAction *actionEcho;
    QAction *actionISCAT;
    QAction *actionFast_Graph;
    QAction *download_samples_action;
    QAction *actionMSK144;
    QAction *actionQRA64;
    QAction *actionRelease_Notes;
    QAction *actionEnable_AP_DXcall;
    QAction *actionFreqCal;
    QAction *actionMeasure_reference_spectrum;
    QAction *actionMeasure_phase_response;
    QAction *actionErase_reference_spectrum;
    QAction *actionFrequency_calibration;
    QAction *view_phase_response_action;
    QAction *actionFT8;
    QAction *actionEnable_AP_FT8;
    QAction *actionEnable_AP_JT65;
    QAction *actionSolve_FreqCal;
    QAction *actionCopyright_Notice;
    QAction *fox_log_action;
    QAction *actionFT8_DXpedition_Mode_User_Guide;
    QAction *reset_cabrillo_log_action;
    QAction *actionColors;
    QAction *actionExport_Cabrillo_log;
    QAction *actionQSG_FST4;
    QAction *contest_log_action;
    QAction *actionErase_WSPR_hashtable;
    QAction *actionFT4;
    QAction *actionFST4;
    QAction *actionFST4W;
    QAction *actionQ65;
    QAction *actionSWL_Mode;
    QAction *actionQSG_Q65;
    QAction *actionAuto_Clear_Avg;
    QAction *actionQSG_X250_M3;
    QAction *actionDon_t_split_ALL_TXT;
    QAction *actionSplit_ALL_TXT_yearly;
    QAction *actionSplit_ALL_TXT_monthly;
    QAction *actionDisable_writing_of_ALL_TXT;
    QAction *actionActiveStations;
    QAction *actionBand_Buttons;
    QAction *actionUse_Dark_Style;
    QAction *actionCallsign_overlay_enabled;
    QAction *actionCallsign_persist_1;
    QAction *actionCallsign_persist_2;
    QAction *actionCallsign_persist_3;
    QAction *actionCallsign_persist_4;
    QAction *actionCallsign_persist_5;
    QAction *actionCallsign_font_small;
    QAction *actionCallsign_font_normal;
    QAction *actionCallsign_font_medium;
    QAction *actionCallsign_font_large;
    QAction *actionCallsign_position_top;
    QAction *actionCallsign_position_bottom;
    QAction *actionCallsign_transparency_None;
    QAction *actionCallsign_transparency_Low;
    QAction *actionCallsign_transparency_Medium;
    QAction *actionCallsign_transparency_High;
    QAction *actionReduce_false_decodes;
    QAction *actionDefault_event_logging;
    QAction *actionDiagnostic_mode;
    QAction *actionDisable_event_logging;
    QAction *actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP;
    QAction *actionWS_Home_Page;
    QAction *actionThe_additional_features_of_wsjt_x_improved;
    QAction *actionRecommended_Audio_Settings;
    QAction *actionRig_Control_Errors;
    QAction *actionErase_list_of_Q65_callers;
    QAction *actionSuperFox_User_Guide;
    QAction *actionQSYMessage_Creator;
    QAction *actionHideB4;
    QAction *actionHideToday;
    QAction *actionHideIgnored;
    QAction *actionIgnoreToday;
    QAction *actionIgnoreIgnored;
    QAction *actionHideTerritory1;
    QAction *actionHideTerritory2;
    QAction *actionHideTerritory3;
    QAction *actionHideTerritory4;
    QAction *actionHideEU;
    QAction *actionHideNA;
    QAction *actionHideSA;
    QAction *actionHideAS;
    QAction *actionHideAF;
    QAction *actionHideOC;
    QAction *actionHideAN;
    QAction *actionFull_Duplex_Mode;
    QAction *actionHighlightB4;
    QAction *actionHighlightToday;
    QAction *actionHighlightIgnored;
    QAction *actionEnable_QSY_Popups;
    QAction *actionQSY_Monitor;
    QAction *actionIgnoreB4;
    QAction *actionUse_multithreaded_FT8_decoder;
    QAction *actionMTAuto;
    QAction *actionMT1;
    QAction *actionMT2;
    QAction *actionMT3;
    QAction *actionMT4;
    QAction *actionMT5;
    QAction *actionMT6;
    QAction *actionMT7;
    QAction *actionMT8;
    QAction *actionMT9;
    QAction *actionMT10;
    QAction *actionMT11;
    QAction *actionMT12;
    QAction *actionRXfLow;
    QAction *actionRXfMedium;
    QAction *actionRXfHigh;
    QAction *actionDecFT8cycles1;
    QAction *actionDecFT8cycles2;
    QAction *actionDecFT8cycles3;
    QAction *actionFT8SensMin;
    QAction *actionlowFT8thresholds;
    QAction *actionFT8subpass;
    QAction *actionStartTwoStage;
    QAction *actionStartThreeStage;
    QAction *actionStartEarly;
    QAction *actionStartNormal;
    QAction *actionStartLate;
    QAction *actionFT8WidebandDXCallSearch;
    QAction *actionHide_FT8_dupe_messages;
    QAction *actionNo_MTD_a8_decodes;
    QAction *actionVHF_UHF_Buttons;
    QAction *actionHighlightTerritory1;
    QAction *actionHighlightTerritory2;
    QAction *actionHighlightTerritory3;
    QAction *actionHighlightTerritory4;
    QAction *actionDisable_clicks_on_waterfall;
    QAction *actionDownload_EME_Ephemeris_Chart;
    QAction *actionHide_AP_info;
    QAction *actionHighlight_Whitelist_entries;
    QAction *actionJTTY;
    QAction *actionFT2;
    QAction *actionAccept_QMAP_click_events;
    QAction *actionClaimQmapClicks;
    QAction *actionQmapSourceAuto;
    QAction *actionQmapSource1;
    QAction *actionQmapSource2;
    QAction *actionQmapSource3;
    QAction *actionQmapSource4;
    QAction *actionFSK441;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QSplitter *decodes_splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *lh_decodes_title_label;
    QLabel *lh_decodes_headings_label;
    DisplayText *decodedTextBrowser;
    QWidget *rh_decodes_widget;
    QVBoxLayout *verticalLayout_9;
    QLabel *rh_decodes_title_label;
    QLabel *rh_decodes_headings_label;
    DisplayText *decodedTextBrowser2;
    QWidget *lower_panel_widget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *Band_buttons_Layout;
    QPushButton *pb40;
    QPushButton *pb10;
    QPushButton *pb17;
    QPushButton *pb60;
    QPushButton *pb12;
    QPushButton *pb160;
    QPushButton *pb20;
    QPushButton *pb80;
    QPushButton *pb70;
    QPushButton *pb15;
    QPushButton *pb2;
    QPushButton *pb30;
    QPushButton *pb6;
    QPushButton *pb24G;
    QPushButton *pb10G;
    QPushButton *pb5G;
    QPushButton *pb9;
    QPushButton *pb13;
    QPushButton *pb23;
    QPushButton *pb902;
    QPushButton *pb432;
    QPushButton *pb220;
    QPushButton *pb144;
    QPushButton *pb4;
    QPushButton *pb50;
    QPushButton *pb8;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cbCQonly;
    QCheckBox *cbBypass;
    QPushButton *logQSOButton;
    QPushButton *stopButton;
    QPushButton *monitorButton;
    QPushButton *EraseButton;
    QPushButton *ClrAvgButton;
    HintedSpinBox *sbEchoAvg;
    QPushButton *DecodeButton;
    QPushButton *autoButton;
    QPushButton *stopTxButton;
    QPushButton *tuneButton;
    QCheckBox *cbMenus;
    QGridLayout *gridLayout_5;
    QWidget *DX_controls_widget;
    QVBoxLayout *verticalLayout_110;
    QGridLayout *DXCall_gridLayout;
    QPushButton *DX_Call_Button;
    QLineEdit *dxGridEntry;
    QLabel *label_4;
    QLineEdit *dxCallEntry;
    QLabel *labAz;
    QHBoxLayout *lookup_control_layout;
    QPushButton *lookupButton;
    QPushButton *addButton;
    QPushButton *ignoreButton;
    QSlider *outAttenuation;
    QLabel *label;
    QStackedWidget *controls_stack_widget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_8;
    QWidget *QSO_controls_widget;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QSpinBox *sbCQTxFreq;
    QCheckBox *cbCQTx;
    QCheckBox *cbRxAll;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labDXped;
    QCheckBox *cbSWL;
    QPushButton *pbBestSP;
    QCheckBox *measure_check_box;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *cbShMsgs;
    QCheckBox *cbFast9;
    QCheckBox *cbAutoSeq;
    QComboBox *respondComboBox;
    QCheckBox *cbTx6;
    QVBoxLayout *verticalLayout_14;
    QCheckBox *txFirstCheckBox;
    QSpinBox *TxFreqSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pbR2T;
    HintedSpinBox *sbFtol;
    QPushButton *pbT2R;
    QSpinBox *RxFreqSpinBox;
    QSpinBox *rptSpinBox;
    RestrictedSpinBox *sbTR;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_13;
    QGridLayout *submode_gridLayout;
    QPushButton *pb15C;
    QPushButton *pb15A;
    QPushButton *pb30B;
    QPushButton *pb60C;
    QPushButton *pb60D;
    QPushButton *pb60E;
    QCheckBox *cbHoldTxFreq;
    QStackedWidget *opt_controls_stack;
    QWidget *page_0;
    QVBoxLayout *verticalLayout;
    QSpinBox *sbSerialNumber;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_10;
    QSpinBox *sbF_Low;
    QSpinBox *sbF_High;
    LettersSpinBox *sbSubmode;
    QSpinBox *syncSpinBox;
    QSpinBox *sbMaxDrift;
    QToolButton *claimQmapToolButton;
    QSpacerItem *verticalSpacer_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QRadioButton *txrb6;
    QLabel *label_5;
    QLineEdit *tx1;
    DoubleClickableRadioButton *txrb4;
    DoubleClickableRadioButton *txrb1;
    QLineEdit *tx6;
    DoubleClickablePushButton *txb5;
    QPushButton *txb2;
    QLineEdit *tx2;
    QLabel *label_2;
    QRadioButton *txrb2;
    QLineEdit *tx4;
    QLineEdit *tx3;
    QPushButton *genStdMsgsPushButton;
    QPushButton *txb3;
    DoubleClickablePushButton *txb4;
    DoubleClickablePushButton *txb1;
    QPushButton *txb6;
    QRadioButton *txrb3;
    QComboBox *tx5;
    DoubleClickableRadioButton *txrb5;
    QWidget *tab_3;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout;
    QCheckBox *cbSendMsg;
    QPushButton *pbFreeText;
    QComboBox *comboBoxCQ;
    QLabel *label_queue;
    QCheckBox *cbWorkDupes;
    QPushButton *pbFoxReset;
    QSpinBox *sbNlist;
    QComboBox *comboBoxHoundSort;
    QCheckBox *cbMoreCQs;
    QLabel *label_inProcess;
    QSpinBox *sbNslots;
    QSpacerItem *verticalSpacer;
    DisplayText *foxTxListTextBrowser;
    DisplayText *houndQueueTextBrowser;
    QWidget *tab_4;
    QGridLayout *gridLayout_13;
    QHBoxLayout *horizontalLayout_30;
    QWidget *widget_3;
    QGridLayout *gridLayout_8;
    QCheckBox *cb70cm;
    QCheckBox *cb30m;
    QPushButton *pbBandHopping;
    QCheckBox *cb12m;
    QCheckBox *cb40m;
    QCheckBox *cb2mMSK;
    QCheckBox *cb10m;
    QCheckBox *cb6m;
    QCheckBox *cb60m;
    QCheckBox *cb160m;
    QCheckBox *cb80m;
    QCheckBox *cb20m;
    QCheckBox *cb17m;
    QCheckBox *cb4m;
    QCheckBox *cb15m;
    QCheckBox *cb2m;
    QCheckBox *cb10mFT4;
    QCheckBox *cb12mFT4;
    QCheckBox *cb15mFT4;
    QCheckBox *cb17mFT4;
    QCheckBox *cb20mFT4;
    QCheckBox *cb30mFT4;
    QCheckBox *cb40mFT4;
    QCheckBox *cb80mFT4;
    QGridLayout *gridLayout_10;
    QCheckBox *cbQRG6;
    QCheckBox *cbQRG1;
    QCheckBox *cbQRG2;
    QCheckBox *cbQRG7;
    QSpinBox *sbQRG8;
    QCheckBox *cbQRG5;
    QCheckBox *cbQRG3;
    QCheckBox *cbQRG4;
    QCheckBox *cbQRG8;
    QSpinBox *sbQRG7;
    QSpinBox *sbQRG6;
    QSpinBox *sbQRG5;
    QSpinBox *sbQRG4;
    QSpinBox *sbQRG3;
    QSpinBox *sbQRG2;
    QSpinBox *sbQRG1;
    QWidget *page_4;
    QGridLayout *gridLayout_12;
    QHBoxLayout *JTTY_horizontalLayout_1;
    QCheckBox *cbLowerCase;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *cbIncludeTime;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_jttyStyle;
    QComboBox *comboBoxJttyStyle;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QGridLayout *JTTY_gridLayout_1;
    QGridLayout *JTTY_gridLayout_2;
    QPushButton *pbF5;
    QLineEdit *msg1;
    QLineEdit *msg2;
    QPushButton *pbF2;
    QLineEdit *msg4;
    QPushButton *pbF1;
    QPushButton *pbF7;
    QPushButton *pbF3;
    QPushButton *pbF6;
    QLineEdit *msg3;
    QPushButton *pbF8;
    QPushButton *pbF4;
    QLineEdit *msg5;
    QLineEdit *msg6;
    QLineEdit *msg7;
    QLineEdit *msg8;
    QSpacerItem *verticalSpacer_10;
    QPushButton *pbSendMessage;
    QLabel *label_3;
    QLineEdit *Tx_Message;
    QHBoxLayout *JTTY_horizontalLayout_2;
    QSpinBox *sbSerialNumber_2;
    QLabel *label_jttyCallNext;
    QLineEdit *lineEdit;
    QVBoxLayout *JTTY_verticalLayout_1;
    QSpinBox *TxFreqSpinBox_2;
    QHBoxLayout *JTTY_horizontalLayout_3;
    QPushButton *pbR2T_2;
    HintedSpinBox *sbFtol_2;
    QPushButton *pbT2R_2;
    QSpinBox *RxFreqSpinBox_2;
    QSpacerItem *verticalSpacer_11;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_9;
    QWidget *WSPR_controls_widget;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_7;
    QSpinBox *WSPRfreqSpinBox;
    QSpinBox *sbFST4W_RxFreq;
    HintedSpinBox *sbFST4W_FTol;
    QComboBox *RoundRobin;
    QSpinBox *sbTxPercent;
    RestrictedSpinBox *sbTR_FST4W;
    QGroupBox *band_hopping_group_box;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *band_hopping_schedule_push_button;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *cbUploadWSPR_Spots;
    QCheckBox *WSPR_prefer_type_1_check_box;
    QCheckBox *cbNoOwnCall;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pbTxNext;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *TxPowerComboBox;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_7;
    QGridLayout *gridLayout_2;
    QRadioButton *rbEchoMessage;
    HintedSpinBox *sbToneSpacing;
    QRadioButton *rbFixedTone;
    QLineEdit *leEchoMessage;
    QRadioButton *rbEchoCW;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labDialFreq;
    QLabel *labUTC;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_11;
    QSpinBox *sbNB;
    QHBoxLayout *horizontalLayout_3;
    SignalMeter *signal_meter_widget;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_15;
    QPushButton *houndButton;
    QPushButton *ft8Button;
    QPushButton *ft4Button;
    QPushButton *ft2Button;
    QPushButton *msk144Button;
    QPushButton *q65Button;
    QPushButton *jt65Button;
    QPushButton *echoButton;
    QHBoxLayout *horizontalLayout;
    BandComboBox *bandComboBox;
    QPushButton *readFreq;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuCallsign_overlay;
    QMenu *menuCallsign_font;
    QMenu *menuCallsign_transparency;
    QMenu *menuCallsign_position;
    QMenu *menuFilters;
    QMenu *menuDecode;
    QMenu *menuParameters;
    QMenu *menuDecoder_sensitivity;
    QMenu *menuDecoder_start;
    QMenu *menuFT8_threads;
    QMenu *menuQSO_RX_freq_sensitivity;
    QMenu *menuDecoding_cycles;
    QMenu *menuQMAP_source;
    QMenu *menuSave;
    QMenu *menuHelp;
    QMenu *menuMode;
    QMenu *menuConfig;
    QMenu *menuTools;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(880, 685);
        MainWindow->setMinimumSize(QSize(750, 0));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setMenuRole(QAction::QuitRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout->setMenuRole(QAction::AboutRole);
        actionWide_Waterfall = new QAction(MainWindow);
        actionWide_Waterfall->setObjectName(QString::fromUtf8("actionWide_Waterfall"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen_next_in_directory = new QAction(MainWindow);
        actionOpen_next_in_directory->setObjectName(QString::fromUtf8("actionOpen_next_in_directory"));
        actionDecode_remaining_files_in_directory = new QAction(MainWindow);
        actionDecode_remaining_files_in_directory->setObjectName(QString::fromUtf8("actionDecode_remaining_files_in_directory"));
        actionDelete_all_wav_files_in_SaveDir = new QAction(MainWindow);
        actionDelete_all_wav_files_in_SaveDir->setObjectName(QString::fromUtf8("actionDelete_all_wav_files_in_SaveDir"));
        actionQuickDecode = new QAction(MainWindow);
        actionQuickDecode->setObjectName(QString::fromUtf8("actionQuickDecode"));
        actionQuickDecode->setCheckable(true);
        actionQuickDecode->setChecked(false);
        actionNone = new QAction(MainWindow);
        actionNone->setObjectName(QString::fromUtf8("actionNone"));
        actionNone->setCheckable(true);
        actionNone->setChecked(true);
        actionSave_all = new QAction(MainWindow);
        actionSave_all->setObjectName(QString::fromUtf8("actionSave_all"));
        actionSave_all->setCheckable(true);
        actionRemove_after_30days = new QAction(MainWindow);
        actionRemove_after_30days->setObjectName(QString::fromUtf8("actionRemove_after_30days"));
        actionRemove_after_30days->setCheckable(true);
        actionWSJT_X_User_Guide = new QAction(MainWindow);
        actionWSJT_X_User_Guide->setObjectName(QString::fromUtf8("actionWSJT_X_User_Guide"));
        actionKeyboard_shortcuts = new QAction(MainWindow);
        actionKeyboard_shortcuts->setObjectName(QString::fromUtf8("actionKeyboard_shortcuts"));
        actionSpecial_mouse_commands = new QAction(MainWindow);
        actionSpecial_mouse_commands->setObjectName(QString::fromUtf8("actionSpecial_mouse_commands"));
        actionJT9 = new QAction(MainWindow);
        actionJT9->setObjectName(QString::fromUtf8("actionJT9"));
        actionJT9->setCheckable(true);
        actionJT9->setChecked(true);
        actionSave_decoded = new QAction(MainWindow);
        actionSave_decoded->setObjectName(QString::fromUtf8("actionSave_decoded"));
        actionSave_decoded->setCheckable(true);
        actionSave_decoded->setEnabled(true);
        actionMediumDecode = new QAction(MainWindow);
        actionMediumDecode->setObjectName(QString::fromUtf8("actionMediumDecode"));
        actionMediumDecode->setCheckable(true);
        actionMediumDecode->setChecked(false);
        actionDeepestDecode = new QAction(MainWindow);
        actionDeepestDecode->setObjectName(QString::fromUtf8("actionDeepestDecode"));
        actionDeepestDecode->setCheckable(true);
        actionDeepestDecode->setChecked(true);
        actionErase_ALL_TXT = new QAction(MainWindow);
        actionErase_ALL_TXT->setObjectName(QString::fromUtf8("actionErase_ALL_TXT"));
        actionErase_wsjtx_log_adi = new QAction(MainWindow);
        actionErase_wsjtx_log_adi->setObjectName(QString::fromUtf8("actionErase_wsjtx_log_adi"));
        actionErase_Tx_Log = new QAction(MainWindow);
        actionErase_Tx_Log->setObjectName(QString::fromUtf8("actionErase_Tx_Log"));
        actionErase_Ignore_List = new QAction(MainWindow);
        actionErase_Ignore_List->setObjectName(QString::fromUtf8("actionErase_Ignore_List"));
        actionJT65 = new QAction(MainWindow);
        actionJT65->setObjectName(QString::fromUtf8("actionJT65"));
        actionJT65->setCheckable(true);
        actionAstronomical_data = new QAction(MainWindow);
        actionAstronomical_data->setObjectName(QString::fromUtf8("actionAstronomical_data"));
        actionAstronomical_data->setCheckable(true);
        actionShort_list_of_add_on_prefixes_and_suffixes = new QAction(MainWindow);
        actionShort_list_of_add_on_prefixes_and_suffixes->setObjectName(QString::fromUtf8("actionShort_list_of_add_on_prefixes_and_suffixes"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionSettings->setMenuRole(QAction::PreferencesRole);
        actionLocal_User_Guide = new QAction(MainWindow);
        actionLocal_User_Guide->setObjectName(QString::fromUtf8("actionLocal_User_Guide"));
        actionOpen_log_directory = new QAction(MainWindow);
        actionOpen_log_directory->setObjectName(QString::fromUtf8("actionOpen_log_directory"));
        actionJT4 = new QAction(MainWindow);
        actionJT4->setObjectName(QString::fromUtf8("actionJT4"));
        actionJT4->setCheckable(true);
        actionMessage_averaging = new QAction(MainWindow);
        actionMessage_averaging->setObjectName(QString::fromUtf8("actionMessage_averaging"));
        actionInclude_averaging = new QAction(MainWindow);
        actionInclude_averaging->setObjectName(QString::fromUtf8("actionInclude_averaging"));
        actionInclude_averaging->setCheckable(true);
        actionInclude_correlation = new QAction(MainWindow);
        actionInclude_correlation->setObjectName(QString::fromUtf8("actionInclude_correlation"));
        actionInclude_correlation->setCheckable(true);
        actionWSPR = new QAction(MainWindow);
        actionWSPR->setObjectName(QString::fromUtf8("actionWSPR"));
        actionWSPR->setCheckable(true);
        actionEcho_Graph = new QAction(MainWindow);
        actionEcho_Graph->setObjectName(QString::fromUtf8("actionEcho_Graph"));
        actionEcho = new QAction(MainWindow);
        actionEcho->setObjectName(QString::fromUtf8("actionEcho"));
        actionEcho->setCheckable(true);
        actionISCAT = new QAction(MainWindow);
        actionISCAT->setObjectName(QString::fromUtf8("actionISCAT"));
        actionISCAT->setCheckable(true);
        actionFast_Graph = new QAction(MainWindow);
        actionFast_Graph->setObjectName(QString::fromUtf8("actionFast_Graph"));
        download_samples_action = new QAction(MainWindow);
        download_samples_action->setObjectName(QString::fromUtf8("download_samples_action"));
        actionMSK144 = new QAction(MainWindow);
        actionMSK144->setObjectName(QString::fromUtf8("actionMSK144"));
        actionMSK144->setCheckable(true);
        actionQRA64 = new QAction(MainWindow);
        actionQRA64->setObjectName(QString::fromUtf8("actionQRA64"));
        actionQRA64->setCheckable(true);
        actionRelease_Notes = new QAction(MainWindow);
        actionRelease_Notes->setObjectName(QString::fromUtf8("actionRelease_Notes"));
        actionEnable_AP_DXcall = new QAction(MainWindow);
        actionEnable_AP_DXcall->setObjectName(QString::fromUtf8("actionEnable_AP_DXcall"));
        actionEnable_AP_DXcall->setCheckable(true);
        actionFreqCal = new QAction(MainWindow);
        actionFreqCal->setObjectName(QString::fromUtf8("actionFreqCal"));
        actionFreqCal->setCheckable(true);
        actionMeasure_reference_spectrum = new QAction(MainWindow);
        actionMeasure_reference_spectrum->setObjectName(QString::fromUtf8("actionMeasure_reference_spectrum"));
        actionMeasure_phase_response = new QAction(MainWindow);
        actionMeasure_phase_response->setObjectName(QString::fromUtf8("actionMeasure_phase_response"));
        actionErase_reference_spectrum = new QAction(MainWindow);
        actionErase_reference_spectrum->setObjectName(QString::fromUtf8("actionErase_reference_spectrum"));
        actionFrequency_calibration = new QAction(MainWindow);
        actionFrequency_calibration->setObjectName(QString::fromUtf8("actionFrequency_calibration"));
        actionFrequency_calibration->setCheckable(true);
        view_phase_response_action = new QAction(MainWindow);
        view_phase_response_action->setObjectName(QString::fromUtf8("view_phase_response_action"));
        actionFT8 = new QAction(MainWindow);
        actionFT8->setObjectName(QString::fromUtf8("actionFT8"));
        actionFT8->setCheckable(true);
        actionFT8->setEnabled(true);
        actionEnable_AP_FT8 = new QAction(MainWindow);
        actionEnable_AP_FT8->setObjectName(QString::fromUtf8("actionEnable_AP_FT8"));
        actionEnable_AP_FT8->setCheckable(true);
        actionEnable_AP_JT65 = new QAction(MainWindow);
        actionEnable_AP_JT65->setObjectName(QString::fromUtf8("actionEnable_AP_JT65"));
        actionEnable_AP_JT65->setCheckable(true);
        actionSolve_FreqCal = new QAction(MainWindow);
        actionSolve_FreqCal->setObjectName(QString::fromUtf8("actionSolve_FreqCal"));
        actionCopyright_Notice = new QAction(MainWindow);
        actionCopyright_Notice->setObjectName(QString::fromUtf8("actionCopyright_Notice"));
        fox_log_action = new QAction(MainWindow);
        fox_log_action->setObjectName(QString::fromUtf8("fox_log_action"));
        fox_log_action->setCheckable(false);
        actionFT8_DXpedition_Mode_User_Guide = new QAction(MainWindow);
        actionFT8_DXpedition_Mode_User_Guide->setObjectName(QString::fromUtf8("actionFT8_DXpedition_Mode_User_Guide"));
        reset_cabrillo_log_action = new QAction(MainWindow);
        reset_cabrillo_log_action->setObjectName(QString::fromUtf8("reset_cabrillo_log_action"));
        actionColors = new QAction(MainWindow);
        actionColors->setObjectName(QString::fromUtf8("actionColors"));
        actionExport_Cabrillo_log = new QAction(MainWindow);
        actionExport_Cabrillo_log->setObjectName(QString::fromUtf8("actionExport_Cabrillo_log"));
        actionQSG_FST4 = new QAction(MainWindow);
        actionQSG_FST4->setObjectName(QString::fromUtf8("actionQSG_FST4"));
        contest_log_action = new QAction(MainWindow);
        contest_log_action->setObjectName(QString::fromUtf8("contest_log_action"));
        actionErase_WSPR_hashtable = new QAction(MainWindow);
        actionErase_WSPR_hashtable->setObjectName(QString::fromUtf8("actionErase_WSPR_hashtable"));
        actionFT4 = new QAction(MainWindow);
        actionFT4->setObjectName(QString::fromUtf8("actionFT4"));
        actionFT4->setCheckable(true);
        actionFST4 = new QAction(MainWindow);
        actionFST4->setObjectName(QString::fromUtf8("actionFST4"));
        actionFST4->setCheckable(true);
        actionFST4W = new QAction(MainWindow);
        actionFST4W->setObjectName(QString::fromUtf8("actionFST4W"));
        actionFST4W->setCheckable(true);
        actionQ65 = new QAction(MainWindow);
        actionQ65->setObjectName(QString::fromUtf8("actionQ65"));
        actionQ65->setCheckable(true);
        actionSWL_Mode = new QAction(MainWindow);
        actionSWL_Mode->setObjectName(QString::fromUtf8("actionSWL_Mode"));
        actionSWL_Mode->setCheckable(true);
        actionQSG_Q65 = new QAction(MainWindow);
        actionQSG_Q65->setObjectName(QString::fromUtf8("actionQSG_Q65"));
        actionAuto_Clear_Avg = new QAction(MainWindow);
        actionAuto_Clear_Avg->setObjectName(QString::fromUtf8("actionAuto_Clear_Avg"));
        actionAuto_Clear_Avg->setCheckable(true);
        actionQSG_X250_M3 = new QAction(MainWindow);
        actionQSG_X250_M3->setObjectName(QString::fromUtf8("actionQSG_X250_M3"));
        actionDon_t_split_ALL_TXT = new QAction(MainWindow);
        actionDon_t_split_ALL_TXT->setObjectName(QString::fromUtf8("actionDon_t_split_ALL_TXT"));
        actionDon_t_split_ALL_TXT->setCheckable(true);
        actionDon_t_split_ALL_TXT->setChecked(true);
        actionSplit_ALL_TXT_yearly = new QAction(MainWindow);
        actionSplit_ALL_TXT_yearly->setObjectName(QString::fromUtf8("actionSplit_ALL_TXT_yearly"));
        actionSplit_ALL_TXT_yearly->setCheckable(true);
        actionSplit_ALL_TXT_monthly = new QAction(MainWindow);
        actionSplit_ALL_TXT_monthly->setObjectName(QString::fromUtf8("actionSplit_ALL_TXT_monthly"));
        actionSplit_ALL_TXT_monthly->setCheckable(true);
        actionDisable_writing_of_ALL_TXT = new QAction(MainWindow);
        actionDisable_writing_of_ALL_TXT->setObjectName(QString::fromUtf8("actionDisable_writing_of_ALL_TXT"));
        actionDisable_writing_of_ALL_TXT->setCheckable(true);
        actionActiveStations = new QAction(MainWindow);
        actionActiveStations->setObjectName(QString::fromUtf8("actionActiveStations"));
        actionBand_Buttons = new QAction(MainWindow);
        actionBand_Buttons->setObjectName(QString::fromUtf8("actionBand_Buttons"));
        actionBand_Buttons->setCheckable(true);
        actionBand_Buttons->setChecked(false);
        actionUse_Dark_Style = new QAction(MainWindow);
        actionUse_Dark_Style->setObjectName(QString::fromUtf8("actionUse_Dark_Style"));
        actionUse_Dark_Style->setCheckable(true);
        actionCallsign_overlay_enabled = new QAction(MainWindow);
        actionCallsign_overlay_enabled->setObjectName(QString::fromUtf8("actionCallsign_overlay_enabled"));
        actionCallsign_overlay_enabled->setCheckable(true);
        actionCallsign_overlay_enabled->setChecked(true);
        actionCallsign_persist_1 = new QAction(MainWindow);
        actionCallsign_persist_1->setObjectName(QString::fromUtf8("actionCallsign_persist_1"));
        actionCallsign_persist_1->setCheckable(true);
        actionCallsign_persist_1->setChecked(false);
        actionCallsign_persist_2 = new QAction(MainWindow);
        actionCallsign_persist_2->setObjectName(QString::fromUtf8("actionCallsign_persist_2"));
        actionCallsign_persist_2->setCheckable(true);
        actionCallsign_persist_2->setChecked(true);
        actionCallsign_persist_3 = new QAction(MainWindow);
        actionCallsign_persist_3->setObjectName(QString::fromUtf8("actionCallsign_persist_3"));
        actionCallsign_persist_3->setCheckable(true);
        actionCallsign_persist_4 = new QAction(MainWindow);
        actionCallsign_persist_4->setObjectName(QString::fromUtf8("actionCallsign_persist_4"));
        actionCallsign_persist_4->setCheckable(true);
        actionCallsign_persist_5 = new QAction(MainWindow);
        actionCallsign_persist_5->setObjectName(QString::fromUtf8("actionCallsign_persist_5"));
        actionCallsign_persist_5->setCheckable(true);
        actionCallsign_font_small = new QAction(MainWindow);
        actionCallsign_font_small->setObjectName(QString::fromUtf8("actionCallsign_font_small"));
        actionCallsign_font_small->setCheckable(true);
        actionCallsign_font_normal = new QAction(MainWindow);
        actionCallsign_font_normal->setObjectName(QString::fromUtf8("actionCallsign_font_normal"));
        actionCallsign_font_normal->setCheckable(true);
        actionCallsign_font_normal->setChecked(true);
        actionCallsign_font_medium = new QAction(MainWindow);
        actionCallsign_font_medium->setObjectName(QString::fromUtf8("actionCallsign_font_medium"));
        actionCallsign_font_medium->setCheckable(true);
        actionCallsign_font_large = new QAction(MainWindow);
        actionCallsign_font_large->setObjectName(QString::fromUtf8("actionCallsign_font_large"));
        actionCallsign_font_large->setCheckable(true);
        actionCallsign_position_top = new QAction(MainWindow);
        actionCallsign_position_top->setObjectName(QString::fromUtf8("actionCallsign_position_top"));
        actionCallsign_position_top->setCheckable(true);
        actionCallsign_position_bottom = new QAction(MainWindow);
        actionCallsign_position_bottom->setObjectName(QString::fromUtf8("actionCallsign_position_bottom"));
        actionCallsign_position_bottom->setCheckable(true);
        actionCallsign_transparency_None = new QAction(MainWindow);
        actionCallsign_transparency_None->setObjectName(QString::fromUtf8("actionCallsign_transparency_None"));
        actionCallsign_transparency_None->setCheckable(true);
        actionCallsign_transparency_None->setChecked(true);
        actionCallsign_transparency_Low = new QAction(MainWindow);
        actionCallsign_transparency_Low->setObjectName(QString::fromUtf8("actionCallsign_transparency_Low"));
        actionCallsign_transparency_Low->setCheckable(true);
        actionCallsign_transparency_Medium = new QAction(MainWindow);
        actionCallsign_transparency_Medium->setObjectName(QString::fromUtf8("actionCallsign_transparency_Medium"));
        actionCallsign_transparency_Medium->setCheckable(true);
        actionCallsign_transparency_High = new QAction(MainWindow);
        actionCallsign_transparency_High->setObjectName(QString::fromUtf8("actionCallsign_transparency_High"));
        actionCallsign_transparency_High->setCheckable(true);
        actionReduce_false_decodes = new QAction(MainWindow);
        actionReduce_false_decodes->setObjectName(QString::fromUtf8("actionReduce_false_decodes"));
        actionReduce_false_decodes->setCheckable(true);
        actionDefault_event_logging = new QAction(MainWindow);
        actionDefault_event_logging->setObjectName(QString::fromUtf8("actionDefault_event_logging"));
        actionDefault_event_logging->setCheckable(true);
        actionDefault_event_logging->setChecked(true);
        actionDiagnostic_mode = new QAction(MainWindow);
        actionDiagnostic_mode->setObjectName(QString::fromUtf8("actionDiagnostic_mode"));
        actionDiagnostic_mode->setCheckable(true);
        actionDisable_event_logging = new QAction(MainWindow);
        actionDisable_event_logging->setObjectName(QString::fromUtf8("actionDisable_event_logging"));
        actionDisable_event_logging->setCheckable(true);
        actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP = new QAction(MainWindow);
        actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP->setObjectName(QString::fromUtf8("actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP"));
        actionWS_Home_Page = new QAction(MainWindow);
        actionWS_Home_Page->setObjectName(QString::fromUtf8("actionWS_Home_Page"));
        actionThe_additional_features_of_wsjt_x_improved = new QAction(MainWindow);
        actionThe_additional_features_of_wsjt_x_improved->setObjectName(QString::fromUtf8("actionThe_additional_features_of_wsjt_x_improved"));
        actionRecommended_Audio_Settings = new QAction(MainWindow);
        actionRecommended_Audio_Settings->setObjectName(QString::fromUtf8("actionRecommended_Audio_Settings"));
        actionRig_Control_Errors = new QAction(MainWindow);
        actionRig_Control_Errors->setObjectName(QString::fromUtf8("actionRig_Control_Errors"));
        actionErase_list_of_Q65_callers = new QAction(MainWindow);
        actionErase_list_of_Q65_callers->setObjectName(QString::fromUtf8("actionErase_list_of_Q65_callers"));
        actionSuperFox_User_Guide = new QAction(MainWindow);
        actionSuperFox_User_Guide->setObjectName(QString::fromUtf8("actionSuperFox_User_Guide"));
        actionQSYMessage_Creator = new QAction(MainWindow);
        actionQSYMessage_Creator->setObjectName(QString::fromUtf8("actionQSYMessage_Creator"));
        actionQSYMessage_Creator->setCheckable(false);
        actionHideB4 = new QAction(MainWindow);
        actionHideB4->setObjectName(QString::fromUtf8("actionHideB4"));
        actionHideB4->setCheckable(true);
        actionHideToday = new QAction(MainWindow);
        actionHideToday->setObjectName(QString::fromUtf8("actionHideToday"));
        actionHideToday->setCheckable(true);
        actionHideIgnored = new QAction(MainWindow);
        actionHideIgnored->setObjectName(QString::fromUtf8("actionHideIgnored"));
        actionHideIgnored->setCheckable(true);
        actionIgnoreToday = new QAction(MainWindow);
        actionIgnoreToday->setObjectName(QString::fromUtf8("actionIgnoreToday"));
        actionIgnoreToday->setCheckable(true);
        actionIgnoreIgnored = new QAction(MainWindow);
        actionIgnoreIgnored->setObjectName(QString::fromUtf8("actionIgnoreIgnored"));
        actionIgnoreIgnored->setCheckable(true);
        actionHideTerritory1 = new QAction(MainWindow);
        actionHideTerritory1->setObjectName(QString::fromUtf8("actionHideTerritory1"));
        actionHideTerritory1->setCheckable(true);
        actionHideTerritory2 = new QAction(MainWindow);
        actionHideTerritory2->setObjectName(QString::fromUtf8("actionHideTerritory2"));
        actionHideTerritory2->setCheckable(true);
        actionHideTerritory3 = new QAction(MainWindow);
        actionHideTerritory3->setObjectName(QString::fromUtf8("actionHideTerritory3"));
        actionHideTerritory3->setCheckable(true);
        actionHideTerritory4 = new QAction(MainWindow);
        actionHideTerritory4->setObjectName(QString::fromUtf8("actionHideTerritory4"));
        actionHideTerritory4->setCheckable(true);
        actionHideEU = new QAction(MainWindow);
        actionHideEU->setObjectName(QString::fromUtf8("actionHideEU"));
        actionHideEU->setCheckable(true);
        actionHideNA = new QAction(MainWindow);
        actionHideNA->setObjectName(QString::fromUtf8("actionHideNA"));
        actionHideNA->setCheckable(true);
        actionHideSA = new QAction(MainWindow);
        actionHideSA->setObjectName(QString::fromUtf8("actionHideSA"));
        actionHideSA->setCheckable(true);
        actionHideAS = new QAction(MainWindow);
        actionHideAS->setObjectName(QString::fromUtf8("actionHideAS"));
        actionHideAS->setCheckable(true);
        actionHideAF = new QAction(MainWindow);
        actionHideAF->setObjectName(QString::fromUtf8("actionHideAF"));
        actionHideAF->setCheckable(true);
        actionHideOC = new QAction(MainWindow);
        actionHideOC->setObjectName(QString::fromUtf8("actionHideOC"));
        actionHideOC->setCheckable(true);
        actionHideAN = new QAction(MainWindow);
        actionHideAN->setObjectName(QString::fromUtf8("actionHideAN"));
        actionHideAN->setCheckable(true);
        actionFull_Duplex_Mode = new QAction(MainWindow);
        actionFull_Duplex_Mode->setObjectName(QString::fromUtf8("actionFull_Duplex_Mode"));
        actionFull_Duplex_Mode->setCheckable(true);
        actionHighlightB4 = new QAction(MainWindow);
        actionHighlightB4->setObjectName(QString::fromUtf8("actionHighlightB4"));
        actionHighlightB4->setCheckable(true);
        actionHighlightToday = new QAction(MainWindow);
        actionHighlightToday->setObjectName(QString::fromUtf8("actionHighlightToday"));
        actionHighlightToday->setCheckable(true);
        actionHighlightIgnored = new QAction(MainWindow);
        actionHighlightIgnored->setObjectName(QString::fromUtf8("actionHighlightIgnored"));
        actionHighlightIgnored->setCheckable(true);
        actionEnable_QSY_Popups = new QAction(MainWindow);
        actionEnable_QSY_Popups->setObjectName(QString::fromUtf8("actionEnable_QSY_Popups"));
        actionEnable_QSY_Popups->setCheckable(true);
        actionEnable_QSY_Popups->setChecked(false);
        actionQSY_Monitor = new QAction(MainWindow);
        actionQSY_Monitor->setObjectName(QString::fromUtf8("actionQSY_Monitor"));
        actionQSY_Monitor->setCheckable(false);
        actionIgnoreB4 = new QAction(MainWindow);
        actionIgnoreB4->setObjectName(QString::fromUtf8("actionIgnoreB4"));
        actionIgnoreB4->setCheckable(true);
        actionUse_multithreaded_FT8_decoder = new QAction(MainWindow);
        actionUse_multithreaded_FT8_decoder->setObjectName(QString::fromUtf8("actionUse_multithreaded_FT8_decoder"));
        actionUse_multithreaded_FT8_decoder->setCheckable(true);
        actionMTAuto = new QAction(MainWindow);
        actionMTAuto->setObjectName(QString::fromUtf8("actionMTAuto"));
        actionMTAuto->setCheckable(true);
        actionMTAuto->setChecked(true);
        actionMT1 = new QAction(MainWindow);
        actionMT1->setObjectName(QString::fromUtf8("actionMT1"));
        actionMT1->setCheckable(true);
        actionMT2 = new QAction(MainWindow);
        actionMT2->setObjectName(QString::fromUtf8("actionMT2"));
        actionMT2->setCheckable(true);
        actionMT3 = new QAction(MainWindow);
        actionMT3->setObjectName(QString::fromUtf8("actionMT3"));
        actionMT3->setCheckable(true);
        actionMT4 = new QAction(MainWindow);
        actionMT4->setObjectName(QString::fromUtf8("actionMT4"));
        actionMT4->setCheckable(true);
        actionMT5 = new QAction(MainWindow);
        actionMT5->setObjectName(QString::fromUtf8("actionMT5"));
        actionMT5->setCheckable(true);
        actionMT6 = new QAction(MainWindow);
        actionMT6->setObjectName(QString::fromUtf8("actionMT6"));
        actionMT6->setCheckable(true);
        actionMT7 = new QAction(MainWindow);
        actionMT7->setObjectName(QString::fromUtf8("actionMT7"));
        actionMT7->setCheckable(true);
        actionMT8 = new QAction(MainWindow);
        actionMT8->setObjectName(QString::fromUtf8("actionMT8"));
        actionMT8->setCheckable(true);
        actionMT9 = new QAction(MainWindow);
        actionMT9->setObjectName(QString::fromUtf8("actionMT9"));
        actionMT9->setCheckable(true);
        actionMT10 = new QAction(MainWindow);
        actionMT10->setObjectName(QString::fromUtf8("actionMT10"));
        actionMT10->setCheckable(true);
        actionMT11 = new QAction(MainWindow);
        actionMT11->setObjectName(QString::fromUtf8("actionMT11"));
        actionMT11->setCheckable(true);
        actionMT12 = new QAction(MainWindow);
        actionMT12->setObjectName(QString::fromUtf8("actionMT12"));
        actionMT12->setCheckable(true);
        actionRXfLow = new QAction(MainWindow);
        actionRXfLow->setObjectName(QString::fromUtf8("actionRXfLow"));
        actionRXfLow->setCheckable(true);
        actionRXfMedium = new QAction(MainWindow);
        actionRXfMedium->setObjectName(QString::fromUtf8("actionRXfMedium"));
        actionRXfMedium->setCheckable(true);
        actionRXfMedium->setChecked(true);
        actionRXfHigh = new QAction(MainWindow);
        actionRXfHigh->setObjectName(QString::fromUtf8("actionRXfHigh"));
        actionRXfHigh->setCheckable(true);
        actionDecFT8cycles1 = new QAction(MainWindow);
        actionDecFT8cycles1->setObjectName(QString::fromUtf8("actionDecFT8cycles1"));
        actionDecFT8cycles1->setCheckable(true);
        actionDecFT8cycles2 = new QAction(MainWindow);
        actionDecFT8cycles2->setObjectName(QString::fromUtf8("actionDecFT8cycles2"));
        actionDecFT8cycles2->setCheckable(true);
        actionDecFT8cycles3 = new QAction(MainWindow);
        actionDecFT8cycles3->setObjectName(QString::fromUtf8("actionDecFT8cycles3"));
        actionDecFT8cycles3->setCheckable(true);
        actionDecFT8cycles3->setChecked(true);
        actionFT8SensMin = new QAction(MainWindow);
        actionFT8SensMin->setObjectName(QString::fromUtf8("actionFT8SensMin"));
        actionFT8SensMin->setCheckable(true);
        actionlowFT8thresholds = new QAction(MainWindow);
        actionlowFT8thresholds->setObjectName(QString::fromUtf8("actionlowFT8thresholds"));
        actionlowFT8thresholds->setCheckable(true);
        actionFT8subpass = new QAction(MainWindow);
        actionFT8subpass->setObjectName(QString::fromUtf8("actionFT8subpass"));
        actionFT8subpass->setCheckable(true);
        actionFT8subpass->setChecked(true);
        actionStartTwoStage = new QAction(MainWindow);
        actionStartTwoStage->setObjectName(QString::fromUtf8("actionStartTwoStage"));
        actionStartTwoStage->setCheckable(true);
        actionStartThreeStage = new QAction(MainWindow);
        actionStartThreeStage->setObjectName(QString::fromUtf8("actionStartThreeStage"));
        actionStartThreeStage->setCheckable(true);
        actionStartEarly = new QAction(MainWindow);
        actionStartEarly->setObjectName(QString::fromUtf8("actionStartEarly"));
        actionStartEarly->setCheckable(true);
        actionStartNormal = new QAction(MainWindow);
        actionStartNormal->setObjectName(QString::fromUtf8("actionStartNormal"));
        actionStartNormal->setCheckable(true);
        actionStartNormal->setChecked(true);
        actionStartLate = new QAction(MainWindow);
        actionStartLate->setObjectName(QString::fromUtf8("actionStartLate"));
        actionStartLate->setCheckable(true);
        actionFT8WidebandDXCallSearch = new QAction(MainWindow);
        actionFT8WidebandDXCallSearch->setObjectName(QString::fromUtf8("actionFT8WidebandDXCallSearch"));
        actionFT8WidebandDXCallSearch->setCheckable(true);
        actionHide_FT8_dupe_messages = new QAction(MainWindow);
        actionHide_FT8_dupe_messages->setObjectName(QString::fromUtf8("actionHide_FT8_dupe_messages"));
        actionHide_FT8_dupe_messages->setCheckable(true);
        actionNo_MTD_a8_decodes = new QAction(MainWindow);
        actionNo_MTD_a8_decodes->setObjectName(QString::fromUtf8("actionNo_MTD_a8_decodes"));
        actionNo_MTD_a8_decodes->setCheckable(true);
        actionVHF_UHF_Buttons = new QAction(MainWindow);
        actionVHF_UHF_Buttons->setObjectName(QString::fromUtf8("actionVHF_UHF_Buttons"));
        actionVHF_UHF_Buttons->setCheckable(true);
        actionHighlightTerritory1 = new QAction(MainWindow);
        actionHighlightTerritory1->setObjectName(QString::fromUtf8("actionHighlightTerritory1"));
        actionHighlightTerritory1->setCheckable(true);
        actionHighlightTerritory2 = new QAction(MainWindow);
        actionHighlightTerritory2->setObjectName(QString::fromUtf8("actionHighlightTerritory2"));
        actionHighlightTerritory2->setCheckable(true);
        actionHighlightTerritory3 = new QAction(MainWindow);
        actionHighlightTerritory3->setObjectName(QString::fromUtf8("actionHighlightTerritory3"));
        actionHighlightTerritory3->setCheckable(true);
        actionHighlightTerritory4 = new QAction(MainWindow);
        actionHighlightTerritory4->setObjectName(QString::fromUtf8("actionHighlightTerritory4"));
        actionHighlightTerritory4->setCheckable(true);
        actionDisable_clicks_on_waterfall = new QAction(MainWindow);
        actionDisable_clicks_on_waterfall->setObjectName(QString::fromUtf8("actionDisable_clicks_on_waterfall"));
        actionDisable_clicks_on_waterfall->setCheckable(true);
        actionDownload_EME_Ephemeris_Chart = new QAction(MainWindow);
        actionDownload_EME_Ephemeris_Chart->setObjectName(QString::fromUtf8("actionDownload_EME_Ephemeris_Chart"));
        actionHide_AP_info = new QAction(MainWindow);
        actionHide_AP_info->setObjectName(QString::fromUtf8("actionHide_AP_info"));
        actionHide_AP_info->setCheckable(true);
        actionHighlight_Whitelist_entries = new QAction(MainWindow);
        actionHighlight_Whitelist_entries->setObjectName(QString::fromUtf8("actionHighlight_Whitelist_entries"));
        actionHighlight_Whitelist_entries->setCheckable(true);
        actionJTTY = new QAction(MainWindow);
        actionJTTY->setObjectName(QString::fromUtf8("actionJTTY"));
        actionJTTY->setCheckable(true);
        actionFT2 = new QAction(MainWindow);
        actionFT2->setObjectName(QString::fromUtf8("actionFT2"));
        actionFT2->setCheckable(true);
        actionAccept_QMAP_click_events = new QAction(MainWindow);
        actionAccept_QMAP_click_events->setObjectName(QString::fromUtf8("actionAccept_QMAP_click_events"));
        actionAccept_QMAP_click_events->setCheckable(true);
        actionAccept_QMAP_click_events->setChecked(false);
        actionClaimQmapClicks = new QAction(MainWindow);
        actionClaimQmapClicks->setObjectName(QString::fromUtf8("actionClaimQmapClicks"));
        actionClaimQmapClicks->setCheckable(true);
        actionClaimQmapClicks->setChecked(false);
        actionQmapSourceAuto = new QAction(MainWindow);
        actionQmapSourceAuto->setObjectName(QString::fromUtf8("actionQmapSourceAuto"));
        actionQmapSourceAuto->setCheckable(true);
        actionQmapSourceAuto->setChecked(true);
        actionQmapSource1 = new QAction(MainWindow);
        actionQmapSource1->setObjectName(QString::fromUtf8("actionQmapSource1"));
        actionQmapSource1->setCheckable(true);
        actionQmapSource2 = new QAction(MainWindow);
        actionQmapSource2->setObjectName(QString::fromUtf8("actionQmapSource2"));
        actionQmapSource2->setCheckable(true);
        actionQmapSource3 = new QAction(MainWindow);
        actionQmapSource3->setObjectName(QString::fromUtf8("actionQmapSource3"));
        actionQmapSource3->setCheckable(true);
        actionQmapSource4 = new QAction(MainWindow);
        actionQmapSource4->setObjectName(QString::fromUtf8("actionQmapSource4"));
        actionQmapSource4->setCheckable(true);
        actionFSK441 = new QAction(MainWindow);
        actionFSK441->setObjectName(QString::fromUtf8("actionFSK441"));
        actionFSK441->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        decodes_splitter = new QSplitter(centralWidget);
        decodes_splitter->setObjectName(QString::fromUtf8("decodes_splitter"));
        decodes_splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(decodes_splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lh_decodes_title_label = new QLabel(layoutWidget);
        lh_decodes_title_label->setObjectName(QString::fromUtf8("lh_decodes_title_label"));
        lh_decodes_title_label->setMaximumSize(QSize(500, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        lh_decodes_title_label->setFont(font);
        lh_decodes_title_label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lh_decodes_title_label);

        lh_decodes_headings_label = new QLabel(layoutWidget);
        lh_decodes_headings_label->setObjectName(QString::fromUtf8("lh_decodes_headings_label"));
        lh_decodes_headings_label->setMinimumSize(QSize(300, 20));
        lh_decodes_headings_label->setMaximumSize(QSize(16777215, 20));
        QPalette palette;
        QBrush brush(QColor(252, 252, 252, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(170, 170, 170, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lh_decodes_headings_label->setPalette(palette);
        lh_decodes_headings_label->setAutoFillBackground(true);
        lh_decodes_headings_label->setTextFormat(Qt::PlainText);
        lh_decodes_headings_label->setIndent(5);

        verticalLayout_3->addWidget(lh_decodes_headings_label);

        decodedTextBrowser = new DisplayText(layoutWidget);
        decodedTextBrowser->setObjectName(QString::fromUtf8("decodedTextBrowser"));
        decodedTextBrowser->setFrameShape(QFrame::StyledPanel);
        decodedTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        decodedTextBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        decodedTextBrowser->setCursorWidth(0);
        decodedTextBrowser->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(decodedTextBrowser);

        decodes_splitter->addWidget(layoutWidget);
        rh_decodes_widget = new QWidget(decodes_splitter);
        rh_decodes_widget->setObjectName(QString::fromUtf8("rh_decodes_widget"));
        verticalLayout_9 = new QVBoxLayout(rh_decodes_widget);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        rh_decodes_title_label = new QLabel(rh_decodes_widget);
        rh_decodes_title_label->setObjectName(QString::fromUtf8("rh_decodes_title_label"));
        rh_decodes_title_label->setFont(font);
        rh_decodes_title_label->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(rh_decodes_title_label);

        rh_decodes_headings_label = new QLabel(rh_decodes_widget);
        rh_decodes_headings_label->setObjectName(QString::fromUtf8("rh_decodes_headings_label"));
        rh_decodes_headings_label->setMinimumSize(QSize(300, 20));
        rh_decodes_headings_label->setMaximumSize(QSize(16777215, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        rh_decodes_headings_label->setPalette(palette1);
        rh_decodes_headings_label->setAutoFillBackground(true);
        rh_decodes_headings_label->setTextFormat(Qt::PlainText);
        rh_decodes_headings_label->setIndent(5);

        verticalLayout_9->addWidget(rh_decodes_headings_label);

        decodedTextBrowser2 = new DisplayText(rh_decodes_widget);
        decodedTextBrowser2->setObjectName(QString::fromUtf8("decodedTextBrowser2"));
        decodedTextBrowser2->setEnabled(true);
        decodedTextBrowser2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        decodedTextBrowser2->setCursorWidth(0);
        decodedTextBrowser2->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_9->addWidget(decodedTextBrowser2);

        decodes_splitter->addWidget(rh_decodes_widget);

        verticalLayout_6->addWidget(decodes_splitter);

        lower_panel_widget = new QWidget(centralWidget);
        lower_panel_widget->setObjectName(QString::fromUtf8("lower_panel_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lower_panel_widget->sizePolicy().hasHeightForWidth());
        lower_panel_widget->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(lower_panel_widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        Band_buttons_Layout = new QGridLayout();
        Band_buttons_Layout->setSpacing(3);
        Band_buttons_Layout->setObjectName(QString::fromUtf8("Band_buttons_Layout"));
        pb40 = new QPushButton(lower_panel_widget);
        pb40->setObjectName(QString::fromUtf8("pb40"));
        pb40->setMinimumSize(QSize(20, 0));
        pb40->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb40, 0, 3, 1, 1);

        pb10 = new QPushButton(lower_panel_widget);
        pb10->setObjectName(QString::fromUtf8("pb10"));
        pb10->setMinimumSize(QSize(20, 0));
        pb10->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb10, 0, 9, 1, 1);

        pb17 = new QPushButton(lower_panel_widget);
        pb17->setObjectName(QString::fromUtf8("pb17"));
        pb17->setMinimumSize(QSize(20, 0));
        pb17->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb17, 0, 6, 1, 1);

        pb60 = new QPushButton(lower_panel_widget);
        pb60->setObjectName(QString::fromUtf8("pb60"));
        pb60->setMinimumSize(QSize(20, 0));

        Band_buttons_Layout->addWidget(pb60, 0, 2, 1, 1);

        pb12 = new QPushButton(lower_panel_widget);
        pb12->setObjectName(QString::fromUtf8("pb12"));
        pb12->setMinimumSize(QSize(20, 0));
        pb12->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb12, 0, 8, 1, 1);

        pb160 = new QPushButton(lower_panel_widget);
        pb160->setObjectName(QString::fromUtf8("pb160"));
        pb160->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb160, 0, 0, 1, 1);

        pb20 = new QPushButton(lower_panel_widget);
        pb20->setObjectName(QString::fromUtf8("pb20"));
        pb20->setMinimumSize(QSize(20, 0));
        pb20->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb20, 0, 5, 1, 1);

        pb80 = new QPushButton(lower_panel_widget);
        pb80->setObjectName(QString::fromUtf8("pb80"));
        pb80->setMinimumSize(QSize(20, 0));
        pb80->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb80, 0, 1, 1, 1);

        pb70 = new QPushButton(lower_panel_widget);
        pb70->setObjectName(QString::fromUtf8("pb70"));
        pb70->setMinimumSize(QSize(20, 0));
        pb70->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb70, 0, 13, 1, 1);

        pb15 = new QPushButton(lower_panel_widget);
        pb15->setObjectName(QString::fromUtf8("pb15"));
        pb15->setMinimumSize(QSize(20, 0));
        pb15->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb15, 0, 7, 1, 1);

        pb2 = new QPushButton(lower_panel_widget);
        pb2->setObjectName(QString::fromUtf8("pb2"));
        pb2->setMinimumSize(QSize(15, 0));
        pb2->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb2, 0, 11, 1, 1);

        pb30 = new QPushButton(lower_panel_widget);
        pb30->setObjectName(QString::fromUtf8("pb30"));
        pb30->setMinimumSize(QSize(20, 0));
        pb30->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb30, 0, 4, 1, 1);

        pb6 = new QPushButton(lower_panel_widget);
        pb6->setObjectName(QString::fromUtf8("pb6"));
        pb6->setMinimumSize(QSize(15, 0));
        pb6->setFocusPolicy(Qt::StrongFocus);

        Band_buttons_Layout->addWidget(pb6, 0, 10, 1, 1);

        pb24G = new QPushButton(lower_panel_widget);
        pb24G->setObjectName(QString::fromUtf8("pb24G"));
        pb24G->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb24G, 1, 13, 1, 1);

        pb10G = new QPushButton(lower_panel_widget);
        pb10G->setObjectName(QString::fromUtf8("pb10G"));
        pb10G->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb10G, 1, 11, 1, 1);

        pb5G = new QPushButton(lower_panel_widget);
        pb5G->setObjectName(QString::fromUtf8("pb5G"));
        pb5G->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb5G, 1, 10, 1, 1);

        pb9 = new QPushButton(lower_panel_widget);
        pb9->setObjectName(QString::fromUtf8("pb9"));
        pb9->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb9, 1, 9, 1, 1);

        pb13 = new QPushButton(lower_panel_widget);
        pb13->setObjectName(QString::fromUtf8("pb13"));
        pb13->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb13, 1, 8, 1, 1);

        pb23 = new QPushButton(lower_panel_widget);
        pb23->setObjectName(QString::fromUtf8("pb23"));
        pb23->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb23, 1, 7, 1, 1);

        pb902 = new QPushButton(lower_panel_widget);
        pb902->setObjectName(QString::fromUtf8("pb902"));
        pb902->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb902, 1, 6, 1, 1);

        pb432 = new QPushButton(lower_panel_widget);
        pb432->setObjectName(QString::fromUtf8("pb432"));
        pb432->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb432, 1, 5, 1, 1);

        pb220 = new QPushButton(lower_panel_widget);
        pb220->setObjectName(QString::fromUtf8("pb220"));
        pb220->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb220, 1, 4, 1, 1);

        pb144 = new QPushButton(lower_panel_widget);
        pb144->setObjectName(QString::fromUtf8("pb144"));
        pb144->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb144, 1, 3, 1, 1);

        pb4 = new QPushButton(lower_panel_widget);
        pb4->setObjectName(QString::fromUtf8("pb4"));
        pb4->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb4, 1, 2, 1, 1);

        pb50 = new QPushButton(lower_panel_widget);
        pb50->setObjectName(QString::fromUtf8("pb50"));
        pb50->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb50, 1, 1, 1, 1);

        pb8 = new QPushButton(lower_panel_widget);
        pb8->setObjectName(QString::fromUtf8("pb8"));
        pb8->setMinimumSize(QSize(25, 0));

        Band_buttons_Layout->addWidget(pb8, 1, 0, 1, 1);


        verticalLayout_4->addLayout(Band_buttons_Layout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cbCQonly = new QCheckBox(lower_panel_widget);
        cbCQonly->setObjectName(QString::fromUtf8("cbCQonly"));

        horizontalLayout_2->addWidget(cbCQonly);

        cbBypass = new QCheckBox(lower_panel_widget);
        cbBypass->setObjectName(QString::fromUtf8("cbBypass"));

        horizontalLayout_2->addWidget(cbBypass);

        logQSOButton = new QPushButton(lower_panel_widget);
        logQSOButton->setObjectName(QString::fromUtf8("logQSOButton"));
        logQSOButton->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(logQSOButton);

        stopButton = new QPushButton(lower_panel_widget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(stopButton);

        monitorButton = new QPushButton(lower_panel_widget);
        monitorButton->setObjectName(QString::fromUtf8("monitorButton"));
        monitorButton->setMinimumSize(QSize(50, 0));
        monitorButton->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    color: #000000;\n"
"	background-color: #00ff00;\n"
"    border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"    border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        monitorButton->setCheckable(true);
        monitorButton->setChecked(false);

        horizontalLayout_2->addWidget(monitorButton);

        EraseButton = new QPushButton(lower_panel_widget);
        EraseButton->setObjectName(QString::fromUtf8("EraseButton"));
        EraseButton->setMinimumSize(QSize(50, 0));
        EraseButton->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_2->addWidget(EraseButton);

        ClrAvgButton = new QPushButton(lower_panel_widget);
        ClrAvgButton->setObjectName(QString::fromUtf8("ClrAvgButton"));
        ClrAvgButton->setEnabled(true);
        ClrAvgButton->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(ClrAvgButton);

        sbEchoAvg = new HintedSpinBox(lower_panel_widget);
        sbEchoAvg->setObjectName(QString::fromUtf8("sbEchoAvg"));
        sbEchoAvg->setMinimum(1);
        sbEchoAvg->setMaximum(100);
        sbEchoAvg->setValue(10);

        horizontalLayout_2->addWidget(sbEchoAvg);

        DecodeButton = new QPushButton(lower_panel_widget);
        DecodeButton->setObjectName(QString::fromUtf8("DecodeButton"));
        DecodeButton->setMinimumSize(QSize(50, 0));
        DecodeButton->setFocusPolicy(Qt::StrongFocus);
        DecodeButton->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: cyan;\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        DecodeButton->setCheckable(true);

        horizontalLayout_2->addWidget(DecodeButton);

        autoButton = new QPushButton(lower_panel_widget);
        autoButton->setObjectName(QString::fromUtf8("autoButton"));
        autoButton->setMinimumSize(QSize(0, 0));
        autoButton->setFocusPolicy(Qt::StrongFocus);
        autoButton->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"	color: white;\n"
"	background-color: red;\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        autoButton->setCheckable(true);

        horizontalLayout_2->addWidget(autoButton);

        stopTxButton = new QPushButton(lower_panel_widget);
        stopTxButton->setObjectName(QString::fromUtf8("stopTxButton"));
        stopTxButton->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(stopTxButton);

        tuneButton = new QPushButton(lower_panel_widget);
        tuneButton->setObjectName(QString::fromUtf8("tuneButton"));
        tuneButton->setMinimumSize(QSize(50, 0));
        tuneButton->setFocusPolicy(Qt::StrongFocus);
        tuneButton->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"	color: white;\n"
"	background-color: red;\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        tuneButton->setCheckable(true);

        horizontalLayout_2->addWidget(tuneButton);

        cbMenus = new QCheckBox(lower_panel_widget);
        cbMenus->setObjectName(QString::fromUtf8("cbMenus"));
        cbMenus->setChecked(true);

        horizontalLayout_2->addWidget(cbMenus);

        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 2);
        horizontalLayout_2->setStretch(4, 2);
        horizontalLayout_2->setStretch(5, 2);
        horizontalLayout_2->setStretch(6, 2);
        horizontalLayout_2->setStretch(8, 2);
        horizontalLayout_2->setStretch(9, 2);
        horizontalLayout_2->setStretch(10, 2);
        horizontalLayout_2->setStretch(11, 2);
        horizontalLayout_2->setStretch(12, 1);

        verticalLayout_4->addLayout(horizontalLayout_2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        DX_controls_widget = new QWidget(lower_panel_widget);
        DX_controls_widget->setObjectName(QString::fromUtf8("DX_controls_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DX_controls_widget->sizePolicy().hasHeightForWidth());
        DX_controls_widget->setSizePolicy(sizePolicy1);
        DX_controls_widget->setMinimumSize(QSize(0, 0));
        verticalLayout_110 = new QVBoxLayout(DX_controls_widget);
        verticalLayout_110->setSpacing(6);
        verticalLayout_110->setContentsMargins(11, 11, 11, 11);
        verticalLayout_110->setObjectName(QString::fromUtf8("verticalLayout_110"));
        verticalLayout_110->setContentsMargins(0, 0, 0, 1);
        DXCall_gridLayout = new QGridLayout();
        DXCall_gridLayout->setSpacing(6);
        DXCall_gridLayout->setObjectName(QString::fromUtf8("DXCall_gridLayout"));
        DX_Call_Button = new QPushButton(DX_controls_widget);
        DX_Call_Button->setObjectName(QString::fromUtf8("DX_Call_Button"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DX_Call_Button->sizePolicy().hasHeightForWidth());
        DX_Call_Button->setSizePolicy(sizePolicy2);
        DX_Call_Button->setMinimumSize(QSize(0, 0));
        DX_Call_Button->setFocusPolicy(Qt::StrongFocus);
        DX_Call_Button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #9fafd5;\n"
"    border: none;\n"
"}"));
        DX_Call_Button->setCheckable(true);

        DXCall_gridLayout->addWidget(DX_Call_Button, 0, 0, 1, 1);

        dxGridEntry = new QLineEdit(DX_controls_widget);
        dxGridEntry->setObjectName(QString::fromUtf8("dxGridEntry"));
        dxGridEntry->setAlignment(Qt::AlignCenter);

        DXCall_gridLayout->addWidget(dxGridEntry, 1, 1, 1, 1);

        label_4 = new QLabel(DX_controls_widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(159, 175, 213, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_4->setPalette(palette2);
        label_4->setAutoFillBackground(true);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setMargin(5);
        label_4->setIndent(2);

        DXCall_gridLayout->addWidget(label_4, 0, 1, 1, 1);

        dxCallEntry = new QLineEdit(DX_controls_widget);
        dxCallEntry->setObjectName(QString::fromUtf8("dxCallEntry"));
        dxCallEntry->setAlignment(Qt::AlignCenter);

        DXCall_gridLayout->addWidget(dxCallEntry, 1, 0, 1, 1);

        DXCall_gridLayout->setColumnStretch(0, 3);
        DXCall_gridLayout->setColumnStretch(1, 2);

        verticalLayout_110->addLayout(DXCall_gridLayout);

        labAz = new QLabel(DX_controls_widget);
        labAz->setObjectName(QString::fromUtf8("labAz"));
        sizePolicy3.setHeightForWidth(labAz->sizePolicy().hasHeightForWidth());
        labAz->setSizePolicy(sizePolicy3);
        labAz->setAutoFillBackground(true);
        labAz->setAlignment(Qt::AlignCenter);
        labAz->setIndent(4);

        verticalLayout_110->addWidget(labAz);

        lookup_control_layout = new QHBoxLayout();
        lookup_control_layout->setSpacing(3);
        lookup_control_layout->setObjectName(QString::fromUtf8("lookup_control_layout"));
        lookupButton = new QPushButton(DX_controls_widget);
        lookupButton->setObjectName(QString::fromUtf8("lookupButton"));
        sizePolicy1.setHeightForWidth(lookupButton->sizePolicy().hasHeightForWidth());
        lookupButton->setSizePolicy(sizePolicy1);
        lookupButton->setMinimumSize(QSize(50, 0));
        lookupButton->setFocusPolicy(Qt::StrongFocus);

        lookup_control_layout->addWidget(lookupButton);

        addButton = new QPushButton(DX_controls_widget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(40, 0));
        addButton->setFocusPolicy(Qt::StrongFocus);

        lookup_control_layout->addWidget(addButton);

        ignoreButton = new QPushButton(DX_controls_widget);
        ignoreButton->setObjectName(QString::fromUtf8("ignoreButton"));
        ignoreButton->setMinimumSize(QSize(50, 0));
        ignoreButton->setFocusPolicy(Qt::StrongFocus);

        lookup_control_layout->addWidget(ignoreButton);


        verticalLayout_110->addLayout(lookup_control_layout);


        gridLayout_5->addWidget(DX_controls_widget, 1, 4, 1, 2);

        outAttenuation = new QSlider(lower_panel_widget);
        outAttenuation->setObjectName(QString::fromUtf8("outAttenuation"));
        outAttenuation->setMaximum(450);
        outAttenuation->setValue(0);
        outAttenuation->setOrientation(Qt::Vertical);
        outAttenuation->setInvertedAppearance(true);
        outAttenuation->setInvertedControls(true);
        outAttenuation->setTickPosition(QSlider::TicksBelow);
        outAttenuation->setTickInterval(50);

        gridLayout_5->addWidget(outAttenuation, 1, 7, 2, 1);

        label = new QLabel(lower_panel_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 7, 1, 1);

        controls_stack_widget = new QStackedWidget(lower_panel_widget);
        controls_stack_widget->setObjectName(QString::fromUtf8("controls_stack_widget"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(controls_stack_widget->sizePolicy().hasHeightForWidth());
        controls_stack_widget->setSizePolicy(sizePolicy4);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_8 = new QHBoxLayout(page);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        QSO_controls_widget = new QWidget(page);
        QSO_controls_widget->setObjectName(QString::fromUtf8("QSO_controls_widget"));
        sizePolicy4.setHeightForWidth(QSO_controls_widget->sizePolicy().hasHeightForWidth());
        QSO_controls_widget->setSizePolicy(sizePolicy4);
        horizontalLayout_6 = new QHBoxLayout(QSO_controls_widget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        sbCQTxFreq = new QSpinBox(QSO_controls_widget);
        sbCQTxFreq->setObjectName(QString::fromUtf8("sbCQTxFreq"));
        sbCQTxFreq->setEnabled(false);
        sbCQTxFreq->setMinimum(1);
        sbCQTxFreq->setMaximum(999);
        sbCQTxFreq->setValue(260);

        horizontalLayout_11->addWidget(sbCQTxFreq);

        cbCQTx = new QCheckBox(QSO_controls_widget);
        cbCQTx->setObjectName(QString::fromUtf8("cbCQTx"));
        cbCQTx->setEnabled(false);

        horizontalLayout_11->addWidget(cbCQTx);

        cbRxAll = new QCheckBox(QSO_controls_widget);
        cbRxAll->setObjectName(QString::fromUtf8("cbRxAll"));

        horizontalLayout_11->addWidget(cbRxAll);


        gridLayout_3->addLayout(horizontalLayout_11, 1, 0, 1, 2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        labDXped = new QLabel(QSO_controls_widget);
        labDXped->setObjectName(QString::fromUtf8("labDXped"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(labDXped->sizePolicy().hasHeightForWidth());
        labDXped->setSizePolicy(sizePolicy5);
        labDXped->setMaximumSize(QSize(100, 16777215));
        labDXped->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(labDXped);

        cbSWL = new QCheckBox(QSO_controls_widget);
        cbSWL->setObjectName(QString::fromUtf8("cbSWL"));

        horizontalLayout_15->addWidget(cbSWL);

        pbBestSP = new QPushButton(QSO_controls_widget);
        pbBestSP->setObjectName(QString::fromUtf8("pbBestSP"));
        pbBestSP->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: red;\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        pbBestSP->setCheckable(true);

        horizontalLayout_15->addWidget(pbBestSP);

        measure_check_box = new QCheckBox(QSO_controls_widget);
        measure_check_box->setObjectName(QString::fromUtf8("measure_check_box"));

        horizontalLayout_15->addWidget(measure_check_box);


        gridLayout_3->addLayout(horizontalLayout_15, 3, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        cbShMsgs = new QCheckBox(QSO_controls_widget);
        cbShMsgs->setObjectName(QString::fromUtf8("cbShMsgs"));

        horizontalLayout_5->addWidget(cbShMsgs);

        cbFast9 = new QCheckBox(QSO_controls_widget);
        cbFast9->setObjectName(QString::fromUtf8("cbFast9"));

        horizontalLayout_5->addWidget(cbFast9);

        cbAutoSeq = new QCheckBox(QSO_controls_widget);
        cbAutoSeq->setObjectName(QString::fromUtf8("cbAutoSeq"));

        horizontalLayout_5->addWidget(cbAutoSeq);

        respondComboBox = new QComboBox(QSO_controls_widget);
        respondComboBox->setObjectName(QString::fromUtf8("respondComboBox"));
        respondComboBox->setMaxVisibleItems(5);

        horizontalLayout_5->addWidget(respondComboBox);

        cbTx6 = new QCheckBox(QSO_controls_widget);
        cbTx6->setObjectName(QString::fromUtf8("cbTx6"));
        cbTx6->setEnabled(false);

        horizontalLayout_5->addWidget(cbTx6);


        gridLayout_3->addLayout(horizontalLayout_5, 2, 0, 1, 2);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        txFirstCheckBox = new QCheckBox(QSO_controls_widget);
        txFirstCheckBox->setObjectName(QString::fromUtf8("txFirstCheckBox"));
        txFirstCheckBox->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_14->addWidget(txFirstCheckBox);

        TxFreqSpinBox = new QSpinBox(QSO_controls_widget);
        TxFreqSpinBox->setObjectName(QString::fromUtf8("TxFreqSpinBox"));
        TxFreqSpinBox->setAlignment(Qt::AlignCenter);
        TxFreqSpinBox->setMinimum(200);
        TxFreqSpinBox->setMaximum(5000);
        TxFreqSpinBox->setValue(1500);

        verticalLayout_14->addWidget(TxFreqSpinBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pbR2T = new QPushButton(QSO_controls_widget);
        pbR2T->setObjectName(QString::fromUtf8("pbR2T"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pbR2T->sizePolicy().hasHeightForWidth());
        pbR2T->setSizePolicy(sizePolicy6);
        pbR2T->setMinimumSize(QSize(15, 0));
        pbR2T->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_4->addWidget(pbR2T);

        sbFtol = new HintedSpinBox(QSO_controls_widget);
        sbFtol->setObjectName(QString::fromUtf8("sbFtol"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(sbFtol->sizePolicy().hasHeightForWidth());
        sbFtol->setSizePolicy(sizePolicy7);
        sbFtol->setAlignment(Qt::AlignCenter);
        sbFtol->setMinimum(1);
        sbFtol->setMaximum(1000);
        sbFtol->setValue(10);

        horizontalLayout_4->addWidget(sbFtol);

        pbT2R = new QPushButton(QSO_controls_widget);
        pbT2R->setObjectName(QString::fromUtf8("pbT2R"));
        sizePolicy6.setHeightForWidth(pbT2R->sizePolicy().hasHeightForWidth());
        pbT2R->setSizePolicy(sizePolicy6);
        pbT2R->setMinimumSize(QSize(15, 0));
        pbT2R->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_4->addWidget(pbT2R);

        horizontalLayout_4->setStretch(1, 6);

        verticalLayout_14->addLayout(horizontalLayout_4);

        RxFreqSpinBox = new QSpinBox(QSO_controls_widget);
        RxFreqSpinBox->setObjectName(QString::fromUtf8("RxFreqSpinBox"));
        RxFreqSpinBox->setAlignment(Qt::AlignCenter);
        RxFreqSpinBox->setMinimum(200);
        RxFreqSpinBox->setMaximum(5000);
        RxFreqSpinBox->setValue(1500);

        verticalLayout_14->addWidget(RxFreqSpinBox);

        rptSpinBox = new QSpinBox(QSO_controls_widget);
        rptSpinBox->setObjectName(QString::fromUtf8("rptSpinBox"));
        rptSpinBox->setAlignment(Qt::AlignCenter);
        rptSpinBox->setMinimum(-50);
        rptSpinBox->setMaximum(49);
        rptSpinBox->setValue(-15);

        verticalLayout_14->addWidget(rptSpinBox);

        sbTR = new RestrictedSpinBox(QSO_controls_widget);
        sbTR->setObjectName(QString::fromUtf8("sbTR"));
        sbTR->setAlignment(Qt::AlignCenter);
        sbTR->setMinimum(5);
        sbTR->setMaximum(1800);
        sbTR->setValue(30);

        verticalLayout_14->addWidget(sbTR);


        gridLayout_3->addLayout(verticalLayout_14, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 4, 0, 1, 1);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        submode_gridLayout = new QGridLayout();
        submode_gridLayout->setSpacing(6);
        submode_gridLayout->setObjectName(QString::fromUtf8("submode_gridLayout"));
        submode_gridLayout->setHorizontalSpacing(4);
        pb15C = new QPushButton(QSO_controls_widget);
        pb15C->setObjectName(QString::fromUtf8("pb15C"));
        pb15C->setMinimumSize(QSize(30, 0));

        submode_gridLayout->addWidget(pb15C, 0, 1, 1, 1);

        pb15A = new QPushButton(QSO_controls_widget);
        pb15A->setObjectName(QString::fromUtf8("pb15A"));
        pb15A->setMinimumSize(QSize(32, 0));

        submode_gridLayout->addWidget(pb15A, 0, 0, 1, 1);

        pb30B = new QPushButton(QSO_controls_widget);
        pb30B->setObjectName(QString::fromUtf8("pb30B"));
        pb30B->setMinimumSize(QSize(32, 0));

        submode_gridLayout->addWidget(pb30B, 0, 2, 1, 1);

        pb60C = new QPushButton(QSO_controls_widget);
        pb60C->setObjectName(QString::fromUtf8("pb60C"));
        pb60C->setMinimumSize(QSize(30, 0));

        submode_gridLayout->addWidget(pb60C, 1, 0, 1, 1);

        pb60D = new QPushButton(QSO_controls_widget);
        pb60D->setObjectName(QString::fromUtf8("pb60D"));
        pb60D->setMinimumSize(QSize(30, 0));

        submode_gridLayout->addWidget(pb60D, 1, 1, 1, 1);

        pb60E = new QPushButton(QSO_controls_widget);
        pb60E->setObjectName(QString::fromUtf8("pb60E"));
        pb60E->setMinimumSize(QSize(30, 0));

        submode_gridLayout->addWidget(pb60E, 1, 2, 1, 1);


        verticalLayout_13->addLayout(submode_gridLayout);

        cbHoldTxFreq = new QCheckBox(QSO_controls_widget);
        cbHoldTxFreq->setObjectName(QString::fromUtf8("cbHoldTxFreq"));

        verticalLayout_13->addWidget(cbHoldTxFreq);

        opt_controls_stack = new QStackedWidget(QSO_controls_widget);
        opt_controls_stack->setObjectName(QString::fromUtf8("opt_controls_stack"));
        page_0 = new QWidget();
        page_0->setObjectName(QString::fromUtf8("page_0"));
        verticalLayout = new QVBoxLayout(page_0);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sbSerialNumber = new QSpinBox(page_0);
        sbSerialNumber->setObjectName(QString::fromUtf8("sbSerialNumber"));
        sbSerialNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbSerialNumber->setMinimum(1);
        sbSerialNumber->setMaximum(4095);

        verticalLayout->addWidget(sbSerialNumber);

        opt_controls_stack->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        verticalLayout_10 = new QVBoxLayout(page_1);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        sbF_Low = new QSpinBox(page_1);
        sbF_Low->setObjectName(QString::fromUtf8("sbF_Low"));
        sbF_Low->setAlignment(Qt::AlignCenter);
        sbF_Low->setMinimum(100);
        sbF_Low->setMaximum(5000);
        sbF_Low->setSingleStep(50);
        sbF_Low->setValue(600);

        verticalLayout_10->addWidget(sbF_Low);

        sbF_High = new QSpinBox(page_1);
        sbF_High->setObjectName(QString::fromUtf8("sbF_High"));
        sbF_High->setAlignment(Qt::AlignCenter);
        sbF_High->setMinimum(100);
        sbF_High->setMaximum(5000);
        sbF_High->setSingleStep(50);
        sbF_High->setValue(1400);

        verticalLayout_10->addWidget(sbF_High);

        opt_controls_stack->addWidget(page_1);

        verticalLayout_13->addWidget(opt_controls_stack);

        sbSubmode = new LettersSpinBox(QSO_controls_widget);
        sbSubmode->setObjectName(QString::fromUtf8("sbSubmode"));
        sbSubmode->setAlignment(Qt::AlignCenter);
        sbSubmode->setMinimum(0);
        sbSubmode->setMaximum(7);

        verticalLayout_13->addWidget(sbSubmode);

        syncSpinBox = new QSpinBox(QSO_controls_widget);
        syncSpinBox->setObjectName(QString::fromUtf8("syncSpinBox"));
        syncSpinBox->setAlignment(Qt::AlignCenter);
        syncSpinBox->setMinimum(-1);
        syncSpinBox->setMaximum(10);
        syncSpinBox->setValue(1);

        verticalLayout_13->addWidget(syncSpinBox);

        sbMaxDrift = new QSpinBox(QSO_controls_widget);
        sbMaxDrift->setObjectName(QString::fromUtf8("sbMaxDrift"));
        sbMaxDrift->setAlignment(Qt::AlignCenter);
        sbMaxDrift->setMaximum(50);
        sbMaxDrift->setSingleStep(5);

        verticalLayout_13->addWidget(sbMaxDrift);

        claimQmapToolButton = new QToolButton(QSO_controls_widget);
        claimQmapToolButton->setObjectName(QString::fromUtf8("claimQmapToolButton"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(claimQmapToolButton->sizePolicy().hasHeightForWidth());
        claimQmapToolButton->setSizePolicy(sizePolicy8);
        claimQmapToolButton->setMinimumSize(QSize(90, 0));
        claimQmapToolButton->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_13->addWidget(claimQmapToolButton, 0, Qt::AlignHCenter);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_6);


        gridLayout_3->addLayout(verticalLayout_13, 0, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_3);

        tabWidget = new QTabWidget(QSO_controls_widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy9(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy9);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_7 = new QGridLayout(tab);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        txrb6 = new QRadioButton(tab);
        txrb6->setObjectName(QString::fromUtf8("txrb6"));
        txrb6->setStyleSheet(QString::fromUtf8("margin-left: 10%; margin-right: 0%"));
        txrb6->setChecked(true);

        gridLayout_6->addWidget(txrb6, 6, 1, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_5, 0, 1, 1, 1);

        tx1 = new QLineEdit(tab);
        tx1->setObjectName(QString::fromUtf8("tx1"));
        sizePolicy3.setHeightForWidth(tx1->sizePolicy().hasHeightForWidth());
        tx1->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(tx1, 1, 0, 1, 1);

        txrb4 = new DoubleClickableRadioButton(tab);
        txrb4->setObjectName(QString::fromUtf8("txrb4"));
        txrb4->setStyleSheet(QString::fromUtf8("margin-left: 10%; margin-right: 0%"));

        gridLayout_6->addWidget(txrb4, 4, 1, 1, 1);

        txrb1 = new DoubleClickableRadioButton(tab);
        txrb1->setObjectName(QString::fromUtf8("txrb1"));
        txrb1->setStyleSheet(QString::fromUtf8("margin-left: 10%; margin-right: 0%"));

        gridLayout_6->addWidget(txrb1, 1, 1, 1, 1);

        tx6 = new QLineEdit(tab);
        tx6->setObjectName(QString::fromUtf8("tx6"));
        sizePolicy3.setHeightForWidth(tx6->sizePolicy().hasHeightForWidth());
        tx6->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(tx6, 6, 0, 1, 1);

        txb5 = new DoubleClickablePushButton(tab);
        txb5->setObjectName(QString::fromUtf8("txb5"));
        txb5->setFocusPolicy(Qt::StrongFocus);
        txb5->setStyleSheet(QString::fromUtf8("padding-left: 15%; padding-right: 15%; padding-top: 3%; padding-bottom: 3%"));

        gridLayout_6->addWidget(txb5, 5, 2, 1, 1);

        txb2 = new QPushButton(tab);
        txb2->setObjectName(QString::fromUtf8("txb2"));
        txb2->setStyleSheet(QString::fromUtf8("padding-left: 15%; padding-right: 15%; padding-top: 3%; padding-bottom: 3%"));

        gridLayout_6->addWidget(txb2, 2, 2, 1, 1);

        tx2 = new QLineEdit(tab);
        tx2->setObjectName(QString::fromUtf8("tx2"));
        sizePolicy3.setHeightForWidth(tx2->sizePolicy().hasHeightForWidth());
        tx2->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(tx2, 2, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_2, 0, 2, 1, 1);

        txrb2 = new QRadioButton(tab);
        txrb2->setObjectName(QString::fromUtf8("txrb2"));
        txrb2->setStyleSheet(QString::fromUtf8("margin-left: 10%; margin-right: 0%"));

        gridLayout_6->addWidget(txrb2, 2, 1, 1, 1);

        tx4 = new QLineEdit(tab);
        tx4->setObjectName(QString::fromUtf8("tx4"));
        sizePolicy3.setHeightForWidth(tx4->sizePolicy().hasHeightForWidth());
        tx4->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(tx4, 4, 0, 1, 1);

        tx3 = new QLineEdit(tab);
        tx3->setObjectName(QString::fromUtf8("tx3"));
        sizePolicy3.setHeightForWidth(tx3->sizePolicy().hasHeightForWidth());
        tx3->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(tx3, 3, 0, 1, 1);

        genStdMsgsPushButton = new QPushButton(tab);
        genStdMsgsPushButton->setObjectName(QString::fromUtf8("genStdMsgsPushButton"));

        gridLayout_6->addWidget(genStdMsgsPushButton, 0, 0, 1, 1);

        txb3 = new QPushButton(tab);
        txb3->setObjectName(QString::fromUtf8("txb3"));
        txb3->setStyleSheet(QString::fromUtf8("padding-left: 15%; padding-right: 15%; padding-top: 3%; padding-bottom: 3%"));

        gridLayout_6->addWidget(txb3, 3, 2, 1, 1);

        txb4 = new DoubleClickablePushButton(tab);
        txb4->setObjectName(QString::fromUtf8("txb4"));
        txb4->setStyleSheet(QString::fromUtf8("padding-left: 15%; padding-right: 15%; padding-top: 3%; padding-bottom: 3%"));

        gridLayout_6->addWidget(txb4, 4, 2, 1, 1);

        txb1 = new DoubleClickablePushButton(tab);
        txb1->setObjectName(QString::fromUtf8("txb1"));
        txb1->setLayoutDirection(Qt::LeftToRight);
        txb1->setStyleSheet(QString::fromUtf8("padding-left: 15%; padding-right: 15%; padding-top: 3%; padding-bottom: 3%"));

        gridLayout_6->addWidget(txb1, 1, 2, 1, 1);

        txb6 = new QPushButton(tab);
        txb6->setObjectName(QString::fromUtf8("txb6"));
        txb6->setStyleSheet(QString::fromUtf8("padding-left: 15%; padding-right: 15%; padding-top: 3%; padding-bottom: 3%"));

        gridLayout_6->addWidget(txb6, 6, 2, 1, 1);

        txrb3 = new QRadioButton(tab);
        txrb3->setObjectName(QString::fromUtf8("txrb3"));
        txrb3->setStyleSheet(QString::fromUtf8("margin-left: 10%; margin-right: 0%"));

        gridLayout_6->addWidget(txrb3, 3, 1, 1, 1);

        tx5 = new QComboBox(tab);
        tx5->setObjectName(QString::fromUtf8("tx5"));
        tx5->setEditable(true);
        tx5->setInsertPolicy(QComboBox::InsertAtBottom);

        gridLayout_6->addWidget(tx5, 5, 0, 1, 1);

        txrb5 = new DoubleClickableRadioButton(tab);
        txrb5->setObjectName(QString::fromUtf8("txrb5"));
        txrb5->setStyleSheet(QString::fromUtf8("margin-left: 10%; margin-right: 0%"));

        gridLayout_6->addWidget(txrb5, 5, 1, 1, 1);

        gridLayout_6->setColumnStretch(0, 1);

        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_11 = new QGridLayout(tab_3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setHorizontalSpacing(4);
        gridLayout_11->setContentsMargins(4, 4, 4, 4);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        cbSendMsg = new QCheckBox(tab_3);
        cbSendMsg->setObjectName(QString::fromUtf8("cbSendMsg"));

        gridLayout->addWidget(cbSendMsg, 8, 2, 1, 1);

        pbFreeText = new QPushButton(tab_3);
        pbFreeText->setObjectName(QString::fromUtf8("pbFreeText"));

        gridLayout->addWidget(pbFreeText, 7, 2, 1, 1);

        comboBoxCQ = new QComboBox(tab_3);
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->addItem(QString());
        comboBoxCQ->setObjectName(QString::fromUtf8("comboBoxCQ"));

        gridLayout->addWidget(comboBoxCQ, 4, 2, 1, 1);

        label_queue = new QLabel(tab_3);
        label_queue->setObjectName(QString::fromUtf8("label_queue"));
        QFont font1;
        font1.setPointSize(9);
        label_queue->setFont(font1);
        label_queue->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_queue, 0, 0, 1, 1);

        cbWorkDupes = new QCheckBox(tab_3);
        cbWorkDupes->setObjectName(QString::fromUtf8("cbWorkDupes"));

        gridLayout->addWidget(cbWorkDupes, 0, 2, 1, 1);

        pbFoxReset = new QPushButton(tab_3);
        pbFoxReset->setObjectName(QString::fromUtf8("pbFoxReset"));

        gridLayout->addWidget(pbFoxReset, 6, 2, 1, 1);

        sbNlist = new QSpinBox(tab_3);
        sbNlist->setObjectName(QString::fromUtf8("sbNlist"));
        sizePolicy1.setHeightForWidth(sbNlist->sizePolicy().hasHeightForWidth());
        sbNlist->setSizePolicy(sizePolicy1);
        sbNlist->setMaximumSize(QSize(16777215, 16777215));
        sbNlist->setMinimum(5);
        sbNlist->setMaximum(100);
        sbNlist->setValue(12);

        gridLayout->addWidget(sbNlist, 2, 2, 1, 1);

        comboBoxHoundSort = new QComboBox(tab_3);
        comboBoxHoundSort->addItem(QString());
        comboBoxHoundSort->addItem(QString());
        comboBoxHoundSort->addItem(QString());
        comboBoxHoundSort->addItem(QString());
        comboBoxHoundSort->addItem(QString());
        comboBoxHoundSort->addItem(QString());
        comboBoxHoundSort->addItem(QString());
        comboBoxHoundSort->addItem(QString());
        comboBoxHoundSort->setObjectName(QString::fromUtf8("comboBoxHoundSort"));
        sizePolicy1.setHeightForWidth(comboBoxHoundSort->sizePolicy().hasHeightForWidth());
        comboBoxHoundSort->setSizePolicy(sizePolicy1);
        comboBoxHoundSort->setMaximumSize(QSize(16777215, 16777215));
        comboBoxHoundSort->setMaxVisibleItems(8);

        gridLayout->addWidget(comboBoxHoundSort, 1, 2, 1, 1);

        cbMoreCQs = new QCheckBox(tab_3);
        cbMoreCQs->setObjectName(QString::fromUtf8("cbMoreCQs"));

        gridLayout->addWidget(cbMoreCQs, 5, 2, 1, 1);

        label_inProcess = new QLabel(tab_3);
        label_inProcess->setObjectName(QString::fromUtf8("label_inProcess"));
        label_inProcess->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_inProcess, 0, 1, 1, 1);

        sbNslots = new QSpinBox(tab_3);
        sbNslots->setObjectName(QString::fromUtf8("sbNslots"));
        sizePolicy1.setHeightForWidth(sbNslots->sizePolicy().hasHeightForWidth());
        sbNslots->setSizePolicy(sizePolicy1);
        sbNslots->setMaximumSize(QSize(16777215, 16777215));
        sbNslots->setMinimum(1);
        sbNslots->setMaximum(5);
        sbNslots->setValue(1);
        sbNslots->setDisplayIntegerBase(10);

        gridLayout->addWidget(sbNslots, 3, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 2, 1, 1);

        foxTxListTextBrowser = new DisplayText(tab_3);
        foxTxListTextBrowser->setObjectName(QString::fromUtf8("foxTxListTextBrowser"));
        foxTxListTextBrowser->setEnabled(true);
        sizePolicy9.setHeightForWidth(foxTxListTextBrowser->sizePolicy().hasHeightForWidth());
        foxTxListTextBrowser->setSizePolicy(sizePolicy9);
        foxTxListTextBrowser->setMaximumSize(QSize(16777215, 16777215));
        foxTxListTextBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(foxTxListTextBrowser, 1, 1, 9, 1);

        houndQueueTextBrowser = new DisplayText(tab_3);
        houndQueueTextBrowser->setObjectName(QString::fromUtf8("houndQueueTextBrowser"));
        sizePolicy9.setHeightForWidth(houndQueueTextBrowser->sizePolicy().hasHeightForWidth());
        houndQueueTextBrowser->setSizePolicy(sizePolicy9);
        houndQueueTextBrowser->setMaximumSize(QSize(16777215, 16777215));
        houndQueueTextBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(houndQueueTextBrowser, 1, 0, 9, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);

        gridLayout_11->addLayout(gridLayout, 0, 0, 2, 1);

        gridLayout_11->setColumnStretch(0, 1);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_13 = new QGridLayout(tab_4);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(2, 3, 0, 1);
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(0);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        widget_3 = new QWidget(tab_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);
        gridLayout_8 = new QGridLayout(widget_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(1);
        gridLayout_8->setVerticalSpacing(6);
        gridLayout_8->setContentsMargins(0, 0, 1, 0);
        cb70cm = new QCheckBox(widget_3);
        cb70cm->setObjectName(QString::fromUtf8("cb70cm"));

        gridLayout_8->addWidget(cb70cm, 7, 1, 1, 1);

        cb30m = new QCheckBox(widget_3);
        cb30m->setObjectName(QString::fromUtf8("cb30m"));

        gridLayout_8->addWidget(cb30m, 5, 0, 1, 1);

        pbBandHopping = new QPushButton(widget_3);
        pbBandHopping->setObjectName(QString::fromUtf8("pbBandHopping"));
        pbBandHopping->setMinimumSize(QSize(0, 34));
        pbBandHopping->setFocusPolicy(Qt::StrongFocus);
        pbBandHopping->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"	background-color: red;\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        pbBandHopping->setCheckable(true);

        gridLayout_8->addWidget(pbBandHopping, 8, 0, 2, 2);

        cb12m = new QCheckBox(widget_3);
        cb12m->setObjectName(QString::fromUtf8("cb12m"));

        gridLayout_8->addWidget(cb12m, 2, 1, 1, 1);

        cb40m = new QCheckBox(widget_3);
        cb40m->setObjectName(QString::fromUtf8("cb40m"));

        gridLayout_8->addWidget(cb40m, 4, 0, 1, 1);

        cb2mMSK = new QCheckBox(widget_3);
        cb2mMSK->setObjectName(QString::fromUtf8("cb2mMSK"));

        gridLayout_8->addWidget(cb2mMSK, 9, 2, 1, 1);

        cb10m = new QCheckBox(widget_3);
        cb10m->setObjectName(QString::fromUtf8("cb10m"));

        gridLayout_8->addWidget(cb10m, 3, 1, 1, 1);

        cb6m = new QCheckBox(widget_3);
        cb6m->setObjectName(QString::fromUtf8("cb6m"));

        gridLayout_8->addWidget(cb6m, 4, 1, 1, 1);

        cb60m = new QCheckBox(widget_3);
        cb60m->setObjectName(QString::fromUtf8("cb60m"));

        gridLayout_8->addWidget(cb60m, 3, 0, 1, 1);

        cb160m = new QCheckBox(widget_3);
        cb160m->setObjectName(QString::fromUtf8("cb160m"));
        sizePolicy6.setHeightForWidth(cb160m->sizePolicy().hasHeightForWidth());
        cb160m->setSizePolicy(sizePolicy6);

        gridLayout_8->addWidget(cb160m, 1, 0, 1, 1);

        cb80m = new QCheckBox(widget_3);
        cb80m->setObjectName(QString::fromUtf8("cb80m"));

        gridLayout_8->addWidget(cb80m, 2, 0, 1, 1);

        cb20m = new QCheckBox(widget_3);
        cb20m->setObjectName(QString::fromUtf8("cb20m"));

        gridLayout_8->addWidget(cb20m, 6, 0, 1, 1);

        cb17m = new QCheckBox(widget_3);
        cb17m->setObjectName(QString::fromUtf8("cb17m"));

        gridLayout_8->addWidget(cb17m, 7, 0, 1, 1);

        cb4m = new QCheckBox(widget_3);
        cb4m->setObjectName(QString::fromUtf8("cb4m"));

        gridLayout_8->addWidget(cb4m, 5, 1, 1, 1);

        cb15m = new QCheckBox(widget_3);
        cb15m->setObjectName(QString::fromUtf8("cb15m"));

        gridLayout_8->addWidget(cb15m, 1, 1, 1, 1);

        cb2m = new QCheckBox(widget_3);
        cb2m->setObjectName(QString::fromUtf8("cb2m"));

        gridLayout_8->addWidget(cb2m, 6, 1, 1, 1);

        cb10mFT4 = new QCheckBox(widget_3);
        cb10mFT4->setObjectName(QString::fromUtf8("cb10mFT4"));

        gridLayout_8->addWidget(cb10mFT4, 8, 2, 1, 1);

        cb12mFT4 = new QCheckBox(widget_3);
        cb12mFT4->setObjectName(QString::fromUtf8("cb12mFT4"));

        gridLayout_8->addWidget(cb12mFT4, 7, 2, 1, 1);

        cb15mFT4 = new QCheckBox(widget_3);
        cb15mFT4->setObjectName(QString::fromUtf8("cb15mFT4"));

        gridLayout_8->addWidget(cb15mFT4, 6, 2, 1, 1);

        cb17mFT4 = new QCheckBox(widget_3);
        cb17mFT4->setObjectName(QString::fromUtf8("cb17mFT4"));

        gridLayout_8->addWidget(cb17mFT4, 5, 2, 1, 1);

        cb20mFT4 = new QCheckBox(widget_3);
        cb20mFT4->setObjectName(QString::fromUtf8("cb20mFT4"));

        gridLayout_8->addWidget(cb20mFT4, 4, 2, 1, 1);

        cb30mFT4 = new QCheckBox(widget_3);
        cb30mFT4->setObjectName(QString::fromUtf8("cb30mFT4"));

        gridLayout_8->addWidget(cb30mFT4, 3, 2, 1, 1);

        cb40mFT4 = new QCheckBox(widget_3);
        cb40mFT4->setObjectName(QString::fromUtf8("cb40mFT4"));

        gridLayout_8->addWidget(cb40mFT4, 2, 2, 1, 1);

        cb80mFT4 = new QCheckBox(widget_3);
        cb80mFT4->setObjectName(QString::fromUtf8("cb80mFT4"));

        gridLayout_8->addWidget(cb80mFT4, 1, 2, 1, 1);

        gridLayout_8->setColumnStretch(0, 1);
        gridLayout_8->setColumnStretch(1, 1);
        gridLayout_8->setColumnStretch(2, 1);

        horizontalLayout_30->addWidget(widget_3);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setHorizontalSpacing(1);
        gridLayout_10->setVerticalSpacing(6);
        gridLayout_10->setContentsMargins(-1, -1, -1, 0);
        cbQRG6 = new QCheckBox(tab_4);
        cbQRG6->setObjectName(QString::fromUtf8("cbQRG6"));
        cbQRG6->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(cbQRG6, 6, 0, 1, 1);

        cbQRG1 = new QCheckBox(tab_4);
        cbQRG1->setObjectName(QString::fromUtf8("cbQRG1"));
        sizePolicy6.setHeightForWidth(cbQRG1->sizePolicy().hasHeightForWidth());
        cbQRG1->setSizePolicy(sizePolicy6);
        cbQRG1->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(cbQRG1, 0, 0, 1, 1);

        cbQRG2 = new QCheckBox(tab_4);
        cbQRG2->setObjectName(QString::fromUtf8("cbQRG2"));
        cbQRG2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(cbQRG2, 1, 0, 1, 1);

        cbQRG7 = new QCheckBox(tab_4);
        cbQRG7->setObjectName(QString::fromUtf8("cbQRG7"));

        gridLayout_10->addWidget(cbQRG7, 7, 0, 1, 1);

        sbQRG8 = new QSpinBox(tab_4);
        sbQRG8->setObjectName(QString::fromUtf8("sbQRG8"));
        sizePolicy6.setHeightForWidth(sbQRG8->sizePolicy().hasHeightForWidth());
        sbQRG8->setSizePolicy(sizePolicy6);
        sbQRG8->setMinimumSize(QSize(57, 0));
        sbQRG8->setMaximumSize(QSize(16777215, 16777215));
        sbQRG8->setProperty("showGroupSeparator", QVariant(true));
        sbQRG8->setMaximum(99999999);
        sbQRG8->setValue(28091);
        sbQRG8->setDisplayIntegerBase(10);

        gridLayout_10->addWidget(sbQRG8, 8, 1, 1, 1);

        cbQRG5 = new QCheckBox(tab_4);
        cbQRG5->setObjectName(QString::fromUtf8("cbQRG5"));
        cbQRG5->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(cbQRG5, 5, 0, 1, 1);

        cbQRG3 = new QCheckBox(tab_4);
        cbQRG3->setObjectName(QString::fromUtf8("cbQRG3"));
        cbQRG3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(cbQRG3, 2, 0, 1, 1);

        cbQRG4 = new QCheckBox(tab_4);
        cbQRG4->setObjectName(QString::fromUtf8("cbQRG4"));
        cbQRG4->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(cbQRG4, 4, 0, 1, 1);

        cbQRG8 = new QCheckBox(tab_4);
        cbQRG8->setObjectName(QString::fromUtf8("cbQRG8"));
        cbQRG8->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(cbQRG8, 8, 0, 1, 1);

        sbQRG7 = new QSpinBox(tab_4);
        sbQRG7->setObjectName(QString::fromUtf8("sbQRG7"));
        sizePolicy6.setHeightForWidth(sbQRG7->sizePolicy().hasHeightForWidth());
        sbQRG7->setSizePolicy(sizePolicy6);
        sbQRG7->setMinimumSize(QSize(57, 0));
        sbQRG7->setMaximumSize(QSize(16777215, 16777215));
        sbQRG7->setProperty("showGroupSeparator", QVariant(true));
        sbQRG7->setMaximum(99999999);
        sbQRG7->setValue(24911);

        gridLayout_10->addWidget(sbQRG7, 7, 1, 1, 1);

        sbQRG6 = new QSpinBox(tab_4);
        sbQRG6->setObjectName(QString::fromUtf8("sbQRG6"));
        sizePolicy6.setHeightForWidth(sbQRG6->sizePolicy().hasHeightForWidth());
        sbQRG6->setSizePolicy(sizePolicy6);
        sbQRG6->setMinimumSize(QSize(57, 0));
        sbQRG6->setMaximumSize(QSize(16777215, 16777215));
        sbQRG6->setProperty("showGroupSeparator", QVariant(true));
        sbQRG6->setMaximum(99999999);
        sbQRG6->setValue(21091);

        gridLayout_10->addWidget(sbQRG6, 6, 1, 1, 1);

        sbQRG5 = new QSpinBox(tab_4);
        sbQRG5->setObjectName(QString::fromUtf8("sbQRG5"));
        sizePolicy6.setHeightForWidth(sbQRG5->sizePolicy().hasHeightForWidth());
        sbQRG5->setSizePolicy(sizePolicy6);
        sbQRG5->setMinimumSize(QSize(57, 0));
        sbQRG5->setMaximumSize(QSize(16777215, 16777215));
        sbQRG5->setProperty("showGroupSeparator", QVariant(true));
        sbQRG5->setMaximum(99999999);
        sbQRG5->setValue(18095);

        gridLayout_10->addWidget(sbQRG5, 5, 1, 1, 1);

        sbQRG4 = new QSpinBox(tab_4);
        sbQRG4->setObjectName(QString::fromUtf8("sbQRG4"));
        sizePolicy6.setHeightForWidth(sbQRG4->sizePolicy().hasHeightForWidth());
        sbQRG4->setSizePolicy(sizePolicy6);
        sbQRG4->setMinimumSize(QSize(57, 0));
        sbQRG4->setMaximumSize(QSize(16777215, 16777215));
        sbQRG4->setProperty("showGroupSeparator", QVariant(true));
        sbQRG4->setMaximum(99999999);
        sbQRG4->setValue(14090);

        gridLayout_10->addWidget(sbQRG4, 4, 1, 1, 1);

        sbQRG3 = new QSpinBox(tab_4);
        sbQRG3->setObjectName(QString::fromUtf8("sbQRG3"));
        sizePolicy6.setHeightForWidth(sbQRG3->sizePolicy().hasHeightForWidth());
        sbQRG3->setSizePolicy(sizePolicy6);
        sbQRG3->setMinimumSize(QSize(57, 0));
        sbQRG3->setMaximumSize(QSize(16777215, 16777215));
        sbQRG3->setProperty("showGroupSeparator", QVariant(true));
        sbQRG3->setMaximum(99999999);
        sbQRG3->setValue(10131);

        gridLayout_10->addWidget(sbQRG3, 2, 1, 1, 1);

        sbQRG2 = new QSpinBox(tab_4);
        sbQRG2->setObjectName(QString::fromUtf8("sbQRG2"));
        sizePolicy6.setHeightForWidth(sbQRG2->sizePolicy().hasHeightForWidth());
        sbQRG2->setSizePolicy(sizePolicy6);
        sbQRG2->setMinimumSize(QSize(57, 0));
        sbQRG2->setMaximumSize(QSize(16777215, 16777215));
        sbQRG2->setProperty("showGroupSeparator", QVariant(true));
        sbQRG2->setMaximum(99999999);
        sbQRG2->setValue(7056);

        gridLayout_10->addWidget(sbQRG2, 1, 1, 1, 1);

        sbQRG1 = new QSpinBox(tab_4);
        sbQRG1->setObjectName(QString::fromUtf8("sbQRG1"));
        sizePolicy6.setHeightForWidth(sbQRG1->sizePolicy().hasHeightForWidth());
        sbQRG1->setSizePolicy(sizePolicy6);
        sbQRG1->setMinimumSize(QSize(57, 0));
        sbQRG1->setMaximumSize(QSize(16777215, 16777215));
        sbQRG1->setProperty("showGroupSeparator", QVariant(true));
        sbQRG1->setMaximum(99999999);
        sbQRG1->setSingleStep(1);
        sbQRG1->setValue(3567);

        gridLayout_10->addWidget(sbQRG1, 0, 1, 1, 1);

        gridLayout_10->setColumnStretch(1, 1);

        horizontalLayout_30->addLayout(gridLayout_10);


        gridLayout_13->addLayout(horizontalLayout_30, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout_6->addWidget(tabWidget);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 2);

        horizontalLayout_8->addWidget(QSO_controls_widget);

        controls_stack_widget->addWidget(page);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_12 = new QGridLayout(page_4);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        JTTY_horizontalLayout_1 = new QHBoxLayout();
        JTTY_horizontalLayout_1->setSpacing(6);
        JTTY_horizontalLayout_1->setObjectName(QString::fromUtf8("JTTY_horizontalLayout_1"));
        cbLowerCase = new QCheckBox(page_4);
        cbLowerCase->setObjectName(QString::fromUtf8("cbLowerCase"));

        JTTY_horizontalLayout_1->addWidget(cbLowerCase);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        JTTY_horizontalLayout_1->addItem(horizontalSpacer_8);

        cbIncludeTime = new QCheckBox(page_4);
        cbIncludeTime->setObjectName(QString::fromUtf8("cbIncludeTime"));

        JTTY_horizontalLayout_1->addWidget(cbIncludeTime);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        JTTY_horizontalLayout_1->addItem(horizontalSpacer_9);

        label_jttyStyle = new QLabel(page_4);
        label_jttyStyle->setObjectName(QString::fromUtf8("label_jttyStyle"));

        JTTY_horizontalLayout_1->addWidget(label_jttyStyle);

        comboBoxJttyStyle = new QComboBox(page_4);
        comboBoxJttyStyle->addItem(QString());
        comboBoxJttyStyle->addItem(QString());
        comboBoxJttyStyle->addItem(QString());
        comboBoxJttyStyle->setObjectName(QString::fromUtf8("comboBoxJttyStyle"));

        JTTY_horizontalLayout_1->addWidget(comboBoxJttyStyle);


        gridLayout_12->addLayout(JTTY_horizontalLayout_1, 2, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_8, 5, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_9, 0, 0, 1, 1);

        JTTY_gridLayout_1 = new QGridLayout();
        JTTY_gridLayout_1->setSpacing(6);
        JTTY_gridLayout_1->setObjectName(QString::fromUtf8("JTTY_gridLayout_1"));
        JTTY_gridLayout_1->setHorizontalSpacing(4);
        JTTY_gridLayout_2 = new QGridLayout();
        JTTY_gridLayout_2->setSpacing(6);
        JTTY_gridLayout_2->setObjectName(QString::fromUtf8("JTTY_gridLayout_2"));
        JTTY_gridLayout_2->setHorizontalSpacing(4);
        pbF5 = new QPushButton(page_4);
        pbF5->setObjectName(QString::fromUtf8("pbF5"));

        JTTY_gridLayout_2->addWidget(pbF5, 2, 0, 1, 1);

        msg1 = new QLineEdit(page_4);
        msg1->setObjectName(QString::fromUtf8("msg1"));
        msg1->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_2->addWidget(msg1, 1, 0, 1, 1);

        msg2 = new QLineEdit(page_4);
        msg2->setObjectName(QString::fromUtf8("msg2"));
        msg2->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_2->addWidget(msg2, 1, 1, 1, 1);

        pbF2 = new QPushButton(page_4);
        pbF2->setObjectName(QString::fromUtf8("pbF2"));

        JTTY_gridLayout_2->addWidget(pbF2, 0, 1, 1, 1);

        msg4 = new QLineEdit(page_4);
        msg4->setObjectName(QString::fromUtf8("msg4"));
        msg4->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_2->addWidget(msg4, 1, 3, 1, 1);

        pbF1 = new QPushButton(page_4);
        pbF1->setObjectName(QString::fromUtf8("pbF1"));

        JTTY_gridLayout_2->addWidget(pbF1, 0, 0, 1, 1);

        pbF7 = new QPushButton(page_4);
        pbF7->setObjectName(QString::fromUtf8("pbF7"));

        JTTY_gridLayout_2->addWidget(pbF7, 2, 2, 1, 1);

        pbF3 = new QPushButton(page_4);
        pbF3->setObjectName(QString::fromUtf8("pbF3"));

        JTTY_gridLayout_2->addWidget(pbF3, 0, 2, 1, 1);

        pbF6 = new QPushButton(page_4);
        pbF6->setObjectName(QString::fromUtf8("pbF6"));

        JTTY_gridLayout_2->addWidget(pbF6, 2, 1, 1, 1);

        msg3 = new QLineEdit(page_4);
        msg3->setObjectName(QString::fromUtf8("msg3"));
        msg3->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_2->addWidget(msg3, 1, 2, 1, 1);

        pbF8 = new QPushButton(page_4);
        pbF8->setObjectName(QString::fromUtf8("pbF8"));

        JTTY_gridLayout_2->addWidget(pbF8, 2, 3, 1, 1);

        pbF4 = new QPushButton(page_4);
        pbF4->setObjectName(QString::fromUtf8("pbF4"));

        JTTY_gridLayout_2->addWidget(pbF4, 0, 3, 1, 1);

        msg5 = new QLineEdit(page_4);
        msg5->setObjectName(QString::fromUtf8("msg5"));
        msg5->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_2->addWidget(msg5, 3, 0, 1, 1);

        msg6 = new QLineEdit(page_4);
        msg6->setObjectName(QString::fromUtf8("msg6"));
        msg6->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_2->addWidget(msg6, 3, 1, 1, 1);

        msg7 = new QLineEdit(page_4);
        msg7->setObjectName(QString::fromUtf8("msg7"));
        msg7->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_2->addWidget(msg7, 3, 2, 1, 1);

        msg8 = new QLineEdit(page_4);
        msg8->setObjectName(QString::fromUtf8("msg8"));
        msg8->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_2->addWidget(msg8, 3, 3, 1, 1);


        JTTY_gridLayout_1->addLayout(JTTY_gridLayout_2, 1, 1, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        JTTY_gridLayout_1->addItem(verticalSpacer_10, 2, 0, 1, 1);

        pbSendMessage = new QPushButton(page_4);
        pbSendMessage->setObjectName(QString::fromUtf8("pbSendMessage"));
        pbSendMessage->setMinimumSize(QSize(100, 0));

        JTTY_gridLayout_1->addWidget(pbSendMessage, 4, 0, 1, 1);

        label_3 = new QLabel(page_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        JTTY_gridLayout_1->addWidget(label_3, 5, 0, 1, 1);

        Tx_Message = new QLineEdit(page_4);
        Tx_Message->setObjectName(QString::fromUtf8("Tx_Message"));

        JTTY_gridLayout_1->addWidget(Tx_Message, 4, 1, 1, 1);

        JTTY_horizontalLayout_2 = new QHBoxLayout();
        JTTY_horizontalLayout_2->setSpacing(6);
        JTTY_horizontalLayout_2->setObjectName(QString::fromUtf8("JTTY_horizontalLayout_2"));
        sbSerialNumber_2 = new QSpinBox(page_4);
        sbSerialNumber_2->setObjectName(QString::fromUtf8("sbSerialNumber_2"));
        sbSerialNumber_2->setMinimumSize(QSize(0, 0));
        sbSerialNumber_2->setAlignment(Qt::AlignCenter);
        sbSerialNumber_2->setMinimum(1);
        sbSerialNumber_2->setMaximum(5000);

        JTTY_horizontalLayout_2->addWidget(sbSerialNumber_2);

        label_jttyCallNext = new QLabel(page_4);
        label_jttyCallNext->setObjectName(QString::fromUtf8("label_jttyCallNext"));
        label_jttyCallNext->setAlignment(Qt::AlignCenter);

        JTTY_horizontalLayout_2->addWidget(label_jttyCallNext);

        lineEdit = new QLineEdit(page_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        JTTY_horizontalLayout_2->addWidget(lineEdit);

        JTTY_horizontalLayout_2->setStretch(0, 1);
        JTTY_horizontalLayout_2->setStretch(1, 1);
        JTTY_horizontalLayout_2->setStretch(2, 1);

        JTTY_gridLayout_1->addLayout(JTTY_horizontalLayout_2, 5, 1, 1, 1);

        JTTY_verticalLayout_1 = new QVBoxLayout();
        JTTY_verticalLayout_1->setSpacing(6);
        JTTY_verticalLayout_1->setObjectName(QString::fromUtf8("JTTY_verticalLayout_1"));
        TxFreqSpinBox_2 = new QSpinBox(page_4);
        TxFreqSpinBox_2->setObjectName(QString::fromUtf8("TxFreqSpinBox_2"));
        TxFreqSpinBox_2->setAlignment(Qt::AlignCenter);
        TxFreqSpinBox_2->setMinimum(200);
        TxFreqSpinBox_2->setMaximum(5000);
        TxFreqSpinBox_2->setValue(1500);

        JTTY_verticalLayout_1->addWidget(TxFreqSpinBox_2);

        JTTY_horizontalLayout_3 = new QHBoxLayout();
        JTTY_horizontalLayout_3->setSpacing(3);
        JTTY_horizontalLayout_3->setObjectName(QString::fromUtf8("JTTY_horizontalLayout_3"));
        pbR2T_2 = new QPushButton(page_4);
        pbR2T_2->setObjectName(QString::fromUtf8("pbR2T_2"));
        pbR2T_2->setMaximumSize(QSize(30, 16777215));

        JTTY_horizontalLayout_3->addWidget(pbR2T_2);

        sbFtol_2 = new HintedSpinBox(page_4);
        sbFtol_2->setObjectName(QString::fromUtf8("sbFtol_2"));
        sbFtol_2->setAlignment(Qt::AlignCenter);
        sbFtol_2->setMinimum(1);
        sbFtol_2->setMaximum(1000);
        sbFtol_2->setValue(20);

        JTTY_horizontalLayout_3->addWidget(sbFtol_2);

        pbT2R_2 = new QPushButton(page_4);
        pbT2R_2->setObjectName(QString::fromUtf8("pbT2R_2"));
        pbT2R_2->setMaximumSize(QSize(30, 16777215));

        JTTY_horizontalLayout_3->addWidget(pbT2R_2);


        JTTY_verticalLayout_1->addLayout(JTTY_horizontalLayout_3);

        RxFreqSpinBox_2 = new QSpinBox(page_4);
        RxFreqSpinBox_2->setObjectName(QString::fromUtf8("RxFreqSpinBox_2"));
        RxFreqSpinBox_2->setAlignment(Qt::AlignCenter);
        RxFreqSpinBox_2->setMinimum(200);
        RxFreqSpinBox_2->setMaximum(5000);
        RxFreqSpinBox_2->setValue(1500);

        JTTY_verticalLayout_1->addWidget(RxFreqSpinBox_2);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        JTTY_verticalLayout_1->addItem(verticalSpacer_11);


        JTTY_gridLayout_1->addLayout(JTTY_verticalLayout_1, 1, 0, 1, 1);


        gridLayout_12->addLayout(JTTY_gridLayout_1, 3, 0, 1, 1);

        controls_stack_widget->addWidget(page_4);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(page_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_9 = new QHBoxLayout(widget_2);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        WSPR_controls_widget = new QWidget(widget_2);
        WSPR_controls_widget->setObjectName(QString::fromUtf8("WSPR_controls_widget"));
        gridLayout_9 = new QGridLayout(WSPR_controls_widget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_7, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        WSPRfreqSpinBox = new QSpinBox(WSPR_controls_widget);
        WSPRfreqSpinBox->setObjectName(QString::fromUtf8("WSPRfreqSpinBox"));
        WSPRfreqSpinBox->setAlignment(Qt::AlignCenter);
        WSPRfreqSpinBox->setMinimum(1400);
        WSPRfreqSpinBox->setMaximum(1600);
        WSPRfreqSpinBox->setValue(1500);

        verticalLayout_7->addWidget(WSPRfreqSpinBox);

        sbFST4W_RxFreq = new QSpinBox(WSPR_controls_widget);
        sbFST4W_RxFreq->setObjectName(QString::fromUtf8("sbFST4W_RxFreq"));
        sbFST4W_RxFreq->setAlignment(Qt::AlignCenter);
        sbFST4W_RxFreq->setMinimum(100);
        sbFST4W_RxFreq->setMaximum(4900);
        sbFST4W_RxFreq->setSingleStep(100);
        sbFST4W_RxFreq->setValue(1500);

        verticalLayout_7->addWidget(sbFST4W_RxFreq);

        sbFST4W_FTol = new HintedSpinBox(WSPR_controls_widget);
        sbFST4W_FTol->setObjectName(QString::fromUtf8("sbFST4W_FTol"));
        sbFST4W_FTol->setAlignment(Qt::AlignCenter);
        sbFST4W_FTol->setMinimum(100);
        sbFST4W_FTol->setMaximum(500);
        sbFST4W_FTol->setSingleStep(100);

        verticalLayout_7->addWidget(sbFST4W_FTol);

        RoundRobin = new QComboBox(WSPR_controls_widget);
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->addItem(QString());
        RoundRobin->setObjectName(QString::fromUtf8("RoundRobin"));
        RoundRobin->setEditable(true);

        verticalLayout_7->addWidget(RoundRobin);

        sbTxPercent = new QSpinBox(WSPR_controls_widget);
        sbTxPercent->setObjectName(QString::fromUtf8("sbTxPercent"));
        sbTxPercent->setStyleSheet(QString::fromUtf8("QSpinBox:enabled[notx=\"true\"] {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 255, 0);\n"
"}"));
        sbTxPercent->setAlignment(Qt::AlignCenter);
        sbTxPercent->setMaximum(100);

        verticalLayout_7->addWidget(sbTxPercent);

        sbTR_FST4W = new RestrictedSpinBox(WSPR_controls_widget);
        sbTR_FST4W->setObjectName(QString::fromUtf8("sbTR_FST4W"));
        sbTR_FST4W->setAlignment(Qt::AlignCenter);
        sbTR_FST4W->setMinimum(15);
        sbTR_FST4W->setMaximum(1800);

        verticalLayout_7->addWidget(sbTR_FST4W);

        band_hopping_group_box = new QGroupBox(WSPR_controls_widget);
        band_hopping_group_box->setObjectName(QString::fromUtf8("band_hopping_group_box"));
        band_hopping_group_box->setCheckable(true);
        horizontalLayout_7 = new QHBoxLayout(band_hopping_group_box);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        band_hopping_schedule_push_button = new QPushButton(band_hopping_group_box);
        band_hopping_schedule_push_button->setObjectName(QString::fromUtf8("band_hopping_schedule_push_button"));

        horizontalLayout_7->addWidget(band_hopping_schedule_push_button);


        verticalLayout_7->addWidget(band_hopping_group_box);


        horizontalLayout_12->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        cbUploadWSPR_Spots = new QCheckBox(WSPR_controls_widget);
        cbUploadWSPR_Spots->setObjectName(QString::fromUtf8("cbUploadWSPR_Spots"));
        cbUploadWSPR_Spots->setStyleSheet(QString::fromUtf8("QCheckBox:unchecked {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 255, 0);\n"
"}"));

        horizontalLayout_10->addWidget(cbUploadWSPR_Spots);


        verticalLayout_2->addLayout(horizontalLayout_10);

        WSPR_prefer_type_1_check_box = new QCheckBox(WSPR_controls_widget);
        WSPR_prefer_type_1_check_box->setObjectName(QString::fromUtf8("WSPR_prefer_type_1_check_box"));
        WSPR_prefer_type_1_check_box->setChecked(true);

        verticalLayout_2->addWidget(WSPR_prefer_type_1_check_box);

        cbNoOwnCall = new QCheckBox(WSPR_controls_widget);
        cbNoOwnCall->setObjectName(QString::fromUtf8("cbNoOwnCall"));

        verticalLayout_2->addWidget(cbNoOwnCall);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        pbTxNext = new QPushButton(WSPR_controls_widget);
        pbTxNext->setObjectName(QString::fromUtf8("pbTxNext"));
        pbTxNext->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: red;\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        pbTxNext->setCheckable(true);

        horizontalLayout_13->addWidget(pbTxNext);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        TxPowerComboBox = new QComboBox(WSPR_controls_widget);
        TxPowerComboBox->setObjectName(QString::fromUtf8("TxPowerComboBox"));

        horizontalLayout_14->addWidget(TxPowerComboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_14);


        verticalLayout_8->addLayout(verticalLayout_2);


        horizontalLayout_12->addLayout(verticalLayout_8);


        gridLayout_9->addLayout(horizontalLayout_12, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_3, 0, 1, 1, 1);


        horizontalLayout_9->addWidget(WSPR_controls_widget);


        verticalLayout_5->addWidget(widget_2);

        controls_stack_widget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        horizontalLayout_17 = new QHBoxLayout(page_3);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_4);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_7);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rbEchoMessage = new QRadioButton(page_3);
        rbEchoMessage->setObjectName(QString::fromUtf8("rbEchoMessage"));
        rbEchoMessage->setMinimumSize(QSize(0, 0));
        rbEchoMessage->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(rbEchoMessage, 1, 0, 1, 1);

        sbToneSpacing = new HintedSpinBox(page_3);
        sbToneSpacing->setObjectName(QString::fromUtf8("sbToneSpacing"));
        sbToneSpacing->setEnabled(false);
        sbToneSpacing->setMinimumSize(QSize(0, 0));
        sbToneSpacing->setMaximumSize(QSize(16777215, 16777215));
        sbToneSpacing->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(sbToneSpacing, 1, 1, 1, 1);

        rbFixedTone = new QRadioButton(page_3);
        rbFixedTone->setObjectName(QString::fromUtf8("rbFixedTone"));
        rbFixedTone->setMinimumSize(QSize(0, 0));
        rbFixedTone->setMaximumSize(QSize(16777215, 16777215));
        rbFixedTone->setChecked(true);

        gridLayout_2->addWidget(rbFixedTone, 0, 0, 1, 1);

        leEchoMessage = new QLineEdit(page_3);
        leEchoMessage->setObjectName(QString::fromUtf8("leEchoMessage"));
        leEchoMessage->setEnabled(false);
        leEchoMessage->setMaximumSize(QSize(16777215, 16777215));
        leEchoMessage->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(leEchoMessage, 2, 1, 1, 1);

        rbEchoCW = new QRadioButton(page_3);
        rbEchoCW->setObjectName(QString::fromUtf8("rbEchoCW"));
        rbEchoCW->setMinimumSize(QSize(0, 0));
        rbEchoCW->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(rbEchoCW, 2, 0, 1, 1);

        gridLayout_2->setColumnStretch(0, 3);
        gridLayout_2->setColumnStretch(1, 2);

        verticalLayout_12->addLayout(gridLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_5);


        horizontalLayout_17->addLayout(verticalLayout_12);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_5);

        controls_stack_widget->addWidget(page_3);

        gridLayout_5->addWidget(controls_stack_widget, 0, 6, 3, 1);

        labDialFreq = new QLabel(lower_panel_widget);
        labDialFreq->setObjectName(QString::fromUtf8("labDialFreq"));
        sizePolicy.setHeightForWidth(labDialFreq->sizePolicy().hasHeightForWidth());
        labDialFreq->setSizePolicy(sizePolicy);
        labDialFreq->setFocusPolicy(Qt::WheelFocus);
        labDialFreq->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  font-family: MS Shell Dlg 2;\n"
"  font-size: 16pt;\n"
"   color : yellow;\n"
"   background-color : black;\n"
"}\n"
"QLabel[oob=\"true\"] {\n"
"  background-color: red;\n"
"}"));
        labDialFreq->setAlignment(Qt::AlignCenter);
        labDialFreq->setMargin(5);

        gridLayout_5->addWidget(labDialFreq, 0, 4, 1, 2);

        labUTC = new QLabel(lower_panel_widget);
        labUTC->setObjectName(QString::fromUtf8("labUTC"));
        sizePolicy.setHeightForWidth(labUTC->sizePolicy().hasHeightForWidth());
        labUTC->setSizePolicy(sizePolicy);
        labUTC->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  font-family: MS Shell Dlg 2;\n"
"  font-size: 16pt;\n"
"  background-color : black;\n"
"  color : yellow;\n"
"}"));
        labUTC->setFrameShape(QFrame::StyledPanel);
        labUTC->setFrameShadow(QFrame::Sunken);
        labUTC->setLineWidth(2);
        labUTC->setMidLineWidth(0);
        labUTC->setAlignment(Qt::AlignCenter);
        labUTC->setMargin(5);

        gridLayout_5->addWidget(labUTC, 2, 4, 1, 2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(6);
        gridLayout_4->setVerticalSpacing(0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        sbNB = new QSpinBox(lower_panel_widget);
        sbNB->setObjectName(QString::fromUtf8("sbNB"));
        sizePolicy7.setHeightForWidth(sbNB->sizePolicy().hasHeightForWidth());
        sbNB->setSizePolicy(sizePolicy7);
        sbNB->setMaximumSize(QSize(100, 16777215));
        sbNB->setAlignment(Qt::AlignCenter);
        sbNB->setMinimum(-2);
        sbNB->setMaximum(25);

        verticalLayout_11->addWidget(sbNB);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        signal_meter_widget = new SignalMeter(lower_panel_widget);
        signal_meter_widget->setObjectName(QString::fromUtf8("signal_meter_widget"));
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(signal_meter_widget->sizePolicy().hasHeightForWidth());
        signal_meter_widget->setSizePolicy(sizePolicy10);
        signal_meter_widget->setMinimumSize(QSize(0, 0));
        signal_meter_widget->setMaximumSize(QSize(100, 16777215));
        signal_meter_widget->setFrameShape(QFrame::Panel);
        signal_meter_widget->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(signal_meter_widget);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_11->addLayout(horizontalLayout_3);


        gridLayout_4->addLayout(verticalLayout_11, 2, 0, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        houndButton = new QPushButton(lower_panel_widget);
        houndButton->setObjectName(QString::fromUtf8("houndButton"));
        houndButton->setMinimumSize(QSize(32, 0));
        houndButton->setMaximumSize(QSize(16777215, 16777215));
        houndButton->setFocusPolicy(Qt::StrongFocus);
        houndButton->setCheckable(true);

        verticalLayout_15->addWidget(houndButton);

        ft8Button = new QPushButton(lower_panel_widget);
        ft8Button->setObjectName(QString::fromUtf8("ft8Button"));
        ft8Button->setMinimumSize(QSize(32, 0));
        ft8Button->setMaximumSize(QSize(16777215, 16777215));
        ft8Button->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_15->addWidget(ft8Button);

        ft4Button = new QPushButton(lower_panel_widget);
        ft4Button->setObjectName(QString::fromUtf8("ft4Button"));
        ft4Button->setMinimumSize(QSize(32, 0));
        ft4Button->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_15->addWidget(ft4Button);

        ft2Button = new QPushButton(lower_panel_widget);
        ft2Button->setObjectName(QString::fromUtf8("ft2Button"));
        ft2Button->setMinimumSize(QSize(32, 0));

        verticalLayout_15->addWidget(ft2Button);

        msk144Button = new QPushButton(lower_panel_widget);
        msk144Button->setObjectName(QString::fromUtf8("msk144Button"));
        msk144Button->setMinimumSize(QSize(32, 0));
        msk144Button->setMaximumSize(QSize(16777215, 16777215));
        msk144Button->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_15->addWidget(msk144Button);

        q65Button = new QPushButton(lower_panel_widget);
        q65Button->setObjectName(QString::fromUtf8("q65Button"));
        q65Button->setMinimumSize(QSize(32, 0));
        q65Button->setMaximumSize(QSize(16777215, 16777215));
        q65Button->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_15->addWidget(q65Button);

        jt65Button = new QPushButton(lower_panel_widget);
        jt65Button->setObjectName(QString::fromUtf8("jt65Button"));
        jt65Button->setMinimumSize(QSize(32, 0));
        jt65Button->setMaximumSize(QSize(16777215, 16777215));
        jt65Button->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_15->addWidget(jt65Button);

        echoButton = new QPushButton(lower_panel_widget);
        echoButton->setObjectName(QString::fromUtf8("echoButton"));
        echoButton->setMinimumSize(QSize(32, 0));

        verticalLayout_15->addWidget(echoButton);


        gridLayout_4->addLayout(verticalLayout_15, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 6);
        bandComboBox = new BandComboBox(lower_panel_widget);
        bandComboBox->setObjectName(QString::fromUtf8("bandComboBox"));
        sizePolicy7.setHeightForWidth(bandComboBox->sizePolicy().hasHeightForWidth());
        bandComboBox->setSizePolicy(sizePolicy7);
        bandComboBox->setMinimumSize(QSize(0, 0));
        bandComboBox->setMaximumSize(QSize(16777215, 16777215));
        bandComboBox->setEditable(true);
        bandComboBox->setMaxVisibleItems(28);
        bandComboBox->setInsertPolicy(QComboBox::NoInsert);
        bandComboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);

        horizontalLayout->addWidget(bandComboBox);

        readFreq = new QPushButton(lower_panel_widget);
        readFreq->setObjectName(QString::fromUtf8("readFreq"));
        readFreq->setEnabled(false);
        readFreq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" font-family: helvetica;\n"
" font-size: 9pt;\n"
" font-weight: bold;\n"
" background-color: white;\n"
" color: black;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:10px;\n"
" border-color: gray;\n"
" max-width:20px;\n"
" max-height:20px;\n"
" min-width:20px;\n"
" min-height:20px;\n"
"}\n"
"QPushButton[state=\"error\"] {\n"
" background-color: red;\n"
"}\n"
"QPushButton[state=\"warning\"] {\n"
" background-color: orange;\n"
"}\n"
"QPushButton[state=\"ok\"] {\n"
" background-color: #00ff00;\n"
"}"));

        horizontalLayout->addWidget(readFreq);

        horizontalLayout->setStretch(0, 1);

        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 2);


        gridLayout_5->addLayout(gridLayout_4, 0, 2, 3, 1);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setColumnStretch(4, 1);
        gridLayout_5->setColumnStretch(5, 1);
        gridLayout_5->setColumnStretch(6, 5);

        verticalLayout_4->addLayout(gridLayout_5);


        verticalLayout_6->addWidget(lower_panel_widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 880, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuCallsign_overlay = new QMenu(menuView);
        menuCallsign_overlay->setObjectName(QString::fromUtf8("menuCallsign_overlay"));
        menuCallsign_font = new QMenu(menuCallsign_overlay);
        menuCallsign_font->setObjectName(QString::fromUtf8("menuCallsign_font"));
        menuCallsign_transparency = new QMenu(menuCallsign_overlay);
        menuCallsign_transparency->setObjectName(QString::fromUtf8("menuCallsign_transparency"));
        menuCallsign_position = new QMenu(menuCallsign_overlay);
        menuCallsign_position->setObjectName(QString::fromUtf8("menuCallsign_position"));
        menuFilters = new QMenu(menuBar);
        menuFilters->setObjectName(QString::fromUtf8("menuFilters"));
        menuDecode = new QMenu(menuBar);
        menuDecode->setObjectName(QString::fromUtf8("menuDecode"));
        menuParameters = new QMenu(menuDecode);
        menuParameters->setObjectName(QString::fromUtf8("menuParameters"));
        menuDecoder_sensitivity = new QMenu(menuParameters);
        menuDecoder_sensitivity->setObjectName(QString::fromUtf8("menuDecoder_sensitivity"));
        menuDecoder_start = new QMenu(menuParameters);
        menuDecoder_start->setObjectName(QString::fromUtf8("menuDecoder_start"));
        menuFT8_threads = new QMenu(menuParameters);
        menuFT8_threads->setObjectName(QString::fromUtf8("menuFT8_threads"));
        menuQSO_RX_freq_sensitivity = new QMenu(menuParameters);
        menuQSO_RX_freq_sensitivity->setObjectName(QString::fromUtf8("menuQSO_RX_freq_sensitivity"));
        menuDecoding_cycles = new QMenu(menuParameters);
        menuDecoding_cycles->setObjectName(QString::fromUtf8("menuDecoding_cycles"));
        menuQMAP_source = new QMenu(menuDecode);
        menuQMAP_source->setObjectName(QString::fromUtf8("menuQMAP_source"));
        menuSave = new QMenu(menuBar);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuMode = new QMenu(menuBar);
        menuMode->setObjectName(QString::fromUtf8("menuMode"));
        menuConfig = new QMenu(menuBar);
        menuConfig->setObjectName(QString::fromUtf8("menuConfig"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
#if QT_CONFIG(shortcut)
        label_4->setBuddy(dxGridEntry);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(decodedTextBrowser, decodedTextBrowser2);
        QWidget::setTabOrder(decodedTextBrowser2, cbCQonly);
        QWidget::setTabOrder(cbCQonly, logQSOButton);
        QWidget::setTabOrder(logQSOButton, stopButton);
        QWidget::setTabOrder(stopButton, monitorButton);
        QWidget::setTabOrder(monitorButton, EraseButton);
        QWidget::setTabOrder(EraseButton, ClrAvgButton);
        QWidget::setTabOrder(ClrAvgButton, DecodeButton);
        QWidget::setTabOrder(DecodeButton, autoButton);
        QWidget::setTabOrder(autoButton, stopTxButton);
        QWidget::setTabOrder(stopTxButton, tuneButton);
        QWidget::setTabOrder(tuneButton, cbMenus);
        QWidget::setTabOrder(cbMenus, sbNB);
        QWidget::setTabOrder(sbNB, dxCallEntry);
        QWidget::setTabOrder(dxCallEntry, dxGridEntry);
        QWidget::setTabOrder(dxGridEntry, txFirstCheckBox);
        QWidget::setTabOrder(txFirstCheckBox, TxFreqSpinBox);
        QWidget::setTabOrder(TxFreqSpinBox, pbR2T);
        QWidget::setTabOrder(pbR2T, sbFtol);
        QWidget::setTabOrder(sbFtol, pbT2R);
        QWidget::setTabOrder(pbT2R, RxFreqSpinBox);
        QWidget::setTabOrder(RxFreqSpinBox, rptSpinBox);
        QWidget::setTabOrder(rptSpinBox, sbTR);
        QWidget::setTabOrder(sbTR, cbHoldTxFreq);
        QWidget::setTabOrder(cbHoldTxFreq, sbF_Low);
        QWidget::setTabOrder(sbF_Low, sbF_High);
        QWidget::setTabOrder(sbF_High, sbSubmode);
        QWidget::setTabOrder(sbSubmode, syncSpinBox);
        QWidget::setTabOrder(syncSpinBox, sbCQTxFreq);
        QWidget::setTabOrder(sbCQTxFreq, cbCQTx);
        QWidget::setTabOrder(cbCQTx, cbRxAll);
        QWidget::setTabOrder(cbRxAll, cbShMsgs);
        QWidget::setTabOrder(cbShMsgs, cbFast9);
        QWidget::setTabOrder(cbFast9, cbAutoSeq);
        QWidget::setTabOrder(cbAutoSeq, cbTx6);
        QWidget::setTabOrder(cbTx6, cbSWL);
        QWidget::setTabOrder(cbSWL, pbBestSP);
        QWidget::setTabOrder(pbBestSP, measure_check_box);
        QWidget::setTabOrder(measure_check_box, tabWidget);
        QWidget::setTabOrder(tabWidget, genStdMsgsPushButton);
        QWidget::setTabOrder(genStdMsgsPushButton, tx1);
        QWidget::setTabOrder(tx1, txrb1);
        QWidget::setTabOrder(txrb1, txb1);
        QWidget::setTabOrder(txb1, tx2);
        QWidget::setTabOrder(tx2, txrb2);
        QWidget::setTabOrder(txrb2, txb2);
        QWidget::setTabOrder(txb2, tx3);
        QWidget::setTabOrder(tx3, txrb3);
        QWidget::setTabOrder(txrb3, txb3);
        QWidget::setTabOrder(txb3, tx4);
        QWidget::setTabOrder(tx4, txrb4);
        QWidget::setTabOrder(txrb4, txb4);
        QWidget::setTabOrder(txb4, tx5);
        QWidget::setTabOrder(tx5, txrb5);
        QWidget::setTabOrder(txrb5, txb5);
        QWidget::setTabOrder(txb5, tx6);
        QWidget::setTabOrder(tx6, txrb6);
        QWidget::setTabOrder(txrb6, txb6);
        QWidget::setTabOrder(txb6, WSPRfreqSpinBox);
        QWidget::setTabOrder(WSPRfreqSpinBox, sbFST4W_RxFreq);
        QWidget::setTabOrder(sbFST4W_RxFreq, sbFST4W_FTol);
        QWidget::setTabOrder(sbFST4W_FTol, RoundRobin);
        QWidget::setTabOrder(RoundRobin, sbTxPercent);
        QWidget::setTabOrder(sbTxPercent, sbTR_FST4W);
        QWidget::setTabOrder(sbTR_FST4W, band_hopping_group_box);
        QWidget::setTabOrder(band_hopping_group_box, band_hopping_schedule_push_button);
        QWidget::setTabOrder(band_hopping_schedule_push_button, cbUploadWSPR_Spots);
        QWidget::setTabOrder(cbUploadWSPR_Spots, WSPR_prefer_type_1_check_box);
        QWidget::setTabOrder(WSPR_prefer_type_1_check_box, cbNoOwnCall);
        QWidget::setTabOrder(cbNoOwnCall, pbTxNext);
        QWidget::setTabOrder(pbTxNext, TxPowerComboBox);
        QWidget::setTabOrder(TxPowerComboBox, outAttenuation);
        QWidget::setTabOrder(outAttenuation, sbSerialNumber);
        QWidget::setTabOrder(sbSerialNumber, DX_Call_Button);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConfig->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuFilters->menuAction());
        menuBar->addAction(menuMode->menuAction());
        menuBar->addAction(menuDecode->menuAction());
        menuBar->addAction(menuSave->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_next_in_directory);
        menuFile->addAction(actionDecode_remaining_files_in_directory);
        menuFile->addSeparator();
        menuFile->addAction(actionDelete_all_wav_files_in_SaveDir);
        menuFile->addAction(actionErase_ALL_TXT);
        menuFile->addAction(actionErase_wsjtx_log_adi);
        menuFile->addAction(actionErase_Tx_Log);
        menuFile->addAction(actionErase_Ignore_List);
        menuFile->addAction(actionErase_WSPR_hashtable);
        menuFile->addAction(actionErase_list_of_Q65_callers);
        menuFile->addAction(reset_cabrillo_log_action);
        menuFile->addAction(actionExport_Cabrillo_log);
        menuFile->addAction(actionOpen_log_directory);
        menuFile->addSeparator();
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuView->addAction(actionWide_Waterfall);
        menuView->addAction(actionAstronomical_data);
        menuView->addAction(actionMessage_averaging);
        menuView->addAction(actionEcho_Graph);
        menuView->addAction(actionFast_Graph);
        menuView->addAction(contest_log_action);
        menuView->addAction(fox_log_action);
        menuView->addAction(actionColors);
        menuView->addAction(actionActiveStations);
        menuView->addAction(actionSWL_Mode);
        menuView->addAction(actionQSYMessage_Creator);
        menuView->addAction(actionQSY_Monitor);
        menuView->addAction(actionEnable_QSY_Popups);
        menuView->addAction(actionBand_Buttons);
        menuView->addAction(actionVHF_UHF_Buttons);
        menuView->addAction(actionUse_Dark_Style);
        menuView->addSeparator();
        menuView->addAction(menuCallsign_overlay->menuAction());
        menuCallsign_overlay->addAction(actionCallsign_overlay_enabled);
        menuCallsign_overlay->addSeparator();
        menuCallsign_overlay->addAction(actionCallsign_persist_1);
        menuCallsign_overlay->addAction(actionCallsign_persist_2);
        menuCallsign_overlay->addAction(actionCallsign_persist_3);
        menuCallsign_overlay->addAction(actionCallsign_persist_4);
        menuCallsign_overlay->addAction(actionCallsign_persist_5);
        menuCallsign_overlay->addSeparator();
        menuCallsign_overlay->addAction(menuCallsign_font->menuAction());
        menuCallsign_overlay->addAction(menuCallsign_transparency->menuAction());
        menuCallsign_overlay->addAction(menuCallsign_position->menuAction());
        menuCallsign_font->addAction(actionCallsign_font_small);
        menuCallsign_font->addAction(actionCallsign_font_normal);
        menuCallsign_font->addAction(actionCallsign_font_medium);
        menuCallsign_font->addAction(actionCallsign_font_large);
        menuCallsign_transparency->addAction(actionCallsign_transparency_None);
        menuCallsign_transparency->addAction(actionCallsign_transparency_Low);
        menuCallsign_transparency->addAction(actionCallsign_transparency_Medium);
        menuCallsign_transparency->addAction(actionCallsign_transparency_High);
        menuCallsign_position->addAction(actionCallsign_position_top);
        menuCallsign_position->addAction(actionCallsign_position_bottom);
        menuFilters->addAction(actionHideB4);
        menuFilters->addAction(actionHideToday);
        menuFilters->addAction(actionHideIgnored);
        menuFilters->addSeparator();
        menuFilters->addAction(actionIgnoreB4);
        menuFilters->addAction(actionIgnoreToday);
        menuFilters->addAction(actionIgnoreIgnored);
        menuFilters->addSeparator();
        menuFilters->addAction(actionHideTerritory1);
        menuFilters->addAction(actionHideTerritory2);
        menuFilters->addAction(actionHideTerritory3);
        menuFilters->addAction(actionHideTerritory4);
        menuFilters->addSeparator();
        menuFilters->addAction(actionHideEU);
        menuFilters->addAction(actionHideNA);
        menuFilters->addAction(actionHideSA);
        menuFilters->addAction(actionHideAS);
        menuFilters->addAction(actionHideAF);
        menuFilters->addAction(actionHideOC);
        menuFilters->addAction(actionHideAN);
        menuFilters->addSeparator();
        menuFilters->addAction(actionHighlightB4);
        menuFilters->addAction(actionHighlightToday);
        menuFilters->addAction(actionHighlightIgnored);
        menuFilters->addSeparator();
        menuFilters->addAction(actionHighlightTerritory1);
        menuFilters->addAction(actionHighlightTerritory2);
        menuFilters->addAction(actionHighlightTerritory3);
        menuFilters->addAction(actionHighlightTerritory4);
        menuFilters->addSeparator();
        menuFilters->addAction(actionHighlight_Whitelist_entries);
        menuDecode->addAction(actionQuickDecode);
        menuDecode->addAction(actionMediumDecode);
        menuDecode->addAction(actionDeepestDecode);
        menuDecode->addSeparator();
        menuDecode->addAction(actionUse_multithreaded_FT8_decoder);
        menuDecode->addAction(menuParameters->menuAction());
        menuDecode->addSeparator();
        menuDecode->addAction(actionInclude_averaging);
        menuDecode->addAction(actionInclude_correlation);
        menuDecode->addAction(actionEnable_AP_FT8);
        menuDecode->addAction(actionEnable_AP_JT65);
        menuDecode->addAction(actionEnable_AP_DXcall);
        menuDecode->addAction(actionAuto_Clear_Avg);
        menuDecode->addSeparator();
        menuDecode->addAction(actionAccept_QMAP_click_events);
        menuDecode->addAction(actionClaimQmapClicks);
        menuDecode->addAction(menuQMAP_source->menuAction());
        menuDecode->addAction(actionDisable_clicks_on_waterfall);
        menuDecode->addSeparator();
        menuDecode->addAction(actionHide_AP_info);
        menuDecode->addAction(actionReduce_false_decodes);
        menuDecode->addSeparator();
        menuDecode->addAction(actionFull_Duplex_Mode);
        menuParameters->addAction(menuFT8_threads->menuAction());
        menuParameters->addAction(menuDecoding_cycles->menuAction());
        menuParameters->addAction(menuQSO_RX_freq_sensitivity->menuAction());
        menuParameters->addAction(menuDecoder_sensitivity->menuAction());
        menuParameters->addAction(menuDecoder_start->menuAction());
        menuParameters->addSeparator();
        menuParameters->addAction(actionFT8WidebandDXCallSearch);
        menuParameters->addAction(actionHide_FT8_dupe_messages);
        menuParameters->addAction(actionNo_MTD_a8_decodes);
        menuDecoder_sensitivity->addAction(actionFT8SensMin);
        menuDecoder_sensitivity->addAction(actionlowFT8thresholds);
        menuDecoder_sensitivity->addAction(actionFT8subpass);
        menuDecoder_start->addAction(actionStartTwoStage);
        menuDecoder_start->addAction(actionStartThreeStage);
        menuDecoder_start->addAction(actionStartEarly);
        menuDecoder_start->addAction(actionStartNormal);
        menuDecoder_start->addAction(actionStartLate);
        menuFT8_threads->addAction(actionMTAuto);
        menuFT8_threads->addAction(actionMT1);
        menuFT8_threads->addAction(actionMT2);
        menuFT8_threads->addAction(actionMT3);
        menuFT8_threads->addAction(actionMT4);
        menuFT8_threads->addAction(actionMT5);
        menuFT8_threads->addAction(actionMT6);
        menuFT8_threads->addAction(actionMT7);
        menuFT8_threads->addAction(actionMT8);
        menuFT8_threads->addAction(actionMT9);
        menuFT8_threads->addAction(actionMT10);
        menuFT8_threads->addAction(actionMT11);
        menuFT8_threads->addAction(actionMT12);
        menuQSO_RX_freq_sensitivity->addAction(actionRXfLow);
        menuQSO_RX_freq_sensitivity->addAction(actionRXfMedium);
        menuQSO_RX_freq_sensitivity->addAction(actionRXfHigh);
        menuDecoding_cycles->addAction(actionDecFT8cycles1);
        menuDecoding_cycles->addAction(actionDecFT8cycles2);
        menuDecoding_cycles->addAction(actionDecFT8cycles3);
        menuQMAP_source->addAction(actionQmapSourceAuto);
        menuQMAP_source->addAction(actionQmapSource1);
        menuQMAP_source->addAction(actionQmapSource2);
        menuQMAP_source->addAction(actionQmapSource3);
        menuQMAP_source->addAction(actionQmapSource4);
        menuSave->addAction(actionNone);
        menuSave->addAction(actionSave_decoded);
        menuSave->addAction(actionSave_all);
        menuSave->addAction(actionRemove_after_30days);
        menuSave->addSeparator();
        menuSave->addAction(actionDon_t_split_ALL_TXT);
        menuSave->addAction(actionSplit_ALL_TXT_yearly);
        menuSave->addAction(actionSplit_ALL_TXT_monthly);
        menuSave->addAction(actionDisable_writing_of_ALL_TXT);
        menuSave->addSeparator();
        menuSave->addAction(actionDefault_event_logging);
        menuSave->addAction(actionDiagnostic_mode);
        menuSave->addAction(actionDisable_event_logging);
        menuHelp->addAction(actionRelease_Notes);
        menuHelp->addAction(actionWS_Home_Page);
        menuHelp->addSeparator();
        menuHelp->addAction(actionWSJT_X_User_Guide);
        menuHelp->addAction(actionFT8_DXpedition_Mode_User_Guide);
        menuHelp->addAction(actionSuperFox_User_Guide);
        menuHelp->addAction(actionQSG_FST4);
        menuHelp->addAction(actionQSG_Q65);
        menuHelp->addAction(actionQSG_X250_M3);
        menuHelp->addAction(actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP);
        menuHelp->addAction(download_samples_action);
        menuHelp->addAction(actionDownload_EME_Ephemeris_Chart);
        menuHelp->addSeparator();
        menuHelp->addAction(actionKeyboard_shortcuts);
        menuHelp->addAction(actionSpecial_mouse_commands);
        menuHelp->addAction(actionShort_list_of_add_on_prefixes_and_suffixes);
        menuHelp->addSeparator();
        menuHelp->addAction(actionRig_Control_Errors);
        menuHelp->addAction(actionRecommended_Audio_Settings);
        menuHelp->addSeparator();
        menuHelp->addAction(actionCopyright_Notice);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuMode->addAction(actionFST4);
        menuMode->addAction(actionFT2);
        menuMode->addAction(actionFT4);
        menuMode->addAction(actionFT8);
        menuMode->addAction(actionJT4);
        menuMode->addAction(actionJT9);
        menuMode->addAction(actionJT65);
        menuMode->addAction(actionQ65);
        menuMode->addSeparator();
        menuMode->addAction(actionJTTY);
        menuMode->addAction(actionMSK144);
        menuMode->addSeparator();
        menuMode->addAction(actionFST4W);
        menuMode->addAction(actionWSPR);
        menuMode->addSeparator();
        menuMode->addAction(actionEcho);
        menuMode->addSeparator();
        menuMode->addAction(actionFreqCal);
        menuTools->addAction(actionErase_reference_spectrum);
        menuTools->addAction(actionMeasure_reference_spectrum);
        menuTools->addSeparator();
        menuTools->addAction(actionMeasure_phase_response);
        menuTools->addAction(view_phase_response_action);
        menuTools->addSeparator();
        menuTools->addAction(actionFrequency_calibration);
        menuTools->addAction(actionSolve_FreqCal);

        retranslateUi(MainWindow);

        controls_stack_widget->setCurrentIndex(0);
        respondComboBox->setCurrentIndex(-1);
        opt_controls_stack->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);
        RoundRobin->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "WSJT-X   by K1JT", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About WS", nullptr));
        actionWide_Waterfall->setText(QCoreApplication::translate("MainWindow", "Waterfall", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_next_in_directory->setText(QCoreApplication::translate("MainWindow", "Open next in directory", nullptr));
        actionDecode_remaining_files_in_directory->setText(QCoreApplication::translate("MainWindow", "Decode remaining files in directory", nullptr));
#if QT_CONFIG(shortcut)
        actionDecode_remaining_files_in_directory->setShortcut(QCoreApplication::translate("MainWindow", "Shift+F6", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete_all_wav_files_in_SaveDir->setText(QCoreApplication::translate("MainWindow", "Delete all *.wav && *.c2 files in SaveDir", nullptr));
        actionQuickDecode->setText(QCoreApplication::translate("MainWindow", "Fast", nullptr));
        actionNone->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        actionSave_all->setText(QCoreApplication::translate("MainWindow", "Save all", nullptr));
        actionRemove_after_30days->setText(QCoreApplication::translate("MainWindow", "Remove saved files after 30 days", nullptr));
        actionWSJT_X_User_Guide->setText(QCoreApplication::translate("MainWindow", "WSJT-X User Guide", nullptr));
        actionKeyboard_shortcuts->setText(QCoreApplication::translate("MainWindow", "Keyboard shortcuts", nullptr));
        actionSpecial_mouse_commands->setText(QCoreApplication::translate("MainWindow", "Special mouse commands", nullptr));
        actionJT9->setText(QCoreApplication::translate("MainWindow", "JT9", nullptr));
        actionSave_decoded->setText(QCoreApplication::translate("MainWindow", "Save decoded", nullptr));
        actionMediumDecode->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        actionDeepestDecode->setText(QCoreApplication::translate("MainWindow", "Deep", nullptr));
        actionErase_ALL_TXT->setText(QCoreApplication::translate("MainWindow", "Erase ALL.TXT", nullptr));
        actionErase_wsjtx_log_adi->setText(QCoreApplication::translate("MainWindow", "Erase wsjtx_log.adi", nullptr));
        actionErase_Tx_Log->setText(QCoreApplication::translate("MainWindow", "Erase wsjtx.log", nullptr));
        actionErase_Ignore_List->setText(QCoreApplication::translate("MainWindow", "Erase Ignore List", nullptr));
        actionJT65->setText(QCoreApplication::translate("MainWindow", "JT65", nullptr));
        actionAstronomical_data->setText(QCoreApplication::translate("MainWindow", "Astronomical data", nullptr));
        actionShort_list_of_add_on_prefixes_and_suffixes->setText(QCoreApplication::translate("MainWindow", "List of Type 1 prefixes and suffixes", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings...", nullptr));
        actionLocal_User_Guide->setText(QCoreApplication::translate("MainWindow", "Local User Guide", nullptr));
        actionOpen_log_directory->setText(QCoreApplication::translate("MainWindow", "Open log directory", nullptr));
        actionJT4->setText(QCoreApplication::translate("MainWindow", "JT4", nullptr));
        actionMessage_averaging->setText(QCoreApplication::translate("MainWindow", "Message averaging", nullptr));
        actionInclude_averaging->setText(QCoreApplication::translate("MainWindow", "Enable averaging", nullptr));
        actionInclude_correlation->setText(QCoreApplication::translate("MainWindow", "Enable deep search", nullptr));
        actionWSPR->setText(QCoreApplication::translate("MainWindow", "WSPR", nullptr));
        actionEcho_Graph->setText(QCoreApplication::translate("MainWindow", "Echo Graph", nullptr));
        actionEcho->setText(QCoreApplication::translate("MainWindow", "Echo", nullptr));
#if QT_CONFIG(tooltip)
        actionEcho->setToolTip(QCoreApplication::translate("MainWindow", "EME Echo mode", nullptr));
#endif // QT_CONFIG(tooltip)
        actionISCAT->setText(QCoreApplication::translate("MainWindow", "ISCAT", nullptr));
        actionFast_Graph->setText(QCoreApplication::translate("MainWindow", "Fast Graph", nullptr));
        download_samples_action->setText(QCoreApplication::translate("MainWindow", "&Download Samples ...", nullptr));
#if QT_CONFIG(whatsthis)
        download_samples_action->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Download sample audio files demonstrating the various modes.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionMSK144->setText(QCoreApplication::translate("MainWindow", "MSK144", nullptr));
        actionQRA64->setText(QCoreApplication::translate("MainWindow", "QRA64", nullptr));
        actionRelease_Notes->setText(QCoreApplication::translate("MainWindow", "Release Notes", nullptr));
        actionEnable_AP_DXcall->setText(QCoreApplication::translate("MainWindow", "Enable AP for DX Call", nullptr));
        actionFreqCal->setText(QCoreApplication::translate("MainWindow", "FreqCal", nullptr));
        actionMeasure_reference_spectrum->setText(QCoreApplication::translate("MainWindow", "Measure reference spectrum", nullptr));
        actionMeasure_phase_response->setText(QCoreApplication::translate("MainWindow", "Measure phase response", nullptr));
        actionErase_reference_spectrum->setText(QCoreApplication::translate("MainWindow", "Erase reference spectrum", nullptr));
        actionFrequency_calibration->setText(QCoreApplication::translate("MainWindow", "Execute frequency calibration cycle", nullptr));
        view_phase_response_action->setText(QCoreApplication::translate("MainWindow", "Equalization tools ...", nullptr));
        actionFT8->setText(QCoreApplication::translate("MainWindow", "FT8", nullptr));
        actionEnable_AP_FT8->setText(QCoreApplication::translate("MainWindow", "Enable AP", nullptr));
        actionEnable_AP_JT65->setText(QCoreApplication::translate("MainWindow", "Enable AP", nullptr));
        actionSolve_FreqCal->setText(QCoreApplication::translate("MainWindow", "Solve for calibration parameters", nullptr));
        actionCopyright_Notice->setText(QCoreApplication::translate("MainWindow", "Copyright notice", nullptr));
#if QT_CONFIG(shortcut)
        actionCopyright_Notice->setShortcut(QCoreApplication::translate("MainWindow", "Shift+F1", nullptr));
#endif // QT_CONFIG(shortcut)
        fox_log_action->setText(QCoreApplication::translate("MainWindow", "Fox log", nullptr));
        actionFT8_DXpedition_Mode_User_Guide->setText(QCoreApplication::translate("MainWindow", "FT8 DXpedition Mode User Guide", nullptr));
        reset_cabrillo_log_action->setText(QCoreApplication::translate("MainWindow", "Reset Cabrillo log ...", nullptr));
        actionColors->setText(QCoreApplication::translate("MainWindow", "Color highlighting scheme", nullptr));
        actionExport_Cabrillo_log->setText(QCoreApplication::translate("MainWindow", "Export Cabrillo log ...", nullptr));
        actionQSG_FST4->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to FST4 and FST4W", nullptr));
        contest_log_action->setText(QCoreApplication::translate("MainWindow", "Contest log", nullptr));
        actionErase_WSPR_hashtable->setText(QCoreApplication::translate("MainWindow", "Erase WSPR hashtable", nullptr));
        actionFT4->setText(QCoreApplication::translate("MainWindow", "FT4", nullptr));
        actionFST4->setText(QCoreApplication::translate("MainWindow", "FST4", nullptr));
        actionFST4W->setText(QCoreApplication::translate("MainWindow", "FST4W", nullptr));
        actionQ65->setText(QCoreApplication::translate("MainWindow", "Q65", nullptr));
        actionSWL_Mode->setText(QCoreApplication::translate("MainWindow", "SWL Mode", nullptr));
#if QT_CONFIG(tooltip)
        actionSWL_Mode->setToolTip(QCoreApplication::translate("MainWindow", "Hide lower panel controls to maximize deocde windows", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQSG_Q65->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to Q65", nullptr));
        actionAuto_Clear_Avg->setText(QCoreApplication::translate("MainWindow", "Auto Clear Avg after decode", nullptr));
        actionQSG_X250_M3->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to WSJT-X 2.5.0 and MAP65 3.0", nullptr));
        actionDon_t_split_ALL_TXT->setText(QCoreApplication::translate("MainWindow", "Don't split ALL.TXT", nullptr));
        actionSplit_ALL_TXT_yearly->setText(QCoreApplication::translate("MainWindow", "Split ALL.TXT yearly", nullptr));
        actionSplit_ALL_TXT_monthly->setText(QCoreApplication::translate("MainWindow", "Split ALL.TXT monthly", nullptr));
        actionDisable_writing_of_ALL_TXT->setText(QCoreApplication::translate("MainWindow", "Disable writing of ALL.TXT", nullptr));
        actionActiveStations->setText(QCoreApplication::translate("MainWindow", "Active Stations", nullptr));
        actionBand_Buttons->setText(QCoreApplication::translate("MainWindow", "Band Buttons", nullptr));
        actionUse_Dark_Style->setText(QCoreApplication::translate("MainWindow", "Use Dark Style", nullptr));
        actionCallsign_overlay_enabled->setText(QCoreApplication::translate("MainWindow", "Show decoded callsigns", nullptr));
#if QT_CONFIG(tooltip)
        actionCallsign_overlay_enabled->setToolTip(QCoreApplication::translate("MainWindow", "Draw decoded callsigns as labels on top of the audio waterfall at their respective frequencies.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCallsign_persist_1->setText(QCoreApplication::translate("MainWindow", "Persist 1 period", nullptr));
        actionCallsign_persist_2->setText(QCoreApplication::translate("MainWindow", "Persist 2 periods", nullptr));
        actionCallsign_persist_3->setText(QCoreApplication::translate("MainWindow", "Persist 3 periods", nullptr));
        actionCallsign_persist_4->setText(QCoreApplication::translate("MainWindow", "Persist 4 periods", nullptr));
        actionCallsign_persist_5->setText(QCoreApplication::translate("MainWindow", "Persist 5 periods", nullptr));
        actionCallsign_font_small->setText(QCoreApplication::translate("MainWindow", "Small (7 pt)", nullptr));
        actionCallsign_font_normal->setText(QCoreApplication::translate("MainWindow", "Normal (8 pt)", nullptr));
        actionCallsign_font_medium->setText(QCoreApplication::translate("MainWindow", "Medium (10 pt)", nullptr));
        actionCallsign_font_large->setText(QCoreApplication::translate("MainWindow", "Large (12 pt)", nullptr));
        actionCallsign_position_top->setText(QCoreApplication::translate("MainWindow", "Top of waterfall", nullptr));
        actionCallsign_position_bottom->setText(QCoreApplication::translate("MainWindow", "Bottom of waterfall (above divider)", nullptr));
        actionCallsign_transparency_None->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        actionCallsign_transparency_Low->setText(QCoreApplication::translate("MainWindow", "Low", nullptr));
        actionCallsign_transparency_Medium->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        actionCallsign_transparency_High->setText(QCoreApplication::translate("MainWindow", "High", nullptr));
        actionReduce_false_decodes->setText(QCoreApplication::translate("MainWindow", "Reduce false decodes", nullptr));
        actionDefault_event_logging->setText(QCoreApplication::translate("MainWindow", "Default event logging", nullptr));
        actionDiagnostic_mode->setText(QCoreApplication::translate("MainWindow", "Diagnostic mode", nullptr));
        actionDisable_event_logging->setText(QCoreApplication::translate("MainWindow", "Disable event logging", nullptr));
        actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to WSJT-X 2.7 and QMAP", nullptr));
        actionWS_Home_Page->setText(QCoreApplication::translate("MainWindow", "WS Home Page", nullptr));
#if QT_CONFIG(whatsthis)
        actionWS_Home_Page->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Go to the WS home page.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionThe_additional_features_of_wsjt_x_improved->setText(QCoreApplication::translate("MainWindow", "What's new?", nullptr));
#if QT_CONFIG(whatsthis)
        actionThe_additional_features_of_wsjt_x_improved->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Overview on the additional features of wsjt-x_improved.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionRecommended_Audio_Settings->setText(QCoreApplication::translate("MainWindow", "Recommended audio settings", nullptr));
#if QT_CONFIG(whatsthis)
        actionRecommended_Audio_Settings->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Recommended Audio Settings.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionRig_Control_Errors->setText(QCoreApplication::translate("MainWindow", "How to deal with rig control errors", nullptr));
#if QT_CONFIG(whatsthis)
        actionRig_Control_Errors->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>How to deal with rig control errors.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionErase_list_of_Q65_callers->setText(QCoreApplication::translate("MainWindow", "Erase list of Q65 callers", nullptr));
        actionSuperFox_User_Guide->setText(QCoreApplication::translate("MainWindow", "SuperFox User Guide", nullptr));
        actionQSYMessage_Creator->setText(QCoreApplication::translate("MainWindow", "Message Creator", nullptr));
        actionHideB4->setText(QCoreApplication::translate("MainWindow", "Hide stations worked before on band", nullptr));
        actionHideToday->setText(QCoreApplication::translate("MainWindow", "Hide stations worked today or yesterday", nullptr));
        actionHideIgnored->setText(QCoreApplication::translate("MainWindow", "Hide stations from Ignore List", nullptr));
        actionIgnoreToday->setText(QCoreApplication::translate("MainWindow", "Ignore stations worked today or yesterday", nullptr));
        actionIgnoreIgnored->setText(QCoreApplication::translate("MainWindow", "Ignore stations from Ignore List", nullptr));
        actionHideTerritory1->setText(QCoreApplication::translate("MainWindow", "Hide stations from Territory 1", nullptr));
        actionHideTerritory2->setText(QCoreApplication::translate("MainWindow", "Hide stations from Territory 2", nullptr));
        actionHideTerritory3->setText(QCoreApplication::translate("MainWindow", "Hide stations from Territory 3", nullptr));
        actionHideTerritory4->setText(QCoreApplication::translate("MainWindow", "Hide stations from Territory 4", nullptr));
        actionHideEU->setText(QCoreApplication::translate("MainWindow", "Hide stations from Europe", nullptr));
        actionHideNA->setText(QCoreApplication::translate("MainWindow", "Hide stations from North America", nullptr));
        actionHideSA->setText(QCoreApplication::translate("MainWindow", "Hide stations from South America", nullptr));
        actionHideAS->setText(QCoreApplication::translate("MainWindow", "Hide stations from Asia", nullptr));
        actionHideAF->setText(QCoreApplication::translate("MainWindow", "Hide stations from Africa", nullptr));
        actionHideOC->setText(QCoreApplication::translate("MainWindow", "Hide stations from Oceania", nullptr));
        actionHideAN->setText(QCoreApplication::translate("MainWindow", "Hide stations from Antarctica", nullptr));
        actionFull_Duplex_Mode->setText(QCoreApplication::translate("MainWindow", "Full Duplex Mode", nullptr));
        actionHighlightB4->setText(QCoreApplication::translate("MainWindow", "Highlight callsigns worked before on band", nullptr));
        actionHighlightToday->setText(QCoreApplication::translate("MainWindow", "Highlight callsigns worked today or yesterday", nullptr));
        actionHighlightIgnored->setText(QCoreApplication::translate("MainWindow", "Highlight callsigns from Ignore List", nullptr));
        actionEnable_QSY_Popups->setText(QCoreApplication::translate("MainWindow", "Enable Message Popups", nullptr));
        actionQSY_Monitor->setText(QCoreApplication::translate("MainWindow", "QSY Monitor", nullptr));
        actionIgnoreB4->setText(QCoreApplication::translate("MainWindow", "Ignore stations worked before on band", nullptr));
        actionUse_multithreaded_FT8_decoder->setText(QCoreApplication::translate("MainWindow", "Use multithreaded FT8 decoder", nullptr));
        actionMTAuto->setText(QCoreApplication::translate("MainWindow", "Auto", nullptr));
        actionMT1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        actionMT2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        actionMT2->setIconText(QCoreApplication::translate("MainWindow", "2", nullptr));
        actionMT3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        actionMT3->setIconText(QCoreApplication::translate("MainWindow", "3", nullptr));
        actionMT4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        actionMT5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        actionMT5->setIconText(QCoreApplication::translate("MainWindow", "5", nullptr));
        actionMT6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        actionMT6->setIconText(QCoreApplication::translate("MainWindow", "6", nullptr));
        actionMT7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        actionMT7->setIconText(QCoreApplication::translate("MainWindow", "7", nullptr));
        actionMT8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        actionMT9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        actionMT9->setIconText(QCoreApplication::translate("MainWindow", "9", nullptr));
        actionMT10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        actionMT10->setIconText(QCoreApplication::translate("MainWindow", "10", nullptr));
        actionMT11->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        actionMT11->setIconText(QCoreApplication::translate("MainWindow", "11", nullptr));
        actionMT12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        actionRXfLow->setText(QCoreApplication::translate("MainWindow", "Low", nullptr));
        actionRXfMedium->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        actionRXfHigh->setText(QCoreApplication::translate("MainWindow", "High", nullptr));
        actionDecFT8cycles1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        actionDecFT8cycles2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        actionDecFT8cycles3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        actionFT8SensMin->setText(QCoreApplication::translate("MainWindow", "Minimum", nullptr));
        actionlowFT8thresholds->setText(QCoreApplication::translate("MainWindow", "Use low thresholds", nullptr));
        actionFT8subpass->setText(QCoreApplication::translate("MainWindow", "Use subpass", nullptr));
        actionStartTwoStage->setText(QCoreApplication::translate("MainWindow", "2-Stage", nullptr));
        actionStartThreeStage->setText(QCoreApplication::translate("MainWindow", "3-Stage", nullptr));
        actionStartEarly->setText(QCoreApplication::translate("MainWindow", "Early", nullptr));
        actionStartNormal->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        actionStartLate->setText(QCoreApplication::translate("MainWindow", "Late", nullptr));
        actionFT8WidebandDXCallSearch->setText(QCoreApplication::translate("MainWindow", "Wideband DX Call search", nullptr));
        actionHide_FT8_dupe_messages->setText(QCoreApplication::translate("MainWindow", "Hide FT8 dupe messages", nullptr));
        actionNo_MTD_a8_decodes->setText(QCoreApplication::translate("MainWindow", "Skip a8 decodes", nullptr));
        actionVHF_UHF_Buttons->setText(QCoreApplication::translate("MainWindow", "VHF / UHF Buttons", nullptr));
        actionHighlightTerritory1->setText(QCoreApplication::translate("MainWindow", "Highlight stations from Territory 1", nullptr));
        actionHighlightTerritory2->setText(QCoreApplication::translate("MainWindow", "Highlight stations from Territory 2", nullptr));
        actionHighlightTerritory3->setText(QCoreApplication::translate("MainWindow", "Highlight stations from Territory 3", nullptr));
        actionHighlightTerritory4->setText(QCoreApplication::translate("MainWindow", "Highlight stations from Territory 4", nullptr));
        actionDisable_clicks_on_waterfall->setText(QCoreApplication::translate("MainWindow", "Disable clicks on waterfall", nullptr));
        actionDownload_EME_Ephemeris_Chart->setText(QCoreApplication::translate("MainWindow", "Download EME Ephemeris Chart", nullptr));
        actionHide_AP_info->setText(QCoreApplication::translate("MainWindow", "Hide AP information", nullptr));
#if QT_CONFIG(tooltip)
        actionHide_AP_info->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Hide AP information</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionHighlight_Whitelist_entries->setText(QCoreApplication::translate("MainWindow", "Highlight Whitelist entries", nullptr));
        actionJTTY->setText(QCoreApplication::translate("MainWindow", "JTTY", nullptr));
        actionFT2->setText(QCoreApplication::translate("MainWindow", "FT2", nullptr));
        actionAccept_QMAP_click_events->setText(QCoreApplication::translate("MainWindow", "Accept WS-MAP/EME65 click events", nullptr));
        actionClaimQmapClicks->setText(QCoreApplication::translate("MainWindow", "Claim WS-MAP", nullptr));
#if QT_CONFIG(tooltip)
        actionClaimQmapClicks->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Claim exclusive click-to-work rights for the subscribed WS-MAP source. Check this when two or more WS instances watch the same WS-MAP source and only one should act on clicks.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQmapSourceAuto->setText(QCoreApplication::translate("MainWindow", "Auto", nullptr));
#if QT_CONFIG(tooltip)
        actionQmapSourceAuto->setToolTip(QCoreApplication::translate("MainWindow", "Watch WS-MAP's legacy/default shared-memory segment (mem_qmap). Safe zero-config default -- matches every WS-MAP instance before per-instance IDs existed, and any single WS-MAP running today.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQmapSource1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
#if QT_CONFIG(tooltip)
        actionQmapSource1->setToolTip(QCoreApplication::translate("MainWindow", "Watch only the WS-MAP instance whose Settings dialog has Instance ID set to 1 (or left at default -- ID 1 uses the same legacy segment as Auto). Restart WS to apply.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQmapSource2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
#if QT_CONFIG(tooltip)
        actionQmapSource2->setToolTip(QCoreApplication::translate("MainWindow", "Watch only the WS-MAP instance whose Settings dialog has Instance ID set to 2 (mem_qmap_2). Restart WS to apply.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQmapSource3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
#if QT_CONFIG(tooltip)
        actionQmapSource3->setToolTip(QCoreApplication::translate("MainWindow", "Watch only the WS-MAP instance whose Settings dialog has Instance ID set to 3 (mem_qmap_3). Restart WS to apply.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQmapSource4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
#if QT_CONFIG(tooltip)
        actionQmapSource4->setToolTip(QCoreApplication::translate("MainWindow", "Watch only the WS-MAP instance whose Settings dialog has Instance ID set to 4 (mem_qmap_4). Restart WS to apply.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFSK441->setText(QCoreApplication::translate("MainWindow", "FSK441", nullptr));
        lh_decodes_title_label->setText(QCoreApplication::translate("MainWindow", "Band Activity", nullptr));
        lh_decodes_headings_label->setText(QCoreApplication::translate("MainWindow", "UTC           dB            DT           Freq          Dr ", nullptr));
        rh_decodes_title_label->setText(QCoreApplication::translate("MainWindow", "Rx Frequency", nullptr));
        rh_decodes_headings_label->setText(QCoreApplication::translate("MainWindow", "UTC           dB            DT           Freq          Dr ", nullptr));
        pb40->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        pb10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        pb17->setText(QCoreApplication::translate("MainWindow", "17", nullptr));
        pb60->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        pb12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        pb160->setText(QCoreApplication::translate("MainWindow", "160", nullptr));
        pb20->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        pb80->setText(QCoreApplication::translate("MainWindow", "80", nullptr));
        pb70->setText(QCoreApplication::translate("MainWindow", "70", nullptr));
        pb15->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        pb2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pb30->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        pb6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pb24G->setText(QCoreApplication::translate("MainWindow", "24G", nullptr));
        pb10G->setText(QCoreApplication::translate("MainWindow", "10G", nullptr));
        pb5G->setText(QCoreApplication::translate("MainWindow", "5G", nullptr));
        pb9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pb13->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        pb23->setText(QCoreApplication::translate("MainWindow", "23", nullptr));
        pb902->setText(QCoreApplication::translate("MainWindow", "33", nullptr));
        pb432->setText(QCoreApplication::translate("MainWindow", "70", nullptr));
        pb220->setText(QCoreApplication::translate("MainWindow", "1.25", nullptr));
        pb144->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pb4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pb50->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pb8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
#if QT_CONFIG(tooltip)
        cbCQonly->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>CQ or CQ/73 messages only. <br>Right-click for messages with DX Call only.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbCQonly->setText(QCoreApplication::translate("MainWindow", "CQ only", nullptr));
#if QT_CONFIG(tooltip)
        cbBypass->setToolTip(QCoreApplication::translate("MainWindow", "Bypass all filters", nullptr));
#endif // QT_CONFIG(tooltip)
        cbBypass->setText(QCoreApplication::translate("MainWindow", "BP", nullptr));
#if QT_CONFIG(tooltip)
        logQSOButton->setToolTip(QCoreApplication::translate("MainWindow", "Enter this QSO in log", nullptr));
#endif // QT_CONFIG(tooltip)
        logQSOButton->setText(QCoreApplication::translate("MainWindow", "Log &QSO", nullptr));
#if QT_CONFIG(tooltip)
        stopButton->setToolTip(QCoreApplication::translate("MainWindow", "Stop monitoring", nullptr));
#endif // QT_CONFIG(tooltip)
        stopButton->setText(QCoreApplication::translate("MainWindow", "&Stop", nullptr));
#if QT_CONFIG(tooltip)
        monitorButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Toggle monitoring On/Off. <br>Yellow when saving .wav files.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        monitorButton->setText(QCoreApplication::translate("MainWindow", "&Monitor", nullptr));
#if QT_CONFIG(tooltip)
        EraseButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Erase right window. Double-click to erase both windows.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        EraseButton->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Erase right window. Double-click to erase both windows.", nullptr));
#endif // QT_CONFIG(accessibility)
        EraseButton->setText(QCoreApplication::translate("MainWindow", "&Erase", nullptr));
#if QT_CONFIG(tooltip)
        ClrAvgButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Clear the accumulating message average.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        ClrAvgButton->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Clear the accumulating message average.", nullptr));
#endif // QT_CONFIG(accessibility)
        ClrAvgButton->setText(QCoreApplication::translate("MainWindow", "Clear Avg", nullptr));
        sbEchoAvg->setPrefix(QCoreApplication::translate("MainWindow", "Avg ", nullptr));
#if QT_CONFIG(tooltip)
        DecodeButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Decode most recent Rx period at QSO Frequency</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        DecodeButton->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Decode most recent Rx period at QSO Frequency", nullptr));
#endif // QT_CONFIG(accessibility)
        DecodeButton->setText(QCoreApplication::translate("MainWindow", "&Decode", nullptr));
#if QT_CONFIG(tooltip)
        autoButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Toggle Auto-Tx On/Off</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        autoButton->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Toggle Auto-Tx On/Off", nullptr));
#endif // QT_CONFIG(accessibility)
        autoButton->setText(QCoreApplication::translate("MainWindow", "E&nable Tx", nullptr));
#if QT_CONFIG(tooltip)
        stopTxButton->setToolTip(QCoreApplication::translate("MainWindow", "Stop transmitting immediately", nullptr));
#endif // QT_CONFIG(tooltip)
        stopTxButton->setText(QCoreApplication::translate("MainWindow", "&Halt Tx", nullptr));
#if QT_CONFIG(tooltip)
        tuneButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Toggle a pure Tx tone On/Off <br>Right-click to tune rig</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        tuneButton->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Toggle a pure Tx tone On/Off", nullptr));
#endif // QT_CONFIG(accessibility)
        tuneButton->setText(QCoreApplication::translate("MainWindow", "&Tune", nullptr));
        cbMenus->setText(QCoreApplication::translate("MainWindow", "Menus", nullptr));
#if QT_CONFIG(tooltip)
        DX_Call_Button->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Toggle Wait &amp; Call On/Off. Right-click to clear the DX Call box.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        DX_Call_Button->setText(QCoreApplication::translate("MainWindow", "DX Call", nullptr));
#if QT_CONFIG(tooltip)
        dxGridEntry->setToolTip(QCoreApplication::translate("MainWindow", "Locator of station to be worked", nullptr));
#endif // QT_CONFIG(tooltip)
        dxGridEntry->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "DX Grid", nullptr));
#if QT_CONFIG(tooltip)
        dxCallEntry->setToolTip(QCoreApplication::translate("MainWindow", "Callsign of station to be worked", nullptr));
#endif // QT_CONFIG(tooltip)
        dxCallEntry->setText(QString());
        labAz->setText(QCoreApplication::translate("MainWindow", "Az: 251     16553 km", nullptr));
#if QT_CONFIG(tooltip)
        lookupButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Search for callsign in database. <br>Right-click searches for callsign on QRZ.com.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lookupButton->setText(QCoreApplication::translate("MainWindow", "&Lookup", nullptr));
#if QT_CONFIG(tooltip)
        addButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Add callsign and locator to database. <br>Right-click searches for callsign on hamqth.com.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
#if QT_CONFIG(tooltip)
        ignoreButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Put callsign on the Ignore List.<br>Right-click searches for callsign on qrzcq.com.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ignoreButton->setText(QCoreApplication::translate("MainWindow", "Ignore", nullptr));
#if QT_CONFIG(tooltip)
        outAttenuation->setToolTip(QCoreApplication::translate("MainWindow", "Adjust Tx audio level", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "Pwr", nullptr));
#if QT_CONFIG(tooltip)
        sbCQTxFreq->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Frequency to call CQ on in kHz above the current MHz</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        sbCQTxFreq->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Frequency to call CQ on in kHz above the current MHz", nullptr));
#endif // QT_CONFIG(accessibility)
        sbCQTxFreq->setPrefix(QCoreApplication::translate("MainWindow", "Tx CQ ", nullptr));
#if QT_CONFIG(tooltip)
        cbCQTx->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check this to call CQ on the &quot;Tx CQ&quot; frequency. Rx will be on the current frequency and the CQ message wiill include the current Rx frequency so callers know which frequency to reply on.</p><p>Not available to nonstandard callsign holders.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        cbCQTx->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Check this to call CQ on the \"Tx CQ\" frequency. Rx will be on the current frequency and the CQ message wiill include the current Rx frequency so callers know which frequency to reply on.\n"
"Not available to nonstandard callsign holders.", nullptr));
#endif // QT_CONFIG(accessibility)
        cbCQTx->setText(QString());
#if QT_CONFIG(tooltip)
        cbRxAll->setToolTip(QCoreApplication::translate("MainWindow", "Decode other Hounds calling above 1000 Hz audio offset", nullptr));
#endif // QT_CONFIG(tooltip)
        cbRxAll->setText(QCoreApplication::translate("MainWindow", "Rx All Freqs", nullptr));
        labDXped->setText(QCoreApplication::translate("MainWindow", "Fox", nullptr));
#if QT_CONFIG(tooltip)
        cbSWL->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check to monitor Sh messages.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        cbSWL->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Check to monitor Sh messages.", nullptr));
#endif // QT_CONFIG(accessibility)
        cbSWL->setText(QCoreApplication::translate("MainWindow", "SWL", nullptr));
#if QT_CONFIG(tooltip)
        pbBestSP->setToolTip(QCoreApplication::translate("MainWindow", "Enable auto response to the first decode from a new DXCC or new call on the current band.", nullptr));
#endif // QT_CONFIG(tooltip)
        pbBestSP->setText(QCoreApplication::translate("MainWindow", "Best S+P", nullptr));
#if QT_CONFIG(tooltip)
        measure_check_box->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check this to start recording calibration data.<br/>While measuring calibration correction is disabled.<br/>When not checked you can view the calibration results.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        measure_check_box->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Check this to start recording calibration data.\n"
"While measuring calibration correction is disabled.\n"
"When not checked you can view the calibration results.", nullptr));
#endif // QT_CONFIG(accessibility)
        measure_check_box->setText(QCoreApplication::translate("MainWindow", "Measure", nullptr));
#if QT_CONFIG(tooltip)
        cbShMsgs->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check to use short-format messages.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        cbShMsgs->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Check to use short-format messages.", nullptr));
#endif // QT_CONFIG(accessibility)
        cbShMsgs->setText(QCoreApplication::translate("MainWindow", "Sh", nullptr));
#if QT_CONFIG(tooltip)
        cbFast9->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check to enable JT9 fast modes</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        cbFast9->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Check to enable JT9 fast modes", nullptr));
#endif // QT_CONFIG(accessibility)
        cbFast9->setText(QCoreApplication::translate("MainWindow", "Fast", nullptr));
#if QT_CONFIG(tooltip)
        cbAutoSeq->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check to enable automatic sequencing of Tx messages based on received messages.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        cbAutoSeq->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Check to enable automatic sequencing of Tx messages based on received messages.", nullptr));
#endif // QT_CONFIG(accessibility)
        cbAutoSeq->setText(QCoreApplication::translate("MainWindow", "Auto Seq", nullptr));
#if QT_CONFIG(tooltip)
        respondComboBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Select <span style=\" font-weight:600;\">CQ: None</span> to choose callers manually.</p><p>Select <span style=\" font-weight:600;\">CQ: First</span> to respond automatically to the first decoded reply to your CQ. </p><p>Select <span style=\" font-weight:600;\">CQ: Max Dist</span> to respond automatically to the reply yielding most points in the ARRL International Digital Contest, or in general to the most distant station, if its message has a valid grid.</p><p>Select <span style=\" font-weight:600;\">CQ: Max dB</span> to respond automatically to the the strongest station's reply to your CQ. </p><p>Select <span style=\" font-weight:600;\">CQ: Min dB</span> to respond automatically to the the weakest station's reply to your CQ. </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        respondComboBox->setCurrentText(QString());
#if QT_CONFIG(tooltip)
        cbTx6->setToolTip(QCoreApplication::translate("MainWindow", "Check to generate \"@1250  (SEND MSGS)\" in Tx6.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTx6->setText(QCoreApplication::translate("MainWindow", "Tx6", nullptr));
#if QT_CONFIG(tooltip)
        txFirstCheckBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check to Tx in even-numbered minutes or sequences, starting at 0; uncheck for odd sequences. Right-click to freeze the state of the checkbox.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        txFirstCheckBox->setAccessibleDescription(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check to Tx in even-numbered minutes or sequences, starting at 0; uncheck for odd sequences. Right-click to freeze the state of the checkbox. Right-click either the FT8 or MSK button to unfreeze.</p></body></html>", nullptr));
#endif // QT_CONFIG(accessibility)
        txFirstCheckBox->setText(QCoreApplication::translate("MainWindow", "Tx even/1st", nullptr));
#if QT_CONFIG(tooltip)
        TxFreqSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "Audio Tx frequency", nullptr));
#endif // QT_CONFIG(tooltip)
        TxFreqSpinBox->setSuffix(QCoreApplication::translate("MainWindow", "  Hz", nullptr));
        TxFreqSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "Tx  ", nullptr));
#if QT_CONFIG(tooltip)
        pbR2T->setToolTip(QCoreApplication::translate("MainWindow", "Set Tx frequency to Rx Frequency", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        pbR2T->setAccessibleName(QCoreApplication::translate("MainWindow", "Set Tx frequency to Rx Frequency", nullptr));
#endif // QT_CONFIG(accessibility)
        pbR2T->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
#if QT_CONFIG(tooltip)
        sbFtol->setToolTip(QCoreApplication::translate("MainWindow", "Frequency tolerance (Hz)", nullptr));
#endif // QT_CONFIG(tooltip)
        sbFtol->setPrefix(QCoreApplication::translate("MainWindow", "F Tol  ", nullptr));
#if QT_CONFIG(tooltip)
        pbT2R->setToolTip(QCoreApplication::translate("MainWindow", "Set Rx frequency to Tx Frequency", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        pbT2R->setAccessibleName(QCoreApplication::translate("MainWindow", "Set Rx frequency to Tx Frequency", nullptr));
#endif // QT_CONFIG(accessibility)
        pbT2R->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
#if QT_CONFIG(tooltip)
        RxFreqSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "Audio Rx frequency", nullptr));
#endif // QT_CONFIG(tooltip)
        RxFreqSpinBox->setSuffix(QCoreApplication::translate("MainWindow", "  Hz", nullptr));
        RxFreqSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "Rx  ", nullptr));
#if QT_CONFIG(tooltip)
        rptSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Signal report: Signal-to-noise ratio in 2500 Hz reference bandwidth (dB).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        rptSpinBox->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Signal report: Signal-to-noise ratio in 2500 Hz reference bandwidth (dB).", nullptr));
#endif // QT_CONFIG(accessibility)
        rptSpinBox->setPrefix(QCoreApplication::translate("MainWindow", " Report ", nullptr));
#if QT_CONFIG(tooltip)
        sbTR->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Tx/Rx or Frequency calibration sequence length</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        sbTR->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Tx/Rx or Frequency calibration sequence length", nullptr));
#endif // QT_CONFIG(accessibility)
        sbTR->setSuffix(QCoreApplication::translate("MainWindow", "  s", nullptr));
        sbTR->setPrefix(QCoreApplication::translate("MainWindow", "T/R  ", nullptr));
#if QT_CONFIG(tooltip)
        pb15C->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to T/R 15 s and Submode C.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb15C->setText(QCoreApplication::translate("MainWindow", "15C", nullptr));
#if QT_CONFIG(tooltip)
        pb15A->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to T/R 15 s and Submode A.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb15A->setText(QCoreApplication::translate("MainWindow", "15A", nullptr));
#if QT_CONFIG(tooltip)
        pb30B->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to T/R 30 s and Submode B.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb30B->setText(QCoreApplication::translate("MainWindow", "30B", nullptr));
#if QT_CONFIG(tooltip)
        pb60C->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to T/R 60 s and Submode C.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb60C->setText(QCoreApplication::translate("MainWindow", "60C", nullptr));
#if QT_CONFIG(tooltip)
        pb60D->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to T/R 60 s and Submode D.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb60D->setText(QCoreApplication::translate("MainWindow", "60D", nullptr));
#if QT_CONFIG(tooltip)
        pb60E->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to T/R 60 s and Submode E.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb60E->setText(QCoreApplication::translate("MainWindow", "60E", nullptr));
#if QT_CONFIG(tooltip)
        cbHoldTxFreq->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check to keep Tx frequency fixed when double-clicking on decoded text.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        cbHoldTxFreq->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Check to keep Tx frequency fixed when double-clicking on decoded text.", nullptr));
#endif // QT_CONFIG(accessibility)
        cbHoldTxFreq->setText(QCoreApplication::translate("MainWindow", "Hold Tx Freq", nullptr));
        sbSerialNumber->setPrefix(QCoreApplication::translate("MainWindow", "Tx# ", nullptr));
        sbF_Low->setPrefix(QCoreApplication::translate("MainWindow", "F Low   ", nullptr));
        sbF_High->setSuffix(QString());
        sbF_High->setPrefix(QCoreApplication::translate("MainWindow", "F High ", nullptr));
#if QT_CONFIG(tooltip)
        sbSubmode->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Submode determines tone spacing; A is narrowest.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        sbSubmode->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Submode determines tone spacing; A is narrowest.", nullptr));
#endif // QT_CONFIG(accessibility)
        sbSubmode->setPrefix(QCoreApplication::translate("MainWindow", "Submode ", nullptr));
#if QT_CONFIG(tooltip)
        syncSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Synchronizing threshold.  Lower numbers accept weaker sync signals.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        syncSpinBox->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Synchronizing threshold. Lower numbers accept weaker sync signals.", nullptr));
#endif // QT_CONFIG(accessibility)
        syncSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "Sync   ", nullptr));
#if QT_CONFIG(tooltip)
        sbMaxDrift->setToolTip(QCoreApplication::translate("MainWindow", "Maximum drift rate in units of symbol rate per transmission.", nullptr));
#endif // QT_CONFIG(tooltip)
        sbMaxDrift->setPrefix(QCoreApplication::translate("MainWindow", "Max Drift  ", nullptr));
#if QT_CONFIG(tooltip)
        claimQmapToolButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Claim exclusive click-to-work rights for the subscribed WS-MAP source. Check this when two or more WS instances watch the same WS-MAP source and only one should act on clicks.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        claimQmapToolButton->setText(QCoreApplication::translate("MainWindow", "Claim WS-MAP", nullptr));
#if QT_CONFIG(tooltip)
        txrb6->setToolTip(QCoreApplication::translate("MainWindow", "Send this message in next Tx interval", nullptr));
#endif // QT_CONFIG(tooltip)
        txrb6->setText(QString());
#if QT_CONFIG(shortcut)
        txrb6->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+6", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        label_5->setToolTip(QCoreApplication::translate("MainWindow", "Queue up the next Tx message", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
#if QT_CONFIG(tooltip)
        txrb4->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Send this message in next Tx interval</p><p>Double-click to toggle between RRR and RR73 messages in Tx4 (not allowed for type 2 compound call holders)</p><p>RR73 messages should only be used when you are reasonably confident that no message repetitions will be required</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        txrb4->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Send this message in next Tx interval\n"
"Double-click to toggle between RRR and RR73 messages in Tx4 (not allowed for type 2 compound call holders)\n"
"RR73 messages should only be used when you are reasonably confident that no message repetitions will be required", nullptr));
#endif // QT_CONFIG(accessibility)
        txrb4->setText(QString());
#if QT_CONFIG(shortcut)
        txrb4->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+4", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        txrb1->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Send this message in next Tx interval</p><p>Double click to toggle the use of the Tx1 message to start a QSO with a station (not allowed for type 1 compound call holders)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        txrb1->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Send this message in next Tx interval\n"
"Double click to toggle the use of the Tx1 message to start a QSO with a station (not allowed for type 1 compound call holders)", nullptr));
#endif // QT_CONFIG(accessibility)
        txrb1->setText(QString());
#if QT_CONFIG(shortcut)
        txrb1->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+1", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        txb5->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to this Tx message NOW</p><p>Double-click to reset to the standard 73 message</p><p>Right-click to retain Tx5 free text</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        txb5->setAccessibleDescription(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to this Tx message NOW</p><p>Double-click to reset to the standard 73 message</p><p>Right-click to retain Tx5 free text</p></body></html>", nullptr));
#endif // QT_CONFIG(accessibility)
        txb5->setText(QCoreApplication::translate("MainWindow", "Tx &5", nullptr));
#if QT_CONFIG(shortcut)
        txb5->setShortcut(QCoreApplication::translate("MainWindow", "Alt+5", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        txb2->setToolTip(QCoreApplication::translate("MainWindow", "Switch to this Tx message NOW", nullptr));
#endif // QT_CONFIG(tooltip)
        txb2->setText(QCoreApplication::translate("MainWindow", "Tx &2", nullptr));
#if QT_CONFIG(shortcut)
        txb2->setShortcut(QCoreApplication::translate("MainWindow", "Alt+2", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        label_2->setToolTip(QCoreApplication::translate("MainWindow", "Switch to this Tx message NOW", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("MainWindow", "Now", nullptr));
#if QT_CONFIG(tooltip)
        txrb2->setToolTip(QCoreApplication::translate("MainWindow", "Send this message in next Tx interval", nullptr));
#endif // QT_CONFIG(tooltip)
        txrb2->setText(QString());
#if QT_CONFIG(shortcut)
        txrb2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+2", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        genStdMsgsPushButton->setToolTip(QCoreApplication::translate("MainWindow", "Generate standard messages for minimal QSO", nullptr));
#endif // QT_CONFIG(tooltip)
        genStdMsgsPushButton->setText(QCoreApplication::translate("MainWindow", "Generate Std Msgs", nullptr));
#if QT_CONFIG(tooltip)
        txb3->setToolTip(QCoreApplication::translate("MainWindow", "Switch to this Tx message NOW", nullptr));
#endif // QT_CONFIG(tooltip)
        txb3->setText(QCoreApplication::translate("MainWindow", "Tx &3", nullptr));
#if QT_CONFIG(shortcut)
        txb3->setShortcut(QCoreApplication::translate("MainWindow", "Alt+3", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        txb4->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to this Tx message NOW</p><p>Double-click to toggle between RRR and RR73 messages in Tx4 (not allowed for type2 compound call holders)</p><p>RR73 messages should only be used when you are reasonably confident that no message repetitions will be required</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        txb4->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Switch to this Tx message NOW\n"
"Double-click to toggle between RRR and RR73 messages in Tx4 (not allowed for type2 compound call holders)\n"
"RR73 messages should only be used when you are reasonably confident that no message repetitions will be required", nullptr));
#endif // QT_CONFIG(accessibility)
        txb4->setText(QCoreApplication::translate("MainWindow", "Tx &4", nullptr));
#if QT_CONFIG(shortcut)
        txb4->setShortcut(QCoreApplication::translate("MainWindow", "Alt+4", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        txb1->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to this Tx message NOW</p><p>Double click to toggle the use of the Tx1 message to start a QSO with a station (not allowed for type 1 compound call holders)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        txb1->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Switch to this Tx message NOW\n"
"Double click to toggle the use of the Tx1 message to start a QSO with a station (not allowed for type 1 compound call holders)", nullptr));
#endif // QT_CONFIG(accessibility)
        txb1->setText(QCoreApplication::translate("MainWindow", "Tx &1", nullptr));
#if QT_CONFIG(shortcut)
        txb1->setShortcut(QCoreApplication::translate("MainWindow", "Alt+1", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        txb6->setToolTip(QCoreApplication::translate("MainWindow", "Switch to this Tx message NOW", nullptr));
#endif // QT_CONFIG(tooltip)
        txb6->setText(QCoreApplication::translate("MainWindow", "Tx &6", nullptr));
#if QT_CONFIG(shortcut)
        txb6->setShortcut(QCoreApplication::translate("MainWindow", "Alt+6", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        txrb3->setToolTip(QCoreApplication::translate("MainWindow", "Send this message in next Tx interval", nullptr));
#endif // QT_CONFIG(tooltip)
        txrb3->setText(QString());
#if QT_CONFIG(shortcut)
        txrb3->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+3", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        tx5->setToolTip(QCoreApplication::translate("MainWindow", "Enter a free text message (maximum 13 characters)\n"
"or select a predefined macro from the dropdown list.\n"
"Press ENTER to add the current text to the predefined\n"
"list. The list can be maintained in Settings (F2).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        txrb5->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Send this message in next Tx interval</p><p>Double-click to reset to the standard 73 message</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        txrb5->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Send this message in next Tx interval\n"
"Double-click to reset to the standard 73 message", nullptr));
#endif // QT_CONFIG(accessibility)
        txrb5->setText(QString());
#if QT_CONFIG(shortcut)
        txrb5->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+5", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "1", nullptr));
#if QT_CONFIG(tooltip)
        cbSendMsg->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Transmit free text message at the next opportunity.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbSendMsg->setText(QCoreApplication::translate("MainWindow", "Send msg", nullptr));
#if QT_CONFIG(tooltip)
        pbFreeText->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Enter a free text message.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbFreeText->setText(QCoreApplication::translate("MainWindow", "Free Text", nullptr));
        comboBoxCQ->setItemText(0, QCoreApplication::translate("MainWindow", "CQ", nullptr));
        comboBoxCQ->setItemText(1, QCoreApplication::translate("MainWindow", "CQ AF", nullptr));
        comboBoxCQ->setItemText(2, QCoreApplication::translate("MainWindow", "CQ AN", nullptr));
        comboBoxCQ->setItemText(3, QCoreApplication::translate("MainWindow", "CQ AS", nullptr));
        comboBoxCQ->setItemText(4, QCoreApplication::translate("MainWindow", "CQ EU", nullptr));
        comboBoxCQ->setItemText(5, QCoreApplication::translate("MainWindow", "CQ NA", nullptr));
        comboBoxCQ->setItemText(6, QCoreApplication::translate("MainWindow", "CQ OC", nullptr));
        comboBoxCQ->setItemText(7, QCoreApplication::translate("MainWindow", "CQ SA", nullptr));
        comboBoxCQ->setItemText(8, QCoreApplication::translate("MainWindow", "CQ 0", nullptr));
        comboBoxCQ->setItemText(9, QCoreApplication::translate("MainWindow", "CQ 1", nullptr));
        comboBoxCQ->setItemText(10, QCoreApplication::translate("MainWindow", "CQ 2", nullptr));
        comboBoxCQ->setItemText(11, QCoreApplication::translate("MainWindow", "CQ 3", nullptr));
        comboBoxCQ->setItemText(12, QCoreApplication::translate("MainWindow", "CQ 4", nullptr));
        comboBoxCQ->setItemText(13, QCoreApplication::translate("MainWindow", "CQ 5", nullptr));
        comboBoxCQ->setItemText(14, QCoreApplication::translate("MainWindow", "CQ 6", nullptr));
        comboBoxCQ->setItemText(15, QCoreApplication::translate("MainWindow", "CQ 7", nullptr));
        comboBoxCQ->setItemText(16, QCoreApplication::translate("MainWindow", "CQ 8", nullptr));
        comboBoxCQ->setItemText(17, QCoreApplication::translate("MainWindow", "CQ 9", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxCQ->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Select a specific CQ message.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBoxCQ->setCurrentText(QCoreApplication::translate("MainWindow", "CQ", nullptr));
        label_queue->setText(QCoreApplication::translate("MainWindow", "Queue", nullptr));
        cbWorkDupes->setText(QCoreApplication::translate("MainWindow", "Allow Dupes", nullptr));
#if QT_CONFIG(tooltip)
        pbFoxReset->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Clear all queues.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbFoxReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
#if QT_CONFIG(tooltip)
        sbNlist->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Maximum number of callsigns to be displayed in the queue.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbNlist->setPrefix(QCoreApplication::translate("MainWindow", "N List     ", nullptr));
        comboBoxHoundSort->setItemText(0, QCoreApplication::translate("MainWindow", "Random", nullptr));
        comboBoxHoundSort->setItemText(1, QCoreApplication::translate("MainWindow", "Call", nullptr));
        comboBoxHoundSort->setItemText(2, QCoreApplication::translate("MainWindow", "Grid", nullptr));
        comboBoxHoundSort->setItemText(3, QCoreApplication::translate("MainWindow", "S/N (dB)", nullptr));
        comboBoxHoundSort->setItemText(4, QCoreApplication::translate("MainWindow", "Distance", nullptr));
        comboBoxHoundSort->setItemText(5, QCoreApplication::translate("MainWindow", "Age", nullptr));
        comboBoxHoundSort->setItemText(6, QCoreApplication::translate("MainWindow", "Continent", nullptr));
        comboBoxHoundSort->setItemText(7, QCoreApplication::translate("MainWindow", "Score", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxHoundSort->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Select a desired sort order for callsigns in the queue.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBoxHoundSort->setCurrentText(QCoreApplication::translate("MainWindow", "Random", nullptr));
#if QT_CONFIG(tooltip)
        cbMoreCQs->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Include a CQ message along with other messages.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbMoreCQs->setText(QCoreApplication::translate("MainWindow", "More CQs", nullptr));
        label_inProcess->setText(QCoreApplication::translate("MainWindow", "In Progress", nullptr));
#if QT_CONFIG(tooltip)
        sbNslots->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Maximum number of concurrent streams for Fox transmissions.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbNslots->setSuffix(QString());
        sbNslots->setPrefix(QCoreApplication::translate("MainWindow", "N Slots    ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "2", nullptr));
#if QT_CONFIG(tooltip)
        cb70cm->setToolTip(QCoreApplication::translate("MainWindow", "70cm FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb70cm->setText(QCoreApplication::translate("MainWindow", "70cm", nullptr));
#if QT_CONFIG(tooltip)
        cb30m->setToolTip(QCoreApplication::translate("MainWindow", "30m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb30m->setText(QCoreApplication::translate("MainWindow", "30m", nullptr));
#if QT_CONFIG(tooltip)
        pbBandHopping->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Toggle band hopping On/Off. Band hopping occurs every other full minute. Changes to the checkboxes take effect immediately.<br/>Right-click to switch to the next selected band hopping frequency, or to test the default audio device, when band hopping is disabled.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbBandHopping->setText(QCoreApplication::translate("MainWindow", "  Band Hopping  ", nullptr));
#if QT_CONFIG(tooltip)
        cb12m->setToolTip(QCoreApplication::translate("MainWindow", "12m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb12m->setText(QCoreApplication::translate("MainWindow", "12m", nullptr));
#if QT_CONFIG(tooltip)
        cb40m->setToolTip(QCoreApplication::translate("MainWindow", "40m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb40m->setText(QCoreApplication::translate("MainWindow", "40m", nullptr));
#if QT_CONFIG(tooltip)
        cb2mMSK->setToolTip(QCoreApplication::translate("MainWindow", "2m MSK144", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        cb2mMSK->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        cb2mMSK->setText(QCoreApplication::translate("MainWindow", "2m MSK", nullptr));
#if QT_CONFIG(tooltip)
        cb10m->setToolTip(QCoreApplication::translate("MainWindow", "10m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb10m->setText(QCoreApplication::translate("MainWindow", "10m", nullptr));
#if QT_CONFIG(tooltip)
        cb6m->setToolTip(QCoreApplication::translate("MainWindow", "6m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb6m->setText(QCoreApplication::translate("MainWindow", "6m", nullptr));
#if QT_CONFIG(tooltip)
        cb60m->setToolTip(QCoreApplication::translate("MainWindow", "60m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb60m->setText(QCoreApplication::translate("MainWindow", "60m", nullptr));
#if QT_CONFIG(tooltip)
        cb160m->setToolTip(QCoreApplication::translate("MainWindow", "160m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb160m->setText(QCoreApplication::translate("MainWindow", "160m", nullptr));
#if QT_CONFIG(tooltip)
        cb80m->setToolTip(QCoreApplication::translate("MainWindow", "80m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb80m->setText(QCoreApplication::translate("MainWindow", "80m", nullptr));
#if QT_CONFIG(tooltip)
        cb20m->setToolTip(QCoreApplication::translate("MainWindow", "20m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb20m->setText(QCoreApplication::translate("MainWindow", "20m", nullptr));
#if QT_CONFIG(tooltip)
        cb17m->setToolTip(QCoreApplication::translate("MainWindow", "17m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb17m->setText(QCoreApplication::translate("MainWindow", "17m", nullptr));
#if QT_CONFIG(tooltip)
        cb4m->setToolTip(QCoreApplication::translate("MainWindow", "4m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb4m->setText(QCoreApplication::translate("MainWindow", "4m", nullptr));
#if QT_CONFIG(tooltip)
        cb15m->setToolTip(QCoreApplication::translate("MainWindow", "15m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb15m->setText(QCoreApplication::translate("MainWindow", "15m", nullptr));
#if QT_CONFIG(tooltip)
        cb2m->setToolTip(QCoreApplication::translate("MainWindow", "2m FT8", nullptr));
#endif // QT_CONFIG(tooltip)
        cb2m->setText(QCoreApplication::translate("MainWindow", "2m", nullptr));
#if QT_CONFIG(tooltip)
        cb10mFT4->setToolTip(QCoreApplication::translate("MainWindow", "10m FT4", nullptr));
#endif // QT_CONFIG(tooltip)
        cb10mFT4->setText(QCoreApplication::translate("MainWindow", "10m FT4", nullptr));
#if QT_CONFIG(tooltip)
        cb12mFT4->setToolTip(QCoreApplication::translate("MainWindow", "12m FT4", nullptr));
#endif // QT_CONFIG(tooltip)
        cb12mFT4->setText(QCoreApplication::translate("MainWindow", "12m FT4", nullptr));
#if QT_CONFIG(tooltip)
        cb15mFT4->setToolTip(QCoreApplication::translate("MainWindow", "15m FT4", nullptr));
#endif // QT_CONFIG(tooltip)
        cb15mFT4->setText(QCoreApplication::translate("MainWindow", "15m FT4", nullptr));
#if QT_CONFIG(tooltip)
        cb17mFT4->setToolTip(QCoreApplication::translate("MainWindow", "17m FT4", nullptr));
#endif // QT_CONFIG(tooltip)
        cb17mFT4->setText(QCoreApplication::translate("MainWindow", "17m FT4", nullptr));
#if QT_CONFIG(tooltip)
        cb20mFT4->setToolTip(QCoreApplication::translate("MainWindow", "20m FT4", nullptr));
#endif // QT_CONFIG(tooltip)
        cb20mFT4->setText(QCoreApplication::translate("MainWindow", "20m FT4", nullptr));
#if QT_CONFIG(tooltip)
        cb30mFT4->setToolTip(QCoreApplication::translate("MainWindow", "30m FT4", nullptr));
#endif // QT_CONFIG(tooltip)
        cb30mFT4->setText(QCoreApplication::translate("MainWindow", "30m FT4", nullptr));
#if QT_CONFIG(tooltip)
        cb40mFT4->setToolTip(QCoreApplication::translate("MainWindow", "40m FT4", nullptr));
#endif // QT_CONFIG(tooltip)
        cb40mFT4->setText(QCoreApplication::translate("MainWindow", "40m FT4", nullptr));
#if QT_CONFIG(tooltip)
        cb80mFT4->setToolTip(QCoreApplication::translate("MainWindow", "80m FT4", nullptr));
#endif // QT_CONFIG(tooltip)
        cb80mFT4->setText(QCoreApplication::translate("MainWindow", "80m FT4", nullptr));
#if QT_CONFIG(tooltip)
        cbQRG6->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Right-click to toggle between FT8 and FT2 mode for QRG6.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbQRG6->setText(QString());
#if QT_CONFIG(tooltip)
        cbQRG1->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Right-click to toggle between FT8 and FT2 mode for QRG1.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbQRG1->setText(QString());
#if QT_CONFIG(tooltip)
        cbQRG2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Right-click to toggle between FT8 and FT2 mode for QRG2.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbQRG2->setText(QString());
#if QT_CONFIG(tooltip)
        cbQRG7->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Right-click to toggle between FT8 and FT2 mode for QRG7.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbQRG7->setText(QString());
#if QT_CONFIG(tooltip)
        sbQRG8->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>FT8 or FT2 QRG8 in kHz.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbQRG5->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Right-click to toggle between FT8 and FT2 mode for QRG5.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbQRG5->setText(QString());
#if QT_CONFIG(tooltip)
        cbQRG3->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Right-click to toggle between FT8 and FT2 mode for QRG3.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbQRG3->setText(QString());
#if QT_CONFIG(tooltip)
        cbQRG4->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Right-click to toggle between FT8 and FT2 mode for QRG4.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbQRG4->setText(QString());
#if QT_CONFIG(tooltip)
        cbQRG8->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Right-click to toggle between FT8 and FT2 mode for QRG8.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbQRG8->setText(QString());
#if QT_CONFIG(tooltip)
        sbQRG7->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>FT8 or FT2 QRG7 in kHz.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbQRG6->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>FT8 or FT2 QRG6 in kHz.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbQRG5->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>FT8 or FT2 QRG5 in kHz.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbQRG4->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>FT8 or FT2 QRG4 in kHz.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbQRG3->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>FT8 or FT2 QRG3 in kHz.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbQRG2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>FT8 or FT2 QRG2 in kHz.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbQRG1->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>FT8 or FT2 QRG1 in kHz.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "3", nullptr));
#if QT_CONFIG(tooltip)
        cbLowerCase->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check to display received messages in lower case.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbLowerCase->setText(QCoreApplication::translate("MainWindow", "Lower case", nullptr));
#if QT_CONFIG(tooltip)
        cbIncludeTime->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Show the UTC start time of each decoded message.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbIncludeTime->setText(QCoreApplication::translate("MainWindow", "Include Time", nullptr));
        label_jttyStyle->setText(QCoreApplication::translate("MainWindow", "Message style", nullptr));
        comboBoxJttyStyle->setItemText(0, QCoreApplication::translate("MainWindow", "Contest", nullptr));
        comboBoxJttyStyle->setItemText(1, QCoreApplication::translate("MainWindow", "FT8", nullptr));
        comboBoxJttyStyle->setItemText(2, QCoreApplication::translate("MainWindow", "Custom", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxJttyStyle->setToolTip(QCoreApplication::translate("MainWindow", "F1-F8 message set: Contest (exchange-oriented), FT8 (chat-QSO-oriented, with a %R report) or Custom (your own eight, started from the Contest set). Each set keeps its own edits.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pbF5->setToolTip(QCoreApplication::translate("MainWindow", "HisCall", nullptr));
#endif // QT_CONFIG(tooltip)
        pbF5->setText(QCoreApplication::translate("MainWindow", "F5", nullptr));
#if QT_CONFIG(tooltip)
        msg1->setToolTip(QCoreApplication::translate("MainWindow", "Macro for F1: %M my call, %H his call, %N serial number, %E exchange, %G grid, %R report", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        msg2->setToolTip(QCoreApplication::translate("MainWindow", "Macro for F2: %M my call, %H his call, %N serial number, %E exchange, %G grid, %R report", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pbF2->setToolTip(QCoreApplication::translate("MainWindow", "HisCall Exchange", nullptr));
#endif // QT_CONFIG(tooltip)
        pbF2->setText(QCoreApplication::translate("MainWindow", "F2", nullptr));
#if QT_CONFIG(tooltip)
        msg4->setToolTip(QCoreApplication::translate("MainWindow", "Macro for F4: %M my call, %H his call, %N serial number, %E exchange, %G grid, %R report", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pbF1->setToolTip(QCoreApplication::translate("MainWindow", "CQ", nullptr));
#endif // QT_CONFIG(tooltip)
        pbF1->setText(QCoreApplication::translate("MainWindow", "F1", nullptr));
#if QT_CONFIG(tooltip)
        pbF7->setToolTip(QCoreApplication::translate("MainWindow", "HisCall AGN ?", nullptr));
#endif // QT_CONFIG(tooltip)
        pbF7->setText(QCoreApplication::translate("MainWindow", "F7", nullptr));
#if QT_CONFIG(tooltip)
        pbF3->setToolTip(QCoreApplication::translate("MainWindow", "TU CQ", nullptr));
#endif // QT_CONFIG(tooltip)
        pbF3->setText(QCoreApplication::translate("MainWindow", "F3", nullptr));
#if QT_CONFIG(tooltip)
        pbF6->setToolTip(QCoreApplication::translate("MainWindow", "Now QueuedCall Exchange", nullptr));
#endif // QT_CONFIG(tooltip)
        pbF6->setText(QCoreApplication::translate("MainWindow", "F6", nullptr));
#if QT_CONFIG(tooltip)
        msg3->setToolTip(QCoreApplication::translate("MainWindow", "Macro for F3: %M my call, %H his call, %N serial number, %E exchange, %G grid, %R report", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pbF8->setToolTip(QCoreApplication::translate("MainWindow", "Exchange", nullptr));
#endif // QT_CONFIG(tooltip)
        pbF8->setText(QCoreApplication::translate("MainWindow", "F8", nullptr));
#if QT_CONFIG(tooltip)
        pbF4->setToolTip(QCoreApplication::translate("MainWindow", "MyCall", nullptr));
#endif // QT_CONFIG(tooltip)
        pbF4->setText(QCoreApplication::translate("MainWindow", "F4", nullptr));
#if QT_CONFIG(tooltip)
        msg5->setToolTip(QCoreApplication::translate("MainWindow", "Macro for F5: %M my call, %H his call, %N serial number, %E exchange, %G grid, %R report", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        msg6->setToolTip(QCoreApplication::translate("MainWindow", "Macro for F6: %M my call, %H his call, %N serial number, %E exchange, %G grid, %R report", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        msg7->setToolTip(QCoreApplication::translate("MainWindow", "Macro for F7: %M my call, %H his call, %N serial number, %E exchange, %G grid, %R report", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        msg8->setToolTip(QCoreApplication::translate("MainWindow", "Macro for F8: %M my call, %H his call, %N serial number, %E exchange, %G grid, %R report", nullptr));
#endif // QT_CONFIG(tooltip)
        pbSendMessage->setText(QCoreApplication::translate("MainWindow", "Send Message", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Serial Number", nullptr));
        Tx_Message->setText(QString());
#if QT_CONFIG(tooltip)
        sbSerialNumber_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Serial number of QSO for contest exchange.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_jttyCallNext->setText(QCoreApplication::translate("MainWindow", "Call Next", nullptr));
#if QT_CONFIG(tooltip)
        TxFreqSpinBox_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Audio Tx frequency</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        TxFreqSpinBox_2->setSuffix(QCoreApplication::translate("MainWindow", "  Hz", nullptr));
        TxFreqSpinBox_2->setPrefix(QCoreApplication::translate("MainWindow", "Tx  ", nullptr));
#if QT_CONFIG(tooltip)
        pbR2T_2->setToolTip(QCoreApplication::translate("MainWindow", "Set Tx frequency to Rx Frequency", nullptr));
#endif // QT_CONFIG(tooltip)
        pbR2T_2->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
#if QT_CONFIG(tooltip)
        sbFtol_2->setToolTip(QCoreApplication::translate("MainWindow", "Frequency tolerance (Hz)", nullptr));
#endif // QT_CONFIG(tooltip)
        sbFtol_2->setPrefix(QCoreApplication::translate("MainWindow", "F Tol  ", nullptr));
#if QT_CONFIG(tooltip)
        pbT2R_2->setToolTip(QCoreApplication::translate("MainWindow", "Set Rx frequency to Tx Frequency", nullptr));
#endif // QT_CONFIG(tooltip)
        pbT2R_2->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
#if QT_CONFIG(tooltip)
        RxFreqSpinBox_2->setToolTip(QCoreApplication::translate("MainWindow", "Audio Rx frequency", nullptr));
#endif // QT_CONFIG(tooltip)
        RxFreqSpinBox_2->setSuffix(QCoreApplication::translate("MainWindow", "  Hz", nullptr));
        RxFreqSpinBox_2->setPrefix(QCoreApplication::translate("MainWindow", "Rx  ", nullptr));
        WSPRfreqSpinBox->setSuffix(QCoreApplication::translate("MainWindow", "  Hz", nullptr));
        WSPRfreqSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "Tx  ", nullptr));
        sbFST4W_RxFreq->setSuffix(QCoreApplication::translate("MainWindow", "  Hz", nullptr));
        sbFST4W_RxFreq->setPrefix(QCoreApplication::translate("MainWindow", "Rx  ", nullptr));
        sbFST4W_FTol->setSuffix(QCoreApplication::translate("MainWindow", "  Hz", nullptr));
        sbFST4W_FTol->setPrefix(QCoreApplication::translate("MainWindow", "F Tol  ", nullptr));
        RoundRobin->setItemText(0, QCoreApplication::translate("MainWindow", "Random", nullptr));
        RoundRobin->setItemText(1, QCoreApplication::translate("MainWindow", "1/2", nullptr));
        RoundRobin->setItemText(2, QCoreApplication::translate("MainWindow", "2/2", nullptr));
        RoundRobin->setItemText(3, QCoreApplication::translate("MainWindow", "1/3", nullptr));
        RoundRobin->setItemText(4, QCoreApplication::translate("MainWindow", "2/3", nullptr));
        RoundRobin->setItemText(5, QCoreApplication::translate("MainWindow", "3/3", nullptr));
        RoundRobin->setItemText(6, QCoreApplication::translate("MainWindow", "1/4", nullptr));
        RoundRobin->setItemText(7, QCoreApplication::translate("MainWindow", "2/4", nullptr));
        RoundRobin->setItemText(8, QCoreApplication::translate("MainWindow", "3/4", nullptr));
        RoundRobin->setItemText(9, QCoreApplication::translate("MainWindow", "4/4", nullptr));
        RoundRobin->setItemText(10, QCoreApplication::translate("MainWindow", "1/5", nullptr));
        RoundRobin->setItemText(11, QCoreApplication::translate("MainWindow", "2/5", nullptr));
        RoundRobin->setItemText(12, QCoreApplication::translate("MainWindow", "3/5", nullptr));
        RoundRobin->setItemText(13, QCoreApplication::translate("MainWindow", "4/5", nullptr));
        RoundRobin->setItemText(14, QCoreApplication::translate("MainWindow", "5/5", nullptr));
        RoundRobin->setItemText(15, QCoreApplication::translate("MainWindow", "1/6", nullptr));
        RoundRobin->setItemText(16, QCoreApplication::translate("MainWindow", "2/6", nullptr));
        RoundRobin->setItemText(17, QCoreApplication::translate("MainWindow", "3/6", nullptr));
        RoundRobin->setItemText(18, QCoreApplication::translate("MainWindow", "4/6", nullptr));
        RoundRobin->setItemText(19, QCoreApplication::translate("MainWindow", "5/6", nullptr));
        RoundRobin->setItemText(20, QCoreApplication::translate("MainWindow", "6/6", nullptr));

#if QT_CONFIG(tooltip)
        sbTxPercent->setToolTip(QCoreApplication::translate("MainWindow", "Percentage of minute sequences devoted to transmitting.", nullptr));
#endif // QT_CONFIG(tooltip)
        sbTxPercent->setSuffix(QCoreApplication::translate("MainWindow", "  %", nullptr));
        sbTxPercent->setPrefix(QCoreApplication::translate("MainWindow", "Tx Pct ", nullptr));
        sbTR_FST4W->setSuffix(QCoreApplication::translate("MainWindow", "  s", nullptr));
        sbTR_FST4W->setPrefix(QCoreApplication::translate("MainWindow", "T/R  ", nullptr));
        band_hopping_group_box->setTitle(QCoreApplication::translate("MainWindow", "Band Hopping", nullptr));
#if QT_CONFIG(tooltip)
        band_hopping_schedule_push_button->setToolTip(QCoreApplication::translate("MainWindow", "Choose bands and times of day for band-hopping.", nullptr));
#endif // QT_CONFIG(tooltip)
        band_hopping_schedule_push_button->setText(QCoreApplication::translate("MainWindow", "Schedule ...", nullptr));
#if QT_CONFIG(tooltip)
        cbUploadWSPR_Spots->setToolTip(QCoreApplication::translate("MainWindow", "Upload decoded messages to WSPRnet.org.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbUploadWSPR_Spots->setText(QCoreApplication::translate("MainWindow", "Upload spots", nullptr));
#if QT_CONFIG(tooltip)
        WSPR_prefer_type_1_check_box->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>6 digit locators cause 2 different messages to be sent, the second contains the full locator but only a hashed callsign, other stations must have decoded the first once before they can decode your call in the second. Check this option to only send 4 digit locators if it will avoid the two message protocol.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        WSPR_prefer_type_1_check_box->setAccessibleDescription(QCoreApplication::translate("MainWindow", "6 digit locators cause 2 different messages to be sent, the second contains the full locator but only a hashed callsign, other stations must have decoded the first once before they can decode your call in the second. Check this option to only send 4 digit locators if it will avoid the two message protocol.", nullptr));
#endif // QT_CONFIG(accessibility)
        WSPR_prefer_type_1_check_box->setText(QCoreApplication::translate("MainWindow", "Prefer Type 1 messages", nullptr));
        cbNoOwnCall->setText(QCoreApplication::translate("MainWindow", "No own call decodes", nullptr));
#if QT_CONFIG(tooltip)
        pbTxNext->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Transmit during the next sequence.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbTxNext->setText(QCoreApplication::translate("MainWindow", "Tx Next", nullptr));
#if QT_CONFIG(tooltip)
        TxPowerComboBox->setToolTip(QCoreApplication::translate("MainWindow", "Set Tx power in dBm (dB above 1 mW) as part of your WSPR message.", nullptr));
#endif // QT_CONFIG(tooltip)
        rbEchoMessage->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
        sbToneSpacing->setSuffix(QCoreApplication::translate("MainWindow", "  Hz", nullptr));
        sbToneSpacing->setPrefix(QCoreApplication::translate("MainWindow", "Spacing  ", nullptr));
        rbFixedTone->setText(QCoreApplication::translate("MainWindow", "Fixed Tone", nullptr));
        leEchoMessage->setText(QCoreApplication::translate("MainWindow", "K1JT", nullptr));
        rbEchoCW->setText(QCoreApplication::translate("MainWindow", "CW", nullptr));
#if QT_CONFIG(tooltip)
        labDialFreq->setToolTip(QCoreApplication::translate("MainWindow", "USB dial frequency", nullptr));
#endif // QT_CONFIG(tooltip)
        labDialFreq->setText(QCoreApplication::translate("MainWindow", "14.078 000", nullptr));
        labUTC->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"> 2015 Jun 17 </p><p align=\"center\"> 01:23:45 </p></body></html>", nullptr));
        sbNB->setSuffix(QCoreApplication::translate("MainWindow", "  %", nullptr));
        sbNB->setPrefix(QCoreApplication::translate("MainWindow", "NB  ", nullptr));
#if QT_CONFIG(tooltip)
        signal_meter_widget->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>30dB recommended when only noise present<br/>Green when good<br/>Red when clipping may occur<br/>Yellow when too low</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        signal_meter_widget->setAccessibleName(QCoreApplication::translate("MainWindow", "Rx Signal", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        signal_meter_widget->setAccessibleDescription(QCoreApplication::translate("MainWindow", "30dB recommended when only noise present\n"
"Green when good\n"
"Red when clipping may occur\n"
"Yellow when too low", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(tooltip)
        houndButton->setToolTip(QCoreApplication::translate("MainWindow", "Toggle FT8 hound mode On/Off.<br>Right-click to activate or deactivate SuperFox mode.", nullptr));
#endif // QT_CONFIG(tooltip)
        houndButton->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
#if QT_CONFIG(tooltip)
        ft8Button->setToolTip(QCoreApplication::translate("MainWindow", "Switch to FT8 mode.<br>Right-click to toggle last used contest mode On/Off.", nullptr));
#endif // QT_CONFIG(tooltip)
        ft8Button->setText(QCoreApplication::translate("MainWindow", "FT8", nullptr));
#if QT_CONFIG(tooltip)
        ft4Button->setToolTip(QCoreApplication::translate("MainWindow", "Switch to FT4 mode", nullptr));
#endif // QT_CONFIG(tooltip)
        ft4Button->setText(QCoreApplication::translate("MainWindow", "FT4", nullptr));
        ft2Button->setText(QCoreApplication::translate("MainWindow", "FT2", nullptr));
#if QT_CONFIG(tooltip)
        msk144Button->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to MSK144 mode. Right-click to switch to FSK441 mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        msk144Button->setText(QCoreApplication::translate("MainWindow", "MSK", nullptr));
#if QT_CONFIG(tooltip)
        q65Button->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to Q65 mode.<br> Right-click to switch to Q65 Pileup mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        q65Button->setText(QCoreApplication::translate("MainWindow", "Q65", nullptr));
#if QT_CONFIG(tooltip)
        jt65Button->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to JT65 mode. <br>Right-click to switch to JT9 mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        jt65Button->setText(QCoreApplication::translate("MainWindow", "JT65", nullptr));
#if QT_CONFIG(tooltip)
        echoButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to Echo mode</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        echoButton->setText(QCoreApplication::translate("MainWindow", "Echo", nullptr));
#if QT_CONFIG(tooltip)
        bandComboBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Select operating band or enter frequency in MHz or enter kHz increment followed by k.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        bandComboBox->setAccessibleName(QCoreApplication::translate("MainWindow", "Frequency entry", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        bandComboBox->setAccessibleDescription(QCoreApplication::translate("MainWindow", "Select operating band or enter frequency in MHz or enter kHz increment followed by k.", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(tooltip)
        readFreq->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>If orange or red there has been a rig control failure, click to reset and read the dial frequency.  S implies split mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        readFreq->setAccessibleDescription(QCoreApplication::translate("MainWindow", "If orange or red there has been a rig control failure, click to reset and read the dial frequency. S implies split mode.", nullptr));
#endif // QT_CONFIG(accessibility)
        readFreq->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuCallsign_overlay->setTitle(QCoreApplication::translate("MainWindow", "Callsigns on waterfall", nullptr));
        menuCallsign_font->setTitle(QCoreApplication::translate("MainWindow", "Font size", nullptr));
        menuCallsign_transparency->setTitle(QCoreApplication::translate("MainWindow", "Transparency", nullptr));
        menuCallsign_position->setTitle(QCoreApplication::translate("MainWindow", "Position", nullptr));
        menuFilters->setTitle(QCoreApplication::translate("MainWindow", "Filters", nullptr));
        menuDecode->setTitle(QCoreApplication::translate("MainWindow", "Decode", nullptr));
        menuParameters->setTitle(QCoreApplication::translate("MainWindow", "Parameters", nullptr));
        menuDecoder_sensitivity->setTitle(QCoreApplication::translate("MainWindow", "Decoder sensitivity", nullptr));
        menuDecoder_start->setTitle(QCoreApplication::translate("MainWindow", "Decoder start", nullptr));
        menuFT8_threads->setTitle(QCoreApplication::translate("MainWindow", "Number of threads", nullptr));
        menuQSO_RX_freq_sensitivity->setTitle(QCoreApplication::translate("MainWindow", "QSO RX freq sensitivity", nullptr));
        menuDecoding_cycles->setTitle(QCoreApplication::translate("MainWindow", "Decoding cycles", nullptr));
        menuQMAP_source->setTitle(QCoreApplication::translate("MainWindow", "WS-MAP/EME65 source", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuMode->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        menuConfig->setTitle(QCoreApplication::translate("MainWindow", "Configurations", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
