#include "saldo.h"
#include "ui_saldo.h"
#include "mainwindow.h"
#include "menuwindow.h"
#include "loginwindow.h"


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




void saldo::on_poistuSaldo_clicked()
{
    saldo::close();
}


