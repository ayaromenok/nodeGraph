#ifndef YSCRIPT_H
#define YSCRIPT_H

#include "ynode.h"
#include <QObject>

class YScript : public YNode
{
    Q_OBJECT
    Q_PROPERTY(int st READ st WRITE setSt NOTIFY stChanged)
    Q_PROPERTY(QString b READ b WRITE setB NOTIFY bChanged)
public:
    YScript(QString name = "YScript", QObject *parent = nullptr);
    ~YScript();
public slots:
    int     st(){return _scriptType;}
    void setSt(int st){_scriptType = st; emit stChanged(st);}

    QString b(){return _body;}
    void setB(QString b){_body.clear(); _body.append(b); emit bChanged(b);}

    void dumpObjectData(int intend);
signals:
    void stChanged(int);
    void  bChanged(QString);
private:
    int         _scriptType;
    QString     _body;
};

#endif // YSCRIPT_H
