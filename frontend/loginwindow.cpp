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

    delete objectChooseCardWindow;
    objectChooseCardWindow=nullptr;
}

/*QString loginWindow::getid_account(QString card_number)
{
    QSqlQuery nimiTest("SELECT id_accout FROM card WHERE card_number=?");
    nimiTest.addBindValue(card_number);
    return nimiTest.value(0).toString();
}*/

void loginWindow::on_btnPoistu_clicked()
{
    loginWindow::close();
}


void loginWindow::on_btnKirjaudu_clicked()
{
    card_number = ui->lineUsername->text();
    pin = ui->linePin->text();
    qDebug()<<card_number;
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

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    QString testi=(json_obj["id_card"].toString());

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
            else {
                if(card_number=="332211")
                {
                objectmenuWindow=new menuWindow(card_number);
                objectmenuWindow->setWebToken("Bearer "+response_data);
                objectmenuWindow->show();
                loginWindow::close();
                }
                else
                {
                    objectChooseCardWindow=new ChooseCard(card_number);
                    objectChooseCardWindow->setWebToken("Bearer "+response_data);
                    objectChooseCardWindow->show();
                    loginWindow::close();
                }



            }
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();

}
