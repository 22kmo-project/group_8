#ifndef OTTO_H
#define OTTO_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <myurl.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>


namespace Ui {
class otto;
}

class otto : public QDialog
{
    Q_OBJECT

public:

    explicit otto(QByteArray bearerToken, QString idAccount, QString idUser, QWidget *parent = nullptr);
    ~otto();
    void updateAccountData();

private slots:

    void on_ottoPoistu_clicked();
    void on_Nosto20_clicked();
    void on_Nosto50_clicked();
    void on_Nosto100_clicked();
    void on_Nosto200_clicked();
    void on_Nosto500_clicked();
    void on_ok_clicked();
    void withdraw(double balanssi, double maara);
    void getAccountTypeSlot (QNetworkReply *reply);
    void updateBalanceSlot(QNetworkReply *reply);
    void transactionSlot(QNetworkReply *reply);
    void timeoutSlot();

private:

    Ui::otto *ui;
    double balanceValue;
    double creditValue;
    double maara;
    int time;
    QByteArray myToken;
    QByteArray response_data;
    QNetworkReply *reply;
    QString accountType;
    QString balance;
    QString creditLimit;
    QString id_account;
    QString id_user;
    QNetworkAccessManager *AccountTypeManager;
    QNetworkAccessManager *updateBalanceManager;
    QNetworkAccessManager *transactionManager;
    QTimer *timer;

};

#endif // OTTO_H
