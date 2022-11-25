#include "loginwindow.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qnetworkreply.h"
#include "qobjectdefs.h"
#include "ui_loginwindow.h"
#include "myurl.h"


loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);

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
    int attempts=0;
    response_data=reply->readAll();
    qDebug()<<response_data;
    int test=QString::compare(response_data,"false");
    qDebug()<<test;

    if(test==-1)
    {
        objectmenuWindow=new menuWindow(card_number);
        objectmenuWindow->setWebToken("Bearer "+response_data);
        objectmenuWindow->show();
        loginWindow::close();
    }

    else
    {
        if(attempts < 3)
        {
            ui->lineUsername->clear();
            ui->linePin->clear();
            qDebug()<<"Yritykset"<<attempts;
            attempts ++;
        }
        else
        {
            ui->labelInfo->setText("Kolme yritystä");
            loginWindow::close();
        }
    }

    reply->deleteLater();
    loginManager->deleteLater();

}

