#include "task_manager.h"
#include "ui_task_manager.h"

Task_manager::Task_manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_manager)
    , new_task{nullptr}
    , tasks{nullptr}
    , m_window_height{845}
    , m_window_width {550}
{
    ui->setupUi(this);
    QWidget * widget = new QWidget;

    QScreen *target_screen = QApplication::screens().at(0);


    add_new_task_button = new QPushButton("Add new task");
    delete_button = new QPushButton("Delete task");
    edit_task_button = new QPushButton("Edit tasks");
    show_all_task_button = new QPushButton("Show all tasks");

    // set layout from top of window
    add_new_task_button->setStyleSheet("margin-top: 170px;");

    // connect button pushment to function
    connect(add_new_task_button, &QPushButton::clicked, this,
            &Task_manager::on_pushButton_clicked);

    // creating layouts for bottons
    QVBoxLayout* hlayout = new QVBoxLayout;

    hlayout->addWidget(add_new_task_button);
    hlayout->addWidget(delete_button);
    hlayout->addWidget(edit_task_button);
    hlayout->addWidget(show_all_task_button);

    widget->setLayout(hlayout);
    widget->window()->setScreen(target_screen);
    widget->resize(m_window_height, m_window_width);
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
    delete add_new_task_button;
    delete delete_button;
    delete edit_task_button;
    delete show_all_task_button;
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



