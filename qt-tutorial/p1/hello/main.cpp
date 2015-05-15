#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString strtst = "Hello World!";

    qDebug() << strtst;

    return a.exec();
}
