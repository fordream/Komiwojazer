#include "komipluginmanager.h"
#include <QDir>
#include <QString>
#include <QPluginLoader>

KomiPluginManager::KomiPluginManager()
    : m_numberOfPlugins(0)
{

}

KomiPluginManager::~KomiPluginManager()
{

}

//! [3]
bool KomiPluginManager::loadPlugin(QMap<int, QString> &_plugIndexNameMap)
{
    QDir pluginsDir(QDir::currentPath());
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
            KomiwojazerPluginInterface * komiwojazerPluginInterface = qobject_cast<KomiwojazerPluginInterface *>(plugin);
            if (komiwojazerPluginInterface)
            {
                m_pluginsMap.insert(m_numberOfPlugins, komiwojazerPluginInterface);
                _plugIndexNameMap.insert(m_numberOfPlugins, komiwojazerPluginInterface->getName());
                ++m_numberOfPlugins;
            }
        }
    }

    return true;
}

KomiwojazerPluginInterface* KomiPluginManager::getPluginByIndex(int _index) const
{
    return m_pluginsMap[_index];
}
