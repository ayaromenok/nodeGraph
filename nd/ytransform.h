#ifndef YTRANSFORM_H
#define YTRANSFORM_H

#include "ynode.h"
#include "core/ybasictypes.h"
#include <QObject>

class YTransform : public YNode
{
    Q_OBJECT
    Q_PROPERTY(double tx READ tx WRITE setTx NOTIFY txChanged)
    Q_PROPERTY(double ty READ ty WRITE setTy NOTIFY tyChanged)
    Q_PROPERTY(double tz READ tz WRITE setTz NOTIFY tzChanged)
    Q_PROPERTY(double3 t READ t WRITE setT NOTIFY tChanged)
    Q_PROPERTY(double3 r READ r WRITE setR NOTIFY rChanged)
    Q_PROPERTY(double3 s READ s WRITE setS NOTIFY sChanged)

public:
    YTransform(QString name = "YTransform", QObject *parent = nullptr);
    ~YTransform();

public slots:
    double   tx(){return _translate.x;}
    void    setTx(double tx){_translate.x = tx; emit txChanged(tx); }

    double   ty(){return _translate.y;}
    void    setTy(double ty){_translate.y = ty; emit tyChanged(ty);}

    double   tz(){return _translate.z;}
    void    setTz(double tz){_translate.z= tz; emit tzChanged(tz);}

    double3   t(){return _translate;}
    void    setT(double3 t){_translate = t; emit tChanged(t);}

    double3   r(){return _rotate;}
    void    setR(double3 r){_rotate = r; emit tChanged(r);}

    double3   s(){return _scale;}
    void    setS(double3 s){_scale = s; emit tChanged(s);}

    void dumpObjectData(int intend);
signals:
    void txChanged(double);
    void tyChanged(double);
    void tzChanged(double);
    void tChanged(double3);
    void rChanged(double3);
    void sChanged(double3);

private:
    double3  _translate;
    double3  _rotate;
    double3  _scale;
};

#endif // YTRANSFORM_H
