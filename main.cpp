#include "task_manager.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <fstream>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString filePath = QDir::homePath() + "/Workspace/Taskopium/Font/SpyBot.qss";
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
