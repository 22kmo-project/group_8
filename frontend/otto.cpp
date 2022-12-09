#include "otto.h"
#include "ui_otto.h"
#include "myurl.h"
#include "menuwindow.h"

otto::otto(QByteArray bearerToken, QString idAccount, QString idUser, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otto)
{
    ui->setupUi(this);
    myToken = bearerToken;
    qDebug()<<"Otto: Token = "+myToken;
    id_account = idAccount;
    id_user = idUser;
    qDebug()<<"Otto: user ID = "+id_user+" ja account ID = "+id_account;
    ui->label_o->hide();

    QString site_url = MyURL::getBaseURL()+"/account/"+id_account;
    qDebug()<<"Otto osoite = "+site_url;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  Onko tämä turha rivi? Jos on niin voi poistaa

    AccountTypeManager = new QNetworkAccessManager();
    connect(AccountTypeManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getAccountTypeSlot(QNetworkReply*)));
    reply = AccountTypeManager->get(request);

    timer = new QTimer(this);
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

    timer->stop();
    time=0;
    QJsonObject jsonObjUpdate;
    jsonObjUpdate.insert("balance", balance);
    QString site_url=MyURL::getBaseURL()+"/account/balance/"+id_account;
    qDebug()<<"Otto: "+site_url;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(myToken)); //WEBTOKEN
    //qDebug()<<"Otto: poistu´BTN Token = "+myToken;

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

    requestPost.setRawHeader(QByteArray("Authorization"),(myToken)); //Hae WEBTOKEN

    transactionManager=new QNetworkAccessManager(this);
    connect(transactionManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(transactionSlot(QNetworkReply*)));
    reply = transactionManager->post(requestPost, QJsonDocument(jsonObjPost).toJson());
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
    qDebug()<<"Otto: ok_BTN maara = " << maara;
    timer->stop();
    time = 0;
    withdraw(balanceValue,maara);
}

void otto::timeoutSlot()
{
    time ++;
    qDebug()<<time;

    if(time>10 && ui->lineEdit->text().isEmpty())
    {
        otto::close();
        menuWindow menu(myToken, id_account, id_user);
        menu.setModal(true);
        menu.exec();
    }
}

void otto::getAccountTypeSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<"Otto getAccountTypeSlot response = "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    accountType=json_obj["account_type"].toString();
    balance=QString::number(json_obj["balance"].toDouble());
    creditLimit=QString::number(json_obj["credit_limit"].toDouble());
    balanceValue=QString(balance).toDouble();
    creditValue=QString(creditLimit).toDouble();
    ui->labelSaldo->setText("Tilisi saldo on " +balance);

    qDebug()<<"Otto: account balance = "+balance+", account type = "+accountType+", credit limit = "+creditLimit ;

    reply->deleteLater();
    AccountTypeManager->deleteLater();
}

void otto::withdraw(double balanssi, double maara)
{
    if(accountType == "credit")
    {
        qDebug()<<"Otto luottotili";
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
            timer->start(1000);
            time = 0;
        }
    }
    else
    {
        qDebug()<<"Otto pankkitili";
        if(balanssi - maara >= 0)
        {
            qDebug()<<"Nosto onnistui";
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
    qDebug()<<"Otto updateBalanceSlot response = "+response_data;
    reply->deleteLater();
    updateBalanceManager->deleteLater();
    otto::close();
    menuWindow menu(myToken, id_account, id_user);
    menu.setModal(true);
    menu.exec();
}

void otto::transactionSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"Otto transaction response = "+response_data;
    reply->deleteLater();
    transactionManager->deleteLater();
}



