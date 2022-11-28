#ifndef CHOOSECARD_H
#define CHOOSECARD_H

#include "menuwindow.h"
#include <QDialog>

namespace Ui {
class ChooseCard;
}

class ChooseCard : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseCard(QString card_number, QWidget *parent = nullptr);
    ~ChooseCard();
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_pushButton_credit_clicked();

    void on_pushButton_debit_clicked();

private:
    Ui::ChooseCard *ui;
    menuWindow *objectCardToMenu;
    QByteArray webToken;
    QString cardNumber;
};

#endif // CHOOSECARD_H
