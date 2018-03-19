#ifndef YTRANSFORM_H
#define YTRANSFORM_H

#include "ynode.h"
#include <QObject>

class YTransform : public YNode
{
    Q_OBJECT
public:
    YTransform(QString name = "YTransform", QObject *parent = nullptr);
    ~YTransform();
};

#endif // YTRANSFORM_H
