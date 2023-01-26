
#include <glib.h>
#include <NetworkManager.h>
#include "mainwindow.h"
#include <QApplication>
#include <unistd.h>
#include <QStringList>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
