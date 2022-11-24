#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtGui>
#include <QStackedWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>

#include "myurl.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    const QString &getWebtoken() const;
    void setWebToken(const QByteArray &newWebToken);

public slots:
    void SisaanWidget();
    void KirjauduWidget();
    void ValitseKorttiWidget();
    void MenuWidget();
    void SaldoWidget();
    void TilitapahtumatWidget();
    void OttoWidget();
    void LuottorajanNostoWidget();

private slots:
    void loginSlot (QNetworkReply *reply);
    void on_btnKirjaudu_clicked();

    void on_btnSisaan_clicked();

    void on_btnPoistu_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray webToken;
    QTimer *timer;
    QString card_number;
    QString pin;
    int time;
};
#endif // MAINWINDOW_H
