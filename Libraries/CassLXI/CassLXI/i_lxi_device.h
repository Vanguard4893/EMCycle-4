#ifndef I_LXI_DEVICE_H
#define I_LXI_DEVICE_H

#include <qobject.h>

namespace Cass {
    namespace LXI {
        class I_LXI_Device
        {
        public:
            enum class LXIErrors { NoError = 0, InitilisationFail, DiscoverDevicesFail, FindDevicesFail,
                                   DeviceNotFound, AlreadyConnected, ConnectionFailed, NoDeviceConnected,
                                   DisconnectFailed, SendLXIFailed, NoReplyToLXISend, SCPISendFail
                                 };
            virtual ~I_LXI_Device();
            virtual bool SearchForDevices() = 0;
            virtual QString getLastCommand() const = 0;
            virtual QString getLastReply() const = 0;
            virtual LXIErrors GetLastError() const = 0;
            static QString GetLastErrorText(LXIErrors theError);
        };
    }
}

#endif // I_LXI_DEVICE_H
