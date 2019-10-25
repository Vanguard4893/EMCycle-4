#include "cassserialwait.h"

namespace Cass {
    namespace SerialIO {
        CassSerialWait::CassSerialWait(QObject *parent, QString portName) : Cass::SerialIO::CassSerial (parent, portName, QSerialPort::Baud9600)
        {
            this->parent = parent;
            //connect ()
        }

        //Public
        void CassSerialWait::SendMessage(QByteArray dataTx)
        {
            if (serialPortInUse != nullptr) {
                if (serialPortInUse->isOpen()) {
//                    readData.clear();
//                    StartRxMessageTimer();
//                    serialPortInUse->write(dataTx);
                }
            }
        }
    }
}
