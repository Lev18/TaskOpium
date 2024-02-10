#include "tasks_list.h"
#include "ui_tasks_list.h"

tasks_list::tasks_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tasks_list)
{
    ui->setupUi(this);
}

tasks_list::~tasks_list()
{
    delete ui;
}
