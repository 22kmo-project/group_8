#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include "menuwindow.h"
#include <QDialog>
#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QJsonDocument>
#include <QTimer>

namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QDialog
{
    Q_OBJECT

public:

    explicit tilitapahtumat(QByteArray bearerToken, QString idAccount, QString idUser, QWidget *parent = nullptr);
    ~tilitapahtumat();

private slots:

    void on_naytaTilitapahtumatBtn_clicked();
    void on_edellisetBtn_clicked();
    void on_seuraavatBtn_clicked();
    void on_TakaisinBtn_clicked();
    void tilitapahtumatSlot (QNetworkReply *reply);
    void getBalanceSlot (QNetworkReply *reply);
    void edellisetTitatSlot (QNetworkReply *reply);
    void seuraavatTitatSlot (QNetworkReply *reply);
    void timeoutSlot();



private:
    Ui::tilitapahtumat *ui;
    int time;
    QByteArray myToken;
    QByteArray response_data;
    QNetworkAccessManager *balanceManager;
    QNetworkAccessManager *tilitapahtumatManager;
    QNetworkAccessManager *edellisetTitatManager;
    QNetworkAccessManager *seuraavatTitatManager;
    QNetworkReply *reply;
    QString balance;
    QString edellisetTitat;
    QString id_account;
    QString id_user;
    QString seuraavatTitat;
    QString transaction;
    QTimer *timer;


    int calc;
    int x=0;
    int y=0;

};

#endif // TILITAPAHTUMAT_H
