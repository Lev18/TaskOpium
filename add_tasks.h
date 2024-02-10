#ifndef TASK_H
#define TASK_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QDate>
#include <jsoncpp/json/json.h>

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
    Ui::Task *ui;
    QString m_task_title;
    QString m_task_description;
    QDateTime date;
};

#endif // TASK_H
