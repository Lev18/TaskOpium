#include "add_tasks.h"

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
    std::string file_path = std::filesystem::absolute("serv.txt");
    std::ofstream m_file(file_path , std::fstream::out | std::fstream::app);

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

        m_file.close();
}

void Add_task::on_pushButton_clicked()
{
    m_task_title = ui->textEdit_2->toPlainText();
    m_task_description = ui->lineEdit_3->text();
    new_task = new Task(ui->textEdit_2->toPlainText()
                        , ui->lineEdit_3->text());
    save_tasks_as_json();

    ui->lineEdit_3->clear();
    ui->textEdit_2->clear();
    // // qDebug() << m_task_title;
    QDialog::close();

}


void Add_task::on_pushButton_2_clicked()
{
    QDialog::close();
}

