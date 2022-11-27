#include "choosecard.h"
#include "ui_choosecard.h"

ChooseCard::ChooseCard(QString card_number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseCard)
{
    ui->setupUi(this);
    ui->labelCardnumber->setText(card_number);
}

ChooseCard::~ChooseCard()
{
    delete ui;
    //delete objectCardToMenu;
    //objectCardToMenu=nullptr;
}

void ChooseCard::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void ChooseCard::on_pushButton_credit_clicked()
{
    objectCardToMenu=new menuWindow(card_number, true);
    objectCardToMenu->setWebToken(webToken);
}


void ChooseCard::on_pushButton_debit_clicked()
{
    objectCardToMenu=new menuWindow(card_number, false);
    objectCardToMenu->setWebToken(webToken);
}

