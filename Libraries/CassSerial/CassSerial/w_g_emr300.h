#ifndef W_G_EMR300_H
#define W_G_EMR300_H

#include <cassserial.h>
#include <i_serial_probe.h>

namespace Cass {
    namespace SerialIO {
        class W_G_Emr300 : public QObject, public I_Serial_Probe
        {
            Q_OBJECT
        public:
            // Types
            enum class CommandError {Undefined = 1, NoError = 0, MissingParameter = -109, UnknownCommand = -110, DataOutOfRange = -222, IllegalParameterValue = -224, ModeError = -300};
            Q_ENUM(CommandError)
            enum class CalcFieldAxes {Undefined = 0, DispTotalSerialXYZ_ALL, DispTotalSerialTotal_EFF, DispXSerialX_X, DispYSerialY_Y, DispZSerialZ_Z};
            Q_ENUM(CalcFieldAxes)
            W_G_Emr300(QObject *parent, QString portName);
            bool OpenPort();
            void ClosePort();
            bool QuerySingleOrThreeValues(bool &threeValues, qreal &fieldX, qreal &fieldY, qreal &fieldZ);
            bool QueryVersion(QString &version);
            bool QueryBatteryVoltage(bool &batteryOK);
            bool QueryCommandError(CommandError &commandError);
            bool QueryFastMode(bool &fastModeOn);
            bool SetBeep();
            bool SetFastMode(const bool fastModeOn);
            bool QueryCalcAxis(CalcFieldAxes &calculationAxis);
            bool SetCalcAxis(const CalcFieldAxes calculationAxis);
            //Properties
            QString getLastCommand() const;
            QByteArray getLastReply() const;
            QString getLastErrorText() const;
            bool getBusy() const;
            bool getVersion(quint8 &Major, quint8 &Minor) const;

        public:
            ~W_G_Emr300();

        private slots:
            void handleNewSerialError(QSerialPort::SerialPortError newError);

        signals:
            void probeNewError(QSerialPort::SerialPortError serialPortError);

        private:
            QObject *serialParent;
            Cass::SerialIO::CassSerial *serPort;
            QString lastCommand;
            QByteArray lastReply;
            QString lastErrorText;
            bool hasTimedOut;
            bool EndsWithString(const QString &comparisonEnding, QByteArray &theData);
            void ResetForNewMessage();
            bool CheckEndCharacters(QString endExpected, QByteArray theData, QByteArray &modifiedData);
            QString SetON_OFF_CRLF(const QString originalCommand, const bool on);
            QString SetCalcAXIS_CRLF(const QString originalCommand, const CalcFieldAxes axis);
            bool GetCalcAXIS(const QString returnedAxisString, CalcFieldAxes &theCalcAxis);
            bool busy;
        };
    }
}

#endif // W_G_EMR300_H
