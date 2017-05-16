#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = 0);
    QString access_token;
    QString user_ID;
    ~widget();

private slots:
    void on_GoButton_clicked();

    void on_webView_urlChanged(const QUrl &arg1);

    void on_webView_titleChanged(const QString &title);

private:
    Ui::widget *ui;
};

#endif // WIDGET_H
