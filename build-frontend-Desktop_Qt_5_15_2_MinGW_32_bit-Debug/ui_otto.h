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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_otto
{
public:
    QPushButton *ottoNosta;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *ottoPoistu;

    void setupUi(QDialog *otto)
    {
        if (otto->objectName().isEmpty())
            otto->setObjectName(QString::fromUtf8("otto"));
        otto->resize(711, 593);
        otto->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        ottoNosta = new QPushButton(otto);
        ottoNosta->setObjectName(QString::fromUtf8("ottoNosta"));
        ottoNosta->setGeometry(QRect(240, 340, 80, 24));
        ottoNosta->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(otto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 130, 511, 61));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::WinPanel);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);
        textEdit = new QTextEdit(otto);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(230, 260, 251, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        textEdit->setFont(font1);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        ottoPoistu = new QPushButton(otto);
        ottoPoistu->setObjectName(QString::fromUtf8("ottoPoistu"));
        ottoPoistu->setGeometry(QRect(380, 340, 80, 24));
        ottoPoistu->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(otto);

        QMetaObject::connectSlotsByName(otto);
    } // setupUi

    void retranslateUi(QDialog *otto)
    {
        otto->setWindowTitle(QCoreApplication::translate("otto", "Dialog", nullptr));
        ottoNosta->setText(QCoreApplication::translate("otto", "Nosta", nullptr));
        label->setText(QCoreApplication::translate("otto", "Valitse nostettava summa ja paina ''Nosta''", nullptr));
        ottoPoistu->setText(QCoreApplication::translate("otto", "Poistu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class otto: public Ui_otto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTTO_H
