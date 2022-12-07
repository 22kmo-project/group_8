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
    explicit luottoraja(QByteArray bearerToken, QString idAccount, QWidget *parent = nullptr);
    ~luottoraja();
    void updateAccountData();
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_luottoPoistu_clicked();
    void on_luotto500_clicked();
    void on_luotto1000_clicked();
    void on_luotto2000_clicked();
    void on_luotto5000_clicked();
    void on_luotto10000_clicked();
    void setlimit(double luottoraja, double maara);
    void timeoutSlot();
    void on_uusi_luotto_clicked();
    void getAccountTypeSlot (QNetworkReply *reply);
    void transactionSlot(QNetworkReply *reply);
    void updateCreditSlot(QNetworkReply *reply);

private:
    Ui::luottoraja *ui;
    menuWindow *objectMenuToLuottoraja;
    QByteArray myToken;
    QByteArray webToken;
    QString id_account;
    QString accountType;
    QNetworkAccessManager *AccountTypeManager;
    QNetworkAccessManager *transactionManager;
    QNetworkAccessManager *updateCreditManager;
    QString credit_limit;
    double maara;
    double creditValue;
    QString creditLimit;
    QTimer *timer;
    int time;
    QByteArray response_data;
    QNetworkReply *reply;
};

#endif // LUOTTORAJA_H
