#ifndef RIGOLDSG_H
#define RIGOLDSG_H

#include <i_lxi_device.h>
#include <lxi.h>
#include <instrumentandipaddress.h>
#include <lxidiscovery.h>
#include <scpi_commands.h>

namespace Cass {
    namespace LXI {
        //QObject MUST be FIRST!!
        class RigolDSG : public QObject, public I_LXI_Device
        {
            Q_OBJECT

        public:
            RigolDSG(QObject *parent);
            ~RigolDSG();
            bool SearchForDevices();
            QString getLastCommand() const;
            QString getLastReply() const;
            I_LXI_Device::LXIErrors GetLastError() const;
            static void SetTheRigol(RigolDSG *aRigol);
            static QList<InstrumentAndIPAddress> allDevices;
            bool SCPISendCommand(const QString *command, QString *reply);
            //Mandatory Commands
            bool SCPI_CLS();
            bool SCPI_ESE_S(const quint8 ESE);
            bool SCPI_ESE_Q(quint8 *ESE);
            bool SCPI_ESR_Q(quint8 *ESR);

            bool SCPI_IDN_Q(QString *IDN);
//            bool SCPI_OPC();
//            bool SCPI_OPC_Q(QString *OPC);
            bool SCPI_RST();

            bool SCPI_SRE_S(const quint8 SRE);
            bool SCPI_SRE_Q(quint8 *SRE);
            bool SCPI_STB_Q(quint8 *STB);
//            bool SCPI_TST_Q(QString *TST);

            bool SCPI_WAI();
            //bool OpenConnection();
            //bool CloseConnection();

            //Rigol Commands
            bool SCPI_OUTP_S(const SCPI_Commands::ON_OFF &ON_OFF);
            bool SCPI_OUTP_Q(SCPI_Commands::ON_OFF *ON_OFF);
            //RF Level
            bool SCPI_SOUR_LEV_S(const qreal &LEV);
            bool SCPI_SOUR_LEV_Q(qreal *LEV);
            bool SCPI_SOUR_LEV_ATT_S(const quint8 &ATT);
            bool SCPI_SOUR_LEV_ATT_Q(quint8 *ATT);
            bool SCPI_SOUR_LEV_ATT_MODE_S(const QString &MODE);
            bool SCPI_SOUR_LEV_ATT_MODE_Q(QString *MODE);
            //Frequency
            bool SCPI_SOUR_FREQ_S(const qreal &FREQ);
            bool SCPI_SOUR_FREQ_S(const qreal &FREQ, const SCPI_Commands::FrequencyUnit &freqUnit);
            bool SCPI_SOUR_FREQ_Q(qreal *FREQ, SCPI_Commands::FrequencyUnit *freqUnit);
            //AM
            bool SCPI_SOUR_AM_FREQ_S(const qreal &AM_FREQ);
            bool SCPI_SOUR_AM_FREQ_S(const qreal &AM_FREQ, const SCPI_Commands::FrequencyUnit &freqUnit);
            bool SCPI_SOUR_AM_FREQ_Q(qreal *AM_FREQ, SCPI_Commands::FrequencyUnit *freqUnit);
            bool SCPI_SOUR_AM_DEPT_S(const quint8 &AM_DEPT);
            bool SCPI_SOUR_AM_DEPT_Q(quint8 *AM_DEPT);
            bool SCPI_SOUR_AM_STAT_S(const SCPI_Commands::ON_OFF &AM_ON_OFF);
            bool SCPI_SOUR_AM_STAT_Q(SCPI_Commands::ON_OFF *AM_ON_OFF);
            //MOD
            bool SCPI_SOUR_MOD_STAT_S(const SCPI_Commands::ON_OFF &MOD_ON_OFF);
            bool SCPI_SOUR_MOD_STAT_Q(SCPI_Commands::ON_OFF *MOD_ON_OFF);

        private:
            QObject *ethernetParent;
            lxi_info_t rigolInformation;
            I_LXI_Device::LXIErrors lastError;
            bool OpenConnection();
            bool CloseConnection();
            bool LXI_send_receive(const QString *command, QString *response, int timeout);
            void SetLastError(I_LXI_Device::LXIErrors newError);
            void SetLastError_NoError();
            //Must be static for callbacks.
            static void BroadcastCallback(__attribute__((unused)) const char *address, const char *interface);
            static void DeviceCallback(const char *ipAddress, const char *instrumentMakeModelEtc);
            InstrumentAndIPAddress* matchRigol;
            const QString EmptyString = QStringLiteral("");
#if true
            const InstrumentAndIPAddress RIGOL_DSG = InstrumentAndIPAddress("RIGOL TECHNOLOGIES", "DSG3060", EmptyString);
#else
            const InstrumentAndIPAddress RIGOL_DSG = InstrumentAndIPAddress("ROHDE&SCHWARZ", "FSV-7", EmptyString);
#endif
            const lxi_discover_t DeviceType = lxi_discover_t::DISCOVER_VXI11;
            const int DeviceFindTimeoutInms = 2000;
            const int ConnectionTimeoutInms = 2000;
            int connectedLXIDevice = NoLXIDevice;
            //0 is reserved so use -1.
            const int NoLXIDevice = -1;
            static const int LXIBufferSizeBytes = 10000;
            char response_buffer[LXIBufferSizeBytes];
            char command_buffer[LXIBufferSizeBytes];
            const int SCPISendAndReceiveTimeoutInms = 2000;
            QString lastCommand;
            QString lastReply;
            QString replyBuffer;

        signals:
            void InstrumentDiscovered(InstrumentAndIPAddress newInstrument);

        };
    }
}

#endif // RIGOLDSG_H
