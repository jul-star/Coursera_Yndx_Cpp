include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_anagramtest.h

SOURCES += \
        main.cpp

win32: LIBS += -L$$PWD/../Anagram_Lib/ -lAnagram

INCLUDEPATH += $$PWD/../Anagram_Lib/include
DEPENDPATH += $$PWD/../Anagram_Lib/include
