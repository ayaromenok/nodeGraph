#ifndef YCAMERA_H
#define YCAMERA_H

#include "ynode.h"
#include <QObject>

class YCamera : public YNode
{
    Q_OBJECT
    Q_PROPERTY(bool o READ o WRITE setO NOTIFY oChanged) //orthographic proj
public:
    YCamera(QString name = "YCamera", QObject *parent = nullptr);
    ~YCamera();

public slots:
    bool       o(){return _ortho;}
    void    setO(bool o){_ortho = o; emit oChanged(o);}

    void    dumpObjectData(int intend);
signals:
    void    oChanged(bool);
private:
    bool    _ortho;
};

#endif // YCAMERA_H
