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
    explicit menuWindow(QByteArray bearerToken, QString idAccount,QString idUser,  QWidget *parent = nullptr);
    ~menuWindow();


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
    int time;
    QByteArray webToken;
    QByteArray response_data;
    QString id_account;
    QString id_card;
    QString id_user;
    QString accountOwner;
    QNetworkAccessManager *idCardManager;
    QNetworkAccessManager *ownerManager;
    QNetworkReply *reply;
    QTimer *timer;

};

#endif // MENUWINDOW_H
