QT += core
QT -= gui
QT += serialport

DEFINES += QT_MESSAGELOGCONTEXT

TARGET = pincher
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += $$system("find ../../src/ -name *.h")
SOURCES += $$system("find ../../src/ -name *.cpp")

#OPENCV
INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui
PKGCONFIG += opencv
CONFIG += link_pkgconfig
