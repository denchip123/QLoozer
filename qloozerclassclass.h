#ifndef QLOOZERCLASSCLASS_H
#define QLOOZERCLASSCLASS_H

#include <QString>
#include <QStringList>
#include <QList>

class QLoozerClassClass
{
public:
    ~QLoozerClassClass();
    QLoozerClassClass();
    QString GetName(int index);
    int GetBonus(int index);
    int GetStat(int index);
    bool IsHere(int index);
    void AddStudent(QString studentName, int studentBonus, int studentStat);
private:
    QStringList* name;
    QList<int>* bonus;
    QList<int>* stat;
    QList<bool>* here;
};

#endif // QLOOZERCLASSCLASS_H
