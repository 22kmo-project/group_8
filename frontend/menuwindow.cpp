#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "otto.h"
#include "luottoraja.h"
#include "tilitapahtumat.h"
#include "saldo.h"



menuWindow::menuWindow(QByteArray bearerToken, QString idAccount, QString idUser, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    webToken = bearerToken;
    id_account = idAccount;
    id_user = idUser;

    QString site_url=MyURL::getBaseURL()+"/account/"+idAccount;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken)); // WEBTOKEN

    ownerManager = new QNetworkAccessManager(this);
    qDebug()<<"MenuWindow: TOKENI = "+webToken;

    connect(ownerManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getOwnerSlot(QNetworkReply*)));
    reply = ownerManager->get(request);
    ui->labelCardnumber->setText(accountOwner);

    timer = new QTimer(this);
    connect (timer, SIGNAL (timeout()),
            this, SLOT (timeoutSlot()));
    timer->start(1000);
    time = 0;
}


void menuWindow::getOwnerSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<"MenuWindow getOwnerSlot response = "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    accountOwner=json_obj["account_owner"].toString();

    qDebug()<<"Menuwindow: tilin omistaja = "+accountOwner;

    reply->deleteLater();
    ui->labelCardnumber->setText("Tervetuloa "+accountOwner+"!");
}


void menuWindow::timeoutSlot()
{
    time ++;
    qDebug()<<time;
    if(time>30)
    {
        menuWindow::close();
        timer->stop();
    }
}


menuWindow::~menuWindow()
{
    delete ui;
}


void menuWindow::on_pushButton_KirjauduUlos_clicked()
{
    timer->stop();
    menuWindow::close();
}


void menuWindow::on_pushButton_Saldo_clicked()
{
    timer->stop();
    class saldo nayta(webToken,id_account,id_user);
    nayta.setModal(true);
    nayta.exec();
    menuWindow::close();
}


void menuWindow::on_pushButton_Otto_clicked()
{
    timer->stop();
    menuWindow::close();
    otto nosto(webToken,id_account, id_user);
    nosto.setModal(true);
    nosto.exec();
}


void menuWindow::on_pushButton_LuottorajanNosto_clicked()
{
    timer->stop();
    menuWindow::close();
    luottoraja luotto(webToken,id_account, id_user);
    luotto.setModal(true);
    luotto.exec();
}


void menuWindow::on_pushButton_Tilitapahtumat_clicked()
{
    timer->stop();
    menuWindow::close();
    tilitapahtumat tilitapahtumat(webToken,id_account, id_user);
    tilitapahtumat.setModal(true);
    tilitapahtumat.exec();
}

