#include "widget.h"
#include "ui_widget.h"

#include <QtWebKit>
#include <QLabel>
#include <QUrl>
#include <QUrlQuery>
#include <regex>

#define DEBUG

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    on_GoButton_clicked();
}

widget::~widget()
{
    delete ui;
}

void widget::on_GoButton_clicked()
{
   QString APP_ID = "5145977";
   QString PERMISSIONS = "4096";
   QString REDIRECT_URI = "https://oauth.vk.com/blank.html";
   QString DISPLAY = "mobile";
   QString API_VERSION = "5.64";
   QString URL1 = "https://oauth.vk.com/authorize?client_id=" + APP_ID + "&scope=" + PERMISSIONS +
           "&redirect_uri=" + REDIRECT_URI + "&display=" + DISPLAY + "&v=" + API_VERSION + "&response_type=token";
   QUrl URL = URL1;
   ui->webView->load(URL);
}

void widget::on_webView_urlChanged(const QUrl &arg1)
{;
    QString URL1 = arg1.toString();
    URL1.replace("#","?");
    QUrl URL = URL1;
    QUrlQuery query(URL);
    widget::access_token = query.queryItemValue("access_token");
    widget::user_ID = query.queryItemValue("user_id");
}

void widget::on_webView_titleChanged(const QString &title)
{
    QUrl track = "https://api.vk.com/method/stats.trackVisitor?access_token=" + access_token;
    QUrlQuery trackQuery(track);
    if (title.contains("OAuth"))
    {
        ui->GoButton->setDisabled(1);
        ui->GoButton->setText("Close");
        ui->webView->setVisible(false);
    }
}
