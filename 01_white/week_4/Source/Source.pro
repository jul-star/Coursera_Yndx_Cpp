CONFIG -= qt

TEMPLATE = lib
TARGET=WhiteWeek04

CONFIG += c++1z
#Linking as an internal lib. If you'd like to link as external lib uncoment next 6 lines.
#LIB_DIR = /../WhiteWeek04_Lib
#build_pass:CONFIG(debug, debug|release){
#DESTDIR=$$PWD$$LIB_DIR
#} else {
#DESTDIR=$$PWD$$LIB_DIR
#}

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \


HEADERS += \ \
    wt_w4_e01.h \
    wt_w4_e02.h \
    wt_w4_e03.h \
    wt_w4_e04.h \
    wt_w4_e05.h



