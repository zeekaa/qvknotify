#ifndef USERS_H
#define USERS_H
#include <QString>
#include <QNetworkAccessManager>


class users
{
public:
    users(QString access_token, QString id );
    //~users();

    QString access_token;

    QString id; //user's id
    QString first_name;
    QString last_name;
    QString nickname;
    QString photo_50; //50px photo

    void get();

};

#endif // USERS_H
