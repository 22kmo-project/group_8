#ifndef LUOTTORAJA_H
#define LUOTTORAJA_H

#include "menuwindow.h"
#include <QDialog>

namespace Ui {
class luottoraja;
}

class luottoraja : public QDialog
{
    Q_OBJECT

public:
    explicit luottoraja(QByteArray wt, QWidget *parent = nullptr);
    ~luottoraja();

private slots:


    void on_luottoPoistu_clicked();

    void on_luottoHae_clicked();

private:
    Ui::luottoraja *ui;
    menuWindow *objectMenuToLuottoraja;
};

#endif // LUOTTORAJA_H
