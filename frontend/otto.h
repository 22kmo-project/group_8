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
    explicit otto(QByteArray bearerToken, QString idAccount, QWidget *parent = nullptr);
    ~otto();
    void updateAccountData();
    QString getAccountData(QString accountId);
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:


    void on_ottoPoistu_clicked();
    void on_Nosto20_clicked();
    void on_Nosto50_clicked();
    void on_Nosto100_clicked();
    void on_Nosto200_clicked();
    void on_Nosto500_clicked();
    void getAccountTypeSlot (QNetworkReply *reply);
    void withdraw(double balanssi, double maara);
    void updateBalanceSlot(QNetworkReply *reply);
    void transactionSlot(QNetworkReply *reply);

    void timeoutSlot();

    void on_ok_clicked();

private:
    Ui::otto *ui;
    QString idAccount;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray myToken;
    QString id_account;
    QString accountType;
    QNetworkAccessManager *AccountTypeManager;
    QNetworkAccessManager *updateBalanceManager;
    QNetworkAccessManager *transactionManager;
    QString balance;
    double maara;
    double balanceValue;
    QString creditLimit;
    double creditValue;
    QTimer *timer;
    int time;
    //PopUpDialog *objectPopUpDialog;
};

#endif // OTTO_H
