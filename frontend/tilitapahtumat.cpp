#include "myurl.h"
#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"


tilitapahtumat::tilitapahtumat(QByteArray bearerToken, QString idAccount, QString idUser, QWidget *parent) :

    QDialog(parent),
    ui(new Ui::tilitapahtumat)
{
    ui->setupUi(this);
    ui->edellisetBtn->hide();
    ui->seuraavatBtn->hide();
    myToken = bearerToken;
    qDebug()<<"Tilitapahtumat Token = "+myToken;
    id_account = idAccount;
    id_user = idUser;
    qDebug()<<"Tilitapahtumat: user ID = "+id_user+ " ja Account = "+id_account;

    QString site_url=MyURL::getBaseURL()+"/account/"+idAccount;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    balanceManager = new QNetworkAccessManager(this);
    connect(balanceManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getBalanceSlot(QNetworkReply*)));
    reply = balanceManager->get(request);

    timer = new QTimer(this);
    connect (timer, SIGNAL (timeout()),
                this, SLOT (timeoutSlot()));
    timer->start(1000);
    time = 0;
}

tilitapahtumat::~tilitapahtumat()
{
    delete ui;
}

void tilitapahtumat::on_naytaTilitapahtumatBtn_clicked()
{
    time = 0;
    QString site_url=MyURL::getBaseURL()+"/transaction/"+id_account;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    tilitapahtumatManager = new QNetworkAccessManager(this);
    connect(tilitapahtumatManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(tilitapahtumatSlot(QNetworkReply*)));
    reply = tilitapahtumatManager->get(request);

    ui->edellisetBtn->show();
}

void tilitapahtumat::getBalanceSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    qDebug()<<"Tilitapahtumat getBalanceSlot response = "+response_data;

    QJsonArray json_array = json_doc.array();
    QString account ="";


    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
        account+=QString::number(json_obj["balance"].toInt())+"\n";
    }

    balance=QString::number(json_obj["balance"].toInt())+"\n";;
    qDebug()<<"Saldo: balance = "+balance;
    ui->labelSaldo->setText("Saldosi on "+balance);
}

void tilitapahtumat::timeoutSlot()
{
    time ++;
    qDebug()<<time;
    if(time>30)
    {
        tilitapahtumat::close();
        menuWindow menu(myToken, id_account, id_user);
        menu.setModal(true);
        menu.exec();
    }
}

void tilitapahtumat::tilitapahtumatSlot(QNetworkReply *reply)
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
    ui->textTilitapahtumat->setText(transaction);
    //x=calc;

}

void tilitapahtumat::edellisetTitatSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    //qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString edellisetTitat;
    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
        edellisetTitat+=json_obj["transaction_date"].toString()+"\r\n"+
                json_obj["activity"].toString()+" , "+QString::number(json_obj["amount"].toInt())+"\r\n";
    }
    //jos ei tulostu mitään, piilotetaan edellisetBtn
    if(response_data=="[]") {
        ui->edellisetBtn->hide();
    }
    ui->textTilitapahtumat->setText(edellisetTitat);
    ui->seuraavatBtn->show();
    x = calc;
    qDebug()<<x;
}

void tilitapahtumat::seuraavatTitatSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    //qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString seuraavatTitat;
    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
        seuraavatTitat+=json_obj["transaction_date"].toString()+"\r\n"+
                json_obj["activity"].toString()+" , "+QString::number(json_obj["amount"].toInt())+"\r\n";
    }
    ui->textTilitapahtumat->setText(seuraavatTitat);
    x = calc;
}


void tilitapahtumat::on_TakaisinBtn_clicked()
{
    timer->stop();
    tilitapahtumat::close();
    menuWindow menu(myToken, id_account, id_user);
    menu.setModal(true);
    menu.exec();
}


void tilitapahtumat::on_edellisetBtn_clicked()
{
    time = 0;
    calc = x+10;
    QString pena = QString::number(calc);

    QString site_url=MyURL::getBaseURL()+"/transaction/"+id_account+"/"+pena;
    QNetworkRequest request((site_url));
    qDebug()<<site_url;
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    edellisetTitatManager = new QNetworkAccessManager(this);

    connect(edellisetTitatManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(edellisetTitatSlot(QNetworkReply*)));

    reply = edellisetTitatManager->get(request);
}


void tilitapahtumat::on_seuraavatBtn_clicked()
{
    time = 0;
    qDebug()<<calc;
    if (calc >= 10){
    calc = x-10;
    } else {
        calc = 0;
        ui->seuraavatBtn->hide();
    }

    QString pena = QString::number(calc);

    QString site_url=MyURL::getBaseURL()+"/transaction/"+id_account+"/"+pena;
    QNetworkRequest request((site_url));
    qDebug()<<site_url;
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    seuraavatTitatManager = new QNetworkAccessManager(this);

    connect(seuraavatTitatManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(seuraavatTitatSlot(QNetworkReply*)));

    reply = seuraavatTitatManager->get(request);
}

