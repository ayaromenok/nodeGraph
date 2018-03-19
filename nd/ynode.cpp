#include "ynode.h"

YNode::YNode(QString name, QObject *parent) : QObject(parent)
{
    setObjectName(name);
    setParent(parent);
}
