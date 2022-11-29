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
    explicit tilitapahtumat(QByteArray wt, QWidget *parent = nullptr);
    ~tilitapahtumat();
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

private:
    Ui::tilitapahtumat *ui;
    menuWindow *objectMenuToTilitapahtumat;
    QByteArray myToken;
    QByteArray webToken;
};

#endif // TILITAPAHTUMAT_H
