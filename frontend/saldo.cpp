#include "saldo.h"
#include "ui_saldo.h"

#include "myurl.h"


saldo::saldo(QByteArray bearerToken, QString idAccount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);
    //ui->labelNaytaSaldo->text();

    myToken = bearerToken;
    qDebug()<<myToken;
    id_account = idAccount;
    qDebug()<<id_account;

    QString site_url=MyURL::getBaseURL()+"/account/"+idAccount;
    QNetworkRequest request((site_url));

    //WEBTOKENIN ALKU


    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKENIN LOPPU
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    saldoManager = new QNetworkAccessManager(this);

    connect(saldoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSaldo(QNetworkReply*)));

    reply = saldoManager->get(request);




}

saldo::~saldo()
{
    delete ui;
}

void saldo::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void saldo::getSaldo(QNetworkReply *reply)

{


    response_data=reply->readAll();
     qDebug()<<"DATA : "+response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();
     QString account;
     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        account+=QString::number(json_obj["balance"].toInt())+", "+json_obj["account_type"].toString()+"\n";
     }

     ui->labelNaytaSaldo->setText(account);

     reply->deleteLater();
     saldoManager->deleteLater();



}


void saldo::on_poistuSaldo_clicked()
{
    saldo::close();
}



/*void saldo::on_textnaytaSaldo_textChanged()
{
    QString site_url=MyURL::getBaseURL()+"/account/";
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKENIN LOPPU
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    saldoManager = new QNetworkAccessManager(this);

    connect(saldoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSaldo(QNetworkReply*)));

    reply = saldoManager->get(request);

}

*/


