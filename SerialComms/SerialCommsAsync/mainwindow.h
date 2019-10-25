#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMetaEnum>
#include <cassserial.h>
#include <narda_ep600.h>
#include <w_g_emr300.h>
#include <cass_controller.h>
#include <controllerstat.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();

    void on_lstSerialPorts_itemSelectionChanged();

    void handleNewSerialData(QByteArray newData, bool fromTimeOut);

    void handleNewSerialError(QSerialPort::SerialPortError newError);

    void on_btnSentIt_clicked();

    //Narda
    void handleNewNardaSerialError(QSerialPort::SerialPortError newError);

    void on_btnNardaVersion_clicked();

    void on_btnNardaTakeReading_clicked();

    void on_btnNardaCalibration_clicked();

    void on_btnNardaSerialNumber_clicked();

    void on_btnNardaBatteryVoltage_clicked();

    void on_btnNardaTemperature_clicked();

    void on_btnNardaThreeAxes_clicked();

    void on_btnNardaSetPowerOffTime_clicked();

    void on_btnNardaPowerOff_clicked();

    //W & G
    void handleNewWGSerialError(QSerialPort::SerialPortError newError);

    void on_btnWGQueryVersion_clicked();

    void on_btnWGQueryBatteryOK_clicked();

    void on_btnWGQueryField_clicked();

    void on_btnWGQueryCmdError_clicked();

    void on_btnWGBeep_clicked();

    void on_btnWGQueryFastMode_clicked();

    void on_btnWGToggleFastMode_clicked();

    void on_btnWGQueryCalcAxis_clicked();

    void on_btnWGToggleCalcAxis_clicked();

    //Cass Controller

    void on_btnCCQueryStatus_clicked();

    void on_btnCCSetReset_clicked();

    void on_btnCCSetDigitalOP_clicked();

    void on_btnCCSetAnIPOn_clicked();

    void on_btnCCSetAnIPOff_clicked();

    void on_btnCCSetDAAnIP_clicked();

    void on_btnCCSetAnOPSweepTime_clicked();

    void on_btnCCSetAnIPScanTime_clicked();

    void on_btnCCSetBaudRate_clicked();

    void on_btnCCSetAnOPOn_clicked();

    void on_btnCCSetAnOPOff_clicked();

    void on_btnCCSetLoadOPSweep_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray readData;
    bool fastMode;
    bool convertOK;
    Cass::SerialIO::W_G_Emr300::CalcFieldAxes calcAxes;

    Cass::SerialIO::CassSerial *serPort;
    Cass::SerialIO::Narda_EP600 *nardaProbe;
    Cass::SerialIO::W_G_Emr300 *wgProbe;
    Cass::SerialIO::Cass_Controller *cassController;

    void CloseSerial();

    void ShowDebugString(QString newDebug);
    void ShowLastReply(QString lastReply);

    void CheckForBusyError(QString errorText);

    QString CommandErrorEnumToString(int value);
    QString CalcAxesToString(int value);
    void ToggleCalcAxes(Cass::SerialIO::W_G_Emr300::CalcFieldAxes &theAxis);

};

#endif // MAINWINDOW_H
