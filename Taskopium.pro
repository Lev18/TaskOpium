QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_tasks.cpp \
    global.cpp \
    main.cpp \
    task.cpp \
    task_manager.cpp \
    tasks_list.cpp

HEADERS += \
    add_tasks.h \
    global.h \
    task.h \
    task_manager.h \
    tasks_list.h

FORMS += \
    add_tasks.ui \
    task.ui \
    task_manager.ui \
    tasks_list.ui

TRANSLATIONS += \
    Taskopium_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations
LIBS += -ljsoncpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    serv.txt
