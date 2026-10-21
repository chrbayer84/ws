/********************************************************************************
** Form generated from reading UI file 'astro.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTRO_H
#define UI_ASTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Astro
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *astroTextBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cbPointingTests;
    QCheckBox *cbCFOM;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *gbPointing;
    QGridLayout *gridLayout_2;
    QRadioButton *rb6;
    QRadioButton *rb1;
    QRadioButton *rb2;
    QRadioButton *rb3;
    QRadioButton *rb4;
    QDoubleSpinBox *sbOffset;
    QSpinBox *sbDwell;
    QCheckBox *cbAutoCycle;
    QCheckBox *cbOnOff;

    void setupUi(QWidget *Astro)
    {
        if (Astro->objectName().isEmpty())
            Astro->setObjectName(QString::fromUtf8("Astro"));
        Astro->resize(430, 430);
        gridLayout = new QGridLayout(Astro);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        astroTextBrowser = new QTextBrowser(Astro);
        astroTextBrowser->setObjectName(QString::fromUtf8("astroTextBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(astroTextBrowser->sizePolicy().hasHeightForWidth());
        astroTextBrowser->setSizePolicy(sizePolicy);
        astroTextBrowser->setMinimumSize(QSize(0, 0));
        astroTextBrowser->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(20);
        font.setBold(true);
        astroTextBrowser->setFont(font);

        verticalLayout->addWidget(astroTextBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cbPointingTests = new QCheckBox(Astro);
        cbPointingTests->setObjectName(QString::fromUtf8("cbPointingTests"));

        horizontalLayout->addWidget(cbPointingTests);

        cbCFOM = new QCheckBox(Astro);
        cbCFOM->setObjectName(QString::fromUtf8("cbCFOM"));

        horizontalLayout->addWidget(cbCFOM);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        gbPointing = new QGroupBox(Astro);
        gbPointing->setObjectName(QString::fromUtf8("gbPointing"));
        gridLayout_2 = new QGridLayout(gbPointing);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb6 = new QRadioButton(gbPointing);
        rb6->setObjectName(QString::fromUtf8("rb6"));

        gridLayout_2->addWidget(rb6, 0, 1, 1, 1);

        rb1 = new QRadioButton(gbPointing);
        rb1->setObjectName(QString::fromUtf8("rb1"));

        gridLayout_2->addWidget(rb1, 1, 0, 1, 1);

        rb2 = new QRadioButton(gbPointing);
        rb2->setObjectName(QString::fromUtf8("rb2"));
        rb2->setChecked(true);

        gridLayout_2->addWidget(rb2, 1, 1, 1, 1);

        rb3 = new QRadioButton(gbPointing);
        rb3->setObjectName(QString::fromUtf8("rb3"));

        gridLayout_2->addWidget(rb3, 1, 2, 1, 1);

        rb4 = new QRadioButton(gbPointing);
        rb4->setObjectName(QString::fromUtf8("rb4"));

        gridLayout_2->addWidget(rb4, 2, 1, 1, 1);

        sbOffset = new QDoubleSpinBox(gbPointing);
        sbOffset->setObjectName(QString::fromUtf8("sbOffset"));
        sbOffset->setAlignment(Qt::AlignCenter);
        sbOffset->setDecimals(1);
        sbOffset->setMinimum(0.500000000000000);
        sbOffset->setMaximum(20.000000000000000);
        sbOffset->setSingleStep(0.500000000000000);
        sbOffset->setValue(2.500000000000000);

        gridLayout_2->addWidget(sbOffset, 3, 0, 1, 3);

        sbDwell = new QSpinBox(gbPointing);
        sbDwell->setObjectName(QString::fromUtf8("sbDwell"));
        sbDwell->setAlignment(Qt::AlignCenter);
        sbDwell->setMinimum(15);
        sbDwell->setMaximum(300);
        sbDwell->setSingleStep(5);

        gridLayout_2->addWidget(sbDwell, 4, 0, 1, 3);

        cbAutoCycle = new QCheckBox(gbPointing);
        cbAutoCycle->setObjectName(QString::fromUtf8("cbAutoCycle"));

        gridLayout_2->addWidget(cbAutoCycle, 5, 0, 1, 3);

        cbOnOff = new QCheckBox(gbPointing);
        cbOnOff->setObjectName(QString::fromUtf8("cbOnOff"));

        gridLayout_2->addWidget(cbOnOff, 6, 0, 1, 2);


        gridLayout->addWidget(gbPointing, 0, 1, 1, 1);


        retranslateUi(Astro);

        QMetaObject::connectSlotsByName(Astro);
    } // setupUi

    void retranslateUi(QWidget *Astro)
    {
        Astro->setWindowTitle(QCoreApplication::translate("Astro", "Form", nullptr));
        cbPointingTests->setText(QCoreApplication::translate("Astro", "Pointing Tests", nullptr));
#if QT_CONFIG(tooltip)
        cbCFOM->setToolTip(QCoreApplication::translate("Astro", "Apply self-Doppler IQ pre-shift before the long FFT (cfom). Useful when listening for your own EME echoes \342\200\224 the echo lands at the dial instead of being shifted by 2\303\227 one-way Doppler. Off by default.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbCFOM->setText(QCoreApplication::translate("Astro", "CFOM (self-Doppler correct)", nullptr));
        gbPointing->setTitle(QString());
        rb6->setText(QCoreApplication::translate("Astro", "6", nullptr));
        rb1->setText(QCoreApplication::translate("Astro", "1", nullptr));
        rb2->setText(QCoreApplication::translate("Astro", "2, 5", nullptr));
        rb3->setText(QCoreApplication::translate("Astro", "3", nullptr));
        rb4->setText(QCoreApplication::translate("Astro", "4", nullptr));
        sbOffset->setPrefix(QCoreApplication::translate("Astro", "Offset   ", nullptr));
        sbOffset->setSuffix(QCoreApplication::translate("Astro", "  deg", nullptr));
        sbDwell->setSuffix(QCoreApplication::translate("Astro", "   s", nullptr));
        sbDwell->setPrefix(QCoreApplication::translate("Astro", "Dwell   ", nullptr));
        cbAutoCycle->setText(QCoreApplication::translate("Astro", "Auto Cycle", nullptr));
        cbOnOff->setText(QCoreApplication::translate("Astro", "On Off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Astro: public Ui_Astro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTRO_H
