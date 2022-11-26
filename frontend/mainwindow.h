#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginwindow.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


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

private:
    Ui::MainWindow *ui;
    loginWindow *objectloginWindow;


};
#endif // MAINWINDOW_H
