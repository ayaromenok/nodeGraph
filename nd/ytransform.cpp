#include "ytransform.h"
#include <QDebug>

YTransform::YTransform(QString name, QObject *parent)
{
    qDebug() << "YTransform(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);

    _translate  = double3{0.0, 0.0, 0.0};
    _rotate     = double3{0.0, 0.0, 0.0};
    _scale      = double3{1.0, 1.0, 1.0};
    _visibility = true;

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
    qDebug("%s%s: %s", static_cast<const char*>(buf),
           "visibility",(_visibility?"true":"false"));
    if ((_translate.x != 0.0) && (_translate.y != 0.0) && (_translate.z != 0.0))
    qDebug("%s%s: %6.3f, %6.3f, %6.3f", static_cast<const char*>(buf),
           "translate", _translate.x, _translate.y, _translate.z);
    if ((_rotate.x != 0.0) && (_rotate.y != 0.0) && (_rotate.z != 0.0))
    qDebug("%s%s: %6.3f, %6.3f, %6.3f", static_cast<const char*>(buf),
           "rotate   ", _rotate.x, _rotate.y, _rotate.z);
    if ((_scale.x != 1.0) && (_scale.y != 1.0) && (_scale.z != 1.0))
    qDebug("%s%s: %6.3f, %6.3f, %6.3f", static_cast<const char*>(buf),
           "scale    ", _scale.x, _scale.y, _scale.z);
}
