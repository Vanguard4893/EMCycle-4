#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <rigoldsg.h>
#include <lxi.h>
#include <i_lxi_device.h>
#include <scpi_commands.h>

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
    void on_btnRigolDiscover_clicked();

    void on_btnStart_clicked();

    void on_btnRigolConnect_clicked();

    void on_btnRigolDisconnect_clicked();

    void on_btnIDN_clicked();

    void on_btnLastError_clicked();

    void on_btnClearReply_clicked();

    void on_btnSendTextCmd_clicked();

    void on_btnESR_Q_clicked();

    void on_btnESE_S_clicked();

    void on_btnESE_Q_clicked();

    void on_btnSRE_Q_clicked();

    void on_btnSRE_S_clicked();

    void on_btnSTB_Q_clicked();

    void on_btnATT_Q_clicked();

    void on_btnATT_S_clicked();

    void on_btnLEV_Q_clicked();

    void on_btnLEV_S_clicked();

    void on_btnMODE_Q_clicked();

    void on_btnMODE_S_clicked();

    void on_btnFREQ_Q_clicked();

    void on_btnFREQ_S_clicked();

    void on_btnON_OFF_Q_clicked();

    void on_btnON_OFF_S_clicked();

    void on_btnAM_DEPT_Q_clicked();

    void on_btnAM_DEPT_S_clicked();

    void on_btnAM_FREQ_Q_clicked();

    void on_btnAM_FREQ_S_clicked();

    void on_btnAM_STAT_Q_clicked();

    void on_btnAM_STAT_S_clicked();

    void on_btnMOD_STAT_Q_clicked();

    void on_btnMOD_STAT_S_clicked();

private:
    void ShowStatus(const QString newStatus);
    void ShowReply(const QString *reply);
    void ShowReply(const quint8 *reply);
    void ShowReply(const qreal *reply);
    void ShowReply(const qreal *reply, const Cass::LXI::SCPI_Commands::FrequencyUnit *freqUnit);
    void ShowReply(const quint64 *reply);
    void ShowReply(const Cass::LXI::SCPI_Commands::ON_OFF *on_off);
    void ShowError(const QString errorText);
    void ClearError();
    Ui::MainWindow *ui;
    Cass::LXI::RigolDSG *rigolDSG;
    QString commandSendQString;
    QString commandReplyString;
    quint8 commandReplyByte;
    quint8 commandSendByte;
    qreal commandReplyQreal;
    qreal commandSendQreal;
    quint64 commandReplyQuint64;
    quint64 commandSendQuint64;

    Cass::LXI::SCPI_Commands::FrequencyUnit commandReplyFreqUnit;
    Cass::LXI::SCPI_Commands::ON_OFF commandReplyON_OFF;

    bool convertOK;
    const QString SENT = "SENT";

    void CloseEthernet();
};

#endif // MAINWINDOW_H
