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

void
YTransform::dumpObjectData(int intend)
{
    QByteArray buf;
    buf.fill(' ',(intend+4));
    qDebug("%s%s: %6.3f, %6.3f, %6.3f", static_cast<const char*>(buf),
           "double3", _pos.x, _pos.y, _pos.z);
}
