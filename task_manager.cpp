#include "task_manager.h"
#include "ui_task_manager.h"
#include <memory>

Task_manager::Task_manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_manager)
    , add_new_task_button{nullptr}
    , tasks{nullptr}
    , m_window_height{1000}
    , m_window_width {750}
{
    this->setFixedSize(m_window_width, m_window_height);
    ui->setupUi(this);
    widget = new QWidget;

    QScreen *target_screen = QApplication::screens().at(0);

    // create buttons
    add_new_task_button = new QPushButton("Add new task", this);
    delete_button = new QPushButton("Delete task", this);
    edit_task_button = new QPushButton("Edit tasks", this);
    show_all_task_button = new QPushButton("Show all tasks", this);

    // connect buttons pushment to function
    connect(add_new_task_button, &QPushButton::clicked, this,
            &Task_manager::on_pushButton_clicked);
    connect(show_all_task_button, &QPushButton::clicked, this,
            &Task_manager::on_pushButton_2_clicked);
    connect(edit_task_button, &QPushButton::clicked, this,
            &Task_manager::pushButton_clicked_3);

    // creating vertical layouts for buttons and picture
    vlayout = new QVBoxLayout;

    QDir dir;
    QString image_path = dir.absoluteFilePath("pixlr-image-generator-1db45a92-d3ce-4b6c-be46-4d921e46ac29.png");

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
    //QLabel* text_label =  new QLabel();

    std::unique_ptr<QLabel> text_label = std::make_unique<QLabel>(new QLabel("Welcome Tascopium"));
    text_label->setGeometry(550,845,845,550);
    // setting text font
    QFont font("Arial",16);
    text_label->setFont(font);

    // adding them to widget
    vlayout->addWidget(text_label.get());
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
    delete delete_button;
    delete add_new_task_button;
    delete edit_task_button;
    delete show_all_task_button;
    delete m_image_label;
}

void Task_manager::on_pushButton_clicked()
{
    new_task = std::make_unique<Add_task>(new Add_task());
    new_task->show();
   // delete new_task;
}


void Task_manager::on_pushButton_2_clicked()
{
    tasks = std::make_unique<tasks_list>(new tasks_list());
    tasks->show();

}

void Task_manager::pushButton_clicked_3()
{
    bool ok{false};
    QInputDialog dialog;

    dialog.setMinimumHeight(400);
    dialog.setInputMode(QInputDialog::TextInput);
    dialog.resize(400,200);

    QString task_id = dialog.getText(this, tr("Enter task id"),
                                            tr("Task Id"), QLineEdit::Normal,
                                            "Tas Id", &ok);
    qDebug() << task_id;

    //delete dialog;

}


