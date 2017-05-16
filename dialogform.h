#ifndef DIALOGFORM_H
#define DIALOGFORM_H

#include <QWidget>

namespace Ui {
class DialogForm;
}

class DialogForm : public QWidget
{
    Q_OBJECT

public:
    explicit DialogForm(QWidget *parent = 0);
    ~DialogForm();

private:
    Ui::DialogForm *ui;
};

#endif // DIALOGFORM_H
