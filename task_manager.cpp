#include "task_manager.h"
#include "ui_task_manager.h"

Task_manager::Task_manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_manager)
    , new_task{nullptr}
    , tasks{nullptr}
{
    ui->setupUi(this);
    QWidget * widget = new QWidget;

    QPushButton* botton_1 = new QPushButton("A");
    QPushButton* botton_2 = new QPushButton("B");
    QPushButton* botton_3 = new QPushButton("C");

    QHBoxLayout* hlayout = new QHBoxLayout;

    hlayout->addWidget(botton_1);
    hlayout->addWidget(botton_2);
    hlayout->addWidget(botton_3);

    widget->setLayout(hlayout);
    widget->setScreen();
    widget->show();


}

Task_manager::~Task_manager()
{
    delete ui;
    if (new_task) {
        delete new_task;
    }
    if (tasks) {
        delete tasks;
    }
}

void Task_manager::on_pushButton_clicked()
{
    new_task = new Add_task;
    new_task->show();
}


void Task_manager::on_pushButton_2_clicked()
{
    tasks = new tasks_list;
    tasks->show();
}



