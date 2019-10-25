/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnStart;
    QListWidget *lstSerialPorts;
    QLabel *lblStatus;
    QListWidget *lstReceived;
    QPushButton *btnSentIt;
    QLineEdit *lneTxText;
    QPushButton *btnNardaVersion;
    QPushButton *btnNardaTakeReading;
    QPushButton *btnNardaCalibration;
    QPushButton *btnNardaSerialNumber;
    QPushButton *btnNardaBatteryVoltage;
    QPushButton *btnNardaTemperature;
    QPushButton *btnNardaThreeAxes;
    QPushButton *btnNardaSetPowerOffTime;
    QPushButton *btnNardaPowerOff;
    QPushButton *btnWGQueryField;
    QPushButton *btnWGQueryVersion;
    QPushButton *btnWGQueryBatteryOK;
    QPushButton *btnWGQueryCmdError;
    QPushButton *btnWGBeep;
    QPushButton *btnWGQueryFastMode;
    QPushButton *btnWGToggleFastMode;
    QPushButton *btnWGToggleCalcAxis;
    QPushButton *btnWGQueryCalcAxis;
    QPushButton *btnCCQueryStatus;
    QPushButton *btnCCSetReset;
    QLabel *lblLastReply;
    QLabel *lblLastReplyTxt;
    QPushButton *btnCCSetDigitalOP;
    QLineEdit *lneDataDecValue;
    QLabel *lblHexData;
    QPushButton *btnCCSetAnIPOn;
    QPushButton *btnCCSetAnIPOff;
    QPushButton *btnCCSetDAAnIP;
    QPushButton *btnCCSetAnIPScanTime;
    QPushButton *btnCCSetAnOPSweepTime;
    QPushButton *btnCCSetBaudRate;
    QPushButton *btnCCSetAnOPOff;
    QPushButton *btnCCSetAnOPOn;
    QPushButton *btnCCSetLoadOPSweep;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1255, 1039);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(970, 300, 111, 51));
        lstSerialPorts = new QListWidget(centralWidget);
        lstSerialPorts->setObjectName(QString::fromUtf8("lstSerialPorts"));
        lstSerialPorts->setGeometry(QRect(760, 300, 201, 51));
        lblStatus = new QLabel(centralWidget);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setGeometry(QRect(10, 910, 1061, 51));
        lblStatus->setWordWrap(true);
        lstReceived = new QListWidget(centralWidget);
        lstReceived->setObjectName(QString::fromUtf8("lstReceived"));
        lstReceived->setGeometry(QRect(5, 1, 1231, 281));
        QFont font;
        font.setPointSize(12);
        lstReceived->setFont(font);
        btnSentIt = new QPushButton(centralWidget);
        btnSentIt->setObjectName(QString::fromUtf8("btnSentIt"));
        btnSentIt->setGeometry(QRect(970, 360, 111, 71));
        lneTxText = new QLineEdit(centralWidget);
        lneTxText->setObjectName(QString::fromUtf8("lneTxText"));
        lneTxText->setGeometry(QRect(400, 360, 551, 71));
        btnNardaVersion = new QPushButton(centralWidget);
        btnNardaVersion->setObjectName(QString::fromUtf8("btnNardaVersion"));
        btnNardaVersion->setGeometry(QRect(10, 550, 121, 51));
        btnNardaTakeReading = new QPushButton(centralWidget);
        btnNardaTakeReading->setObjectName(QString::fromUtf8("btnNardaTakeReading"));
        btnNardaTakeReading->setGeometry(QRect(140, 550, 121, 51));
        btnNardaCalibration = new QPushButton(centralWidget);
        btnNardaCalibration->setObjectName(QString::fromUtf8("btnNardaCalibration"));
        btnNardaCalibration->setGeometry(QRect(270, 550, 121, 51));
        btnNardaSerialNumber = new QPushButton(centralWidget);
        btnNardaSerialNumber->setObjectName(QString::fromUtf8("btnNardaSerialNumber"));
        btnNardaSerialNumber->setGeometry(QRect(400, 550, 121, 51));
        btnNardaBatteryVoltage = new QPushButton(centralWidget);
        btnNardaBatteryVoltage->setObjectName(QString::fromUtf8("btnNardaBatteryVoltage"));
        btnNardaBatteryVoltage->setGeometry(QRect(530, 550, 121, 51));
        btnNardaTemperature = new QPushButton(centralWidget);
        btnNardaTemperature->setObjectName(QString::fromUtf8("btnNardaTemperature"));
        btnNardaTemperature->setGeometry(QRect(10, 610, 121, 51));
        btnNardaThreeAxes = new QPushButton(centralWidget);
        btnNardaThreeAxes->setObjectName(QString::fromUtf8("btnNardaThreeAxes"));
        btnNardaThreeAxes->setGeometry(QRect(140, 610, 121, 51));
        btnNardaSetPowerOffTime = new QPushButton(centralWidget);
        btnNardaSetPowerOffTime->setObjectName(QString::fromUtf8("btnNardaSetPowerOffTime"));
        btnNardaSetPowerOffTime->setGeometry(QRect(270, 610, 121, 51));
        btnNardaPowerOff = new QPushButton(centralWidget);
        btnNardaPowerOff->setObjectName(QString::fromUtf8("btnNardaPowerOff"));
        btnNardaPowerOff->setGeometry(QRect(400, 610, 121, 51));
        btnWGQueryField = new QPushButton(centralWidget);
        btnWGQueryField->setObjectName(QString::fromUtf8("btnWGQueryField"));
        btnWGQueryField->setGeometry(QRect(10, 670, 121, 51));
        btnWGQueryVersion = new QPushButton(centralWidget);
        btnWGQueryVersion->setObjectName(QString::fromUtf8("btnWGQueryVersion"));
        btnWGQueryVersion->setGeometry(QRect(140, 670, 121, 51));
        btnWGQueryBatteryOK = new QPushButton(centralWidget);
        btnWGQueryBatteryOK->setObjectName(QString::fromUtf8("btnWGQueryBatteryOK"));
        btnWGQueryBatteryOK->setGeometry(QRect(270, 670, 121, 51));
        btnWGQueryCmdError = new QPushButton(centralWidget);
        btnWGQueryCmdError->setObjectName(QString::fromUtf8("btnWGQueryCmdError"));
        btnWGQueryCmdError->setGeometry(QRect(400, 670, 121, 51));
        btnWGBeep = new QPushButton(centralWidget);
        btnWGBeep->setObjectName(QString::fromUtf8("btnWGBeep"));
        btnWGBeep->setGeometry(QRect(530, 670, 121, 51));
        btnWGQueryFastMode = new QPushButton(centralWidget);
        btnWGQueryFastMode->setObjectName(QString::fromUtf8("btnWGQueryFastMode"));
        btnWGQueryFastMode->setGeometry(QRect(10, 730, 121, 51));
        btnWGToggleFastMode = new QPushButton(centralWidget);
        btnWGToggleFastMode->setObjectName(QString::fromUtf8("btnWGToggleFastMode"));
        btnWGToggleFastMode->setGeometry(QRect(140, 730, 121, 51));
        btnWGToggleCalcAxis = new QPushButton(centralWidget);
        btnWGToggleCalcAxis->setObjectName(QString::fromUtf8("btnWGToggleCalcAxis"));
        btnWGToggleCalcAxis->setGeometry(QRect(400, 730, 121, 51));
        btnWGQueryCalcAxis = new QPushButton(centralWidget);
        btnWGQueryCalcAxis->setObjectName(QString::fromUtf8("btnWGQueryCalcAxis"));
        btnWGQueryCalcAxis->setGeometry(QRect(270, 730, 121, 51));
        btnCCQueryStatus = new QPushButton(centralWidget);
        btnCCQueryStatus->setObjectName(QString::fromUtf8("btnCCQueryStatus"));
        btnCCQueryStatus->setGeometry(QRect(10, 790, 121, 51));
        btnCCSetReset = new QPushButton(centralWidget);
        btnCCSetReset->setObjectName(QString::fromUtf8("btnCCSetReset"));
        btnCCSetReset->setGeometry(QRect(10, 850, 121, 51));
        lblLastReply = new QLabel(centralWidget);
        lblLastReply->setObjectName(QString::fromUtf8("lblLastReply"));
        lblLastReply->setGeometry(QRect(20, 460, 111, 41));
        lblLastReplyTxt = new QLabel(centralWidget);
        lblLastReplyTxt->setObjectName(QString::fromUtf8("lblLastReplyTxt"));
        lblLastReplyTxt->setGeometry(QRect(140, 460, 941, 51));
        btnCCSetDigitalOP = new QPushButton(centralWidget);
        btnCCSetDigitalOP->setObjectName(QString::fromUtf8("btnCCSetDigitalOP"));
        btnCCSetDigitalOP->setGeometry(QRect(140, 790, 121, 51));
        lneDataDecValue = new QLineEdit(centralWidget);
        lneDataDecValue->setObjectName(QString::fromUtf8("lneDataDecValue"));
        lneDataDecValue->setGeometry(QRect(950, 540, 141, 71));
        lblHexData = new QLabel(centralWidget);
        lblHexData->setObjectName(QString::fromUtf8("lblHexData"));
        lblHexData->setGeometry(QRect(970, 620, 121, 41));
        btnCCSetAnIPOn = new QPushButton(centralWidget);
        btnCCSetAnIPOn->setObjectName(QString::fromUtf8("btnCCSetAnIPOn"));
        btnCCSetAnIPOn->setGeometry(QRect(270, 790, 121, 51));
        btnCCSetAnIPOff = new QPushButton(centralWidget);
        btnCCSetAnIPOff->setObjectName(QString::fromUtf8("btnCCSetAnIPOff"));
        btnCCSetAnIPOff->setGeometry(QRect(270, 850, 121, 51));
        btnCCSetDAAnIP = new QPushButton(centralWidget);
        btnCCSetDAAnIP->setObjectName(QString::fromUtf8("btnCCSetDAAnIP"));
        btnCCSetDAAnIP->setGeometry(QRect(400, 790, 121, 51));
        btnCCSetAnIPScanTime = new QPushButton(centralWidget);
        btnCCSetAnIPScanTime->setObjectName(QString::fromUtf8("btnCCSetAnIPScanTime"));
        btnCCSetAnIPScanTime->setGeometry(QRect(530, 850, 121, 51));
        btnCCSetAnOPSweepTime = new QPushButton(centralWidget);
        btnCCSetAnOPSweepTime->setObjectName(QString::fromUtf8("btnCCSetAnOPSweepTime"));
        btnCCSetAnOPSweepTime->setGeometry(QRect(530, 790, 121, 51));
        btnCCSetBaudRate = new QPushButton(centralWidget);
        btnCCSetBaudRate->setObjectName(QString::fromUtf8("btnCCSetBaudRate"));
        btnCCSetBaudRate->setGeometry(QRect(140, 850, 121, 51));
        btnCCSetAnOPOff = new QPushButton(centralWidget);
        btnCCSetAnOPOff->setObjectName(QString::fromUtf8("btnCCSetAnOPOff"));
        btnCCSetAnOPOff->setGeometry(QRect(660, 850, 121, 51));
        btnCCSetAnOPOn = new QPushButton(centralWidget);
        btnCCSetAnOPOn->setObjectName(QString::fromUtf8("btnCCSetAnOPOn"));
        btnCCSetAnOPOn->setGeometry(QRect(660, 790, 121, 51));
        btnCCSetLoadOPSweep = new QPushButton(centralWidget);
        btnCCSetLoadOPSweep->setObjectName(QString::fromUtf8("btnCCSetLoadOPSweep"));
        btnCCSetLoadOPSweep->setGeometry(QRect(400, 850, 121, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1255, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        lblStatus->setText(QApplication::translate("MainWindow", "Status", nullptr));
        btnSentIt->setText(QApplication::translate("MainWindow", "Send", nullptr));
        btnNardaVersion->setText(QApplication::translate("MainWindow", "N Version", nullptr));
        btnNardaTakeReading->setText(QApplication::translate("MainWindow", "N Take Reading", nullptr));
        btnNardaCalibration->setText(QApplication::translate("MainWindow", "N Calibration", nullptr));
        btnNardaSerialNumber->setText(QApplication::translate("MainWindow", "N Serial Number", nullptr));
        btnNardaBatteryVoltage->setText(QApplication::translate("MainWindow", "N Battery Volts", nullptr));
        btnNardaTemperature->setText(QApplication::translate("MainWindow", "N Temperature", nullptr));
        btnNardaThreeAxes->setText(QApplication::translate("MainWindow", "N 3 Axes", nullptr));
        btnNardaSetPowerOffTime->setText(QApplication::translate("MainWindow", "N Power Time", nullptr));
        btnNardaPowerOff->setText(QApplication::translate("MainWindow", "N Power Off", nullptr));
        btnWGQueryField->setText(QApplication::translate("MainWindow", "WG Single M", nullptr));
        btnWGQueryVersion->setText(QApplication::translate("MainWindow", "WG Version", nullptr));
        btnWGQueryBatteryOK->setText(QApplication::translate("MainWindow", "WG Battery OK", nullptr));
        btnWGQueryCmdError->setText(QApplication::translate("MainWindow", "WG Command Error", nullptr));
        btnWGBeep->setText(QApplication::translate("MainWindow", "WG Beep", nullptr));
        btnWGQueryFastMode->setText(QApplication::translate("MainWindow", "WG Fast Mode?", nullptr));
        btnWGToggleFastMode->setText(QApplication::translate("MainWindow", "WG Tgle Fast Mode", nullptr));
        btnWGToggleCalcAxis->setText(QApplication::translate("MainWindow", "WG Tgle C Axis", nullptr));
        btnWGQueryCalcAxis->setText(QApplication::translate("MainWindow", "WG Calc Axis?", nullptr));
        btnCCQueryStatus->setText(QApplication::translate("MainWindow", "CC Status", nullptr));
        btnCCSetReset->setText(QApplication::translate("MainWindow", "CC Reset", nullptr));
        lblLastReply->setText(QApplication::translate("MainWindow", "Last Reply", nullptr));
        lblLastReplyTxt->setText(QString());
        btnCCSetDigitalOP->setText(QApplication::translate("MainWindow", "CC Digi Set", nullptr));
        lblHexData->setText(QApplication::translate("MainWindow", "Dec Data to Tx", nullptr));
        btnCCSetAnIPOn->setText(QApplication::translate("MainWindow", "CC An IP On", nullptr));
        btnCCSetAnIPOff->setText(QApplication::translate("MainWindow", "CC An IP Off", nullptr));
        btnCCSetDAAnIP->setText(QApplication::translate("MainWindow", "CC D/A An IP", nullptr));
        btnCCSetAnIPScanTime->setText(QApplication::translate("MainWindow", "CC An IP Scn T", nullptr));
        btnCCSetAnOPSweepTime->setText(QApplication::translate("MainWindow", "CC An OP Swp T", nullptr));
        btnCCSetBaudRate->setText(QApplication::translate("MainWindow", "CC Baud Set", nullptr));
        btnCCSetAnOPOff->setText(QApplication::translate("MainWindow", "CC An OP Off", nullptr));
        btnCCSetAnOPOn->setText(QApplication::translate("MainWindow", "CC An OP On", nullptr));
        btnCCSetLoadOPSweep->setText(QApplication::translate("MainWindow", "CC Load OP SWP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
