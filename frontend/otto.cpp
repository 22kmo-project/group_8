#include "otto.h"
#include "ui_otto.h"
#include "mainwindow.h"


otto::otto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otto)
{
    ui->setupUi(this);

}

otto::~otto()
{
    delete ui;

}



void otto::on_ottoPoistu_clicked()
{
    otto::close();
}

void otto::on_Nosto10_clicked()
{
   withdraw(10,"debit");
   //getAccountData("1");
}


void otto::on_Nosto20_clicked()
{
   amount=20;
}


void otto::on_Nosto50_clicked()
{
   amount=50;
}


void otto::on_Nosto100_clicked()
{
   amount=100;
}


void otto::on_Nosto200_clicked()
{
    amount=200;
}

void otto::ottoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
        qDebug()<<response_data;
        reply->deleteLater();
        ottoManager->deleteLater();
        this->close();
}

void otto::resetTimer()
{
    objectTimer->stop();
    objectTimer->start();
}

void otto::withdraw(int amount, QString account_type)
{
    editSaldo("1", -amount, account_type);

}

// Muuta annetun tilin saldoa
void otto::editSaldo(QString accountId, int amount, QString account_type)
{
    // Keskeytä jos annettu määrä on 0 tai suurempi kuin tilin saldo


    QJsonObject jsonObj;
    jsonObj.insert("balance",amount);

    jsonObj.insert("account_type",account_type);
    QString site_url=MyURL::getBaseURL()+"/account/"+accountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //qDebug()<<request;
    ottoManager = new QNetworkAccessManager(this);
    connect(ottoManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(ottoSlot(QNetworkReply*)));
    reply = ottoManager->put(request, QJsonDocument(jsonObj).toJson());

}

// Palauta pyydetty tieto annetulta tililtä
QString otto::getAccountData(QString accountId)
{
    QJsonObject jsonObj;

    jsonObj.insert("id_account",accountId);
    QString site_url=MyURL::getBaseURL()+"/account/"+accountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //qDebug()<<request;
    ottoManager = new QNetworkAccessManager(this);
    connect(ottoManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(ottoSlot(QNetworkReply*)));
    reply = ottoManager->post(request, QJsonDocument(jsonObj).toJson());
}


