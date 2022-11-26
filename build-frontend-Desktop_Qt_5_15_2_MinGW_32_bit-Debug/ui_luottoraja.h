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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_luottoraja
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QPushButton *luottoHae;
    QPushButton *luottoPoistu;
    QTextEdit *textEdit;

    void setupUi(QDialog *luottoraja)
    {
        if (luottoraja->objectName().isEmpty())
            luottoraja->setObjectName(QString::fromUtf8("luottoraja"));
        luottoraja->resize(714, 603);
        luottoraja->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        frame = new QFrame(luottoraja);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(120, 130, 481, 81));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Plain);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 10, 341, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 451, 20));
        label_2->setFont(font);
        luottoHae = new QPushButton(luottoraja);
        luottoHae->setObjectName(QString::fromUtf8("luottoHae"));
        luottoHae->setGeometry(QRect(200, 350, 101, 24));
        luottoHae->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        luottoPoistu = new QPushButton(luottoraja);
        luottoPoistu->setObjectName(QString::fromUtf8("luottoPoistu"));
        luottoPoistu->setGeometry(QRect(390, 350, 101, 24));
        luottoPoistu->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        textEdit = new QTextEdit(luottoraja);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(230, 260, 241, 41));
        textEdit->setFont(font);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(luottoraja);

        QMetaObject::connectSlotsByName(luottoraja);
    } // setupUi

    void retranslateUi(QDialog *luottoraja)
    {
        luottoraja->setWindowTitle(QCoreApplication::translate("luottoraja", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("luottoraja", "Valitse haluamasi uusi luottoraja, ", nullptr));
        label_2->setText(QCoreApplication::translate("luottoraja", "saat p\303\244\303\244t\303\266ksen hakemuksellesi v\303\244litt\303\266m\303\244sti", nullptr));
        luottoHae->setText(QCoreApplication::translate("luottoraja", "Tee hakemus", nullptr));
        luottoPoistu->setText(QCoreApplication::translate("luottoraja", "Poistu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class luottoraja: public Ui_luottoraja {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUOTTORAJA_H
