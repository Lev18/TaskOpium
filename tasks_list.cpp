#include "tasks_list.h"
#include "ui_tasks_list.h"

#include <memory>

tasks_list::tasks_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tasks_list)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    tasks_list::read_from_file();
    QPushButton* button;
    for (int i = 0; i < task_title_list.size(); ++i) {
        button = new QPushButton(QString::fromLocal8Bit(task_title_list[i].c_str()));
        button->setMinimumHeight(32);
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
        delete temp;
    }
    else {
        qDebug() << "Noo";
    }  
}

void tasks_list::read_from_file()
{
    std::string file_path = std::filesystem::absolute("server.json");
    std::ifstream file(file_path, std::fstream::in);
    if (!file.is_open()) {
        std::exit(1);
    }
    std::string line {};
    std::string title {};
    while(std::getline(file,line))  {
        if(line.find("Title") != std::string::npos) {
            // size_t pos = line.find('"');
            title = line.substr(14);
            remove_par(title);
            task_title_list.push_back(title);
            // break;
        }
    }
    file.close();
}

void tasks_list::remove_par(std::string& task_title)
{
    size_t pos = task_title.find('"');
    if (pos != std::string::npos) {
        task_title = task_title.substr(0,pos);
    }

}
