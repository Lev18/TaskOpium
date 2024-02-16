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
