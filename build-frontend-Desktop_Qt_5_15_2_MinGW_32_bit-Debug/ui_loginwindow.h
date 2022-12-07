/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineUsername;
    QLineEdit *linePin;
    QPushButton *btnKirjaudu;
    QPushButton *btnPoistu;
    QLabel *labelInfo;

    void setupUi(QDialog *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QString::fromUtf8("loginWindow"));
        loginWindow->resize(751, 511);
        loginWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        label = new QLabel(loginWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 90, 241, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::WinPanel);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(loginWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 220, 241, 61));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setAlignment(Qt::AlignCenter);
        lineUsername = new QLineEdit(loginWindow);
        lineUsername->setObjectName(QString::fromUtf8("lineUsername"));
        lineUsername->setGeometry(QRect(440, 90, 211, 61));
        lineUsername->setFont(font);
        lineUsername->setCursor(QCursor(Qt::IBeamCursor));
        lineUsername->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        linePin = new QLineEdit(loginWindow);
        linePin->setObjectName(QString::fromUtf8("linePin"));
        linePin->setGeometry(QRect(440, 220, 211, 61));
        linePin->setFont(font);
        linePin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        linePin->setEchoMode(QLineEdit::Password);
        btnKirjaudu = new QPushButton(loginWindow);
        btnKirjaudu->setObjectName(QString::fromUtf8("btnKirjaudu"));
        btnKirjaudu->setGeometry(QRect(210, 410, 101, 31));
        btnKirjaudu->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        btnPoistu = new QPushButton(loginWindow);
        btnPoistu->setObjectName(QString::fromUtf8("btnPoistu"));
        btnPoistu->setGeometry(QRect(440, 410, 101, 31));
        btnPoistu->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        labelInfo = new QLabel(loginWindow);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(170, 330, 451, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        labelInfo->setFont(font1);
        labelInfo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QDialog *loginWindow)
    {
        loginWindow->setWindowTitle(QCoreApplication::translate("loginWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("loginWindow", "K\303\244ytt\303\244j\303\244tunnus", nullptr));
        label_2->setText(QCoreApplication::translate("loginWindow", "Pin", nullptr));
        btnKirjaudu->setText(QCoreApplication::translate("loginWindow", "Kirjaudu", nullptr));
        btnPoistu->setText(QCoreApplication::translate("loginWindow", "Poistu", nullptr));
        labelInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
