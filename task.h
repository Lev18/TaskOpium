#ifndef TASK_H
#define TASK_H

#include <QDialog>
#include <QDateTime>


namespace Ui {
class Task;
}

class Task : public QDialog
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    Task(const QString& title, const QString& descript);
    ~Task();

private:
    Ui::Task *ui;
    QString m_task_title;
    QString m_task_description;
    QDateTime m_date;
public:
    QString get_task_title() const;
    QString get_task_description() const;

};

#endif // TASK_H
