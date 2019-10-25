/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1225, 1081);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(970, 300, 111, 51));
        lstSerialPorts = new QListWidget(centralWidget);
        lstSerialPorts->setObjectName(QStringLiteral("lstSerialPorts"));
        lstSerialPorts->setGeometry(QRect(760, 300, 201, 51));
        lblStatus = new QLabel(centralWidget);
        lblStatus->setObjectName(QStringLiteral("lblStatus"));
        lblStatus->setGeometry(QRect(10, 910, 1061, 51));
        lblStatus->setWordWrap(true);
        lstReceived = new QListWidget(centralWidget);
        lstReceived->setObjectName(QStringLiteral("lstReceived"));
        lstReceived->setGeometry(QRect(5, 1, 1231, 281));
        QFont font;
        font.setPointSize(12);
        lstReceived->setFont(font);
        btnSentIt = new QPushButton(centralWidget);
        btnSentIt->setObjectName(QStringLiteral("btnSentIt"));
        btnSentIt->setGeometry(QRect(970, 360, 111, 71));
        lneTxText = new QLineEdit(centralWidget);
        lneTxText->setObjectName(QStringLiteral("lneTxText"));
        lneTxText->setGeometry(QRect(400, 360, 551, 71));
        btnNardaVersion = new QPushButton(centralWidget);
        btnNardaVersion->setObjectName(QStringLiteral("btnNardaVersion"));
        btnNardaVersion->setGeometry(QRect(10, 550, 121, 51));
        btnNardaTakeReading = new QPushButton(centralWidget);
        btnNardaTakeReading->setObjectName(QStringLiteral("btnNardaTakeReading"));
        btnNardaTakeReading->setGeometry(QRect(140, 550, 121, 51));
        btnNardaCalibration = new QPushButton(centralWidget);
        btnNardaCalibration->setObjectName(QStringLiteral("btnNardaCalibration"));
        btnNardaCalibration->setGeometry(QRect(270, 550, 121, 51));
        btnNardaSerialNumber = new QPushButton(centralWidget);
        btnNardaSerialNumber->setObjectName(QStringLiteral("btnNardaSerialNumber"));
        btnNardaSerialNumber->setGeometry(QRect(400, 550, 121, 51));
        btnNardaBatteryVoltage = new QPushButton(centralWidget);
        btnNardaBatteryVoltage->setObjectName(QStringLiteral("btnNardaBatteryVoltage"));
        btnNardaBatteryVoltage->setGeometry(QRect(530, 550, 121, 51));
        btnNardaTemperature = new QPushButton(centralWidget);
        btnNardaTemperature->setObjectName(QStringLiteral("btnNardaTemperature"));
        btnNardaTemperature->setGeometry(QRect(10, 610, 121, 51));
        btnNardaThreeAxes = new QPushButton(centralWidget);
        btnNardaThreeAxes->setObjectName(QStringLiteral("btnNardaThreeAxes"));
        btnNardaThreeAxes->setGeometry(QRect(140, 610, 121, 51));
        btnNardaSetPowerOffTime = new QPushButton(centralWidget);
        btnNardaSetPowerOffTime->setObjectName(QStringLiteral("btnNardaSetPowerOffTime"));
        btnNardaSetPowerOffTime->setGeometry(QRect(270, 610, 121, 51));
        btnNardaPowerOff = new QPushButton(centralWidget);
        btnNardaPowerOff->setObjectName(QStringLiteral("btnNardaPowerOff"));
        btnNardaPowerOff->setGeometry(QRect(400, 610, 121, 51));
        btnWGQueryField = new QPushButton(centralWidget);
        btnWGQueryField->setObjectName(QStringLiteral("btnWGQueryField"));
        btnWGQueryField->setGeometry(QRect(10, 670, 121, 51));
        btnWGQueryVersion = new QPushButton(centralWidget);
        btnWGQueryVersion->setObjectName(QStringLiteral("btnWGQueryVersion"));
        btnWGQueryVersion->setGeometry(QRect(140, 670, 121, 51));
        btnWGQueryBatteryOK = new QPushButton(centralWidget);
        btnWGQueryBatteryOK->setObjectName(QStringLiteral("btnWGQueryBatteryOK"));
        btnWGQueryBatteryOK->setGeometry(QRect(270, 670, 121, 51));
        btnWGQueryCmdError = new QPushButton(centralWidget);
        btnWGQueryCmdError->setObjectName(QStringLiteral("btnWGQueryCmdError"));
        btnWGQueryCmdError->setGeometry(QRect(400, 670, 121, 51));
        btnWGBeep = new QPushButton(centralWidget);
        btnWGBeep->setObjectName(QStringLiteral("btnWGBeep"));
        btnWGBeep->setGeometry(QRect(530, 670, 121, 51));
        btnWGQueryFastMode = new QPushButton(centralWidget);
        btnWGQueryFastMode->setObjectName(QStringLiteral("btnWGQueryFastMode"));
        btnWGQueryFastMode->setGeometry(QRect(10, 730, 121, 51));
        btnWGToggleFastMode = new QPushButton(centralWidget);
        btnWGToggleFastMode->setObjectName(QStringLiteral("btnWGToggleFastMode"));
        btnWGToggleFastMode->setGeometry(QRect(140, 730, 121, 51));
        btnWGToggleCalcAxis = new QPushButton(centralWidget);
        btnWGToggleCalcAxis->setObjectName(QStringLiteral("btnWGToggleCalcAxis"));
        btnWGToggleCalcAxis->setGeometry(QRect(400, 730, 121, 51));
        btnWGQueryCalcAxis = new QPushButton(centralWidget);
        btnWGQueryCalcAxis->setObjectName(QStringLiteral("btnWGQueryCalcAxis"));
        btnWGQueryCalcAxis->setGeometry(QRect(270, 730, 121, 51));
        btnCCQueryStatus = new QPushButton(centralWidget);
        btnCCQueryStatus->setObjectName(QStringLiteral("btnCCQueryStatus"));
        btnCCQueryStatus->setGeometry(QRect(10, 790, 121, 51));
        btnCCSetReset = new QPushButton(centralWidget);
        btnCCSetReset->setObjectName(QStringLiteral("btnCCSetReset"));
        btnCCSetReset->setGeometry(QRect(10, 850, 121, 51));
        lblLastReply = new QLabel(centralWidget);
        lblLastReply->setObjectName(QStringLiteral("lblLastReply"));
        lblLastReply->setGeometry(QRect(20, 460, 111, 41));
        lblLastReplyTxt = new QLabel(centralWidget);
        lblLastReplyTxt->setObjectName(QStringLiteral("lblLastReplyTxt"));
        lblLastReplyTxt->setGeometry(QRect(140, 460, 941, 51));
        btnCCSetDigitalOP = new QPushButton(centralWidget);
        btnCCSetDigitalOP->setObjectName(QStringLiteral("btnCCSetDigitalOP"));
        btnCCSetDigitalOP->setGeometry(QRect(140, 790, 121, 51));
        lneDataDecValue = new QLineEdit(centralWidget);
        lneDataDecValue->setObjectName(QStringLiteral("lneDataDecValue"));
        lneDataDecValue->setGeometry(QRect(950, 540, 141, 71));
        lblHexData = new QLabel(centralWidget);
        lblHexData->setObjectName(QStringLiteral("lblHexData"));
        lblHexData->setGeometry(QRect(970, 620, 121, 41));
        btnCCSetAnIPOn = new QPushButton(centralWidget);
        btnCCSetAnIPOn->setObjectName(QStringLiteral("btnCCSetAnIPOn"));
        btnCCSetAnIPOn->setGeometry(QRect(270, 790, 121, 51));
        btnCCSetAnIPOff = new QPushButton(centralWidget);
        btnCCSetAnIPOff->setObjectName(QStringLiteral("btnCCSetAnIPOff"));
        btnCCSetAnIPOff->setGeometry(QRect(270, 850, 121, 51));
        btnCCSetDAAnIP = new QPushButton(centralWidget);
        btnCCSetDAAnIP->setObjectName(QStringLiteral("btnCCSetDAAnIP"));
        btnCCSetDAAnIP->setGeometry(QRect(400, 790, 121, 51));
        btnCCSetAnIPScanTime = new QPushButton(centralWidget);
        btnCCSetAnIPScanTime->setObjectName(QStringLiteral("btnCCSetAnIPScanTime"));
        btnCCSetAnIPScanTime->setGeometry(QRect(530, 850, 121, 51));
        btnCCSetAnOPSweepTime = new QPushButton(centralWidget);
        btnCCSetAnOPSweepTime->setObjectName(QStringLiteral("btnCCSetAnOPSweepTime"));
        btnCCSetAnOPSweepTime->setGeometry(QRect(530, 790, 121, 51));
        btnCCSetBaudRate = new QPushButton(centralWidget);
        btnCCSetBaudRate->setObjectName(QStringLiteral("btnCCSetBaudRate"));
        btnCCSetBaudRate->setGeometry(QRect(140, 850, 121, 51));
        btnCCSetAnOPOff = new QPushButton(centralWidget);
        btnCCSetAnOPOff->setObjectName(QStringLiteral("btnCCSetAnOPOff"));
        btnCCSetAnOPOff->setGeometry(QRect(660, 850, 121, 51));
        btnCCSetAnOPOn = new QPushButton(centralWidget);
        btnCCSetAnOPOn->setObjectName(QStringLiteral("btnCCSetAnOPOn"));
        btnCCSetAnOPOn->setGeometry(QRect(660, 790, 121, 51));
        btnCCSetLoadOPSweep = new QPushButton(centralWidget);
        btnCCSetLoadOPSweep->setObjectName(QStringLiteral("btnCCSetLoadOPSweep"));
        btnCCSetLoadOPSweep->setGeometry(QRect(400, 850, 121, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1225, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        lblStatus->setText(QApplication::translate("MainWindow", "Status", Q_NULLPTR));
        btnSentIt->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        btnNardaVersion->setText(QApplication::translate("MainWindow", "N Version", Q_NULLPTR));
        btnNardaTakeReading->setText(QApplication::translate("MainWindow", "N Take Reading", Q_NULLPTR));
        btnNardaCalibration->setText(QApplication::translate("MainWindow", "N Calibration", Q_NULLPTR));
        btnNardaSerialNumber->setText(QApplication::translate("MainWindow", "N Serial Number", Q_NULLPTR));
        btnNardaBatteryVoltage->setText(QApplication::translate("MainWindow", "N Battery Volts", Q_NULLPTR));
        btnNardaTemperature->setText(QApplication::translate("MainWindow", "N Temperature", Q_NULLPTR));
        btnNardaThreeAxes->setText(QApplication::translate("MainWindow", "N 3 Axes", Q_NULLPTR));
        btnNardaSetPowerOffTime->setText(QApplication::translate("MainWindow", "N Power Time", Q_NULLPTR));
        btnNardaPowerOff->setText(QApplication::translate("MainWindow", "N Power Off", Q_NULLPTR));
        btnWGQueryField->setText(QApplication::translate("MainWindow", "WG Single M", Q_NULLPTR));
        btnWGQueryVersion->setText(QApplication::translate("MainWindow", "WG Version", Q_NULLPTR));
        btnWGQueryBatteryOK->setText(QApplication::translate("MainWindow", "WG Battery OK", Q_NULLPTR));
        btnWGQueryCmdError->setText(QApplication::translate("MainWindow", "WG Command Error", Q_NULLPTR));
        btnWGBeep->setText(QApplication::translate("MainWindow", "WG Beep", Q_NULLPTR));
        btnWGQueryFastMode->setText(QApplication::translate("MainWindow", "WG Fast Mode?", Q_NULLPTR));
        btnWGToggleFastMode->setText(QApplication::translate("MainWindow", "WG Tgle Fast Mode", Q_NULLPTR));
        btnWGToggleCalcAxis->setText(QApplication::translate("MainWindow", "WG Tgle C Axis", Q_NULLPTR));
        btnWGQueryCalcAxis->setText(QApplication::translate("MainWindow", "WG Calc Axis?", Q_NULLPTR));
        btnCCQueryStatus->setText(QApplication::translate("MainWindow", "CC Status", Q_NULLPTR));
        btnCCSetReset->setText(QApplication::translate("MainWindow", "CC Reset", Q_NULLPTR));
        lblLastReply->setText(QApplication::translate("MainWindow", "Last Reply", Q_NULLPTR));
        lblLastReplyTxt->setText(QString());
        btnCCSetDigitalOP->setText(QApplication::translate("MainWindow", "CC Digi Set", Q_NULLPTR));
        lblHexData->setText(QApplication::translate("MainWindow", "Dec Data to Tx", Q_NULLPTR));
        btnCCSetAnIPOn->setText(QApplication::translate("MainWindow", "CC An IP On", Q_NULLPTR));
        btnCCSetAnIPOff->setText(QApplication::translate("MainWindow", "CC An IP Off", Q_NULLPTR));
        btnCCSetDAAnIP->setText(QApplication::translate("MainWindow", "CC D/A An IP", Q_NULLPTR));
        btnCCSetAnIPScanTime->setText(QApplication::translate("MainWindow", "CC An IP Scn T", Q_NULLPTR));
        btnCCSetAnOPSweepTime->setText(QApplication::translate("MainWindow", "CC An OP Swp T", Q_NULLPTR));
        btnCCSetBaudRate->setText(QApplication::translate("MainWindow", "CC Baud Set", Q_NULLPTR));
        btnCCSetAnOPOff->setText(QApplication::translate("MainWindow", "CC An OP Off", Q_NULLPTR));
        btnCCSetAnOPOn->setText(QApplication::translate("MainWindow", "CC An OP On", Q_NULLPTR));
        btnCCSetLoadOPSweep->setText(QApplication::translate("MainWindow", "CC Load OP SWP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
