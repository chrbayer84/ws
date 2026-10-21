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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgets/displaytext.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionAstro_Data;
    QAction *actionMessages;
    QAction *actionWide_Waterfall;
    QAction *actionBand_Map;
    QAction *actionOpen;
    QAction *actionOpen_next_in_directory;
    QAction *actionDecode_remaining_files_in_directory;
    QAction *actionDelete_all_iq_files_in_SaveDir;
    QAction *actionErase_Band_Map_and_Messages;
    QAction *actionLinrad;
    QAction *actionCuteSDR;
    QAction *actionFind_Delta_Phi;
    QAction *actionF4_sets_Tx6;
    QAction *actionOnly_EME_calls;
    QAction *actionNo_shorthands_if_Tx1;
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
    QAction *actionAFMHot;
    QAction *actionBlue;
    QAction *actionFUNcube_Dongle;
    QAction *actionEdit_wsjt_log;
    QAction *actionTx_Tune;
    QAction *actionDecode_Q65_near_QSO_frequency;
    QAction *actionQ65A;
    QAction *actionQ65B;
    QAction *actionQ65C;
    QAction *actionQ65D;
    QAction *actionQ65E;
    QAction *actionQSG_Q65;
    QAction *actionRelease_Notes;
    QAction *actionSettings;
    QAction *actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP;
    QAction *actionQuick_Start_Guide_to_Q65;
    QAction *continuous_waterfall;
    QAction *actionAlso_Q65_30x;
    QAction *actionSave_decoded;
    QAction *actionExport_wav_file_at_fQSO;
    QAction *actionExport_wav_file_at_fQSO_30b;
    QAction *actionExport_wav_file_at_fQSO_30a;
    QAction *actionFadd_controls;
    QAction *actionShow_callsigns_on_Waterfall;
    QAction *actionTick_5kHz;
    QAction *actionTick_10kHz;
    QAction *actionTick_20kHz;
    QAction *actionTick_50kHz;
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
    QAction *actionSync_WSJTX;
    QAction *actionOpen_QMAP_data_directory;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    DisplayText *decodedTextBrowser;
    QGridLayout *gridLayout;
    QComboBox *fAddComboBox;
    QLabel *labFreq;
    QPushButton *monitorButton;
    QSlider *NBslider;
    QCheckBox *NBcheckBox;
    QPushButton *EraseButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *labTol1;
    QSpinBox *tolSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbSet;
    QPushButton *pbAdd;
    QSpinBox *sbMaxDrift;
    QLabel *fAdd_label;
    QFrame *xMeterFrame;
    QPushButton *DecodeButton;
    QLabel *labTol2;
    QSpinBox *sbOffset;
    QVBoxLayout *verticalLayout_2;
    QLabel *labUTC;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuWaterfall_palette;
    QMenu *menuTick_spacing;
    QMenu *menuCallsign_transparency;
    QMenu *menuCallsign_font;
    QMenu *menuCallsign_position;
    QMenu *menuSave;
    QMenu *menuHelp;
    QMenu *menuMode;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 431);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(550, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAstro_Data = new QAction(MainWindow);
        actionAstro_Data->setObjectName(QString::fromUtf8("actionAstro_Data"));
        actionMessages = new QAction(MainWindow);
        actionMessages->setObjectName(QString::fromUtf8("actionMessages"));
        actionWide_Waterfall = new QAction(MainWindow);
        actionWide_Waterfall->setObjectName(QString::fromUtf8("actionWide_Waterfall"));
        actionBand_Map = new QAction(MainWindow);
        actionBand_Map->setObjectName(QString::fromUtf8("actionBand_Map"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen_next_in_directory = new QAction(MainWindow);
        actionOpen_next_in_directory->setObjectName(QString::fromUtf8("actionOpen_next_in_directory"));
        actionDecode_remaining_files_in_directory = new QAction(MainWindow);
        actionDecode_remaining_files_in_directory->setObjectName(QString::fromUtf8("actionDecode_remaining_files_in_directory"));
        actionDelete_all_iq_files_in_SaveDir = new QAction(MainWindow);
        actionDelete_all_iq_files_in_SaveDir->setObjectName(QString::fromUtf8("actionDelete_all_iq_files_in_SaveDir"));
        actionErase_Band_Map_and_Messages = new QAction(MainWindow);
        actionErase_Band_Map_and_Messages->setObjectName(QString::fromUtf8("actionErase_Band_Map_and_Messages"));
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
        actionQ65C = new QAction(MainWindow);
        actionQ65C->setObjectName(QString::fromUtf8("actionQ65C"));
        actionQ65C->setCheckable(true);
        actionQ65C->setChecked(true);
        actionQ65D = new QAction(MainWindow);
        actionQ65D->setObjectName(QString::fromUtf8("actionQ65D"));
        actionQ65D->setCheckable(true);
        actionQ65E = new QAction(MainWindow);
        actionQ65E->setObjectName(QString::fromUtf8("actionQ65E"));
        actionQ65E->setCheckable(true);
        actionQSG_Q65 = new QAction(MainWindow);
        actionQSG_Q65->setObjectName(QString::fromUtf8("actionQSG_Q65"));
        actionRelease_Notes = new QAction(MainWindow);
        actionRelease_Notes->setObjectName(QString::fromUtf8("actionRelease_Notes"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP = new QAction(MainWindow);
        actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP->setObjectName(QString::fromUtf8("actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP"));
        actionQuick_Start_Guide_to_Q65 = new QAction(MainWindow);
        actionQuick_Start_Guide_to_Q65->setObjectName(QString::fromUtf8("actionQuick_Start_Guide_to_Q65"));
        continuous_waterfall = new QAction(MainWindow);
        continuous_waterfall->setObjectName(QString::fromUtf8("continuous_waterfall"));
        continuous_waterfall->setCheckable(true);
        actionAlso_Q65_30x = new QAction(MainWindow);
        actionAlso_Q65_30x->setObjectName(QString::fromUtf8("actionAlso_Q65_30x"));
        actionAlso_Q65_30x->setCheckable(true);
        actionAlso_Q65_30x->setChecked(true);
        actionSave_decoded = new QAction(MainWindow);
        actionSave_decoded->setObjectName(QString::fromUtf8("actionSave_decoded"));
        actionSave_decoded->setCheckable(true);
        actionExport_wav_file_at_fQSO = new QAction(MainWindow);
        actionExport_wav_file_at_fQSO->setObjectName(QString::fromUtf8("actionExport_wav_file_at_fQSO"));
        actionExport_wav_file_at_fQSO_30b = new QAction(MainWindow);
        actionExport_wav_file_at_fQSO_30b->setObjectName(QString::fromUtf8("actionExport_wav_file_at_fQSO_30b"));
        actionExport_wav_file_at_fQSO_30a = new QAction(MainWindow);
        actionExport_wav_file_at_fQSO_30a->setObjectName(QString::fromUtf8("actionExport_wav_file_at_fQSO_30a"));
        actionFadd_controls = new QAction(MainWindow);
        actionFadd_controls->setObjectName(QString::fromUtf8("actionFadd_controls"));
        actionFadd_controls->setCheckable(true);
        actionShow_callsigns_on_Waterfall = new QAction(MainWindow);
        actionShow_callsigns_on_Waterfall->setObjectName(QString::fromUtf8("actionShow_callsigns_on_Waterfall"));
        actionShow_callsigns_on_Waterfall->setCheckable(true);
        actionShow_callsigns_on_Waterfall->setChecked(true);
        actionTick_5kHz = new QAction(MainWindow);
        actionTick_5kHz->setObjectName(QString::fromUtf8("actionTick_5kHz"));
        actionTick_5kHz->setCheckable(true);
        actionTick_5kHz->setChecked(true);
        actionTick_10kHz = new QAction(MainWindow);
        actionTick_10kHz->setObjectName(QString::fromUtf8("actionTick_10kHz"));
        actionTick_10kHz->setCheckable(true);
        actionTick_20kHz = new QAction(MainWindow);
        actionTick_20kHz->setObjectName(QString::fromUtf8("actionTick_20kHz"));
        actionTick_20kHz->setCheckable(true);
        actionTick_50kHz = new QAction(MainWindow);
        actionTick_50kHz->setObjectName(QString::fromUtf8("actionTick_50kHz"));
        actionTick_50kHz->setCheckable(true);
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
        actionSync_WSJTX = new QAction(MainWindow);
        actionSync_WSJTX->setObjectName(QString::fromUtf8("actionSync_WSJTX"));
        actionSync_WSJTX->setCheckable(true);
        actionSync_WSJTX->setChecked(true);
        actionOpen_QMAP_data_directory = new QAction(MainWindow);
        actionOpen_QMAP_data_directory->setObjectName(QString::fromUtf8("actionOpen_QMAP_data_directory"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        decodedTextBrowser = new DisplayText(groupBox);
        decodedTextBrowser->setObjectName(QString::fromUtf8("decodedTextBrowser"));
        sizePolicy1.setHeightForWidth(decodedTextBrowser->sizePolicy().hasHeightForWidth());
        decodedTextBrowser->setSizePolicy(sizePolicy1);
        decodedTextBrowser->setMinimumSize(QSize(0, 0));
        decodedTextBrowser->setMaximumSize(QSize(16777215, 16777215));
        decodedTextBrowser->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(10);
        decodedTextBrowser->setFont(font);
        decodedTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        decodedTextBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        decodedTextBrowser->setAcceptRichText(false);

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, decodedTextBrowser);


        formLayout->setWidget(0, QFormLayout::SpanningRole, groupBox);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fAddComboBox = new QComboBox(centralWidget);
        fAddComboBox->setObjectName(QString::fromUtf8("fAddComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fAddComboBox->sizePolicy().hasHeightForWidth());
        fAddComboBox->setSizePolicy(sizePolicy2);
        fAddComboBox->setEditable(true);
        fAddComboBox->setMaxVisibleItems(20);

        gridLayout->addWidget(fAddComboBox, 3, 2, 1, 1);

        labFreq = new QLabel(centralWidget);
        labFreq->setObjectName(QString::fromUtf8("labFreq"));
        labFreq->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(16);
        labFreq->setFont(font1);
        labFreq->setFrameShape(QFrame::Panel);
        labFreq->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labFreq, 1, 1, 1, 1);

        monitorButton = new QPushButton(centralWidget);
        monitorButton->setObjectName(QString::fromUtf8("monitorButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(monitorButton->sizePolicy().hasHeightForWidth());
        monitorButton->setSizePolicy(sizePolicy3);
        monitorButton->setMinimumSize(QSize(0, 0));
        monitorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(monitorButton, 1, 2, 1, 1);

        NBslider = new QSlider(centralWidget);
        NBslider->setObjectName(QString::fromUtf8("NBslider"));
        NBslider->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(NBslider->sizePolicy().hasHeightForWidth());
        NBslider->setSizePolicy(sizePolicy4);
        NBslider->setMaximumSize(QSize(80, 16777215));
        NBslider->setMinimum(0);
        NBslider->setMaximum(100);
        NBslider->setValue(40);
        NBslider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(NBslider, 5, 4, 1, 2);

        NBcheckBox = new QCheckBox(centralWidget);
        NBcheckBox->setObjectName(QString::fromUtf8("NBcheckBox"));

        gridLayout->addWidget(NBcheckBox, 5, 3, 1, 1, Qt::AlignHCenter);

        EraseButton = new QPushButton(centralWidget);
        EraseButton->setObjectName(QString::fromUtf8("EraseButton"));
        EraseButton->setMinimumSize(QSize(0, 0));
        EraseButton->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(EraseButton, 1, 3, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 6, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labTol1 = new QLabel(centralWidget);
        labTol1->setObjectName(QString::fromUtf8("labTol1"));
        sizePolicy.setHeightForWidth(labTol1->sizePolicy().hasHeightForWidth());
        labTol1->setSizePolicy(sizePolicy);
        labTol1->setMinimumSize(QSize(0, 0));
        labTol1->setMaximumSize(QSize(16777215, 16777215));
        labTol1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labTol1);

        tolSpinBox = new QSpinBox(centralWidget);
        tolSpinBox->setObjectName(QString::fromUtf8("tolSpinBox"));
        tolSpinBox->setEnabled(true);
        sizePolicy4.setHeightForWidth(tolSpinBox->sizePolicy().hasHeightForWidth());
        tolSpinBox->setSizePolicy(sizePolicy4);
        tolSpinBox->setMinimumSize(QSize(0, 23));
        tolSpinBox->setMaximumSize(QSize(18, 16777215));
        tolSpinBox->setMinimum(1);
        tolSpinBox->setMaximum(6);
        tolSpinBox->setValue(5);

        horizontalLayout->addWidget(tolSpinBox);

        horizontalLayout->setStretch(0, 3);

        gridLayout->addLayout(horizontalLayout, 2, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbSet = new QPushButton(centralWidget);
        pbSet->setObjectName(QString::fromUtf8("pbSet"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pbSet->sizePolicy().hasHeightForWidth());
        pbSet->setSizePolicy(sizePolicy5);
        pbSet->setMinimumSize(QSize(35, 0));
        pbSet->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(pbSet);

        pbAdd = new QPushButton(centralWidget);
        pbAdd->setObjectName(QString::fromUtf8("pbAdd"));
        sizePolicy5.setHeightForWidth(pbAdd->sizePolicy().hasHeightForWidth());
        pbAdd->setSizePolicy(sizePolicy5);
        pbAdd->setMinimumSize(QSize(35, 0));
        pbAdd->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(pbAdd);


        gridLayout->addLayout(horizontalLayout_2, 4, 2, 1, 1);

        sbMaxDrift = new QSpinBox(centralWidget);
        sbMaxDrift->setObjectName(QString::fromUtf8("sbMaxDrift"));
        sbMaxDrift->setAlignment(Qt::AlignCenter);
        sbMaxDrift->setMaximum(50);
        sbMaxDrift->setSingleStep(5);

        gridLayout->addWidget(sbMaxDrift, 2, 4, 1, 2);

        fAdd_label = new QLabel(centralWidget);
        fAdd_label->setObjectName(QString::fromUtf8("fAdd_label"));
        fAdd_label->setMinimumSize(QSize(0, 0));
        fAdd_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(fAdd_label, 3, 3, 1, 1);

        xMeterFrame = new QFrame(centralWidget);
        xMeterFrame->setObjectName(QString::fromUtf8("xMeterFrame"));
        xMeterFrame->setMinimumSize(QSize(50, 150));
        xMeterFrame->setFrameShape(QFrame::StyledPanel);
        xMeterFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(xMeterFrame, 1, 0, 5, 1);

        DecodeButton = new QPushButton(centralWidget);
        DecodeButton->setObjectName(QString::fromUtf8("DecodeButton"));
        DecodeButton->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(DecodeButton, 1, 5, 1, 1);

        labTol2 = new QLabel(centralWidget);
        labTol2->setObjectName(QString::fromUtf8("labTol2"));
        sizePolicy.setHeightForWidth(labTol2->sizePolicy().hasHeightForWidth());
        labTol2->setSizePolicy(sizePolicy);
        labTol2->setMinimumSize(QSize(0, 0));
        labTol2->setMaximumSize(QSize(16777215, 16777215));
        labTol2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labTol2, 2, 3, 1, 1);

        sbOffset = new QSpinBox(centralWidget);
        sbOffset->setObjectName(QString::fromUtf8("sbOffset"));
        sbOffset->setAlignment(Qt::AlignCenter);
        sbOffset->setMinimum(500);
        sbOffset->setMaximum(2000);
        sbOffset->setSingleStep(100);
        sbOffset->setValue(1500);

        gridLayout->addWidget(sbOffset, 3, 4, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labUTC = new QLabel(centralWidget);
        labUTC->setObjectName(QString::fromUtf8("labUTC"));
        labUTC->setMinimumSize(QSize(140, 0));
        labUTC->setMaximumSize(QSize(16777215, 16777215));
        labUTC->setFont(font1);
        labUTC->setFrameShape(QFrame::Panel);
        labUTC->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labUTC);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 3, 1, 3, 1);

        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnStretch(4, 1);
        gridLayout->setColumnStretch(5, 2);
        gridLayout->setColumnStretch(6, 2);

        formLayout->setLayout(1, QFormLayout::SpanningRole, gridLayout);


        verticalLayout->addLayout(formLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuWaterfall_palette = new QMenu(menuView);
        menuWaterfall_palette->setObjectName(QString::fromUtf8("menuWaterfall_palette"));
        menuTick_spacing = new QMenu(menuView);
        menuTick_spacing->setObjectName(QString::fromUtf8("menuTick_spacing"));
        menuCallsign_transparency = new QMenu(menuView);
        menuCallsign_transparency->setObjectName(QString::fromUtf8("menuCallsign_transparency"));
        menuCallsign_font = new QMenu(menuView);
        menuCallsign_font->setObjectName(QString::fromUtf8("menuCallsign_font"));
        menuCallsign_position = new QMenu(menuView);
        menuCallsign_position->setObjectName(QString::fromUtf8("menuCallsign_position"));
        menuSave = new QMenu(menuBar);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuMode = new QMenu(menuBar);
        menuMode->setObjectName(QString::fromUtf8("menuMode"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuMode->menuAction());
        menuBar->addAction(menuSave->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_next_in_directory);
        menuFile->addAction(actionDecode_remaining_files_in_directory);
        menuFile->addSeparator();
        menuFile->addAction(actionDelete_all_iq_files_in_SaveDir);
        menuFile->addSeparator();
        menuFile->addAction(actionExport_wav_file_at_fQSO);
        menuFile->addAction(actionExport_wav_file_at_fQSO_30a);
        menuFile->addAction(actionExport_wav_file_at_fQSO_30b);
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_QMAP_data_directory);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuView->addAction(actionAstro_Data);
        menuView->addAction(actionWide_Waterfall);
        menuView->addAction(actionBand_Map);
        menuView->addSeparator();
        menuView->addAction(menuWaterfall_palette->menuAction());
        menuView->addAction(menuTick_spacing->menuAction());
        menuView->addSeparator();
        menuView->addAction(continuous_waterfall);
        menuView->addAction(actionFadd_controls);
        menuView->addSeparator();
        menuView->addAction(actionShow_callsigns_on_Waterfall);
        menuView->addAction(menuCallsign_transparency->menuAction());
        menuView->addAction(menuCallsign_font->menuAction());
        menuView->addAction(menuCallsign_position->menuAction());
        menuView->addSeparator();
        menuView->addAction(actionSync_WSJTX);
        menuWaterfall_palette->addAction(actionLinrad);
        menuWaterfall_palette->addAction(actionCuteSDR);
        menuTick_spacing->addAction(actionTick_5kHz);
        menuTick_spacing->addAction(actionTick_10kHz);
        menuTick_spacing->addAction(actionTick_20kHz);
        menuTick_spacing->addAction(actionTick_50kHz);
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
        menuSave->addAction(actionNone);
        menuSave->addAction(actionSave_decoded);
        menuSave->addAction(actionSave_all);
        menuHelp->addAction(actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP);
        menuHelp->addAction(actionQuick_Start_Guide_to_Q65);
        menuHelp->addAction(actionAbout);
        menuMode->addSeparator();
        menuMode->addSeparator();
        menuMode->addAction(actionQ65A);
        menuMode->addAction(actionQ65B);
        menuMode->addAction(actionQ65C);
        menuMode->addAction(actionQ65D);
        menuMode->addAction(actionQ65E);
        menuMode->addSeparator();
        menuMode->addAction(actionAlso_Q65_30x);

        retranslateUi(MainWindow);
        QObject::connect(monitorButton, SIGNAL(toggled(bool)), MainWindow, SLOT(update()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SpecJT   by K1JT", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About WS-MAP", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAstro_Data->setText(QCoreApplication::translate("MainWindow", "Astro Data", nullptr));
#if QT_CONFIG(shortcut)
        actionAstro_Data->setShortcut(QCoreApplication::translate("MainWindow", "Shift+F10", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMessages->setText(QCoreApplication::translate("MainWindow", "Messages", nullptr));
        actionWide_Waterfall->setText(QCoreApplication::translate("MainWindow", "Wideband Waterfall", nullptr));
        actionBand_Map->setText(QCoreApplication::translate("MainWindow", "Band Map", nullptr));
#if QT_CONFIG(tooltip)
        actionBand_Map->setToolTip(QCoreApplication::translate("MainWindow", "Vertical frequency-axis view of recently-decoded stations, retained longer than the waterfall's own callsign overlay (10/15/30 min, configurable in the Band Map window). Click a station the same as on the waterfall or decoded-text list.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionOpen_next_in_directory->setText(QCoreApplication::translate("MainWindow", "Open next in directory", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_next_in_directory->setShortcut(QCoreApplication::translate("MainWindow", "F6", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDecode_remaining_files_in_directory->setText(QCoreApplication::translate("MainWindow", "Decode remaining files in directory", nullptr));
#if QT_CONFIG(shortcut)
        actionDecode_remaining_files_in_directory->setShortcut(QCoreApplication::translate("MainWindow", "Shift+F6", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete_all_iq_files_in_SaveDir->setText(QCoreApplication::translate("MainWindow", "Delete all *.iq and *.qm files in SaveDir", nullptr));
        actionErase_Band_Map_and_Messages->setText(QCoreApplication::translate("MainWindow", "Erase Band Map and Messages", nullptr));
        actionLinrad->setText(QCoreApplication::translate("MainWindow", "Linrad", nullptr));
        actionCuteSDR->setText(QCoreApplication::translate("MainWindow", "CuteSDR", nullptr));
        actionFind_Delta_Phi->setText(QCoreApplication::translate("MainWindow", "Find Delta Phi", nullptr));
        actionF4_sets_Tx6->setText(QCoreApplication::translate("MainWindow", "F4 sets Tx6", nullptr));
        actionOnly_EME_calls->setText(QCoreApplication::translate("MainWindow", "Only EME calls", nullptr));
        actionNo_shorthands_if_Tx1->setText(QCoreApplication::translate("MainWindow", "No shorthand decodes if Tx1", nullptr));
        actionNone->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        actionSave_all->setText(QCoreApplication::translate("MainWindow", "Save all", nullptr));
        action50->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        action144->setText(QCoreApplication::translate("MainWindow", "144", nullptr));
        action222->setText(QCoreApplication::translate("MainWindow", "222", nullptr));
        action432->setText(QCoreApplication::translate("MainWindow", "432", nullptr));
        action1296->setText(QCoreApplication::translate("MainWindow", "1296", nullptr));
        action2304->setText(QCoreApplication::translate("MainWindow", "2304", nullptr));
        actionOnline_Users_Guide->setText(QCoreApplication::translate("MainWindow", "Online User's Guide", nullptr));
#if QT_CONFIG(shortcut)
        actionOnline_Users_Guide->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKeyboard_shortcuts->setText(QCoreApplication::translate("MainWindow", "Keyboard shortcuts", nullptr));
        actionSpecial_mouse_commands->setText(QCoreApplication::translate("MainWindow", "Special mouse commands", nullptr));
        actionAvailable_suffixes_and_add_on_prefixes->setText(QCoreApplication::translate("MainWindow", "Available suffixes and add-on-prefixes", nullptr));
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
        actionQ65A->setText(QCoreApplication::translate("MainWindow", "Q65-60A", nullptr));
        actionQ65B->setText(QCoreApplication::translate("MainWindow", "Q65-60B", nullptr));
        actionQ65C->setText(QCoreApplication::translate("MainWindow", "Q65-60C", nullptr));
        actionQ65D->setText(QCoreApplication::translate("MainWindow", "Q65-60D", nullptr));
        actionQ65E->setText(QCoreApplication::translate("MainWindow", "Q65-60E", nullptr));
        actionQSG_Q65->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to Q65", nullptr));
        actionRelease_Notes->setText(QCoreApplication::translate("MainWindow", "Release Notes", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings ...", nullptr));
#if QT_CONFIG(shortcut)
        actionSettings->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to WSJT-X 2.7 and QMAP", nullptr));
        actionQuick_Start_Guide_to_Q65->setText(QCoreApplication::translate("MainWindow", "Quick-Start Guide to Q65", nullptr));
        continuous_waterfall->setText(QCoreApplication::translate("MainWindow", "Continuous Waterfall", nullptr));
        actionAlso_Q65_30x->setText(QCoreApplication::translate("MainWindow", "Also Q65-30x", nullptr));
        actionSave_decoded->setText(QCoreApplication::translate("MainWindow", "Save decoded", nullptr));
        actionExport_wav_file_at_fQSO->setText(QCoreApplication::translate("MainWindow", "Export .wav file at fQSO (60 s)", nullptr));
        actionExport_wav_file_at_fQSO_30b->setText(QCoreApplication::translate("MainWindow", "Export .wav file at fQSO (30 s, second part)", nullptr));
        actionExport_wav_file_at_fQSO_30a->setText(QCoreApplication::translate("MainWindow", "Export .wav file at fQSO (30 s, first part)", nullptr));
        actionFadd_controls->setText(QCoreApplication::translate("MainWindow", "Fadd controls", nullptr));
        actionShow_callsigns_on_Waterfall->setText(QCoreApplication::translate("MainWindow", "Show callsigns on Waterfall", nullptr));
#if QT_CONFIG(tooltip)
        actionShow_callsigns_on_Waterfall->setToolTip(QCoreApplication::translate("MainWindow", "Mirror of the WideGraph \"Show callsigns\" checkbox. Toggling either one updates the other.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTick_5kHz->setText(QCoreApplication::translate("MainWindow", "5 kHz (default)", nullptr));
        actionTick_10kHz->setText(QCoreApplication::translate("MainWindow", "10 kHz", nullptr));
        actionTick_20kHz->setText(QCoreApplication::translate("MainWindow", "20 kHz", nullptr));
        actionTick_50kHz->setText(QCoreApplication::translate("MainWindow", "50 kHz", nullptr));
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
        actionSync_WSJTX->setText(QCoreApplication::translate("MainWindow", "Click to synchronize WS", nullptr));
#if QT_CONFIG(tooltip)
        actionSync_WSJTX->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Click to transfer Fsked, submode, and TR period to WS; double-click to start a QSO</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpen_QMAP_data_directory->setText(QCoreApplication::translate("MainWindow", "Open WS-MAP data directory", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "      UTC                   Frx              Fsked             DT           dB       Q65-     Message", nullptr));
        decodedTextBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Courier New'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        labFreq->setText(QCoreApplication::translate("MainWindow", "1296.080", nullptr));
#if QT_CONFIG(tooltip)
        monitorButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Toggle monitoring On/Off. <br/>Yellow when saving .qm files.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        monitorButton->setText(QCoreApplication::translate("MainWindow", "&Monitor", nullptr));
        NBcheckBox->setText(QCoreApplication::translate("MainWindow", "NB", nullptr));
#if QT_CONFIG(tooltip)
        EraseButton->setToolTip(QCoreApplication::translate("MainWindow", "Erase window.<br>Right-click to clear the selected callsign.", nullptr));
#endif // QT_CONFIG(tooltip)
        EraseButton->setText(QCoreApplication::translate("MainWindow", "&Erase", nullptr));
        labTol1->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
#if QT_CONFIG(tooltip)
        pbSet->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Set a manually entered Fadd value.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbSet->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
#if QT_CONFIG(tooltip)
        pbAdd->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Add a manually entered Fadd value to the file &quot;fadd.txt&quot;.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
#if QT_CONFIG(tooltip)
        sbMaxDrift->setToolTip(QCoreApplication::translate("MainWindow", "Maximum drift rate in units of symbol rate per transmission.", nullptr));
#endif // QT_CONFIG(tooltip)
        sbMaxDrift->setPrefix(QCoreApplication::translate("MainWindow", "Max Drift  ", nullptr));
        fAdd_label->setText(QCoreApplication::translate("MainWindow", "Fadd", nullptr));
#if QT_CONFIG(tooltip)
        DecodeButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Decode most recent Rx period</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        DecodeButton->setText(QCoreApplication::translate("MainWindow", "&Decode", nullptr));
        labTol2->setText(QCoreApplication::translate("MainWindow", "Tol", nullptr));
#if QT_CONFIG(tooltip)
        sbOffset->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Select offset announced by calling station, or use commonly used value for the band in use. Manually set WS TX and RX offset to same value.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbOffset->setSuffix(QCoreApplication::translate("MainWindow", " Hz", nullptr));
        sbOffset->setPrefix(QCoreApplication::translate("MainWindow", "Offset ", nullptr));
        labUTC->setText(QCoreApplication::translate("MainWindow", " 2023 Feb 02\n"
"01:23:45 ", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuWaterfall_palette->setTitle(QCoreApplication::translate("MainWindow", "Waterfall palette", nullptr));
        menuTick_spacing->setTitle(QCoreApplication::translate("MainWindow", "Wide-waterfall tick spacing", nullptr));
        menuCallsign_transparency->setTitle(QCoreApplication::translate("MainWindow", "Callsign transparency", nullptr));
        menuCallsign_font->setTitle(QCoreApplication::translate("MainWindow", "Callsign font size", nullptr));
        menuCallsign_position->setTitle(QCoreApplication::translate("MainWindow", "Callsign position", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuMode->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
