#ifndef TASKS_LIST_H
#define TASKS_LIST_H

#include "task.h"

#include <filesystem>
#include <fstream>
#include <string>

#include <QVector>
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
    QVector<std::string> task_title_list;

private:
    void update_window_size(int val);
    void on_button_clicked();
    void read_from_file();
    void remove_par(std::string& str);
};

#endif // TASKS_LIST_H
