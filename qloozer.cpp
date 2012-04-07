#include "qloozer.h"
#include "ui_qloozer.h"

QLoozer::QLoozer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QLoozer)
{
    ui->setupUi(this);
}

QLoozer::~QLoozer()
{
    delete ui;
}
