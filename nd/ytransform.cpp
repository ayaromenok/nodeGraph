#include "ytransform.h"
#include <QDebug>

YTransform::YTransform(QString name, QObject *parent)
{
    qDebug() << "YTransform(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);

    _pos.x = 0.0;
    _pos.y = 0.0;
    _pos.z = 0.0;
}

YTransform::~YTransform()
{
    qDebug() << "~YTransform()";
}
