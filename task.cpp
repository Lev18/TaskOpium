#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);
}

Task::Task(int task_id, const QString& title, const QString& descript)
    : m_task_title(title)
    , m_task_description(descript)
{

}

Task::~Task()
{
    delete ui;
}

QString Task::get_task_title() const
{
    return m_task_title;
}

QString Task::get_task_description() const
{
    return m_task_description;
}

void Task::on_pushButton_clicked()
{
    // Todo implemented
}


void Task::on_pushButton_2_clicked()
{
    QDialog::close();
}

