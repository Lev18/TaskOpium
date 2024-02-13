#include "tasks_list.h"
#include "ui_tasks_list.h"


tasks_list::tasks_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tasks_list)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    task_list.push_back(new Task("Task 1","Create task"));
    task_list.push_back(new Task("Task 2","Change task"));
    task_list.push_back(new Task("Task 3","Change task"));
    task_list.push_back(new Task("Task 4","Change task"));
    task_list.push_back(new Task("Task 5","Change task"));
    for (int i = 0; i < task_list.size(); ++i) {
        QPushButton* button = new QPushButton(task_list[i]->get_task_title());
        connect(button,&QPushButton::clicked,this
                ,&tasks_list::on_button_clicked);
        layout->addWidget(button);
    }

    ui->scrollAreaWidgetContents->setLayout(layout);
}

tasks_list::~tasks_list()
{
    delete ui;
    delete scroll_area;

}

void tasks_list::update_window_size(int val)
{
    QSize size = sizeHint();
    size.setHeight(val + 2 * scroll_area->frameWidth());
    setFixedSize(size);
}

void tasks_list::on_button_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Task","Would you like to edit task"
                                                             ,QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        Task* temp = new Task();
        temp->show();
    }
    else {
        qDebug() << "Noo";
    }


}
