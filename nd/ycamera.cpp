#include "ycamera.h"
#include <QDebug>

YCamera::YCamera(QString name, QObject *parent)
{
    qDebug() << "YCamera(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
    _ortho = false;
    _cap = double2{1.5, 1.0};
}

YCamera::~YCamera()
{
    qDebug() << "~YCamera()";
}

void
YCamera::dumpObjectData(int intend)
{
    QByteArray buf;
    buf.fill(' ',(intend+4));

    qDebug("%s%s: %s", static_cast<const char*>(buf),
           "ortho",(_ortho?"true":"false"));
    if ((_cap.x != 1.5) || (_cap.y != 1.0))
    qDebug("%s%s: %6.3f, %6.3f", static_cast<const char*>(buf),
           "camera aperture", _cap.x, _cap.y);
}
