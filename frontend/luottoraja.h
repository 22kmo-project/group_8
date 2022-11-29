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
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:


    void on_luottoPoistu_clicked();

    void on_luottoHae_clicked();

private:
    Ui::luottoraja *ui;
    menuWindow *objectMenuToLuottoraja;
    QByteArray myToken;
    QByteArray webToken;
};

#endif // LUOTTORAJA_H
