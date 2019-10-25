#ifndef I_SERIAL_PROBE_H
#define I_SERIAL_PROBE_H

#include <cassserial.h>

namespace Cass {
    namespace SerialIO {
        class I_Serial_Probe : public I_Serial_Port
        {
            //Cannot declare signals here.
        public:
            virtual ~I_Serial_Probe();
            virtual QString getLastCommand() const = 0;
            virtual QByteArray getLastReply() const = 0;
            virtual QString getLastErrorText() const = 0;
            virtual bool getBusy() const = 0;

        signals:
            virtual void probeNewError(QSerialPort::SerialPortError serialPortError) = 0;
        };
    }
}

#endif // I_SERIAL_PROBE_H
