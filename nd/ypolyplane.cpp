#include "ypolyplane.h"
#include <QDebug>

YPolyPlane::YPolyPlane(QString name, QObject *parent)
{
    qDebug() << "YPolyPlane(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
}

YPolyPlane::~YPolyPlane()
{
    qDebug() << "~YPolyPlane()";
}
