#include "ynode.h"
#include <QDebug>

static void dumpRecursive(int level, const QObject *object)
{
    if (object) {
        QByteArray buf;
        buf.fill(' ', level / 2 * 8);
        if (level % 2)
            buf += "    ";
        QString name = object->objectName();
        QString flags = QLatin1String("");
        qDebug("%s%s::%s %s", (const char*)buf, object->metaObject()->className(), name.toLocal8Bit().data(),
               flags.toLatin1().data());
        ((YNode*)object)->dumpObjectData(buf.length());
        QObjectList children = object->children();
        if (!children.isEmpty()) {
            for (int i = 0; i < children.size(); ++i)
                dumpRecursive(level+1, children.at(i));
        }
    }

}

YNode::YNode(QString name, QObject *parent) : QObject(parent)
{
    setObjectName(name);
    setParent(parent);
}

void
YNode::dumpObjectTreeData() const
{
    dumpRecursive(0, this);
}

void
YNode::dumpObjectData(int intend)
{
    QByteArray buf;
    buf.fill(' ',(intend+4));
    qDebug("%s%s",static_cast<const char*>(buf), "empty");
}
