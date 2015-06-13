#ifndef KOMIPLUGINMANAGER_H
#define KOMIPLUGINMANAGER_H

#include <QObject>
#include <QMap>
#include "komiwojazerplugininterface.h"

class KomiPluginManager
{
public:
    KomiPluginManager();
    ~KomiPluginManager();
    bool loadPlugin(QMap<int, QString> &_plugIndexNameMap);
    KomiwojazerPluginInterface* getPluginByIndex(int _index) const;
private:
    int m_numberOfPlugins;
    QMap<int, KomiwojazerPluginInterface*> m_pluginsMap;
};

#endif // KOMIPLUGINMANAGER_H
