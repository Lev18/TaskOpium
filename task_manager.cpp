#include "task_manager.h"
#include "ui_task_manager.h"
#include "add_tasks.h"

Task_manager::Task_manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_manager)
{
    ui->setupUi(this);
}

Task_manager::~Task_manager()
{
    delete ui;
    delete task;
}

void Task_manager::on_pushButton_clicked()
{
    task = new Add_task();
    task->show();
}


void Task_manager::on_pushButton_2_clicked()
{

}

