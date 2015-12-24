#include "dialog.h"
#include "ui_dialog.h"

#include "users.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDesktopServices>
#include <QSystemTrayIcon>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::fill(QString user_id, QString access_token, QString body)
{
    ui->textEdit_Sent->setReadOnly(1);
    this->user_id = user_id;
    users currentUser(access_token, user_id);
    currentUser.get();
    ui->sender->setText(currentUser.first_name + " " + currentUser.last_name);
    ui->textEdit_Sent->append(body);

    qDebug() << "Userpic URL:" << currentUser.photo_50;

    QEventLoop eventLoop;

    QNetworkAccessManager* nam = new QNetworkAccessManager;
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl url(currentUser.photo_50);
    QNetworkReply* reply = nam->get(QNetworkRequest(url));
    eventLoop.exec();

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray photo_50_bytes = reply->readAll();  // bytes
        QImage img(20, 20, QImage::Format_Indexed8);
        img.loadFromData(photo_50_bytes);
        ui->userPic->setPixmap(QPixmap::fromImage(img));

        qDebug() << "photo_50 set";

    }
    else
    {
        qDebug() << "Unable to recieve photo_50";
    }
    delete reply;
}

void Dialog::on_ButtonInBrowser_pressed()
{
    QUrl url("https://vk.com/im?sel=" + this->user_id);
    bool flag = QDesktopServices::openUrl(url);
    if (flag)
    {
        qDebug() << "Opened in default browser";
    }
}
