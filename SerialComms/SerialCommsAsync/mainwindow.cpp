#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnStart->setEnabled(false);
    ui->lblStatus->setText("Select Port and then press Start");

    ui->lneDataDecValue->setClearButtonEnabled(true);

    serPort = nullptr;
    nardaProbe = nullptr;
    wgProbe = nullptr;

    fastMode = false;
    calcAxes = Cass::SerialIO::W_G_Emr300::CalcFieldAxes::Undefined;
    convertOK = false;

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            ui->lstSerialPorts->addItem(info.portName());
        }
}

MainWindow::~MainWindow()
{
    CloseSerial();
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    QListWidgetItem *qlwi;
    qlwi = ui->lstSerialPorts->currentItem();

    serPort = new Cass::SerialIO::CassSerial(this, qlwi->text(), QSerialPort::Baud9600);
    //nardaProbe = new Cass::SerialIO::Narda_EP600(this, qlwi->text());
    //wgProbe = new Cass::SerialIO::W_G_Emr300(this, qlwi->text());
    cassController = new Cass::SerialIO::Cass_Controller(this, qlwi->text());

    //QT 5 syntax not SLOTS()...
    connect(serPort, &Cass::SerialIO::CassSerial::serialDataRx, this, &MainWindow::handleNewSerialData);
    connect(serPort, &Cass::SerialIO::CassSerial::serialNewError, this, &MainWindow::handleNewSerialError);

    //connect(nardaProbe, &Cass::SerialIO::Narda_EP600::probeNewError, this, &MainWindow::handleNewNardaSerialError);
    //connect(wgProbe, &Cass::SerialIO::W_G_Emr300::probeNewError, this, &MainWindow::handleNewWGSerialError);
    connect(cassController, &Cass::SerialIO::Cass_Controller::probeNewError, this, &MainWindow::handleNewWGSerialError);



// //    serPort->setBaudRate(QSerialPort::Baud9600);
// //    serPort->setDataBits(QSerialPort::Data8);
// //    serPort->setParity(QSerialPort::NoParity);
    serPort->setFlowControl(QSerialPort::NoFlowControl);
//    serPort->setFlowControl(QSerialPort::HardwareControl);
    serPort->setRxMessageTimeout(8000);
    //serPort->setRxMessageTimeout(0);

//    if (serPort->OpenPort()) {
//        ui->lblStatus->setText("SP Open");
//    }
//    else {
//        ui->lblStatus->setText(Cass::SerialIO::CassSerial::SerialMessage(serPort->getLastError()));
//    }



//    if (nardaProbe->OpenPort()) {
//        ui->lblStatus->setText("Narda Open");
//    }
//    else {
//        ui->lblStatus->setText(nardaProbe->getLastErrorText());
//    }

//    if (wgProbe->OpenPort()) {
//        ui->lblStatus->setText("W&G Open");
//    }
//    else {
//        ui->lblStatus->setText(wgProbe->getLastErrorText());
//    }

    if (cassController->OpenPort()) {
        ui->lblStatus->setText("Cass Controller Open");
    }
    else {
        ui->lblStatus->setText(cassController->getLastErrorText());
    }

}

//Handlers
void MainWindow::handleNewSerialData(QByteArray newData, bool fromTimeOut) {
    /*
    QString newSize;
    QListWidgetItem* lastItem;

    newSize = QString("bytes : %1 timeout : %2").arg(newData.length()).arg(fromTimeOut);

    ui->lstReceived->addItem(newSize);
    lastItem = new QListWidgetItem(QString(newData));
    ui->lstReceived->addItem(lastItem);
    ui->lstReceived->setCurrentItem(lastItem);
    */
}

void MainWindow::handleNewSerialError(QSerialPort::SerialPortError newError) {
    QString newText = Cass::SerialIO::CassSerial::SerialMessage(newError);
    ui->lblStatus->setText(QString("Comms Error: %1").arg(newText));
}

void MainWindow::on_lstSerialPorts_itemSelectionChanged()
{
    CloseSerial();
    ui->btnStart->setEnabled(true);
}

void MainWindow::CloseSerial()
{
    if (serPort != nullptr) {
        serPort->ClosePort();
        delete serPort;
        serPort = nullptr;
    }

    if (nardaProbe != nullptr) {
        nardaProbe->ClosePort();
        delete nardaProbe;
        nardaProbe = nullptr;
    }

    if (wgProbe != nullptr) {
        wgProbe->ClosePort();
        delete wgProbe;
        wgProbe = nullptr;
    }
}

void MainWindow::ShowDebugString(QString newDebug) {
    QListWidgetItem* lastItem;

    lastItem = new QListWidgetItem(QString(newDebug));
    ui->lstReceived->addItem(lastItem);
    ui->lstReceived->setCurrentItem(lastItem);
}

void MainWindow::ShowLastReply(QString lastReply) {
    ui->lblLastReplyTxt->setText(lastReply);
}

void MainWindow::CheckForBusyError(QString errorText) {
    if (nardaProbe != nullptr) {
        if (nardaProbe->getBusy()) {
            ShowDebugString("BUSY");
        } else {
            ShowDebugString(errorText);
        }
    }

    if (wgProbe != nullptr) {
        if (wgProbe->getBusy()) {
            ShowDebugString("BUSY");
        } else {
            ShowDebugString(errorText);
        }
    }

}

void MainWindow::on_btnSentIt_clicked()
{
    QString newSize;
    QByteArray asBytes = ui->lneTxText->text().toUtf8();
    QByteArray rxData;
    bool wasTimeout;
    bool busy;

    if (serPort != nullptr) {
        rxData = serPort->SendSerialBytes(asBytes, wasTimeout, busy, Cass::SerialIO::CassSerial::TerminationType::byteCount, 3);
        newSize = QString("bytes : %1 timeout : %2").arg(rxData.length()).arg(wasTimeout);
        ShowDebugString(newSize);
        ShowDebugString(QString(rxData));
    }
}

//Narda
void MainWindow::handleNewNardaSerialError(QSerialPort::SerialPortError newError) {
    QString newText = Cass::SerialIO::CassSerial::SerialMessage(newError);
    ui->lblStatus->setText(QString("Narda Comms Error: %1").arg(newText));
}

void MainWindow::on_btnNardaVersion_clicked()
{
    QString version;

    if (nardaProbe->QueryVersion(version)) {
        ShowDebugString(version);
    } else {
        CheckForBusyError("btnNardaVersion FAIL");
    }
}

void MainWindow::on_btnNardaTakeReading_clicked()
{
    qreal fieldStrength;

    if (nardaProbe->QueryTakeReading(fieldStrength)) {
        ShowDebugString(QString::number(fieldStrength));
    } else {
        CheckForBusyError("btnNardaTakeReading FAIL");
    }
}

void MainWindow::on_btnNardaCalibration_clicked()
{
    QString calDate;

    if (nardaProbe->QueryCalibrationDate(calDate)) {
        ShowDebugString(calDate);
    } else {
        CheckForBusyError("btnNardaCalibration FAIL");
    }
}

void MainWindow::on_btnNardaSerialNumber_clicked()
{
    QString serialNumber;

    if (nardaProbe->QuerySerialNumber(serialNumber)) {
        ShowDebugString(serialNumber);
    } else {
        CheckForBusyError("btnNardaSerialNumber FAIL");
    }
}

void MainWindow::on_btnNardaBatteryVoltage_clicked()
{
    qreal batteryVoltage;

    if (nardaProbe->QueryBatteryVoltage(batteryVoltage)) {
        ShowDebugString(QString::number(batteryVoltage));
    } else {
        CheckForBusyError("btnNardaBatteryVoltage FAIL");
    }
}

void MainWindow::on_btnNardaTemperature_clicked()
{
    qreal tempInC;

    if (nardaProbe->QueryTemperatureC(tempInC)) {
        ShowDebugString(QString::number(tempInC));
    } else {
        CheckForBusyError("btnNardaTemperature FAIL");
    }
}

void MainWindow::on_btnNardaThreeAxes_clicked()
{
    qreal fX, fY, fZ;

    if (nardaProbe->QueryThreeAxesFields(fX, fY, fZ)) {
        ShowDebugString(QString("X:%1 Y:%2 Z:%3").arg(fX).arg(fY).arg(fZ));
    } else {
        CheckForBusyError("btnNardaThreeAxes FAIL");
    }
}

void MainWindow::on_btnNardaSetPowerOffTime_clicked()
{
    unsigned short inSeconds = ui->lneTxText->text().toUShort();
    if (nardaProbe->SetProbePowerOffTimeIns(inSeconds)) {
        ShowDebugString(QString("Power Off In :%1 s").arg(inSeconds));
    } else {
        CheckForBusyError("btnNardaSetPowerOffTime FAIL");
    }
}

void MainWindow::on_btnNardaPowerOff_clicked()
{
    if (nardaProbe->SetProbePowerOff()) {
        ShowDebugString(QString("Power Off!"));
    } else {
        CheckForBusyError("btnNardaPowerOff FAIL");
    }
}

//W & G
void MainWindow::handleNewWGSerialError(QSerialPort::SerialPortError newError) {
    QString newText = Cass::SerialIO::CassSerial::SerialMessage(newError);
    ui->lblStatus->setText(QString("WG Comms Error: %1").arg(newText));
}

void MainWindow::on_btnWGQueryVersion_clicked()
{
    QString WGversion;

    if (wgProbe->QueryVersion(WGversion)) {
        ShowDebugString(QString("Version:%1").arg(WGversion));
    } else {
        CheckForBusyError("btnWGQueryVersion FAIL");
    }
}

void MainWindow::on_btnWGQueryBatteryOK_clicked()
{
    bool BattOK;

    if (wgProbe->QueryBatteryVoltage(BattOK)) {
        ShowDebugString(QString("Battery OK:%1").arg(BattOK));
    } else {
        CheckForBusyError("btnWGQueryBatteryOK FAIL");
    }
}

void MainWindow::on_btnWGQueryField_clicked()
{
    bool threeValues;
    qreal fieldStrengthX;
    qreal fieldStrengthY;
    qreal fieldStrengthZ;

    if (wgProbe->QuerySingleOrThreeValues(threeValues, fieldStrengthX, fieldStrengthY, fieldStrengthZ)) {
        ShowDebugString(QString("Three %1 X:%2 Y:%3 Z:%4").arg(threeValues).arg(fieldStrengthX).arg(fieldStrengthY).arg(fieldStrengthZ));
    } else {
        CheckForBusyError("btnWGMeasureSingle FAIL");
    }
}

void MainWindow::on_btnWGQueryCmdError_clicked()
{
    Cass::SerialIO::W_G_Emr300::CommandError commandError;

    if (wgProbe->QueryCommandError(commandError)) {
        ShowDebugString(QString("Cmd:%1").arg(CommandErrorEnumToString(static_cast<int>(commandError))));
    } else {
        CheckForBusyError("btnWGQueryCmdError FAIL");
    }
}

void MainWindow::on_btnWGBeep_clicked()
{
    if (wgProbe->SetBeep()) {
        ShowDebugString(QString("Beeped"));
    } else {
        CheckForBusyError("btnWGBeep FAIL");
    }
}

void MainWindow::on_btnWGQueryFastMode_clicked()
{
    if (wgProbe->QueryFastMode(fastMode)) {
        ShowDebugString(QString("Fast Mode:%1").arg(fastMode));
    } else {
        CheckForBusyError("btnWGQueryFastMode FAIL");
    }
}

void MainWindow::on_btnWGToggleFastMode_clicked()
{
    fastMode = !fastMode;
    if (wgProbe->SetFastMode(fastMode)) {
        ShowDebugString(QString("Fast Mode set to:%1").arg(fastMode));
    } else {
        CheckForBusyError("btnWGToggleFastMode FAIL");
    }
}

void MainWindow::on_btnWGQueryCalcAxis_clicked()
{
    if (wgProbe->QueryCalcAxis(calcAxes)) {
        ShowDebugString(QString("Calc Axes:%1").arg(CalcAxesToString(static_cast<int>(calcAxes))));
    } else {
        CheckForBusyError("btnWGQueryCalcAxis FAIL");
    }
}

void MainWindow::on_btnWGToggleCalcAxis_clicked()
{
    ToggleCalcAxes(calcAxes);
    if (wgProbe->SetCalcAxis(calcAxes)) {
        ShowDebugString(QString("++Calc Axes:%1").arg(CalcAxesToString(static_cast<int>(calcAxes))));
    } else {
        CheckForBusyError("btnWGToggleCalcAxis FAIL");
    }
}

QString MainWindow::CommandErrorEnumToString(int value)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<Cass::SerialIO::W_G_Emr300::CommandError>();
    return QLatin1String(metaEnum.valueToKey(value));
}

QString MainWindow::CalcAxesToString(int value)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<Cass::SerialIO::W_G_Emr300::CalcFieldAxes>();
    return QLatin1String(metaEnum.valueToKey(value));
}

void MainWindow::ToggleCalcAxes(Cass::SerialIO::W_G_Emr300::CalcFieldAxes &theAxis) {
    switch (theAxis) {
        case Cass::SerialIO::W_G_Emr300::CalcFieldAxes::Undefined:
            theAxis = Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispTotalSerialXYZ_ALL;
        break;
        case Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispTotalSerialXYZ_ALL:
            theAxis = Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispTotalSerialTotal_EFF;
        break;
        case Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispTotalSerialTotal_EFF:
            theAxis = Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispXSerialX_X;
        break;
        case Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispXSerialX_X:
            theAxis = Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispYSerialY_Y;
        break;
        case Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispYSerialY_Y:
            theAxis = Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispZSerialZ_Z;
        break;
        case Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispZSerialZ_Z:
            theAxis = Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispTotalSerialXYZ_ALL;
        break;
    }
}

void MainWindow::on_btnCCQueryStatus_clicked()
{
    Cass::SerialIO::ControllerSTAT STAT;

    if (cassController->QueryAllStatus(&STAT)) {
        ShowLastReply(cassController->getLastReply());
        ShowDebugString(QString("STAT IPStatus %1 "
                                "\nDI1:%2 DI2:%3 DI3:%4 DI4:%5 "
                                "\nAn0:%6 An1:%7 An2:%8 An3:%9 An4:%10 "
                                "\nIPSRate:%11 "
                                "\nAnIP0:%12 AnIP1:%13 AnIP2:%14 AnIP3:%15 AnIP4:%16 "
                                "\nANA1:%17 ANA2:%18 RLY1:%19 RLY2:%20 OC1:%21 OC2:%22 "
                                "\nOPSWT:%23 "
                                "\nErrorCode:%24 "
                                "\nCSum:%25")

                        .arg(STAT.GetSelectInputStatus())
                        //DI
                        .arg(STAT.GetDI1()).arg(STAT.GetDI2())
                        .arg(STAT.GetDI3()).arg(STAT.GetDI4())
                        //AN IPs 4-1
                        .arg(STAT.GetAnIP0Enabled()).arg(STAT.GetAnIP1Enabled()).arg(STAT.GetAnIP2Enabled()).arg(STAT.GetAnIP3Enabled()).arg(STAT.GetAnIP4Enabled())
                        //ISR
                        .arg(STAT.GetInputScanRate())
                        //Analogues
                        .arg(STAT.GetAnIP0()).arg(STAT.GetAnIP1()).arg(STAT.GetAnIP2()).arg(STAT.GetAnIP3()).arg(STAT.GetAnIP4())
                        //Outputs
                        .arg(STAT.GetAnOP1Active()).arg(STAT.GetAnOP2Active()).arg(STAT.GetRelayOP1Active()).arg(STAT.GetRelayOP2Active()).arg(STAT.GetOcOP1Active()).arg(STAT.GetOcOP2Active())
                        //OPSWT
                        .arg(STAT.GetOutputSweepTime())
                        //Error
                        .arg(STAT.GetErrorCode())
                        //CSUM
                        .arg(STAT.GetChecksum())
                        );
    } else {
        CheckForBusyError("btnCCQueryStatus FAIL");
    }
}

void MainWindow::on_btnCCSetReset_clicked()
{
    if (cassController->SetReset()) {
        ShowLastReply(cassController->getLastReply());
        ShowDebugString(QString("Reset"));
    } else {
        CheckForBusyError("btnCCSetReset FAIL");
    }
}

void MainWindow::on_btnCCSetDigitalOP_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 valueByte = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetDigitalOutput(valueByte)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Digital OP %1").arg(valueByte));
            } else {
                CheckForBusyError("btnCCSetDigitalOP FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetAnIPOn_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 portByte = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetAnalogueInputON(portByte)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Analogue IP ON %1").arg(portByte));
            } else {
                CheckForBusyError("btnCCSetAnIPOn FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetAnIPOff_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 portByte = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetAnalogueInputOFF(portByte)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Analogue IP OFF %1").arg(portByte));
            } else {
                CheckForBusyError("btnCCSetAnIPOff FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetDAAnIP_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 portByte = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetSelectAnalogueInputForDA(portByte)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("D/A Analogue IP %1").arg(portByte));
            } else {
                CheckForBusyError("btnCCSetDAAnIP FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetAnOPSweepTime_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 theTime = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetAnalogueOutputSweepTime(theTime)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Analogue O/P Sweep Time %1").arg(theTime));
            } else {
                CheckForBusyError("btnCCSetAnOPSweepTime FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetAnIPScanTime_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 theTime = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetAnalogueInputOFF(theTime)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Analogue IP Scan Time %1").arg(theTime));
            } else {
                CheckForBusyError("btnCCSetAnIPScanTime FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetBaudRate_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 theBaud = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetBaudRate(theBaud)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Baud Rate %1").arg(theBaud));
            } else {
                CheckForBusyError("btnCCSetBaudRate FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetAnOPOn_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 portByte = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetAnalogueInputON(portByte)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Analogue OP %1 ON").arg(portByte));
            } else {
                CheckForBusyError("btnCCSetAnOPOn FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetAnOPOff_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 portByte = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            if (cassController->SetAnalogueInputOFF(portByte)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Analogue OP %1 OFF").arg(portByte));
            } else {
                CheckForBusyError("btnCCSetAnOPOff FAIL");
            }
        }
    }
}

void MainWindow::on_btnCCSetLoadOPSweep_clicked()
{
    if (ui->lneDataDecValue->text().length() > 0) {
        quint8 theOutput = static_cast<quint8>(ui->lneDataDecValue->text().toUShort(&convertOK));
        if (convertOK) {
            QByteArray sampleData = QByteArrayLiteral(
                        "\x00\x04\x08\x0C\x10\x14\x18\x1C"
                        "\x20\x24\x28\x2C\x30\x34\x38\x3C"
                        "\x40\x44\x48\x4C\x50\x54\x58\x5C"
                        "\x60\x64\x68\x6C\x70\x74\x78\x7C"
                        "\x80\x84\x88\x8C\x90\x94\x98\x9C"
                        "\xA0\xA4\xA8\xAC\xB0\xB4\xB8\xBC"
                        "\xC0\xC4\xC8\xCC\xD0\xD4\xD8\xDC"
                        "\xE0\xE4\xE8\xEC\xF0\xF4\xF8\xFC"
                        "\x00\x04\x08\x0C\x10\x14\x18\x1C"
                        "\x20\x24\x28\x2C\x30\x34\x38\x3C"
                        );

            if (cassController->SetLoadOutputSweep(theOutput, sampleData)) {
                ShowLastReply(cassController->getLastReply());
                ShowDebugString(QString("Load OP SWEEP %1").arg(theOutput));
            } else {
                CheckForBusyError("btnCCSetLoadOPSweep FAIL");
            }
        }
    }
}
