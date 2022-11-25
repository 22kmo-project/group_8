#ifndef LUOTTORAJA_H
#define LUOTTORAJA_H

#include "menuwindow.h"
#include <QDialog>

namespace Ui {
class luottoraja;
}

class luottoraja : public QDialog
{
    Q_OBJECT

public:
    explicit luottoraja(QWidget *parent = nullptr);
    ~luottoraja();

private:
    Ui::luottoraja *ui;
    menuWindow *objectMenuToLuottoraja;
};

#endif // LUOTTORAJA_H
