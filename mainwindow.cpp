#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QTranslator>

#include "message.h"
#include "users.h"
#include "about.h"

#include <QDialog>
#include <QVariant>
#include <QApplication>
#include <QFile>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->retranslateUi(this);
    setWindowTitle("QVkNotify");
    setWindowIcon(QIcon("res/icon.png"));

    timer = new QTimer(this);//for auto update
    timer->setSingleShot(true);
    timer->setInterval(60000);
    connect(timer, SIGNAL(timeout()), SLOT(on_GetButton_pressed()));
    sysTrayIcon();

    on_actionLogin_triggered();//autologin

    on_GetButton_pressed();//first update
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::sysTrayIcon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("res/icon.png"));
    trayIcon->setToolTip("QVkNotify");
    trayIcon->show();
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(clickSysTrayIcon(QSystemTrayIcon::ActivationReason)));

    QMenu* menu = new QMenu(this);
//    menu->addAction("Hide",this,SLOT(hide()));
    menu->addAction("Exit",this,SLOT(close()));
    trayIcon->setContextMenu(menu);
}
void MainWindow::clickSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
        case QSystemTrayIcon::DoubleClick:
        break;
        case QSystemTrayIcon::MiddleClick:
        break;
        case QSystemTrayIcon::Unknown:
        break;
        case QSystemTrayIcon::Context:
        break;
        case QSystemTrayIcon::Trigger:
        if (this->isHidden() == true)
            this->setVisible(1);
        else
            this->setVisible(0);
        break;
    }
}

//menu action buttons
void MainWindow::on_actionLogin_triggered()
{
    if (LoadToken() == false)//login if no file
    {
        QVBoxLayout* lay = new QVBoxLayout;

        widget* temp = new widget(this);
        lay->addWidget(temp);

        QDialog LoginDialog(this);
        LoginDialog.setModal(true);
        LoginDialog.setLayout(lay);
        LoginDialog.setWindowTitle(tr("Login"));//open the login window

        LoginDialog.exec();
        access_token = temp->access_token;
        user_ID = temp->user_ID;
    }
    if (access_token == "")
    {
        ui->statusbar->showMessage(tr("Unable to login"));
        return;
    }
    ui->label_name->setText(tr("Logged in as"));
    ui->statusbar->showMessage(tr("Token recieved"));
    SaveToken(access_token, user_ID);
    on_login(access_token);
}
void MainWindow::on_actionLogout_triggered()
{
    access_token = "";
    user_ID = "";
    ui->Name->setText("");
    ui->label_name->setText(tr("Not Logged In"));
    ui->statusbar->showMessage(tr("Logged out"));
    ui->GetButton->setEnabled(0);
    QFile("auth").remove();
}

//related to ^
void MainWindow::SaveToken(QString access_token, QString user_ID)
{
    QFile file("auth");
    file.open(QIODevice::WriteOnly);
    if(!file.isOpen())
    {
        return;
    }
    QTextStream s(&file);
    s << access_token << "\n" << user_ID;
    file.close();
    ui->statusbar->showMessage(tr("Token saved"));
}
bool MainWindow::LoadToken()
{
    QFile file("auth");
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen())
    {
        return false;
    }
    QTextStream s(&file);
    access_token = s.readLine();
    user_ID = s.readLine();
    file.close();
    if (user_ID == "" || access_token == "")
        return false;
    ui->statusbar->showMessage(tr("Token loaded"));
    return true;
}
void MainWindow::on_login ( QString access_token )
{
    users me(access_token, user_ID);
    me.get();
    ui->Name->setText(me.first_name + " " + me.last_name);
    ui->GetButton->setEnabled(1);
    ui->statusbar->showMessage(tr("Ready"));
}

//other buttons
bool flag = true;
void MainWindow::on_GetButton_pressed()
{
    ui->statusbar->showMessage(tr("Recieving new messages..."));
    if ( ui->widget->layout() != NULL )
    {
        QLayoutItem* item;
            while ( ( item = ui->widget->layout()->takeAt( 0 ) ) != NULL )
            {
                delete item->widget();
                delete item;
            }
            delete ui->widget->layout();
    }
    QVBoxLayout* NewDialogList = new QVBoxLayout;

    int i = 0;

    while (1)
    {
        Dialog check;
        check.getDialogs( i, access_token);
        if ( check.dialogList->read_state == (QString)"1" )
        {
            qDebug() << "No more new messages. Bailing out";
            break;
        }
        Dialog* got = new Dialog(this);

        got->fill( check.dialogList->user_id, access_token , check.dialogList->body );
        NewDialogList->addWidget(got);

        trayIcon->setIcon((QIcon)"res/icon_new.png");

        users currentUser( access_token, check.dialogList->user_id);
        currentUser.get();

        if (flag == true)
        {
            trayIcon->showMessage("QVkNotify","New message from " + currentUser.first_name + " " + currentUser.last_name);
            flag = false;
        }

        i++;
    }
    ui->statusbar->showMessage(tr("Done"));

    if (i == 0)
    {
        trayIcon->setIcon((QIcon)"res/icon.png");
        ui->statusbar->showMessage(tr("No new messages"));
        flag = true;
    }

    ui->widget->setLayout(NewDialogList);
    timer->start();
}

void MainWindow::on_actionAbout_triggered()
{
    QVBoxLayout* lay = new QVBoxLayout;

    About* temp = new About(this);
    lay->addWidget(temp);

    QDialog AboutDialog(this);
    AboutDialog.setModal(true);
    AboutDialog.setLayout(lay);
    AboutDialog.setWindowTitle(tr("About QVkNotify"));//open the login window

    AboutDialog.exec();
    delete temp;
    delete lay;
}
