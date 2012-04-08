#include "qloozerclassclass.h"

QLoozerClassClass::QLoozerClassClass()
{
    bonus = new QList<int>;
    stat = new QList<int>;
    here = new QList<bool>;
}

QLoozerClassClass::~QLoozerClassClass()
{
    delete bonus;
    delete stat;
    delete here;
}

void QLoozerClassClass::AddStudent(QString studentName, int studentBonus, int studentStat)
{
    return;
}

int QLoozerClassClass::GetBonus(int index)
{

    return 0;
}

QString QLoozerClassClass::GetName(int index)
{

    return QString("ga");
}

int QLoozerClassClass::GetStat(int index)
{

    return 0;
}

bool QLoozerClassClass::IsHere(int index)
{
    return true;
}
