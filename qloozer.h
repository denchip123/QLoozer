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

private:
    Ui::QLoozer *ui;
};

#endif // QLOOZER_H
