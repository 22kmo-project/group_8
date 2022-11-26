#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include "menuwindow.h"
#include <QDialog>

namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tilitapahtumat(QWidget *parent = nullptr);
    ~tilitapahtumat();

private:
    Ui::tilitapahtumat *ui;
    menuWindow *objectMenuToTilitapahtumat;
};

#endif // TILITAPAHTUMAT_H
