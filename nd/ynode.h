#ifndef YNODE_H
#define YNODE_H

#include <QObject>

class YNode : public QObject
{
    Q_OBJECT
public:
    YNode(QString name = "YNode", QObject *parent = nullptr);
    void dumpObjectTreeData() const;
signals:

public slots:
    virtual void dumpObjectData(int intend);
};

#endif // YNODE_H
