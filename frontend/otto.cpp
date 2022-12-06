#include "otto.h"
#include "ui_otto.h"
#include "myurl.h"
#include "menuwindow.h"

otto::otto(QByteArray bearerToken, QString idAccount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otto)
{
    ui->setupUi(this);
    myToken = bearerToken;
    //qDebug()<<myToken;
    id_account = idAccount;
    qDebug()<<id_account;
    ui->label_o->hide();
    timer = new QTimer(this);

    QString site_url = MyURL::getBaseURL()+"/account/"+idAccount;
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    AccountTypeManager = new QNetworkAccessManager();

    connect(AccountTypeManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getAccountTypeSlot(QNetworkReply*)));
    reply = AccountTypeManager->get(request);

    connect (timer, SIGNAL (timeout()),
            this, SLOT (timeoutSlot()));
    timer->start(1000);
    time = 0;
}

otto::~otto()
{
    delete ui;

}


void otto::on_ottoPoistu_clicked()
{
    QJsonObject jsonObjUpdate;
    jsonObjUpdate.insert("balance", balance);
    QString site_url=MyURL::getBaseURL()+"/account/balance/"+id_account;
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    qDebug()<<myToken;
    //WEBTOKEN LOPPU

    updateBalanceManager = new QNetworkAccessManager(this);
    connect(updateBalanceManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(updateBalanceSlot(QNetworkReply*)));

    reply = updateBalanceManager->put(request, QJsonDocument(jsonObjUpdate).toJson());

    if(maara>0)
    {//päivitetään transaction-tauluun
    QJsonObject jsonObjPost;
    jsonObjPost.insert("transaction_date",QDate::currentDate().toString((Qt::ISODate)));
    jsonObjPost.insert("activity", "nosto");
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
     menuWindow menu(myToken, id_account);
     menu.setModal(true);
     menu.exec();
    }  
}


void otto::on_Nosto20_clicked()
{
    withdraw(balanceValue,20);
    maara=20;
    timer->stop();
    time = 0;

}


void otto::on_Nosto50_clicked()
{
    withdraw(balanceValue,50);
    maara=50;
    timer->stop();
    time = 0;
}


void otto::on_Nosto100_clicked()
{
    withdraw(balanceValue,100);
    maara=100;
    timer->stop();
    time = 0;
}


void otto::on_Nosto200_clicked()
{
    withdraw(balanceValue,200);
    maara=200;
    timer->stop();
    time = 0;
}

void otto::on_Nosto500_clicked()
{
    withdraw(balanceValue,500);
    maara=500;
    timer->stop();
    time = 0;
}

void otto::on_ok_clicked()
{

    maara = ui->lineEdit->text().toDouble();
    qDebug()<<maara;
    timer->stop();
    time = 0;
    withdraw(balanceValue,maara);
}

void otto::timeoutSlot()
{
    time ++;
    qDebug()<<time;

    /* Tämä koodihan ei toteudu koska label tulee näkyviin vasta kun painaa ok ja ok-nappi pysäyttää kellon
      if(time>10 && ui->label_o->isVisible())
    {
            ui->label_o->hide();
            timer->stop();
            time = 0;
    }*/
    if(time>10 && ui->lineEdit->text().isEmpty())
    {
        otto::close();
        menuWindow menu(myToken, id_account);
        menu.setModal(true);
        menu.exec();
    }
}

void otto::getAccountTypeSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    accountType=json_obj["account_type"].toString();
    balance=QString::number(json_obj["balance"].toDouble());
    creditLimit=QString::number(json_obj["credit_limit"].toDouble());
    balanceValue=QString(balance).toDouble();
    creditValue=QString(creditLimit).toDouble();
    qDebug()<<balance;
    ui->labelSaldo->setText("Tilisi saldo on " +balance);
    qDebug()<<accountType;
    qDebug()<<creditLimit;

    reply->deleteLater();
    AccountTypeManager->deleteLater();
}

void otto::withdraw(double balanssi, double maara)
{
    if(accountType == "credit")
    {
        qDebug()<<"luotto";
        if(maara - balanssi <= creditValue)
        {
            balanssi = balanssi-maara;
            balance=QString::number(balanssi);
            ui->label_o->setVisible(true);
            ui->label_o->setText("Varmista nosto painamalla poistu-painiketta.");
        }
        else
        {
            ui->label_o->setVisible(true);
            ui->label_o->setText("Tililläsi ei ole tarpeeksi rahaa. \nValitse uusi summa tai paina poistu-painiketta.");
            //timer->start(1000);
            //time = 0;
        }
    }
    else
    {
        qDebug()<<"pankki";
        if(balanssi - maara >= 0)
        {
            qDebug()<<"onnistui";
            balanssi = balanssi-maara;
            balance=QString::number(balanssi);
            ui->label_o->setVisible(true);
            ui->label_o->setText("Varmista nosto painamalla poistu-painiketta.");
        }
        else
        {
            ui->label_o->setVisible(true);
            ui->label_o->setText("Tililläsi ei ole tarpeeksi rahaa. Valitse uusi summa tai paina poistu-painiketta.");
            timer->start(1000);
            time=0;

        }
    }
}

void otto::updateBalanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    updateBalanceManager->deleteLater();
    otto::close();
}

void otto::transactionSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    transactionManager->deleteLater();
    otto::close();
}







