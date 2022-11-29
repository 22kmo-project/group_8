#include "luottoraja.h"
#include "ui_luottoraja.h"

luottoraja::luottoraja(QByteArray wt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::luottoraja)
{
    ui->setupUi(this);
    myToken = wt;
    qDebug()<<myToken;
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

