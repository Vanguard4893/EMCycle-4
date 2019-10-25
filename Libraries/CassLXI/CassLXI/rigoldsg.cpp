#include "rigoldsg.h"

namespace Cass {
    namespace LXI {
        RigolDSG::RigolDSG(QObject *parent)
        {
            ethernetParent = parent;
            SetLastError_NoError();
            matchRigol = nullptr;
            connectedLXIDevice = NoLXIDevice;
            lastCommand = EmptyString;
            lastReply = EmptyString;
            //Initialise library
            if (lxi_init() == LXI_OK) {
                //Callbacks
                rigolInformation.broadcast = &RigolDSG::BroadcastCallback;
                rigolInformation.device = &RigolDSG::DeviceCallback;
                SetLastError_NoError();
            } else {
                SetLastError(LXIErrors::InitilisationFail);
            }
        }

        RigolDSG::~RigolDSG()
        {
        }

        //Properties
        QString RigolDSG::getLastCommand() const {
            return lastCommand;
        }

        QString RigolDSG::getLastReply() const {
            return lastReply;
        }

        I_LXI_Device::LXIErrors RigolDSG::GetLastError() const {
            return lastError;
        }

        //Public
        bool RigolDSG::SearchForDevices() {
            bool returnValue = false;
            SetLastError_NoError();

            //Clear list
            matchRigol = nullptr;
            LxiDiscovery::getInstance()->clearAllDevices();
            //It SEEMS, from tests, that this method does not return until all the devices have been found...
            //A nasty, but easy assumption.
            if (lxi_discover(&rigolInformation, DeviceFindTimeoutInms, DeviceType) == LXI_OK) {
                lastError = LXIErrors::DeviceNotFound;
                if ((matchRigol = LxiDiscovery::getInstance()->FindOnlyOneMakeAndModel(RIGOL_DSG.GetKey())) != nullptr) {
                    lastError = LXIErrors::NoError;
                    returnValue = true;
                } else {
                    SetLastError(LXIErrors::FindDevicesFail);
                }
            } else {
                SetLastError(LXIErrors::DiscoverDevicesFail);
            }

            return returnValue;
        }

        bool RigolDSG::SCPISendCommand(const QString *command, QString *reply)
        {
            bool returnValue = false;

            SetLastError_NoError();
            *reply = EmptyString;
            bool LXICommandOK;

            if (matchRigol != nullptr) {
                //LXI_connect();
                if (OpenConnection()) {
                    lastCommand = *command;
                    lastReply.clear();
                    LXICommandOK = LXI_send_receive(command, &lastReply, SCPISendAndReceiveTimeoutInms);
                    if (LXICommandOK == true)
                    {
                        if (lastReply.size() > 0)
                        {
                            //Trim off the '\n' or whatever.
                            *reply = lastReply.trimmed();
                        }
                        SetLastError_NoError();
                        returnValue = true;
                    } else {
                        SetLastError(LXIErrors::SCPISendFail);
                    }
                    //LXI_disconnect();
                    CloseConnection();
                }
            } else {
                SetLastError(LXIErrors::NoDeviceConnected);
            }
            return returnValue;
        }

        //Mandatory Commands
        bool RigolDSG::SCPI_CLS() {
            return SCPISendCommand(SCPI_Commands::PrefixStar(&SCPI_Commands::CLS), nullptr);
        }
        bool RigolDSG::SCPI_ESE_S(const quint8 ESE) {
            return SCPISendCommand(SCPI_Commands::PostfixSpaceValue(SCPI_Commands::PrefixStar(&SCPI_Commands::ESE),
                                                                    SCPI_Commands::ToString(&ESE)), &replyBuffer);
        }
        bool RigolDSG::SCPI_ESE_Q(quint8 *ESE) {
            bool returnValue = false;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(SCPI_Commands::PrefixStar(&SCPI_Commands::ESE)), &replyBuffer)) {
                returnValue = SCPI_Commands::ToValue(ESE, &replyBuffer);
            }
            return returnValue;
        }
        bool RigolDSG::SCPI_ESR_Q(quint8 *ESR) {
            bool returnValue = false;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(SCPI_Commands::PrefixStar(&SCPI_Commands::ESR)), &replyBuffer)) {
                returnValue = SCPI_Commands::ToValue(ESR, &replyBuffer);
            }

            return returnValue;
        }

        bool RigolDSG::SCPI_IDN_Q(QString *IDN) {
            return SCPISendCommand(SCPI_Commands::PostfixQuestion(SCPI_Commands::PrefixStar(&SCPI_Commands::IDN)), IDN);
        }
//        bool RigolDSG::SCPI_OPC() {
//            return SCPISendCommand(SCPI_Commands::PrefixStar(&SCPI_Commands::OPC), nullptr);
//        }
//        bool RigolDSG::SCPI_OPC_Q(QString *OPC) {
//            return SCPISendCommand(SCPI_Commands::PostfixQuestion(SCPI_Commands::PrefixStar(&SCPI_Commands::OPC)), OPC);
//        }
        bool RigolDSG::SCPI_RST() {
            return SCPISendCommand(SCPI_Commands::PrefixStar(&SCPI_Commands::RST), nullptr);
        }

        bool RigolDSG::SCPI_SRE_S(const quint8 SRE) {
            return SCPISendCommand(SCPI_Commands::PostfixSpaceValue(SCPI_Commands::PrefixStar(&SCPI_Commands::SRE),
                                                                    SCPI_Commands::ToString(&SRE)), &replyBuffer);
        }
        bool RigolDSG::SCPI_SRE_Q(quint8 *SRE) {
            bool returnValue = false;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(SCPI_Commands::PrefixStar(&SCPI_Commands::SRE)), &replyBuffer)) {
                returnValue = SCPI_Commands::ToValue(SRE, &replyBuffer);
            }

            return returnValue;
        }
        bool RigolDSG::SCPI_STB_Q(quint8 *STB) {
            bool returnValue = false;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(SCPI_Commands::PrefixStar(&SCPI_Commands::STB)), &replyBuffer)) {
                returnValue = SCPI_Commands::ToValue(STB, &replyBuffer);
            }

            return returnValue;
        }
//        bool RigolDSG::SCPI_TST_Q(QString *TST) {
//            return SCPISendCommand(SCPI_Commands::PostfixQuestion(SCPI_Commands::PrefixStar(&SCPI_Commands::TST)), TST);

//        }
        bool RigolDSG::SCPI_WAI() {
            return SCPISendCommand(SCPI_Commands::PrefixStar(&SCPI_Commands::WAI), nullptr);
        }

        //Compound Commands
        bool RigolDSG::SCPI_OUTP_S(const SCPI_Commands::ON_OFF &ON_OFF) {
            return SCPISendCommand(SCPI_Commands::PostfixSpaceON_OFF(&SCPI_Commands::OUTP,
                                                                    &ON_OFF), &replyBuffer);
        }

        bool RigolDSG::SCPI_OUTP_Q(SCPI_Commands::ON_OFF *ON_OFF) {
            SCPI_Commands::ON_OFF returnEnum = SCPI_Commands::ON_OFF::None;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::OUTP), &replyBuffer)) {
                returnEnum = SCPI_Commands::FromON_OFF(&replyBuffer);
                if (returnEnum!= SCPI_Commands::ON_OFF::None) {
                    *ON_OFF = returnEnum;
                    return true;
                }
            }
            return false;
        }

        bool RigolDSG::SCPI_SOUR_LEV_S(const qreal &LEV) {
                        return SCPISendCommand(SCPI_Commands::PostfixSpaceValue(&SCPI_Commands::SOUR_LEV,
                                                                                SCPI_Commands::ToString(&LEV)), &replyBuffer);
        }

        bool RigolDSG::SCPI_SOUR_LEV_Q(qreal *LEV) {
            bool returnValue = false;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::SOUR_LEV), &replyBuffer)) {
                returnValue = SCPI_Commands::ToValue(LEV, &replyBuffer);
            }

            return returnValue;
        }

        bool RigolDSG::SCPI_SOUR_LEV_ATT_S(const quint8 &ATT) {
            return SCPISendCommand(SCPI_Commands::PostfixSpaceValue(&SCPI_Commands::SOUR_LEV_ATT,
                                                                    SCPI_Commands::ToString(&ATT)), &replyBuffer);
        }

        bool RigolDSG::SCPI_SOUR_LEV_ATT_Q(quint8 *ATT) {
            bool returnValue = false;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::SOUR_LEV_ATT), &replyBuffer)) {
                returnValue = SCPI_Commands::ToValue(ATT, &replyBuffer);
            }

            return returnValue;
        }

        bool RigolDSG::SCPI_SOUR_LEV_ATT_MODE_S(const QString &MODE) {
                        return SCPISendCommand(SCPI_Commands::PostfixSpaceValue(&SCPI_Commands::SOUR_LEV_ATT_MODE,
                                                                                &MODE), &replyBuffer);
        }

        bool RigolDSG::SCPI_SOUR_LEV_ATT_MODE_Q(QString *MODE) {
            return SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::SOUR_LEV_ATT_MODE), MODE);
        }


        bool RigolDSG::SCPI_SOUR_FREQ_S(const qreal &FREQ) {
            return SCPISendCommand(SCPI_Commands::PostfixSpaceValue(&SCPI_Commands::SOUR_FREQ,
                                                                                SCPI_Commands::ToString(&FREQ)), &replyBuffer);
        }

        bool RigolDSG::SCPI_SOUR_FREQ_S(const qreal &FREQ, const SCPI_Commands::FrequencyUnit &freqUnit) {
            return SCPISendCommand(SCPI_Commands::PostfixSpaceValueFreqUnit(&SCPI_Commands::SOUR_FREQ,
                                                                                SCPI_Commands::ToString(&FREQ),
                                                                                    &freqUnit), &replyBuffer);
        }

        bool RigolDSG::SCPI_SOUR_FREQ_Q(qreal *FREQ, SCPI_Commands::FrequencyUnit *freqUnit) {
            bool returnValue = false;
            QString valueAlone;
            QString unitAlone;

            //"3.000 000 000 00GHz"

//            QString test = "3.000 000 000 00GHz";
//            QString test2 = "3.333 444 555 66";
//            valueAlone = *SCPI_Commands::CleanNumber(&test, &unitAlone);
//            valueAlone = *SCPI_Commands::CleanNumber(&test2, &unitAlone);

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::SOUR_FREQ), &replyBuffer)) {
                valueAlone = *SCPI_Commands::CleanNumber(&replyBuffer, &unitAlone);
                *freqUnit = SCPI_Commands::FromFrequencyUnit(&unitAlone);
                returnValue = SCPI_Commands::ToValue(FREQ, &valueAlone);
            }

            return returnValue;
        }

        //AM
        bool RigolDSG::SCPI_SOUR_AM_FREQ_S(const qreal &AM_FREQ){
            return SCPISendCommand(SCPI_Commands::PostfixSpaceValue(&SCPI_Commands::SOUR_AM_FREQ,
                                                                                SCPI_Commands::ToString(&AM_FREQ)), &replyBuffer);
        }
        bool RigolDSG::SCPI_SOUR_AM_FREQ_S(const qreal &AM_FREQ, const SCPI_Commands::FrequencyUnit &freqUnit){
            return SCPISendCommand(SCPI_Commands::PostfixSpaceValueFreqUnit(&SCPI_Commands::SOUR_AM_FREQ,
                                                                                SCPI_Commands::ToString(&AM_FREQ),
                                                                                    &freqUnit), &replyBuffer);
        }
        bool RigolDSG::SCPI_SOUR_AM_FREQ_Q(qreal *AM_FREQ, SCPI_Commands::FrequencyUnit *freqUnit){
            bool returnValue = false;
            QString valueAlone;
            QString unitAlone;

            //"3.000 000 000 00GHz"
            //"700.00Hz"
//            QString test("3.000 000 000 00GHz");
//            QString test2("700.00Hz");
//            valueAlone = *SCPI_Commands::CleanNumber(&test2, &unitAlone);

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::SOUR_AM_FREQ), &replyBuffer)) {
                valueAlone = *SCPI_Commands::CleanNumber(&replyBuffer, &unitAlone);
                *freqUnit = SCPI_Commands::FromFrequencyUnit(&unitAlone);
                returnValue = SCPI_Commands::ToValue(AM_FREQ, &valueAlone);
            }

            return returnValue;
        }
        bool RigolDSG::SCPI_SOUR_AM_DEPT_S(const quint8 &AM_DEPT){
            return SCPISendCommand(SCPI_Commands::PostfixSpaceValue(&SCPI_Commands::SOUR_AM_DEPT,
                                                                    SCPI_Commands::ToString(&AM_DEPT)), &replyBuffer);
        }
        bool RigolDSG::SCPI_SOUR_AM_DEPT_Q(quint8 *AM_DEPT){
            bool returnValue = false;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::SOUR_AM_DEPT), &replyBuffer)) {
                returnValue = SCPI_Commands::ToValue(AM_DEPT, &replyBuffer);
            }

            return returnValue;
        }
        bool RigolDSG::SCPI_SOUR_AM_STAT_S(const SCPI_Commands::ON_OFF &AM_ON_OFF){
            return SCPISendCommand(SCPI_Commands::PostfixSpaceON_OFF(&SCPI_Commands::SOUR_AM_STAT,
                                                                    &AM_ON_OFF), &replyBuffer);
        }
        bool RigolDSG::SCPI_SOUR_AM_STAT_Q(SCPI_Commands::ON_OFF *AM_ON_OFF){
            SCPI_Commands::ON_OFF returnEnum = SCPI_Commands::ON_OFF::None;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::SOUR_AM_STAT), &replyBuffer)) {
                returnEnum = SCPI_Commands::FromON_OFF(&replyBuffer);
                if (returnEnum!= SCPI_Commands::ON_OFF::None) {
                    *AM_ON_OFF = returnEnum;
                    return true;
                }
            }
            return false;
        }
        //MOD
        bool RigolDSG::SCPI_SOUR_MOD_STAT_S(const SCPI_Commands::ON_OFF &MOD_ON_OFF){
            return SCPISendCommand(SCPI_Commands::PostfixSpaceON_OFF(&SCPI_Commands::SOUR_MOD_STAT,
                                                                    &MOD_ON_OFF), &replyBuffer);
        }
        bool RigolDSG::SCPI_SOUR_MOD_STAT_Q(SCPI_Commands::ON_OFF *MOD_ON_OFF){
            SCPI_Commands::ON_OFF returnEnum = SCPI_Commands::ON_OFF::None;

            if (SCPISendCommand(SCPI_Commands::PostfixQuestion(&SCPI_Commands::SOUR_MOD_STAT), &replyBuffer)) {
                returnEnum = SCPI_Commands::FromON_OFF(&replyBuffer);
                if (returnEnum!= SCPI_Commands::ON_OFF::None) {
                    *MOD_ON_OFF = returnEnum;
                    return true;
                }
            }
            return false;
        }

        //Private
        bool RigolDSG::OpenConnection() {
            bool returnValue = false;

            if (connectedLXIDevice == NoLXIDevice) {
                if (matchRigol != nullptr) {
                    char *ip = matchRigol->GetIPAddress().toUtf8().data();

                    //Connect
                    connectedLXIDevice = lxi_connect(ip, 0, nullptr, ConnectionTimeoutInms, VXI11);
                    if (connectedLXIDevice != LXI_ERROR) {
                        returnValue = true;
                    } else {
                        connectedLXIDevice = NoLXIDevice;
                        SetLastError(LXIErrors::ConnectionFailed);
                    }
                } else {
                    SetLastError(LXIErrors::NoDeviceConnected);
                }
            } else {
                SetLastError(LXIErrors::AlreadyConnected);
            }

            return returnValue;
        }

        bool RigolDSG::CloseConnection() {
            bool returnValue = false;

            if (connectedLXIDevice != NoLXIDevice) {
                //Disconnect
                if (lxi_disconnect(connectedLXIDevice) != LXI_OK) {
                    SetLastError(LXIErrors::DisconnectFailed);
                }
                else {
                    connectedLXIDevice = NoLXIDevice;
                    returnValue = true;
                }
            } else {
                SetLastError(LXIErrors::NoDeviceConnected);
            }

            return returnValue;
        }

        bool RigolDSG::LXI_send_receive(const QString *command, QString *response, int timeout)
        {
            bool returnValue = false;

            int replyLength;

            if (connectedLXIDevice != NoLXIDevice) {
                response_buffer[0] = '\0';
                command_buffer[0] = '\0';

                if (command->size() > 0)
                {
                    // Prepare SCPI command string
                    strcpy(command_buffer, command->toUtf8().constData());

                    // Send command
                    int bytesSent = 0;
                    int bytesToSend = static_cast<int>(strlen(command_buffer));
                    if ((bytesSent = lxi_send(connectedLXIDevice, command_buffer, bytesToSend, timeout)) == bytesToSend) {
                        // If command is a question then receive a response
                        if (SCPI_Commands::IsQuestion(command))
                        {
                            replyLength = lxi_receive(connectedLXIDevice, response_buffer, LXIBufferSizeBytes, timeout);
                            if (replyLength >= 0)
                            {
                                // Return response as a COPY of only the chars sent.
                                *response = QString::fromUtf8(response_buffer, replyLength);
                                //There seems to be a trailing '\n'.
                                returnValue = true;
                            } else {
                                SetLastError(LXIErrors::NoReplyToLXISend);
                            }
                        } else {
                            returnValue = true;
                        }
                    } else {
                        SetLastError(LXIErrors::SendLXIFailed);
                    }
                }
            }

            return returnValue;
        }

        void RigolDSG::BroadcastCallback(__attribute__((unused)) const char *address, const char *interface)
        {
            std::string broadcast_message = "Broadcasting on interface "
                                            + std::string(interface);
            //main_window->update_statusbar(broadcast_message.c_str());
        }

        void RigolDSG::DeviceCallback(const char *ipAddress, const char *instrumentMakeModelEtc)
        {
            //Create local copies.
            QString address = QString::fromLocal8Bit(ipAddress);
            QString allDetails = QString::fromLocal8Bit(instrumentMakeModelEtc);
            InstrumentAndIPAddress newInstrument = InstrumentAndIPAddress(address, allDetails);
            LxiDiscovery::getInstance()->addNewDevice(newInstrument);
            //address "192.168.1.126"
            //"Rohde&Schwarz,FSV-7,1307.9002K07/102597,2.30 SP1"
            //"ROHDE&SCHWARZFSV-7"
            //"192.168.1.112"
            //"Rigol Technologies,DSG3060,DSG3A190800008,00.01.06"
        }

        void RigolDSG::SetLastError(I_LXI_Device::LXIErrors newError) {
            //Set once
            if (lastError == LXIErrors::NoError) {
                lastError = newError;
            }
        }

        //At the start of any Public method use this
        void RigolDSG::SetLastError_NoError() {
            lastError = LXIErrors::NoError;
        }
    }
}
