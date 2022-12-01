#ifndef OTTO_H
#define OTTO_H

#include "menuwindow.h"
#include <QDialog>
#include "mainwindow.h"
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtWidgets>
#include <QSqlTableModel>
#include <QDateTime>
#include <QTimer>
#include <QJsonObject>
#include <myurl.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


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
    void addActivity(QString accountID, int amount);
    void editSaldo(QString accountID, int amount); //QString account_type);
    QString getAccountData(QString accountId);
    void withdraw(int amount);// QString account_type);
    void resetTimer();
    int amount;
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:


    void on_ottoPoistu_clicked();
    //void on_ottoNosta_clicked();
    void on_Nosto10_clicked();
    void on_Nosto20_clicked();
    void on_Nosto50_clicked();
    void on_Nosto100_clicked();
    void on_Nosto200_clicked();
    void ottoSlot (QNetworkReply *reply);

private:
    Ui::otto *ui;
    QSqlQuery *query;
    QTimer *objectTimer;
    QString accountId;
    QNetworkAccessManager *ottoManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray myToken;
    QByteArray webToken;
    QString id_account;
    //PopUpDialog *objectPopUpDialog;
};

#endif // OTTO_H
