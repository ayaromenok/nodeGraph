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

public:
    YTransform(QString name = "YTransform", QObject *parent = nullptr);
    ~YTransform();

public slots:
    double   tx(){return _pos.x;}
    void    setTx(double tx){_pos.x = tx; emit txChanged(tx); }

    double   ty(){return _pos.y;}
    void    setTy(double ty){_pos.y = ty; emit tyChanged(ty);}

    double   tz(){return _pos.z;}
    void    setTz(double tz){_pos.x= tz; emit tzChanged(tz);}

    double3   t(){return _pos;}
    void    setT(double3 t){_pos = t; emit tChanged();}


signals:
    void txChanged(double);
    void tyChanged(double);
    void tzChanged(double);
    void tChanged(double3);

private:
    double3  _pos;
};

#endif // YTRANSFORM_H
