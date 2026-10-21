/********************************************************************************
** Form generated from reading UI file 'txtune.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TXTUNE_H
#define UI_TXTUNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TxTune
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *pwrSlider;
    QCheckBox *cbTxImage;
    QLabel *labAmp;
    QSlider *ampSlider;
    QLabel *labFineAmp;
    QSlider *fineAmpSlider;
    QLabel *labPha;
    QSlider *phaSlider;
    QLabel *labFinePha;
    QSlider *finePhaSlider;
    QLabel *labAmpReal;
    QLabel *labPhaReal;
    QPushButton *pbTune;
    QLabel *labPower;

    void setupUi(QDialog *TxTune)
    {
        if (TxTune->objectName().isEmpty())
            TxTune->setObjectName(QString::fromUtf8("TxTune"));
        TxTune->resize(400, 300);
        buttonBox = new QDialogButtonBox(TxTune);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        widget = new QWidget(TxTune);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(13, 38, 351, 191));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pwrSlider = new QSlider(widget);
        pwrSlider->setObjectName(QString::fromUtf8("pwrSlider"));
        pwrSlider->setMaximum(100);
        pwrSlider->setValue(100);
        pwrSlider->setOrientation(Qt::Horizontal);
        pwrSlider->setTickPosition(QSlider::TicksBelow);
        pwrSlider->setTickInterval(10);

        gridLayout->addWidget(pwrSlider, 0, 1, 1, 1);

        cbTxImage = new QCheckBox(widget);
        cbTxImage->setObjectName(QString::fromUtf8("cbTxImage"));

        gridLayout->addWidget(cbTxImage, 1, 0, 1, 2);

        labAmp = new QLabel(widget);
        labAmp->setObjectName(QString::fromUtf8("labAmp"));
        labAmp->setEnabled(false);
        labAmp->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(labAmp, 2, 0, 1, 1);

        ampSlider = new QSlider(widget);
        ampSlider->setObjectName(QString::fromUtf8("ampSlider"));
        ampSlider->setEnabled(false);
        ampSlider->setMinimum(-100);
        ampSlider->setMaximum(100);
        ampSlider->setValue(0);
        ampSlider->setOrientation(Qt::Horizontal);
        ampSlider->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(ampSlider, 2, 1, 1, 1);

        labFineAmp = new QLabel(widget);
        labFineAmp->setObjectName(QString::fromUtf8("labFineAmp"));
        labFineAmp->setEnabled(false);
        labFineAmp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labFineAmp, 3, 0, 1, 1);

        fineAmpSlider = new QSlider(widget);
        fineAmpSlider->setObjectName(QString::fromUtf8("fineAmpSlider"));
        fineAmpSlider->setEnabled(false);
        fineAmpSlider->setMinimum(-100);
        fineAmpSlider->setMaximum(100);
        fineAmpSlider->setOrientation(Qt::Horizontal);
        fineAmpSlider->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(fineAmpSlider, 3, 1, 1, 1);

        labPha = new QLabel(widget);
        labPha->setObjectName(QString::fromUtf8("labPha"));
        labPha->setEnabled(false);
        labPha->setMinimumSize(QSize(70, 0));
        labPha->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labPha, 4, 0, 1, 1);

        phaSlider = new QSlider(widget);
        phaSlider->setObjectName(QString::fromUtf8("phaSlider"));
        phaSlider->setEnabled(false);
        phaSlider->setMinimum(-100);
        phaSlider->setMaximum(100);
        phaSlider->setValue(0);
        phaSlider->setOrientation(Qt::Horizontal);
        phaSlider->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(phaSlider, 4, 1, 1, 1);

        labFinePha = new QLabel(widget);
        labFinePha->setObjectName(QString::fromUtf8("labFinePha"));
        labFinePha->setEnabled(false);
        labFinePha->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labFinePha, 5, 0, 1, 1);

        finePhaSlider = new QSlider(widget);
        finePhaSlider->setObjectName(QString::fromUtf8("finePhaSlider"));
        finePhaSlider->setEnabled(false);
        finePhaSlider->setMinimum(-100);
        finePhaSlider->setMaximum(100);
        finePhaSlider->setOrientation(Qt::Horizontal);
        finePhaSlider->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(finePhaSlider, 5, 1, 1, 1);

        labAmpReal = new QLabel(widget);
        labAmpReal->setObjectName(QString::fromUtf8("labAmpReal"));
        labAmpReal->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labAmpReal, 2, 2, 1, 1);

        labPhaReal = new QLabel(widget);
        labPhaReal->setObjectName(QString::fromUtf8("labPhaReal"));
        labPhaReal->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labPhaReal, 4, 2, 1, 1);

        pbTune = new QPushButton(widget);
        pbTune->setObjectName(QString::fromUtf8("pbTune"));

        gridLayout->addWidget(pbTune, 1, 2, 1, 1);

        labPower = new QLabel(widget);
        labPower->setObjectName(QString::fromUtf8("labPower"));
        labPower->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labPower, 0, 2, 1, 1);


        retranslateUi(TxTune);
        QObject::connect(buttonBox, SIGNAL(accepted()), TxTune, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TxTune, SLOT(reject()));

        QMetaObject::connectSlotsByName(TxTune);
    } // setupUi

    void retranslateUi(QDialog *TxTune)
    {
        TxTune->setWindowTitle(QCoreApplication::translate("TxTune", "Tx Tune", nullptr));
        label->setText(QCoreApplication::translate("TxTune", "Tx Power:", nullptr));
        cbTxImage->setText(QCoreApplication::translate("TxTune", "Enable Tx I/Q Adjustment", nullptr));
        labAmp->setText(QCoreApplication::translate("TxTune", "I/Q Amplitude:", nullptr));
        labFineAmp->setText(QCoreApplication::translate("TxTune", "Fine:", nullptr));
        labPha->setText(QCoreApplication::translate("TxTune", "I/Q Phase:", nullptr));
        labFinePha->setText(QCoreApplication::translate("TxTune", "Fine:", nullptr));
        labAmpReal->setText(QCoreApplication::translate("TxTune", "1.0000", nullptr));
        labPhaReal->setText(QCoreApplication::translate("TxTune", "0.000", nullptr));
        pbTune->setText(QCoreApplication::translate("TxTune", "Tune", nullptr));
        labPower->setText(QCoreApplication::translate("TxTune", "100 %", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TxTune: public Ui_TxTune {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TXTUNE_H
