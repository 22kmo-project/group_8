#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "saldo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectloginWindow;
    objectloginWindow=nullptr;
}


void MainWindow::on_btnSisaan_clicked()
{
    objectloginWindow = new loginWindow();
    objectloginWindow->show();
}

