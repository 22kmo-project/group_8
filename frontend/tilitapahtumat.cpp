#include "myurl.h"
#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"


tilitapahtumat::tilitapahtumat(QByteArray bearerToken, QString idAccount, QWidget *parent) :

    QDialog(parent),
    ui(new Ui::tilitapahtumat)
{
    ui->setupUi(this);
    myToken = bearerToken;
    qDebug()<<myToken;
    id_account = idAccount;
    qDebug()<<id_account;
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
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    tilitapahtumatManager = new QNetworkAccessManager(this);

    connect(tilitapahtumatManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(tilitapahtumatSlot(QNetworkReply*)));

    reply = tilitapahtumatManager->get(request);
}

void tilitapahtumat::timeoutSlot()
{
    time ++;
    qDebug()<<time;
    if(time>30)
    {
        tilitapahtumat::close();
        menuWindow menu(myToken, id_account);
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
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
             transaction+=json_obj["transaction_date"].toString()+"\r\n"+
                     json_obj["activity"].toString()+" , "+QString::number(json_obj["amount"].toInt())+"\r\n";
}
    ui->textTilitapahtumat->setText(transaction);

}


void tilitapahtumat::on_TakaisinBtn_clicked()
{
    timer->stop();
    tilitapahtumat::close();
    menuWindow menu(myToken, id_account);
    menu.setModal(true);
    menu.exec();
}

void tilitapahtumat::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}
