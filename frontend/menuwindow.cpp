#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "otto.h"
#include "luottoraja.h"
#include "tilitapahtumat.h"
#include "saldo.h"



menuWindow::menuWindow(QByteArray bearerToken, QString idAccount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    webToken = bearerToken;
    qDebug()<<webToken;
    id_account = idAccount;

    QString site_url=MyURL::getBaseURL()+"/account/owner/";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken=bearerToken;
    qDebug()<<myToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    ownerManager = new QNetworkAccessManager(this);

    QJsonObject jsonObj;
    jsonObj.insert("id_account",id_account);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(ownerManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(getOwnerSlot(QNetworkReply*)));
    reply = ownerManager->post(request, QJsonDocument(jsonObj).toJson());
}

void menuWindow::getOwnerSlot(QNetworkReply *reply)
{
     response_data = reply->readAll();
     qDebug()<<response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonObject json_obj = json_doc.object();
     owner=json_obj["account_owner"].toString();
     qDebug()<<owner;

     reply->deleteLater();
     ui->labelCardnumber->setText("Tervetuloa "+owner+"!");
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
    menuWindow::close();
}


void menuWindow::on_pushButton_Saldo_clicked()
{
  class saldo nayta(webToken,id_account);
  nayta.setModal(true);
  nayta.exec();

}



void menuWindow::on_pushButton_Otto_clicked()
{
    otto nosto(webToken,id_account);
    nosto.setModal(true);
    nosto.exec();
}

void menuWindow::on_pushButton_LuottorajanNosto_clicked()
{
    luottoraja luotto(webToken,id_account);
    luotto.setModal(true);
    luotto.exec();
}


void menuWindow::on_pushButton_Tilitapahtumat_clicked()
{
    tilitapahtumat tilitapahtumat(webToken,id_account);
    tilitapahtumat.setModal(true);
    tilitapahtumat.exec();
}

