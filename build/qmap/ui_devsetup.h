/********************************************************************************
** Form generated from reading UI file 'devsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVSETUP_H
#define UI_DEVSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSndCard
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *ioTabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *myCallEntry;
    QLineEdit *myGridEntry;
    QSpinBox *astroFont;
    QComboBox *myCallColor;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QLabel *label_11;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QSpinBox *fCalSpinBox;
    QLineEdit *faddEntry;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLineEdit *saveDirEntry;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *azelDirEntry;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *sb_dB;
    QSpacerItem *horizontalSpacer_11;
    QSpinBox *sbPort;
    QLabel *label_Port;
    QHBoxLayout *horizontalLayout_iqRate;
    QLabel *label_iqRate;
    QComboBox *cbSampleRateMode;
    QLabel *label_iqRateRestart;
    QHBoxLayout *horizontalLayout_linradEndpoint;
    QLabel *label_linradHost;
    QLineEdit *leLinradHost;
    QLabel *label_linradTcpPort;
    QSpinBox *sbLinradTcpPort;
    QSpacerItem *horizontalSpacer;
    QGroupBox *gbLiveCQ;
    QGridLayout *gridLayout_3;
    QHBoxLayout *hlLiveCQW3SZ;
    QCheckBox *cbLiveCQOfficial;
    QComboBox *cbLiveCQW3SZAppId;
    QCheckBox *cbLiveCQN6NU;
    QCheckBox *cbLiveCQCustom;
    QLineEdit *otherUrlBox;
    QCheckBox *cbSpotPSK;
    QCheckBox *cbSpotPSKTcpIp;
    QGroupBox *groupBox_instance;
    QHBoxLayout *horizontalLayout_instance;
    QLabel *label_instanceId;
    QSpinBox *sbInstanceId;
    QSpacerItem *horizontalSpacer_instance;
    QLabel *label_configName;
    QLineEdit *leConfigName;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSndCard)
    {
        if (DialogSndCard->objectName().isEmpty())
            DialogSndCard->setObjectName(QString::fromUtf8("DialogSndCard"));
        DialogSndCard->resize(400, 268);
        gridLayout_2 = new QGridLayout(DialogSndCard);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ioTabWidget = new QTabWidget(DialogSndCard);
        ioTabWidget->setObjectName(QString::fromUtf8("ioTabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(label_2);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        myCallEntry = new QLineEdit(tab);
        myCallEntry->setObjectName(QString::fromUtf8("myCallEntry"));
        myCallEntry->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(myCallEntry);

        myGridEntry = new QLineEdit(tab);
        myGridEntry->setObjectName(QString::fromUtf8("myGridEntry"));
        myGridEntry->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(myGridEntry);

        astroFont = new QSpinBox(tab);
        astroFont->setObjectName(QString::fromUtf8("astroFont"));
        astroFont->setMinimum(12);
        astroFont->setMaximum(32);
        astroFont->setValue(20);

        verticalLayout_3->addWidget(astroFont);

        myCallColor = new QComboBox(tab);
        myCallColor->setObjectName(QString::fromUtf8("myCallColor"));

        verticalLayout_3->addWidget(myCallColor);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 0));

        verticalLayout_4->addWidget(label_9);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 0));

        verticalLayout_4->addWidget(label_11);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        fCalSpinBox = new QSpinBox(tab);
        fCalSpinBox->setObjectName(QString::fromUtf8("fCalSpinBox"));
        fCalSpinBox->setMinimum(-50000);
        fCalSpinBox->setMaximum(50000);

        verticalLayout_5->addWidget(fCalSpinBox);

        faddEntry = new QLineEdit(tab);
        faddEntry->setObjectName(QString::fromUtf8("faddEntry"));

        verticalLayout_5->addWidget(faddEntry);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(label_10);

        saveDirEntry = new QLineEdit(tab);
        saveDirEntry->setObjectName(QString::fromUtf8("saveDirEntry"));

        horizontalLayout_3->addWidget(saveDirEntry);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(label_6);

        azelDirEntry = new QLineEdit(tab);
        azelDirEntry->setObjectName(QString::fromUtf8("azelDirEntry"));

        horizontalLayout_4->addWidget(azelDirEntry);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_6);

        ioTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(true);
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        sb_dB = new QSpinBox(groupBox_2);
        sb_dB->setObjectName(QString::fromUtf8("sb_dB"));
        sb_dB->setEnabled(true);
        sb_dB->setMinimum(-50);
        sb_dB->setMaximum(50);
        sb_dB->setSingleStep(1);

        horizontalLayout_8->addWidget(sb_dB);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        sbPort = new QSpinBox(groupBox_2);
        sbPort->setObjectName(QString::fromUtf8("sbPort"));
        sbPort->setMinimumSize(QSize(57, 0));
        sbPort->setMinimum(20000);
        sbPort->setMaximum(51000);
        sbPort->setValue(50004);

        horizontalLayout_8->addWidget(sbPort);

        label_Port = new QLabel(groupBox_2);
        label_Port->setObjectName(QString::fromUtf8("label_Port"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Port->sizePolicy().hasHeightForWidth());
        label_Port->setSizePolicy(sizePolicy1);
        label_Port->setMinimumSize(QSize(0, 0));
        label_Port->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(label_Port);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_iqRate = new QHBoxLayout();
        horizontalLayout_iqRate->setObjectName(QString::fromUtf8("horizontalLayout_iqRate"));
        label_iqRate = new QLabel(groupBox_2);
        label_iqRate->setObjectName(QString::fromUtf8("label_iqRate"));

        horizontalLayout_iqRate->addWidget(label_iqRate);

        cbSampleRateMode = new QComboBox(groupBox_2);
        cbSampleRateMode->addItem(QString());
        cbSampleRateMode->addItem(QString());
        cbSampleRateMode->addItem(QString());
        cbSampleRateMode->addItem(QString());
        cbSampleRateMode->addItem(QString());
        cbSampleRateMode->setObjectName(QString::fromUtf8("cbSampleRateMode"));

        horizontalLayout_iqRate->addWidget(cbSampleRateMode);

        label_iqRateRestart = new QLabel(groupBox_2);
        label_iqRateRestart->setObjectName(QString::fromUtf8("label_iqRateRestart"));
        label_iqRateRestart->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_iqRate->addWidget(label_iqRateRestart);


        verticalLayout_7->addLayout(horizontalLayout_iqRate);

        horizontalLayout_linradEndpoint = new QHBoxLayout();
        horizontalLayout_linradEndpoint->setObjectName(QString::fromUtf8("horizontalLayout_linradEndpoint"));
        label_linradHost = new QLabel(groupBox_2);
        label_linradHost->setObjectName(QString::fromUtf8("label_linradHost"));

        horizontalLayout_linradEndpoint->addWidget(label_linradHost);

        leLinradHost = new QLineEdit(groupBox_2);
        leLinradHost->setObjectName(QString::fromUtf8("leLinradHost"));

        horizontalLayout_linradEndpoint->addWidget(leLinradHost);

        label_linradTcpPort = new QLabel(groupBox_2);
        label_linradTcpPort->setObjectName(QString::fromUtf8("label_linradTcpPort"));

        horizontalLayout_linradEndpoint->addWidget(label_linradTcpPort);

        sbLinradTcpPort = new QSpinBox(groupBox_2);
        sbLinradTcpPort->setObjectName(QString::fromUtf8("sbLinradTcpPort"));
        sbLinradTcpPort->setMinimum(1024);
        sbLinradTcpPort->setMaximum(65535);
        sbLinradTcpPort->setValue(49812);

        horizontalLayout_linradEndpoint->addWidget(sbLinradTcpPort);


        verticalLayout_7->addLayout(horizontalLayout_linradEndpoint);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);


        verticalLayout_8->addWidget(groupBox_2);


        gridLayout_4->addLayout(verticalLayout_8, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 1, 1, 1);

        gbLiveCQ = new QGroupBox(tab_2);
        gbLiveCQ->setObjectName(QString::fromUtf8("gbLiveCQ"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbLiveCQ->sizePolicy().hasHeightForWidth());
        gbLiveCQ->setSizePolicy(sizePolicy2);
        gbLiveCQ->setCheckable(true);
        gbLiveCQ->setChecked(true);
        gridLayout_3 = new QGridLayout(gbLiveCQ);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        hlLiveCQW3SZ = new QHBoxLayout();
        hlLiveCQW3SZ->setObjectName(QString::fromUtf8("hlLiveCQW3SZ"));
        cbLiveCQOfficial = new QCheckBox(gbLiveCQ);
        cbLiveCQOfficial->setObjectName(QString::fromUtf8("cbLiveCQOfficial"));
        cbLiveCQOfficial->setChecked(false);

        hlLiveCQW3SZ->addWidget(cbLiveCQOfficial);

        cbLiveCQW3SZAppId = new QComboBox(gbLiveCQ);
        cbLiveCQW3SZAppId->addItem(QString());
        cbLiveCQW3SZAppId->addItem(QString());
        cbLiveCQW3SZAppId->setObjectName(QString::fromUtf8("cbLiveCQW3SZAppId"));

        hlLiveCQW3SZ->addWidget(cbLiveCQW3SZAppId);


        gridLayout_3->addLayout(hlLiveCQW3SZ, 0, 0, 1, 2);

        cbLiveCQN6NU = new QCheckBox(gbLiveCQ);
        cbLiveCQN6NU->setObjectName(QString::fromUtf8("cbLiveCQN6NU"));
        cbLiveCQN6NU->setChecked(true);

        gridLayout_3->addWidget(cbLiveCQN6NU, 1, 0, 1, 2);

        cbLiveCQCustom = new QCheckBox(gbLiveCQ);
        cbLiveCQCustom->setObjectName(QString::fromUtf8("cbLiveCQCustom"));

        gridLayout_3->addWidget(cbLiveCQCustom, 2, 0, 1, 1);

        otherUrlBox = new QLineEdit(gbLiveCQ);
        otherUrlBox->setObjectName(QString::fromUtf8("otherUrlBox"));

        gridLayout_3->addWidget(otherUrlBox, 2, 1, 1, 1);


        gridLayout_4->addWidget(gbLiveCQ, 1, 0, 1, 2);

        cbSpotPSK = new QCheckBox(tab_2);
        cbSpotPSK->setObjectName(QString::fromUtf8("cbSpotPSK"));

        gridLayout_4->addWidget(cbSpotPSK, 2, 0, 1, 2);

        cbSpotPSKTcpIp = new QCheckBox(tab_2);
        cbSpotPSKTcpIp->setObjectName(QString::fromUtf8("cbSpotPSKTcpIp"));

        gridLayout_4->addWidget(cbSpotPSKTcpIp, 3, 0, 1, 2);

        groupBox_instance = new QGroupBox(tab_2);
        groupBox_instance->setObjectName(QString::fromUtf8("groupBox_instance"));
        sizePolicy2.setHeightForWidth(groupBox_instance->sizePolicy().hasHeightForWidth());
        groupBox_instance->setSizePolicy(sizePolicy2);
        horizontalLayout_instance = new QHBoxLayout(groupBox_instance);
        horizontalLayout_instance->setObjectName(QString::fromUtf8("horizontalLayout_instance"));
        label_instanceId = new QLabel(groupBox_instance);
        label_instanceId->setObjectName(QString::fromUtf8("label_instanceId"));

        horizontalLayout_instance->addWidget(label_instanceId);

        sbInstanceId = new QSpinBox(groupBox_instance);
        sbInstanceId->setObjectName(QString::fromUtf8("sbInstanceId"));
        sbInstanceId->setMinimum(1);
        sbInstanceId->setMaximum(4);
        sbInstanceId->setValue(1);

        horizontalLayout_instance->addWidget(sbInstanceId);

        horizontalSpacer_instance = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_instance->addItem(horizontalSpacer_instance);

        label_configName = new QLabel(groupBox_instance);
        label_configName->setObjectName(QString::fromUtf8("label_configName"));

        horizontalLayout_instance->addWidget(label_configName);

        leConfigName = new QLineEdit(groupBox_instance);
        leConfigName->setObjectName(QString::fromUtf8("leConfigName"));

        horizontalLayout_instance->addWidget(leConfigName);


        gridLayout_4->addWidget(groupBox_instance, 4, 0, 1, 2);

        ioTabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(ioTabWidget, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogSndCard);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(DialogSndCard);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSndCard, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSndCard, SLOT(reject()));

        ioTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogSndCard);
    } // setupUi

    void retranslateUi(QDialog *DialogSndCard)
    {
        DialogSndCard->setWindowTitle(QCoreApplication::translate("DialogSndCard", "Settings", nullptr));
        label->setText(QCoreApplication::translate("DialogSndCard", "My Call:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSndCard", "My Grid:", nullptr));
        label_7->setText(QCoreApplication::translate("DialogSndCard", "Astro Font Size:", nullptr));
        label_3->setText(QCoreApplication::translate("DialogSndCard", "Highlight My Call:", nullptr));
        myCallEntry->setText(QCoreApplication::translate("DialogSndCard", "K1JT", nullptr));
        myGridEntry->setText(QCoreApplication::translate("DialogSndCard", "FN20qi", nullptr));
        label_9->setText(QCoreApplication::translate("DialogSndCard", "Fcal (Hz):", nullptr));
        label_11->setText(QCoreApplication::translate("DialogSndCard", "Fadd (MHz)", nullptr));
        faddEntry->setText(QCoreApplication::translate("DialogSndCard", "0.0", nullptr));
        label_10->setText(QCoreApplication::translate("DialogSndCard", "Save Directory:", nullptr));
        saveDirEntry->setText(QString());
        label_6->setText(QCoreApplication::translate("DialogSndCard", "AzEl Directory:", nullptr));
        azelDirEntry->setText(QString());
        ioTabWidget->setTabText(ioTabWidget->indexOf(tab), QCoreApplication::translate("DialogSndCard", "Station", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogSndCard", "Input from Linrad or SDR Console", nullptr));
#if QT_CONFIG(tooltip)
        sb_dB->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Adjust to scale digital I/Q data.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sb_dB->setSuffix(QCoreApplication::translate("DialogSndCard", "  dB", nullptr));
        sb_dB->setPrefix(QCoreApplication::translate("DialogSndCard", "Gain  ", nullptr));
#if QT_CONFIG(tooltip)
        sbPort->setToolTip(QCoreApplication::translate("DialogSndCard", "Linrad UDP data port. The bridge sends IQ packets here. Default 50004; change for multi-instance setups (each WS-MAP needs its own port matched by the bridge's --linrad-port). Restart WS-MAP to apply.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_Port->setText(QCoreApplication::translate("DialogSndCard", "Port", nullptr));
        label_iqRate->setText(QCoreApplication::translate("DialogSndCard", "IQ sample rate", nullptr));
        cbSampleRateMode->setItemText(0, QCoreApplication::translate("DialogSndCard", "Auto (detect from bridge)", nullptr));
        cbSampleRateMode->setItemText(1, QCoreApplication::translate("DialogSndCard", "96 kHz", nullptr));
        cbSampleRateMode->setItemText(2, QCoreApplication::translate("DialogSndCard", "128 kHz", nullptr));
        cbSampleRateMode->setItemText(3, QCoreApplication::translate("DialogSndCard", "192 kHz", nullptr));
        cbSampleRateMode->setItemText(4, QCoreApplication::translate("DialogSndCard", "256 kHz", nullptr));

#if QT_CONFIG(tooltip)
        cbSampleRateMode->setToolTip(QCoreApplication::translate("DialogSndCard", "Linrad IQ sample rate. 'Auto' detects from the bridge's TCP handshake at startup. Manual values override. Rates >96 kHz need a wide-capable bridge build (--linrad-rate <hz>). Restart WS-MAP to apply.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_iqRateRestart->setText(QCoreApplication::translate("DialogSndCard", "(restart to apply)", nullptr));
        label_linradHost->setText(QCoreApplication::translate("DialogSndCard", "Linrad host", nullptr));
#if QT_CONFIG(tooltip)
        leLinradHost->setToolTip(QCoreApplication::translate("DialogSndCard", "Bridge hostname or IP for Linrad UDP data and TCP parameter handshake. Default 127.0.0.1 (loopback). Restart WS-MAP to apply.", nullptr));
#endif // QT_CONFIG(tooltip)
        leLinradHost->setText(QCoreApplication::translate("DialogSndCard", "127.0.0.1", nullptr));
        label_linradTcpPort->setText(QCoreApplication::translate("DialogSndCard", "TCP port", nullptr));
#if QT_CONFIG(tooltip)
        sbLinradTcpPort->setToolTip(QCoreApplication::translate("DialogSndCard", "Linrad parameter-server TCP port. WS-MAP queries it at startup to auto-detect the bridge's IQ rate. Default 49812. Restart WS-MAP to apply.", nullptr));
#endif // QT_CONFIG(tooltip)
        gbLiveCQ->setTitle(QCoreApplication::translate("DialogSndCard", "Upload decodes to LiveCQ", nullptr));
#if QT_CONFIG(tooltip)
        gbLiveCQ->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Master switch for LiveCQ spotting: each CQ decode is uploaded to every enabled destination.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbLiveCQOfficial->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Send CQ spots to the W3SZ LiveCQ at w3sz.com.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbLiveCQOfficial->setText(QCoreApplication::translate("DialogSndCard", "W3SZ (w3sz.com)", nullptr));
        cbLiveCQW3SZAppId->setItemText(0, QCoreApplication::translate("DialogSndCard", "QMAP", nullptr));
        cbLiveCQW3SZAppId->setItemText(1, QCoreApplication::translate("DialogSndCard", "WSMAP", nullptr));

#if QT_CONFIG(tooltip)
        cbLiveCQW3SZAppId->setToolTip(QCoreApplication::translate("DialogSndCard", "Program name reported to w3sz.com: QMAP, as before the re-branding, or WSMAP. N6NU and custom destinations always receive WSMAP.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbLiveCQN6NU->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Send CQ spots to LiveCQ at livecq.n6nu.org.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbLiveCQN6NU->setText(QCoreApplication::translate("DialogSndCard", "N6NU (livecq.n6nu.org)", nullptr));
#if QT_CONFIG(tooltip)
        cbLiveCQCustom->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Send CQ spots to your own LiveCQ endpoint. Does nothing while the URL field is empty.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbLiveCQCustom->setText(QCoreApplication::translate("DialogSndCard", "Custom:", nullptr));
#if QT_CONFIG(tooltip)
        otherUrlBox->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Full URL of your own LiveCQ endpoint, e.g. http://localhost:3000/api/livecq_update</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        otherUrlBox->setText(QString());
#if QT_CONFIG(tooltip)
        cbSpotPSK->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Send the stations WS-MAP decodes, with your callsign and grid, to PSK Reporter (pskreporter.info). Only live decodes that carry a locator or a CQ are sent, never decodes from recorded files. Needs My Call and My Grid.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbSpotPSK->setText(QCoreApplication::translate("DialogSndCard", "Spot decodes to PSK Reporter", nullptr));
#if QT_CONFIG(tooltip)
        cbSpotPSKTcpIp->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Send the spots to PSK Reporter over a TCP/IP connection instead of UDP datagrams. Try this when spots do not reach PSK Reporter, for example behind a firewall that blocks UDP.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbSpotPSKTcpIp->setText(QCoreApplication::translate("DialogSndCard", "Use TCP/IP for PSK Reporter", nullptr));
        groupBox_instance->setTitle(QCoreApplication::translate("DialogSndCard", "Multi-Instance Identity", nullptr));
#if QT_CONFIG(tooltip)
        label_instanceId->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Identifies this WS-MAP instance (1-4). Change ID 1 (default) only for multi-instance operation.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_instanceId->setText(QCoreApplication::translate("DialogSndCard", "Instance ID", nullptr));
#if QT_CONFIG(tooltip)
        sbInstanceId->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Identifies this WS-MAP instance (1-4). Change ID 1 (default) only for multi-instance operation.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_configName->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Free-text label for this WS-MAP instance. Shown in the window title.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_configName->setText(QCoreApplication::translate("DialogSndCard", "Name", nullptr));
#if QT_CONFIG(tooltip)
        leConfigName->setToolTip(QCoreApplication::translate("DialogSndCard", "<html><head/><body><p>Free-text label for this WS-MAP instance. Shown in the window title.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ioTabWidget->setTabText(ioTabWidget->indexOf(tab_2), QCoreApplication::translate("DialogSndCard", "I/O Devices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSndCard: public Ui_DialogSndCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVSETUP_H
