#ifndef YPOLYPLANE_H
#define YPOLYPLANE_H

#include "ynode.h"
#include "core/ybasictypes.h"
#include <QObject>

class YPolyPlane : public YNode
{
    Q_OBJECT
    Q_PROPERTY(double w READ w WRITE setW NOTIFY wChanged)
    Q_PROPERTY(double h READ h WRITE setH NOTIFY hChanged)


    Q_PROPERTY(int sw READ sw WRITE setSw NOTIFY swChanged)
    Q_PROPERTY(int sh READ sh WRITE setSh NOTIFY shChanged)

public:
    YPolyPlane(QString name = "YPolyPlane", QObject *parent = nullptr);
    ~YPolyPlane();
public slots:
    double     w(){return _w;}
    void    setW(double w){_w = w; emit wChanged(w);}
    double     h(){return _h;}
    void    setH(double h){_h = h; emit hChanged(h);}

    int     sw(){return _sw;}
    void    setSw(int sw){_sw = sw; emit swChanged(sw);}
    int     sh(){return _sh;}
    void    setSh(int sh){_sh = sh; emit shChanged(sh);}

    void dumpObjectData(int intend);
signals:
    void    wChanged(double);
    void    hChanged(double);

    void    swChanged(int);
    void    shChanged(int);

private:
    double      _w;
    double      _h;

    int         _sw;
    int         _sh;
};

#endif // YPOLYPLANE_H
