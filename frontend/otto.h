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

private:
    Ui::otto *ui;
    menuWindow *objectMenuToOtto;
};

#endif // OTTO_H
