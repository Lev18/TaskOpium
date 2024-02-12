#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "ui_task_manager.h"
#include "add_tasks.h"
#include "tasks_list.h"

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>

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
    Ui::Task_manager *ui;
    Add_task *new_task;
    tasks_list *tasks;
};
#endif // TASK_MANAGER_H
