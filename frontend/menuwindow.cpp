#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "saldo.h"
#include "otto.h"
#include "luottoraja.h"
#include "tilitapahtumat.h"

menuWindow::menuWindow(QString card_number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    ui->labelCardnumber->setText(card_number);
}

menuWindow::~menuWindow()
{
    delete ui;
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

}
void menuWindow::on_pushButton_Otto_clicked()
{
    otto nosto;
    nosto.setModal(true);
    nosto.exec();
}

void menuWindow::on_pushButton_LuottorajanNosto_clicked()
{
    luottoraja luotto;
    luotto.setModal(true);
    luotto.exec();
}


void menuWindow::on_pushButton_Tilitapahtumat_clicked()
{
    tilitapahtumat tilitapahtumat;
    tilitapahtumat.setModal(true);
    tilitapahtumat.exec();
}

