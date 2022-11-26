#ifndef SALDO_H
#define SALDO_H

#include "menuwindow.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(QWidget *parent = nullptr);
    ~saldo();

private slots:


    void on_poistuSaldo_clicked();


private:
    Ui::saldo *ui;
    menuWindow *objectMenuToSaldo;
};

#endif // SALDO_H
