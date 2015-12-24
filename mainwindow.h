#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QTimer>
#include <QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString access_token = NULL;
    QString user_ID = NULL;
    QJsonObject* response;
    QTimer* timer;
    QSystemTrayIcon* trayIcon;

private slots:
    void on_actionLogin_triggered();
    void on_actionLogout_triggered();

    void sysTrayIcon();
    void clickSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

    void SaveToken( QString access_token, QString user_ID );
    bool LoadToken();
    void on_login( QString access_token );

    void on_GetButton_pressed();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
//    widget::widget *mMyNewWindow;
};

#endif // MAINWINDOW_H
