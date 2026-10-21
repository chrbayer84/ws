/********************************************************************************
** Form generated from reading UI file 'messages.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "displaytext.h"

QT_BEGIN_NAMESPACE

class Ui_Messages
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lab1;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cbCQstar;
    QCheckBox *cbCQ;
    DisplayText *messagesTextBrowser;

    void setupUi(QDialog *Messages)
    {
        if (Messages->objectName().isEmpty())
            Messages->setObjectName(QString::fromUtf8("Messages"));
        Messages->resize(399, 595);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Messages->sizePolicy().hasHeightForWidth());
        Messages->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Messages);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lab1 = new QLabel(Messages);
        lab1->setObjectName(QString::fromUtf8("lab1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lab1->sizePolicy().hasHeightForWidth());
        lab1->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lab1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cbCQstar = new QCheckBox(Messages);
        cbCQstar->setObjectName(QString::fromUtf8("cbCQstar"));

        horizontalLayout->addWidget(cbCQstar);

        cbCQ = new QCheckBox(Messages);
        cbCQ->setObjectName(QString::fromUtf8("cbCQ"));

        horizontalLayout->addWidget(cbCQ);


        verticalLayout->addLayout(horizontalLayout);

        messagesTextBrowser = new DisplayText(Messages);
        messagesTextBrowser->setObjectName(QString::fromUtf8("messagesTextBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(messagesTextBrowser->sizePolicy().hasHeightForWidth());
        messagesTextBrowser->setSizePolicy(sizePolicy2);
        messagesTextBrowser->setMinimumSize(QSize(340, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(9);
        messagesTextBrowser->setFont(font);

        verticalLayout->addWidget(messagesTextBrowser);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Messages);

        QMetaObject::connectSlotsByName(Messages);
    } // setupUi

    void retranslateUi(QDialog *Messages)
    {
        Messages->setWindowTitle(QCoreApplication::translate("Messages", "Dialog", nullptr));
        lab1->setText(QCoreApplication::translate("Messages", " Freq     DF     Pol     UTC       dB", nullptr));
        cbCQstar->setText(QCoreApplication::translate("Messages", "CQ* Only", nullptr));
        cbCQ->setText(QCoreApplication::translate("Messages", "CQ Only", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Messages: public Ui_Messages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGES_H
