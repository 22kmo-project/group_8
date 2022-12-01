#include "mainwindow.h"

#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    time = 0;
    QObject::connect(ui->btnSisaan, SIGNAL(clicked()), this, SLOT(KirjauduWidget()));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(on_btnSisaan_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SisaanWidget()
{
    QObject::connect(ui->btnSisaan, SIGNAL(clicked()), this, SLOT(KirjauduWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_sisaan);
    /*if(time == 10000)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_sisaan);
    }*/
}

void MainWindow::KirjauduWidget()
{
    QObject::connect(ui->btnKirjaudu, SIGNAL(clicked()), this, SLOT(ValitseKorttiWidget()));
    QObject::connect(ui->btnPoistu, SIGNAL(clicked()), this, SLOT(SisaanWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_kirjaudu);
    ui->labelkayttajan_nimi->setText(card_number);
}

void MainWindow::ValitseKorttiWidget()
{
    QObject::connect(ui->btnDebit, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    QObject::connect(ui->btnCredit, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_valitseKortti);
}
void MainWindow::MenuWidget()
{

    QObject::connect(ui->btnSaldo, SIGNAL(clicked()), this, SLOT(SaldoWidget()));
    QObject::connect(ui->btnTilitapahtumat, SIGNAL(clicked()), this, SLOT(TilitapahtumatWidget()));
    QObject::connect(ui->btnOtto, SIGNAL(clicked()), this, SLOT(OttoWidget()));
    QObject::connect(ui->btnLuottorajanNosto, SIGNAL(clicked()), this, SLOT(LuottorajanNostoWidget()));
    QObject::connect(ui->btnPoistu_2, SIGNAL(clicked()), this, SLOT(SisaanWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_menu);
}

void MainWindow::SaldoWidget()
{
    QObject::connect(ui->btnTakaisin_3, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_saldo);
}

void MainWindow::TilitapahtumatWidget()
{
    QObject::connect(ui->btnTakaisin_4, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_tilitapahtumat);
}

void MainWindow::OttoWidget()
{
    QObject::connect(ui->btnTakaisin_2, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_otto);
}

void MainWindow::LuottorajanNostoWidget()
{
    QObject::connect(ui->btnTakaisin, SIGNAL(clicked()), this, SLOT(MenuWidget()));
    ui->stackedWidget->setCurrentWidget(ui->page_nostaLuottorajaa);
}

void MainWindow::on_btnKirjaudu_clicked()
{
    timer->stop();
    card_number=ui->lineEdit_cardnumber->text();
    pin=ui->lineEdit_pin->text();

     QJsonObject jsonObj;
     jsonObj.insert("card_number",card_number);
     jsonObj.insert("pin",pin);

     QString site_url=MyURL::getBaseURL()+"/login";
     QNetworkRequest request((site_url));
     request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


     loginManager = new QNetworkAccessManager(this);
     connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

     reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}


void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
        qDebug()<<response_data;
        int test=QString::compare(response_data,"false");
        qDebug()<<test;
        if(test==-1)
        {
            ui->stackedWidget->setCurrentWidget(ui->page_menu);
        }

        if(test==0)
            {
                ui->lineEdit_cardnumber->clear();
                ui->lineEdit_pin->clear();
                timer->stop();
                time = 0;
                timer->start(1000);
                time ++;
                qDebug()<<time;
                if(time < 10)
                {
                    ui->stackedWidget->setCurrentWidget(ui->page_kirjaudu);
                }
                else
                {
                    ui->stackedWidget->setCurrentWidget(ui->page_valitseKortti);
                    timer->stop();
                }
            }

        reply->deleteLater();
        loginManager->deleteLater();
}


void MainWindow::on_btnSisaan_clicked()
{
    timer->start(1000);
    time ++;
    qDebug()<<time;
    if(time < 10)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_kirjaudu);
    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->page_sisaan);
        timer->stop();
        time = 0;
    }

}


void MainWindow::on_btnPoistu_clicked()
{
    timer->stop();
    time = 0;
    ui->stackedWidget->setCurrentWidget(ui->page_sisaan);

}


void MainWindow::on_btnPoistu_2_clicked()
{
    timer->stop();
    time=0;
        ui->stackedWidget->setCurrentWidget(ui->page_sisaan);
}
