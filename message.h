#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QNetworkAccessManager>

class message
{
public:
    message( QString access_token, QString out, QString offset);
//    ~message();

    QString access_token;
    QString offset;

    QString id;                 // 	Message ID. (Not returned for forwarded messages.)
    QString user_id;            // 	For an incoming message, the user ID of the author. For an outgoing message, the user ID of the receiver.
    QString date;               // 	Date (in Unix time) when the message was sent.
    QString read_state;        // 	Message status (0 — not read, 1 — read). (Not returned for forwarded messages.)
    QString out;               // 	Message type (0 — received, 1 — sent). (Not returned for forwarded messages.)
    QString title;              // 	Title of message or chat.
    QString body;               // 	Body of the message.


    void get ();
    void send (QString body);
};

#endif // MESSAGE_H
