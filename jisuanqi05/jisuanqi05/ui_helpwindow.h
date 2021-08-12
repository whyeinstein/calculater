/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helpwindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helpwindow)
    {
        if (helpwindow->objectName().isEmpty())
            helpwindow->setObjectName(QStringLiteral("helpwindow"));
        helpwindow->resize(548, 489);
        centralwidget = new QWidget(helpwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 551, 461));
        helpwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helpwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 548, 26));
        helpwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(helpwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        helpwindow->setStatusBar(statusbar);

        retranslateUi(helpwindow);

        QMetaObject::connectSlotsByName(helpwindow);
    } // setupUi

    void retranslateUi(QMainWindow *helpwindow)
    {
        helpwindow->setWindowTitle(QApplication::translate("helpwindow", "MainWindow", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("helpwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\257\264\346\230\216\344\271\246</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class helpwindow: public Ui_helpwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
