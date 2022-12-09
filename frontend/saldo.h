#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qbytearray.h>
#include "info.h"
#include "myurl.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QTimer>




namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(QByteArray bearerToken, QString idAccount, QString idUser, QWidget *parent = nullptr);
    ~saldo();
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);
    void setBalance(const QString &newBalance);


private slots:

    void on_poistuSaldo_clicked();
    void getBalanceSlot (QNetworkReply *reply);
    void timeoutSlot();
    void getTransactionSlot (QNetworkReply *reply);
    void on_pushNaytaTapahtumat_clicked();
    void on_pushKayttajanTiedot_clicked();
    void getUserSlot (QNetworkReply *reply);


private:
    Ui::saldo *ui;
    QByteArray webToken;
    QNetworkReply *reply;
    QByteArray response_data;
    QString account;
    QByteArray myToken;
    QString id_account;
    QString balance;
    QString transaction;
    QString id_user;
    QNetworkAccessManager *balanceManager;
    QNetworkAccessManager *transactionManager;
    QNetworkAccessManager *tietoManager;

    int time;
    QTimer *timer;

    Info *info;


};


#endif // SALDO_H
