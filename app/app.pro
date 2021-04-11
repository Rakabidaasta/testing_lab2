TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    editor.cpp \
    load.cpp \
    save.cpp \
    show.cpp \
    showupper.cpp \
    text/append_line.cpp \
    text/create_text.cpp \
    text/m.cpp \
    text/mlb.cpp \
    text/process_forward.cpp \
    text/r1e.cpp \
    text/remove_all.cpp

HEADERS += \
    text/text.h \
    text/_text.h \
    common.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
