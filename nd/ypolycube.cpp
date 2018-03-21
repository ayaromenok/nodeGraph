#include "ypolycube.h"
#include <QDebug>

YPolyCube::YPolyCube(QString name, QObject *parent)
{
    qDebug() << "YPolyCube(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
    _w = 1.0;
    _h = 1.0;
    _d = 1.0;
    _sw = 1;
    _sh = 1;
    _sd = 1;
}

YPolyCube::~YPolyCube()
{
    qDebug() << "~YPolyCube()";
}

void
YPolyCube::dumpObjectData(int intend)
{
    QByteArray buf;
    buf.fill(' ',(intend+4));
    if ((_w != 1.0) || (_h != 1.0) || (_d != 1.0))
    qDebug("%s%s: %6.3f, %6.3f, %6.3f", static_cast<const char*>(buf),
           "width, heigh, depth", _w, _h, _d);
    if ((_sw != 1) || (_sh != 1) || (_sd != 1))
    qDebug("%s%s: %d, %d, %d", static_cast<const char*>(buf),
           "subdivisions w, h, d", _sw, _sh, _sd);
}
