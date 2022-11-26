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
    attempts=0;
}

loginWindow::~loginWindow()
{
    delete ui;
    delete objectmenuWindow;
    objectmenuWindow=nullptr;

    //delete objectChooseCardWindow;
    //objectChooseCardWindow=nullptr;
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

    /*bool credit;
    if(jason_obj["card_type"].toInt()==1)
    {
        credit == true;
    }
    else
    {
        credit = false;
    }*/

    if(test==-1)
    {
        /*if(credit==true)
        {
            objectChooseCardWindow= new ChooseCard(card_number);
            objectChooseCardWindow->setWebToken("Bearer "+response_data);
        }*/
        objectmenuWindow=new menuWindow(card_number, false);
        objectmenuWindow->setWebToken("Bearer "+response_data);
        objectmenuWindow->show();
        loginWindow::close();
    }

    else
    {
        if(attempts < 2)
        {
            ++attempts;
            ui->lineUsername->clear();
            ui->linePin->clear();
            qDebug()<<"Yritykset"<<attempts;

        }
        else
        {
            ui->labelInfo->setText("Kortti on lukittu, sulje ikkuna ja yritä uudestaan");
        }
    }

    reply->deleteLater();
    loginManager->deleteLater();

}

