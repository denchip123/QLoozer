#include "qloozerclassfilesparser.h"
#include <dirent.h>

QLoozerClassFilesParser::QLoozerClassFilesParser()
{
    classes = new QList<QLoozerClassClass>;
    badCP = new QLoozerClassClass;
    badCP->AddStudent("six",6,6);

    struct dirent *entry;
    DIR *dp;

    dp = opendir("./classes");
    if (dp == NULL) {
        qDebug("Can't open class files directory!");
    }
    qDebug("sdf");
    while((entry = readdir(dp)))
    {
        qDebug("gg");
        QLoozerClassClass tmp = Parse(QString(entry->d_name));
        qDebug("keke");
        QString a, b;
        qDebug("s0adasdwe");
        a = badCP->GetName(0);
        qDebug("s1adasdwe");
        b = tmp.GetName(0);
        qDebug("s2adasdwe");
        if (a != b){
            qDebug("sadasdwe");
            classes->push_back(Parse(QString(entry->d_name)));
        }else qDebug("lol");
    }
    qDebug("sdf");

    closedir(dp);
}

QLoozerClassFilesParser::~QLoozerClassFilesParser()
{
    delete classes;
    delete badCP;
}
//Осторожно -- Костыль
//    (__)_(__)
//       | |
//       | |
//       | |
//       | |
//       \I/
QLoozerClassClass QLoozerClassFilesParser::Parse(QString fileName)
{
    QLoozerClassClass *curClass = new QLoozerClassClass;

    if (fileName == QString('.') || fileName == QString("..")){
        curClass->AddStudent("six",6,6);
        return *curClass;
    }

    int bonus[1000+5], stat[1000+5], count=0;
    QString names[1000+5];


    QFile file;
    QString path = QString("classes/");
    path.push_back(fileName);
    file.setFileName(path);

    bool allOk = file.open(QIODevice::ReadOnly);
    if (!allOk) {
        qDebug("ke ke ke ke can't parse file");
        qDebug(path.toAscii());
    }
    QTextStream in( &file );


    QString curStr="is't Null";
    int temp;
    while((curStr=in.readLine())!="#bonus" && !curStr.isNull())
        names[count++]=curStr;
    for(int i=0;i<count;i++)
    {
        in>>temp;
        bonus[i]=temp;
    }
    curStr=in.readLine();
    for(int i=0;i<count;i++)
    {
        in>>temp;
        stat[i]=temp;
    }
    for(int i=0;i<count;i++)
    {
        curClass->AddStudent(names[i],bonus[i],stat[i]);
    }

    return *curClass;
}


bool QLoozerClassFilesParser::Match(char *string, char *pattern)
{
  for (; '*'^*pattern; ++pattern, ++string)
  {
    if (!*string)
      return (!*pattern);
    if ((*string)^(*pattern) && '?'^*pattern)
      return false;
  }
  /* two-line patch to prevent *too* much recursiveness: */
  while ('*' == pattern[1])
    ++pattern;

  do
  {
    if (Match(string, pattern + 1))
      return true;
  }
  while (*string++);

  return false;
}
