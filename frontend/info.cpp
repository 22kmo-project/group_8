#include "info.h"
#include "menuwindow.h"
#include "myurl.h"

Info::Info()
{

}

void Info::getIdCard()
{
    QJsonObject jsonObj;
    jsonObj.insert("card_number", getCard_Number());

    QString wb = webToken;
    qDebug()<<"Webtoken ="+wb;
    qDebug()<<webToken;
    bearerToken = "Bearer "+wb.toUtf8();
    qDebug()<<bearerToken;
    QString site_url = MyURL::getBaseURL()+"/idcard/";
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(bearerToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    idCardManager = new QNetworkAccessManager();

    connect(idCardManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getIdSlot(QNetworkReply*)));
    qDebug()<<jsonObj;
    reply = idCardManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Info::getIdAccount()
{
    QJsonObject jsonObj;
    jsonObj.insert("id_card", getCardId());
    QString wb = webToken;
    qDebug()<<"Webtoken ="+wb;
    qDebug()<<webToken;
    bearerToken = "Bearer "+wb.toUtf8();
    qDebug()<<bearerToken;
    QString site_url = MyURL::getBaseURL()+"/idaccount";
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(bearerToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    idAccountManager = new QNetworkAccessManager();

    connect(idAccountManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getAccountSlot(QNetworkReply*)));
    qDebug()<<jsonObj;
    reply = idAccountManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Info::getIdSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    qDebug()<<response_data;
    setCardId(QString::number(json_obj["id_card"].toInt()));
    qDebug()<<idCard;

    reply->deleteLater();

    getIdAccount();

}

void Info::getAccountSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonObject json_obj = json_doc.object();

     qDebug()<<response_data;
     setIdAccount(QString::number(json_obj["id_account"].toInt()));
     qDebug()<<idAccount;

     reply->deleteLater();

     startMenuWindow();

}



void Info::startMenuWindow()
{
    menuWindow *objectmenuWindow;
    objectmenuWindow = new menuWindow(bearerToken, idAccount);
    //objectmenuWindow->setWebToken(webToken);
    objectmenuWindow->show();
}

const QString &Info::getWebToken() const
{
    return webToken;
}


void Info::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

const QString &Info::getCard_Number() const
{
    return cardNumber;
}

void Info::setCard_Number(const QString &newCardNumber)
{
    cardNumber = newCardNumber;
}

const QString &Info::getCardId() const
{
    return idCard;
}

void Info::setCardId(const QString &newIdCard)
{
    idCard = newIdCard;
}

const QString &Info::getIdAccount() const
{
    return idAccount;
}

void Info::setIdAccount(const QString &newIdAccount)
{
    idAccount = newIdAccount;
}

const QString &Info::getAccount_Type() const
{
    return account_Type;
}

void Info::setAccount_Type(const QString &newAccount_Type)
{
    account_Type = newAccount_Type;
}
