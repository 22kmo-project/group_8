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
    const QString &getWebToken() const;
    void setWebToken(const QByteArray &newWebToken);

    const QString &getCard_Number() const;
    void setCard_Number(const QString &newCardNumber);

    const QString &getCardId() const;
    void setCardId(const QString &newCardId);

private slots:

    void getIdSlot(QNetworkReply *reply);

private:
    QString idCard;
    QString cardNumber;
    QByteArray webToken;
    QNetworkAccessManager *idCardManager;
    QNetworkReply *reply;
    QByteArray response_data;
    void startMenuWindow();
    QByteArray bearerToken;
};

#endif // INFO_H
