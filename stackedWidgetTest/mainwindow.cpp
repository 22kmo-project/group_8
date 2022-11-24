#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->btnSisaan, SIGNAL(clicked()), this, SLOT(KirjauduWidget()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SisaanWidget()
{
    QObject::connect(ui->btnSisaan, SIGNAL(clicked()), this, SLOT(KirjauduWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_sisaan);
}

void MainWindow::KirjauduWidget()
{
    QObject::connect(ui->btnKirjaudu, SIGNAL(clicked()), this, SLOT(ValitseKorttiWidget()));
    QObject::connect(ui->btnPoistu, SIGNAL(clicked()), this, SLOT(SisaanWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_kirjaudu);
}

void MainWindow::ValitseKorttiWidget()
{
    QObject::connect(ui->btnDebit, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    QObject::connect(ui->btnCredit, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_valitseKortti);
}
void MainWindow::MenuWidget()
{
    QObject::connect(ui->btnSaldo, SIGNAL(clicked()), this, SLOT(SaldoWidget()));
    QObject::connect(ui->btnTilitapahtumat, SIGNAL(clicked()), this, SLOT(TilitapahtumatWidget()));
    QObject::connect(ui->btnOtto, SIGNAL(clicked()), this, SLOT(OttoWidget()));
    QObject::connect(ui->btnLuottorajanNosto, SIGNAL(clicked()), this, SLOT(LuottorajanNostoWidget()));
    QObject::connect(ui->btnPoistu_2, SIGNAL(clicked()), this, SLOT(SisaanWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_menu);
}

void MainWindow::SaldoWidget()
{
    QObject::connect(ui->btnTakaisin_3, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_saldo);
}

void MainWindow::TilitapahtumatWidget()
{
    QObject::connect(ui->btnTakaisin_4, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_tilitapahtumat);
}

void MainWindow::OttoWidget()
{
    QObject::connect(ui->btnTakaisin_2, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_otto);
}

void MainWindow::LuottorajanNostoWidget()
{
    QObject::connect(ui->btnTakaisin, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_nostaLuottorajaa);
}
