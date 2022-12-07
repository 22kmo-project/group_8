/********************************************************************************
** Form generated from reading UI file 'luottoraja.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUOTTORAJA_H
#define UI_LUOTTORAJA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_luottoraja
{
public:
    QPushButton *luottoPoistu;
    QPushButton *luotto500;
    QPushButton *luotto1000;
    QPushButton *luotto2000;
    QPushButton *luotto5000;
    QPushButton *luotto10000;
    QLabel *label_luotto;
    QPushButton *uusi_luotto;

    void setupUi(QDialog *luottoraja)
    {
        if (luottoraja->objectName().isEmpty())
            luottoraja->setObjectName(QString::fromUtf8("luottoraja"));
        luottoraja->resize(714, 603);
        luottoraja->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        luottoPoistu = new QPushButton(luottoraja);
        luottoPoistu->setObjectName(QString::fromUtf8("luottoPoistu"));
        luottoPoistu->setGeometry(QRect(290, 500, 101, 24));
        luottoPoistu->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        luotto500 = new QPushButton(luottoraja);
        luotto500->setObjectName(QString::fromUtf8("luotto500"));
        luotto500->setGeometry(QRect(70, 320, 80, 24));
        luotto500->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        luotto1000 = new QPushButton(luottoraja);
        luotto1000->setObjectName(QString::fromUtf8("luotto1000"));
        luotto1000->setGeometry(QRect(180, 320, 80, 24));
        luotto1000->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        luotto2000 = new QPushButton(luottoraja);
        luotto2000->setObjectName(QString::fromUtf8("luotto2000"));
        luotto2000->setGeometry(QRect(300, 320, 80, 24));
        luotto2000->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        luotto5000 = new QPushButton(luottoraja);
        luotto5000->setObjectName(QString::fromUtf8("luotto5000"));
        luotto5000->setGeometry(QRect(430, 320, 80, 24));
        luotto5000->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        luotto10000 = new QPushButton(luottoraja);
        luotto10000->setObjectName(QString::fromUtf8("luotto10000"));
        luotto10000->setGeometry(QRect(550, 320, 80, 24));
        luotto10000->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_luotto = new QLabel(luottoraja);
        label_luotto->setObjectName(QString::fromUtf8("label_luotto"));
        label_luotto->setGeometry(QRect(70, 180, 561, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        label_luotto->setFont(font);
        label_luotto->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        label_luotto->setFrameShape(QFrame::WinPanel);
        label_luotto->setAlignment(Qt::AlignCenter);
        uusi_luotto = new QPushButton(luottoraja);
        uusi_luotto->setObjectName(QString::fromUtf8("uusi_luotto"));
        uusi_luotto->setGeometry(QRect(260, 410, 171, 24));
        uusi_luotto->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(luottoraja);

        QMetaObject::connectSlotsByName(luottoraja);
    } // setupUi

    void retranslateUi(QDialog *luottoraja)
    {
        luottoraja->setWindowTitle(QCoreApplication::translate("luottoraja", "Dialog", nullptr));
        luottoPoistu->setText(QCoreApplication::translate("luottoraja", "Poistu", nullptr));
        luotto500->setText(QCoreApplication::translate("luottoraja", "500e", nullptr));
        luotto1000->setText(QCoreApplication::translate("luottoraja", "1000e", nullptr));
        luotto2000->setText(QCoreApplication::translate("luottoraja", "2000e", nullptr));
        luotto5000->setText(QCoreApplication::translate("luottoraja", "5000e", nullptr));
        luotto10000->setText(QCoreApplication::translate("luottoraja", "10000e", nullptr));
        label_luotto->setText(QCoreApplication::translate("luottoraja", "Mill\303\244 summalla haluat korottaa luottorajaasi?", nullptr));
        uusi_luotto->setText(QCoreApplication::translate("luottoraja", "Tallenna uusi luottoraja", nullptr));
    } // retranslateUi

};

namespace Ui {
    class luottoraja: public Ui_luottoraja {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUOTTORAJA_H
