#ifndef YPOLYCUBE_H
#define YPOLYCUBE_H

#include "ynode.h"
#include <QObject>

class YPolyCube : public YNode
{
    Q_OBJECT
public:
    YPolyCube(QString name = "YPolyCube", QObject *parent = nullptr);
    ~YPolyCube();
};

#endif // YPOLYCUBE_H
