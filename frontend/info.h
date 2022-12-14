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

    void getIdUser();
    void getIdAccount();

    const QString &getWebToken() const;
    void setWebToken(const QByteArray &newWebToken);

    const QString &getCard_Number() const;
    void setCard_Number(const QString &newCardNumber);

    const QString &getUserId() const;
    void setUserId(const QString &newCardId);

    const QString &getAccountId() const;
    void setAccountId(const QString &newIdAccount);

private slots:

    void getUserIdSlot(QNetworkReply *reply);
    void getAccountSlot (QNetworkReply *reply);

private:
    QByteArray webToken;
    QByteArray bearerToken;
    QByteArray response_data;
    QNetworkAccessManager *idUserManager;
    QNetworkAccessManager *idAccountManager;
    QNetworkReply *reply;
    QString idUser;
    QString idAccount;
    QString cardNumber;
    void startMenuWindow();
};


#endif // INFO_H
