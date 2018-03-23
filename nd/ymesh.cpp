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
    _ed = new QVector<int2>;
    _edLength = 0;
    _fc3 = new QVector<int3>;
    _fc4 = new QVector<int4>;
    _faceLength = 4;    //default
    _fcLength = 0;;
}

YMesh::~YMesh()
{
    qDebug() << "~YMesh()";
    _vt->clear();
    delete _vt;
    _n->clear();
    delete _n;
    _ed->clear();
    delete _ed;
    _fc3->clear();
    delete _fc3;
    _fc4->clear();
    delete _fc4;
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
    //cube 6x4x2 triangulated or quad
    //    setAttr -s 8 ".vt[0:7]"  -3 -2 1 3 -2 1 -3 2 1 3 2 1 -3 2 -1 3 2 -1
    //                     -3 -2 -1 3 -2 -1;

    QStringList sList(_sLastIn.split(' '));
    sList.last().chop(1);
    qDebug() << sList;
    int listLength = sList.length();

    int     arrRecomendedLength = 0;
    int     arrRecomendedCapacity = 0;
    QString arrType;

    for (int i=0; i<listLength; i++){
        if (sList.at(i).contains("-s")){
            i++;
            arrRecomendedLength = sList.at(i).toInt();
        }
        if (sList.at(i).contains("-ch")){
            i++;
            arrRecomendedCapacity = sList.at(i).toInt();
        }
        if (sList.at(i).contains("-type")){
            i++;
            //need to parse it too: float3, polyFaces, etc
            arrType.append(sList.at(i));
        }
        if (sList.at(i).contains(".vt")){
            int2 arrLength = _getArrayLength(sList.at(i));
            qDebug() << "vertex array:" << arrLength.x << arrLength.y
                     << ", recomended length" << arrRecomendedLength;
            i+=2; //it's a additional space in Maya ASCII;
            for (int j=arrLength.x; j<=arrLength.y;j++){
                _vt->append(_getFloat3(&sList, i));
                i+=3;
            }
            _vtLength = _vt->length();
            break;
        }
        if (sList.at(i).contains(".ed")){
            int2 arrLength = _getArrayLength(sList.at(i));
            qDebug() << "edges array:" << arrLength.x << arrLength.y
                     << ", recomended length" << arrRecomendedLength;
            i+=2; //it's a additional space in Maya ASCII;
            for (int j=arrLength.x; j<=arrLength.y;j++){
                _ed->append(_getInt2(&sList, i));
                i+=3; //edge represented by 3 values: 1st, 2nd and 0. so drop zero
            }
            _edLength = _ed->length();
            break;
        }
        if (sList.at(i).contains(".n")){
            int2 arrLength = _getArrayLength(sList.at(i));
            qDebug() << "normals array:" << arrLength.x << arrLength.y
                     << ", recomended length" << arrRecomendedLength;
            i+=2; //it's a additional space in Maya ASCII;
            for (int j=arrLength.x; j<=arrLength.y;j++){
                _n->append(_getFloat3(&sList, i));
                i+=3;
            }
            _nLength = _n->length();
            break;
        }
        if (sList.at(i).contains(".fc")){
            qDebug() << "NOT IMPLEMENTED, need more evaluation";
//            int2 arrLength = _getArrayLength(sList.at(i));
//            _faceLength = arrRecomendedCapacity/arrRecomendedLength;
//            qDebug() << "faces array:" << arrLength.x << arrLength.y
//                     << ", recomended length" << arrRecomendedLength
//                     << ", recomended capacity" << arrRecomendedCapacity
//                     <<", face length" << _faceLength;

//            i+=2; //it's a additional space in Maya ASCII;
//            for (int j=arrLength.x; j<=arrLength.y;j++){
//                if (_faceLength == 3){
//                    _fc3->append(_getInt3(&sList, i));
//                    i+=3;
//                } else if (_faceLength == 4){
//                    _fc4->append(_getInt4(&sList, i));
//                    i+=4;
//                } else {
//                    qDebug() << "unsupported face length";
//                }
//            }
//            if (_faceLength == 4)
//                _fcLength = _fc4->length();
//            else if(_faceLength == 3)
//                _fcLength = _fc3->length();
//            break;
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
YMesh::_getInt2(QStringList* list, int ii)
{
    int2 value;
    value.x = list->at(ii).toInt();
    ii++;
    value.y = list->at(ii).toInt();
    ii++;
    return value;
}

int3
YMesh::_getInt3(QStringList* list, int ii)
{
    int3 value;
    value.x = list->at(ii).toInt();
    ii++;
    value.y = list->at(ii).toInt();
    ii++;
    value.z = list->at(ii).toInt();
    ii++;
    return value;
}

int4
YMesh::_getInt4(QStringList* list, int ii)
{
    int4 value;
    value.x = list->at(ii).toInt();
    ii++;
    value.y = list->at(ii).toInt();
    ii++;
    value.z = list->at(ii).toInt();
    ii++;
    value.w = list->at(ii).toInt();
    ii++;
    return value;
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

    if (_vtLength > 0){
        qDebug("%s%s:   %d", static_cast<const char*>(buf),
               "vertex  length", _vtLength );
        for (int i=0; i<_vtLength; i++)
            qDebug("%s%s:   %6.3f, %6.3f, %6.3f", static_cast<const char*>(buf),
                   "vertex x, y, z", _vt->at(i).x, _vt->at(i).y, _vt->at(i).z );
    }
    if (_nLength > 0){
        qDebug("%s%s:   %d", static_cast<const char*>(buf),
               "normal  length", _nLength );
        for (int i=0; i<_nLength; i++)
            qDebug("%s%s:   %6.3f, %6.3f, %6.3f", static_cast<const char*>(buf),
                   "normal x, y, z", _n->at(i).x, _n->at(i).y, _n->at(i).z );
    }
    if (_edLength > 0){
        qDebug("%s%s:   %d", static_cast<const char*>(buf),
               "edge    length", _edLength );
        for (int i=0; i<_edLength; i++)
            qDebug("%s%s:   %d, %d", static_cast<const char*>(buf),
                   "edge       a b", _ed->at(i).x, _ed->at(i).y );
    }
    if (_fcLength > 0){
        qDebug("%s%s:   %d", static_cast<const char*>(buf),
               "faces    length", _fcLength );
        if (_faceLength == 4) {
            for (int i=0; i<_fcLength; i++)
                qDebug("%s%s:   %d, %d, %d, %d", static_cast<const char*>(buf),
                       "face   a b c d", _fc4->at(i).x, _fc4->at(i).y,
                       _fc4->at(i).z, _fc4->at(i).w );
        } else if (_faceLength == 3) {
            for (int i=0; i<_edLength; i++)
                qDebug("%s%s:   %d, %d, %d", static_cast<const char*>(buf),
                       "face    a b c", _fc3->at(i).x, _fc3->at(i).y,
                       _fc3->at(i).z );
        }
    }
}
