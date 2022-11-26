
#include <glib.h>
#include <NetworkManager.h>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    NMClient *client;

        client = nm_client_new (NULL, NULL);
        if (client)
            g_print ("NetworkManager version: %s\n", nm_client_get_version (client));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
