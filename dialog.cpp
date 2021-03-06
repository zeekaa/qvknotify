#include "dialog.h"
#include "ui_dialog.h"

#include "users.h"
#include "message.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDesktopServices>
#include <QSystemTrayIcon>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDateTime>

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

void Dialog::getDialogs( int offset, QString access_token)
{
    dialogList = new message(access_token, "0","0");

    //dialogList = new message[count] { message(access_token,"0","0"), message(access_token,"0","0"), message(access_token,"0","0") };
    QEventLoop eventLoop;

    QUrl request_url("https://api.vk.com/method/messages.getDialogs");
    QUrlQuery query;
    query.addQueryItem("count", "1");
    query.addQueryItem("offset", QString::number(offset));
    query.addQueryItem("access_token", access_token); //form the URL of request
    request_url.setQuery(query);

    QNetworkAccessManager* nam = new QNetworkAccessManager();
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkReply* reply = nam->get(QNetworkRequest(request_url));    //request
    qDebug() << request_url;
    eventLoop.exec();
    //while (1)
    {
        if(reply->error() == QNetworkReply::NoError) {

            qDebug() << "No dialog error, continuing";

            QString strReply = (QString)reply->readAll(); //read json
            QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();
            QJsonArray jsonArray = (jsonObject.value("response")).toArray();


            QJsonObject response = jsonArray[1].toObject();

            this->dialogList->id = QString::number(response["mid"].toDouble());        //write to class members
            this->dialogList->user_id = QString::number(response["uid"].toInt());
            this->dialogList->title = response.value("title").toString();
            this->dialogList->body = response.value("body").toString();
            this->dialogList->read_state = QString::number(response["read_state"].toDouble());
            this->dialogList->date = response.value("date").toInt();


            qDebug() << "recieved dialog " << this->dialogList->body << " from " << user_id;

            if (this->dialogList->read_state == (QString)"0")
            {
                ui->textEdit_Sent->setReadOnly(1);
                QDateTime time;
                time.setSecsSinceEpoch(this->dialogList->date);

                qDebug() << time;
                QLabel* timeWidget = new QLabel;
                timeWidget->setText("at " + time.toString());
                ui->verticalLayout_2->addWidget(timeWidget);

                users currentUser(access_token, this->dialogList->user_id);
                currentUser.get();
                ui->sender->setText(currentUser.first_name + " " + currentUser.last_name);
                ui->textEdit_Sent->append(this->dialogList->body);
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


        } else {
            qDebug() << "NETWORK ERROR";
        }
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
