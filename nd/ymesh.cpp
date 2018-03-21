#include "ymesh.h"
#include <QDebug>

YMesh::YMesh(QString name, QObject *parent)
{
    qDebug() << "YMesh(" << name << parent->objectName() << ")";
    setObjectName(name);
    setParent(parent);
    _vt = new QVector<float3>;
    _vtLength = 0;
    _n = new QVector<float3>;
    _nLength = 0;
    _ed = new QVector<int>;
    _edLength = 0;
    _fc = new QVector<int>;
    _faceLength = 4;    //default
    _fcLength = 0;;
}

YMesh::~YMesh()
{
    qDebug() << "~YMesh()";
    delete[] _vt;
    delete [] _n;
    delete [] _ed;
    delete [] _fc;
}

void
YMesh::setI(QString i)
{
    _sLastIn.clear();
    _sLastIn.append(i);
    _parseInput();
    emit iChanged(i);
}

bool
YMesh::_parseInput()
{
    //cube 6x4x2 triangulated
//    setAttr -s 8 ".vt[0:7]"  -3 -2 1 3 -2 1 -3 2 1 3 2 1 -3 2 -1 3 2 -1
//                     -3 -2 -1 3 -2 -1;
    QStringList sList(_sLastIn.split(' '));
    qDebug() << sList;
    int listLength = sList.length();

    int     arrLength = 0;
    QString arrType;

    for (int i=0; i<listLength; i++){
        if (sList.at(i).contains("-s")){
            i++;
            arrLength = sList.at(i).toInt();
        }
        if (sList.at(i).contains("-type")){
            i++;
            //need to parse it too: float3, polyFaces, etc
            arrType.append(sList.at(i));
        }
        if (sList.at(i).contains(".vt")){
            //need to parse too.
            i+=2; //it's a additional space in Maya ASCII;
            for (int j=0; j<_vtLength;j++){
                //getFloat3
                //getInt2
                //getInt3
                //getInt4
                float3 vt;
                vt.x = sList.at(i).toFloat();
                i++;
                vt.y = sList.at(i).toFloat();
                i++;
                vt.z = sList.at(i).toFloat();
                i++;
                _vt->append(vt);
            }
        }
    }

    return true;
}
void
YMesh::dumpObjectData(int intend)
{
    QByteArray buf;
    buf.fill(' ',(intend+4));
    int lengthV = _vt->length();
    if (lengthV > 0){
        for (int i=0; i<lengthV; i++)
            qDebug("%s%s: %6.3f, %6.3f, %6.3f", static_cast<const char*>(buf),
            "x, y, z", _vt->at(i).x, _vt->at(i).y, _vt->at(i).z );
    }
}
