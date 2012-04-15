#ifndef QLOOZER_H
#define QLOOZER_H


#include <QMainWindow>
#include <QFileDialog>
#include <QCheckBox>
#include <QStringList>
#include <QTime>

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

private:
    Ui::QLoozer *ui;
    QStringList headerList;
    void MakeConnections();
    void AddStudentRow(QString name, int raiting, int stat);
    int GetLoozer(void);

private slots:
    void OnFindLooserClicked();
    void OnClassChange(QString newClass);
    void OnChooseAnotherClassFile();
};

#endif // QLOOZER_H
