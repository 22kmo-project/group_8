/********************************************************************************
** Form generated from reading UI file 'saldo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDO_H
#define UI_SALDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saldo
{
public:
    QLabel *labelNaytaSaldo;
    QPushButton *poistuSaldo;
    QLabel *label;

    void setupUi(QDialog *saldo)
    {
        if (saldo->objectName().isEmpty())
            saldo->setObjectName(QString::fromUtf8("saldo"));
        saldo->resize(558, 426);
        saldo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        labelNaytaSaldo = new QLabel(saldo);
        labelNaytaSaldo->setObjectName(QString::fromUtf8("labelNaytaSaldo"));
        labelNaytaSaldo->setGeometry(QRect(30, 130, 251, 81));
        QFont font;
        font.setPointSize(20);
        labelNaytaSaldo->setFont(font);
        poistuSaldo = new QPushButton(saldo);
        poistuSaldo->setObjectName(QString::fromUtf8("poistuSaldo"));
        poistuSaldo->setGeometry(QRect(380, 350, 101, 51));
        poistuSaldo->setFont(font);
        label = new QLabel(saldo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 101, 41));
        label->setFont(font);

        retranslateUi(saldo);

        QMetaObject::connectSlotsByName(saldo);
    } // setupUi

    void retranslateUi(QDialog *saldo)
    {
        saldo->setWindowTitle(QCoreApplication::translate("saldo", "Dialog", nullptr));
        labelNaytaSaldo->setText(QCoreApplication::translate("saldo", "TextLabel", nullptr));
        poistuSaldo->setText(QCoreApplication::translate("saldo", "Poistu", nullptr));
        label->setText(QCoreApplication::translate("saldo", "Saldo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saldo: public Ui_saldo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDO_H
