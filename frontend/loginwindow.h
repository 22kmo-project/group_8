#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "menuwindow.h"
#include "qnetworkaccessmanager.h"
#include <QtNetwork>
#include <QDialog>
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

private:
    Ui::loginWindow *ui;
    menuWindow *objectmenuWindow;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QTimer *timer;

    QByteArray response_data;
    QString card_number;
    QString pin;
    QString webtoken;
    int attempts;
    int time;
};

#endif // LOGINWINDOW_H
