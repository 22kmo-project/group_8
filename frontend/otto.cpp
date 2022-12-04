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
    QJsonObject jsonObjUpdate;
    jsonObjUpdate.insert("balance", balance);
    QString site_url=MyURL::getBaseURL()+"/account/balance/"+id_account;
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    qDebug()<<myToken;
    //WEBTOKEN LOPPU

    updateBalanceManager = new QNetworkAccessManager(this);
    connect(updateBalanceManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(updateBalanceSlot(QNetworkReply*)));

    reply = updateBalanceManager->put(request, QJsonDocument(jsonObjUpdate).toJson());


}

void otto::on_Nosto10_clicked()
{
    checkMoney(balanceValue,10);
    amount=10;
}


void otto::on_Nosto20_clicked()
{
    checkMoney(balanceValue,20);
    amount=20;
}


void otto::on_Nosto50_clicked()
{
    checkMoney(balanceValue,50);
    amount=50;
}


void otto::on_Nosto100_clicked()
{
    checkMoney(balanceValue,100);
    amount=100;
}


void otto::on_Nosto200_clicked()
{
    checkMoney(balanceValue,200);
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


/*void otto::withdraw(int amount)
{
    editSaldo("1", -amount);

}*/

/*// Muuta annetun tilin saldoa
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
}*/


void otto::getAccountTypeSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    accountType=json_obj["account_type"].toString();
    balance=QString::number(json_obj["balance"].toDouble());
    balanceValue=QString(balance).toDouble();
    qDebug()<<balance;
    qDebug()<<accountType;

    reply->deleteLater();
    AccountTypeManager->deleteLater();
}

void otto::checkMoney(double balanssi, double amountti)
{
    if(balanssi<amountti)
    {
        qDebug()<<"ei onnistunut";
    }
    else
    {
        balanssi=balanssi-amountti;
        balance=QString::number(balanssi);
        qDebug()<<"onnistui";
    }
}

void otto::updateBalanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    updateBalanceManager->deleteLater();
    otto::close();
}

