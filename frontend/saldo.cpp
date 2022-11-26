#include "saldo.h"
#include "ui_saldo.h"
#include "mainwindow.h"
#include "menuwindow.h"


saldo::saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);
}

saldo::~saldo()
{
    delete ui;
}

void saldo::on_saldoTakaisin_clicked()
{
saldo::close();
}

