#include "ypolyplane.h"
#include <QDebug>

YPolyPlane::YPolyPlane(QString name, QObject *parent)
{
    qDebug() << "YPolyPlane(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);

    _w = 1.0;
    _h = 1.0;
    _sw = 1;
    _sh = 1;

}

YPolyPlane::~YPolyPlane()
{
    qDebug() << "~YPolyPlane()";
}

void
YPolyPlane::dumpObjectData(int intend)
{
    QByteArray buf;
    buf.fill(' ',(intend+4));
    if ((_w != 1.0) || (_h != 1.0))
    qDebug("%s%s: %6.3f, %6.3f", static_cast<const char*>(buf),
           "width, heigh", _w, _h);
    if ((_sw != 1) || (_sh != 1))
    qDebug("%s%s: %d, %d", static_cast<const char*>(buf),
           "subdivisions w, h", _sw, _sh);
}
