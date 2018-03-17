#include <QCoreApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "nodeGraph/Console";

    app.setOrganizationName("Andrey Yaromenok");
    app.setOrganizationDomain("yaromenok.info");
    app.setApplicationName(QFileInfo(app.applicationFilePath()).baseName());

    return app.exec();
}
