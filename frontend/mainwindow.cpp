#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //objectMySQL = new DLLMySQL;
    objectTimer = new QTimer;
    objectTimer->setInterval(30000);
    objectTimer->setSingleShot(true);
    connect(objectTimer, SIGNAL(timeout()), this, SLOT(on_timeout()));
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

