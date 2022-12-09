#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qbytearray.h>
#include "info.h"
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
    void setBalance(const QString &newBalance);


private slots:

    void on_poistuSaldo_clicked();
    void on_pushNaytaTapahtumat_clicked();
    void on_pushKayttajanTiedot_clicked();
    void getBalanceSlot (QNetworkReply *reply);
    void timeoutSlot();
    void getTransactionSlot (QNetworkReply *reply);
    void getUserSlot (QNetworkReply *reply);


private:

    Ui::saldo *ui;
    int time;
    QByteArray myToken;
    QByteArray response_data;
    QNetworkReply *reply;
    QString account;
    QString balance;
    QString id_account;
    QString id_user;
    QString transaction;
    QNetworkAccessManager *balanceManager;
    QNetworkAccessManager *tietoManager;
    QNetworkAccessManager *transactionManager;

    QTimer *timer;

};


#endif // SALDO_H
