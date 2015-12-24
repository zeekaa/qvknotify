/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;

    QAction *actionLogin;
    QAction *actionLogout;
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_name;
    QLabel *Name;
    QPushButton *GetButton;
    QWidget *widget;
    QMenuBar *menubar;
    QMenu *menuUser;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(300, 358);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName(QStringLiteral("label_name"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_name->setFont(font);

        horizontalLayout_2->addWidget(label_name);

        Name = new QLabel(centralwidget);
        Name->setObjectName(QStringLiteral("Name"));

        horizontalLayout_2->addWidget(Name);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        GetButton = new QPushButton(centralwidget);
        GetButton->setObjectName(QStringLiteral("GetButton"));
        GetButton->setEnabled(false);
        GetButton->setFlat(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, GetButton);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(200, 0));

        formLayout->setWidget(1, QFormLayout::SpanningRole, widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 22));
        menuUser = new QMenu(menubar);
        menuUser->setObjectName(QStringLiteral("menuUser"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuUser->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuUser->addAction(actionLogin);
        menuUser->addAction(actionLogout);
        menuHelp->addAction(actionAbout);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0));

        actionLogin->setText(QApplication::translate("MainWindow", "Login", 0));
        actionLogout->setText(QApplication::translate("MainWindow", "Logout", 0));
        label_name->setText(QApplication::translate("MainWindow", "Not Logged In", 0));
        Name->setText(QString());
        GetButton->setText(QApplication::translate("MainWindow", "Check for new messages", 0));
        menuUser->setTitle(QApplication::translate("MainWindow", "User", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
