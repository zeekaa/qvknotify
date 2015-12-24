/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QWebView *webView;
    QPushButton *GoButton;

    void setupUi(QWidget *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QStringLiteral("widget"));
        widget->resize(340, 266);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        webView = new QWebView(widget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setMaximumSize(QSize(300, 200));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        formLayout->setWidget(0, QFormLayout::LabelRole, webView);

        GoButton = new QPushButton(widget);
        GoButton->setObjectName(QStringLiteral("GoButton"));
        GoButton->setMaximumSize(QSize(80, 25));

        formLayout->setWidget(1, QFormLayout::LabelRole, GoButton);


        horizontalLayout->addLayout(formLayout);


        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QWidget *widget)
    {
        widget->setWindowTitle(QApplication::translate("widget", "widget", 0));
        GoButton->setText(QApplication::translate("widget", "Go", 0));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
