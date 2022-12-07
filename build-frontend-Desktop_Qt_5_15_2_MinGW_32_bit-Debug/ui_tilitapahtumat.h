/********************************************************************************
** Form generated from reading UI file 'tilitapahtumat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILITAPAHTUMAT_H
#define UI_TILITAPAHTUMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_tilitapahtumat
{
public:
    QLabel *labelTilitapahtumat;
    QTextBrowser *textTilitapahtumat;
    QPushButton *seuraavatBtn;
    QPushButton *edellisetBtn;
    QPushButton *naytaTilitapahtumatBtn;
    QPushButton *TakaisinBtn;

    void setupUi(QDialog *tilitapahtumat)
    {
        if (tilitapahtumat->objectName().isEmpty())
            tilitapahtumat->setObjectName(QString::fromUtf8("tilitapahtumat"));
        tilitapahtumat->resize(684, 570);
        tilitapahtumat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        labelTilitapahtumat = new QLabel(tilitapahtumat);
        labelTilitapahtumat->setObjectName(QString::fromUtf8("labelTilitapahtumat"));
        labelTilitapahtumat->setGeometry(QRect(40, 20, 141, 41));
        QFont font;
        font.setPointSize(14);
        labelTilitapahtumat->setFont(font);
        labelTilitapahtumat->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        labelTilitapahtumat->setFrameShape(QFrame::WinPanel);
        labelTilitapahtumat->setAlignment(Qt::AlignCenter);
        textTilitapahtumat = new QTextBrowser(tilitapahtumat);
        textTilitapahtumat->setObjectName(QString::fromUtf8("textTilitapahtumat"));
        textTilitapahtumat->setGeometry(QRect(30, 70, 251, 421));
        textTilitapahtumat->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);\n"
"color: rgb(255, 255, 255);"));
        textTilitapahtumat->setFrameShape(QFrame::WinPanel);
        seuraavatBtn = new QPushButton(tilitapahtumat);
        seuraavatBtn->setObjectName(QString::fromUtf8("seuraavatBtn"));
        seuraavatBtn->setGeometry(QRect(320, 330, 121, 41));
        seuraavatBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        edellisetBtn = new QPushButton(tilitapahtumat);
        edellisetBtn->setObjectName(QString::fromUtf8("edellisetBtn"));
        edellisetBtn->setGeometry(QRect(500, 330, 121, 41));
        edellisetBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        naytaTilitapahtumatBtn = new QPushButton(tilitapahtumat);
        naytaTilitapahtumatBtn->setObjectName(QString::fromUtf8("naytaTilitapahtumatBtn"));
        naytaTilitapahtumatBtn->setGeometry(QRect(320, 220, 121, 41));
        naytaTilitapahtumatBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        TakaisinBtn = new QPushButton(tilitapahtumat);
        TakaisinBtn->setObjectName(QString::fromUtf8("TakaisinBtn"));
        TakaisinBtn->setGeometry(QRect(500, 220, 121, 41));
        TakaisinBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(tilitapahtumat);

        QMetaObject::connectSlotsByName(tilitapahtumat);
    } // setupUi

    void retranslateUi(QDialog *tilitapahtumat)
    {
        tilitapahtumat->setWindowTitle(QCoreApplication::translate("tilitapahtumat", "Dialog", nullptr));
        labelTilitapahtumat->setText(QCoreApplication::translate("tilitapahtumat", "Tilitapahtumat", nullptr));
        seuraavatBtn->setText(QCoreApplication::translate("tilitapahtumat", "Seuraavat(10)", nullptr));
        edellisetBtn->setText(QCoreApplication::translate("tilitapahtumat", "Edelliset(10)", nullptr));
        naytaTilitapahtumatBtn->setText(QCoreApplication::translate("tilitapahtumat", "N\303\244yt\303\244 Tilitapahtumat", nullptr));
        TakaisinBtn->setText(QCoreApplication::translate("tilitapahtumat", "Takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tilitapahtumat: public Ui_tilitapahtumat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILITAPAHTUMAT_H
