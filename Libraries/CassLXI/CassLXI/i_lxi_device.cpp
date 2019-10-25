#include "i_lxi_device.h"

namespace Cass {
    namespace LXI {
        //MUST implement the empty destructor
        I_LXI_Device::~I_LXI_Device()
        {

        }

        //Public
        QString I_LXI_Device::GetLastErrorText(LXIErrors theError) {
            QString returnValue = QStringLiteral("");
            switch (theError) {
            case LXIErrors::NoError:
                returnValue = QStringLiteral("NoError");
                break;
            case LXIErrors::InitilisationFail:
                returnValue = QStringLiteral("InitilisationFail");
                break;
            case LXIErrors::DiscoverDevicesFail:
                returnValue = QStringLiteral("DiscoverDevicesFail");
                break;
            case LXIErrors::FindDevicesFail:
                returnValue = QStringLiteral("FindDevicesFail");
                break;
            case LXIErrors::DeviceNotFound:
                returnValue = QStringLiteral("DeviceNotFound");
                break;
            case LXIErrors::AlreadyConnected:
                returnValue = QStringLiteral("AlreadyConnected");
                break;
            case LXIErrors::ConnectionFailed:
                returnValue = QStringLiteral("ConnectionFailed");
                break;
            case LXIErrors::NoDeviceConnected:
                returnValue = QStringLiteral("NoDeviceConnected");
                break;
            case LXIErrors::DisconnectFailed:
                returnValue = QStringLiteral("DisconnectFailed");
                break;
            case LXIErrors::SendLXIFailed:
                returnValue = QStringLiteral("SendLXIFailed");
                break;
            case LXIErrors::NoReplyToLXISend:
                returnValue = QStringLiteral("NoReplyToLXISend");
                break;
            case LXIErrors::SCPISendFail:
                returnValue = QStringLiteral("SCPISendFail");
                break;
            default:
                returnValue = "Uncoded LXIErrors";
            }

            return returnValue;
        }
    }
}
