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

    void on_TakaisinBtn_clicked();
    void timeoutSlot();

private:
    Ui::tilitapahtumat *ui;
    menuWindow *objectMenuToTilitapahtumat;

    QNetworkAccessManager *tilitapahtumatManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QByteArray myToken;
    QByteArray webToken;
    QString id_account;
    QString transaction;
    QTimer *timer;
    int time;
    QString id_user;

};

#endif // TILITAPAHTUMAT_H
