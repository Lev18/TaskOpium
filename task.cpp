#include "task.h"
#include "ui_task.h"

#include <QDebug>
Task::Task(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);
}

Task::~Task()
{
    delete ui;
}


void Task::on_pushButton_clicked()
{
    m_task_title = ui->textEdit_2->toPlainText();
    m_task_description = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    qDebug() << m_task_title;
}


void Task::on_pushButton_2_clicked()
{
    QDialog::close();
}

