#ifndef SALDO_H
#define SALDO_H

#include "menuwindow.h"
#include <QDialog>

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
    void on_saldoTakaisin_clicked();

private:
    Ui::saldo *ui;
    menuWindow *objectMenuToSaldo;
};

#endif // SALDO_H
