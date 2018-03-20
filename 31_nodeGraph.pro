QT += qml quick

TARGET = 31_nodeGraphConsole

DEFINES += GIT_VERSION=\\\"$$system(git describe --tags)\\\"
DEFINES += GIT_VERSION0=\\\"$$system(git describe --tags > $$PWD/program_version.txt)\\\"
DEFINES += GIT_VERSION1=\\\"$$system(git rev-list --all --count >> $$PWD/program_version.txt)\\\"
DEFINES += GIT_VERSION2=\\\"$$system(git branch | grep \* >> $$PWD/program_version.txt)\\\"

# or git descrinbe --tags & git branch
CONFIG += c++11

SOURCES += mainConsole.cpp \
    test/ytestnodes.cpp \
    nd/ynode.cpp \
    nd/ycamera.cpp \
    nd/ymesh.cpp \
    nd/ypolycube.cpp \
    nd/ypolyplane.cpp \
    nd/yscript.cpp \
    nd/ytransform.cpp

HEADERS += \
    test/ytestnodes.h \
    nd/ynode.h \    
    nd/ycamera.h \
    nd/ynodelist.h \
    nd/ymesh.h \    
    nd/ypolycube.h \
    nd/ypolyplane.h \
    nd/yscript.h \
    nd/ytransform.h \
    core/ybasictypes.h


