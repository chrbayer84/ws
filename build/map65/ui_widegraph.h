/********************************************************************************
** Form generated from reading UI file 'widegraph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDEGRAPH_H
#define UI_WIDEGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "plotter.h"

QT_BEGIN_NAMESPACE

class Ui_WideGraph
{
public:
    QVBoxLayout *verticalLayout_2;
    CPlotter *widePlot;
    QLabel *labFreq;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *srLabel;
    QLabel *srValueLabel;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *freqOffsetSpinBox;
    QSpinBox *freqSpanSpinBox;
    QSpinBox *waterfallAvgSpinBox;
    QSpinBox *gainSpinBox;
    QSpinBox *zeroSpinBox;
    QPushButton *autoZeroPushButton;
    QCheckBox *cbSpec2d;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cbLockTxRx;
    QCheckBox *cbFcenter;
    QLineEdit *fCenterLineEdit;
    QPushButton *pbSetRxHardware;

    void setupUi(QDialog *WideGraph)
    {
        if (WideGraph->objectName().isEmpty())
            WideGraph->setObjectName(QString::fromUtf8("WideGraph"));
        WideGraph->resize(1178, 326);
        verticalLayout_2 = new QVBoxLayout(WideGraph);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widePlot = new CPlotter(WideGraph);
        widePlot->setObjectName(QString::fromUtf8("widePlot"));
        widePlot->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widePlot->sizePolicy().hasHeightForWidth());
        widePlot->setSizePolicy(sizePolicy);
        widePlot->setMinimumSize(QSize(400, 200));
        widePlot->setFrameShape(QFrame::StyledPanel);
        widePlot->setFrameShadow(QFrame::Sunken);
        widePlot->setLineWidth(1);
        labFreq = new QLabel(widePlot);
        labFreq->setObjectName(QString::fromUtf8("labFreq"));
        labFreq->setGeometry(QRect(940, 230, 211, 41));
        QFont font;
        font.setPointSize(12);
        labFreq->setFont(font);
        labFreq->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: yellow;\n"
"}"));
        labFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(widePlot);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        srLabel = new QLabel(WideGraph);
        srLabel->setObjectName(QString::fromUtf8("srLabel"));
        srLabel->setAlignment(Qt::AlignRight|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(srLabel);

        srValueLabel = new QLabel(WideGraph);
        srValueLabel->setObjectName(QString::fromUtf8("srValueLabel"));
        srValueLabel->setMinimumSize(QSize(30, 0));
        srValueLabel->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(srValueLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        freqOffsetSpinBox = new QSpinBox(WideGraph);
        freqOffsetSpinBox->setObjectName(QString::fromUtf8("freqOffsetSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(freqOffsetSpinBox->sizePolicy().hasHeightForWidth());
        freqOffsetSpinBox->setSizePolicy(sizePolicy1);
        freqOffsetSpinBox->setMinimumSize(QSize(60, 0));
        freqOffsetSpinBox->setMaximumSize(QSize(16777215, 16777215));
        freqOffsetSpinBox->setMinimum(-24);
        freqOffsetSpinBox->setMaximum(24);
        freqOffsetSpinBox->setSingleStep(1);
        freqOffsetSpinBox->setValue(0);

        horizontalLayout_3->addWidget(freqOffsetSpinBox);

        freqSpanSpinBox = new QSpinBox(WideGraph);
        freqSpanSpinBox->setObjectName(QString::fromUtf8("freqSpanSpinBox"));
        sizePolicy1.setHeightForWidth(freqSpanSpinBox->sizePolicy().hasHeightForWidth());
        freqSpanSpinBox->setSizePolicy(sizePolicy1);
        freqSpanSpinBox->setMinimumSize(QSize(60, 0));
        freqSpanSpinBox->setMaximumSize(QSize(16777215, 16777215));
        freqSpanSpinBox->setMinimum(5);
        freqSpanSpinBox->setMaximum(190);
        freqSpanSpinBox->setSingleStep(5);
        freqSpanSpinBox->setValue(60);

        horizontalLayout_3->addWidget(freqSpanSpinBox);

        waterfallAvgSpinBox = new QSpinBox(WideGraph);
        waterfallAvgSpinBox->setObjectName(QString::fromUtf8("waterfallAvgSpinBox"));
        sizePolicy1.setHeightForWidth(waterfallAvgSpinBox->sizePolicy().hasHeightForWidth());
        waterfallAvgSpinBox->setSizePolicy(sizePolicy1);
        waterfallAvgSpinBox->setMinimumSize(QSize(0, 0));
        waterfallAvgSpinBox->setMaximumSize(QSize(16777215, 16777215));
        waterfallAvgSpinBox->setMinimum(1);
        waterfallAvgSpinBox->setMaximum(20);

        horizontalLayout_3->addWidget(waterfallAvgSpinBox);

        gainSpinBox = new QSpinBox(WideGraph);
        gainSpinBox->setObjectName(QString::fromUtf8("gainSpinBox"));
        sizePolicy1.setHeightForWidth(gainSpinBox->sizePolicy().hasHeightForWidth());
        gainSpinBox->setSizePolicy(sizePolicy1);
        gainSpinBox->setMaximumSize(QSize(16777215, 16777215));
        gainSpinBox->setMinimum(-20);
        gainSpinBox->setMaximum(20);

        horizontalLayout_3->addWidget(gainSpinBox);

        zeroSpinBox = new QSpinBox(WideGraph);
        zeroSpinBox->setObjectName(QString::fromUtf8("zeroSpinBox"));
        sizePolicy1.setHeightForWidth(zeroSpinBox->sizePolicy().hasHeightForWidth());
        zeroSpinBox->setSizePolicy(sizePolicy1);
        zeroSpinBox->setMaximumSize(QSize(16777215, 16777215));
        zeroSpinBox->setMinimum(-100);
        zeroSpinBox->setMaximum(100);

        horizontalLayout_3->addWidget(zeroSpinBox);

        autoZeroPushButton = new QPushButton(WideGraph);
        autoZeroPushButton->setObjectName(QString::fromUtf8("autoZeroPushButton"));

        horizontalLayout_3->addWidget(autoZeroPushButton);

        cbSpec2d = new QCheckBox(WideGraph);
        cbSpec2d->setObjectName(QString::fromUtf8("cbSpec2d"));

        horizontalLayout_3->addWidget(cbSpec2d);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cbLockTxRx = new QCheckBox(WideGraph);
        cbLockTxRx->setObjectName(QString::fromUtf8("cbLockTxRx"));

        horizontalLayout_3->addWidget(cbLockTxRx);

        cbFcenter = new QCheckBox(WideGraph);
        cbFcenter->setObjectName(QString::fromUtf8("cbFcenter"));

        horizontalLayout_3->addWidget(cbFcenter);

        fCenterLineEdit = new QLineEdit(WideGraph);
        fCenterLineEdit->setObjectName(QString::fromUtf8("fCenterLineEdit"));
        fCenterLineEdit->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fCenterLineEdit->sizePolicy().hasHeightForWidth());
        fCenterLineEdit->setSizePolicy(sizePolicy2);
        fCenterLineEdit->setMaximumSize(QSize(65, 16777215));

        horizontalLayout_3->addWidget(fCenterLineEdit);

        pbSetRxHardware = new QPushButton(WideGraph);
        pbSetRxHardware->setObjectName(QString::fromUtf8("pbSetRxHardware"));
        pbSetRxHardware->setEnabled(false);

        horizontalLayout_3->addWidget(pbSetRxHardware);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(WideGraph);

        QMetaObject::connectSlotsByName(WideGraph);
    } // setupUi

    void retranslateUi(QDialog *WideGraph)
    {
        WideGraph->setWindowTitle(QCoreApplication::translate("WideGraph", "Dialog", nullptr));
        labFreq->setText(QCoreApplication::translate("WideGraph", "Rx:  144.118.200\n"
"Tx:  144.127.317", nullptr));
        srLabel->setText(QCoreApplication::translate("WideGraph", "SR", nullptr));
        srValueLabel->setText(QCoreApplication::translate("WideGraph", "96", nullptr));
        freqOffsetSpinBox->setSuffix(QCoreApplication::translate("WideGraph", " kHz", nullptr));
        freqOffsetSpinBox->setPrefix(QCoreApplication::translate("WideGraph", "Offset ", nullptr));
        freqSpanSpinBox->setSuffix(QCoreApplication::translate("WideGraph", " kHz", nullptr));
        freqSpanSpinBox->setPrefix(QCoreApplication::translate("WideGraph", "Span ", nullptr));
        waterfallAvgSpinBox->setPrefix(QCoreApplication::translate("WideGraph", "N Avg ", nullptr));
        gainSpinBox->setPrefix(QCoreApplication::translate("WideGraph", "Gain ", nullptr));
        zeroSpinBox->setPrefix(QCoreApplication::translate("WideGraph", "Zero ", nullptr));
        autoZeroPushButton->setText(QCoreApplication::translate("WideGraph", "Auto Zero", nullptr));
        cbSpec2d->setText(QCoreApplication::translate("WideGraph", "2D Spectrum", nullptr));
        cbLockTxRx->setText(QCoreApplication::translate("WideGraph", "Lock Tx=Rx Freq", nullptr));
        cbFcenter->setText(QCoreApplication::translate("WideGraph", "Force Center Freq (MHz)", nullptr));
        fCenterLineEdit->setText(QCoreApplication::translate("WideGraph", "1296.065", nullptr));
        pbSetRxHardware->setText(QCoreApplication::translate("WideGraph", "Set Rx Freq", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WideGraph: public Ui_WideGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDEGRAPH_H
