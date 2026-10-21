/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CAboutDlg
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labelTxt;

    void setupUi(QDialog *CAboutDlg)
    {
        if (CAboutDlg->objectName().isEmpty())
            CAboutDlg->setObjectName(QString::fromUtf8("CAboutDlg"));
        CAboutDlg->setWindowModality(Qt::NonModal);
        CAboutDlg->resize(374, 164);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CAboutDlg->sizePolicy().hasHeightForWidth());
        CAboutDlg->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(CAboutDlg);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelTxt = new QLabel(CAboutDlg);
        labelTxt->setObjectName(QString::fromUtf8("labelTxt"));

        horizontalLayout->addWidget(labelTxt);


        retranslateUi(CAboutDlg);

        QMetaObject::connectSlotsByName(CAboutDlg);
    } // setupUi

    void retranslateUi(QDialog *CAboutDlg)
    {
        CAboutDlg->setWindowTitle(QCoreApplication::translate("CAboutDlg", "About WS-MAP", nullptr));
        labelTxt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CAboutDlg: public Ui_CAboutDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
