#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString user_id;

    void fill(QString user_id, QString access_token, QString body);

private slots:
    void on_ButtonInBrowser_pressed();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
