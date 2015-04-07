#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T12:40:12
#
#-------------------------------------------------

QT       += core gui testlib
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app

FORMS += \
    forms/mainwindow.ui

HEADERS += \
    inc/core/scanner.h \
    inc/core/token.h \
    inc/gui/mainwindow.h \
    inc/tests/mathTestHeader.h \
    src/core/parser.h \
    src/core/evaluator.h \
    inc/core/evaluator.h \
    inc/core/parser.h \
    inc/core/math.h

SOURCES += \
    src/core/scanner.cpp \
    src/core/token.cpp \
    src/gui/main.cpp \
    src/gui/mainwindow.cpp \
    src/tests/mathTest.cpp \
    src/core/parser.cpp \
    src/core/evaluator.cpp \
    src/core/math.cpp
