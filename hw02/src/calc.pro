TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c99 -pedantic -Wall -Wextra -Werror

SOURCES += \
    calc.c
