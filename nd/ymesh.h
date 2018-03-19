#ifndef YMESH_H
#define YMESH_H

#include "ynode.h"
#include <QObject>

class YMesh : public YNode
{
    Q_OBJECT
public:
    YMesh(QString name = "YMesh", QObject *parent = nullptr);
    ~YMesh();
};

#endif // YMESH_H
