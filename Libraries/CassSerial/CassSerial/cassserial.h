#ifndef CASSSERIAL_H
#define CASSSERIAL_H

#include <QEventLoop>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>
#include <i_serial_port.h>

namespace Cass {
    namespace SerialIO {
        class CassSerial : public QObject, public I_Serial_Port
        {
            Q_OBJECT

        public:
            // Types
            enum class TerminationType {defaultToTimeout, byteCount, terminationByte, onMessageSent};
            // Default to 9600/8/N/1.
            explicit CassSerial(QObject *parent, QString portName, QSerialPort::BaudRate speed);
            bool OpenPort();
            void ClosePort();
            bool ClearRxPort() const;
            QByteArray SendSerialBytes(QByteArray dataTx, bool &rxHasTimedOut, bool &busy, TerminationType messageTerminationMethod = TerminationType::defaultToTimeout, unsigned short terminationMatchValue = 0);
            //Properties
            QString getPortName() const;
            void setPortName(QString value);
            QSerialPort::FlowControl getFlowControl() const;
            void setFlowControl(QSerialPort::FlowControl value);
            unsigned short getRxMessageTimeout() const;
            void setRxMessageTimeout(unsigned short value);
            TerminationType getRxMessageTerminationType() const;
            unsigned short getRxMessageTerminationValue() const;
            QSerialPort::SerialPortError getLastError() const;

            static QString SerialMessage(QSerialPort::SerialPortError serialCode);

        public:
            ~CassSerial();

        private slots:
            void handleReadyRead();
            void handleError(QSerialPort::SerialPortError error);
            void handleRxMessageTimeout();
            void handleTxMessageComplete();

        signals:
            void serialDataRx(QByteArray theData, bool timeout);
            void serialNewError(QSerialPort::SerialPortError serialPortError);
            void serialRxTimeout();
            void serialRxAllDataReceivedOrAllTxSent();

        protected:
            QSerialPort *serialPortInUse;

        private:
            QEventLoop eventLoop;
            QObject *serialParent;
            QSerialPort::FlowControl flowControl;
            unsigned short rxMessageTimeout;
            TerminationType rxMessageTerminationType;
            unsigned short rxMessageTerminationValue;
            QString portNameToUse;
            QSerialPort::BaudRate speedToUse;
            QTimer rxTimer;
            QByteArray readData;
            QSerialPort::SerialPortError lastError;
            bool rxTimedOut;

            void CloseSerial();
            void UpdateRxMessageTimer();
            void StartRxMessageTimer();
        };
    }
}

#endif // CASSSERIAL_H
