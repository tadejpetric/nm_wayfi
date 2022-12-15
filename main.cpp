
#include <glib.h>
#include <NetworkManager.h>
#include "mainwindow.h"
#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
    NMClient *client;

    client = nm_client_new (NULL, NULL);
    //  For a serious program, you should therefore avoid these problems by using g_async_initable_init_async() or nm_client_new_async() instead.

    if (client)
        g_print ("NetworkManager version: %s\n", nm_client_get_version (client));
    //  on NM_DBUS_PATH, NM_DBUS_INTERFACE to set "WirelessEnabled" property to a "(b)" value.
    //const GPtrArray* conns = nm_client_get_connections(client);
    /*
    for (gsize i = 0; i < conns->len; ++i) {
        //const gpointer x = g_ptr_array_index(conns, i);
        //g_print("Device %s\n", nm_device_get_iface(x));
        NMConnection* connection = static_cast<NMConnection*>(conns->pdata[i]);
        auto asd = nm_connection_get_setting_connection(connection);
        g_print("device %s\n", nm_setting_connection_get_id(asd));
    }*/
    const GPtrArray* devices = nm_client_get_devices(client);

    for (gsize i = 0; i < devices->len; ++i) {
        NMDevice* device = static_cast<NMDevice*>(devices->pdata[i]);
        auto x = nm_device_get_type_description(device);
        g_print("dev %s\n", x);
        if (!strcmp(x, "wifi")) {
            auto y = NM_DEVICE_WIFI(device);
            auto active_ap = nm_device_wifi_get_access_points(y);
            for (gsize j = 0; j < active_ap->len; ++j) {
                auto current = static_cast<NMAccessPoint*>(active_ap->pdata[j]);
                g_print("device %s\n", nm_access_point_get_bssid(current));
                auto gbytedev = nm_access_point_get_ssid(current);
                auto sz = g_bytes_get_size(gbytedev);
                auto ssid = static_cast<const char*>(g_bytes_get_data(gbytedev, &sz));
                g_print("ssid: %s\n", ssid);
            }

        }
    }

    g_object_unref(client);

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    return 0; //a.exec();
}
