#include "luottoraja.h"
#include "ui_luottoraja.h"

luottoraja::luottoraja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::luottoraja)
{
    ui->setupUi(this);
}

luottoraja::~luottoraja()
{
    delete ui;
}




void luottoraja::on_luottoPoistu_clicked()
{
    luottoraja::close();
}


void luottoraja::on_luottoHae_clicked()
{

}

