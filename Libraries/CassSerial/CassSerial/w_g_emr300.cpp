#include "w_g_emr300.h"

namespace Cass {
    namespace SerialIO {
        //Const
        const QString FaultString = QStringLiteral("***FAULT***");
        const QString EmptyString = QStringLiteral("");
        const QString Colon = QStringLiteral(":");
        const QString Question = QStringLiteral("?");
        const QChar CR = QLatin1Char('\r');
        const QChar LF = QLatin1Char('\n');
        const QChar Comma = QLatin1Char(',');
        const QChar Space = QLatin1Char(' ');
        const QString LFCR = QString(CR) + QString(LF);
        const qreal NullQRealValue = -999.0;
        const QString BAT_OK = QStringLiteral("BAT_OK");
        const QString BAT_LOW = QStringLiteral("BAT_LOW");
        const QString ON = QStringLiteral("ON");
        const QString OFF = QStringLiteral("OFF");
        const QString ALL = QStringLiteral("ALL");
        const QString EFF = QStringLiteral("EFF");
        const QString X = QStringLiteral("X");
        const QString Y = QStringLiteral("Y");
        const QString Z = QStringLiteral("Z");
        //Command Types
        const QString SYST = QStringLiteral("SYST");
        const QString MEAS = QStringLiteral("MEAS");
        const QString FAST = QStringLiteral("FAST");
        const QString M = QStringLiteral("M");
        const QString CALC = QStringLiteral("CALC");
        //Prefix
        const QString SYSTPrefix = SYST + Colon;
        const QString MEASPrefix = MEAS + Colon;
        const QString CALCPrefix = CALC + Colon;
        const QString FASTPrefix = FAST + Colon;
        const unsigned short Timeout500Inms = 500;
        const unsigned short Timeout4000Inms = 4000;
        const unsigned short StandardTimeoutInms = 200;
        //Commands
        const QString SystStarIDN = QStringLiteral("*IDN") + Question;
        const QString SystBEEP = SYSTPrefix + QStringLiteral("BEEP");
        const QString BPSystBEEP = QStringLiteral("BP");
        const QString SystERR = SYSTPrefix + QStringLiteral("ERR") + Question;
        const QString SESystERR = QStringLiteral("SE");
        const QString SystBAT = SYSTPrefix + QStringLiteral("BAT") + Question;
        const QString FastMODE = FASTPrefix + QStringLiteral("MODE");
        const QString CalcAXIS = CALCPrefix + QStringLiteral("AXIS");
        const QString CAXCalcAXIS = QStringLiteral("CAX");
        //CR is optional but any parameters must be separated by a space.
        const QString MeasSingleValue = MEAS + Question + CR + LF;
        const QString MSingleValue = M + CR + LF;
        const QString QueryVersionData = SystStarIDN + CR + LF;
        const QString QueryBatteryOK = SystBAT + CR + LF;
        const QString QuerySystERR = SystERR + CR + LF;
        const QString QuerySESystERR = SESystERR + CR + LF;
        const QString QueryFastMODE = FastMODE + Question + CR + LF;
        const QString SetFastMODE = FastMODE + Space;
        const QString SetSystBEEP = SystBEEP + CR + LF;
        const QString SetBPSystBEEP = BPSystBEEP + CR + LF;
        const QString QueryCalcAXIS = CalcAXIS + Question + CR + LF;
        const QString SetCalcAXIS = CalcAXIS + Space;

        W_G_Emr300::W_G_Emr300(QObject *parent, QString portName)
        {
            serialParent = parent;
            serPort = new Cass::SerialIO::CassSerial(this, portName, QSerialPort::Baud4800);

            //QT 5 syntax not SLOTS()...
            connect(serPort, &Cass::SerialIO::CassSerial::serialNewError, this, &W_G_Emr300::handleNewSerialError);

            //Xon/Xoff handshake, 4800 1 Start 1 Stop No Parity.
            serPort->setFlowControl(QSerialPort::SoftwareControl);
            serPort->setRxMessageTimeout(StandardTimeoutInms);

            ResetForNewMessage();
        }

        //Public
        W_G_Emr300::~W_G_Emr300() {
            ClosePort();
            serPort = nullptr;
        }

        bool W_G_Emr300::OpenPort() {
            return serPort->OpenPort();
        }

        void W_G_Emr300::ClosePort() {
            serPort->ClosePort();
        }

        bool W_G_Emr300::QuerySingleOrThreeValues(bool &threeValues, qreal &fieldX, qreal &fieldY, qreal &fieldZ) {
            const int OneMeasurement = 1;
            const int ThreeMeasurements = 3;

            bool returnValue = false;
            QByteArray numericPartData;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            threeValues = false;
            fieldX = fieldY = fieldZ =NullQRealValue;
            lastCommand = false ? MeasSingleValue : MSingleValue;
            QList<QByteArray> threeAxisData;
            bool convertXOK = false;
            bool convertYOK = false;
            bool convertZOK = false;

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, LF.unicode());
            if (!busy && CheckEndCharacters(LFCR, lastReply, numericPartData) && !hasTimedOut) {
                threeAxisData = numericPartData.split(Comma.toLatin1());
                //No match returns single element.
                if (threeAxisData.length() == OneMeasurement || threeAxisData.length() == ThreeMeasurements) {
                    fieldX = threeAxisData[0].toDouble(&convertXOK);
                    if (convertXOK) {
                        // Three
                        if (threeAxisData.length() == ThreeMeasurements) {
                            threeValues = true;
                            fieldY = threeAxisData[1].toDouble(&convertYOK);
                            fieldZ = threeAxisData[2].toDouble(&convertZOK);
                            if (convertYOK && convertZOK) {
                                returnValue = true;
                            } else {
                                fieldY = fieldZ =NullQRealValue;
                            }
                        } else {
                            returnValue = true;
                        }
                    } else {
                        fieldX = NullQRealValue;
                    }
                }
            }
            return returnValue;
        }

        bool W_G_Emr300::QueryVersion(QString &version) {
            bool returnValue = false;
            QByteArray numericPartData;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            version = EmptyString;
            lastCommand = QueryVersionData;

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, LF.unicode());
            if (!busy && CheckEndCharacters(LFCR, lastReply, numericPartData) && !hasTimedOut) {
                version = QString(numericPartData);
                returnValue = true;
            }
            return returnValue;
        }

        bool W_G_Emr300::QueryBatteryVoltage(bool &batteryOK) {
            bool returnValue = false;
            QByteArray numericPartData;
            QString reply;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            batteryOK = false;
            lastCommand = QueryBatteryOK;

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, LF.unicode());
            if (!busy && CheckEndCharacters(LFCR, lastReply, numericPartData) && !hasTimedOut) {
                reply = QString(numericPartData).toUpper();
                if (reply == BAT_OK) {
                    batteryOK = true;
                    returnValue = true;
                }
                if (reply == BAT_LOW) {
                    batteryOK = false;
                    returnValue = true;
                }
            }
            return returnValue;
        }

        bool W_G_Emr300::QueryCommandError(CommandError &commandError) {
            bool returnValue = false;
            QByteArray numericPartData;
            short reply;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            commandError = CommandError::Undefined;
            lastCommand = true ? QuerySystERR : QuerySESystERR;
            bool convertionOK = false;

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, LF.unicode());
            if (!busy && CheckEndCharacters(LFCR, lastReply, numericPartData) && !hasTimedOut) {
                reply = numericPartData.toShort(&convertionOK);
                if (convertionOK) {
                    commandError = static_cast<CommandError>(reply);
                    returnValue = true;
                } else {
                    commandError = CommandError::Undefined;
                }
            }
            return returnValue;
        }

        bool W_G_Emr300::SetBeep() {
            bool returnValue = false;
            QByteArray numericPartData;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            lastCommand = true ? SetSystBEEP : SetBPSystBEEP;

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::onMessageSent);
            if (!busy && !hasTimedOut) {
                returnValue = true;
            }
            return returnValue;
        }

        bool W_G_Emr300::QueryFastMode(bool &fastModeOn) {
            bool returnValue = false;
            QByteArray numericPartData;
            QString reply;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            fastModeOn = false;
            lastCommand = QueryFastMODE;

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, LF.unicode());
            if (!busy && CheckEndCharacters(LFCR, lastReply, numericPartData) && !hasTimedOut) {
                reply = QString(numericPartData).toUpper();
                if (reply == ON) {
                    fastModeOn = true;
                    returnValue = true;
                }
                if (reply == OFF) {
                    fastModeOn = false;
                    returnValue = true;
                }
            }
            return returnValue;
        }

        bool W_G_Emr300::SetFastMode(const bool fastModeOn) {
            bool returnValue = false;
            QByteArray numericPartData;
            QString reply;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            lastCommand = SetON_OFF_CRLF(SetFastMODE, fastModeOn);

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::onMessageSent);
            if (!busy && !hasTimedOut) {
                returnValue = true;
            }
            return returnValue;
        }

        bool W_G_Emr300::QueryCalcAxis(CalcFieldAxes &calculationAxis) {
            bool returnValue = false;
            QByteArray numericPartData;
            QString reply;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            lastCommand = QueryCalcAXIS;

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, LF.unicode());
            if (!busy && CheckEndCharacters(LFCR, lastReply, numericPartData) && !hasTimedOut) {
                if (GetCalcAXIS(QString(numericPartData), calculationAxis)) {
                    returnValue = true;
                }
            }
            return returnValue;
        }

        bool W_G_Emr300::SetCalcAxis(const CalcFieldAxes calculationAxis) {
            bool returnValue = false;
            QByteArray numericPartData;
            QString reply;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout4000Inms);
            lastCommand = SetCalcAXIS_CRLF(SetCalcAXIS, calculationAxis);

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::onMessageSent);
            if (!busy && !hasTimedOut) {
                returnValue = true;
            }
            return returnValue;
        }

        //Properties
        QString W_G_Emr300::getLastCommand() const {
            return lastCommand;
        }

        QByteArray W_G_Emr300::getLastReply() const {
            return lastReply;
        }

        QString W_G_Emr300::getLastErrorText() const {
            return lastErrorText;
        }

        bool W_G_Emr300::getBusy() const {
            return busy;
        }

        bool W_G_Emr300::getVersion(quint8 &Major, quint8 &Minor) const {
            Major = 1;
            Minor =0;
            return true;
        }

        //Private
        bool W_G_Emr300::EndsWithString(const QString &comparisonEnding, QByteArray &theData) {
            return theData.endsWith(comparisonEnding.toUtf8());
        }

        void W_G_Emr300::ResetForNewMessage() {
            lastCommand = QStringLiteral("");
            lastReply = QByteArray();
            lastErrorText = QStringLiteral("");
            hasTimedOut = false;
            busy = false;
            serPort->ClearRxPort();
            serPort->setRxMessageTimeout(StandardTimeoutInms);
        }

        bool W_G_Emr300::CheckEndCharacters(QString endExpected, QByteArray theData, QByteArray &modifiedData) {
            bool returnValue = false;

            if (EndsWithString(endExpected, theData)) {
                modifiedData = theData.left(theData.length()-endExpected.length());
                returnValue = true;
            }
            return returnValue;
        }

        QString W_G_Emr300::SetON_OFF_CRLF(const QString originalCommand, const bool on) {
            return  originalCommand + (on ? ON : OFF) + CR + LF;
        }

        QString W_G_Emr300::SetCalcAXIS_CRLF(const QString originalCommand, const CalcFieldAxes axis) {
            QString returnValue = originalCommand;

            switch (axis) {
            case CalcFieldAxes::Undefined:
                returnValue += FaultString;
                break;

            case CalcFieldAxes::DispTotalSerialXYZ_ALL:
                returnValue += ALL;
                break;

            case CalcFieldAxes::DispTotalSerialTotal_EFF:
                returnValue += EFF;
                break;

            case CalcFieldAxes::DispXSerialX_X:
                returnValue += X;
                break;

            case CalcFieldAxes::DispYSerialY_Y:
                returnValue += Y;
                break;

            case CalcFieldAxes::DispZSerialZ_Z:
                returnValue += Z;
                break;

            default:
                returnValue += FaultString;
                break;
            }
            return  (returnValue + CR + LF);
        }

        bool W_G_Emr300::GetCalcAXIS(const QString returnedAxisString, CalcFieldAxes &theCalcAxis) {
            bool returnValue = false;
            theCalcAxis = CalcFieldAxes::Undefined;
            QString returnedUpper = returnedAxisString.toUpper();

            if (returnedUpper == ALL) {
                theCalcAxis = CalcFieldAxes::DispTotalSerialXYZ_ALL;
                returnValue = true;
            } else if (returnedUpper == EFF) {
                theCalcAxis = CalcFieldAxes::DispTotalSerialTotal_EFF;
                returnValue = true;
            } else if (returnedUpper == X) {
                theCalcAxis = CalcFieldAxes::DispXSerialX_X;
                returnValue = true;
            } else if (returnedUpper == Y) {
                theCalcAxis = CalcFieldAxes::DispYSerialY_Y;
                returnValue = true;
            } else if (returnedUpper == Z) {
                theCalcAxis = CalcFieldAxes::DispZSerialZ_Z;
                returnValue = true;
            }

            return returnValue;
        }

        //Handlers
        void W_G_Emr300::handleNewSerialError(QSerialPort::SerialPortError newError) {
            QString newText = Cass::SerialIO::CassSerial::SerialMessage(newError);
            lastErrorText = newText;
            emit probeNewError(newError);
        }
    }
}
