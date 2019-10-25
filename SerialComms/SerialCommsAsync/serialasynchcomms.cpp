#include "serialasynchcomms.h"

namespace Cass {
    namespace SerialIO
    {
        //Constructors
        SerialAsynchComms::SerialAsynchComms(QObject *parent, QString portName, QSerialPort::BaudRate speed)
        {
            serialParent = parent;
            hardwareHandshake = false;
            rxMessageTimeout = 0;
            portNameToUse = portName;
            speedToUse = speed;
            serialPortInUse = nullptr;
            lastError = QSerialPort::NoError;
        }

        //Destructors
        SerialAsynchComms::~SerialAsynchComms()
        {
            CloseSerial();
        }

        //Public
        QString SerialAsynchComms::getPortName() {
            return portNameToUse;
        }
        void SerialAsynchComms::setPortName(QString value) {
           portNameToUse = value;
        }

        bool SerialAsynchComms::getHardwareHandshake() {
            return hardwareHandshake;
        }
        void SerialAsynchComms::setHardwareHandshake(bool value) {
           hardwareHandshake = value;
        }

        unsigned short SerialAsynchComms::getRxMessageTimeout() {
            return rxMessageTimeout;
        }
        void SerialAsynchComms::setRxMessageTimeout(unsigned short value) {
           rxMessageTimeout = value;
        }

        QSerialPort::SerialPortError SerialAsynchComms::getLastError() {
            return lastError;
        }

        bool SerialAsynchComms::OpenPort() {
            bool returnValue = false;
            QSerialPort sp;

            serialPortInUse = new QSerialPort(portNameToUse);
            serialPortInUse->setParent(serialParent);
            //Connect signals up
            QObject::connect(serialPortInUse, &QSerialPort::readyRead, this, &SerialAsynchComms::handleReadyRead);
            QObject::connect(serialPortInUse, &QSerialPort::errorOccurred, this, &SerialAsynchComms::handleError);
            QObject::connect(&rxTimer, &QTimer::timeout, this, &SerialAsynchComms::handleRxMessageTimeout);

            serialPortInUse->setBaudRate(speedToUse);
            serialPortInUse->setDataBits(QSerialPort::Data8);
            serialPortInUse->setParity(QSerialPort::NoParity);
            serialPortInUse->setStopBits(QSerialPort::OneStop);
            serialPortInUse->setFlowControl(hardwareHandshake ? QSerialPort::HardwareControl : QSerialPort::NoFlowControl);

            //Timers
            if (rxMessageTimeout != 0) {
                rxTimer.setSingleShot(false);
                rxTimer.setInterval(rxMessageTimeout);
                readData.clear();
            }

            if (serialPortInUse->open(QSerialPort::ReadWrite)) {
                if (hardwareHandshake) {
                    serialPortInUse->setDataTerminalReady(true);
                }
                returnValue = true;
            }
            else {
                lastError = serialPortInUse->error();
            }

            return returnValue;
        }

        void SerialAsynchComms::ClosePort() {
            CloseSerial();
        }

        void SerialAsynchComms::CloseSerial()
        {
            if (serialPortInUse != nullptr) {
                if (serialPortInUse->isOpen()) {
                    serialPortInUse->flush();
                    serialPortInUse->close();
                }
                delete serialPortInUse;
                serialPortInUse = nullptr;
            }
        }

        void SerialAsynchComms::SendSerialBytes(QByteArray dataTx)
        {
            if (serialPortInUse != nullptr) {
                if (serialPortInUse->isOpen()) {
                    readData.clear();
                    StartRxMessageTimer();
                    serialPortInUse->write(dataTx);
                }
            }
        }

        QString SerialAsynchComms::SerialMessage(QSerialPort::SerialPortError serialCode) {

            QString returnMsg;

            switch (serialCode) {

            case QSerialPort::NoError:
                returnMsg = "No error occurred";
                break;
            case QSerialPort::DeviceNotFoundError:
                returnMsg = "An error occurred while attempting to open an non-existing device";
                break;
            case QSerialPort::PermissionError:
                returnMsg = "An error occurred while attempting to open an already opened device by another process or a user not having enough permission and credentials to open";
                break;
            case QSerialPort::OpenError:
                returnMsg = "An error occurred while attempting to open an already opened device by another process or a user not having enough permission and credentials to open";
                break;
            case QSerialPort::NotOpenError:
                returnMsg = "This error occurs when an operation is executed that can only be successfully performed if the device is open";
                break;
            case QSerialPort::ParityError:
                returnMsg = "Parity error detected by the hardware while reading data";
                break;
            case QSerialPort::FramingError:
                returnMsg = "Framing error detected by the hardware while reading data";
                break;
            case QSerialPort::BreakConditionError:
                returnMsg = "Break condition detected by the hardware on the input line";
                break;
            case QSerialPort::WriteError:
                returnMsg = "An I/O error occurred while writing the data";
                break;
            case QSerialPort::ReadError:
                returnMsg = "An I/O error occurred while reading the data";
                break;
            case QSerialPort::ResourceError:
                returnMsg = "An I/O error occurred when a resource becomes unavailable, e.g. when the device is unexpectedly removed from the system";
                break;
            case QSerialPort::UnsupportedOperationError:
                returnMsg = "The requested device operation is not supported or prohibited by the running operating system";
                break;
            case QSerialPort::TimeoutError:
                returnMsg = "A timeout error occurred. This value was introduced in QtSerialPort 5.2";
                break;
            case QSerialPort::UnknownError:
                returnMsg = "An unidentified error occurred";
                break;
            default:
                returnMsg = QString("Uncoded value %1").arg(serialCode);
                break;
            }

            return returnMsg;
        }

        //Private
        void SerialAsynchComms::StartRxMessageTimer() {
            if (!rxTimer.isActive()) {
                //Restart
                rxTimer.start();
            }
        }

        //Handlers
        void SerialAsynchComms::handleReadyRead()
        {
            QByteArray receivedBytes;

            receivedBytes = serialPortInUse->readAll();

            if (rxMessageTimeout != 0) {
                StartRxMessageTimer();
                readData.append(receivedBytes);
            }
            else {
                //Immediate data
                emit(serialDataRx(receivedBytes));
            }
        }

        void SerialAsynchComms::handleError(QSerialPort::SerialPortError serialPortError)
        {
            if (serialPortError != QSerialPort::NoError) {
                emit serialNewError(serialPortError);
            }
        }

        void SerialAsynchComms::handleRxMessageTimeout() {
            if (rxMessageTimeout != 0) {
                rxTimer.stop();
                emit(serialDataRx(readData));
                readData.clear();
            }
         }
    }
}


