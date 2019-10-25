#ifndef W_G_EMR300_H
#define W_G_EMR300_H

#include <cassserial.h>
#include <i_serial_probe.h>

namespace Cass {
    namespace SerialIO {
        class W_G_Emr300 : public QObject, public I_Serial_Probe
        {
            Q_OBJECT
        public:
            W_G_Emr300(QObject *parent, QString portName);
            bool OpenPort();
            void ClosePort();
            bool MeasureSingleValue(qreal &fieldStrength);
            //Properties
            QString getLastCommand() const;
            QByteArray getLastReply() const;
            QString getLastErrorText() const;
            bool getBusy() const;

        public:
            ~W_G_Emr300();

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
            bool EndsWithString(const QString &comparisonEnding, QByteArray &theData);
            void ResetForNewMessage();
            bool CheckEndCharacters(QString endExpected, QByteArray theData, QByteArray &modifiedData);
            bool busy;
        };
    }
}

#endif // W_G_EMR300_H
