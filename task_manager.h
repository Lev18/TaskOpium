#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "ui_task_manager.h"
#include "add_tasks.h"
#include "tasks_list.h"

#include <memory>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScreen>
#include <QPicture>

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
    QPushButton* add_new_task_button;
    QPushButton* delete_button;
    QPushButton* edit_task_button;
    QPushButton* show_all_task_button;
    //std::unique_ptr<QPushButton> button;

private:
    const size_t m_window_height;
    const size_t m_window_width;
};
#endif // TASK_MANAGER_H
