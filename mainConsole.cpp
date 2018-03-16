#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "nodeGraph/Console";
#ifdef GIT_VERSION
    qDebug() << GIT_VERSION;
#endif //GIT_VERSION

    return a.exec();
}
