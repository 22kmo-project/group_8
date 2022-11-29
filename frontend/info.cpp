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

void Info::getIdSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    qDebug()<<response_data;
    setCardId(QString::number(json_obj["id_card"].toInt()));
    qDebug()<<idCard;

    reply->deleteLater();

    startMenuWindow();

}




void Info::startMenuWindow()
{
    menuWindow *objectmenuWindow;
    objectmenuWindow = new menuWindow(this);
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

