#ifndef YMESH_H
#define YMESH_H

#include "ynode.h"
#include "core/ybasictypes.h"
#include <QObject>

class YMesh : public YNode
{
    Q_OBJECT
    Q_PROPERTY(QString i READ i WRITE setI NOTIFY iChanged)
public:
    YMesh(QString name = "YMesh", QObject *parent = nullptr);
    ~YMesh();
public slots:
    QString i(){return _sLastIn;}
    void setI(QString i);

    void dumpObjectData(int intend);
signals:
    void iChanged(QString);
private:
    bool                _parseInput();
    float3              _getFloat3(QStringList* list,int i);
    int2                 _getArrayLength(QString value);
    QString             _sLastIn;
    QVector<float3>*    _vt;
    int                 _vtLength;
    QVector<float3>*    _n;//normals(faces)
    int                 _nLength;
    QVector<int2>*       _ed;//edges,
    int                 _edLength;
    QVector<int>*       _fc;//(faces, can be 3(tri) or 4 for now)
    int                 _faceLength;
    int                 _fcLength;
};

#endif // YMESH_H
