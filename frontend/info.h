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

    const QString &getIdAccount() const;
    void setIdAccount(const QString &newIdAccount);

    const QString &getAccount_Type() const;
    void setAccount_Type(const QString &newAccount_Type);





private slots:

    void getIdSlot(QNetworkReply *reply);
    void getAccountSlot (QNetworkReply *reply);

private:
    QString idCard;
    QString idAccount;
    QString cardNumber;
    QByteArray webToken;
    QNetworkAccessManager *idCardManager;
    QNetworkAccessManager *idAccountManager;
    QNetworkReply *reply;
    QByteArray response_data;
    void startMenuWindow();
    QByteArray bearerToken;
    QString account_Type;
};

#endif // INFO_H
