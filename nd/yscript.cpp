#include "yscript.h"
#include <QDebug>

YScript::YScript(QString name, QObject *parent)
{
    qDebug() << "YScript(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
}

YScript::~YScript()
{
    qDebug() << "~YScript()";
}
