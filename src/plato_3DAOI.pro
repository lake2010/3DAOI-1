TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += xml

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
    App/capturesetting.cpp

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
    App/capturesetting.hpp

DISTFILES +=
