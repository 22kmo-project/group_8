#include "otto.h"
#include "ui_otto.h"
#include "myurl.h"

otto::otto(QByteArray bearerToken, QString idAccount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otto)
{
    ui->setupUi(this);
    myToken = bearerToken;
    qDebug()<<myToken;
    id_account = idAccount;
    qDebug()<<id_account;

    QString site_url = MyURL::getBaseURL()+"/account/"+idAccount;
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    AccountTypeManager = new QNetworkAccessManager();

    connect(AccountTypeManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getAccountTypeSlot(QNetworkReply*)));

    reply = AccountTypeManager->get(request);
}

otto::~otto()
{
    delete ui;

}

void otto::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}


void otto::on_ottoPoistu_clicked()
{
    otto::close();
}

void otto::on_Nosto10_clicked()
{
   withdraw(10);
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


void otto::withdraw(int amount)
{
    editSaldo("1", -amount);

}

// Muuta annetun tilin saldoa
void otto::editSaldo(QString accountId, int amount)// QString accountType)
{
    // Keskeytä jos annettu määrä on 0 tai suurempi kuin tilin saldo


    QJsonObject jsonObj;
    jsonObj.insert("balance",amount);

    //jsonObj.insert("account_type",accountType);
    QString site_url=MyURL::getBaseURL()+"/account/"+idAccount;
    QNetworkRequest request((site_url));
    //WEBTOKENIN ALKU
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKENIN LOPPU
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //qDebug()<<request;
    ottoManager = new QNetworkAccessManager(this);
    connect(ottoManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(ottoSlot(QNetworkReply*)));
    reply = ottoManager->put(request, QJsonDocument(jsonObj).toJson());

    //lisäys transactioniin

}

// Palauta pyydetty tieto annetulta tililtä
QString otto::getAccountData(QString idAccount)
{
    QJsonObject jsonObj;

    QString site_url=MyURL::getBaseURL()+"/account/"+idAccount;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //qDebug()<<request;
    ottoManager = new QNetworkAccessManager(this);
    connect(ottoManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(ottoSlot(QNetworkReply*)));
    reply = ottoManager->post(request, QJsonDocument(jsonObj).toJson());
}

void otto::getAccountType()
{

}

void otto::getAccountTypeSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    accountType=json_obj["account_type"].toString();
    qDebug()<<accountType;

    reply->deleteLater();
}
