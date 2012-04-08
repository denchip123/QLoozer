#ifndef QLOOZERCLASSFILESPARSER_H
#define QLOOZERCLASSFILESPARSER_H

#include "qloozerclassclass.h"
#include <QTextStream>
#include <QFile>
#include <QList>
#include <dirent.h>

class QLoozerClassFilesParser
{
public:
    QLoozerClassFilesParser();
    ~QLoozerClassFilesParser();
    QLoozerClassClass Parse(QString fileName);
    QList<QLoozerClassClass>* classes;
private:
    bool Match(char *string, char *pattern);
    QLoozerClassClass* badCP;
};

#endif // QLOOZERCLASSFILESPARSER_H
