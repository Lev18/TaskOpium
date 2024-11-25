#include "task_manager.h"

#include <filesystem>
#include <fstream>
#include <string>

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/levon/Workspace/Taskopium/server/db.sqlite");


    auto d_v = db.open();
    qDebug() << d_v;
    if (!db.open()) {
        qDebug() << "Problem to open file";
    }


    QSqlQuery qry;
/*
    QString query = "CREATE TABLE test ("
                    "ID INTEGER PRIMARY KEY,"
                    "FirstName VARCHAR(20),"
                    "LastName VARCHAR(20),"
                    "Birthday DATETIME);";
*/
    // auto v = qry.exec(query);
    // qDebug()  << v;
    // if (!qry.exec(query)) {
    //     qDebug() << "error creating table" <<  qry.lastError().text();
    // }

    QSqlQuery select;
    qry.prepare("INSERT INTO test(ID, FirstName, LastName, Birthday) Values(:ID, :Name, LName, Bday)");
    qry.bindValue(":ID", 15);
    qry.bindValue(":Name", "John");
    qry.bindValue(":LName", "Bolton");
    qry.bindValue(":Bday", "1990-05-15");

    qry.exec();

    select.exec();
    auto val = select.exec("SELECT * FROM test;");
    qDebug() << val;
    if (val) {
        while (qry.next()) {
            QString tableName = select.value(0).toString();
            qDebug() << "Table: " << tableName; // Output the table name
        }
    }
    else {
        qDebug() << "Query failed: " << select.lastError().text();
    }

    QApplication a(argc, argv);
   // QDir dir;
    std::string file_path = std::filesystem::absolute("Diffnes.qss");
    QString filePath = QString::fromLocal8Bit(file_path);
    QFile styleSheetFile(filePath);
    if (!styleSheetFile.open(QFile::ReadOnly)) {
        qDebug() << "Unable open file" ;
    }
    QString styleSheet = QLatin1String(styleSheetFile.readAll());

    a.setStyleSheet(styleSheet);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Taskopium_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    Task_manager w;


    // w.show();
    return a.exec();
}
