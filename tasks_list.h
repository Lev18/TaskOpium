#ifndef TASKS_LIST_H
#define TASKS_LIST_H

#include "task.h"

#include <QScrollBar>
#include <QScrollArea>
#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>

namespace Ui {
class tasks_list;
}

class tasks_list : public QDialog
{
    Q_OBJECT

public:
    explicit tasks_list(QWidget *parent = nullptr);
    ~tasks_list();

private slots:

private:
    Ui::tasks_list *ui;
    QScrollArea *scroll_area;
    QVector<Task*> task_list;

private:
    void update_window_size(int val);
    void on_button_clicked();
};

#endif // TASKS_LIST_H
