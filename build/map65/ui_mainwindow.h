/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "displaytext.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSync_WSJTX;
    QAction *actionTx_via_WSJTX;
    QAction *actionContinuous_waterfall;
    QAction *actionInstance_ID_1;
    QAction *actionInstance_ID_2;
    QAction *actionInstance_ID_3;
    QAction *actionInstance_ID_4;
    QAction *actionAdd_Call_to_SH;
    QAction *actionExit;
    QAction *actionDeviceSetup;
    QAction *actionAbout;
    QAction *actionAstro_Data;
    QAction *actionBand_Map;
    QAction *actionMessages;
    QAction *actionWide_Waterfall;
    QAction *actionPast_periods_on_Wide_Graph;
    QAction *actionKeep_last_period;
    QAction *actionShow_callsigns_on_Waterfall;
    QAction *actionEnable_Click_to_Work;
    QAction *actionTransparency_None;
    QAction *actionTransparency_Low;
    QAction *actionTransparency_Medium;
    QAction *actionTransparency_High;
    QAction *actionCallsign_font_small;
    QAction *actionCallsign_font_normal;
    QAction *actionCallsign_font_medium;
    QAction *actionCallsign_font_large;
    QAction *actionCallsign_position_top;
    QAction *actionCallsign_position_bottom;
    QAction *actionOpen;
    QAction *actionOpen_next_in_directory;
    QAction *actionDecode_remaining_files_in_directory;
    QAction *actionDelete_all_tf2_files_in_SaveDir;
    QAction *actionErase_Band_Map_and_Messages;
    QAction *actionErase_map65_rx_log;
    QAction *actionLinrad;
    QAction *actionCuteSDR;
    QAction *actionFind_Delta_Phi;
    QAction *actionF4_sets_Tx6;
    QAction *actionOnly_EME_calls;
    QAction *actionNo_shorthands_if_Tx1;
    QAction *actionNo_Deep_Search;
    QAction *actionNormal_Deep_Search;
    QAction *actionAggressive_Deep_Search;
    QAction *actionQ65_Fast;
    QAction *actionQ65_Normal;
    QAction *actionQ65_Deep;
    QAction *actionNone;
    QAction *actionSave_all;
    QAction *action50;
    QAction *action144;
    QAction *action222;
    QAction *action432;
    QAction *action1296;
    QAction *action2304;
    QAction *actionOnline_Users_Guide;
    QAction *actionKeyboard_shortcuts;
    QAction *actionSpecial_mouse_commands;
    QAction *actionAvailable_suffixes_and_add_on_prefixes;
    QAction *actionErase_map65_tx_log;
    QAction *actionJT65A;
    QAction *actionJT65B;
    QAction *actionJT65C;
    QAction *actionI_Q_Calibration;
    QAction *actionAdjust_IQ_Calibration;
    QAction *actionApply_IQ_Calibration;
    QAction *actionAFMHot;
    QAction *actionBlue;
    QAction *actionFUNcube_Dongle;
    QAction *actionEdit_wsjt_log;
    QAction *actionTx_Tune;
    QAction *actionDecode_Q65_near_QSO_frequency;
    QAction *actionQ65A;
    QAction *actionQ65B;
    QAction *actionNoJT65;
    QAction *actionNoQ65;
    QAction *actionQ65C;
    QAction *actionQ65D;
    QAction *actionQ65E;
    QAction *actionQSG_Q65;
    QAction *actionQSG_MAP65_v3;
    QAction *actionQ65_Sensitivity_in_MAP65_3_0;
    QAction *actionRelease_Notes;
    QAction *actionOpen_MAP65_data_directory;
    QAction *actionReduce_false_decodes;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_9;
    DisplayText *decodedTextBrowser;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *logQSOButton;
    QPushButton *stopButton;
    QPushButton *monitorButton;
    QPushButton *DecodeButton;
    QPushButton *EraseButton;
    QPushButton *autoButton;
    QPushButton *stopTxButton;
    QHBoxLayout *horizontalLayout_5;
    QFrame *xMeterFrame;
    QFrame *yMeterFrame;
    QVBoxLayout *verticalLayout;
    QGroupBox *dxStationGroupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *dxCallEntry;
    QLineEdit *dxGridEntry;
    QGridLayout *gridLayout_2;
    QPushButton *lookupButton;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *genStdMsgsPushButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *DX_Grid_label;
    QLabel *DX_Call_label;
    QSpacerItem *verticalSpacer_2;
    QLabel *labUTC;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *txFirstCheckBox;
    QPushButton *pbTxMode;
    QPushButton *setTxFreqButton;
    QSpinBox *sbMaxDrift;
    QSpacerItem *verticalSpacer;
    QCheckBox *NBcheckBox;
    QSlider *NBslider;
    QHBoxLayout *horizontalLayout;
    QLabel *labTol1;
    QSpinBox *tolSpinBox;
    QLabel *labTol2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *tx1;
    QLineEdit *tx2;
    QLineEdit *tx3;
    QLineEdit *tx4;
    QLineEdit *tx5;
    QLineEdit *tx6;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *txrb1;
    QRadioButton *txrb2;
    QRadioButton *txrb3;
    QRadioButton *txrb4;
    QRadioButton *txrb5;
    QRadioButton *txrb6;
    QVBoxLayout *verticalLayout_4;
    QPushButton *txb1;
    QPushButton *txb2;
    QPushButton *txb3;
    QPushButton *txb4;
    QPushButton *txb5;
    QPushButton *txb6;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSetup;
    QMenu *menuView;
    QMenu *menuWaterfall_palette;
    QMenu *menuCallsign_transparency;
    QMenu *menuCallsign_font;
    QMenu *menuCallsign_position;
    QMenu *menuDecode;
    QMenu *menuSave;
    QMenu *menuHelp;
    QMenu *menuMode;
    QMenu *menuWSJT_X;
    QMenu *menuInstance_ID;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(635, 0));
        MainWindow->setMaximumSize(QSize(2048, 2048));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionSync_WSJTX = new QAction(MainWindow);
        actionSync_WSJTX->setObjectName(QString::fromUtf8("actionSync_WSJTX"));
        actionSync_WSJTX->setCheckable(true);
        actionTx_via_WSJTX = new QAction(MainWindow);
        actionTx_via_WSJTX->setObjectName(QString::fromUtf8("actionTx_via_WSJTX"));
        actionTx_via_WSJTX->setCheckable(true);
        actionContinuous_waterfall = new QAction(MainWindow);
        actionContinuous_waterfall->setObjectName(QString::fromUtf8("actionContinuous_waterfall"));
        actionContinuous_waterfall->setCheckable(true);
        actionInstance_ID_1 = new QAction(MainWindow);
        actionInstance_ID_1->setObjectName(QString::fromUtf8("actionInstance_ID_1"));
        actionInstance_ID_1->setCheckable(true);
        actionInstance_ID_2 = new QAction(MainWindow);
        actionInstance_ID_2->setObjectName(QString::fromUtf8("actionInstance_ID_2"));
        actionInstance_ID_2->setCheckable(true);
        actionInstance_ID_3 = new QAction(MainWindow);
        actionInstance_ID_3->setObjectName(QString::fromUtf8("actionInstance_ID_3"));
        actionInstance_ID_3->setCheckable(true);
        actionInstance_ID_4 = new QAction(MainWindow);
        actionInstance_ID_4->setObjectName(QString::fromUtf8("actionInstance_ID_4"));
        actionInstance_ID_4->setCheckable(true);
        actionAdd_Call_to_SH = new QAction(MainWindow);
        actionAdd_Call_to_SH->setObjectName(QString::fromUtf8("actionAdd_Call_to_SH"));
        actionAdd_Call_to_SH->setCheckable(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionDeviceSetup = new QAction(MainWindow);
        actionDeviceSetup->setObjectName(QString::fromUtf8("actionDeviceSetup"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAstro_Data = new QAction(MainWindow);
        actionAstro_Data->setObjectName(QString::fromUtf8("actionAstro_Data"));
        actionBand_Map = new QAction(MainWindow);
        actionBand_Map->setObjectName(QString::fromUtf8("actionBand_Map"));
        actionMessages = new QAction(MainWindow);
        actionMessages->setObjectName(QString::fromUtf8("actionMessages"));
        actionWide_Waterfall = new QAction(MainWindow);
        actionWide_Waterfall->setObjectName(QString::fromUtf8("actionWide_Waterfall"));
        actionPast_periods_on_Wide_Graph = new QAction(MainWindow);
        actionPast_periods_on_Wide_Graph->setObjectName(QString::fromUtf8("actionPast_periods_on_Wide_Graph"));
        actionPast_periods_on_Wide_Graph->setCheckable(true);
        actionPast_periods_on_Wide_Graph->setChecked(false);
        actionKeep_last_period = new QAction(MainWindow);
        actionKeep_last_period->setObjectName(QString::fromUtf8("actionKeep_last_period"));
        actionKeep_last_period->setCheckable(true);
        actionKeep_last_period->setChecked(false);
        actionShow_callsigns_on_Waterfall = new QAction(MainWindow);
        actionShow_callsigns_on_Waterfall->setObjectName(QString::fromUtf8("actionShow_callsigns_on_Waterfall"));
        actionShow_callsigns_on_Waterfall->setCheckable(true);
        actionShow_callsigns_on_Waterfall->setChecked(true);
        actionEnable_Click_to_Work = new QAction(MainWindow);
        actionEnable_Click_to_Work->setObjectName(QString::fromUtf8("actionEnable_Click_to_Work"));
        actionEnable_Click_to_Work->setCheckable(true);
        actionEnable_Click_to_Work->setChecked(false);
        actionTransparency_None = new QAction(MainWindow);
        actionTransparency_None->setObjectName(QString::fromUtf8("actionTransparency_None"));
        actionTransparency_None->setCheckable(true);
        actionTransparency_None->setChecked(true);
        actionTransparency_Low = new QAction(MainWindow);
        actionTransparency_Low->setObjectName(QString::fromUtf8("actionTransparency_Low"));
        actionTransparency_Low->setCheckable(true);
        actionTransparency_Medium = new QAction(MainWindow);
        actionTransparency_Medium->setObjectName(QString::fromUtf8("actionTransparency_Medium"));
        actionTransparency_Medium->setCheckable(true);
        actionTransparency_High = new QAction(MainWindow);
        actionTransparency_High->setObjectName(QString::fromUtf8("actionTransparency_High"));
        actionTransparency_High->setCheckable(true);
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
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen_next_in_directory = new QAction(MainWindow);
        actionOpen_next_in_directory->setObjectName(QString::fromUtf8("actionOpen_next_in_directory"));
        actionDecode_remaining_files_in_directory = new QAction(MainWindow);
        actionDecode_remaining_files_in_directory->setObjectName(QString::fromUtf8("actionDecode_remaining_files_in_directory"));
        actionDelete_all_tf2_files_in_SaveDir = new QAction(MainWindow);
        actionDelete_all_tf2_files_in_SaveDir->setObjectName(QString::fromUtf8("actionDelete_all_tf2_files_in_SaveDir"));
        actionErase_Band_Map_and_Messages = new QAction(MainWindow);
        actionErase_Band_Map_and_Messages->setObjectName(QString::fromUtf8("actionErase_Band_Map_and_Messages"));
        actionErase_map65_rx_log = new QAction(MainWindow);
        actionErase_map65_rx_log->setObjectName(QString::fromUtf8("actionErase_map65_rx_log"));
        actionLinrad = new QAction(MainWindow);
        actionLinrad->setObjectName(QString::fromUtf8("actionLinrad"));
        actionLinrad->setCheckable(true);
        actionLinrad->setChecked(false);
        actionCuteSDR = new QAction(MainWindow);
        actionCuteSDR->setObjectName(QString::fromUtf8("actionCuteSDR"));
        actionCuteSDR->setCheckable(true);
        actionCuteSDR->setChecked(true);
        actionFind_Delta_Phi = new QAction(MainWindow);
        actionFind_Delta_Phi->setObjectName(QString::fromUtf8("actionFind_Delta_Phi"));
        actionF4_sets_Tx6 = new QAction(MainWindow);
        actionF4_sets_Tx6->setObjectName(QString::fromUtf8("actionF4_sets_Tx6"));
        actionF4_sets_Tx6->setCheckable(true);
        actionOnly_EME_calls = new QAction(MainWindow);
        actionOnly_EME_calls->setObjectName(QString::fromUtf8("actionOnly_EME_calls"));
        actionOnly_EME_calls->setCheckable(true);
        actionNo_shorthands_if_Tx1 = new QAction(MainWindow);
        actionNo_shorthands_if_Tx1->setObjectName(QString::fromUtf8("actionNo_shorthands_if_Tx1"));
        actionNo_shorthands_if_Tx1->setCheckable(true);
        actionNo_Deep_Search = new QAction(MainWindow);
        actionNo_Deep_Search->setObjectName(QString::fromUtf8("actionNo_Deep_Search"));
        actionNo_Deep_Search->setCheckable(true);
        actionNo_Deep_Search->setChecked(true);
        actionNormal_Deep_Search = new QAction(MainWindow);
        actionNormal_Deep_Search->setObjectName(QString::fromUtf8("actionNormal_Deep_Search"));
        actionNormal_Deep_Search->setCheckable(true);
        actionAggressive_Deep_Search = new QAction(MainWindow);
        actionAggressive_Deep_Search->setObjectName(QString::fromUtf8("actionAggressive_Deep_Search"));
        actionAggressive_Deep_Search->setCheckable(true);
        actionQ65_Fast = new QAction(MainWindow);
        actionQ65_Fast->setObjectName(QString::fromUtf8("actionQ65_Fast"));
        actionQ65_Fast->setCheckable(true);
        actionQ65_Normal = new QAction(MainWindow);
        actionQ65_Normal->setObjectName(QString::fromUtf8("actionQ65_Normal"));
        actionQ65_Normal->setCheckable(true);
        actionQ65_Deep = new QAction(MainWindow);
        actionQ65_Deep->setObjectName(QString::fromUtf8("actionQ65_Deep"));
        actionQ65_Deep->setCheckable(true);
        actionQ65_Deep->setChecked(true);
        actionNone = new QAction(MainWindow);
        actionNone->setObjectName(QString::fromUtf8("actionNone"));
        actionNone->setCheckable(true);
        actionNone->setChecked(true);
        actionSave_all = new QAction(MainWindow);
        actionSave_all->setObjectName(QString::fromUtf8("actionSave_all"));
        actionSave_all->setCheckable(true);
        action50 = new QAction(MainWindow);
        action50->setObjectName(QString::fromUtf8("action50"));
        action50->setCheckable(true);
        action144 = new QAction(MainWindow);
        action144->setObjectName(QString::fromUtf8("action144"));
        action144->setCheckable(true);
        action144->setChecked(true);
        action222 = new QAction(MainWindow);
        action222->setObjectName(QString::fromUtf8("action222"));
        action222->setCheckable(true);
        action432 = new QAction(MainWindow);
        action432->setObjectName(QString::fromUtf8("action432"));
        action432->setCheckable(true);
        action1296 = new QAction(MainWindow);
        action1296->setObjectName(QString::fromUtf8("action1296"));
        action1296->setCheckable(true);
        action2304 = new QAction(MainWindow);
        action2304->setObjectName(QString::fromUtf8("action2304"));
        action2304->setCheckable(true);
        actionOnline_Users_Guide = new QAction(MainWindow);
        actionOnline_Users_Guide->setObjectName(QString::fromUtf8("actionOnline_Users_Guide"));
        actionKeyboard_shortcuts = new QAction(MainWindow);
        actionKeyboard_shortcuts->setObjectName(QString::fromUtf8("actionKeyboard_shortcuts"));
        actionSpecial_mouse_commands = new QAction(MainWindow);
        actionSpecial_mouse_commands->setObjectName(QString::fromUtf8("actionSpecial_mouse_commands"));
        actionAvailable_suffixes_and_add_on_prefixes = new QAction(MainWindow);
        actionAvailable_suffixes_and_add_on_prefixes->setObjectName(QString::fromUtf8("actionAvailable_suffixes_and_add_on_prefixes"));
        actionErase_map65_tx_log = new QAction(MainWindow);
        actionErase_map65_tx_log->setObjectName(QString::fromUtf8("actionErase_map65_tx_log"));
        actionJT65A = new QAction(MainWindow);
        actionJT65A->setObjectName(QString::fromUtf8("actionJT65A"));
        actionJT65A->setCheckable(true);
        actionJT65B = new QAction(MainWindow);
        actionJT65B->setObjectName(QString::fromUtf8("actionJT65B"));
        actionJT65B->setCheckable(true);
        actionJT65B->setChecked(true);
        actionJT65C = new QAction(MainWindow);
        actionJT65C->setObjectName(QString::fromUtf8("actionJT65C"));
        actionJT65C->setCheckable(true);
        actionI_Q_Calibration = new QAction(MainWindow);
        actionI_Q_Calibration->setObjectName(QString::fromUtf8("actionI_Q_Calibration"));
        actionAdjust_IQ_Calibration = new QAction(MainWindow);
        actionAdjust_IQ_Calibration->setObjectName(QString::fromUtf8("actionAdjust_IQ_Calibration"));
        actionApply_IQ_Calibration = new QAction(MainWindow);
        actionApply_IQ_Calibration->setObjectName(QString::fromUtf8("actionApply_IQ_Calibration"));
        actionApply_IQ_Calibration->setCheckable(true);
        actionAFMHot = new QAction(MainWindow);
        actionAFMHot->setObjectName(QString::fromUtf8("actionAFMHot"));
        actionAFMHot->setCheckable(true);
        actionBlue = new QAction(MainWindow);
        actionBlue->setObjectName(QString::fromUtf8("actionBlue"));
        actionBlue->setCheckable(true);
        actionFUNcube_Dongle = new QAction(MainWindow);
        actionFUNcube_Dongle->setObjectName(QString::fromUtf8("actionFUNcube_Dongle"));
        actionEdit_wsjt_log = new QAction(MainWindow);
        actionEdit_wsjt_log->setObjectName(QString::fromUtf8("actionEdit_wsjt_log"));
        actionTx_Tune = new QAction(MainWindow);
        actionTx_Tune->setObjectName(QString::fromUtf8("actionTx_Tune"));
        actionDecode_Q65_near_QSO_frequency = new QAction(MainWindow);
        actionDecode_Q65_near_QSO_frequency->setObjectName(QString::fromUtf8("actionDecode_Q65_near_QSO_frequency"));
        actionDecode_Q65_near_QSO_frequency->setCheckable(true);
        actionQ65A = new QAction(MainWindow);
        actionQ65A->setObjectName(QString::fromUtf8("actionQ65A"));
        actionQ65A->setCheckable(true);
        actionQ65B = new QAction(MainWindow);
        actionQ65B->setObjectName(QString::fromUtf8("actionQ65B"));
        actionQ65B->setCheckable(true);
        actionNoJT65 = new QAction(MainWindow);
        actionNoJT65->setObjectName(QString::fromUtf8("actionNoJT65"));
        actionNoJT65->setCheckable(true);
        actionNoQ65 = new QAction(MainWindow);
        actionNoQ65->setObjectName(QString::fromUtf8("actionNoQ65"));
        actionNoQ65->setCheckable(true);
        actionNoQ65->setChecked(true);
        actionQ65C = new QAction(MainWindow);
        actionQ65C->setObjectName(QString::fromUtf8("actionQ65C"));
        actionQ65C->setCheckable(true);
        actionQ65D = new QAction(MainWindow);
        actionQ65D->setObjectName(QString::fromUtf8("actionQ65D"));
        actionQ65D->setCheckable(true);
        actionQ65E = new QAction(MainWindow);
        actionQ65E->setObjectName(QString::fromUtf8("actionQ65E"));
        actionQ65E->setCheckable(true);
        actionQSG_Q65 = new QAction(MainWindow);
        actionQSG_Q65->setObjectName(QString::fromUtf8("actionQSG_Q65"));
        actionQSG_MAP65_v3 = new QAction(MainWindow);
        actionQSG_MAP65_v3->setObjectName(QString::fromUtf8("actionQSG_MAP65_v3"));
        actionQ65_Sensitivity_in_MAP65_3_0 = new QAction(MainWindow);
        actionQ65_Sensitivity_in_MAP65_3_0->setObjectName(QString::fromUtf8("actionQ65_Sensitivity_in_MAP65_3_0"));
        actionRelease_Notes = new QAction(MainWindow);
        actionRelease_Notes->setObjectName(QString::fromUtf8("actionRelease_Notes"));
        actionOpen_MAP65_data_directory = new QAction(MainWindow);
        actionOpen_MAP65_data_directory->setObjectName(QString::fromUtf8("actionOpen_MAP65_data_directory"));
        actionReduce_false_decodes = new QAction(MainWindow);
        actionReduce_false_decodes->setObjectName(QString::fromUtf8("actionReduce_false_decodes"));
        actionReduce_false_decodes->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(10);
        groupBox->setFont(font);
        verticalLayout_9 = new QVBoxLayout(groupBox);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        decodedTextBrowser = new DisplayText(groupBox);
        decodedTextBrowser->setObjectName(QString::fromUtf8("decodedTextBrowser"));
        sizePolicy1.setHeightForWidth(decodedTextBrowser->sizePolicy().hasHeightForWidth());
        decodedTextBrowser->setSizePolicy(sizePolicy1);
        decodedTextBrowser->setMinimumSize(QSize(0, 0));
        decodedTextBrowser->setMaximumSize(QSize(16777215, 16777215));
        decodedTextBrowser->setFont(font);
        decodedTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        decodedTextBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        decodedTextBrowser->setAcceptRichText(false);

        verticalLayout_9->addWidget(decodedTextBrowser);


        verticalLayout_7->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        logQSOButton = new QPushButton(centralWidget);
        logQSOButton->setObjectName(QString::fromUtf8("logQSOButton"));
        logQSOButton->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(logQSOButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(stopButton);

        monitorButton = new QPushButton(centralWidget);
        monitorButton->setObjectName(QString::fromUtf8("monitorButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(monitorButton->sizePolicy().hasHeightForWidth());
        monitorButton->setSizePolicy(sizePolicy2);
        monitorButton->setMinimumSize(QSize(50, 0));
        monitorButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(monitorButton);

        DecodeButton = new QPushButton(centralWidget);
        DecodeButton->setObjectName(QString::fromUtf8("DecodeButton"));
        DecodeButton->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(DecodeButton);

        EraseButton = new QPushButton(centralWidget);
        EraseButton->setObjectName(QString::fromUtf8("EraseButton"));
        EraseButton->setMinimumSize(QSize(50, 0));
        EraseButton->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_2->addWidget(EraseButton);

        autoButton = new QPushButton(centralWidget);
        autoButton->setObjectName(QString::fromUtf8("autoButton"));
        sizePolicy2.setHeightForWidth(autoButton->sizePolicy().hasHeightForWidth());
        autoButton->setSizePolicy(sizePolicy2);
        autoButton->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(autoButton);

        stopTxButton = new QPushButton(centralWidget);
        stopTxButton->setObjectName(QString::fromUtf8("stopTxButton"));
        sizePolicy2.setHeightForWidth(stopTxButton->sizePolicy().hasHeightForWidth());
        stopTxButton->setSizePolicy(sizePolicy2);
        stopTxButton->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(stopTxButton);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        xMeterFrame = new QFrame(centralWidget);
        xMeterFrame->setObjectName(QString::fromUtf8("xMeterFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(xMeterFrame->sizePolicy().hasHeightForWidth());
        xMeterFrame->setSizePolicy(sizePolicy3);
        xMeterFrame->setMinimumSize(QSize(65, 100));
        xMeterFrame->setMaximumSize(QSize(100, 16777215));
        xMeterFrame->setFrameShape(QFrame::StyledPanel);
        xMeterFrame->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(xMeterFrame);

        yMeterFrame = new QFrame(centralWidget);
        yMeterFrame->setObjectName(QString::fromUtf8("yMeterFrame"));
        sizePolicy3.setHeightForWidth(yMeterFrame->sizePolicy().hasHeightForWidth());
        yMeterFrame->setSizePolicy(sizePolicy3);
        yMeterFrame->setMinimumSize(QSize(65, 0));
        yMeterFrame->setMaximumSize(QSize(100, 16777215));
        yMeterFrame->setFrameShape(QFrame::StyledPanel);
        yMeterFrame->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(yMeterFrame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dxStationGroupBox = new QGroupBox(centralWidget);
        dxStationGroupBox->setObjectName(QString::fromUtf8("dxStationGroupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dxStationGroupBox->sizePolicy().hasHeightForWidth());
        dxStationGroupBox->setSizePolicy(sizePolicy4);
        dxStationGroupBox->setMinimumSize(QSize(190, 0));
        dxStationGroupBox->setMaximumSize(QSize(16777215, 16777215));
        dxStationGroupBox->setStyleSheet(QString::fromUtf8(""));
        dxStationGroupBox->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(dxStationGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(6, 0, 6, 6);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dxCallEntry = new QLineEdit(dxStationGroupBox);
        dxCallEntry->setObjectName(QString::fromUtf8("dxCallEntry"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(dxCallEntry->sizePolicy().hasHeightForWidth());
        dxCallEntry->setSizePolicy(sizePolicy5);
        dxCallEntry->setMinimumSize(QSize(0, 23));
        dxCallEntry->setMaximumSize(QSize(16777215, 16777215));
        dxCallEntry->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(dxCallEntry);

        dxGridEntry = new QLineEdit(dxStationGroupBox);
        dxGridEntry->setObjectName(QString::fromUtf8("dxGridEntry"));
        sizePolicy5.setHeightForWidth(dxGridEntry->sizePolicy().hasHeightForWidth());
        dxGridEntry->setSizePolicy(sizePolicy5);
        dxGridEntry->setMinimumSize(QSize(0, 23));
        dxGridEntry->setMaximumSize(QSize(16777215, 16777215));
        dxGridEntry->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(dxGridEntry);


        verticalLayout_6->addLayout(horizontalLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lookupButton = new QPushButton(dxStationGroupBox);
        lookupButton->setObjectName(QString::fromUtf8("lookupButton"));
        sizePolicy5.setHeightForWidth(lookupButton->sizePolicy().hasHeightForWidth());
        lookupButton->setSizePolicy(sizePolicy5);
        lookupButton->setMinimumSize(QSize(0, 0));
        lookupButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(lookupButton, 0, 0, 1, 1);

        addButton = new QPushButton(dxStationGroupBox);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        sizePolicy5.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy5);
        addButton->setMinimumSize(QSize(0, 0));
        addButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(addButton, 0, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_2);


        gridLayout->addLayout(verticalLayout_6, 2, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        genStdMsgsPushButton = new QPushButton(dxStationGroupBox);
        genStdMsgsPushButton->setObjectName(QString::fromUtf8("genStdMsgsPushButton"));
        sizePolicy2.setHeightForWidth(genStdMsgsPushButton->sizePolicy().hasHeightForWidth());
        genStdMsgsPushButton->setSizePolicy(sizePolicy2);
        genStdMsgsPushButton->setMinimumSize(QSize(0, 0));
        genStdMsgsPushButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(genStdMsgsPushButton);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 2);

        DX_Grid_label = new QLabel(dxStationGroupBox);
        DX_Grid_label->setObjectName(QString::fromUtf8("DX_Grid_label"));
        DX_Grid_label->setStyleSheet(QString::fromUtf8("border-width: 0;"));
        DX_Grid_label->setLineWidth(1);
        DX_Grid_label->setMidLineWidth(0);

        gridLayout->addWidget(DX_Grid_label, 1, 1, 1, 1);

        DX_Call_label = new QLabel(dxStationGroupBox);
        DX_Call_label->setObjectName(QString::fromUtf8("DX_Call_label"));
        DX_Call_label->setStyleSheet(QString::fromUtf8("border-width: 0;"));
        DX_Call_label->setLineWidth(1);
        DX_Call_label->setMidLineWidth(0);
        DX_Call_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(DX_Call_label, 1, 0, 1, 1);


        verticalLayout->addWidget(dxStationGroupBox);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        labUTC = new QLabel(centralWidget);
        labUTC->setObjectName(QString::fromUtf8("labUTC"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(labUTC->sizePolicy().hasHeightForWidth());
        labUTC->setSizePolicy(sizePolicy6);
        labUTC->setMinimumSize(QSize(180, 100));
        labUTC->setMaximumSize(QSize(300, 200));
        QFont font1;
        font1.setPointSize(14);
        labUTC->setFont(font1);
        labUTC->setFrameShape(QFrame::Panel);
        labUTC->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labUTC, 0, Qt::AlignHCenter);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);

        txFirstCheckBox = new QCheckBox(centralWidget);
        txFirstCheckBox->setObjectName(QString::fromUtf8("txFirstCheckBox"));
        txFirstCheckBox->setMinimumSize(QSize(0, 23));
        txFirstCheckBox->setMaximumSize(QSize(80, 16777215));

        verticalLayout_5->addWidget(txFirstCheckBox);

        pbTxMode = new QPushButton(centralWidget);
        pbTxMode->setObjectName(QString::fromUtf8("pbTxMode"));
        pbTxMode->setMinimumSize(QSize(90, 0));
        pbTxMode->setMaximumSize(QSize(80, 16777215));

        verticalLayout_5->addWidget(pbTxMode);

        setTxFreqButton = new QPushButton(centralWidget);
        setTxFreqButton->setObjectName(QString::fromUtf8("setTxFreqButton"));
        setTxFreqButton->setMinimumSize(QSize(90, 0));
        setTxFreqButton->setMaximumSize(QSize(80, 16777215));

        verticalLayout_5->addWidget(setTxFreqButton);

        sbMaxDrift = new QSpinBox(centralWidget);
        sbMaxDrift->setObjectName(QString::fromUtf8("sbMaxDrift"));
        sbMaxDrift->setAlignment(Qt::AlignCenter);
        sbMaxDrift->setMaximum(50);
        sbMaxDrift->setSingleStep(5);

        verticalLayout_5->addWidget(sbMaxDrift);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer);

        NBcheckBox = new QCheckBox(centralWidget);
        NBcheckBox->setObjectName(QString::fromUtf8("NBcheckBox"));

        verticalLayout_5->addWidget(NBcheckBox);

        NBslider = new QSlider(centralWidget);
        NBslider->setObjectName(QString::fromUtf8("NBslider"));
        NBslider->setEnabled(false);
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(NBslider->sizePolicy().hasHeightForWidth());
        NBslider->setSizePolicy(sizePolicy7);
        NBslider->setMaximumSize(QSize(80, 16777215));
        NBslider->setMinimum(0);
        NBslider->setMaximum(100);
        NBslider->setValue(40);
        NBslider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(NBslider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labTol1 = new QLabel(centralWidget);
        labTol1->setObjectName(QString::fromUtf8("labTol1"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(labTol1->sizePolicy().hasHeightForWidth());
        labTol1->setSizePolicy(sizePolicy8);
        labTol1->setMinimumSize(QSize(42, 0));
        labTol1->setMaximumSize(QSize(42, 18));
        labTol1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labTol1);

        tolSpinBox = new QSpinBox(centralWidget);
        tolSpinBox->setObjectName(QString::fromUtf8("tolSpinBox"));
        tolSpinBox->setEnabled(true);
        sizePolicy7.setHeightForWidth(tolSpinBox->sizePolicy().hasHeightForWidth());
        tolSpinBox->setSizePolicy(sizePolicy7);
        tolSpinBox->setMinimumSize(QSize(0, 23));
        tolSpinBox->setMaximumSize(QSize(18, 16777215));
        tolSpinBox->setMinimum(1);
        tolSpinBox->setMaximum(6);
        tolSpinBox->setValue(5);

        horizontalLayout->addWidget(tolSpinBox);

        labTol2 = new QLabel(centralWidget);
        labTol2->setObjectName(QString::fromUtf8("labTol2"));
        sizePolicy8.setHeightForWidth(labTol2->sizePolicy().hasHeightForWidth());
        labTol2->setSizePolicy(sizePolicy8);
        labTol2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(labTol2);


        verticalLayout_5->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tx1 = new QLineEdit(centralWidget);
        tx1->setObjectName(QString::fromUtf8("tx1"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(160);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(tx1->sizePolicy().hasHeightForWidth());
        tx1->setSizePolicy(sizePolicy9);
        tx1->setMinimumSize(QSize(100, 24));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        tx1->setFont(font2);

        verticalLayout_2->addWidget(tx1);

        tx2 = new QLineEdit(centralWidget);
        tx2->setObjectName(QString::fromUtf8("tx2"));
        sizePolicy9.setHeightForWidth(tx2->sizePolicy().hasHeightForWidth());
        tx2->setSizePolicy(sizePolicy9);
        tx2->setMinimumSize(QSize(100, 24));

        verticalLayout_2->addWidget(tx2);

        tx3 = new QLineEdit(centralWidget);
        tx3->setObjectName(QString::fromUtf8("tx3"));
        sizePolicy9.setHeightForWidth(tx3->sizePolicy().hasHeightForWidth());
        tx3->setSizePolicy(sizePolicy9);
        tx3->setMinimumSize(QSize(100, 24));

        verticalLayout_2->addWidget(tx3);

        tx4 = new QLineEdit(centralWidget);
        tx4->setObjectName(QString::fromUtf8("tx4"));
        sizePolicy9.setHeightForWidth(tx4->sizePolicy().hasHeightForWidth());
        tx4->setSizePolicy(sizePolicy9);
        tx4->setMinimumSize(QSize(100, 24));

        verticalLayout_2->addWidget(tx4);

        tx5 = new QLineEdit(centralWidget);
        tx5->setObjectName(QString::fromUtf8("tx5"));
        sizePolicy9.setHeightForWidth(tx5->sizePolicy().hasHeightForWidth());
        tx5->setSizePolicy(sizePolicy9);
        tx5->setMinimumSize(QSize(100, 24));

        verticalLayout_2->addWidget(tx5);

        tx6 = new QLineEdit(centralWidget);
        tx6->setObjectName(QString::fromUtf8("tx6"));
        sizePolicy9.setHeightForWidth(tx6->sizePolicy().hasHeightForWidth());
        tx6->setSizePolicy(sizePolicy9);
        tx6->setMinimumSize(QSize(100, 24));

        verticalLayout_2->addWidget(tx6);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        txrb1 = new QRadioButton(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->setExclusive(true);
        buttonGroup->addButton(txrb1);
        txrb1->setObjectName(QString::fromUtf8("txrb1"));
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(16);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(txrb1->sizePolicy().hasHeightForWidth());
        txrb1->setSizePolicy(sizePolicy10);
        txrb1->setMinimumSize(QSize(0, 20));
        txrb1->setMaximumSize(QSize(30, 16777215));
        txrb1->setChecked(true);

        verticalLayout_3->addWidget(txrb1);

        txrb2 = new QRadioButton(centralWidget);
        buttonGroup->addButton(txrb2);
        txrb2->setObjectName(QString::fromUtf8("txrb2"));
        sizePolicy10.setHeightForWidth(txrb2->sizePolicy().hasHeightForWidth());
        txrb2->setSizePolicy(sizePolicy10);
        txrb2->setMinimumSize(QSize(0, 20));
        txrb2->setMaximumSize(QSize(30, 16777215));

        verticalLayout_3->addWidget(txrb2);

        txrb3 = new QRadioButton(centralWidget);
        buttonGroup->addButton(txrb3);
        txrb3->setObjectName(QString::fromUtf8("txrb3"));
        sizePolicy10.setHeightForWidth(txrb3->sizePolicy().hasHeightForWidth());
        txrb3->setSizePolicy(sizePolicy10);
        txrb3->setMinimumSize(QSize(0, 20));
        txrb3->setMaximumSize(QSize(30, 16777215));

        verticalLayout_3->addWidget(txrb3);

        txrb4 = new QRadioButton(centralWidget);
        buttonGroup->addButton(txrb4);
        txrb4->setObjectName(QString::fromUtf8("txrb4"));
        sizePolicy10.setHeightForWidth(txrb4->sizePolicy().hasHeightForWidth());
        txrb4->setSizePolicy(sizePolicy10);
        txrb4->setMinimumSize(QSize(0, 20));
        txrb4->setMaximumSize(QSize(30, 16777215));

        verticalLayout_3->addWidget(txrb4);

        txrb5 = new QRadioButton(centralWidget);
        buttonGroup->addButton(txrb5);
        txrb5->setObjectName(QString::fromUtf8("txrb5"));
        sizePolicy10.setHeightForWidth(txrb5->sizePolicy().hasHeightForWidth());
        txrb5->setSizePolicy(sizePolicy10);
        txrb5->setMinimumSize(QSize(0, 20));
        txrb5->setMaximumSize(QSize(30, 16777215));

        verticalLayout_3->addWidget(txrb5);

        txrb6 = new QRadioButton(centralWidget);
        buttonGroup->addButton(txrb6);
        txrb6->setObjectName(QString::fromUtf8("txrb6"));
        sizePolicy10.setHeightForWidth(txrb6->sizePolicy().hasHeightForWidth());
        txrb6->setSizePolicy(sizePolicy10);
        txrb6->setMinimumSize(QSize(0, 20));
        txrb6->setMaximumSize(QSize(30, 16777215));

        verticalLayout_3->addWidget(txrb6);


        horizontalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        txb1 = new QPushButton(centralWidget);
        txb1->setObjectName(QString::fromUtf8("txb1"));
        QSizePolicy sizePolicy11(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(50);
        sizePolicy11.setVerticalStretch(20);
        sizePolicy11.setHeightForWidth(txb1->sizePolicy().hasHeightForWidth());
        txb1->setSizePolicy(sizePolicy11);
        txb1->setMinimumSize(QSize(35, 20));
        txb1->setMaximumSize(QSize(50, 30));

        verticalLayout_4->addWidget(txb1);

        txb2 = new QPushButton(centralWidget);
        txb2->setObjectName(QString::fromUtf8("txb2"));
        txb2->setMinimumSize(QSize(35, 20));
        txb2->setMaximumSize(QSize(50, 30));

        verticalLayout_4->addWidget(txb2);

        txb3 = new QPushButton(centralWidget);
        txb3->setObjectName(QString::fromUtf8("txb3"));
        txb3->setMinimumSize(QSize(35, 20));
        txb3->setMaximumSize(QSize(50, 30));

        verticalLayout_4->addWidget(txb3);

        txb4 = new QPushButton(centralWidget);
        txb4->setObjectName(QString::fromUtf8("txb4"));
        txb4->setMinimumSize(QSize(35, 20));
        txb4->setMaximumSize(QSize(50, 30));

        verticalLayout_4->addWidget(txb4);

        txb5 = new QPushButton(centralWidget);
        txb5->setObjectName(QString::fromUtf8("txb5"));
        txb5->setMinimumSize(QSize(35, 20));
        txb5->setMaximumSize(QSize(50, 30));

        verticalLayout_4->addWidget(txb5);

        txb6 = new QPushButton(centralWidget);
        txb6->setObjectName(QString::fromUtf8("txb6"));
        txb6->setMinimumSize(QSize(35, 20));
        txb6->setMaximumSize(QSize(50, 30));

        verticalLayout_4->addWidget(txb6);


        horizontalLayout_9->addLayout(verticalLayout_4);

        horizontalLayout_9->setStretch(0, 1);

        horizontalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(5, 1);

        verticalLayout_7->addLayout(horizontalLayout_5);

        verticalLayout_7->setStretch(0, 5);

        verticalLayout_8->addLayout(verticalLayout_7);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSetup = new QMenu(menuBar);
        menuSetup->setObjectName(QString::fromUtf8("menuSetup"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuWaterfall_palette = new QMenu(menuView);
        menuWaterfall_palette->setObjectName(QString::fromUtf8("menuWaterfall_palette"));
        menuCallsign_transparency = new QMenu(menuView);
        menuCallsign_transparency->setObjectName(QString::fromUtf8("menuCallsign_transparency"));
        menuCallsign_font = new QMenu(menuView);
        menuCallsign_font->setObjectName(QString::fromUtf8("menuCallsign_font"));
        menuCallsign_position = new QMenu(menuView);
        menuCallsign_position->setObjectName(QString::fromUtf8("menuCallsign_position"));
        menuDecode = new QMenu(menuBar);
        menuDecode->setObjectName(QString::fromUtf8("menuDecode"));
        menuSave = new QMenu(menuBar);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuMode = new QMenu(menuBar);
        menuMode->setObjectName(QString::fromUtf8("menuMode"));
        menuWSJT_X = new QMenu(menuBar);
        menuWSJT_X->setObjectName(QString::fromUtf8("menuWSJT_X"));
        menuInstance_ID = new QMenu(menuWSJT_X);
        menuInstance_ID->setObjectName(QString::fromUtf8("menuInstance_ID"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSetup->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuMode->menuAction());
        menuBar->addAction(menuDecode->menuAction());
        menuBar->addAction(menuSave->menuAction());
        menuBar->addAction(menuWSJT_X->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_next_in_directory);
        menuFile->addAction(actionDecode_remaining_files_in_directory);
        menuFile->addSeparator();
        menuFile->addAction(actionEdit_wsjt_log);
        menuFile->addSeparator();
        menuFile->addAction(actionDelete_all_tf2_files_in_SaveDir);
        menuFile->addAction(actionErase_Band_Map_and_Messages);
        menuFile->addAction(actionErase_map65_rx_log);
        menuFile->addAction(actionErase_map65_tx_log);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_MAP65_data_directory);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuSetup->addAction(actionDeviceSetup);
        menuSetup->addSeparator();
        menuSetup->addAction(actionAdjust_IQ_Calibration);
        menuSetup->addAction(actionApply_IQ_Calibration);
        menuSetup->addAction(actionFind_Delta_Phi);
        menuSetup->addAction(actionTx_Tune);
        menuSetup->addSeparator();
        menuSetup->addAction(actionF4_sets_Tx6);
        menuSetup->addSeparator();
        menuSetup->addAction(actionFUNcube_Dongle);
        menuView->addAction(actionAstro_Data);
        menuView->addAction(actionBand_Map);
        menuView->addAction(actionMessages);
        menuView->addAction(actionWide_Waterfall);
        menuView->addSeparator();
        menuView->addAction(menuWaterfall_palette->menuAction());
        menuView->addSeparator();
        menuView->addAction(actionShow_callsigns_on_Waterfall);
        menuView->addAction(menuCallsign_transparency->menuAction());
        menuView->addAction(menuCallsign_font->menuAction());
        menuView->addAction(menuCallsign_position->menuAction());
        menuView->addSeparator();
        menuView->addAction(actionEnable_Click_to_Work);
        menuView->addAction(actionAdd_Call_to_SH);
        menuWaterfall_palette->addAction(actionLinrad);
        menuWaterfall_palette->addAction(actionCuteSDR);
        menuCallsign_transparency->addAction(actionTransparency_None);
        menuCallsign_transparency->addAction(actionTransparency_Low);
        menuCallsign_transparency->addAction(actionTransparency_Medium);
        menuCallsign_transparency->addAction(actionTransparency_High);
        menuCallsign_font->addAction(actionCallsign_font_small);
        menuCallsign_font->addAction(actionCallsign_font_normal);
        menuCallsign_font->addAction(actionCallsign_font_medium);
        menuCallsign_font->addAction(actionCallsign_font_large);
        menuCallsign_position->addAction(actionCallsign_position_top);
        menuCallsign_position->addAction(actionCallsign_position_bottom);
        menuDecode->addAction(actionOnly_EME_calls);
        menuDecode->addAction(actionNo_shorthands_if_Tx1);
        menuDecode->addSeparator();
        menuDecode->addAction(actionNo_Deep_Search);
        menuDecode->addAction(actionNormal_Deep_Search);
        menuDecode->addAction(actionAggressive_Deep_Search);
        menuDecode->addSeparator();
        menuDecode->addAction(actionQ65_Fast);
        menuDecode->addAction(actionQ65_Normal);
        menuDecode->addAction(actionQ65_Deep);
        menuDecode->addSeparator();
        menuDecode->addAction(actionKeep_last_period);
        menuDecode->addAction(actionPast_periods_on_Wide_Graph);
        menuDecode->addSeparator();
        menuDecode->addAction(actionReduce_false_decodes);
        menuSave->addAction(actionNone);
        menuSave->addAction(actionSave_all);
        menuHelp->addAction(actionRelease_Notes);
        menuHelp->addAction(actionOnline_Users_Guide);
        menuHelp->addAction(actionQSG_Q65);
        menuHelp->addAction(actionQSG_MAP65_v3);
        menuHelp->addAction(actionQ65_Sensitivity_in_MAP65_3_0);
        menuHelp->addAction(actionKeyboard_shortcuts);
        menuHelp->addAction(actionSpecial_mouse_commands);
        menuHelp->addAction(actionAvailable_suffixes_and_add_on_prefixes);
        menuHelp->addAction(actionAbout);
        menuMode->addAction(actionNoJT65);
        menuMode->addAction(actionJT65A);
        menuMode->addAction(actionJT65B);
        menuMode->addAction(actionJT65C);
        menuMode->addSeparator();
        menuMode->addAction(actionNoQ65);
        menuMode->addAction(actionQ65A);
        menuMode->addAction(actionQ65B);
        menuMode->addAction(actionQ65C);
        menuMode->addAction(actionQ65D);
        menuMode->addAction(actionQ65E);
        menuWSJT_X->addAction(actionSync_WSJTX);
        menuWSJT_X->addAction(actionTx_via_WSJTX);
        menuWSJT_X->addAction(actionContinuous_waterfall);
        menuWSJT_X->addSeparator();
        menuWSJT_X->addAction(menuInstance_ID->menuAction());
        menuInstance_ID->addAction(actionInstance_ID_1);
        menuInstance_ID->addAction(actionInstance_ID_2);
        menuInstance_ID->addAction(actionInstance_ID_3);
        menuInstance_ID->addAction(actionInstance_ID_4);

        retranslateUi(MainWindow);
        QObject::connect(monitorButton, SIGNAL(toggled(bool)), MainWindow, SLOT(update()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SpecJT   by K1JT", nullptr));
        actionSync_WSJTX->setText(QCoreApplication::translate("MainWindow", "Send data to WS", nullptr));
        actionTx_via_WSJTX->setText(QCoreApplication::translate("MainWindow", "Double-click keys WS (else EME65)", nullptr));
        actionTx_via_WSJTX->setIconText(QCoreApplication::translate("MainWindow", "Double-click keys WS (else EME65)", nullptr));
#if QT_CONFIG(tooltip)
        actionTx_via_WSJTX->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Double-click keys WS (else EME65)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionContinuous_waterfall->setText(QCoreApplication::translate("MainWindow", "Continuous Waterfall (keep Rx on while WS transmits)", nullptr));
        actionContinuous_waterfall->setIconText(QCoreApplication::translate("MainWindow", "Continuous Waterfall (keep Rx on while WS transmits)", nullptr));
#if QT_CONFIG(tooltip)
        actionContinuous_waterfall->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Normally EME65 mutes its receiver, holds the waterfall and skips the decode while WS transmits, so your own signal cannot produce bad decodes. Tick this to keep receiving anyway (tests, RX-only stations).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionInstance_ID_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        actionInstance_ID_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        actionInstance_ID_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        actionInstance_ID_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        actionAdd_Call_to_SH->setText(QCoreApplication::translate("MainWindow", "Assign callsign to sh messages (RO/RRR/73)", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionDeviceSetup->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
#if QT_CONFIG(shortcut)
        actionDeviceSetup->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About EME65", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAstro_Data->setText(QCoreApplication::translate("MainWindow", "Astro Data", nullptr));
#if QT_CONFIG(shortcut)
        actionAstro_Data->setShortcut(QCoreApplication::translate("MainWindow", "Shift+F10", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBand_Map->setText(QCoreApplication::translate("MainWindow", "Band Map", nullptr));
        actionMessages->setText(QCoreApplication::translate("MainWindow", "Messages", nullptr));
        actionWide_Waterfall->setText(QCoreApplication::translate("MainWindow", "Wide Waterfall", nullptr));
        actionPast_periods_on_Wide_Graph->setText(QCoreApplication::translate("MainWindow", "Allow re-decoding of past 3 periods", nullptr));
#if QT_CONFIG(tooltip)
        actionPast_periods_on_Wide_Graph->setToolTip(QCoreApplication::translate("MainWindow", "Keep the last 3 periods on disk. This allows you to click on a signal from a past period, so it can be decoded again.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionKeep_last_period->setText(QCoreApplication::translate("MainWindow", "Keep last period in RAM", nullptr));
#if QT_CONFIG(tooltip)
        actionKeep_last_period->setToolTip(QCoreApplication::translate("MainWindow", "Keep the last decoded period in memory. Double-clicking the lower (zoomed) graph then re-decodes that period at the clicked frequency +/- Tol instead of the live buffer.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionShow_callsigns_on_Waterfall->setText(QCoreApplication::translate("MainWindow", "Show callsigns on Waterfall", nullptr));
#if QT_CONFIG(tooltip)
        actionShow_callsigns_on_Waterfall->setToolTip(QCoreApplication::translate("MainWindow", "Toggle the decoded-callsign overlay on the wide waterfall. Default ON. Persists across launches.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEnable_Click_to_Work->setText(QCoreApplication::translate("MainWindow", "Double-clicking activates Enable Tx", nullptr));
#if QT_CONFIG(tooltip)
        actionEnable_Click_to_Work->setToolTip(QCoreApplication::translate("MainWindow", "Click a callsign overlay on the waterfall, or in the decoded-text/Messages windows, to populate DX Call/Grid. Double-click also enables Tx.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTransparency_None->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        actionTransparency_Low->setText(QCoreApplication::translate("MainWindow", "Low", nullptr));
        actionTransparency_Medium->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        actionTransparency_High->setText(QCoreApplication::translate("MainWindow", "High", nullptr));
        actionCallsign_font_small->setText(QCoreApplication::translate("MainWindow", "Small (7 pt)", nullptr));
        actionCallsign_font_normal->setText(QCoreApplication::translate("MainWindow", "Normal (8 pt)", nullptr));
        actionCallsign_font_medium->setText(QCoreApplication::translate("MainWindow", "Medium (10 pt)", nullptr));
        actionCallsign_font_large->setText(QCoreApplication::translate("MainWindow", "Large (12 pt)", nullptr));
        actionCallsign_position_top->setText(QCoreApplication::translate("MainWindow", "Top of waterfall", nullptr));
        actionCallsign_position_bottom->setText(QCoreApplication::translate("MainWindow", "Bottom of waterfall (above divider)", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionOpen_next_in_directory->setText(QCoreApplication::translate("MainWindow", "Open next in directory", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_next_in_directory->setShortcut(QCoreApplication::translate("MainWindow", "F6", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDecode_remaining_files_in_directory->setText(QCoreApplication::translate("MainWindow", "Decode remaining files in directory", nullptr));
#if QT_CONFIG(shortcut)
        actionDecode_remaining_files_in_directory->setShortcut(QCoreApplication::translate("MainWindow", "Shift+F6", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete_all_tf2_files_in_SaveDir->setText(QCoreApplication::translate("MainWindow", "Delete all *.tf2 and *.iq files in SaveDir", nullptr));
        actionErase_Band_Map_and_Messages->setText(QCoreApplication::translate("MainWindow", "Erase Band Map and Messages", nullptr));
        actionErase_map65_rx_log->setText(QCoreApplication::translate("MainWindow", "Erase map65_rx.log", nullptr));
        actionLinrad->setText(QCoreApplication::translate("MainWindow", "Linrad", nullptr));
        actionCuteSDR->setText(QCoreApplication::translate("MainWindow", "CuteSDR", nullptr));
        actionFind_Delta_Phi->setText(QCoreApplication::translate("MainWindow", "Find Delta Phi", nullptr));
        actionF4_sets_Tx6->setText(QCoreApplication::translate("MainWindow", "F4 sets Tx6", nullptr));
        actionOnly_EME_calls->setText(QCoreApplication::translate("MainWindow", "Only EME calls", nullptr));
        actionNo_shorthands_if_Tx1->setText(QCoreApplication::translate("MainWindow", "No shorthand decodes if Tx1", nullptr));
        actionNo_Deep_Search->setText(QCoreApplication::translate("MainWindow", "No Deep Search", nullptr));
        actionNormal_Deep_Search->setText(QCoreApplication::translate("MainWindow", "Normal Deep Search", nullptr));
        actionAggressive_Deep_Search->setText(QCoreApplication::translate("MainWindow", "Aggressive Deep Search", nullptr));
        actionQ65_Fast->setText(QCoreApplication::translate("MainWindow", "Q65 Fast", nullptr));
        actionQ65_Normal->setText(QCoreApplication::translate("MainWindow", "Q65 Normal", nullptr));
        actionQ65_Deep->setText(QCoreApplication::translate("MainWindow", "Q65 Deep", nullptr));
        actionNone->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        actionSave_all->setText(QCoreApplication::translate("MainWindow", "Save all", nullptr));
        action50->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        action144->setText(QCoreApplication::translate("MainWindow", "144", nullptr));
        action222->setText(QCoreApplication::translate("MainWindow", "222", nullptr));
        action432->setText(QCoreApplication::translate("MainWindow", "432", nullptr));
        action1296->setText(QCoreApplication::translate("MainWindow", "1296", nullptr));
        action2304->setText(QCoreApplication::translate("MainWindow", "2304", nullptr));
        actionOnline_Users_Guide->setText(QCoreApplication::translate("MainWindow", "MAP65 Online User's Guide", nullptr));
#if QT_CONFIG(shortcut)
        actionOnline_Users_Guide->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKeyboard_shortcuts->setText(QCoreApplication::translate("MainWindow", "Keyboard shortcuts", nullptr));
        actionSpecial_mouse_commands->setText(QCoreApplication::translate("MainWindow", "Special mouse commands", nullptr));
        actionAvailable_suffixes_and_add_on_prefixes->setText(QCoreApplication::translate("MainWindow", "Available suffixes and add-on-prefixes", nullptr));
        actionErase_map65_tx_log->setText(QCoreApplication::translate("MainWindow", "Erase map65_tx.log", nullptr));
        actionJT65A->setText(QCoreApplication::translate("MainWindow", "JT65A", nullptr));
        actionJT65B->setText(QCoreApplication::translate("MainWindow", "JT65B", nullptr));
        actionJT65C->setText(QCoreApplication::translate("MainWindow", "JT65C", nullptr));
        actionI_Q_Calibration->setText(QCoreApplication::translate("MainWindow", "I/Q Calibration", nullptr));
#if QT_CONFIG(shortcut)
        actionI_Q_Calibration->setShortcut(QCoreApplication::translate("MainWindow", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAdjust_IQ_Calibration->setText(QCoreApplication::translate("MainWindow", "Adjust Rx I/Q Calibration", nullptr));
        actionApply_IQ_Calibration->setText(QCoreApplication::translate("MainWindow", "Apply Rx I/Q Calibration", nullptr));
        actionAFMHot->setText(QCoreApplication::translate("MainWindow", "AFMHot", nullptr));
        actionBlue->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        actionFUNcube_Dongle->setText(QCoreApplication::translate("MainWindow", "FUNcube Dongle Settings", nullptr));
        actionEdit_wsjt_log->setText(QCoreApplication::translate("MainWindow", "Edit wsjt.log", nullptr));
#if QT_CONFIG(shortcut)
        actionEdit_wsjt_log->setShortcut(QCoreApplication::translate("MainWindow", "Alt+Shift+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTx_Tune->setText(QCoreApplication::translate("MainWindow", "Tx Tune", nullptr));
#if QT_CONFIG(shortcut)
        actionTx_Tune->setShortcut(QCoreApplication::translate("MainWindow", "Alt+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDecode_Q65_near_QSO_frequency->setText(QCoreApplication::translate("MainWindow", "Decode Q65 near QSO frequency", nullptr));
        actionQ65A->setText(QCoreApplication::translate("MainWindow", "Q65A", nullptr));
        actionQ65B->setText(QCoreApplication::translate("MainWindow", "Q65B", nullptr));
        actionNoJT65->setText(QCoreApplication::translate("MainWindow", "No JT65", nullptr));
        actionNoQ65->setText(QCoreApplication::translate("MainWindow", "No Q65", nullptr));
        actionQ65C->setText(QCoreApplication::translate("MainWindow", "Q65C", nullptr));
        actionQ65D->setText(QCoreApplication::translate("MainWindow", "Q65D", nullptr));
        actionQ65E->setText(QCoreApplication::translate("MainWindow", "Q65E", nullptr));
        actionQSG_Q65->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to Q65", nullptr));
        actionQSG_MAP65_v3->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to WSJT-X 2.5.0 and MAP65 3.0", nullptr));
        actionQ65_Sensitivity_in_MAP65_3_0->setText(QCoreApplication::translate("MainWindow", "Q65 Sensitivity in MAP65 3.0", nullptr));
        actionRelease_Notes->setText(QCoreApplication::translate("MainWindow", "Release Notes", nullptr));
        actionOpen_MAP65_data_directory->setText(QCoreApplication::translate("MainWindow", "Open EME65 data directory", nullptr));
        actionReduce_false_decodes->setText(QCoreApplication::translate("MainWindow", "Reduce false decodes", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Freq   DF Pol  UTC   DT   dB       Message            RC   DS  TxPol", nullptr));
        decodedTextBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New';\"><br /></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        logQSOButton->setToolTip(QCoreApplication::translate("MainWindow", "Enter this QSO in log", nullptr));
#endif // QT_CONFIG(tooltip)
        logQSOButton->setText(QCoreApplication::translate("MainWindow", "Log &QSO", nullptr));
#if QT_CONFIG(tooltip)
        stopButton->setToolTip(QCoreApplication::translate("MainWindow", "Stop monitoring", nullptr));
#endif // QT_CONFIG(tooltip)
        stopButton->setText(QCoreApplication::translate("MainWindow", "&Stop", nullptr));
#if QT_CONFIG(tooltip)
        monitorButton->setToolTip(QCoreApplication::translate("MainWindow", "Toggle monitoring On/Off", nullptr));
#endif // QT_CONFIG(tooltip)
        monitorButton->setText(QCoreApplication::translate("MainWindow", "&Monitor", nullptr));
#if QT_CONFIG(tooltip)
        DecodeButton->setToolTip(QCoreApplication::translate("MainWindow", "Decode most recent Rx period at QSO Frequency", nullptr));
#endif // QT_CONFIG(tooltip)
        DecodeButton->setText(QCoreApplication::translate("MainWindow", "&Decode", nullptr));
#if QT_CONFIG(tooltip)
        EraseButton->setToolTip(QCoreApplication::translate("MainWindow", "Clear the main window; double-clicking also clears the message window.<br>Right-click to clear the DX Call and DX Grid.", nullptr));
#endif // QT_CONFIG(tooltip)
        EraseButton->setText(QCoreApplication::translate("MainWindow", "&Erase", nullptr));
#if QT_CONFIG(tooltip)
        autoButton->setToolTip(QCoreApplication::translate("MainWindow", "Toggle Auto-Tx On/Off", nullptr));
#endif // QT_CONFIG(tooltip)
        autoButton->setText(QCoreApplication::translate("MainWindow", "Enable Tx", nullptr));
#if QT_CONFIG(tooltip)
        stopTxButton->setToolTip(QCoreApplication::translate("MainWindow", "Stop transmitting immediately", nullptr));
#endif // QT_CONFIG(tooltip)
        stopTxButton->setText(QCoreApplication::translate("MainWindow", "Halt Tx", nullptr));
        dxStationGroupBox->setTitle(QString());
        dxCallEntry->setText(QString());
        dxGridEntry->setText(QString());
        lookupButton->setText(QCoreApplication::translate("MainWindow", "&Lookup", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        genStdMsgsPushButton->setText(QCoreApplication::translate("MainWindow", "&GenStdMsgs", nullptr));
        DX_Grid_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">DX Grid</p></body></html>", nullptr));
        DX_Call_label->setText(QCoreApplication::translate("MainWindow", "DX Call", nullptr));
        labUTC->setText(QCoreApplication::translate("MainWindow", " 2014 Dec 02\n"
"01:23:45 ", nullptr));
        txFirstCheckBox->setText(QCoreApplication::translate("MainWindow", "Tx first", nullptr));
        pbTxMode->setText(QCoreApplication::translate("MainWindow", "Tx Q65  $", nullptr));
        setTxFreqButton->setText(QCoreApplication::translate("MainWindow", "Set Tx Freq", nullptr));
#if QT_CONFIG(tooltip)
        sbMaxDrift->setToolTip(QCoreApplication::translate("MainWindow", "Maximum drift rate in units of symbol rate per transmissiion.", nullptr));
#endif // QT_CONFIG(tooltip)
        sbMaxDrift->setPrefix(QCoreApplication::translate("MainWindow", "Max Drift  ", nullptr));
        NBcheckBox->setText(QCoreApplication::translate("MainWindow", "NB", nullptr));
        labTol1->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        labTol2->setText(QCoreApplication::translate("MainWindow", "Tol", nullptr));
        tx1->setText(QString());
        txrb1->setText(QString());
        txrb2->setText(QString());
        txrb3->setText(QString());
        txrb4->setText(QString());
        txrb5->setText(QString());
        txrb6->setText(QString());
        txb1->setText(QCoreApplication::translate("MainWindow", "Tx1", nullptr));
        txb2->setText(QCoreApplication::translate("MainWindow", "Tx2", nullptr));
        txb3->setText(QCoreApplication::translate("MainWindow", "Tx3", nullptr));
        txb4->setText(QCoreApplication::translate("MainWindow", "Tx4", nullptr));
        txb5->setText(QCoreApplication::translate("MainWindow", "Tx5", nullptr));
        txb6->setText(QCoreApplication::translate("MainWindow", "Tx6", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSetup->setTitle(QCoreApplication::translate("MainWindow", "Setup", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuWaterfall_palette->setTitle(QCoreApplication::translate("MainWindow", "Waterfall palette", nullptr));
        menuCallsign_transparency->setTitle(QCoreApplication::translate("MainWindow", "Callsign transparency", nullptr));
        menuCallsign_font->setTitle(QCoreApplication::translate("MainWindow", "Callsign font size", nullptr));
        menuCallsign_position->setTitle(QCoreApplication::translate("MainWindow", "Callsign position", nullptr));
        menuDecode->setTitle(QCoreApplication::translate("MainWindow", "Decode", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuMode->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        menuWSJT_X->setTitle(QCoreApplication::translate("MainWindow", "WS", nullptr));
        menuInstance_ID->setTitle(QCoreApplication::translate("MainWindow", "Instance ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
