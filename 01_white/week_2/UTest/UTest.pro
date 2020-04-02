include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    ToTest.h \
    tst_anagramtest.h \
    tst_capitaltest.h \
    tst_uniquestringtest.h \
    tst_wt_w2_e01.h

SOURCES += \
        main.cpp
