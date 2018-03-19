#include "ypolycube.h"
#include <QDebug>

YPolyCube::YPolyCube(QString name, QObject *parent)
{
    qDebug() << "YPolyCube(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
}

YPolyCube::~YPolyCube()
{
    qDebug() << "~YPolyCube()";
}
