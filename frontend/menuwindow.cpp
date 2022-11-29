#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "otto.h"
#include "luottoraja.h"
#include "myurl.h"
#include "saldo.h"


menuWindow::menuWindow(QString card_number, bool credit, QByteArray webToken, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    cardNumber = card_number;
    token = webToken;
    this->isCredit = credit;
    this->getIdCard(cardNumber);
    this->setWebToken(token);
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

    //saldo saldo;
    //saldo.setModal(true);
    //saldo.exec();

  class saldo nayta(webToken);
  nayta.setModal(true);
  nayta.exec();

}

void menuWindow::idCardSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
       QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
       QJsonArray json_array = json_doc.array();
       foreach (const QJsonValue &value, json_array)
       {
           QJsonObject json_obj = value.toObject();
           qDebug()<<json_obj["id_card"].toString();
           id_card=json_obj["id_card"].toString();
       }

       qDebug()<<id_card;
       ui->labelCardnumber->setText(id_card);

       reply->deleteLater();
       idCardManager->deleteLater();
}

void menuWindow::getIdCard(QString card_number)
{
    qDebug()<<token;
    QString site_url=MyURL::getBaseURL()+"/card/"+card_number;
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    idCardManager = new QNetworkAccessManager(this);

    connect(idCardManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(idCardSlot(QNetworkReply*)));

    reply = idCardManager->get(request);
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

