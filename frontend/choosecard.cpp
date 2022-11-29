#include "choosecard.h"
#include "ui_choosecard.h"

ChooseCard::ChooseCard(QString card_number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseCard)
{
    ui->setupUi(this);
    ui->labelCardnumber->setText(card_number);
    cardNumber = card_number;
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
    info = new Info();
    info->setWebToken(webToken);
    info->setCard_Number(cardNumber);
    info->getIdCard();
    //objectCardToMenu=new menuWindow(cardNumber, true, webToken);
    //objectCardToMenu->setWebToken(webToken);
    //objectCardToMenu->show();
    ChooseCard::close();
}


void ChooseCard::on_pushButton_debit_clicked()
{
    info = new Info();
    info->setWebToken(webToken);
    info->setCard_Number(cardNumber);
    info->getIdCard();
    //objectCardToMenu=new menuWindow(cardNumber, false, webToken);
    //objectCardToMenu->setWebToken(webToken);
    //objectCardToMenu->show();
    ChooseCard::close();
}
