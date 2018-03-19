#ifndef YNODE_H
#define YNODE_H

#include <QObject>

class YNode : public QObject
{
    Q_OBJECT
public:
    YNode(QString name = "YNode", QObject *parent = nullptr);

signals:

public slots:
};

#endif // YNODE_H
