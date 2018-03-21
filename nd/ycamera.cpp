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

void
YCamera::dumpObjectData(int intend)
{
    QByteArray buf;
    buf.fill(' ',(intend+4));

    qDebug("%s%s: %s", static_cast<const char*>(buf),
           "ortho",(_ortho?"true":"false"));
}
