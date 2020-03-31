TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32: LIBS += -L$$PWD/../UniqueString_Lib/ -lUniqueString

INCLUDEPATH += $$PWD/../UniqueString_Lib
DEPENDPATH += $$PWD/../UniqueString_Lib
