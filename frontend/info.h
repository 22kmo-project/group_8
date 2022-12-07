#ifndef INFO_H
#define INFO_H

#include <QString>
#include "qnetworkaccessmanager.h"
#include <QtNetwork>
#include <QDialog>
#include <QWidget>
#include <QObject>

class Info:public QWidget
{
    Q_OBJECT
public:
    Info();

    void getIdCard();
    void getIdAccount();




    const QString &getWebToken() const;
    void setWebToken(const QByteArray &newWebToken);

    const QString &getCard_Number() const;
    void setCard_Number(const QString &newCardNumber);

    const QString &getCardId() const;
    void setCardId(const QString &newCardId);

    const QString &getAccountId() const;
    void setAccountId(const QString &newIdAccount);



private slots:

    void getIdSlot(QNetworkReply *reply);
    void getAccountSlot (QNetworkReply *reply);




private:
    QString idCard;
    QString idAccount;
    QString cardNumber;
    QString userID;
    QByteArray webToken;
    QNetworkAccessManager *idCardManager;
    QNetworkAccessManager *idAccountManager;

    QNetworkReply *reply;
    QByteArray response_data;
    void startMenuWindow();
    QByteArray bearerToken;

};


#endif // INFO_H
