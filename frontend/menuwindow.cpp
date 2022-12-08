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
    //qDebug()<<webToken;
    id_account = idAccount;
    id_user = idUser;



    QString site_url=MyURL::getBaseURL()+"/account/"+idAccount;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken=bearerToken;
    //qDebug()<<myToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    ownerManager = new QNetworkAccessManager(this);

    //Onko nämä alla olevat turhia? Jos on niin voi poistaa.
   // QJsonObject jsonObj;
    //jsonObj.insert("account_owner", owner);
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(ownerManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getOwnerSlot(QNetworkReply*)));

    reply = ownerManager->get(request);
    ui->labelCardnumber->setText(owner);

    timer = new QTimer(this);
    connect (timer, SIGNAL (timeout()),
            this, SLOT (timeoutSlot()));
    timer->start(1000);
    time = 0;

}

void menuWindow::getOwnerSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    owner=json_obj["account_owner"].toString();
    qDebug()<<"Menuwindow: tilin omistaja = "+owner;

   // reply->deleteLater();
    ui->labelCardnumber->setText("Tervetuloa "+owner+"!");
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

const QString &menuWindow::getWebtoken() const
{
    return webToken;
}


void menuWindow::setWebToken(const QByteArray &newWebToken)
{
 webToken = newWebToken;
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

