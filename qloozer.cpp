#include "qloozer.h"
#include "ui_qloozer.h"

QLoozer::QLoozer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QLoozer)
{
    ui->setupUi(this);

    ui->studentsTableWidget->setShowGrid(true);
    ui->studentsTableWidget->setColumnCount(4);
    ui->studentsTableWidget->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    ui->studentsTableWidget->setColumnWidth(0,14);
    ui->studentsTableWidget->setColumnWidth(2,42);
    ui->studentsTableWidget->setColumnWidth(3,32);

    headerList << tr("n") << tr("Names") << tr("Bonus") << tr("Stat");
    ui->studentsTableWidget->setHorizontalHeaderLabels(headerList);

    AddStudentRow("gagagaga", 1, 5);
    AddStudentRow("gagagrterteaga", 13, 654);
    AddStudentRow("gagagasdfsdga", 17, 777);
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

void QLoozer::AddStudentRow(QString name, int bonus, int stat)
{
    int current_row = ui->studentsTableWidget->rowCount();
    ui->studentsTableWidget->setRowCount(current_row + 1);
    ui->studentsTableWidget->setRowHeight(current_row, 24);

    QTableWidgetItem* studentName = new QTableWidgetItem(name);
    ui->studentsTableWidget->setItem(current_row, 1, studentName);

    QCheckBox* isHereSB = new QCheckBox;
    isHereSB->setChecked(true);

    ui->studentsTableWidget->setCellWidget(current_row, 0, isHereSB);

    QSpinBox* bonusSpinBox = new QSpinBox(ui->studentsTableWidget);
    bonusSpinBox->setValue(bonus);
    ui->studentsTableWidget->setCellWidget(current_row, 2, bonusSpinBox);

    QLabel* statLabel = new QLabel;
    statLabel->setText(QString::number(stat));
    statLabel->setAlignment(Qt::AlignCenter);
    ui->studentsTableWidget->setCellWidget(current_row, 3, statLabel);

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
