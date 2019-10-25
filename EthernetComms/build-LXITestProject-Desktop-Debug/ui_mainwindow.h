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
    QPushButton *btnRigolDiscover;
    QPushButton *btnStart;
    QPushButton *btnRigolConnect;
    QPushButton *btnRigolDisconnect;
    QLabel *lblStatus;
    QLabel *lblReply;
    QPushButton *btnIDN;
    QPushButton *btnLastError;
    QLabel *lblError;
    QPushButton *btnClearReply;
    QLineEdit *ledTestCommand;
    QPushButton *btnSendTextCmd;
    QPushButton *btnESR_Q;
    QPushButton *btnESE_Q;
    QLineEdit *ledNumericValue;
    QLabel *lblNumericValue;
    QPushButton *btnESE_S;
    QPushButton *btnSRE_Q;
    QPushButton *btnSRE_S;
    QPushButton *btnSTB_Q;
    QPushButton *btnATT_Q;
    QPushButton *btnATT_S;
    QPushButton *btnLEV_Q;
    QPushButton *btnLEV_S;
    QPushButton *btnMODE_S;
    QPushButton *btnMODE_Q;
    QLabel *lblStringValue;
    QLineEdit *ledStringValue;
    QPushButton *btnFREQ_Q;
    QPushButton *btnFREQ_S;
    QPushButton *btnON_OFF_S;
    QPushButton *btnON_OFF_Q;
    QPushButton *btnAM_DEPT_Q;
    QPushButton *btnAM_DEPT_S;
    QPushButton *btnAM_FREQ_Q;
    QPushButton *btnAM_FREQ_S;
    QPushButton *btnAM_STAT_Q;
    QPushButton *btnAM_STAT_S;
    QPushButton *btnMOD_STAT_Q;
    QPushButton *btnMOD_STAT_S;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1445, 704);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnRigolDiscover = new QPushButton(centralWidget);
        btnRigolDiscover->setObjectName(QStringLiteral("btnRigolDiscover"));
        btnRigolDiscover->setGeometry(QRect(30, 20, 121, 41));
        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(30, 280, 121, 41));
        btnRigolConnect = new QPushButton(centralWidget);
        btnRigolConnect->setObjectName(QStringLiteral("btnRigolConnect"));
        btnRigolConnect->setGeometry(QRect(160, 20, 121, 41));
        btnRigolDisconnect = new QPushButton(centralWidget);
        btnRigolDisconnect->setObjectName(QStringLiteral("btnRigolDisconnect"));
        btnRigolDisconnect->setGeometry(QRect(290, 20, 121, 41));
        lblStatus = new QLabel(centralWidget);
        lblStatus->setObjectName(QStringLiteral("lblStatus"));
        lblStatus->setGeometry(QRect(10, 520, 531, 41));
        lblStatus->setFrameShape(QFrame::Box);
        lblReply = new QLabel(centralWidget);
        lblReply->setObjectName(QStringLiteral("lblReply"));
        lblReply->setGeometry(QRect(10, 430, 531, 71));
        lblReply->setFrameShape(QFrame::Box);
        btnIDN = new QPushButton(centralWidget);
        btnIDN->setObjectName(QStringLiteral("btnIDN"));
        btnIDN->setGeometry(QRect(30, 70, 121, 41));
        btnLastError = new QPushButton(centralWidget);
        btnLastError->setObjectName(QStringLiteral("btnLastError"));
        btnLastError->setGeometry(QRect(160, 280, 121, 41));
        lblError = new QLabel(centralWidget);
        lblError->setObjectName(QStringLiteral("lblError"));
        lblError->setGeometry(QRect(10, 580, 531, 41));
        lblError->setFrameShape(QFrame::Box);
        btnClearReply = new QPushButton(centralWidget);
        btnClearReply->setObjectName(QStringLiteral("btnClearReply"));
        btnClearReply->setGeometry(QRect(580, 440, 121, 41));
        ledTestCommand = new QLineEdit(centralWidget);
        ledTestCommand->setObjectName(QStringLiteral("ledTestCommand"));
        ledTestCommand->setGeometry(QRect(12, 370, 521, 30));
        btnSendTextCmd = new QPushButton(centralWidget);
        btnSendTextCmd->setObjectName(QStringLiteral("btnSendTextCmd"));
        btnSendTextCmd->setGeometry(QRect(580, 360, 121, 41));
        btnESR_Q = new QPushButton(centralWidget);
        btnESR_Q->setObjectName(QStringLiteral("btnESR_Q"));
        btnESR_Q->setGeometry(QRect(160, 70, 121, 41));
        btnESE_Q = new QPushButton(centralWidget);
        btnESE_Q->setObjectName(QStringLiteral("btnESE_Q"));
        btnESE_Q->setGeometry(QRect(290, 70, 121, 41));
        ledNumericValue = new QLineEdit(centralWidget);
        ledNumericValue->setObjectName(QStringLiteral("ledNumericValue"));
        ledNumericValue->setGeometry(QRect(1180, 70, 241, 30));
        lblNumericValue = new QLabel(centralWidget);
        lblNumericValue->setObjectName(QStringLiteral("lblNumericValue"));
        lblNumericValue->setGeometry(QRect(1180, 110, 111, 31));
        lblNumericValue->setFrameShape(QFrame::NoFrame);
        btnESE_S = new QPushButton(centralWidget);
        btnESE_S->setObjectName(QStringLiteral("btnESE_S"));
        btnESE_S->setGeometry(QRect(290, 120, 121, 41));
        btnSRE_Q = new QPushButton(centralWidget);
        btnSRE_Q->setObjectName(QStringLiteral("btnSRE_Q"));
        btnSRE_Q->setGeometry(QRect(420, 70, 121, 41));
        btnSRE_S = new QPushButton(centralWidget);
        btnSRE_S->setObjectName(QStringLiteral("btnSRE_S"));
        btnSRE_S->setGeometry(QRect(420, 120, 121, 41));
        btnSTB_Q = new QPushButton(centralWidget);
        btnSTB_Q->setObjectName(QStringLiteral("btnSTB_Q"));
        btnSTB_Q->setGeometry(QRect(550, 70, 121, 41));
        btnATT_Q = new QPushButton(centralWidget);
        btnATT_Q->setObjectName(QStringLiteral("btnATT_Q"));
        btnATT_Q->setGeometry(QRect(680, 70, 121, 41));
        btnATT_S = new QPushButton(centralWidget);
        btnATT_S->setObjectName(QStringLiteral("btnATT_S"));
        btnATT_S->setGeometry(QRect(680, 120, 121, 41));
        btnLEV_Q = new QPushButton(centralWidget);
        btnLEV_Q->setObjectName(QStringLiteral("btnLEV_Q"));
        btnLEV_Q->setGeometry(QRect(810, 70, 121, 41));
        btnLEV_S = new QPushButton(centralWidget);
        btnLEV_S->setObjectName(QStringLiteral("btnLEV_S"));
        btnLEV_S->setGeometry(QRect(810, 120, 121, 41));
        btnMODE_S = new QPushButton(centralWidget);
        btnMODE_S->setObjectName(QStringLiteral("btnMODE_S"));
        btnMODE_S->setGeometry(QRect(940, 120, 121, 41));
        btnMODE_Q = new QPushButton(centralWidget);
        btnMODE_Q->setObjectName(QStringLiteral("btnMODE_Q"));
        btnMODE_Q->setGeometry(QRect(940, 70, 121, 41));
        lblStringValue = new QLabel(centralWidget);
        lblStringValue->setObjectName(QStringLiteral("lblStringValue"));
        lblStringValue->setGeometry(QRect(1180, 190, 111, 31));
        lblStringValue->setFrameShape(QFrame::NoFrame);
        ledStringValue = new QLineEdit(centralWidget);
        ledStringValue->setObjectName(QStringLiteral("ledStringValue"));
        ledStringValue->setGeometry(QRect(1180, 150, 241, 30));
        btnFREQ_Q = new QPushButton(centralWidget);
        btnFREQ_Q->setObjectName(QStringLiteral("btnFREQ_Q"));
        btnFREQ_Q->setGeometry(QRect(30, 170, 121, 41));
        btnFREQ_S = new QPushButton(centralWidget);
        btnFREQ_S->setObjectName(QStringLiteral("btnFREQ_S"));
        btnFREQ_S->setGeometry(QRect(30, 220, 121, 41));
        btnON_OFF_S = new QPushButton(centralWidget);
        btnON_OFF_S->setObjectName(QStringLiteral("btnON_OFF_S"));
        btnON_OFF_S->setGeometry(QRect(160, 220, 121, 41));
        btnON_OFF_Q = new QPushButton(centralWidget);
        btnON_OFF_Q->setObjectName(QStringLiteral("btnON_OFF_Q"));
        btnON_OFF_Q->setGeometry(QRect(160, 170, 121, 41));
        btnAM_DEPT_Q = new QPushButton(centralWidget);
        btnAM_DEPT_Q->setObjectName(QStringLiteral("btnAM_DEPT_Q"));
        btnAM_DEPT_Q->setGeometry(QRect(290, 170, 121, 41));
        btnAM_DEPT_S = new QPushButton(centralWidget);
        btnAM_DEPT_S->setObjectName(QStringLiteral("btnAM_DEPT_S"));
        btnAM_DEPT_S->setGeometry(QRect(290, 220, 121, 41));
        btnAM_FREQ_Q = new QPushButton(centralWidget);
        btnAM_FREQ_Q->setObjectName(QStringLiteral("btnAM_FREQ_Q"));
        btnAM_FREQ_Q->setGeometry(QRect(420, 170, 121, 41));
        btnAM_FREQ_S = new QPushButton(centralWidget);
        btnAM_FREQ_S->setObjectName(QStringLiteral("btnAM_FREQ_S"));
        btnAM_FREQ_S->setGeometry(QRect(420, 220, 121, 41));
        btnAM_STAT_Q = new QPushButton(centralWidget);
        btnAM_STAT_Q->setObjectName(QStringLiteral("btnAM_STAT_Q"));
        btnAM_STAT_Q->setGeometry(QRect(550, 170, 121, 41));
        btnAM_STAT_S = new QPushButton(centralWidget);
        btnAM_STAT_S->setObjectName(QStringLiteral("btnAM_STAT_S"));
        btnAM_STAT_S->setGeometry(QRect(550, 220, 121, 41));
        btnMOD_STAT_Q = new QPushButton(centralWidget);
        btnMOD_STAT_Q->setObjectName(QStringLiteral("btnMOD_STAT_Q"));
        btnMOD_STAT_Q->setGeometry(QRect(680, 170, 121, 41));
        btnMOD_STAT_S = new QPushButton(centralWidget);
        btnMOD_STAT_S->setObjectName(QStringLiteral("btnMOD_STAT_S"));
        btnMOD_STAT_S->setGeometry(QRect(680, 220, 121, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1445, 27));
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
        btnRigolDiscover->setText(QApplication::translate("MainWindow", "R. Discover", Q_NULLPTR));
        btnStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        btnRigolConnect->setText(QApplication::translate("MainWindow", "R. Connect", Q_NULLPTR));
        btnRigolDisconnect->setText(QApplication::translate("MainWindow", "R. Disconnect", Q_NULLPTR));
        lblStatus->setText(QString());
        lblReply->setText(QString());
        btnIDN->setText(QApplication::translate("MainWindow", "IDN ?", Q_NULLPTR));
        btnLastError->setText(QApplication::translate("MainWindow", "Last Error", Q_NULLPTR));
        lblError->setText(QString());
        btnClearReply->setText(QApplication::translate("MainWindow", "Clear Reply", Q_NULLPTR));
        btnSendTextCmd->setText(QApplication::translate("MainWindow", "Send It", Q_NULLPTR));
        btnESR_Q->setText(QApplication::translate("MainWindow", "ESR ?", Q_NULLPTR));
        btnESE_Q->setText(QApplication::translate("MainWindow", "ESE ?", Q_NULLPTR));
        lblNumericValue->setText(QApplication::translate("MainWindow", "Numeric Value", Q_NULLPTR));
        btnESE_S->setText(QApplication::translate("MainWindow", "Set ESE", Q_NULLPTR));
        btnSRE_Q->setText(QApplication::translate("MainWindow", "SRE ?", Q_NULLPTR));
        btnSRE_S->setText(QApplication::translate("MainWindow", "Set SRE", Q_NULLPTR));
        btnSTB_Q->setText(QApplication::translate("MainWindow", "STB ?", Q_NULLPTR));
        btnATT_Q->setText(QApplication::translate("MainWindow", "ATT ?", Q_NULLPTR));
        btnATT_S->setText(QApplication::translate("MainWindow", "Set ATT", Q_NULLPTR));
        btnLEV_Q->setText(QApplication::translate("MainWindow", "LEV ?", Q_NULLPTR));
        btnLEV_S->setText(QApplication::translate("MainWindow", "Set LEV", Q_NULLPTR));
        btnMODE_S->setText(QApplication::translate("MainWindow", "Set MODE", Q_NULLPTR));
        btnMODE_Q->setText(QApplication::translate("MainWindow", "MODE ?", Q_NULLPTR));
        lblStringValue->setText(QApplication::translate("MainWindow", "String Value", Q_NULLPTR));
        btnFREQ_Q->setText(QApplication::translate("MainWindow", "FREQ ?", Q_NULLPTR));
        btnFREQ_S->setText(QApplication::translate("MainWindow", "Set FREQ", Q_NULLPTR));
        btnON_OFF_S->setText(QApplication::translate("MainWindow", "Set RF ON/OFF", Q_NULLPTR));
        btnON_OFF_Q->setText(QApplication::translate("MainWindow", "RF ON/OFF ?", Q_NULLPTR));
        btnAM_DEPT_Q->setText(QApplication::translate("MainWindow", "AM DEPT ?", Q_NULLPTR));
        btnAM_DEPT_S->setText(QApplication::translate("MainWindow", "Set AM DEPT", Q_NULLPTR));
        btnAM_FREQ_Q->setText(QApplication::translate("MainWindow", "AM FREQ ?", Q_NULLPTR));
        btnAM_FREQ_S->setText(QApplication::translate("MainWindow", "Set AM FREQ", Q_NULLPTR));
        btnAM_STAT_Q->setText(QApplication::translate("MainWindow", "AM STAT ?", Q_NULLPTR));
        btnAM_STAT_S->setText(QApplication::translate("MainWindow", "Set AM STAT", Q_NULLPTR));
        btnMOD_STAT_Q->setText(QApplication::translate("MainWindow", "MOD STAT ?", Q_NULLPTR));
        btnMOD_STAT_S->setText(QApplication::translate("MainWindow", "Set MOD STAT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
