include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/input/\\\"

HEADERS += \
    ../app/text.h \
    ../app/_text.h \
    ../app/common.h \
    test_load.h \
    test_move.h \
    test_plb.h \
    test_save.h \
    test_show.h \
    test_showcl.h \
    test_split.h

SOURCES +=     main.cpp \
    ../app/append_line.c \
    ../app/create_text.c \
    ../app/load.c \
    ../app/move.c \
    ../app/plb.c \
    ../app/process_forward.c \
    ../app/remove_all.c \
    ../app/save.c \
    ../app/show.c \
    ../app/showclassified.c \
    ../app/split.c


INCLUDEPATH += ../app \

DISTFILES += \
    input/TestSTDOut_output.txt
