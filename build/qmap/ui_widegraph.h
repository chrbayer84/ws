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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *cbFreqSpanMode;
    QSpinBox *freqSpanValueSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *waterfallAvgSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *gainSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *zeroSpinBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *autoZeroPushButton;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *cbSpec2d;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labFreq;
    QSpacerItem *horizontalSpacer_iqRate;
    QLabel *labIqRate;
    QSpacerItem *horizontalSpacer;

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

        verticalLayout_2->addWidget(widePlot);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        cbFreqSpanMode = new QComboBox(WideGraph);
        cbFreqSpanMode->addItem(QString());
        cbFreqSpanMode->addItem(QString());
        cbFreqSpanMode->addItem(QString());
        cbFreqSpanMode->addItem(QString());
        cbFreqSpanMode->setObjectName(QString::fromUtf8("cbFreqSpanMode"));

        horizontalLayout_3->addWidget(cbFreqSpanMode);

        freqSpanValueSpinBox = new QSpinBox(WideGraph);
        freqSpanValueSpinBox->setObjectName(QString::fromUtf8("freqSpanValueSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(freqSpanValueSpinBox->sizePolicy().hasHeightForWidth());
        freqSpanValueSpinBox->setSizePolicy(sizePolicy1);
        freqSpanValueSpinBox->setMinimumSize(QSize(70, 0));
        freqSpanValueSpinBox->setMinimum(90);
        freqSpanValueSpinBox->setMaximum(256);
        freqSpanValueSpinBox->setSingleStep(5);
        freqSpanValueSpinBox->setValue(96);

        horizontalLayout_3->addWidget(freqSpanValueSpinBox);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        waterfallAvgSpinBox = new QSpinBox(WideGraph);
        waterfallAvgSpinBox->setObjectName(QString::fromUtf8("waterfallAvgSpinBox"));
        sizePolicy1.setHeightForWidth(waterfallAvgSpinBox->sizePolicy().hasHeightForWidth());
        waterfallAvgSpinBox->setSizePolicy(sizePolicy1);
        waterfallAvgSpinBox->setMinimumSize(QSize(0, 0));
        waterfallAvgSpinBox->setMaximumSize(QSize(16777215, 16777215));
        waterfallAvgSpinBox->setMinimum(1);
        waterfallAvgSpinBox->setMaximum(20);

        horizontalLayout_3->addWidget(waterfallAvgSpinBox);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        gainSpinBox = new QSpinBox(WideGraph);
        gainSpinBox->setObjectName(QString::fromUtf8("gainSpinBox"));
        sizePolicy1.setHeightForWidth(gainSpinBox->sizePolicy().hasHeightForWidth());
        gainSpinBox->setSizePolicy(sizePolicy1);
        gainSpinBox->setMaximumSize(QSize(16777215, 16777215));
        gainSpinBox->setMinimum(-20);
        gainSpinBox->setMaximum(20);

        horizontalLayout_3->addWidget(gainSpinBox);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        zeroSpinBox = new QSpinBox(WideGraph);
        zeroSpinBox->setObjectName(QString::fromUtf8("zeroSpinBox"));
        sizePolicy1.setHeightForWidth(zeroSpinBox->sizePolicy().hasHeightForWidth());
        zeroSpinBox->setSizePolicy(sizePolicy1);
        zeroSpinBox->setMaximumSize(QSize(16777215, 16777215));
        zeroSpinBox->setMinimum(-100);
        zeroSpinBox->setMaximum(100);

        horizontalLayout_3->addWidget(zeroSpinBox);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        autoZeroPushButton = new QPushButton(WideGraph);
        autoZeroPushButton->setObjectName(QString::fromUtf8("autoZeroPushButton"));

        horizontalLayout_3->addWidget(autoZeroPushButton);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        cbSpec2d = new QCheckBox(WideGraph);
        cbSpec2d->setObjectName(QString::fromUtf8("cbSpec2d"));

        horizontalLayout_3->addWidget(cbSpec2d);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        labFreq = new QLabel(WideGraph);
        labFreq->setObjectName(QString::fromUtf8("labFreq"));

        horizontalLayout_3->addWidget(labFreq);

        horizontalSpacer_iqRate = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_iqRate);

        labIqRate = new QLabel(WideGraph);
        labIqRate->setObjectName(QString::fromUtf8("labIqRate"));

        horizontalLayout_3->addWidget(labIqRate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 1);

        retranslateUi(WideGraph);

        QMetaObject::connectSlotsByName(WideGraph);
    } // setupUi

    void retranslateUi(QDialog *WideGraph)
    {
        WideGraph->setWindowTitle(QCoreApplication::translate("WideGraph", "Dialog", nullptr));
        cbFreqSpanMode->setItemText(0, QCoreApplication::translate("WideGraph", "Span Auto", nullptr));
        cbFreqSpanMode->setItemText(1, QCoreApplication::translate("WideGraph", "Span 96", nullptr));
        cbFreqSpanMode->setItemText(2, QCoreApplication::translate("WideGraph", "Span 256", nullptr));
        cbFreqSpanMode->setItemText(3, QCoreApplication::translate("WideGraph", "Span User", nullptr));

#if QT_CONFIG(tooltip)
        cbFreqSpanMode->setToolTip(QCoreApplication::translate("WideGraph", "Span: Auto follows the active IQ rate; 96 / 256 select fixed widths (chosen value persists even when WS-MAP runs at a smaller rate); User enables the editable value to the right.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        freqSpanValueSpinBox->setToolTip(QCoreApplication::translate("WideGraph", "Editable in User mode (90..256 kHz). Read-only in Auto/96/256.", nullptr));
#endif // QT_CONFIG(tooltip)
        freqSpanValueSpinBox->setSuffix(QCoreApplication::translate("WideGraph", " kHz", nullptr));
        waterfallAvgSpinBox->setPrefix(QCoreApplication::translate("WideGraph", "N Avg ", nullptr));
        gainSpinBox->setPrefix(QCoreApplication::translate("WideGraph", "Gain ", nullptr));
        zeroSpinBox->setPrefix(QCoreApplication::translate("WideGraph", "Zero ", nullptr));
        autoZeroPushButton->setText(QCoreApplication::translate("WideGraph", "Auto Zero", nullptr));
        cbSpec2d->setText(QCoreApplication::translate("WideGraph", "2D Spectrum", nullptr));
        labFreq->setText(QCoreApplication::translate("WideGraph", "<html><head/><body><p>Center freq:   1296.065.000</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        labIqRate->setToolTip(QCoreApplication::translate("WideGraph", "Active Linrad IQ sample rate. 'auto' = detected from bridge handshake; 'manual' = forced via INI/CLI.", nullptr));
#endif // QT_CONFIG(tooltip)
        labIqRate->setText(QCoreApplication::translate("WideGraph", "IQ rate: \342\200\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WideGraph: public Ui_WideGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDEGRAPH_H
