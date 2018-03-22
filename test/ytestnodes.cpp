#include "ytestnodes.h"
#include <QDebug>

#include "nd/ynodelist.h"

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
        _ndl->append(new YTransform("front", _ndl->at(0)));
        (static_cast<YTransform*> (_ndl->last()))->setTx(0.314);
        (static_cast<YTransform*> (_ndl->last()))->setTy(-3.14);
        (static_cast<YTransform*> (_ndl->last()))->setTz(31.415);
        (static_cast<YTransform*> (_ndl->last()))->setR(double3{30.0,-45.0,60.0});
        (static_cast<YTransform*> (_ndl->last()))->setS(double3{1.1,-2.2,3.3});
        (static_cast<YTransform*> (_ndl->last()))->setV(false);

        _ndl->append(new YCamera("camera", _ndl->last()));
        (static_cast<YCamera*> (_ndl->last()))->setO(false);
        (static_cast<YCamera*> (_ndl->last()))->setCap(double2{1.41732, 0.94488});

        _ndl->append(new YTransform("MeshObj0", _ndl->at(0)));
        (static_cast<YTransform*> (_ndl->last()))->setT(double3{2.98, -3.97, 4.96});
        (static_cast<YTransform*> (_ndl->last()))->setSx(0.9);
        (static_cast<YTransform*> (_ndl->last()))->setSy(-1.8);
        (static_cast<YTransform*> (_ndl->last()))->setSz(2.7);

        _ndl->append(new YMesh("Mesh0", _ndl->last()));
        _ndl->append(new YPolyCube("Cube0", _ndl->last()));
        (static_cast<YPolyCube*> (_ndl->last()))->setW(3.2);
        (static_cast<YPolyCube*> (_ndl->last()))->setH(2.2);
        (static_cast<YPolyCube*> (_ndl->last()))->setD(1.1);
        (static_cast<YPolyCube*> (_ndl->last()))->setSw(3);
        (static_cast<YPolyCube*> (_ndl->last()))->setSh(2);

        _ndl->append(new YTransform("MeshObj1", _ndl->at(0)));
        (static_cast<YTransform*> (_ndl->last()))->setRx(11.1);
        (static_cast<YTransform*> (_ndl->last()))->setRy(-22.2);
        (static_cast<YTransform*> (_ndl->last()))->setRz(33.3);

        _ndl->append(new YMesh("Mesh1", _ndl->last()));
        (static_cast<YMesh*> (_ndl->last()))->setI(" -s 8 \".vt[0:7]\"  -3 -2 1 3 -2 1 -3 2 1 3 2 1 -3 2 -1 3 2 -1 -3 -2 -1 3 -2 -1;");

        _ndl->append(new YPolyPlane("Plane0", _ndl->last()));
        (static_cast<YPolyPlane*> (_ndl->last()))->setW(3.2);
        (static_cast<YPolyPlane*> (_ndl->last()))->setH(2.2);
        (static_cast<YPolyPlane*> (_ndl->last()))->setSw(3);
        (static_cast<YPolyPlane*> (_ndl->last()))->setSh(2);

        _ndl->append(new YScript("Script0", _ndl->at(0)));
    }
    qDebug() << "added nodes" << _ndl->length();

    (static_cast<YTransform*>(_ndl->at(0)))->dumpObjectTreeData();
    //_ndl->at(0)->dumpObjectInfo();
    return true;
}
