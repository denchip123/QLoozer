#ifndef QLOOZERCLASSFILESPARSER_H
#define QLOOZERCLASSFILESPARSER_H

#include "qloozerclassclass.h"
#include <QTextStream>
#include <QFile>
#include <dirent.h>

class QLoozerClassFilesParser
{
public:
    QLoozerClassFilesParser();
    ~QLoozerClassFilesParser();
    QLoozerClassClass Parse(QString fileName);
    QLoozerClassClass GetThisClass(int index);
    QLoozerClassClass classes[100+5];
    int classes_count;
private:
    bool Match(char *string, char *pattern);
    QLoozerClassClass* badCP;

};

#endif // QLOOZERCLASSFILESPARSER_H
