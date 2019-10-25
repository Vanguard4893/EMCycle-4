#ifndef CONTROLLERSTAT_H
#define CONTROLLERSTAT_H

#include <QObject>

namespace Cass {
    namespace SerialIO {
        class ControllerSTAT : public QObject
        {
            Q_OBJECT
        public:
            explicit ControllerSTAT(QObject *parent = nullptr);
            static const int Hex = 16;
            static const quint8 NumberOfFields = 19;

            //Properties
            quint8 GetSelectInputStatus();
            bool GetDI4();
            bool GetDI3();
            bool GetDI2();
            bool GetDI1();
            bool GetAnIP4Enabled();
            bool GetAnIP3Enabled();
            bool GetAnIP2Enabled();
            bool GetAnIP1Enabled();
            bool GetAnIP0Enabled();
            quint8 GetInputScanRate();
            quint16 GetAnIP0();
            quint16 GetAnIP1();
            quint16 GetAnIP2();
            quint16 GetAnIP3();
            quint16 GetAnIP4();
            bool GetAnOP1Active();
            bool GetAnOP2Active();
            bool GetRelayOP1Active();
            bool GetRelayOP2Active();
            bool GetOcOP1Active();
            bool GetOcOP2Active();
            quint8 GetOutputSweepTime();
            quint8 GetErrorCode();
            quint16 GetChecksum();

            void Clear();
            bool Populate(QByteArray STAT);

        private:
            //Fields
            quint8 selectInputStatus;
            bool dI4;
            bool dI3;
            bool dI2;
            bool dI1;
            bool anIP4Enabled;
            bool anIP3Enabled;
            bool anIP2Enabled;
            bool anIP1Enabled;
            bool anIP0Enabled;
            quint8 inputScanRate;
            quint16 anIP0;
            quint16 anIP1;
            quint16 anIP2;
            quint16 anIP3;
            quint16 anIP4;
            bool anOP1Active;
            bool anOP2Active;
            bool relayOP1Active;
            bool relayOP2Active;
            bool ocOP1Active;
            bool ocOP2Active;
            quint8 outputSweepTime;
            quint8 errorCode;
            quint16 checksum;

            //Variables
            QObject *serialParent;
            QList<QByteArray> inParts;
            bool convertOK;

            //Methods
            bool IsBitSet(quint8 b, quint8 pos);
            quint16 Bits16FromBigEndian(QList<QByteArray> &inParts, int &index, bool &BitsConverted);
            quint8 Bits8FromBigEndian(QList<QByteArray> &inParts, int &index, bool &BitsConverted);

        signals:

        public slots:
        };
    }
}

#endif // CONTROLLERSTAT_H
