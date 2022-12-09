#include "info.h"
#include "menuwindow.h"
#include "myurl.h"

Info::Info()
{

}

void Info::getIdUser()
{
    QJsonObject jsonObj;
    jsonObj.insert("card_number", getCard_Number());

    QString wb = webToken;
    //qDebug()<<"Webtoken ="+wb;
    bearerToken = "Bearer "+wb.toUtf8();
    QString site_url = MyURL::getBaseURL()+"/card/iduser/"+cardNumber;
    qDebug()<<"Info: osoite = "+site_url;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(bearerToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    idUserManager = new QNetworkAccessManager();
            connect(idUserManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getUserIdSlot(QNetworkReply*)));
    qDebug()<<jsonObj;
    reply = idUserManager->post(request, QJsonDocument(jsonObj).toJson());
}


void Info::getIdAccount()
{
    QJsonObject jsonObj;
    jsonObj.insert("id_user", getUserId());
    QString wb = webToken;
    bearerToken = "Bearer "+wb.toUtf8();

    QString site_url = MyURL::getBaseURL()+"/useraccount";
    qDebug()<<"Info getIdAccount osoite = "+site_url;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(bearerToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    idAccountManager = new QNetworkAccessManager();

    connect(idAccountManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getAccountSlot(QNetworkReply*)));
    qDebug()<<jsonObj;
    reply = idAccountManager->post(request, QJsonDocument(jsonObj).toJson());
}


void Info::getUserIdSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    qDebug()<<"Info getUserIdSlot response = "+response_data;
    setUserId(QString::number(json_obj["id_user"].toInt()));
    qDebug()<<"Info.cpp: User ID = "+idUser;

    reply->deleteLater();
    getIdAccount();
}


void Info::getAccountSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonObject json_obj = json_doc.object();

     qDebug()<<response_data;
     setAccountId(QString::number(json_obj["id_account"].toInt()));

     qDebug()<<"Info.cpp: Account ID = "+idAccount;

     reply->deleteLater();

     startMenuWindow();
}


void Info::startMenuWindow()
{
    menuWindow *objectmenuWindow;
    objectmenuWindow = new menuWindow(bearerToken, idAccount, idUser);
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


const QString &Info::getUserId() const
{
    return idUser;
}


void Info::setUserId(const QString &newIdUser)
{
    idUser = newIdUser;
}


const QString &Info::getAccountId() const
{
    return idAccount;
}


void Info::setAccountId(const QString &newIdAccount)
{
    idAccount = newIdAccount;
}


