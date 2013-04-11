#-------------------------------------------------
#
# Project created by QtCreator 2013-03-16T20:07:43
#
#-------------------------------------------------
extralib.target = extra
extralib.commands =	echo "Building extralib.."; \
                        pwd; \
                                make -w -C ../tthCalculatorQt5/librhash; \
                                echo "Done building extralib."; \

QMAKE_EXTRA_TARGETS += extralib
PRE_TARGETDEPS = extra


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tthCalculatorQt5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    listchecker.cpp \
    dirviewer.cpp

HEADERS  += mainwindow.h \
    listchecker.h \
    dirviewer.h

FORMS    += mainwindow.ui \
    dirviewer.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/librhash/ -lrhash
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/librhash/ -lrhash
else:unix: LIBS += -L$$PWD/librhash/ -lrhash

INCLUDEPATH += $$PWD/librhash
DEPENDPATH += $$PWD/librhash
