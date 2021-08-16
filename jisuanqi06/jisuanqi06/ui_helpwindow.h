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
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">\350\257\264\346\230\216\344\271\246</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">\342\200\2731\357\274\232\345\217\257\350\207\252\345\212\250\350\257\206\345\210\253\350"
                        "\276\223\345\205\245\347\232\204\350\277\233\345\210\266\357\274\214\346\240\274\345\274\217\344\270\272\357\274\232\344\272\214\350\277\233\345\210\266\346\225\260\345\211\215\345\212\240B\357\274\214\345\205\253\350\277\233\345\210\266\346\225\260\345\211\215\345\212\240O\357\274\214\345\215\201\345\205\255\350\277\233\345\210\266\345\211\215\345\212\240H (\344\276\213\357\274\232B101+H5f)\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">\342\200\2732\357\274\232\346\224\257\346\214\201\344\270\211\350\247\222\345\207\275\346\225\260\357\274\214\345\257\271\346\225\260\345\207\275\346\225\260\345\222\214\346\214\207\346\225\260\345\207\275\346\225\260\357\274\214\345\207\275\346\225\260\345\217\257\347\233"
                        "\264\346\216\245\345\214\205\345\220\253\345\234\250\347\256\227\345\274\217\344\270\255\357\274\210\344\276\213\357\274\232sin10+log2(4)*3^5\357\274\211\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">\342\200\2733\357\274\232\346\257\224\350\276\203\345\244\247\345\260\217\347\232\204\345\212\237\350\203\275\344\270\255\346\224\257\346\214\201\350\276\223\345\205\245\347\256\227\345\274\217\357\274\214\345\233\240\346\255\244\344\271\237\345\217\257\344\273\245\346\257\224\350\276\203\344\270\244\344\270\252\347\256\227\345\274\217\347\232\204\347\273\223\346\236\234\345\244\247\345\260\217\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px;"
                        " margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">\342\200\2734\357\274\232\346\211\200\346\234\211\350\276\223\345\205\245\351\224\231\350\257\257/\346\227\240\350\247\243\347\232\204\346\203\205\345\206\265\344\270\213\357\274\214\344\274\232\347\273\231\345\207\272\351\224\231\350\257\257\346\217\220\347\244\272\345\271\266\344\270\224\347\273\223\346\236\234\350\207\252\345\212\250\347\275\256\351\233\266\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">\342\200\2735\357\274\232\344\270\272\346\226\271\344\276\277"
                        "\346\237\245\347\234\213\345\222\214\347\224\250\346\210\267\350\276\223\345\205\245\357\274\214\346\211\200\346\234\211\350\277\233\345\210\266\346\225\260\345\235\207\344\270\215\351\234\200\350\246\201\350\200\203\350\231\221\347\254\246\345\217\267\344\275\215\357\274\214\350\264\237\346\225\260\344\275\277\347\224\250\350\264\237\345\217\267\350\241\250\347\244\272\345\215\263\345\217\257\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class helpwindow: public Ui_helpwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
