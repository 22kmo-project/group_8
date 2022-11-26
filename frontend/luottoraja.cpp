#include "luottoraja.h"
#include "ui_luottoraja.h"

luottoraja::luottoraja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::luottoraja)
{
    ui->setupUi(this);
}

luottoraja::~luottoraja()
{
    delete ui;
}
