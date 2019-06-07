include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
QT += webengine webenginewidgets network

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage

LIBS += -lgcov

HEADERS += \
    ../app/webviewinterface.h \
    ../app/token.h \
    ../app/datareceiver.h \
    ../app/vk.h \
    ../app/profileloader.h \
    ../app/postloader.h \
    ../app/post.h \
    ../app/loadthread.h \
    ../app/dataloadthread.h \
    tests.h

SOURCES += \
        main.cpp \
    ../app/webviewinterface.cpp \
    ../app/datareceiver.cpp \
    ../app/token.cpp \
    ../app/vk.cpp \
    ../app/profileloader.cpp \
    ../app/postloader.cpp \
    ../app/post.cpp \
    ../app/loadthread.cpp \
    ../app/dataloadthread.cpp

INCLUDEPATH += ../app
