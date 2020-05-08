include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    ToTest.h \
#    tst_yl_w1_e01.h \
#    tst_yl_w1_e02.h \
#    tst_yl_w1_e03.h \
    tst_yl_w1_e04.h

SOURCES += \
        main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Source/release/ -lYellowWeek01
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Source/debug/ -lYellowWeek01

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source
