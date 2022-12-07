/********************************************************************************
** Form generated from reading UI file 'otto.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTTO_H
#define UI_OTTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_otto
{
public:
    QLabel *label;
    QPushButton *ottoPoistu;
    QPushButton *Nosto500;
    QPushButton *Nosto20;
    QPushButton *Nosto50;
    QPushButton *Nosto100;
    QPushButton *Nosto200;
    QLabel *labelSaldo;
    QLabel *label_o;
    QLineEdit *lineEdit;
    QPushButton *ok;

    void setupUi(QDialog *otto)
    {
        if (otto->objectName().isEmpty())
            otto->setObjectName(QString::fromUtf8("otto"));
        otto->resize(711, 593);
        otto->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        label = new QLabel(otto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 200, 671, 61));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::WinPanel);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);
        ottoPoistu = new QPushButton(otto);
        ottoPoistu->setObjectName(QString::fromUtf8("ottoPoistu"));
        ottoPoistu->setGeometry(QRect(310, 520, 80, 24));
        ottoPoistu->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        Nosto500 = new QPushButton(otto);
        Nosto500->setObjectName(QString::fromUtf8("Nosto500"));
        Nosto500->setGeometry(QRect(560, 470, 80, 24));
        Nosto500->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        Nosto20 = new QPushButton(otto);
        Nosto20->setObjectName(QString::fromUtf8("Nosto20"));
        Nosto20->setGeometry(QRect(90, 470, 80, 24));
        Nosto20->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        Nosto50 = new QPushButton(otto);
        Nosto50->setObjectName(QString::fromUtf8("Nosto50"));
        Nosto50->setGeometry(QRect(200, 470, 80, 24));
        Nosto50->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        Nosto100 = new QPushButton(otto);
        Nosto100->setObjectName(QString::fromUtf8("Nosto100"));
        Nosto100->setGeometry(QRect(310, 470, 80, 24));
        Nosto100->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        Nosto200 = new QPushButton(otto);
        Nosto200->setObjectName(QString::fromUtf8("Nosto200"));
        Nosto200->setGeometry(QRect(440, 470, 80, 24));
        Nosto200->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        labelSaldo = new QLabel(otto);
        labelSaldo->setObjectName(QString::fromUtf8("labelSaldo"));
        labelSaldo->setGeometry(QRect(100, 120, 151, 41));
        QFont font1;
        font1.setPointSize(7);
        labelSaldo->setFont(font1);
        labelSaldo->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        labelSaldo->setAlignment(Qt::AlignCenter);
        label_o = new QLabel(otto);
        label_o->setObjectName(QString::fromUtf8("label_o"));
        label_o->setGeometry(QRect(280, 70, 381, 101));
        QFont font2;
        font2.setPointSize(9);
        label_o->setFont(font2);
        label_o->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(otto);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 330, 211, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        ok = new QPushButton(otto);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(410, 330, 171, 51));

        retranslateUi(otto);

        QMetaObject::connectSlotsByName(otto);
    } // setupUi

    void retranslateUi(QDialog *otto)
    {
        otto->setWindowTitle(QCoreApplication::translate("otto", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("otto", "Valitse nostettava summa tai kirjoita vapaavalintainen summa ja paina OK-painiketta", nullptr));
        ottoPoistu->setText(QCoreApplication::translate("otto", "Poistu", nullptr));
        Nosto500->setText(QCoreApplication::translate("otto", "500", nullptr));
        Nosto20->setText(QCoreApplication::translate("otto", "20e", nullptr));
        Nosto50->setText(QCoreApplication::translate("otto", "50e", nullptr));
        Nosto100->setText(QCoreApplication::translate("otto", "100e", nullptr));
        Nosto200->setText(QCoreApplication::translate("otto", "200e", nullptr));
        labelSaldo->setText(QString());
        label_o->setText(QString());
        ok->setText(QCoreApplication::translate("otto", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class otto: public Ui_otto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTTO_H
