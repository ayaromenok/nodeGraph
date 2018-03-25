#ifndef YPOLYCUBE_H
#define YPOLYCUBE_H

#include "ynode.h"
#include "core/ybasictypes.h"
#include <QObject>

class YPolyCube : public YNode
{
    Q_OBJECT
    Q_PROPERTY(double w READ w WRITE setW NOTIFY wChanged)
    Q_PROPERTY(double h READ h WRITE setH NOTIFY hChanged)
    Q_PROPERTY(double d READ d WRITE setD NOTIFY dChanged)

    Q_PROPERTY(int sw READ sw WRITE setSw NOTIFY swChanged)
    Q_PROPERTY(int sh READ sh WRITE setSh NOTIFY shChanged)
    Q_PROPERTY(int sd READ sd WRITE setSd NOTIFY sdChanged)
public:
    YPolyCube(QString name = "YPolyCube", QObject *parent = nullptr);
    ~YPolyCube();
public slots:

    double     w(){return _w;}
    void    setW(double w){_w = w; emit wChanged(w);}
    double     h(){return _h;}
    void    setH(double h){_h = h; emit hChanged(h);}
    double     d(){return _d;}
    void    setD(double d){_d = d; emit dChanged(d);}

    int     sw(){return _sw;}
    void    setSw(int sw){_sw = sw; emit swChanged(sw);}
    int     sh(){return _sh;}
    void    setSh(int sh){_sh = sh; emit shChanged(sh);}
    int     sd(){return _sd;}
    void    setSd(int sd){_sd = sd; emit sdChanged(sd);}

    void dumpObjectData(int intend);
signals:
    void    wChanged(double);
    void    hChanged(double);
    void    dChanged(double);

    void    swChanged(int);
    void    shChanged(int);
    void    sdChanged(int);
private:
    double      _w;
    double      _h;
    double      _d;
    int         _sw;
    int         _sh;
    int         _sd;
};

#endif // YPOLYCUBE_H
