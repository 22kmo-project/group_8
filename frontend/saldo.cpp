#include "saldo.h"
#include "menuwindow.h"
#include "ui_saldo.h"
#include "myurl.h"
#include <QTimer>


saldo::saldo(QByteArray bearerToken, QString idAccount,QString idUser,QWidget *parent) : //Välitetään bearerToken ja idAccount
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);

    myToken = bearerToken;
    qDebug()<<"Saldo Webtoken = "+myToken;
    id_account = idAccount;
    id_user = idUser;
    qDebug()<<"Saldo ikkuna: user ID = "+id_user+" ja account ID = "+id_account;

    QString site_url=MyURL::getBaseURL()+"/account/"+idAccount;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    balanceManager = new QNetworkAccessManager(this);
    connect(balanceManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getBalanceSlot(QNetworkReply*)));
    reply = balanceManager->get(request);

    ui->labelNaytaSaldo->setText(balance);

    timer = new QTimer(this);
    connect (timer, SIGNAL (timeout()),
            this, SLOT (timeoutSlot()));
    timer->start(1000);
    time = 0;
}


saldo::~saldo()
{
    delete ui;
}


void saldo::on_poistuSaldo_clicked() //Suljetaan saldo-ikkuna
{
    timer->stop();
    saldo::close();
    menuWindow menu(myToken, id_account, id_user);
    menu.setModal(true);
    menu.exec();
}


void saldo::getBalanceSlot(QNetworkReply *reply) //Pyydetään balance tietokannasta
{
    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    qDebug()<<"Saldo getBalanceSlot response = "+response_data;

    QJsonArray json_array = json_doc.array();
    QString account ="";

    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
        account+=QString::number(json_obj["balance"].toInt())+"\n";
    }

    balance=QString::number(json_obj["balance"].toInt())+"\n";;
    qDebug()<<"Saldo: balance = "+balance;
    ui->labelNaytaSaldo->setText(balance);
}


void saldo::timeoutSlot() //Ajastin
{
    time ++;
    qDebug()<<time;
    if(time>30)
    {
        saldo::close();
        timer->stop();
    }
}


void saldo::getTransactionSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString transaction;
    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
             transaction+=json_obj["transaction_date"].toString()+"\r\n"+
                     json_obj["activity"].toString()+" , "+QString::number(json_obj["amount"].toInt())+"\r\n";
    }
    ui->label_2->setText(transaction);
}


void saldo::setBalance(const QString &newBalance)
{
    balance = newBalance;
}


void saldo::on_pushNaytaTapahtumat_clicked() // Haetaan tietokannasta tilitapahtumia
{
    time = 0;
    QString site_url=MyURL::getBaseURL()+"/transaction/fivetransactions/"+id_account;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    transactionManager = new QNetworkAccessManager(this);
    connect(transactionManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTransactionSlot(QNetworkReply*)));
    reply = transactionManager->get(request);
}


void saldo::on_pushKayttajanTiedot_clicked() // Haetaan tietokannasta käyttäjän tiedot
{
    time = 0;
    QString site_url=MyURL::getBaseURL()+"/user/"+id_user;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    tietoManager = new QNetworkAccessManager(this);
    connect(tietoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getUserSlot(QNetworkReply*)));
    reply = tietoManager->get(request);
}


void saldo::getUserSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString user;
    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
            user+=json_obj["fname"].toString()+" "+
                     json_obj["lname"].toString()+"\r\n"+json_obj["address"].toString()+" , "+"\r\n"
                     +(json_obj["phone"].toString())+"\r\n";
    }
    ui->label_3->setText(user);
}
