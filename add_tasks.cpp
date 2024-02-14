#include "add_tasks.h"
#include "global.h"

Add_task::Add_task(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_task)
    , new_task(nullptr)
{

    ui->setupUi(this);
    ui->comboBox->addItem("Done");
    ui->comboBox->addItem("In Progress");
    ui->comboBox->addItem("Backlog");
    ui->comboBox->addItem("Failed");

    ui->comboBox_2->addItem("Low");
    ui->comboBox_2->addItem("Medium");
    ui->comboBox_2->addItem("High");
    setWindowTitle("Add new task");
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
        root["Task ID"] = m_task_id;
        root["Title"] = new_task->get_task_description().toStdString();
        root["Descript"] = new_task->get_task_description().toStdString();
        root["Priority"] = ui->comboBox_2->currentText().toStdString();
        root["Status"] = m_task_status.toStdString();
        root["Date"] = m_task_date.toStdString();
        std::cout << root.toStyledString();

        Json::StyledWriter writer;
       //  m_file << "Hello" << std::endl;
        m_file << writer.write(root);

        m_file.close();
}

void Add_task::on_pushButton_clicked()
{
    m_task_title = ui->lineEdit_3->text();
    m_task_description = ui->textEdit->toPlainText();
    m_task_status = ui->comboBox->currentText();
    m_task_priority = ui->comboBox_2->currentText();
    m_task_date = ui->calendarWidget->selectedDate().toString();
    m_task_id = Global::get_next_task_id();

    new_task = new Task(m_task_id, m_task_title
                        , m_task_description);
    qDebug() << m_task_priority;
    save_tasks_as_json();

    ui->lineEdit_3->clear();
    QDialog::close();

}


void Add_task::on_pushButton_2_clicked()
{
    QDialog::close();
}




