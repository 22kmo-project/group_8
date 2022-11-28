#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "qnetworkreply.h"
#include <QDialog>



namespace Ui {
class menuWindow;
}

class menuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit menuWindow(QString card_number, bool credit, QByteArray token, QWidget *parent = nullptr);
    ~menuWindow();

    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_pushButton_KirjauduUlos_clicked();

    void on_pushButton_Otto_clicked();

    void on_pushButton_LuottorajanNosto_clicked();

    void on_pushButton_Saldo_clicked();

    void idCardSlot (QNetworkReply *reply);

    void getIdCard (QString card_number);
private:
    Ui::menuWindow *ui;
    QByteArray webToken;
    bool isCredit;
    QString id_card;
    QNetworkAccessManager *idCardManager;
    QNetworkReply *reply;
    QString cardNumber;
    QByteArray token;
};

#endif // MENUWINDOW_H
