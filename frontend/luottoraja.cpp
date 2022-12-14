#include "luottoraja.h"
#include "ui_luottoraja.h"
#include "myurl.h"
#include "menuwindow.h"

luottoraja::luottoraja(QByteArray bearerToken, QString idAccount, QString idUser, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::luottoraja)
{
    ui->setupUi(this);
    myToken = bearerToken;
    qDebug()<<"Luottoraja: Token = "+myToken;
    id_account = idAccount;
    id_user = idUser;
    qDebug()<<"Luottoraja ikkuna: user ID = "+id_user+" Luottoraja ikkuna: account ID = "+id_account;

    QString site_url = MyURL::getBaseURL()+"/account/"+idAccount;
    qDebug()<<"Luottoraja: Osoite = "+site_url;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  Onko tällä mitään tarkoitusta vai miksi kommenttina? Jos ei niin voi poistaa

    accountTypeManager = new QNetworkAccessManager();
    connect(accountTypeManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getAccountTypeSlot(QNetworkReply*)));
    reply = accountTypeManager->get(request);

    timer = new QTimer(this);
    connect (timer, SIGNAL (timeout()),
            this, SLOT (timeoutSlot()));
    timer->start(1000);
    time = 0;
}


void luottoraja::timeoutSlot()
{
    time ++;
    qDebug()<<time;

    if(time>10)
    {
        timer->stop();
        luottoraja::close();
        menuWindow menu(myToken, id_account,id_user);
        menu.setModal(true);
        menu.exec();
    }
}


luottoraja::~luottoraja()
{
    delete ui;
}


void luottoraja::on_luottoPoistu_clicked()
{
    timer->stop();
    luottoraja::close();
    menuWindow menu(myToken, id_account,id_user);
    menu.setModal(true);
    menu.exec();
}


void luottoraja::on_luotto500_clicked()
{
    setCreditLimit(creditValue,500);
    amount=500;
    timer->stop();
    time = 0;
}


void luottoraja::on_luotto1000_clicked()
{
    setCreditLimit(creditValue,1000);
    amount=1000;
    timer->stop();
    time = 0;
}


void luottoraja::on_luotto2000_clicked()
{
    setCreditLimit(creditValue,2000);
    amount=2000;
    timer->stop();
    time = 0;
}


void luottoraja::on_luotto5000_clicked()
{
    setCreditLimit(creditValue,5000);
    amount=5000;
    timer->stop();
    time = 0;
}


void luottoraja::on_luotto10000_clicked()
{
    setCreditLimit(creditValue,10000);
    amount=10000;
    timer->stop();
    time = 0;
}


void luottoraja::on_uusi_luotto_clicked()
{
    time = 0;
    QJsonObject jsonObjUpdate;
    jsonObjUpdate.insert("credit_limit", credit_limit);
    QString site_url=MyURL::getBaseURL()+"/account/creditlimit/"+id_account;
    qDebug()<<"Luottoraja uusi luottoBTN osoite= "+site_url;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    updateCreditManager = new QNetworkAccessManager(this);
    connect(updateCreditManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(updateCreditSlot(QNetworkReply*)));
    reply = updateCreditManager->put(request, QJsonDocument(jsonObjUpdate).toJson());

    if(amount>0)
    {//päivitetään transaction-tauluun
    QJsonObject jsonObjPost;
    jsonObjPost.insert("transaction_date",QDate::currentDate().toString((Qt::ISODate)));
    jsonObjPost.insert("activity", "luottorajan korotus");
    jsonObjPost.insert("amount", amount);
    jsonObjPost.insert("id_account",id_account);

    QString site_urlPost=MyURL::getBaseURL()+"/transaction/";
    QNetworkRequest requestPost((site_urlPost));
    requestPost.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    requestPost.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    transactionManager=new QNetworkAccessManager(this);
    connect(transactionManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(transactionSlot(QNetworkReply*)));
    reply = transactionManager->post(requestPost, QJsonDocument(jsonObjPost).toJson());
    }
}


void luottoraja::setCreditLimit(double currentCreditLimit, double amount)
{
    if(accountType == "credit")
    {
        qDebug()<<"luotto";
        currentCreditLimit = currentCreditLimit + amount;
        credit_limit=QString::number(currentCreditLimit);
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
    qDebug()<<"Luottoraja getAccountTypeSlot response = "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    accountType=json_obj["account_type"].toString();
    credit_limit=QString::number(json_obj["credit_limit"].toDouble());
    creditValue=QString(credit_limit).toDouble();

    qDebug()<<"Luottoraja ikkuna: account type = "+accountType+ " Credit limit = "+credit_limit;

    reply->deleteLater();
    accountTypeManager->deleteLater();
}


void luottoraja::transactionSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"Luottoraja transactionSlot response = "+response_data;
    reply->deleteLater();
    transactionManager->deleteLater();
}


void luottoraja::updateCreditSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"Luottoraja updateCreditSlot response = "+response_data;
    reply->deleteLater();
    updateCreditManager->deleteLater();
}

