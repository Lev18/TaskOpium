#ifndef TASKS_LIST_H
#define TASKS_LIST_H

#include <QDialog>

namespace Ui {
class tasks_list;
}

class tasks_list : public QDialog
{
    Q_OBJECT

public:
    explicit tasks_list(QWidget *parent = nullptr);
    ~tasks_list();

private:
    Ui::tasks_list *ui;
};

#endif // TASKS_LIST_H
