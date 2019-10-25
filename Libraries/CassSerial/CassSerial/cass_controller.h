#ifndef CASS_CONTROLLER_H
#define CASS_CONTROLLER_H

#include <QObject>
#include <i_serial_probe.h>
#include <controllerstat.h>

namespace Cass {
    namespace SerialIO {
        class Cass_Controller : public QObject, public I_Serial_Probe
        {
            Q_OBJECT
        public:
            explicit Cass_Controller(QObject *parent = nullptr, QString portName = QString());
            bool OpenPort();
            void ClosePort();
            bool QueryAllStatus(ControllerSTAT *theSTAT);
            bool SetReset();
            bool SetDigitalOutput(const quint8 theBitPattern);
            bool SetAnalogueInputON(const quint8 thePort);
            bool SetAnalogueInputOFF(const quint8 thePort);
            bool SetSelectAnalogueInputForDA(const quint8 thePort);
            bool SetAnalogueInputScanTime(const quint8 theTime);
            bool SetAnalogueOutputSweepTime(const quint8 theTime);
            bool SetBaudRate(const quint8 baudRate);
            bool SetAnalogueAcquireOn(const quint8 thePort);
            bool SetAnalogueOutputOn(const quint8 thePort);
            bool SetLoadOutputSweep(const quint8 theOutput, QByteArray theWaveform);

            //Properties
            QString getLastCommand() const;
            QByteArray getLastReply() const;
            QString getLastErrorText() const;
            bool getBusy() const;
            bool getVersion(quint8 &Major, quint8 &Minor) const;

        public:
            ~Cass_Controller();

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
            bool EndsWithChars(const QString &comparisonChars, QByteArray &theData);
            void ResetForNewMessage();
            bool CheckReplyFirstCharacterAndEnding(QString expectedReplyFirst, QString expectedReplySecond, QString expectedReplyLast, QByteArray theData, QByteArray &modifiedData);
            bool SendCommandBytesIndividually(const QString &theCommand, const bool replyExpected, QByteArray &numericPartData);
            bool SendExtraDataBytes(const QString &theDataAsASCIIPairs);
            QString As2HexDigits(const quint8 theBitPattern);
            QString InHexDigitPairs(const QByteArray theBytes);
            QString InHexDigitPairs(const quint8 theFirstByte, const QByteArray theBytes);

            bool busy;
            QByteArray returnedData;
        };
    }
}

#endif // CASS_CONTROLLER_H
