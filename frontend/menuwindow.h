#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>

namespace Ui {
class menuWindow;
}

class menuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = nullptr);
    ~menuWindow();

    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_pushButton_LuottorajanNosto_clicked();

    void on_pushButton_Saldo_clicked();

private:
    Ui::menuWindow *ui;
    QByteArray webToken;
};

#endif // MENUWINDOW_H
