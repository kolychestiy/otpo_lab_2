TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    append_line.c \
    create_text.c \
    editor.c \
    load.c \
    move.c \
    plb.c \
    process_forward.c \
    remove_all.c \
    save.c \
    show.c \
    showclassified.c \
    split.c

HEADERS += \
    text.h \
    _text.h \
    common.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
