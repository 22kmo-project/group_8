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
    void edellisetTilitapahtumatSlot (QNetworkReply *reply);
    void seuraavatTilitapahtumatSlot (QNetworkReply *reply);
    void timeoutSlot();

private:

    Ui::tilitapahtumat *ui;
    QByteArray myToken;
    QByteArray response_data;
    QNetworkAccessManager *balanceManager;
    QNetworkAccessManager *tilitapahtumatManager;
    QNetworkAccessManager *edellisetTilitapahtumatManager;
    QNetworkAccessManager *seuraavatTilitapahtumatManager;
    QNetworkReply *reply;
    QString balance;
    QString edellisetTilitapahtumat;
    QString id_account;
    QString id_user;
    QString seuraavatTilitapahtumat;
    QString transaction;
    QTimer *timer;
    int time;
    int nextPage;
    int currentPage=0;

};

#endif // TILITAPAHTUMAT_H
