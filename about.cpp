#include "about.h"
#include "ui_about.h"

#include <QUrl>
#include <QDesktopServices>
About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->Button_github->setEnabled(0);
    ui->Button_github->setToolTip("Comming soon");
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
