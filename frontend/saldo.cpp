#include "saldo.h"
#include "ui_saldo.h"
#include "myurl.h"


saldo::saldo(QByteArray bearerToken, QString idAccount, QWidget *parent) : //Välitetään bearerToken ja idAccount
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);

    myToken = bearerToken;
    qDebug()<<myToken;
    id_account = idAccount;
    qDebug()<<id_account;

    QString site_url=MyURL::getBaseURL()+"/account/"+idAccount;
       QNetworkRequest request((site_url));
       //WEBTOKEN ALKU
       request.setRawHeader(QByteArray("Authorization"),(myToken));
       //WEBTOKEN LOPPU
       balanceManager = new QNetworkAccessManager(this);

       connect(balanceManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getBalanceSlot(QNetworkReply*)));

       reply = balanceManager->get(request);


    ui->labelNaytaSaldo->setText(balance);

}

saldo::~saldo()
{
    delete ui;
}

void saldo::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}



void saldo::on_poistuSaldo_clicked() //Suljetaan saldo-ikkuna
{
    saldo::close();
}

void saldo::getBalanceSlot(QNetworkReply *reply) //Pyydetään balance tietokannasta
{


    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    qDebug()<<response_data;

    response_data=reply->readAll();
     qDebug()<<"DATA : "+response_data;
     //QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();
     QString account ="";
     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        account+=QString::number(json_obj["balance"].toInt())+", "+json_obj["account_type"].toString()+"\n";
}


    balance=QString::number(json_obj["balance"].toInt())+"\n";;
    qDebug()<<balance;
    ui->labelNaytaSaldo->setText(balance);

}

void saldo::setBalance(const QString &newBalance)
{
    balance = newBalance;
}





