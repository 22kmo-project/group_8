#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "info.h"
#include <QDialog>



namespace Ui {
class menuWindow;
}

class menuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit menuWindow(Info *info =nullptr, QWidget *parent = nullptr);
    ~menuWindow();

    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_pushButton_KirjauduUlos_clicked();

    void on_pushButton_Otto_clicked();

    void on_pushButton_LuottorajanNosto_clicked();

    void on_pushButton_Saldo_clicked();

private:
    Ui::menuWindow *ui;
    QByteArray webToken;
    bool isCredit;
    QString id_card;
    QNetworkAccessManager *idCardManager;
    QNetworkReply *reply;
    QString cardNumber;
    QByteArray token;
    Info *info;
};

#endif // MENUWINDOW_H
