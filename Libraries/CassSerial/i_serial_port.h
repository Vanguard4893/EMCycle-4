#ifndef I_SERIAL_PORT_H
#define I_SERIAL_PORT_H


namespace Cass {
    namespace SerialIO {
        class I_Serial_Port
        {
        public:
            virtual ~I_Serial_Port();
            virtual bool OpenPort() = 0;
            virtual void ClosePort() = 0;
        };
    }
}

#endif // I_SERIAL_PORT_H
