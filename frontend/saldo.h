#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qbytearray.h>
#include "myurl.h"
#include <QMainWindow>
#include <QtNetwork>



namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(QByteArray bearerToken, QString idAccount, QWidget *parent = nullptr);
    ~saldo();
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);



private slots:

    void getSaldo (QNetworkReply *reply);
    void on_poistuSaldo_clicked();
    //void on_textnaytaSaldo_textChanged();





private:
    Ui::saldo *ui;
    QByteArray webToken;
    QNetworkAccessManager *saldoManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString account;
    QByteArray myToken;
    QString id_account;







};

#endif // SALDO_H
