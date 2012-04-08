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

    classParser = new QLoozerClassFilesParser;
    LoadClasses();

    headerList << tr("n") << tr("Names") << tr("Bonus") << tr("Stat");
    ui->studentsTableWidget->setHorizontalHeaderLabels(headerList);
}

QLoozer::~QLoozer()
{
    delete ui;
    delete classParser;
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

int QLoozer::GetLoozer(QLoozerClassClass badClass)
{
    QTime midnight(0, 0, 0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    QList<int> possibleLoozers;

    int currentMember;
    bool checked[250];
    for(int i=0;i<250;i++)
    {
        checked[i]=false;
    }

    int part = badClass.GetMembersCount()/4;
    if (part <1)
        part = 1;
    for (int i = 0; i < part;)
    {
        currentMember=qrand()%badClass.GetMembersCount();
        if( !checked[currentMember] ){
            possibleLoozers.push_back(currentMember);
            checked[currentMember]=true;
            i++;
        }
    }
    currentMember = qrand()%possibleLoozers.count();
    for(int i=0;i<possibleLoozers.count();i++)
    {
        int tmp = qrand()%possibleLoozers.count();
        if (badClass.GetBonus(currentMember) < badClass.GetBonus(tmp)) {
            currentMember = tmp;
        }
    }
    return currentMember;
}

bool QLoozer::LoadClasses()
{
    qDebug("loading...");
    int c = classParser->classes[classParser->classes_count].GetMembersCount();
//    for (int i = 0; i < c; i++)
//    {
        int m = classParser->GetThisClass(0).GetMembersCount();
        qDebug(QString::number(m).toAscii());
        for (int j = 0; j < m; j++)
        {
            qDebug("ga");
            QLoozerClassClass tmp;
            qDebug("gd222fa");
            tmp = classParser->GetThisClass(0);
            qDebug("gggggovno");
            qDebug(tmp.GetName(0).toAscii());
            AddStudentRow(tmp.GetName(j),
                          tmp.GetBonus(j),
                          tmp.GetStat(j));
        }
//    }
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
