#include "loginwindow.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qnetworkreply.h"
#include "qobjectdefs.h"
#include "ui_loginwindow.h"
#include "myurl.h"
#include "mainwindow.h"


loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this, SLOT(ajastin()));
}

loginWindow::~loginWindow()
{
    delete ui;
    delete objectmenuWindow;
    objectmenuWindow=nullptr;
}

void loginWindow::on_btnPoistu_clicked()
{
    loginWindow::close();
}


void loginWindow::on_btnKirjaudu_clicked()
{
    card_number = ui->lineUsername->text();
    pin = ui->linePin->text();

    QJsonObject jsonObj;
    jsonObj.insert("card_number", card_number);
    jsonObj.insert("pin", pin);

    QString site_url=MyURL::getBaseURL()+"/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}

void loginWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    int test=QString::compare(response_data,"false");
    qDebug()<<test;

    if(response_data.length()==0)
    {
        ui->labelInfo->setText("Palvelin ei vastaa");
    }
    else
    {
        if(QString::compare(response_data,"-4078")==0){
            ui->labelInfo->setText("Virhe tietokanta yhteydessä");
        }
        else
        {
            if(test==0){
                ui->lineUsername->clear();
                ui->linePin->clear();
                ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
            }
            else {
                objectmenuWindow=new menuWindow(card_number);
                objectmenuWindow->setWebToken("Bearer "+response_data);
                objectmenuWindow->show();
                loginWindow::close();
            }
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();

}

void loginWindow::ajastin()
{
      if(loginWindow::isVisible())
    {
        timer->start(1000);
        if(aika < 10000)
        {
            loginWindow::close();
            qDebug()<<"update";
        }

    }
}
