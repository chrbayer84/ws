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
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *astroTextBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cbPointingTests;
    QSpacerItem *horizontalSpacer;
    QGroupBox *gbPointing;
    QGridLayout *gridLayout;
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
        Astro->resize(441, 503);
        gridLayout_2 = new QGridLayout(Astro);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        astroTextBrowser = new QTextBrowser(Astro);
        astroTextBrowser->setObjectName(QString::fromUtf8("astroTextBrowser"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(20);
        font.setBold(true);
        astroTextBrowser->setFont(font);

        verticalLayout->addWidget(astroTextBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cbPointingTests = new QCheckBox(Astro);
        cbPointingTests->setObjectName(QString::fromUtf8("cbPointingTests"));

        horizontalLayout->addWidget(cbPointingTests);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gbPointing = new QGroupBox(Astro);
        gbPointing->setObjectName(QString::fromUtf8("gbPointing"));
        gridLayout = new QGridLayout(gbPointing);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rb6 = new QRadioButton(gbPointing);
        rb6->setObjectName(QString::fromUtf8("rb6"));

        gridLayout->addWidget(rb6, 0, 1, 1, 1);

        rb1 = new QRadioButton(gbPointing);
        rb1->setObjectName(QString::fromUtf8("rb1"));

        gridLayout->addWidget(rb1, 1, 0, 1, 1);

        rb2 = new QRadioButton(gbPointing);
        rb2->setObjectName(QString::fromUtf8("rb2"));
        rb2->setChecked(true);

        gridLayout->addWidget(rb2, 1, 1, 1, 1);

        rb3 = new QRadioButton(gbPointing);
        rb3->setObjectName(QString::fromUtf8("rb3"));

        gridLayout->addWidget(rb3, 1, 2, 1, 1);

        rb4 = new QRadioButton(gbPointing);
        rb4->setObjectName(QString::fromUtf8("rb4"));

        gridLayout->addWidget(rb4, 2, 1, 1, 1);

        sbOffset = new QDoubleSpinBox(gbPointing);
        sbOffset->setObjectName(QString::fromUtf8("sbOffset"));
        sbOffset->setAlignment(Qt::AlignCenter);
        sbOffset->setDecimals(1);
        sbOffset->setMinimum(0.500000000000000);
        sbOffset->setMaximum(20.000000000000000);
        sbOffset->setSingleStep(0.500000000000000);
        sbOffset->setValue(2.500000000000000);

        gridLayout->addWidget(sbOffset, 3, 0, 1, 3);

        sbDwell = new QSpinBox(gbPointing);
        sbDwell->setObjectName(QString::fromUtf8("sbDwell"));
        sbDwell->setAlignment(Qt::AlignCenter);
        sbDwell->setMinimum(10);
        sbDwell->setMaximum(300);
        sbDwell->setSingleStep(10);

        gridLayout->addWidget(sbDwell, 4, 0, 1, 3);

        cbAutoCycle = new QCheckBox(gbPointing);
        cbAutoCycle->setObjectName(QString::fromUtf8("cbAutoCycle"));

        gridLayout->addWidget(cbAutoCycle, 5, 0, 1, 3);

        cbOnOff = new QCheckBox(gbPointing);
        cbOnOff->setObjectName(QString::fromUtf8("cbOnOff"));

        gridLayout->addWidget(cbOnOff, 6, 0, 1, 2);


        gridLayout_2->addWidget(gbPointing, 0, 1, 1, 1);


        retranslateUi(Astro);

        QMetaObject::connectSlotsByName(Astro);
    } // setupUi

    void retranslateUi(QWidget *Astro)
    {
        Astro->setWindowTitle(QCoreApplication::translate("Astro", "Form", nullptr));
        cbPointingTests->setText(QCoreApplication::translate("Astro", "Pointing Tests", nullptr));
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
