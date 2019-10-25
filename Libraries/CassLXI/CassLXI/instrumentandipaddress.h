#ifndef INSTRUMENTANDIPADDRESS_H
#define INSTRUMENTANDIPADDRESS_H

#include <qobject.h>
#include <qhash.h>

namespace Cass {
    namespace LXI {
        class InstrumentAndIPAddress
        {
        public:
            InstrumentAndIPAddress();
            InstrumentAndIPAddress(const QString instrumentIPAddress, const QString allInstrumentDetails);
            InstrumentAndIPAddress(const QString maker, const QString model, const QString IPAddressUsed);
            QString GetIPAddress() const;
            QString GetMaker() const;
            QString GetModel() const;
            QString GetSerialNumber() const;
            QString GetSoftwareVersion() const;
            QString GetKey() const;
            inline bool operator==(const InstrumentAndIPAddress &other);
            inline bool operator!=(const InstrumentAndIPAddress &other);
            inline uint qHash(const InstrumentAndIPAddress &key);

        private:
            QString IPAddress;
            QString Maker;
            QString Model;
            QString SerialNumber;
            QString SoftwareVersion;

        };
    }
}

#endif // INSTRUMENTANDIPADDRESS_H
