#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginwindow.h"
#include <QMainWindow>
#include <QTimer>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
//#include "../group_8/backend/database"

/*enum SearchMode
{
    name,
    saldo,
    activity
}; voiko poistaa? */


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSisaan_clicked();
    //QTimer *objectTimer;

private:
    Ui::MainWindow *ui;
    loginWindow *objectloginWindow;
    //QTimer *objectTimer;
    //DLLMySQL *objectMySQL;
};
#endif // MAINWINDOW_H
