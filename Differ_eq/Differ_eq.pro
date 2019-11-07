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
    error_plotter.cpp \
    euler.cpp \
    exact.cpp \
    imp_euler.cpp \
    kunkka.cpp \
    main.cpp \
    main_plotter.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    toterror_graph.cpp

HEADERS += \
    Graph.h \
    error_plotter.h \
    euler.h \
    exact.h \
    imp_euler.h \
    kunkka.h \
    main_plotter.h \
    mainwindow.h \
    plotter.h \
    qcustomplot.h \
    toterror_graph.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
