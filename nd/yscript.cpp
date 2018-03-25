#include "yscript.h"
#include <QDebug>

YScript::YScript(QString name, QObject *parent)
{
    qDebug() << "YScript(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
    _scriptType = 0; //execute on demand
//    0 	Execute on demand.
//    1 	Execute on file load or on node deletion.
//    2 	Execute on file load or on node deletion when not in batch mode.
//    3 	Internal
//    4 	Execute on software render
//    5 	Execute on software frame render
//    6 	Execute on scene configuration
//    7 	Execute on time changed
}

YScript::~YScript()
{
    qDebug() << "~YScript()";
}

void
YScript::dumpObjectData(int intend)
{
    QByteArray buf;
    buf.fill(' ',(intend+4));

    if (_scriptType != 0)
        qDebug("%s%s:%d", static_cast<const char*>(buf),
               "script execution", _scriptType);
    if (_body.length() > 0)
    qDebug("%s%s", static_cast<const char*>(buf),
           _body.toLatin1().data());
}
