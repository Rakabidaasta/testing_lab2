include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES += main.cpp \
    ../app/load.cpp \
    ../app/save.cpp \
    ../app/show.cpp \
    ../app/showupper.cpp \
    ../app/text/append_line.cpp \
    ../app/text/create_text.cpp \
    ../app/text/m.cpp \
    ../app/text/mlb.cpp \
    ../app/text/process_forward.cpp \
    ../app/text/r1e.cpp \
    ../app/text/remove_all.cpp

HEADERS += \
    ../app/text/text.h \
    ../app/text/_text.h \
    ../app/common.h \
    load.h \
    m.h \
    mlb.h \
    r1e.h \
    save.h \
    all_tests.h \
    showupper.h

INCLUDEPATH += ../app
