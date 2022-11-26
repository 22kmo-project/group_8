#include "otto.h"
#include "ui_otto.h"
#include "mainwindow.h"
#include <QtSql/QSqlDatabase>

otto::otto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otto)
{
    ui->setupUi(this);
}

otto::~otto()
{
    delete ui;
}



void otto::on_ottoPoistu_clicked()
{
    otto::close();
}


/*void otto::on_ottoNosta_clicked()
{
    QSqlQuery::exec()
}

void QSqlQuery::exec()
{
    QSqlQuery query;
    query.exec("SELECT ")
}*/


