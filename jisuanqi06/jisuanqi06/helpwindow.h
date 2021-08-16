#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class helpwindow;
}

class helpwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit helpwindow(QWidget *parent = 0);
    ~helpwindow();

private:

    Ui::helpwindow *ui;
};

#endif // HELPWINDOW_H
