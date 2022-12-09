#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "myurl.h"

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    attempts=0;
    timer = new QTimer(this);
    connect (timer, SIGNAL (timeout()),
            this, SLOT (timeoutSlot()));
    timer->start(1000);
    time = 0;

}

loginWindow::~loginWindow()
{
    delete ui;

}


void loginWindow::on_btnPoistu_clicked()
{
    timer->stop();
    loginWindow::close();
}


void loginWindow::on_btnKirjaudu_clicked()
{
    card_number = ui->lineUsername->text();
    pin = ui->linePin->text();

    qDebug()<<"LoginWindow: Card ID = "+card_number;

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
    qDebug()<<"Info loginSlot response = "+response_data;
    int test=QString::compare(response_data,"false");
    qDebug()<<test;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();


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
                if(attempts < 2) //käyttäjällä on 3 yritystä kirjautua.
                {
                    ++attempts;
                    ui->lineUsername->clear();
                    ui->linePin->clear();
                    qDebug()<<"Yritykset"<<attempts;
                }
                else
                { //jos yrityksiä tulee kolme, kirjaudu-nappi häviää ja käyttäjän täytyy sulkea ikkuna voidakseen yrittää uudelleen.
                    ui->labelInfo->setText("Kortti on lukittu, sulje ikkuna ja yritä uudestaan");
                    ui->btnKirjaudu->hide();

                }
            }
            else { //jos kirjautuminen onnistuu luodaan olio info-luokasta. välitetään luokalle kortin numero, sekä responsedata
                    info = new Info();
                    info->setWebToken(response_data);
                    info->setCard_Number(card_number);
                    info->getIdUser();

                    timer->stop();
                    //info->getAccount_Type(account_Type);
                    loginWindow::close();
                }
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();

}

void loginWindow::timeoutSlot()
{
    time ++;
    qDebug()<<time;
    if(time>10 && ui->lineUsername->text().isEmpty() && ui->linePin->text().isEmpty())
    {
        loginWindow::close();
        timer->stop();
    }
}
