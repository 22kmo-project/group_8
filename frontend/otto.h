#ifndef OTTO_H
#define OTTO_H

#include "menuwindow.h"
#include <QDialog>

namespace Ui {
class otto;
}

class otto : public QDialog
{
    Q_OBJECT

public:
    explicit otto(QWidget *parent = nullptr);
    ~otto();
    void updateAccountData();

private slots:


    void on_ottoPoistu_clicked();

    //void on_ottoNosta_clicked();


private:
    Ui::otto *ui;
    menuWindow *objectMenuToOtto;
};

#endif // OTTO_H
