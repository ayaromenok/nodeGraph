#include "ytestnodes.h"
#include <QDebug>

#include "nd/ynodeList.h"

YTestNodes::YTestNodes(QObject *parent) : QObject(parent)
{
    qDebug() << "TestNodes constructor";
    _ndl = new QVector<QObject*>;

}

YTestNodes::~YTestNodes()
{
    qDebug() << "TestNodes destructor";
    _ndl->clear();
    delete _ndl;
}

bool
YTestNodes::run()
{
    qDebug() << "TestNodes run";
    _addAllNodes();
    return true;
}

bool
YTestNodes::_addAllNodes()
{
    qDebug() << "TestNodes _addAllNodes";
    if (_ndl)
    {
        _ndl->append(new YNode("root"));//at 0 is alwyas root node
        _ndl->append(new YCamera("camera", _ndl->at(0)));
        _ndl->append(new YNode("child of a camera", _ndl->at(1)));
        _ndl->append(new YNode("child2", _ndl->at(0)));
    }
    qDebug() << "added nodes" << _ndl->length();

    _ndl->at(0)->dumpObjectTree();
    //_ndl->at(0)->dumpObjectInfo();
    return true;
}
