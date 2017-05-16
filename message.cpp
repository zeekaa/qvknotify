#include "message.h"
#include <QUrl>
#include <QtNetwork>
#include <QNetworkAccessManager>

const int MESSAGE_COUNT = 10;

message::message(QString access_token, QString out, QString offset)
{
    message::access_token = access_token;
    message::out = out;
    message::offset = offset;
}

void message::get ()
{
    //QEventLoop eventLoop;

    QUrl request_url("https://api.vk.com/method/messages.get");
    QUrlQuery query;
    query.addQueryItem("out", this->out);
    query.addQueryItem("offset", this->offset);
    query.addQueryItem("count", "1");
    query.addQueryItem("time_offset", "0");
    query.addQueryItem("filters", "3");
    query.addQueryItem("preview_length","0");
    query.addQueryItem("access_token", access_token); //form the URL of request
    request_url.setQuery(query);

    QNetworkAccessManager* nam = new QNetworkAccessManager();
    //QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkReply* reply = nam->get(QNetworkRequest(request_url));    //request
    //eventLoop.exec();

    if(reply->error() == QNetworkReply::NoError) {

        qDebug() << "No message error, continuing";

        QString strReply = (QString)reply->readAll(); //read json
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        QJsonArray jsonArray = (jsonObject.value("response")).toArray();


        QJsonObject response = jsonArray[1].toObject();

        this->id = QString::number(response["mid"].toDouble());        //write to class members
        this->user_id = QString::number(response["uid"].toInt());
        this->title = response.value("title").toString();
        this->body = response.value("body").toString();
        this->read_state = QString::number(response["read_state"].toDouble());
        this->date = QString::number(response["date"].toDouble());


        qDebug() << "recieved message #" << id << " from " << user_id;

    } else {
        qDebug() << "NETWORK ERROR";
    }

    delete reply;

}

void message::send (QString body)
{
    qDebug() << "NOT IMPLEMENTED YET" << endl;
    //TODO
}

