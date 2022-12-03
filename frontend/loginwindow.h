#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QDialog>
#include "info.h"

//#include <QSqlQuery>

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
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    Info *info;
    QByteArray response_data;
    QString card_number;
    QString pin;
    int attempts;
    int time;
};



#endif // LOGINWINDOW_H
