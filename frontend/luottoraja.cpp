#include "luottoraja.h"
#include "ui_luottoraja.h"
#include "myurl.h"
#include "menuwindow.h"

luottoraja::luottoraja(QByteArray bearerToken, QString idAccount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::luottoraja)
{
    ui->setupUi(this);
    myToken = bearerToken;
    qDebug()<<myToken;
    id_account = idAccount;
    qDebug()<<id_account;

}

void luottoraja::timeoutSlot()
{
    time ++;
    qDebug()<<time;
    if(time>10 && ui->label_luotto->isVisible())
    {
            ui->label_luotto->hide();
            timer->stop();
            time = 0;
    }
    if(time>10)
    {
        luottoraja::close();
        menuWindow menu(myToken, id_account);
        menu.setModal(true);
        menu.exec();
    }
}

luottoraja::~luottoraja()
{
    delete ui;
}

void luottoraja::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}




void luottoraja::on_luottoPoistu_clicked()
{
    luottoraja::close();
}



void luottoraja::on_luotto500_clicked()
{
    setlimit(creditLimit,500);
    maara=500;
    timer->stop();
    time = 0;
}


void luottoraja::on_luotto1000_clicked()
{
    setlimit(creditLimit,1000);
    maara=1000;
    timer->stop();
    time = 0;
}


void luottoraja::on_luotto2000_clicked()
{
    setlimit(creditLimit,2000);
    maara=2000;
    timer->stop();
    time = 0;
}


void luottoraja::on_luotto5000_clicked()
{
    setlimit(creditLimit,5000);
    maara=5000;
    timer->stop();
    time = 0;
}


void luottoraja::on_luotto10000_clicked()
{
    setlimit(creditLimit,10000);
    maara=10000;
    timer->stop();
    time = 0;
}

void luottoraja::on_uusi_luotto_clicked()
{
    QJsonObject jsonObjUpdate;
    jsonObjUpdate.insert("credit_limit", credit_limit);
    QString site_url=MyURL::getBaseURL()+"/account/credit_limit/"+id_account;
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    qDebug()<<myToken;
    //WEBTOKEN LOPPU

    updateCreditManager = new QNetworkAccessManager(this);
    connect(updateCreditManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(updateCreditSlot(QNetworkReply*)));

    reply = updateCreditManager->put(request, QJsonDocument(jsonObjUpdate).toJson());

    if(maara>0)
    {//päivitetään transaction-tauluun
    QJsonObject jsonObjPost;
    jsonObjPost.insert("transaction_date",QDate::currentDate().toString((Qt::ISODate)));
    jsonObjPost.insert("activity", "luottoraja");
    jsonObjPost.insert("amount", maara);
    jsonObjPost.insert("id_account",id_account);

    QString site_urlPost=MyURL::getBaseURL()+"/transaction/";
    QNetworkRequest requestPost((site_urlPost));
    requestPost.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    requestPost.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    transactionManager=new QNetworkAccessManager(this);
    connect(transactionManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(transactionSlot(QNetworkReply*)));

     reply = transactionManager->post(requestPost, QJsonDocument(jsonObjPost).toJson());
    }
}

void luottoraja::setlimit(double luottoraja, double maara)
{
    if(accountType == "credit")
    {
        qDebug()<<"luotto";
        creditValue = maara + credit_limit;

        creditLimit = creditLimit + maara;
        credit_limit=QString::number(luottoraja);
        ui->uusi_luotto->setVisible(true);
        ui->label_luotto->setText("Varmista korottaminen painamalla Tallenna uusi luottoraja-painiketta.");
        }
        else
        {
            ui->uusi_luotto->setVisible(false);
            ui->label_luotto->setText("Et voi tehdä korotusta debit-kortilla");
            timer->start(1000);
            time = 0;
        }
}

void luottoraja::getAccountTypeSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    accountType=json_obj["account_type"].toString();
    creditLimit=QString::number(json_obj["credit_limit"].toDouble());
    creditValue=QString(creditLimit).toDouble();
    qDebug()<<accountType;
    qDebug()<<creditLimit;

    reply->deleteLater();
    AccountTypeManager->deleteLater();
}

void luottoraja::transactionSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    transactionManager->deleteLater();
    luottoraja::close();
    menuWindow menu(myToken, id_account);
    menu.setModal(true);
    menu.exec();
}

void luottoraja::updateCreditSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    updateCreditManager->deleteLater();
    luottoraja::close();
    menuWindow menu(myToken, id_account);
    menu.setModal(true);
    menu.exec();
}

