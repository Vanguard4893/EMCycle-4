#include "instrumentandipaddress.h"

const int InstrumentDataItems = 4;
const QChar Splitter = ',';
const QString EmptyString = QStringLiteral("");

namespace Cass {
    namespace LXI {
        InstrumentAndIPAddress::InstrumentAndIPAddress()
        {
            IPAddress = EmptyString;
            Maker = EmptyString;
            Model = EmptyString;
            SerialNumber = EmptyString;
            SoftwareVersion = EmptyString;
        }

        InstrumentAndIPAddress::InstrumentAndIPAddress(const QString instrumentIPAddress, const QString allInstrumentDetails)
        {
            IPAddress = instrumentIPAddress;

            Maker = EmptyString;
            Model = EmptyString;
            SerialNumber = EmptyString;
            SoftwareVersion = EmptyString;

            QStringList allParts = allInstrumentDetails.split(Splitter);
            if (allParts.count() == InstrumentDataItems) {
                //U Case
                Maker = allParts[0].toUpper();
                Model = allParts[1].toUpper();
                SerialNumber = allParts[2].toUpper();
                SoftwareVersion = allParts[3].toUpper();
            }
        }

        InstrumentAndIPAddress::InstrumentAndIPAddress(const QString maker, const QString model, const QString IPAddressUsed) {
            IPAddress = IPAddressUsed;
            Maker = maker;
            Model = model;
            SerialNumber = EmptyString;
            SoftwareVersion = EmptyString;
        }

        //Properties
        QString InstrumentAndIPAddress::GetIPAddress() const {
            return IPAddress;
        }

        QString InstrumentAndIPAddress::GetMaker() const {
            return Maker;
        }

        QString InstrumentAndIPAddress::GetModel() const {
            return Model;
        }

        QString InstrumentAndIPAddress::GetSerialNumber() const {
            return  SerialNumber;
        }

        QString InstrumentAndIPAddress::GetSoftwareVersion() const {
            return SoftwareVersion;
        }

        QString InstrumentAndIPAddress::GetKey() const {
            return  Maker + Model;
        }

        //Methods
        uint qHash(const InstrumentAndIPAddress &key) {
            return qHash(key.GetKey());
        }

        //Operators
        bool InstrumentAndIPAddress::operator==(const InstrumentAndIPAddress& other) {
          return (Maker == other.Maker) && (Model == other.Model);
        }

        bool InstrumentAndIPAddress::operator!=(const InstrumentAndIPAddress& other) {
          return !(*this == other);
        }
    }
}
