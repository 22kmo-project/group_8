#include "luottoraja.h"
#include "ui_luottoraja.h"

luottoraja::luottoraja(QByteArray bearerToken, QString idAccount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::luottoraja)
{
    ui->setupUi(this);
    myToken = bearerToken;
    qDebug()<<myToken;
    id_account = idAccount;
    qDebug()<<id_account;

}

luottoraja::~luottoraja()
{
    delete ui;
}

void luottoraja::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}




void luottoraja::on_luottoPoistu_clicked()
{
    luottoraja::close();
}


void luottoraja::on_luottoHae_clicked()
{

}

