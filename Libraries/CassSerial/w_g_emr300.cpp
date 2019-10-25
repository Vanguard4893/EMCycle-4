#include "w_g_emr300.h"

namespace Cass {
    namespace SerialIO {
        //Const
        const QString Colon = QStringLiteral(":");
        const QString Question = QStringLiteral("?");
        const QChar CR = '\r';
        const QChar LF = '\n';
        const QString CRLF = QString(CR) + QString(LF);
        const qreal NullQRealValue = -999.0;
        //Command Types
        const QString SYST = QStringLiteral("SYST");
        const QString MEAS = QStringLiteral("MEAS");
        const QString M = QStringLiteral("M");
        const QString CALC = QStringLiteral("CALC");

        const QString SYSTPrefix = SYST + Colon;
        const QString MEASPrefix = MEAS + Colon;
        const QString CALCPrefix = CALC + Colon;
        const unsigned short Timeout500Inms = 500;
        const unsigned short StandardTimeoutInms = 200;
        //Commands
        const QString SystBEEP = SYSTPrefix + QStringLiteral("BEEP");
        //CR is optional but any parameters must be separated by a space.
        const QString MeasSingleValue = MEAS + Question + CR + LF;
        const QString MSingleValue = M + CR + LF;

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

        bool W_G_Emr300::MeasureSingleValue(qreal &fieldStrength) {
            bool returnValue = false;
            QByteArray numericPartData;

            ResetForNewMessage();
            serPort->setRxMessageTimeout(Timeout500Inms);
            fieldStrength = NullQRealValue;
            lastCommand = false ? MeasSingleValue : MSingleValue;
            bool convertionOK = false;

            lastReply = serPort->SendSerialBytes(lastCommand.toUtf8(), hasTimedOut, busy, CassSerial::TerminationType::terminationByte, LF.unicode());
            if (!busy && CheckEndCharacters(CRLF, lastReply, numericPartData) && !hasTimedOut) {
                fieldStrength = numericPartData.toDouble(&convertionOK);
                if (convertionOK) {
                    returnValue = true;
                } else {
                    fieldStrength = NullQRealValue;
                }
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


        //Handlers
        void W_G_Emr300::handleNewSerialError(QSerialPort::SerialPortError newError) {
            QString newText = Cass::SerialIO::CassSerial::SerialMessage(newError);
            lastErrorText = newText;
            emit probeNewError(newError);
        }
    }
}
