#include "add_tasks.h"

#include <iostream>
#include <QDebug>
#include <QTextStream>
#include <QFile>

Add_task::Add_task(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_task)
    , new_task(nullptr)
{
    ui->setupUi(this);
}

Add_task::~Add_task()
{
    delete ui;
    delete new_task;
}

void Add_task::save_tasks_as_json()
{

    std::ofstream m_file("/home/levon/Workspace/Taskopium/server/serv.txt", std::fstream::out | std::fstream::app);

        if (!m_file.is_open()) {
            std::cerr << "Unable to launch server file" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        Json::Value root;
        root["Title"] = new_task->get_task_title().toStdString();
        root["Descript"] = new_task->get_task_description().toStdString();
        std::cout << root.toStyledString();

        Json::StyledWriter writer;
       //  m_file << "Hello" << std::endl;
        m_file << writer.write(root);
        std::cout << "writed in file" << std::endl;
        m_file.close();


}

void Add_task::on_pushButton_clicked()
{
    // m_task_title = ui->textEdit_2->toPlainText();
    // m_task_description = ui->textEdit->toPlainText();
    new_task = new Task(ui->textEdit_2->toPlainText()
                        ,ui->textEdit->toPlainText());
     save_tasks_as_json();

    ui->textEdit->clear();
    ui->textEdit_2->clear();
    // qDebug() << m_task_title;
    QDialog::close();

}


void Add_task::on_pushButton_2_clicked()
{
    QDialog::close();
}

