/********************************************************************************
** Form generated from reading UI file 'astro.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTRO_H
#define UI_ASTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mycustomspinbox.h>

QT_BEGIN_NAMESPACE

class Ui_Astro
{
public:
    QGridLayout *gridLayout;
    QWidget *doppler_widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *dt_groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbFullTrack;
    QRadioButton *rbOwnEcho;
    QRadioButton *rbConstFreqOnMoon;
    QRadioButton *rbOnDxEcho;
    QRadioButton *rbCallDx;
    QRadioButton *rbNoDoppler;
    QGroupBox *sf_groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_sf;
    QLabel *label;
    QLabel *sked_frequency_label;
    QLabel *label_2;
    QLabel *sked_tx_frequency_label;
    QHBoxLayout *horizontalLayout_sf1;
    MyCustomSpinBox *sbSked_kHz;
    QPushButton *pbSet;
    QHBoxLayout *horizontalLayout_sf2;
    QSpinBox *sbibShift;
    QCheckBox *cbEnableShift;
    QGroupBox *em_groupBox;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_em;
    QSpinBox *sbRIT;
    QCheckBox *cbDither;
    QHBoxLayout *horizontalLayout_locksSkedFreq;
    QCheckBox *cbLockSkedFreq;
    QVBoxLayout *verticalLayout_3;
    QLabel *text_label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbDopplerTracking;

    void setupUi(QWidget *Astro)
    {
        if (Astro->objectName().isEmpty())
            Astro->setObjectName(QString::fromUtf8("Astro"));
        Astro->resize(343, 451);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Astro->sizePolicy().hasHeightForWidth());
        Astro->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Astro);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        doppler_widget = new QWidget(Astro);
        doppler_widget->setObjectName(QString::fromUtf8("doppler_widget"));
        doppler_widget->setStyleSheet(QString::fromUtf8("* {\n"
"	font-weight: normal;\n"
"}"));
        verticalLayout = new QVBoxLayout(doppler_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 0, 3);
        dt_groupBox = new QGroupBox(doppler_widget);
        dt_groupBox->setObjectName(QString::fromUtf8("dt_groupBox"));
        verticalLayout_2 = new QVBoxLayout(dt_groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 6, -1);
        rbFullTrack = new QRadioButton(dt_groupBox);
        rbFullTrack->setObjectName(QString::fromUtf8("rbFullTrack"));
        rbFullTrack->setChecked(true);

        verticalLayout_2->addWidget(rbFullTrack);

        rbOwnEcho = new QRadioButton(dt_groupBox);
        rbOwnEcho->setObjectName(QString::fromUtf8("rbOwnEcho"));

        verticalLayout_2->addWidget(rbOwnEcho);

        rbConstFreqOnMoon = new QRadioButton(dt_groupBox);
        rbConstFreqOnMoon->setObjectName(QString::fromUtf8("rbConstFreqOnMoon"));
        rbConstFreqOnMoon->setChecked(false);

        verticalLayout_2->addWidget(rbConstFreqOnMoon);

        rbOnDxEcho = new QRadioButton(dt_groupBox);
        rbOnDxEcho->setObjectName(QString::fromUtf8("rbOnDxEcho"));
        rbOnDxEcho->setChecked(false);

        verticalLayout_2->addWidget(rbOnDxEcho);

        rbCallDx = new QRadioButton(dt_groupBox);
        rbCallDx->setObjectName(QString::fromUtf8("rbCallDx"));
        rbCallDx->setChecked(false);

        verticalLayout_2->addWidget(rbCallDx);

        rbNoDoppler = new QRadioButton(dt_groupBox);
        rbNoDoppler->setObjectName(QString::fromUtf8("rbNoDoppler"));
        rbNoDoppler->setChecked(false);

        verticalLayout_2->addWidget(rbNoDoppler);


        verticalLayout->addWidget(dt_groupBox);

        sf_groupBox = new QGroupBox(doppler_widget);
        sf_groupBox->setObjectName(QString::fromUtf8("sf_groupBox"));
        sf_groupBox->setEnabled(true);
        gridLayout_2 = new QGridLayout(sf_groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, 6, -1);
        gridLayout_sf = new QGridLayout();
        gridLayout_sf->setObjectName(QString::fromUtf8("gridLayout_sf"));
        gridLayout_sf->setHorizontalSpacing(6);
        label = new QLabel(sf_groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));

        gridLayout_sf->addWidget(label, 0, 0, 1, 1);

        sked_frequency_label = new QLabel(sf_groupBox);
        sked_frequency_label->setObjectName(QString::fromUtf8("sked_frequency_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sked_frequency_label->sizePolicy().hasHeightForWidth());
        sked_frequency_label->setSizePolicy(sizePolicy1);
        sked_frequency_label->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));
        sked_frequency_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_sf->addWidget(sked_frequency_label, 0, 1, 1, 1);

        label_2 = new QLabel(sf_groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));

        gridLayout_sf->addWidget(label_2, 1, 0, 1, 1);

        sked_tx_frequency_label = new QLabel(sf_groupBox);
        sked_tx_frequency_label->setObjectName(QString::fromUtf8("sked_tx_frequency_label"));
        sizePolicy1.setHeightForWidth(sked_tx_frequency_label->sizePolicy().hasHeightForWidth());
        sked_tx_frequency_label->setSizePolicy(sizePolicy1);
        sked_tx_frequency_label->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));
        sked_tx_frequency_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_sf->addWidget(sked_tx_frequency_label, 1, 1, 1, 1);

        gridLayout_sf->setColumnStretch(1, 1);

        gridLayout_2->addLayout(gridLayout_sf, 3, 0, 1, 2);

        horizontalLayout_sf1 = new QHBoxLayout();
        horizontalLayout_sf1->setObjectName(QString::fromUtf8("horizontalLayout_sf1"));
        sbSked_kHz = new MyCustomSpinBox(sf_groupBox);
        sbSked_kHz->setObjectName(QString::fromUtf8("sbSked_kHz"));
        sbSked_kHz->setMinimumSize(QSize(0, 0));
        sbSked_kHz->setAlignment(Qt::AlignCenter);
        sbSked_kHz->setMaximum(999);
        sbSked_kHz->setValue(65);

        horizontalLayout_sf1->addWidget(sbSked_kHz);

        pbSet = new QPushButton(sf_groupBox);
        pbSet->setObjectName(QString::fromUtf8("pbSet"));
        pbSet->setMinimumSize(QSize(0, 0));
        pbSet->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_sf1->addWidget(pbSet);

        horizontalLayout_sf1->setStretch(0, 1);
        horizontalLayout_sf1->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_sf1, 0, 0, 1, 2);

        horizontalLayout_sf2 = new QHBoxLayout();
        horizontalLayout_sf2->setObjectName(QString::fromUtf8("horizontalLayout_sf2"));
        sbibShift = new QSpinBox(sf_groupBox);
        sbibShift->setObjectName(QString::fromUtf8("sbibShift"));
        sbibShift->setMinimumSize(QSize(0, 0));
        sbibShift->setAlignment(Qt::AlignCenter);
        sbibShift->setMinimum(-30);
        sbibShift->setMaximum(30);
        sbibShift->setSingleStep(1);
        sbibShift->setValue(0);

        horizontalLayout_sf2->addWidget(sbibShift);

        cbEnableShift = new QCheckBox(sf_groupBox);
        cbEnableShift->setObjectName(QString::fromUtf8("cbEnableShift"));
        cbEnableShift->setEnabled(true);
        sizePolicy.setHeightForWidth(cbEnableShift->sizePolicy().hasHeightForWidth());
        cbEnableShift->setSizePolicy(sizePolicy);

        horizontalLayout_sf2->addWidget(cbEnableShift, 0, Qt::AlignRight);


        gridLayout_2->addLayout(horizontalLayout_sf2, 4, 0, 1, 2);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        verticalLayout->addWidget(sf_groupBox);

        em_groupBox = new QGroupBox(doppler_widget);
        em_groupBox->setObjectName(QString::fromUtf8("em_groupBox"));
        em_groupBox->setMinimumSize(QSize(0, 0));
        horizontalLayout_3 = new QHBoxLayout(em_groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 6, -1);
        horizontalLayout_em = new QHBoxLayout();
        horizontalLayout_em->setObjectName(QString::fromUtf8("horizontalLayout_em"));
        sbRIT = new QSpinBox(em_groupBox);
        sbRIT->setObjectName(QString::fromUtf8("sbRIT"));
        sbRIT->setEnabled(false);
        sizePolicy1.setHeightForWidth(sbRIT->sizePolicy().hasHeightForWidth());
        sbRIT->setSizePolicy(sizePolicy1);
        sbRIT->setAlignment(Qt::AlignCenter);
        sbRIT->setMinimum(-20000);
        sbRIT->setMaximum(20000);
        sbRIT->setSingleStep(100);

        horizontalLayout_em->addWidget(sbRIT);

        cbDither = new QCheckBox(em_groupBox);
        cbDither->setObjectName(QString::fromUtf8("cbDither"));
        sizePolicy.setHeightForWidth(cbDither->sizePolicy().hasHeightForWidth());
        cbDither->setSizePolicy(sizePolicy);

        horizontalLayout_em->addWidget(cbDither, 0, Qt::AlignRight);


        horizontalLayout_3->addLayout(horizontalLayout_em);


        verticalLayout->addWidget(em_groupBox);

        horizontalLayout_locksSkedFreq = new QHBoxLayout();
        horizontalLayout_locksSkedFreq->setObjectName(QString::fromUtf8("horizontalLayout_locksSkedFreq"));
        horizontalLayout_locksSkedFreq->setContentsMargins(9, -1, -1, -1);
        cbLockSkedFreq = new QCheckBox(doppler_widget);
        cbLockSkedFreq->setObjectName(QString::fromUtf8("cbLockSkedFreq"));
        sizePolicy.setHeightForWidth(cbLockSkedFreq->sizePolicy().hasHeightForWidth());
        cbLockSkedFreq->setSizePolicy(sizePolicy);

        horizontalLayout_locksSkedFreq->addWidget(cbLockSkedFreq);


        verticalLayout->addLayout(horizontalLayout_locksSkedFreq);


        gridLayout->addWidget(doppler_widget, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        text_label = new QLabel(Astro);
        text_label->setObjectName(QString::fromUtf8("text_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(text_label->sizePolicy().hasHeightForWidth());
        text_label->setSizePolicy(sizePolicy2);
        text_label->setStyleSheet(QString::fromUtf8("* {\n"
"	font-family: Courier;\n"
"	font-size: 12pt;\n"
"	font-weight: bold;\n"
"}"));
        text_label->setFrameShadow(QFrame::Sunken);
        text_label->setAlignment(Qt::AlignCenter);
        text_label->setMargin(6);

        verticalLayout_3->addWidget(text_label, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbDopplerTracking = new QCheckBox(Astro);
        cbDopplerTracking->setObjectName(QString::fromUtf8("cbDopplerTracking"));
        cbDopplerTracking->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(cbDopplerTracking);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(Astro);

        QMetaObject::connectSlotsByName(Astro);
    } // setupUi

    void retranslateUi(QWidget *Astro)
    {
        dt_groupBox->setTitle(QCoreApplication::translate("Astro", "Doppler tracking", nullptr));
#if QT_CONFIG(tooltip)
        rbFullTrack->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>One station does all Doppler shift correction, their QSO partner receives and transmits on the sked frequency.</p><p>If the rig does not accept CAT QSY commands while transmitting a single correction is applied for the whole transmit period.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbFullTrack->setText(QCoreApplication::translate("Astro", "Full Doppler to DX Grid", nullptr));
#if QT_CONFIG(tooltip)
        rbOwnEcho->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>Transmit takes place on sked frequency and receive frequency is  corrected for own echoes. </p><p>This mode can be used for calling CQ, or when using Echo mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbOwnEcho->setText(QCoreApplication::translate("Astro", "Own Echo", nullptr));
#if QT_CONFIG(tooltip)
        rbConstFreqOnMoon->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>Both stations correct for Doppler shift such that they would be heard on the moon at the sked frequency.</p><p>If the rig does not accept CAT QSY commands while transmitting a single correction is applied for the whole transmit period.</p><p>Use this option also for Echo mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbConstFreqOnMoon->setText(QCoreApplication::translate("Astro", "Constant frequency on Moon", nullptr));
#if QT_CONFIG(tooltip)
        rbOnDxEcho->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>DX station announces their TX Freq, which is entered as the Sked Freq. Correction applied to RX and TX so you appear on the DX's station's own echo Freq.</p><p>If the rig does not accept CAT QSY commands while transmitting a single correction is applied for the whole transmit period.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbOnDxEcho->setText(QCoreApplication::translate("Astro", "On DX Echo", nullptr));
#if QT_CONFIG(tooltip)
        rbCallDx->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>Tune radio manually and select this mode to put your echo on the same frequency.</p><p>If the rig does not accept CAT QSY commands while transmitting a single correction is applied for the whole transmit period.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbCallDx->setText(QCoreApplication::translate("Astro", "Call DX", nullptr));
#if QT_CONFIG(tooltip)
        rbNoDoppler->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>No Doppler shift correction is applied. This may be used when the QSO partner does full Doppler correction to your grid square.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbNoDoppler->setText(QCoreApplication::translate("Astro", "None", nullptr));
        sf_groupBox->setTitle(QCoreApplication::translate("Astro", "Sked frequency", nullptr));
        label->setText(QCoreApplication::translate("Astro", "Rx:", nullptr));
        sked_frequency_label->setText(QCoreApplication::translate("Astro", "0", nullptr));
        label_2->setText(QCoreApplication::translate("Astro", "Tx:", nullptr));
        sked_tx_frequency_label->setText(QCoreApplication::translate("Astro", "0", nullptr));
        sbSked_kHz->setSuffix(QCoreApplication::translate("Astro", "  kHz", nullptr));
        pbSet->setText(QCoreApplication::translate("Astro", "Set kHz", nullptr));
#if QT_CONFIG(tooltip)
        sbibShift->setToolTip(QCoreApplication::translate("Astro", "<html><head/><body><p>Tx shift relative to Rx sked frequency</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbibShift->setSuffix(QCoreApplication::translate("Astro", "  MHz", nullptr));
        sbibShift->setPrefix(QCoreApplication::translate("Astro", "Tx Shift  ", nullptr));
        cbEnableShift->setText(QCoreApplication::translate("Astro", "Enable", nullptr));
        em_groupBox->setTitle(QCoreApplication::translate("Astro", "Echo Mode", nullptr));
        sbRIT->setSuffix(QCoreApplication::translate("Astro", "  Hz", nullptr));
        sbRIT->setPrefix(QCoreApplication::translate("Astro", "RIT  ", nullptr));
        cbDither->setText(QCoreApplication::translate("Astro", "Dither ", nullptr));
        cbLockSkedFreq->setText(QCoreApplication::translate("Astro", "Ctl-Lock Sked Freq", nullptr));
        text_label->setText(QCoreApplication::translate("Astro", "Astro Data", nullptr));
        cbDopplerTracking->setText(QCoreApplication::translate("Astro", "Doppler tracking", nullptr));
        (void)Astro;
    } // retranslateUi

};

namespace Ui {
    class Astro: public Ui_Astro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTRO_H
