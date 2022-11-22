#include "menuwindow.h"
#include "ui_menuwindow.h"

menuWindow::menuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
}

menuWindow::~menuWindow()
{
    delete ui;
}


void menuWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}


void menuWindow::on_pushButton_Saldo_clicked()
{

}

