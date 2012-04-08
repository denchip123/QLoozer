#include "qloozerclassclass.h"

QLoozerClassClass::QLoozerClassClass()
{
    membersCount = new int;
    membersCount = 0;
    name = new QStringList;
    bonus = new QVector<int>;
    stat = new QVector<int>;
    here = new QVector<bool>;
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
    name->push_back(studentName);
    bonus->push_back(studentBonus);
    stat->push_back(studentStat);
    here->push_back(true);
    membersCount++;
    return;
}

int QLoozerClassClass::GetBonus(int index)
{
    return bonus->value(index);
}

QString QLoozerClassClass::GetName(int index)
{
    return name->value(index);
}

int QLoozerClassClass::GetStat(int index)
{
    return stat->value(index);
}

bool QLoozerClassClass::IsHere(int index)
{
    return here->value(index);
}

int QLoozerClassClass::GetMembersCount()
{
    return *membersCount;
}
