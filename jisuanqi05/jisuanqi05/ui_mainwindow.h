/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QPushButton *compare;
    QComboBox *comboBox_2;
    QPushButton *solve;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(560, 545);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 110, 171, 21));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 160, 171, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 310, 93, 28));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(160, 200, 171, 21));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 250, 89, 21));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(160, 250, 171, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 10, 93, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 10, 93, 28));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(380, 10, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 81, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 200, 131, 16));
        compare = new QPushButton(centralWidget);
        compare->setObjectName(QStringLiteral("compare"));
        compare->setGeometry(QRect(180, 310, 93, 28));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(140, 60, 211, 22));
        solve = new QPushButton(centralWidget);
        solve->setObjectName(QStringLiteral("solve"));
        solve->setGeometry(QRect(180, 310, 93, 28));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 110, 121, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 160, 111, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 250, 72, 15));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 560, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\350\257\264\346\230\216", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\215\201\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\272\214\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\205\253\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\257\224\350\276\203\345\244\247\345\260\217", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\347\256\227\345\274\217\350\256\241\347\256\227", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\346\226\271\347\250\213\346\261\202\350\247\243", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\345\212\237\350\203\275", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227\347\212\266\346\200\201", Q_NULLPTR));
        compare->setText(QApplication::translate("MainWindow", "\346\257\224\350\276\203", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\200\345\205\203\344\270\200\346\254\241\346\226\271\347\250\213\357\274\210ax+b=0\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\200\345\205\203\344\272\214\346\254\241\346\226\271\347\250\213\357\274\210ax^2)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\214\207\346\225\260\345\207\275\346\225\260\346\226\271\347\250\213\357\274\210a^x=b\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\214\207\346\225\260\345\207\275\346\225\260\346\226\271\347\250\213\357\274\210x^a=b\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\257\271\346\225\260\345\207\275\346\225\260\346\226\271\347\250\213\357\274\210log x(a)=b\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\257\271\346\225\260\345\207\275\346\225\260\346\226\271\347\250\213\357\274\210log a(x)=b\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\215\346\257\224\344\276\213\345\207\275\346\225\260\346\226\271\347\250\213", Q_NULLPTR)
        );
        solve->setText(QApplication::translate("MainWindow", "\346\261\202\350\247\243", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\256\241\347\256\227\345\274\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227\347\273\223\346\236\234", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\346\226\271\347\250\213\347\232\204\350\247\243\344\270\272", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\231\250", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
