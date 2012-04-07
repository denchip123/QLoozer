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

/*
 *
 * Private
 *
 */

void QLoozer::MakeConnections()
{
    connect(ui->findLooserButton,SIGNAL(pressed()),this,SLOT(OnFindLooserClicked()));
    connect(ui->classChooseComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(OnClassChange(QString)));
    connect(ui->openClassFileButton,SIGNAL(pressed()),this,SLOT(OnChooseAnotherClassFile()));
}

/*
 *
 * Public slots
 *
 */

void QLoozer::OpenClassFile(QString file)
{
    return;
}

/*
 *
 * Private slots
 *
 */

void QLoozer::OnChooseAnotherClassFile()
{
    return;
}

void QLoozer::OnClassChange(QString newClass)
{
    return;
}

void QLoozer::OnFindLooserClicked()
{
    return;
}
