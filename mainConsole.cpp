#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include "test/ytestnodes.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "nodeGraph/Console";

    app.setOrganizationName("Andrey Yaromenok");
    app.setOrganizationDomain("yaromenok.info");
    app.setApplicationName(QFileInfo(app.applicationFilePath()).baseName());

    YTestNodes *ytn = new YTestNodes;
    ytn->run();
    delete ytn;

    return 0;
}
