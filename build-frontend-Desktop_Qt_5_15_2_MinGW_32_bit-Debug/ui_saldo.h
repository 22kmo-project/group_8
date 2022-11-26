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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saldo
{
public:
    QPushButton *saldoTakaisin;
    QLabel *kortin_numero;
    QLineEdit *naytaSaldo;

    void setupUi(QDialog *saldo)
    {
        if (saldo->objectName().isEmpty())
            saldo->setObjectName(QString::fromUtf8("saldo"));
        saldo->resize(830, 546);
        saldoTakaisin = new QPushButton(saldo);
        saldoTakaisin->setObjectName(QString::fromUtf8("saldoTakaisin"));
        saldoTakaisin->setGeometry(QRect(640, 420, 121, 61));
        saldoTakaisin->setAutoFillBackground(false);
        kortin_numero = new QLabel(saldo);
        kortin_numero->setObjectName(QString::fromUtf8("kortin_numero"));
        kortin_numero->setGeometry(QRect(40, 50, 161, 41));
        naytaSaldo = new QLineEdit(saldo);
        naytaSaldo->setObjectName(QString::fromUtf8("naytaSaldo"));
        naytaSaldo->setGeometry(QRect(90, 170, 431, 161));

        retranslateUi(saldo);

        QMetaObject::connectSlotsByName(saldo);
    } // setupUi

    void retranslateUi(QDialog *saldo)
    {
        saldo->setWindowTitle(QCoreApplication::translate("saldo", "Dialog", nullptr));
        saldoTakaisin->setText(QCoreApplication::translate("saldo", "Takaisin", nullptr));
        kortin_numero->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class saldo: public Ui_saldo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDO_H
