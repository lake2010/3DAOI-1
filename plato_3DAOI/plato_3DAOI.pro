TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += xml

SOURCES += main.cpp \
    App/app.cpp \
    App/appsetting.cpp \
    Job/inspectiondata.cpp \
    Job/board.cpp \
    Job/measuredobjlist.cpp \
    Job/measuredobj.cpp \
    SDK/rectangle.cpp \
    SDK/customexception.cpp \

HEADERS += \
    App/app.hpp \
    App/appsetting.hpp \
    Job/inspectiondata.hpp \
    Job/board.hpp \
    Job/measuredobjlist.hpp \
    Job/measuredobj.hpp \
    SDK/rectangle.hpp \
    SDK/customexception.hpp \

DISTFILES +=
