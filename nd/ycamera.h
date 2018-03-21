#ifndef YCAMERA_H
#define YCAMERA_H

#include "ynode.h"
#include "core/ybasictypes.h"
#include <QObject>

class YCamera : public YNode
{
    Q_OBJECT
    Q_PROPERTY(bool o READ o WRITE setO NOTIFY oChanged) //orthographic proj
            //cap - Camera APerture (Horizontal and Vertical)
    Q_PROPERTY(double capH READ capH WRITE setCapH NOTIFY capHChanged)
    Q_PROPERTY(double capV READ capV WRITE setCapV NOTIFY capVChanged)
    Q_PROPERTY(double2 cap READ cap WRITE setCap NOTIFY capChanged)
public:
    YCamera(QString name = "YCamera", QObject *parent = nullptr);
    ~YCamera();

public slots:
    bool       o(){return _ortho;}
    void    setO(bool o){_ortho = o; emit oChanged(o);}

    double  capH(){return _cap.x;}
    void    setCapH(double capH){_cap.x = capH; emit capHChanged(capH);}
    double  capV(){return _cap.y;}
    void    setCapV(double capV){_cap.y = capV; emit capVChanged(capV);}
    double2 cap(){return _cap;}
    void    setCap(double2 cap){_cap = cap; emit capChanged(cap);}

    void    dumpObjectData(int intend);
signals:
    void    oChanged(bool);
    void    capHChanged(double);
    void    capVChanged(double);
    void    capChanged(double2);

private:
    bool    _ortho;
    double2 _cap;
};

#endif // YCAMERA_H
