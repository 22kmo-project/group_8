/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_menuWindow
{
public:
    QPushButton *pushButton_Saldo;
    QPushButton *pushButton_Tilitapahtumat;
    QPushButton *pushButton_Otto;
    QPushButton *pushButton_LuottorajanNosto;
    QLabel *labelCardnumber;
    QPushButton *pushButton_KirjauduUlos;

    void setupUi(QDialog *menuWindow)
    {
        if (menuWindow->objectName().isEmpty())
            menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuWindow->resize(749, 527);
        menuWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        pushButton_Saldo = new QPushButton(menuWindow);
        pushButton_Saldo->setObjectName(QString::fromUtf8("pushButton_Saldo"));
        pushButton_Saldo->setGeometry(QRect(80, 90, 121, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        pushButton_Saldo->setFont(font);
        pushButton_Saldo->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        pushButton_Tilitapahtumat = new QPushButton(menuWindow);
        pushButton_Tilitapahtumat->setObjectName(QString::fromUtf8("pushButton_Tilitapahtumat"));
        pushButton_Tilitapahtumat->setGeometry(QRect(400, 90, 171, 51));
        pushButton_Tilitapahtumat->setFont(font);
        pushButton_Tilitapahtumat->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        pushButton_Otto = new QPushButton(menuWindow);
        pushButton_Otto->setObjectName(QString::fromUtf8("pushButton_Otto"));
        pushButton_Otto->setGeometry(QRect(90, 260, 121, 51));
        pushButton_Otto->setFont(font);
        pushButton_Otto->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        pushButton_LuottorajanNosto = new QPushButton(menuWindow);
        pushButton_LuottorajanNosto->setObjectName(QString::fromUtf8("pushButton_LuottorajanNosto"));
        pushButton_LuottorajanNosto->setGeometry(QRect(370, 260, 241, 51));
        pushButton_LuottorajanNosto->setFont(font);
        pushButton_LuottorajanNosto->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        labelCardnumber = new QLabel(menuWindow);
        labelCardnumber->setObjectName(QString::fromUtf8("labelCardnumber"));
        labelCardnumber->setGeometry(QRect(80, 50, 131, 21));
        labelCardnumber->setFont(font);
        labelCardnumber->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        pushButton_KirjauduUlos = new QPushButton(menuWindow);
        pushButton_KirjauduUlos->setObjectName(QString::fromUtf8("pushButton_KirjauduUlos"));
        pushButton_KirjauduUlos->setGeometry(QRect(230, 380, 201, 51));
        pushButton_KirjauduUlos->setFont(font);
        pushButton_KirjauduUlos->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(menuWindow);

        QMetaObject::connectSlotsByName(menuWindow);
    } // setupUi

    void retranslateUi(QDialog *menuWindow)
    {
        menuWindow->setWindowTitle(QCoreApplication::translate("menuWindow", "Dialog", nullptr));
        pushButton_Saldo->setText(QCoreApplication::translate("menuWindow", "Saldo", nullptr));
        pushButton_Tilitapahtumat->setText(QCoreApplication::translate("menuWindow", "Tilitapahtumat", nullptr));
        pushButton_Otto->setText(QCoreApplication::translate("menuWindow", "Otto", nullptr));
        pushButton_LuottorajanNosto->setText(QCoreApplication::translate("menuWindow", "Luottorajan nosto", nullptr));
        labelCardnumber->setText(QString());
        pushButton_KirjauduUlos->setText(QCoreApplication::translate("menuWindow", "Kirjaudu ulos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuWindow: public Ui_menuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
