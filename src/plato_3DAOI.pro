TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += xml
QT += core

SOURCES += main.cpp \
    App/appsetting.cpp \
    Job/inspectiondata.cpp \
    Job/board.cpp \
    Job/measuredobjlist.cpp \
    Job/measuredobj.cpp \
    SDK/rectangle.cpp \
    SDK/customexception.cpp \
    SDK/datahelper.cpp \
    App/datagenerator.cpp \
    App/capturesetting.cpp \
    App/appstartup.cpp \
    DB/blob.cpp \
    DB/sqlitedb.cpp \

HEADERS += \
    App/appsetting.hpp \
    Job/inspectiondata.hpp \
    Job/board.hpp \
    Job/measuredobjlist.hpp \
    Job/measuredobj.hpp \
    SDK/rectangle.hpp \
    SDK/customexception.hpp \
    SDK/datahelper.hpp \
    App/datagenerator.hpp \
    App/capturesetting.hpp \
    App/appstartup.hpp \
    DB/blob.hpp \
    DB/sqlitedb.hpp \

DISTFILES +=

INCLUDEPATH += $$PWD/../include/sqlite
INCLUDEPATH += $$PWD/../include

unix::LIBS += -L$$PWD/../lib/ -lsqlite3

unix::LIBS += -L/usr/lib/x86_64-linux-gnu\
-ldl
