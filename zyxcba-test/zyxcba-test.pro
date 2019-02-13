TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += ZYXCBA_DEBUG

include(../src/zyxcba.pri)

SOURCES += \
        main.cpp
