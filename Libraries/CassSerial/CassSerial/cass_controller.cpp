#include "cass_controller.h"

namespace Cass {
    namespace SerialIO {
        //Const
        const QChar CR = QLatin1Char('\r');
        const QChar LF = QLatin1Char('\n');
        const QChar ESC = QLatin1Char('\x1B');
        const QChar Space = QLatin1Char(' ');
        const QString LFCR = QString(LF) + QString(CR);
        const unsigned short StandardTimeoutInms = 2000;
        const quint8 LoadOutputSweepSizeInBytes = 80;
        //Commands
        const QString ACQD = QStringLiteral("ACQD");
        const QString ANIN = QStringLiteral("ANIN");
        const QString ANIF = QStringLiteral("ANIF");
        const QString ANON = QStringLiteral("ANON");
        const QString ANOF = QStringLiteral("ANOF");
        const QString BAUD = QStringLiteral("BAUD");
        const QString DIGO = QStringLiteral("DIGO");
        const QString LMEM = QStringLiteral("LMEM");
        const QString LDOP = QStringLiteral("LDOP");
        const QString MEMD = QStringLiteral("MEMD");
        const QString RSET = QStringLiteral("RSET");
        const QString SCNT = QStringLiteral("SCNT");
        const QString SELI = QStringLiteral("SELI");
        const QString STAT = QStringLiteral("STAT");
        const QString SWPT = QStringLiteral("SWPT");

        Cass_Controller::Cass_Controller(QObject *parent, QString portName) : QObject(parent)
        {
            serialParent = parent;
            serPort = new Cass::SerialIO::CassSerial(this, portName, QSerialPort::Baud9600);

            //QT 5 syntax not SLOTS()...
            connect(serPort, &Cass::SerialIO::CassSerial::serialNewError, this, &Cass_Controller::handleNewSerialError);

            //Not hardware handshake, 57K6 or 9600, 1 Start 1 Stop No Parity.
            serPort->setFlowControl(QSerialPort::NoFlowControl);
            serPort->setRxMessageTimeout(StandardTimeoutInms);

            ResetForNewMessage();

        }
        //Public
        Cass_Controller::~Cass_Controller() {
            ClosePort();
            serPort = nullptr;
        }

        bool Cass_Controller::OpenPort() {
            return serPort->OpenPort();
        }

        void Cass_Controller::ClosePort() {
            serPort->ClosePort();
        }

        //Commands
        bool Cass_Controller::QueryAllStatus(ControllerSTAT *theSTAT) {
            bool returnValue = false;

            theSTAT->Clear();

            ResetForNewMessage();

            if (SendCommandBytesIndividually(STAT, true, returnedData)) {
                if (theSTAT->Populate(returnedData)) {
                    returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetReset() {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(RSET, false, returnedData)) {
                returnValue = true;
            }

            return returnValue;
        }

        bool Cass_Controller::SetDigitalOutput(quint8 theBitPattern) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(DIGO, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(theBitPattern))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetAnalogueInputON(quint8 thePort) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(ANIN, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(thePort))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetAnalogueInputOFF(quint8 thePort) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(ANIF, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(thePort))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetSelectAnalogueInputForDA(quint8 thePort) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(SELI, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(thePort))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetAnalogueInputScanTime(quint8 theTime) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(SCNT, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(theTime))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetAnalogueOutputSweepTime(quint8 theTime) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(SWPT, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(theTime))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetBaudRate(const quint8 baudRate) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(BAUD, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(baudRate))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetAnalogueAcquireOn(const quint8 thePort) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(ACQD, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(thePort))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetAnalogueOutputOn(const quint8 thePort) {
            bool returnValue = false;

            ResetForNewMessage();

            if (SendCommandBytesIndividually(ANON, false, returnedData)) {
                //Now the data
                if (SendExtraDataBytes(As2HexDigits(thePort))) {
                        returnValue = true;
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SetLoadOutputSweep(const quint8 theOutput, QByteArray theWaveform) {
            bool returnValue = false;

            ResetForNewMessage();

            if (theWaveform.length() == LoadOutputSweepSizeInBytes) {
                if (SendCommandBytesIndividually(LDOP, false, returnedData)) {
                    //Now the data
                    if (SendExtraDataBytes(InHexDigitPairs(theOutput, theWaveform))) {
                            returnValue = true;
                    }
                }
            }

            return returnValue;
        }


        //Properties
        QString Cass_Controller::getLastCommand() const {
            return lastCommand;
        }

        QByteArray Cass_Controller::getLastReply() const {
            return lastReply;
        }

        QString Cass_Controller::getLastErrorText() const {
            return lastErrorText;
        }

        bool Cass_Controller::getBusy() const {
            return busy;
        }

        bool Cass_Controller::getVersion(quint8 &Major, quint8 &Minor) const {
            Major = 1;
            Minor =0;
            return true;
        }

        //Private
        void Cass_Controller::ResetForNewMessage() {
            lastCommand = QStringLiteral("");
            lastReply = QByteArray();
            lastErrorText = QStringLiteral("");
            hasTimedOut = false;
            busy = false;
            serPort->ClearRxPort();
            serPort->setRxMessageTimeout(StandardTimeoutInms);
        }

        bool Cass_Controller::StartsWithChar(const QString &comparisonChar, QByteArray &theData) {
            return theData.startsWith(comparisonChar.at(0).toLatin1());
        }

        bool Cass_Controller::EndsWithChars(const QString &comparisonChars, QByteArray &theData) {
            return theData.endsWith(comparisonChars.toUtf8());
        }

        bool Cass_Controller::CheckReplyFirstCharacterAndEnding(QString expectedReplyFirst, QString expectedReplySecond, QString expectedReplyLast, QByteArray theData, QByteArray &modifiedData) {
            bool returnValue = false;

            int dataSize = theData.length();
            int firstSize = expectedReplyFirst.length();
            int secondSize = expectedReplySecond.length();
            int lastSize = expectedReplyLast.length();
            if (StartsWithChar(expectedReplyFirst, theData) && EndsWithChars(expectedReplyLast, theData)) {
                //Take off the start and end parts first.
                modifiedData = theData.right(dataSize-firstSize);
                modifiedData = modifiedData.left(dataSize-firstSize-lastSize);
                //Maybe the second. Wont hurt if there is none.
                if (!expectedReplySecond.isNull() && !expectedReplySecond.isEmpty()) {
                    modifiedData = modifiedData.right(dataSize-firstSize-secondSize-lastSize);
                }
                modifiedData = modifiedData.trimmed();

                returnValue = true;
            }
            return returnValue;
        }

        bool Cass_Controller::SendCommandBytesIndividually(const QString &theCommand, const bool replyExpected, QByteArray &numericPartData) {
            const unsigned short expectedCount = 1;
            bool returnValue = true;

            //2 cases of reply data to "...T".
            //"T\n\r00 00 00 00 00 00 05 40 92 71 91 52 00 42 00 00 00 02 6D \n\r"
            //"T\n\r"

            int commandSizeBytes = theCommand.length();

            numericPartData.clear();
            for (int byteIndex = 0; byteIndex < commandSizeBytes; byteIndex++) {
                ResetForNewMessage();
                serPort->setRxMessageTimeout(StandardTimeoutInms);
                lastCommand = theCommand.at(byteIndex);
                if (byteIndex == commandSizeBytes-1) {
                    //Last one has \n\r too.
                    lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, CR.unicode());
                    if (!busy && CheckReplyFirstCharacterAndEnding(lastCommand, replyExpected ? LFCR : QString(), LFCR, lastReply, numericPartData) && !hasTimedOut) {
                        //"\n\r00 00 00 00 00 00 05 3A 92 49 91 11 00 42 00 00 00 01 FE \n\r"
                        //OK
                    } else {
                        returnValue = false;
                        break;
                    }
                } else {
                    lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::byteCount, expectedCount);
                    if (!busy && StartsWithChar(lastCommand, lastReply) && !hasTimedOut) {
                        //OK
                    } else {
                        returnValue = false;
                        break;
                    }
                }
            }

            return returnValue;
        }

        bool Cass_Controller::SendExtraDataBytes(const QString &theDataAsASCIIPairs) {
            bool returnValue = false;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(StandardTimeoutInms);
            //Add LFCR
            lastCommand = theDataAsASCIIPairs + LFCR;
            //Post data has \n\r too. ""07\n\r\n\r"
            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, CR.unicode());
            if (!busy && EndsWithChars(LFCR, lastReply) && !hasTimedOut) {
                returnValue = true;
            } else {
                //Reset it
                lastReply = serPort->SendSerialBytes(QString(ESC).toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::onMessageSent);
            }
            return returnValue;
        }

        QString Cass_Controller::As2HexDigits(const quint8 theBitPattern) {
            const int HexWidth =2;
            return QString("%1").arg(theBitPattern, HexWidth, Cass::SerialIO::ControllerSTAT::Hex, QChar('0'));
        }

        QString Cass_Controller::InHexDigitPairs(const QByteArray theBytes) {
            QString returnValue = QString();

            int size = theBytes.size();
            for (int i = 0; i < size; i++) {
                returnValue += As2HexDigits(static_cast<quint8>(theBytes[i]));
                if (i != size -1) {
                    returnValue += Space;
                }
            }

            return returnValue;
        }

        QString Cass_Controller::InHexDigitPairs(const quint8 theFirstByte, const QByteArray theBytes) {
            QString returnValue = As2HexDigits(theFirstByte);

            returnValue += InHexDigitPairs(theBytes);

            return returnValue;
        }


        //Handlers
        void Cass_Controller::handleNewSerialError(QSerialPort::SerialPortError newError) {
            QString newText = Cass::SerialIO::CassSerial::SerialMessage(newError);
            lastErrorText = newText;
            emit probeNewError(newError);
        }
    }
}
