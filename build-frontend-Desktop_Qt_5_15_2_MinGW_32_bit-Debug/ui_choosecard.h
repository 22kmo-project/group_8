/********************************************************************************
** Form generated from reading UI file 'choosecard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSECARD_H
#define UI_CHOOSECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChooseCard
{
public:
    QPushButton *pushButton_credit;
    QLabel *label;
    QPushButton *pushButton_debit;
    QLabel *labelCardnumber;

    void setupUi(QDialog *ChooseCard)
    {
        if (ChooseCard->objectName().isEmpty())
            ChooseCard->setObjectName(QString::fromUtf8("ChooseCard"));
        ChooseCard->resize(755, 590);
        ChooseCard->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        pushButton_credit = new QPushButton(ChooseCard);
        pushButton_credit->setObjectName(QString::fromUtf8("pushButton_credit"));
        pushButton_credit->setGeometry(QRect(130, 230, 141, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        pushButton_credit->setFont(font);
        pushButton_credit->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(ChooseCard);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 110, 561, 71));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        pushButton_debit = new QPushButton(ChooseCard);
        pushButton_debit->setObjectName(QString::fromUtf8("pushButton_debit"));
        pushButton_debit->setGeometry(QRect(460, 230, 141, 51));
        pushButton_debit->setFont(font);
        pushButton_debit->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));
        labelCardnumber = new QLabel(ChooseCard);
        labelCardnumber->setObjectName(QString::fromUtf8("labelCardnumber"));
        labelCardnumber->setGeometry(QRect(90, 70, 131, 21));
        labelCardnumber->setFont(font);
        labelCardnumber->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(ChooseCard);

        QMetaObject::connectSlotsByName(ChooseCard);
    } // setupUi

    void retranslateUi(QDialog *ChooseCard)
    {
        ChooseCard->setWindowTitle(QCoreApplication::translate("ChooseCard", "Dialog", nullptr));
        pushButton_credit->setText(QCoreApplication::translate("ChooseCard", "Credit", nullptr));
        label->setText(QCoreApplication::translate("ChooseCard", "Valitse Credit tai Debit", nullptr));
        pushButton_debit->setText(QCoreApplication::translate("ChooseCard", "Debit", nullptr));
        labelCardnumber->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChooseCard: public Ui_ChooseCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSECARD_H
