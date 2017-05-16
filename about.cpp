#include "about.h"
#include "ui_about.h"

#include <QUrl>
#include <QDesktopServices>
About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_button_aboutQt_pressed()
{
    QUrl url("https://wiki.qt.io/About_Qt");
    QDesktopServices::openUrl(url);
}

void About::on_Button_github_pressed()
{
    QUrl url("https://github.com/zeekaa/qvknotify");
    QDesktopServices::openUrl(url);

}
