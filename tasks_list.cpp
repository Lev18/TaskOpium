#include "tasks_list.h"
#include "ui_tasks_list.h"


tasks_list::tasks_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tasks_list)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    for (int i = 0; i < 25; ++i) {
        QPushButton* button = new QPushButton("Hello scrolling window /n new task");
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


