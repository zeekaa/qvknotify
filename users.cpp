#include "users.h"

#include <QtNetwork>
#include <QUrl>
#include <QNetworkAccessManager>

users::users(QString access_token, QString id)
{
    users::access_token = access_token;
    users::id = id;
}
void users::get ()
{
    QEventLoop eventLoop;

    QUrl request_url = "https://api.vk.com/method/users.get?user_ids=" + this->id + "&fields=photo_50,nickname&access_token=" + access_token; //form the URL of request
    QNetworkAccessManager* nam = new QNetworkAccessManager;
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkReply* reply = nam->get(QNetworkRequest(request_url));    //request
    eventLoop.exec();

    if(reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "No error, continuing";

        QString strReply = (QString)reply->readAll(); //read json
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        QJsonArray jsonArray = (jsonObject.value("response")).toArray();
        QJsonObject response = jsonArray[0].toObject();

        //this->id = response.value("id").toString();//todo
        this->first_name = response.value("first_name").toString();
        this->last_name = response.value("last_name").toString();
        this->nickname = response.value("nickname").toString();
        this->photo_50 = response.value("photo_50").toString();

        qDebug() << "recieved user #" << this->id << this->first_name << this->last_name;

    } else {
        qDebug() << "NETWORK ERROR";
    }

    delete reply;
}
