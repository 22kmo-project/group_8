#ifndef MENUWINDOW_H
#define MENUWINDOW_H

//#include "otto.h"
#include <QDialog>



namespace Ui {
class menuWindow;
}

class menuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit menuWindow(QString card_number, bool credit, QWidget *parent = nullptr);
    ~menuWindow();

    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_pushButton_KirjauduUlos_clicked();

    void on_pushButton_Otto_clicked();

    void on_pushButton_LuottorajanNosto_clicked();

    void on_pushButton_Saldo_clicked();

private:
    Ui::menuWindow *ui;
    QByteArray webToken;
    //otto *objectMenuToOtto;
};

#endif // MENUWINDOW_H
