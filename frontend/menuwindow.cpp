#include "menuwindow.h"
#include "ui_menuwindow.h"

menuWindow::menuWindow(QString card_number, bool credit, QWidget *parent) :
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

