#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginwindow.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
//#include "../group_8/backend/database"

enum SearchMode
{
    name,
    saldo,
    activity
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool editSaldo(QString account_id, int amount);

private slots:
    void on_btnSisaan_clicked();
    //QTimer *objectTimer;

private:
    Ui::MainWindow *ui;
    loginWindow *objectloginWindow;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;


    QTimer *objectTimer;
    //DLLMySQL *objectMySQL;
};
#endif // MAINWINDOW_H
