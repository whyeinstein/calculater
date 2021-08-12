#include "helpwindow.h"
#include "ui_helpwindow.h"

helpwindow::helpwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::helpwindow)
{
    ui->setupUi(this);

    this->setWindowTitle("说明");


}

helpwindow::~helpwindow()
{
    delete ui;
}
