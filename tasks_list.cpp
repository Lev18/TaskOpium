#include "tasks_list.h"
#include "ui_tasks_list.h"


tasks_list::tasks_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tasks_list)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // creating scroll area
    scroll_area = new QScrollArea(this);
    layout->addWidget(scroll_area );

    connect(scroll_area->verticalScrollBar(),
            &QScrollBar::valueChanged, this, &tasks_list::update_window_size);
    ui->setupUi(this);
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


