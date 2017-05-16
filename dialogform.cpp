#include "dialogform.h"
#include "ui_dialogform.h"

DialogForm::DialogForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogForm)
{
    ui->setupUi(this);
}

DialogForm::~DialogForm()
{
    delete ui;
}
