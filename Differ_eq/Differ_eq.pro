QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += qdarkstyle/style.qrc


SOURCES += \
    Graphs/euler.cpp \
    Graphs/exact.cpp \
    Graphs/imp_euler.cpp \
    Graphs/kunkka.cpp \
    Plotters/error_plotter.cpp \
    Plotters/main_plotter.cpp \
    Plotters/toterror_plotter.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \

HEADERS += \
    Graph.h \
    Graphs/euler.h \
    Graphs/exact.h \
    Graphs/imp_euler.h \
    Graphs/kunkka.h \
    Plotters/error_plotter.h \
    Plotters/main_plotter.h \
    Plotters/toterror_plotter.h \
    mainwindow.h \
    plotter.h \
    qcustomplot.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
