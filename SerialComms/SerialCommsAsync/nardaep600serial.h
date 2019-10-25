#ifndef NARDAEP600SERIAL_H
#define NARDAEP600SERIAL_H

#include <cassserial.h>

namespace Cass {
    namespace SerialIO {
        class NardaEP600Serial : public Cass::SerialIO::CassSerial
        {
        public:
            NardaEP600Serial(QObject *parent, QString portName);
            QString QueryVersion();

        private slots:
            //void handleNewSerialData(QByteArray newData, bool fromTimeOut);

            void handleNewSerialError(QSerialPort::SerialPortError newError);

        private:
            QObject *serialParent;

        };
    }
}

#endif // NARDAEP600SERIAL_H
