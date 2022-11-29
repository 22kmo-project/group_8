#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "otto.h"
#include "luottoraja.h"
#include "tilitapahtumat.h"
#include "myurl.h"
#include "saldo.h"



menuWindow::menuWindow(Info *givenInfo, QWidget *parent) ://QString card_number, bool credit, QByteArray webToken,

    QDialog(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    info = givenInfo;
    info->getWebToken();
}

menuWindow::~menuWindow()
{
    delete ui;
}

const QString &menuWindow::getWebtoken() const
{
    return webToken;
}


void menuWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}


void menuWindow::on_pushButton_KirjauduUlos_clicked()
{
    menuWindow::close();
}


void menuWindow::on_pushButton_Saldo_clicked()
{
    //saldo saldo;
    //saldo.setModal(true);
    //saldo.exec();

  class saldo nayta(webToken);
  nayta.setModal(true);
  nayta.exec();

}


void menuWindow::on_pushButton_Otto_clicked()
{
    otto nosto(webToken);
    nosto.setModal(true);
    nosto.exec();
}

void menuWindow::on_pushButton_LuottorajanNosto_clicked()
{
    luottoraja luotto(webToken);
    luotto.setModal(true);
    luotto.exec();
}


void menuWindow::on_pushButton_Tilitapahtumat_clicked()
{
    tilitapahtumat tilitapahtumat(webToken);
    tilitapahtumat.setModal(true);
    tilitapahtumat.exec();
}

