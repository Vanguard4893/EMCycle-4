#ifndef CASSSERIALWAIT_H
#define CASSSERIALWAIT_H

#include <QEventLoop>
#include <cassserial.h>

namespace Cass {
    namespace SerialIO {
        class CassSerialWait : Cass::SerialIO::CassSerial
        {
        public:
            CassSerialWait(QObject *parent, QString portName);
            void SendMessage(QByteArray dataTx);
        private:
            QObject *parent;
            QEventLoop eventLoop;
        };
    }
}

#endif // CASSSERIALWAIT_H
