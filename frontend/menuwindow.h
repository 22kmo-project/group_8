#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "info.h"
#include <QDialog>
#include <QTimer>

namespace Ui {
class menuWindow;
}

class menuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit menuWindow(QByteArray bearerToken, QString idAccount, QWidget *parent = nullptr);
    ~menuWindow();

    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_pushButton_KirjauduUlos_clicked();
    void on_pushButton_Otto_clicked();
    void on_pushButton_LuottorajanNosto_clicked();
    void on_pushButton_Tilitapahtumat_clicked();
    void on_pushButton_Saldo_clicked();

private slots:
    void getOwnerSlot (QNetworkReply *reply);
    void timeoutSlot();

private:
    Ui::menuWindow *ui;
    QByteArray webToken;
    bool isCredit;
    QString id_card;
    QString id_account;
    QNetworkAccessManager *idCardManager;
    QNetworkAccessManager *ownerManager;
    QNetworkReply *reply;
    QString cardNumber;
    QByteArray token;
    Info *info;
    QByteArray response_data;
    QString owner;
    int time;
    QTimer *timer;
};

#endif // MENUWINDOW_H
