QT += qml quick

TARGET = 31_nodeGraphConsole

DEFINES += GIT_VERSION=\\\"$$system(git describe --tags)\\\"
DEFINES += GIT_VERSION0=\\\"$$system(git describe --tags > $$PWD/program_version.txt)\\\"
DEFINES += GIT_VERSION1=\\\"$$system(git rev-list --all --count >> $$PWD/program_version.txt)\\\"
DEFINES += GIT_VERSION2=\\\"$$system(git branch | grep \* >> $$PWD/program_version.txt)\\\"

# or git descrinbe --tags & git branch
CONFIG += c++11

SOURCES += mainConsole.cpp \
    nd/ynode.cpp \
    test/ytestnodes.cpp

HEADERS += \
    nd/ynode.h \
    test/ytestnodes.h \
    nd/ynodeList.h


