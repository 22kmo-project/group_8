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
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:

    void tilitapahtumatSlot (QNetworkReply *reply);
    void on_naytaTilitapahtumatBtn_clicked();
    void edellisetTitatSlot (QNetworkReply *reply);
    void seuraavatTitatSlot (QNetworkReply *reply);

    void on_TakaisinBtn_clicked();
    void timeoutSlot();

    void on_edellisetBtn_clicked();

    void on_seuraavatBtn_clicked();

private:
    Ui::tilitapahtumat *ui;
    menuWindow *objectMenuToTilitapahtumat;

    QNetworkAccessManager *tilitapahtumatManager;
    QNetworkAccessManager *edellisetTitatManager;
    QNetworkAccessManager *seuraavatTitatManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QByteArray myToken;
    QByteArray webToken;
    QString id_account;
    QString transaction;
    QString edellisetTitat;
    QString seuraavatTitat;
    QTimer *timer;
    int time;
    QString id_user;

    int calc;
    int x=0;
    int y=0;

};

#endif // TILITAPAHTUMAT_H
