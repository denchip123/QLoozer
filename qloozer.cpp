#include "qloozer.h"
#include "ui_qloozer.h"
//ÐžÑÑ‚Ð¾Ñ€Ð¾Ð¶Ð½Ð¾ -- Ð Ð¾ÑÑ‚Ñ‹Ð»ÑŒ
//    (__)_(__)
//       | |
//       | |
//       | |
//       | |
//       \I/
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
    MakeConnections();

    QLoozerLuaAPI lAPI;

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
    connect(ui->openClassFileButton,SIGNAL(clicked()),this,SLOT(OnChooseAnotherClassFile()));
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
int QLoozer::GetLoozer(void)
{
//| OLD CODE
//|-> QTime midnight(0, 0, 0);
//    qsrand(midnight.secsTo(QTime::currentTime()));

//    QList<int> possibleLoozers;

//    int currentMember;
//    bool checked[250];
//    for(int i=0;i<250;i++)
//    {
//        if(badClass.IsHere(i)) checked[i]=false;
//    }

//    int part = badClass.GetMembersCount()/4;
//    if (part <1)
//        part = 1;
//    for (int i = 0; i < part;)
//    {
//        currentMember=qrand()%badClass.GetMembersCount();
//        if( !checked[currentMember] ){
//            possibleLoozers.push_back(currentMember);
//            checked[currentMember]=true;
//            i++;
//        }
//    }
//    currentMember = qrand()%possibleLoozers.count();
//    for(int i=0;i<possibleLoozers.count();i++)
//    {
//        int tmp = qrand()%possibleLoozers.count();
//        if (badClass.GetBonus(currentMember) < badClass.GetBonus(tmp)) {
//            currentMember = tmp;
//        }
//    }
//    badClass.SetHere(currentMember, false);//chtoby v sled raz ego ne vybralo loozerom
//    return currentMember;
}

/*
 *
 * Public slots
 *
 */

void QLoozer::OpenClassFile(QString fileName)
{

}
/*
 *
 * Private slots
 *
 */

void QLoozer::OnChooseAnotherClassFile()
{
    QString s = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("Îòêðûòü"),"/","Text File (*.txt)");
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
