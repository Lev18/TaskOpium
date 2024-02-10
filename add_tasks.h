#ifndef ADD_TASKS_H
#define ADD_TASKS_H

#include "task.h"
#include "ui_add_tasks.h"

#include <QDialog>
#include <QPlainTextEdit>
#include <QDate>
#include <QFile>

#include <fstream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>



QT_BEGIN_NAMESPACE
namespace Ui {
class Add_task;
}
QT_END_NAMESPACE

class Add_task : public QDialog
{
    Q_OBJECT

public:
    explicit Add_task(QWidget *parent = nullptr);
    ~Add_task();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Add_task *ui;
    //std::ofstream m_file;
    Task *new_task;

private:
    void save_tasks_as_json();

};

#endif // ADD_TASKS_H
