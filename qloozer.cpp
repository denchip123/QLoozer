#include "qloozer.h"
#include "ui_qloozer.h"

QLoozer::QLoozer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QLoozer)
{
    ui->setupUi(this);

    ui->studentsTableWidget->setShowGrid(true);
    ui->studentsTableWidget->setColumnCount(2);
    ui->studentsTableWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    ui->studentsTableWidget->setColumnWidth(1,42);

    AddStudentRow("gagagaga", 1);
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
    return;
}

void QLoozer::AddStudentRow(QString name, int raiting)
{
    int current_row = ui->studentsTableWidget->rowCount();
    ui->studentsTableWidget->setRowCount(current_row + 1);
    ui->studentsTableWidget->setRowHeight(current_row, 24);

    QTableWidgetItem* studentName = new QTableWidgetItem("gagagaga");
    ui->studentsTableWidget->setItem(current_row, 0, studentName);


    QSpinBox* raitingSpinBox = new QSpinBox(ui->studentsTableWidget);
    ui->studentsTableWidget->setCellWidget(current_row, 1, raitingSpinBox);

    return;
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
