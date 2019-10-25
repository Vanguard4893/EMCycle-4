#include "cassserial.h"

namespace Cass {
    namespace SerialIO
    {
        //Constructors
        CassSerial::CassSerial(QObject *parent, QString portName, QSerialPort::BaudRate speed)
        {
            serialParent = parent;
            flowControl = QSerialPort::NoFlowControl;
            rxMessageTimeout = 0;
            rxMessageTerminationType = TerminationType::defaultToTimeout;
            rxMessageTerminationValue = 0;
            portNameToUse = portName;
            speedToUse = speed;
            serialPortInUse = nullptr;
            lastError = QSerialPort::NoError;
            rxTimedOut = false;
        }

        //Destructors
        CassSerial::~CassSerial()
        {
            CloseSerial();
        }
        //Public
        QString CassSerial::getPortName() const {
            return portNameToUse;
        }
        void CassSerial::setPortName(QString value) {
           portNameToUse = value;
        }

        QSerialPort::FlowControl CassSerial::getFlowControl() const {
            return flowControl;
        }
        void CassSerial::setFlowControl(QSerialPort::FlowControl value) {
           flowControl = value;
        }

        unsigned short CassSerial::getRxMessageTimeout() const {
            return rxMessageTimeout;
        }
        void CassSerial::setRxMessageTimeout(unsigned short value) {
           rxMessageTimeout = value;
           rxTimer.setInterval(rxMessageTimeout);
        }

        Cass::SerialIO::CassSerial::TerminationType CassSerial::getRxMessageTerminationType() const {
            return rxMessageTerminationType;
        }

        unsigned short CassSerial::getRxMessageTerminationValue() const {
            return rxMessageTerminationValue;
        }

        QSerialPort::SerialPortError CassSerial::getLastError() const {
            return lastError;
        }

        bool CassSerial::OpenPort() {
            bool returnValue = false;
            QSerialPort sp;

            serialPortInUse = new QSerialPort(portNameToUse);
            serialPortInUse->setParent(serialParent);
            //Connect signals up
            QObject::connect(serialPortInUse, &QSerialPort::readyRead, this, &CassSerial::handleReadyRead);
            QObject::connect(serialPortInUse, &QSerialPort::errorOccurred, this, &CassSerial::handleError);
            QObject::connect(serialPortInUse, &QSerialPort::bytesWritten, this, &CassSerial::handleTxMessageComplete);
            QObject::connect(&rxTimer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
            QObject::connect(this, &CassSerial::serialRxAllDataReceivedOrAllTxSent, &eventLoop, &QEventLoop::quit);

            serialPortInUse->setBaudRate(speedToUse);
            serialPortInUse->setDataBits(QSerialPort::Data8);
            serialPortInUse->setParity(QSerialPort::NoParity);
            serialPortInUse->setStopBits(QSerialPort::OneStop);
            serialPortInUse->setFlowControl(flowControl);

            //Timers
            if (rxMessageTimeout != 0) {
                rxTimer.setSingleShot(false);
                rxTimer.setInterval(rxMessageTimeout);
                readData.clear();
            }

            if (serialPortInUse->open(QSerialPort::ReadWrite)) {
                if (flowControl) {
                    serialPortInUse->setDataTerminalReady(true);
                }
                returnValue = true;
            }
            else {
                lastError = serialPortInUse->error();
            }

            return returnValue;
        }

        void CassSerial::ClosePort() {
            CloseSerial();
        }

        void CassSerial::CloseSerial() {
            if (serialPortInUse != nullptr) {
                if (serialPortInUse->isOpen()) {
                    serialPortInUse->flush();
                    serialPortInUse->close();
                }
                delete serialPortInUse;
                serialPortInUse = nullptr;
            }
        }

        bool CassSerial::ClearRxPort() const {
            bool returnValue = false;

            if (serialPortInUse != nullptr) {
                if (serialPortInUse->isOpen()) {
                    serialPortInUse->clear(QSerialPort::Input);
                    returnValue = true;
                }
            }

            return returnValue;
        }

        QByteArray CassSerial::SendSerialBytes(QByteArray dataTx, bool &rxHasTimedOut, bool &busy, TerminationType messageTerminationMethod, unsigned short terminationMatchValue)
        {
            QByteArray returnedData = nullptr;
            //By default true
            rxTimedOut = true;
            busy = false;
            rxMessageTerminationType = messageTerminationMethod;
            rxMessageTerminationValue = terminationMatchValue;

            if (serialPortInUse != nullptr) {
                if (serialPortInUse->isOpen()) {
                    if (!eventLoop.isRunning()) {
                        readData.clear();
                        StartRxMessageTimer();
                        serialPortInUse->write(dataTx);
                        eventLoop.exec();
                        //We get here either by timeout, the correct byte count, or the right termination byte.
                        handleRxMessageTimeout();
                        emit(serialDataRx(readData, rxTimedOut));
                        returnedData = readData;
                    } else {
                        busy = true;
                    }
                }
            }
            rxHasTimedOut = rxTimedOut;
            return returnedData;
        }

        QString CassSerial::SerialMessage(QSerialPort::SerialPortError serialCode) {

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
        void CassSerial::UpdateRxMessageTimer() {
            if (!rxTimer.isActive()) {
                //Restart
                rxTimer.start();
            }
        }

        void CassSerial::StartRxMessageTimer() {
            rxTimer.start();
        }

        //Handlers
        void CassSerial::handleReadyRead()
        {
            QByteArray receivedBytes;

            receivedBytes = serialPortInUse->readAll();

            if (rxMessageTimeout != 0) {
                UpdateRxMessageTimer();
                readData.append(receivedBytes);
                //Check for byte count
                switch (rxMessageTerminationType) {
                case TerminationType::byteCount:
                    if (rxMessageTerminationValue && readData.count() == rxMessageTerminationValue) {
                        rxTimedOut = false;
                        emit(serialRxAllDataReceivedOrAllTxSent());
                    }
                    break;
                case TerminationType::terminationByte:
                    if (rxMessageTerminationValue && readData.endsWith(static_cast<char>(rxMessageTerminationValue))) {
                        rxTimedOut = false;
                        emit(serialRxAllDataReceivedOrAllTxSent());
                    }
                    break;
                case TerminationType::defaultToTimeout:
                        //Ignore
                    break;
                default:
                    break;
                }
                if (rxMessageTerminationType == TerminationType::byteCount && readData.count() == rxMessageTerminationValue) {
                    rxTimedOut = false;
                    emit(serialRxAllDataReceivedOrAllTxSent());
                }
            }
            else {
                //Immediate data
                emit(serialDataRx(receivedBytes, false));
            }
        }

        void CassSerial::handleError(QSerialPort::SerialPortError serialPortError)
        {
            if (serialPortError != QSerialPort::NoError) {
                emit serialNewError(serialPortError);
            }
        }

        void CassSerial::handleRxMessageTimeout() {
            if (rxMessageTimeout != 0) {
                rxTimer.stop();
            }
        }

        void CassSerial::handleTxMessageComplete()
        {
            //Check for byte count
            switch (rxMessageTerminationType) {
            case TerminationType::onMessageSent:
                rxTimedOut = false;
                emit(serialRxAllDataReceivedOrAllTxSent());
                break;
            default:
                break;
            }
        }
    }
}
