#ifndef NMANAGER_H
#define NMANAGER_H

#include <glib.h>
#include <NetworkManager.h>
#include <QStringList>
#include <QString>
#include <QByteArray>

NMClient* make_client();

QStringList get_ssid(NMClient* client);
#endif // NMANAGER_H
