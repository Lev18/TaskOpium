#include "taskopium.h"
#include "ui_taskopium.h"
#include "task.h"
Taskopium::Taskopium(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Taskopium)
{
    ui->setupUi(this);
}

Taskopium::~Taskopium()
{
    delete ui;
    delete task;
}

void Taskopium::on_pushButton_clicked()
{
    task = new Task();
    task->show();
}

