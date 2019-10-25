#ifndef SERAILASYNCHCOMMS_H
#define SERAILASYNCHCOMMS_H

#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>

namespace Cass {
    namespace SerialIO {
        class SerialAsynchComms : public QObject
        {
            Q_OBJECT
        public:
            SerialAsynchComms(QObject *parent, QString portName, QSerialPort::BaudRate speed);
            bool OpenPort();
            void ClosePort();
            void SendSerialBytes(QByteArray dataTx);
            //Properties
            QString getPortName();
            void setPortName(QString value);
            bool getHardwareHandshake();
            void setHardwareHandshake(bool value);
            unsigned short getRxMessageTimeout();
            void setRxMessageTimeout(unsigned short value);
            QSerialPort::SerialPortError getLastError();

            static QString SerialMessage(QSerialPort::SerialPortError serialCode);

        //protected:
        public:
            ~SerialAsynchComms();

        private slots:
            void handleReadyRead();
            void handleError(QSerialPort::SerialPortError error);
            void handleRxMessageTimeout();

        signals:
            void serialDataRx(QByteArray theData);
            void serialNewError(QSerialPort::SerialPortError serialPortError);
            void serialRxTimeout();

        private:
            QObject *serialParent;
            bool hardwareHandshake;
            unsigned short rxMessageTimeout;
            QString portNameToUse;
            QSerialPort::BaudRate speedToUse;
            QSerialPort *serialPortInUse;
            QTimer rxTimer;
            QByteArray readData;
            QSerialPort::SerialPortError lastError;

            void CloseSerial();
            void StartRxMessageTimer();
        };
    }
}

#endif // SERIALASYNCHCOMMS_H
