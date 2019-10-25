#include "lxidiscovery.h"

//Must null pointer.
namespace Cass {
    namespace LXI {
LxiDiscovery* LxiDiscovery::theLxi = nullptr;

        LxiDiscovery::LxiDiscovery()
        {
            allDevices = QHash<QString, InstrumentAndIPAddress>();
        }

        LxiDiscovery::~LxiDiscovery()
        {
        }

        LxiDiscovery* LxiDiscovery::getInstance()
        {
            if (theLxi == nullptr) {
                theLxi = new LxiDiscovery();
            }

            return theLxi;
        }

        //Properties
        QHash<QString, InstrumentAndIPAddress> LxiDiscovery::getAllDevices() const {
            return  allDevices;
        }

        //Methods
        void LxiDiscovery::addNewDevice(InstrumentAndIPAddress newDevice) {
            allDevices.insert(newDevice.GetKey(), newDevice);
        }

        void LxiDiscovery::clearAllDevices() {
            allDevices.clear();
        }

        InstrumentAndIPAddress *LxiDiscovery::FindOnlyOneMakeAndModel(const QString makeAndModelKey) {
            InstrumentAndIPAddress *returnValue = nullptr;

            //Matches MUST be declared at this class level othewise its memory gets corrupted.
            //QList<InstrumentAndIPAddress> matches;
            matches.clear();
            if (allDevices.count() != 0) {
                matches = allDevices.values(makeAndModelKey);
                if (matches.count() == 1) {
                    returnValue = &(matches[0]);
                }
            }

            return returnValue;
        }
    }
}
