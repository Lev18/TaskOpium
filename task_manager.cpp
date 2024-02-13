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
    widget = new QWidget;

    QScreen *target_screen = QApplication::screens().at(0);

    // create buttons
    add_new_task_button = new QPushButton("Add new task");
    delete_button = new QPushButton("Delete task");
    edit_task_button = new QPushButton("Edit tasks");
    show_all_task_button = new QPushButton("Show all tasks");

    // connect buttons pushment to function
    connect(add_new_task_button, &QPushButton::clicked, this,
            &Task_manager::on_pushButton_clicked);
    connect(show_all_task_button, &QPushButton::clicked, this,
            &Task_manager::on_pushButton_2_clicked);

    // creating vertical layouts for buttons and picture
    vlayout = new QVBoxLayout;

    QDir dir;
    QString image_path = "/home/levon/Workspace/Taskopium/images/pixlr-image-generator-1db45a92-d3ce-4b6c-be46-4d921e46ac29.png";

    if (QFile::exists(image_path)) {
        m_image = QImage(image_path);
        if(m_image.isNull()){
            qDebug() << "Unable to load picture";
        }
    }
    else {
        qDebug() << "Image not found at" << image_path;
    }

    m_image_label = new QLabel(this);
    m_image_label->setScaledContents(true);
    m_image_label->setPixmap(QPixmap::fromImage(m_image));
    m_image_label->setFixedSize(340,400);

    // creating text label
    QLabel *text_label = new QLabel();
    text_label->setGeometry(550,845,845,550);
    text_label->setText("Welcome Tascopium");

    // setting text font
    QFont font("Arial",16);
    text_label->setFont(font);

    // adding them to widget
    vlayout->addWidget(text_label);
    vlayout->addWidget(m_image_label);
    vlayout->addWidget(add_new_task_button);
    vlayout->addWidget(delete_button);
    vlayout->addWidget(edit_task_button);
    vlayout->addWidget(show_all_task_button);

    // widget->setLayout(hlayout);
    widget->setLayout(vlayout);
    widget->window()->setScreen(target_screen);
    widget->resize(m_window_height, m_window_width);
    widget->show();
}

Task_manager::~Task_manager()
{
    delete ui;
    delete widget;
    delete vlayout;
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
    delete m_image_label;
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



