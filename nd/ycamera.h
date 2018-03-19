#ifndef YCAMERA_H
#define YCAMERA_H

#include "ynode.h"
#include <QObject>

class YCamera : public YNode
{
    Q_OBJECT
public:
    YCamera(QString name = "YCamera", QObject *parent = nullptr);
    ~YCamera();
};

#endif // YCAMERA_H
