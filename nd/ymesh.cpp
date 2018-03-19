#include "ymesh.h"
#include <QDebug>

YMesh::YMesh(QString name, QObject *parent)
{
    qDebug() << "YMesh(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
}

YMesh::~YMesh()
{
    qDebug() << "~YMesh()";
}
