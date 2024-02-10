#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "add_tasks.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Task_manager;
}
QT_END_NAMESPACE

class Task_manager : public QMainWindow
{
    Q_OBJECT

public:
    Task_manager(QWidget *parent = nullptr);
    ~Task_manager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Add_task *task;
    Ui::Task_manager *ui;
};
#endif // TASK_MANAGER_H
