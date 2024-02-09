#ifndef TASK_H
#define TASK_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class Task;
}

class Task : public QDialog
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QString m_task_title;
    QString m_task_description;
    Ui::Task *ui;
};

#endif // TASK_H
