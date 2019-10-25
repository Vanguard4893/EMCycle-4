#ifndef LXIDISCOVERY_H
#define LXIDISCOVERY_H

#include <qobject.h>
#include <instrumentandipaddress.h>

//Singleton, for storage of available instruments.
namespace Cass {
    namespace LXI {
        class LxiDiscovery
        {
        public:
            static LxiDiscovery* getInstance();
            QHash<QString, InstrumentAndIPAddress> getAllDevices() const;
            void addNewDevice(InstrumentAndIPAddress newDevice);
            void clearAllDevices();
            InstrumentAndIPAddress *FindOnlyOneMakeAndModel(const QString makeAndModelKey);

        private:
            LxiDiscovery();
            ~LxiDiscovery();
            static LxiDiscovery *theLxi;
            QHash<QString, InstrumentAndIPAddress> allDevices;
            //Class level.
            QList<InstrumentAndIPAddress> matches;
        };
    }
}

#endif // LXIDISCOVERY_H
