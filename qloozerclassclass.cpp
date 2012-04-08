#include "qloozerclassclass.h"

QLoozerClassClass::QLoozerClassClass()
{
    name = new QStringList;
    bonus = new QList<int>;
    stat = new QList<int>;
    here = new QList<bool>;
}

QLoozerClassClass::~QLoozerClassClass()
{
    delete name;
    delete bonus;
    delete stat;
    delete here;
}

void QLoozerClassClass::AddStudent(QString studentName, int studentBonus, int studentStat)
{
//    name << studentName;
//    bonus << studentBonus;
//    stat << studentStat;
//    here << true;
    return;
}

int QLoozerClassClass::GetBonus(int index)
{
    return bonus[index];
}

QString QLoozerClassClass::GetName(int index)
{

    return name[index];
}

int QLoozerClassClass::GetStat(int index)
{

    return 0;
}

bool QLoozerClassClass::IsHere(int index)
{
    return true;
}
