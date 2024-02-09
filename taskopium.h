#ifndef TASKOPIUM_H
#define TASKOPIUM_H

#include "task.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Taskopium;
}
QT_END_NAMESPACE

class Taskopium : public QMainWindow
{
    Q_OBJECT

public:
    Taskopium(QWidget *parent = nullptr);
    ~Taskopium();

private slots:
    void on_pushButton_clicked();

private:
    Task *task;
    Ui::Taskopium *ui;
};
#endif // TASKOPIUM_H
