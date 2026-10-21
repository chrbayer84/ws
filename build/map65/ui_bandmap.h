/********************************************************************************
** Form generated from reading UI file 'bandmap.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANDMAP_H
#define UI_BANDMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "displaytext.h"

QT_BEGIN_NAMESPACE

class Ui_BandMap
{
public:
    QGridLayout *gridLayout;
    DisplayText *bmTextBrowser;

    void setupUi(QWidget *BandMap)
    {
        if (BandMap->objectName().isEmpty())
            BandMap->setObjectName(QString::fromUtf8("BandMap"));
        BandMap->resize(329, 379);
        BandMap->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(BandMap);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bmTextBrowser = new DisplayText(BandMap);
        bmTextBrowser->setObjectName(QString::fromUtf8("bmTextBrowser"));
        bmTextBrowser->setMinimumSize(QSize(107, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(9);
        bmTextBrowser->setFont(font);

        gridLayout->addWidget(bmTextBrowser, 0, 0, 1, 1);


        retranslateUi(BandMap);

        QMetaObject::connectSlotsByName(BandMap);
    } // setupUi

    void retranslateUi(QWidget *BandMap)
    {
        BandMap->setWindowTitle(QCoreApplication::translate("BandMap", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BandMap: public Ui_BandMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANDMAP_H
