#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QDialog>
#include "info.h"
#include <QTimer>

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:

    void on_btnPoistu_clicked();
    void on_btnKirjaudu_clicked();
    void loginSlot (QNetworkReply *reply);
    void timeoutSlot();

private:

    Ui::loginWindow *ui;
    Info *info;
    int attempts;
    int time;
    QByteArray response_data;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QString cardNumber;
    QString card_number;
    QString idUser;
    QString idAccount;
    QString pin;
    QTimer *timer;

};



#endif // LOGINWINDOW_H
