#ifndef YPOLYPLANE_H
#define YPOLYPLANE_H

#include "ynode.h"
#include <QObject>

class YPolyPlane : public YNode
{
    Q_OBJECT
public:
    YPolyPlane(QString name = "YPolyPlane", QObject *parent = nullptr);
    ~YPolyPlane();
};

#endif // YPOLYPLANE_H
