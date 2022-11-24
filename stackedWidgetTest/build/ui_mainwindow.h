/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_sisaan;
    QLabel *label;
    QPushButton *btnSisaan;
    QWidget *page_menu;
    QPushButton *btnSaldo;
    QPushButton *btnOtto;
    QPushButton *btnTilitapahtumat;
    QPushButton *btnLuottorajanNosto;
    QPushButton *btnPoistu_2;
    QWidget *page_valitseKortti;
    QPushButton *btnDebit;
    QPushButton *btnCredit;
    QLabel *lblValitse_Kortti;
    QWidget *page_saldo;
    QLabel *label_4;
    QPushButton *btnTakaisin_3;
    QWidget *page_tilitapahtumat;
    QLabel *label_5;
    QPushButton *btnTakaisin_4;
    QWidget *page_otto;
    QLabel *label_6;
    QPushButton *btnTakaisin_2;
    QWidget *page_nostaLuottorajaa;
    QLabel *label_7;
    QPushButton *btnTakaisin;
    QWidget *page_kirjaudu;
    QPushButton *btnKirjaudu;
    QPushButton *btnPoistu;
    QLineEdit *lineEdit_cardnumber;
    QLineEdit *lineEdit_pin;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelInfo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 20, 721, 501));
        page_sisaan = new QWidget();
        page_sisaan->setObjectName(QString::fromUtf8("page_sisaan"));
        label = new QLabel(page_sisaan);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 70, 321, 81));
        label->setAlignment(Qt::AlignCenter);
        btnSisaan = new QPushButton(page_sisaan);
        btnSisaan->setObjectName(QString::fromUtf8("btnSisaan"));
        btnSisaan->setGeometry(QRect(220, 270, 231, 81));
        stackedWidget->addWidget(page_sisaan);
        page_menu = new QWidget();
        page_menu->setObjectName(QString::fromUtf8("page_menu"));
        btnSaldo = new QPushButton(page_menu);
        btnSaldo->setObjectName(QString::fromUtf8("btnSaldo"));
        btnSaldo->setGeometry(QRect(130, 100, 171, 51));
        btnOtto = new QPushButton(page_menu);
        btnOtto->setObjectName(QString::fromUtf8("btnOtto"));
        btnOtto->setGeometry(QRect(130, 260, 171, 51));
        btnTilitapahtumat = new QPushButton(page_menu);
        btnTilitapahtumat->setObjectName(QString::fromUtf8("btnTilitapahtumat"));
        btnTilitapahtumat->setGeometry(QRect(430, 100, 171, 51));
        btnLuottorajanNosto = new QPushButton(page_menu);
        btnLuottorajanNosto->setObjectName(QString::fromUtf8("btnLuottorajanNosto"));
        btnLuottorajanNosto->setGeometry(QRect(430, 260, 171, 51));
        btnPoistu_2 = new QPushButton(page_menu);
        btnPoistu_2->setObjectName(QString::fromUtf8("btnPoistu_2"));
        btnPoistu_2->setGeometry(QRect(280, 380, 171, 51));
        stackedWidget->addWidget(page_menu);
        page_valitseKortti = new QWidget();
        page_valitseKortti->setObjectName(QString::fromUtf8("page_valitseKortti"));
        btnDebit = new QPushButton(page_valitseKortti);
        btnDebit->setObjectName(QString::fromUtf8("btnDebit"));
        btnDebit->setGeometry(QRect(140, 190, 171, 51));
        btnCredit = new QPushButton(page_valitseKortti);
        btnCredit->setObjectName(QString::fromUtf8("btnCredit"));
        btnCredit->setGeometry(QRect(390, 190, 171, 51));
        lblValitse_Kortti = new QLabel(page_valitseKortti);
        lblValitse_Kortti->setObjectName(QString::fromUtf8("lblValitse_Kortti"));
        lblValitse_Kortti->setGeometry(QRect(230, 70, 271, 61));
        lblValitse_Kortti->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_valitseKortti);
        page_saldo = new QWidget();
        page_saldo->setObjectName(QString::fromUtf8("page_saldo"));
        label_4 = new QLabel(page_saldo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 70, 151, 71));
        label_4->setAlignment(Qt::AlignCenter);
        btnTakaisin_3 = new QPushButton(page_saldo);
        btnTakaisin_3->setObjectName(QString::fromUtf8("btnTakaisin_3"));
        btnTakaisin_3->setGeometry(QRect(290, 370, 171, 51));
        stackedWidget->addWidget(page_saldo);
        page_tilitapahtumat = new QWidget();
        page_tilitapahtumat->setObjectName(QString::fromUtf8("page_tilitapahtumat"));
        label_5 = new QLabel(page_tilitapahtumat);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(260, 70, 141, 61));
        label_5->setAlignment(Qt::AlignCenter);
        btnTakaisin_4 = new QPushButton(page_tilitapahtumat);
        btnTakaisin_4->setObjectName(QString::fromUtf8("btnTakaisin_4"));
        btnTakaisin_4->setGeometry(QRect(270, 370, 171, 51));
        stackedWidget->addWidget(page_tilitapahtumat);
        page_otto = new QWidget();
        page_otto->setObjectName(QString::fromUtf8("page_otto"));
        label_6 = new QLabel(page_otto);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 80, 141, 61));
        label_6->setAlignment(Qt::AlignCenter);
        btnTakaisin_2 = new QPushButton(page_otto);
        btnTakaisin_2->setObjectName(QString::fromUtf8("btnTakaisin_2"));
        btnTakaisin_2->setGeometry(QRect(270, 370, 171, 51));
        stackedWidget->addWidget(page_otto);
        page_nostaLuottorajaa = new QWidget();
        page_nostaLuottorajaa->setObjectName(QString::fromUtf8("page_nostaLuottorajaa"));
        label_7 = new QLabel(page_nostaLuottorajaa);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 80, 141, 61));
        label_7->setAlignment(Qt::AlignCenter);
        btnTakaisin = new QPushButton(page_nostaLuottorajaa);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(280, 370, 171, 51));
        stackedWidget->addWidget(page_nostaLuottorajaa);
        page_kirjaudu = new QWidget();
        page_kirjaudu->setObjectName(QString::fromUtf8("page_kirjaudu"));
        btnKirjaudu = new QPushButton(page_kirjaudu);
        btnKirjaudu->setObjectName(QString::fromUtf8("btnKirjaudu"));
        btnKirjaudu->setGeometry(QRect(90, 380, 221, 61));
        btnPoistu = new QPushButton(page_kirjaudu);
        btnPoistu->setObjectName(QString::fromUtf8("btnPoistu"));
        btnPoistu->setGeometry(QRect(380, 380, 221, 61));
        lineEdit_cardnumber = new QLineEdit(page_kirjaudu);
        lineEdit_cardnumber->setObjectName(QString::fromUtf8("lineEdit_cardnumber"));
        lineEdit_cardnumber->setGeometry(QRect(400, 100, 181, 51));
        lineEdit_pin = new QLineEdit(page_kirjaudu);
        lineEdit_pin->setObjectName(QString::fromUtf8("lineEdit_pin"));
        lineEdit_pin->setGeometry(QRect(400, 200, 181, 51));
        label_2 = new QLabel(page_kirjaudu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 200, 221, 51));
        label_3 = new QLabel(page_kirjaudu);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 100, 221, 51));
        labelInfo = new QLabel(page_kirjaudu);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(130, 320, 421, 21));
        stackedWidget->addWidget(page_kirjaudu);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Pankkisimulaattori", nullptr));
        btnSisaan->setText(QCoreApplication::translate("MainWindow", "Sis\303\244\303\244n", nullptr));
        btnSaldo->setText(QCoreApplication::translate("MainWindow", "Saldo", nullptr));
        btnOtto->setText(QCoreApplication::translate("MainWindow", "Otto", nullptr));
        btnTilitapahtumat->setText(QCoreApplication::translate("MainWindow", "Tilitapahtumat", nullptr));
        btnLuottorajanNosto->setText(QCoreApplication::translate("MainWindow", "Luottorajan Nosto", nullptr));
        btnPoistu_2->setText(QCoreApplication::translate("MainWindow", "Poistu", nullptr));
        btnDebit->setText(QCoreApplication::translate("MainWindow", "Debit", nullptr));
        btnCredit->setText(QCoreApplication::translate("MainWindow", "Credit", nullptr));
        lblValitse_Kortti->setText(QCoreApplication::translate("MainWindow", "Valitse kortti", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Saldo", nullptr));
        btnTakaisin_3->setText(QCoreApplication::translate("MainWindow", "Takaisin", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Tilitapahtumat", nullptr));
        btnTakaisin_4->setText(QCoreApplication::translate("MainWindow", "Takaisin", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Otto", nullptr));
        btnTakaisin_2->setText(QCoreApplication::translate("MainWindow", "Takaisin", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nosta luottorajaa", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("MainWindow", "Takaisin", nullptr));
        btnKirjaudu->setText(QCoreApplication::translate("MainWindow", "Kirjaudu", nullptr));
        btnPoistu->setText(QCoreApplication::translate("MainWindow", "Poistu", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PIN", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "K\303\204YTT\303\204J\303\204TUNNUS", nullptr));
        labelInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
