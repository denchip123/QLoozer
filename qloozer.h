#ifndef QLOOZER_H
#define QLOOZER_H


#include <QMainWindow>
#include <QFileDialog>
#include <QCheckBox>
#include <QStringList>
#include <QTime>
#include "qloozerluaapi.h"

namespace Ui {
    class QLoozer;
}

class QLoozer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QLoozer(QWidget *parent = 0);
    ~QLoozer();
public slots:
    void OpenClassFile(QString file);
    void AddStudentRow(QString name, int raiting, int stat);

private:
    Ui::QLoozer *ui;
    QStringList headerList;
    void MakeConnections();

private slots:
    void OnFindLooserClicked();
    void OnClassChange(QString newClass);
    void OnChooseAnotherClassFile();
};

#endif // QLOOZER_H
