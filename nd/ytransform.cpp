#include "ytransform.h"
#include <QDebug>

YTransform::YTransform(QString name, QObject *parent)
{
    qDebug() << "YTransform(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
}

YTransform::~YTransform()
{
    qDebug() << "~YTransform()";
}
