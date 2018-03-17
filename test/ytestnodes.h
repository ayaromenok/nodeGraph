#ifndef YTESTNODES_H
#define YTESTNODES_H

#include <QObject>

class YTestNodes : public QObject
{
    Q_OBJECT
public:
    explicit YTestNodes(QObject *parent = nullptr);
    ~YTestNodes();

signals:

public slots:
    bool run();

private:
    bool        _addAllNodes();
    QVector<QObject*>* _ndl; //NodeList
};

#endif // YTESTNODES_H
