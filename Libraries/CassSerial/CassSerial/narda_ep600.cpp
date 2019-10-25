#include "narda_ep600.h"
#include <QBuffer>
#include <QtMath>

namespace Cass {
    namespace SerialIO {
        //Const
        const QString StartChar = QStringLiteral("#");
        const QString CR = QStringLiteral("*");
        const QString BroadcastAddress = QStringLiteral("00");
        const QString Query = QStringLiteral("?");
        const QString Operation = QStringLiteral("@");
        const QString SettingSpace = QStringLiteral(" ");
        const QString EmptyString = QStringLiteral("");
        const QString CommandPrefix = StartChar + BroadcastAddress;
        const QString QueryPrefix = CommandPrefix + Query;
        const QString OperationPrefix = CommandPrefix + Operation;
        const QString SettingPrefix = CommandPrefix;
        const unsigned short Timeout500Inms = 500;
        const unsigned short StandardTimeoutInms = 200;
        //Commands
        //Query
        const QString CommandQueryVersion = QStringLiteral("v");
        const QString CommandQueryTake = QStringLiteral("T");
        const QString CommandQueryCalibration = QStringLiteral("p");
        const QString CommandQuerySerialNumber = QStringLiteral("s");
        const QString CommandQueryBatteryVoltage = QStringLiteral("b");
        const QString CommandQueryTemperatureC = QStringLiteral("t");
        const QString CommandQueryThreeAxisFields = QStringLiteral("A");
        //Setting
        const QString CommandSetPowerOffTime = QStringLiteral("e");
        const QString CommandSetPowerOff = QStringLiteral("!");

        Narda_EP600::Narda_EP600(QObject *parent, QString portName)
        {
            serialParent = parent;
            serPort = new Cass::SerialIO::CassSerial(this, portName, QSerialPort::Baud9600);

            //QT 5 syntax not SLOTS()...
            connect(serPort, &Cass::SerialIO::CassSerial::serialNewError, this, &Narda_EP600::handleNewSerialError);

            //Not hardware handshake, 9600 1 Start 1 Stop No Parity.
            serPort->setFlowControl(QSerialPort::NoFlowControl);
            serPort->setRxMessageTimeout(StandardTimeoutInms);

            ResetForNewMessage();
        }

        //Public
        Narda_EP600::~Narda_EP600() {
            ClosePort();
            serPort = nullptr;
        }

        bool Narda_EP600::OpenPort() {
            return serPort->OpenPort();
        }

        void Narda_EP600::ClosePort() {
            serPort->ClosePort();
        }

        bool Narda_EP600::QueryVersion(QString &version) {
            bool returnValue = false;
            QByteArray stringPartData;

            ResetForNewMessage();
            version = EmptyString;
            lastCommand = QueryPrefix + CommandQueryVersion + CR;
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, ';');
            if (!busy && CheckReplyCharacter(CommandQueryVersion, lastReply, stringPartData) && !hasTimedOut) {
                version = QString(stringPartData);
                returnValue = true;
            }
            return returnValue;
        }

        bool Narda_EP600::QueryTakeReading(qreal &fieldStrength) {
            const unsigned short expectedCount = 5;
            bool returnValue = false;
            QByteArray numericPartData;
            float fieldStrengthSquared = 0;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout500Inms);
            fieldStrength = 0.0;
            lastCommand = QueryPrefix + CommandQueryTake + SettingSpace + CR;
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::byteCount, expectedCount);
            if (!busy && CheckReplyCharacter(CommandQueryTake, lastReply, numericPartData) && !hasTimedOut) {
                //numericPartData = QByteArrayLiteral("\x80\x00\x00\x00");
                //Little Endian.
                QBuffer buffer(&numericPartData, serialParent);
                buffer.open(QIODevice::ReadOnly);
                buffer.read(reinterpret_cast<char *>(&fieldStrengthSquared), sizeof(float));
                buffer.close();
                fieldStrength = sqrt(static_cast<double>(fieldStrengthSquared));
                returnValue = true;
            }
            return returnValue;
        }

        bool Narda_EP600::QueryCalibrationDate(QString &calDate) {
            bool returnValue = false;
            QByteArray stringPartData;

            ResetForNewMessage();
            calDate = EmptyString;
            lastCommand = QueryPrefix + CommandQueryCalibration + CR;
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy);
            if (!busy && CheckReplyCharacter(CommandQueryCalibration, lastReply, stringPartData) && hasTimedOut) {
                calDate = QString(stringPartData);
                returnValue = true;
            }
            return returnValue;
        }

        bool Narda_EP600::QuerySerialNumber(QString &serialNumber) {
            bool returnValue = false;
            QByteArray stringPartData;

            ResetForNewMessage();
            serialNumber = EmptyString;
            lastCommand = QueryPrefix + CommandQuerySerialNumber + CR;
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy);
            if (!busy && CheckReplyCharacter(CommandQuerySerialNumber, lastReply, stringPartData) && hasTimedOut) {
                serialNumber = QString(stringPartData);
                returnValue = true;
            }
            return returnValue;
        }

        bool Narda_EP600::QueryBatteryVoltage(qreal &batteyVoltage) {
            const unsigned short expectedCount = 3;
            const quint16 Batt3 = 3;
            const qreal Batt1024 = 1024.0;
            const qreal Batt1Point6 = 1.6;
            bool returnValue = false;
            QByteArray numericPartData;
            quint16 rawVoltage = 0;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout500Inms);
            batteyVoltage = 0.0;
            lastCommand = QueryPrefix + CommandQueryBatteryVoltage + CR;
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::byteCount, expectedCount);
            if (!busy && CheckReplyCharacter(CommandQueryBatteryVoltage, lastReply, numericPartData) && !hasTimedOut) {
                //Big Endian.
                std::reverse(numericPartData.begin(), numericPartData.end());
                QBuffer buffer(&numericPartData, serialParent);
                buffer.open(QIODevice::ReadOnly);
                buffer.read(reinterpret_cast<char *>(&rawVoltage), sizeof(quint16));
                buffer.close();
                batteyVoltage = Batt3 * ((rawVoltage/Batt1024) * Batt1Point6);
                returnValue = true;
            }
            return returnValue;
        }

        bool Narda_EP600::QueryTemperatureC(qreal &temperatureInC){
            const unsigned short expectedCount = 3;
            const quint16 Temp1000 = 1000;
            const qreal Temp1024 = 1024.0;
            const qreal Temp1Point6 = 1.6;
            const qreal Temp3Point55 = 3.55;
            const qreal TempPoint986 = 0.986;
            bool returnValue = false;
            QByteArray numericPartData;
            quint16 rawTemperature = 0;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout500Inms);
            temperatureInC = 0.0;
            lastCommand = QueryPrefix + CommandQueryTemperatureC + CR;
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::byteCount, expectedCount);
            if (!busy && CheckReplyCharacter(CommandQueryTemperatureC, lastReply, numericPartData) && !hasTimedOut) {
                //Big Endian.
                std::reverse(numericPartData.begin(), numericPartData.end());
                QBuffer buffer(&numericPartData, serialParent);
                buffer.open(QIODevice::ReadOnly);
                buffer.read(reinterpret_cast<char *>(&rawTemperature), sizeof(quint16));
                buffer.close();
                temperatureInC = Temp1000/Temp3Point55 * (((rawTemperature/Temp1024) * Temp1Point6) - TempPoint986);
                returnValue = true;
            }
            return returnValue;
        }

        bool Narda_EP600::QueryThreeAxesFields(qreal &fieldX, qreal &fieldY, qreal &fieldZ) {
            const unsigned short expectedCount = 13;
            bool returnValue = false;
            QByteArray numericPartData;
            float fieldStrength;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout500Inms);
            fieldX = fieldY = fieldZ = 0.0;
            lastCommand = QueryPrefix + CommandQueryThreeAxisFields + CR;
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::byteCount, expectedCount);
            if (!busy && CheckReplyCharacter(CommandQueryThreeAxisFields, lastReply, numericPartData) && !hasTimedOut) {
                //Little Endian.
                QBuffer buffer(&numericPartData, serialParent);
                buffer.open(QIODevice::ReadOnly);
                buffer.read(reinterpret_cast<char *>(&fieldStrength), sizeof(float));
                fieldX = static_cast<qreal>(fieldStrength);
                buffer.read(reinterpret_cast<char *>(&fieldStrength), sizeof(float));
                fieldY = static_cast<qreal>(fieldStrength);
                buffer.read(reinterpret_cast<char *>(&fieldStrength), sizeof(float));
                fieldZ = static_cast<qreal>(fieldStrength);
                buffer.close();
                returnValue = true;
            }
            return returnValue;
        }

        bool Narda_EP600::SetProbePowerOffTimeIns(unsigned short timeIns) {
            const unsigned short expectedCount = 1;
            const unsigned int MaxSeconds = 10800;
            bool returnValue = false;
            QByteArray numericPartData;

            if (timeIns <= MaxSeconds) {
                ResetForNewMessage();
                serPort->setRxMessageTimeout(Timeout500Inms);
                lastCommand = SettingPrefix + CommandSetPowerOffTime + SettingSpace + QString::number(timeIns) + CR;
                lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::byteCount, expectedCount);
                if (!busy && CheckReplyCharacter(CommandSetPowerOffTime, lastReply, numericPartData) && !hasTimedOut) {
                    returnValue = true;
                }
            }
            return returnValue;
        }

        bool Narda_EP600::SetProbePowerOff() {
            const unsigned short expectedCount = 7;
            bool returnValue = false;
            QByteArray numericPartData;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout500Inms);
            lastCommand = SettingPrefix + CommandSetPowerOff + SettingSpace + CR;
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::byteCount, expectedCount);
            if (!busy && CheckReplyCharacter(CommandQueryVersion, lastReply, numericPartData) && !hasTimedOut) {
                returnValue = true;
            }
            return returnValue;
        }

        //Properties
        QString Narda_EP600::getLastCommand() const {
            return lastCommand;
        }

        QByteArray Narda_EP600::getLastReply() const {
            return lastReply;
        }

        QString Narda_EP600::getLastErrorText() const {
            return lastErrorText;
        }

        bool Narda_EP600::getBusy() const {
            return busy;
        }

        bool Narda_EP600::getVersion(quint8 &Major, quint8 &Minor) const {
            Major = 1;
            Minor =0;
            return true;
        }

        //Private
        bool Narda_EP600::StartsWithChar(const QString &comparisonChar, QByteArray &theData) {
            return theData.startsWith(comparisonChar.at(0).toLatin1());
        }

        void Narda_EP600::ResetForNewMessage() {
            lastCommand = QStringLiteral("");
            lastReply = QByteArray();
            lastErrorText = QStringLiteral("");
            hasTimedOut = false;
            busy = false;
            serPort->ClearRxPort();
            serPort->setRxMessageTimeout(StandardTimeoutInms);
        }

        bool Narda_EP600::CheckReplyCharacter(QString replyExpected, QByteArray theData, QByteArray &modifiedData) {
            bool returnValue = false;

            if (StartsWithChar(replyExpected, theData)) {
                modifiedData = theData.right(theData.length()-replyExpected.length());
                returnValue = true;
            }
            return returnValue;
        }

        //Handlers
        void Narda_EP600::handleNewSerialError(QSerialPort::SerialPortError newError) {
            QString newText = Cass::SerialIO::CassSerial::SerialMessage(newError);
            lastErrorText = newText;
            emit probeNewError(newError);
        }
    }
}
