#include "ycamera.h"
#include <QDebug>

YCamera::YCamera(QString name, QObject *parent)
{
    qDebug() << "YCamera(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
}

YCamera::~YCamera()
{
    qDebug() << "~YCamera()";
}
