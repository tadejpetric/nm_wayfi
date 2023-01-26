#include "nmanager.h"



QStringList get_ssid(NMClient* client) {
    QStringList list;
    const GPtrArray* devices = nm_client_get_devices(client);

    for (gsize i = 0; i < devices->len; ++i) {
        NMDevice* device = static_cast<NMDevice*>(devices->pdata[i]);
        auto x = nm_device_get_type_description(device);
        //g_print("dev %s\n", x);
        if (!strcmp(x, "wifi")) {
            auto y = NM_DEVICE_WIFI(device);
            auto active_ap = nm_device_wifi_get_access_points(y);
            for (gsize j = 0; j < active_ap->len; ++j) {
                auto current = static_cast<NMAccessPoint*>(active_ap->pdata[j]);
                //g_print("device %s\n", nm_access_point_get_bssid(current));
                auto gbytedev = nm_access_point_get_ssid(current);
                auto sz = g_bytes_get_size(gbytedev);
                g_print("%lu\n", sz);
                auto ssid = QString(QByteArray(static_cast<const char*>(g_bytes_get_data(gbytedev, &sz)), sz));

                list << ssid;
                //g_print("ssid: %s\n", ssid);
            }

        }
    }
    return list;
}
