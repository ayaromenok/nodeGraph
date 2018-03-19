#ifndef YSCRIPT_H
#define YSCRIPT_H

#include "ynode.h"
#include <QObject>

class YScript : public YNode
{
    Q_OBJECT
public:
    YScript(QString name = "YScript", QObject *parent = nullptr);
    ~YScript();
};

#endif // YSCRIPT_H
