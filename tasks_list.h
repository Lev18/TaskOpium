#ifndef TASKS_LIST_H
#define TASKS_LIST_H

#include <QScrollBar>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDialog>
#include <QWidget>

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
private:
    void update_window_size(int val);
};

#endif // TASKS_LIST_H
