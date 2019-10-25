#include "nardaep600serial.h"

namespace Cass {
    namespace SerialIO {
        NardaEP600Serial::NardaEP600Serial(QObject *parent, QString portName) : Cass::SerialIO::CassSerial (parent, portName, QSerialPort::Baud9600)
        {
            serialParent = parent;
        }

        QString QueryVersion() {

            return "k";
        }


        //http://www.howtobuildsoftware.com/index.php/how-do/bWi2/c-qt-qt-waiting-for-a-signal-with-timeout-management
    }
}
