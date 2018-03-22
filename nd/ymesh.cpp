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
    delete _vt;
    delete _n;
    delete _ed;
    delete _fc;
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
    sList.last().chop(1);
    qDebug() << sList;
    int listLength = sList.length();

    int     arrRecomendedLength = 0;
    QString arrType;

    for (int i=0; i<listLength; i++){
        if (sList.at(i).contains("-s")){
            i++;
            arrRecomendedLength = sList.at(i).toInt();
        }
        if (sList.at(i).contains("-type")){
            i++;
            //need to parse it too: float3, polyFaces, etc
            arrType.append(sList.at(i));
        }
        if (sList.at(i).contains(".vt")){
            int2 arrLength = _getArrayLength(sList.at(i));
            qDebug() << "vt array:" << arrLength.x << arrLength.y
                     << ", recomended length" << arrRecomendedLength;
            _vtLength = arrLength.y-arrLength.x;
            i+=2; //it's a additional space in Maya ASCII;
            for (int j=arrLength.x; j<=arrLength.y;j++){
                //getInt2
                //getInt3
                //getInt4
                _vt->append(_getFloat3(&sList, i));
                i+=3;
            }
        }
    }

    return true;
}

float3
YMesh::_getFloat3(QStringList* list, int ii)
{
    float3 vt;
    vt.x = list->at(ii).toFloat();
    ii++;
    vt.y = list->at(ii).toFloat();
    ii++;
    vt.z = list->at(ii).toFloat();
    ii++;
    return vt;
}

int2
YMesh::_getArrayLength(QString value)
{
    int braceOpen = value.indexOf("[");
    int separator = value.indexOf(":");
    int braceClose = value.indexOf("]");
    int2 arr;
    arr.x =  value.mid(braceOpen+1, (separator-braceOpen-1)).toInt();
    arr.y = value.mid(separator+1, (braceClose -separator-1)).toInt();
    qDebug() << value.mid(braceOpen, (separator-braceOpen))
             << value.mid(separator, (braceClose -separator))
            << arr.x << arr.y;

    return arr;
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
