#ifndef LUOTTORAJA_H
#define LUOTTORAJA_H

#include "menuwindow.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>
#include <myurl.h>
#include <QDebug>

namespace Ui {
class luottoraja;
}

class luottoraja : public QDialog
{
    Q_OBJECT

public:

    explicit luottoraja(QByteArray bearerToken, QString idAccount, QString idUser, QWidget *parent = nullptr);
    ~luottoraja();
    void updateAccountData();

private slots:

    void on_luottoPoistu_clicked();
    void on_luotto500_clicked();
    void on_luotto1000_clicked();
    void on_luotto2000_clicked();
    void on_luotto5000_clicked();
    void on_luotto10000_clicked();
    void on_uusi_luotto_clicked();
    void setCreditLimit(double currentCreditLimit, double amount);
    void timeoutSlot();
    void getAccountTypeSlot (QNetworkReply *reply);
    void transactionSlot(QNetworkReply *reply);
    void updateCreditSlot(QNetworkReply *reply);

private:

    Ui::luottoraja *ui;
    double creditValue;
    double amount;
    int time;
    QByteArray myToken;
    QByteArray response_data;
    QString accountType;
    QString id_account;
    QString id_user;
    QString credit_limit;
    QNetworkAccessManager *accountTypeManager;
    QNetworkAccessManager *transactionManager;
    QNetworkAccessManager *updateCreditManager;
    QNetworkReply *reply;
    QTimer *timer;

};

#endif // LUOTTORAJA_H
