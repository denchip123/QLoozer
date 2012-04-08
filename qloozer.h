#ifndef QLOOZER_H
#define QLOOZER_H

#include <QMainWindow>

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
    void MakeConnections();
    void AddStudentRow(QString name, int raiting);

private slots:
    void OnFindLooserClicked();
    void OnClassChange(QString newClass);
    void OnChooseAnotherClassFile();
};

#endif // QLOOZER_H
