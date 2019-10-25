#ifndef NARDA_EP600_H
#define NARDA_EP600_H

#include <cassserial.h>
#include <i_serial_probe.h>

namespace Cass {
    namespace SerialIO {
        //QObject MUST be FIRST!!
        class Narda_EP600 : public QObject, public I_Serial_Probe
        {
            Q_OBJECT
        public:
            Narda_EP600(QObject *parent, QString portName);
            bool OpenPort();
            void ClosePort();
            bool QueryVersion(QString &version);
            bool QueryTakeReading(qreal &fieldStrength);
            bool QueryCalibrationDate(QString &calDate);
            bool QuerySerialNumber(QString &serialNumber);
            bool QueryBatteryVoltage(qreal &batteyVoltage);
            bool QueryTemperatureC(qreal &temperatureInC);
            bool QueryThreeAxesFields(qreal &fieldX, qreal &fieldY, qreal &FieldZ);
            bool SetProbePowerOffTimeIns(unsigned short timeIns);
            bool SetProbePowerOff();
            //Properties
            QString getLastCommand() const;
            QByteArray getLastReply() const;
            QString getLastErrorText() const;
            bool getBusy() const;

        public:
            ~Narda_EP600();

        private slots:
            void handleNewSerialError(QSerialPort::SerialPortError newError);

        signals:
            void probeNewError(QSerialPort::SerialPortError serialPortError);

        private:
            QObject *serialParent;
            Cass::SerialIO::CassSerial *serPort;
            QString lastCommand;
            QByteArray lastReply;
            QString lastErrorText;
            bool hasTimedOut;
            bool StartsWithChar(const QString &comparisonChar, QByteArray &theData);
            void ResetForNewMessage();
            bool CheckReplyCharacter(QString replyExpected, QByteArray theData, QByteArray &modifiedData);
            bool busy;
        };
    }
}

#endif // NARDA_EP600_H
