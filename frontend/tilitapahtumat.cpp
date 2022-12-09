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
    connect(balanceManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getBalanceSlot(QNetworkReply*)));
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
    currentPage = 0;
    time = 0;
    QString site_url=MyURL::getBaseURL()+"/transaction/"+id_account;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    tilitapahtumatManager = new QNetworkAccessManager(this);
    connect(tilitapahtumatManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(tilitapahtumatSlot(QNetworkReply*)));
    reply = tilitapahtumatManager->get(request);

    ui->edellisetBtn->show();
    ui->seuraavatBtn->hide();
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
}


void tilitapahtumat::edellisetTilitapahtumatSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    //qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString edellisetTilitapahtumat;
    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
        edellisetTilitapahtumat+=json_obj["transaction_date"].toString()+"\r\n"+
                json_obj["activity"].toString()+" , "+QString::number(json_obj["amount"].toInt())+"\r\n";
    }

    ui->seuraavatBtn->show();
    //jos ei tulostu mitään, piilotetaan edellisetBtn
    if(response_data=="[]") {
        ui->edellisetBtn->hide();
    }
    ui->textTilitapahtumat->setText(edellisetTilitapahtumat);
    qDebug()<<currentPage;
}


void tilitapahtumat::seuraavatTilitapahtumatSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    //qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString seuraavatTilitapahtumat;
    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
        seuraavatTilitapahtumat+=json_obj["transaction_date"].toString()+"\r\n"+
                json_obj["activity"].toString()+" , "+QString::number(json_obj["amount"].toInt())+"\r\n";
    }
    ui->edellisetBtn->show();
    ui->textTilitapahtumat->setText(seuraavatTilitapahtumat);
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

    currentPage = currentPage+10;
    QString page = QString::number(currentPage);

    QString site_url=MyURL::getBaseURL()+"/transaction/"+id_account+"/"+page;
    QNetworkRequest request((site_url));
    qDebug()<<site_url;

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    edellisetTilitapahtumatManager = new QNetworkAccessManager(this);
    connect(edellisetTilitapahtumatManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(edellisetTilitapahtumatSlot(QNetworkReply*)));
    reply = edellisetTilitapahtumatManager->get(request);
}


void tilitapahtumat::on_seuraavatBtn_clicked()
{
    time = 0;
    qDebug()<<currentPage;
    currentPage = currentPage-10;

    if(currentPage < 10)
    {
        ui->seuraavatBtn->hide();
    }
    else
    {
        ui->seuraavatBtn->show();
    }

    QString page = QString::number(currentPage);

    QString site_url=MyURL::getBaseURL()+"/transaction/"+id_account+"/"+page;
    QNetworkRequest request((site_url));
    qDebug()<<site_url;

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN

    seuraavatTilitapahtumatManager = new QNetworkAccessManager(this);
    connect(seuraavatTilitapahtumatManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(seuraavatTilitapahtumatSlot(QNetworkReply*)));
    reply = seuraavatTilitapahtumatManager->get(request);
}

