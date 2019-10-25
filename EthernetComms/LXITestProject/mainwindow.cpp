#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString Processing = QStringLiteral("Processing...");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ledTestCommand->setClearButtonEnabled(true);
    ui->ledNumericValue->setClearButtonEnabled(true);
    ui->ledStringValue->setClearButtonEnabled(true);
    //ui->ledNumericValue->setMask();
    rigolDSG = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Private
void MainWindow::ShowStatus(QString newStatus) {
    ui->lblStatus->setText(newStatus);
}

void MainWindow::ShowReply(const QString *reply) {
    //Clear any error first
    ClearError();
    ui->lblReply->setText(*reply);
    ui->ledTestCommand->setText(rigolDSG->getLastCommand());
}

void MainWindow::ShowReply(const quint8* reply) {
    QString* asString;

    //Clear any error first
    ClearError();
    asString = Cass::LXI::SCPI_Commands::ToString(reply);
    ui->lblReply->setText("[" + *asString + "]");
    ui->ledTestCommand->setText(rigolDSG->getLastCommand());
}

void MainWindow::ShowReply(const qreal* reply) {
    QString* asString;

    //Clear any error first
    ClearError();
    asString = Cass::LXI::SCPI_Commands::ToString(reply);
    ui->lblReply->setText("[" + *asString + "]");
    ui->ledTestCommand->setText(rigolDSG->getLastCommand());
}

void MainWindow::ShowReply(const qreal *reply, const Cass::LXI::SCPI_Commands::FrequencyUnit *freqUnit) {
    QString* asString;

    //Clear any error first
    ClearError();
    asString = Cass::LXI::SCPI_Commands::ToString(reply);
    ui->lblReply->setText("[" + *asString + Cass::LXI::SCPI_Commands::ToString(freqUnit) + "]");
    ui->ledTestCommand->setText(rigolDSG->getLastCommand());
}

void MainWindow::ShowReply(const quint64* reply) {
    QString* asString;

    //Clear any error first
    ClearError();
    asString = Cass::LXI::SCPI_Commands::ToString(reply);
    ui->lblReply->setText("[" + *asString + "]");
    ui->ledTestCommand->setText(rigolDSG->getLastCommand());
}

void MainWindow::ShowReply(const Cass::LXI::SCPI_Commands::ON_OFF *on_off) {
    QString* asString;

    //Clear any error first
    ClearError();
    asString = Cass::LXI::SCPI_Commands::ToString(on_off);
    ui->lblReply->setText("[" + *asString + "]");
    ui->ledTestCommand->setText(rigolDSG->getLastCommand());
}

void MainWindow::ShowError(const QString errorText) {
    ui ->lblError->setText(errorText);
}

void MainWindow::ClearError() {
    ui ->lblError->clear();
}

void MainWindow::CloseEthernet() {
    if (rigolDSG != nullptr) {
        //rigolDSG->CloseConnection();
        rigolDSG = nullptr;
    }
}

//Handlers
void MainWindow::on_btnRigolDiscover_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SearchForDevices()) {
            ShowStatus("Devices Found...");
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnStart_clicked()
{
    rigolDSG = new Cass::LXI::RigolDSG(this);
    if (rigolDSG->GetLastError() != Cass::LXI::I_LXI_Device::LXIErrors::NoError) {
        CloseEthernet();
        ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
    } else {
        ShowStatus("Started...");
    }
}

void MainWindow::on_btnRigolConnect_clicked()
{
    if (rigolDSG != nullptr) {
        //if (rigolDSG->OpenConnection()) {
            if (true) {
            ShowStatus("Connected...");
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnRigolDisconnect_clicked()
{
    if (rigolDSG != nullptr) {
        //if (rigolDSG->CloseConnection()) {
            if (true) {
            ShowStatus("Disconnected...");
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnIDN_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_IDN_Q(&commandReplyString)) {
            ShowReply(&commandReplyString);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnLastError_clicked()
{
    if (rigolDSG != nullptr) {
        ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
    }
}

void MainWindow::on_btnClearReply_clicked()
{
    ui->lblReply->clear();
}

void MainWindow::on_btnSendTextCmd_clicked()
{
    if (rigolDSG != nullptr) {
        commandSendQString = ui->ledTestCommand->text();
        if (commandSendQString.length() > 0) {
            ShowReply(&Processing);
            if (rigolDSG->SCPISendCommand(&commandSendQString, &commandReplyString)) {
                ShowReply(&commandReplyString);
            } else {
                ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
            }
        }
    }
}

void MainWindow::on_btnESR_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_ESR_Q(&commandReplyByte)) {
            ShowReply(&commandReplyByte);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnESE_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledNumericValue->text().length() > 0) {
            long valueLong = ui->ledNumericValue->text().toLong(&convertOK);
            if (convertOK) {
                ShowReply(&Processing);
                commandSendByte = static_cast<const quint8>(valueLong);

                if (rigolDSG->SCPI_ESE_S(commandSendByte)) {
                    ShowReply(&SENT);
                } else {
                    ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                }
            }
        }
    }
}

void MainWindow::on_btnESE_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_ESE_Q(&commandReplyByte)) {
            ShowReply(&commandReplyByte);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnSRE_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_SRE_Q(&commandReplyByte)) {
            ShowReply(&commandReplyByte);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnSRE_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledNumericValue->text().length() > 0) {
            long valueLong = ui->ledNumericValue->text().toLong(&convertOK);
            if (convertOK) {
                ShowReply(&Processing);
                commandSendByte = static_cast<const quint8>(valueLong);

                if (rigolDSG->SCPI_SRE_S(commandSendByte)) {
                    ShowReply(&SENT);
                } else {
                    ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                }
            }
        }
    }
}

void MainWindow::on_btnSTB_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_STB_Q(&commandReplyByte)) {
            ShowReply(&commandReplyByte);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnATT_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_SOUR_LEV_ATT_Q(&commandReplyByte)) {
            ShowReply(&commandReplyByte);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnATT_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledNumericValue->text().length() > 0) {
            long valueLong = ui->ledNumericValue->text().toLong(&convertOK);
            if (convertOK) {
                ShowReply(&Processing);
                commandSendByte = static_cast<const quint8>(valueLong);

                if (rigolDSG->SCPI_SOUR_LEV_ATT_S(commandSendByte)) {
                    ShowReply(&SENT);
                } else {
                    ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                }
            }
        }
    }
}

void MainWindow::on_btnLEV_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_SOUR_LEV_Q(&commandReplyQreal)) {
            ShowReply(&commandReplyQreal);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnLEV_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledNumericValue->text().length() > 0) {
            qreal valueQreal = ui->ledNumericValue->text().toDouble(&convertOK);
            if (convertOK) {
                ShowReply(&Processing);
                commandSendQreal = static_cast<const qreal>(valueQreal);

                if (rigolDSG->SCPI_SOUR_LEV_S(commandSendQreal)) {
                    ShowReply(&SENT);
                } else {
                    ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                }
            }
        }
    }
}

void MainWindow::on_btnMODE_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_SOUR_LEV_ATT_MODE_Q(&commandReplyString)) {
            ShowReply(&commandReplyString);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnMODE_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledStringValue->text().length() > 0) {
            ShowReply(&Processing);
            commandSendQString = ui->ledStringValue->text();

            if (rigolDSG->SCPI_SOUR_LEV_ATT_MODE_S(commandSendQString)) {
                ShowReply(&SENT);
            } else {
                ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
            }
        }
    }
}

void MainWindow::on_btnFREQ_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);

        if (rigolDSG->SCPI_SOUR_FREQ_Q(&commandReplyQreal, &commandReplyFreqUnit)) {
            ShowReply(&commandReplyQreal, &commandReplyFreqUnit);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnFREQ_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledNumericValue->text().length() > 0) {
            qreal valueQreal = ui->ledNumericValue->text().toDouble(&convertOK);
            if (convertOK) {
                ShowReply(&Processing);
                commandSendQreal = valueQreal;
                //Is there a frequency unit?
                bool gotValidFreqUnit = false;
                Cass::LXI::SCPI_Commands::FrequencyUnit fUnit;
                if (ui->ledStringValue->text().length() > 0) {
                    QString fUnitStr = ui->ledStringValue->text();
                    fUnit = Cass::LXI::SCPI_Commands::FromFrequencyUnit(&fUnitStr);
                    if (fUnit != Cass::LXI::SCPI_Commands::FrequencyUnit::None) {
                        gotValidFreqUnit = true;
                    }
                }
                if (gotValidFreqUnit) {
                    if (rigolDSG->SCPI_SOUR_FREQ_S(commandSendQreal, fUnit)) {
                        ShowReply(&SENT);
                    } else {
                        ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                    }
                } else {
                    if (rigolDSG->SCPI_SOUR_FREQ_S(commandSendQreal)) {
                        ShowReply(&SENT);
                    } else {
                        ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                    }
                }
            }
        }
    }
}

void MainWindow::on_btnON_OFF_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);

        commandReplyON_OFF = Cass::LXI::SCPI_Commands::ON_OFF::None;

        if (rigolDSG->SCPI_OUTP_Q(&commandReplyON_OFF)) {
            ShowReply(&commandReplyON_OFF);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnON_OFF_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledStringValue->text().length() > 0) {
            ShowReply(&Processing);
            commandSendQString = ui->ledStringValue->text();
            Cass::LXI::SCPI_Commands::ON_OFF on_off = Cass::LXI::SCPI_Commands::FromON_OFF(&commandSendQString);
            if (on_off != Cass::LXI::SCPI_Commands::ON_OFF::None) {
                if (rigolDSG->SCPI_OUTP_S(on_off)) {
                    ShowReply(&SENT);
                } else {
                    ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                }
            }
        }
    }
}

void MainWindow::on_btnAM_DEPT_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);
        if (rigolDSG->SCPI_SOUR_AM_DEPT_Q(&commandReplyByte)) {
            ShowReply(&commandReplyByte);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnAM_DEPT_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledNumericValue->text().length() > 0) {
            long valueLong = ui->ledNumericValue->text().toLong(&convertOK);
            if (convertOK) {
                ShowReply(&Processing);
                commandSendByte = static_cast<const quint8>(valueLong);

                if (rigolDSG->SCPI_SOUR_AM_DEPT_S(commandSendByte)) {
                    ShowReply(&SENT);
                } else {
                    ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                }
            }
        }
    }
}

void MainWindow::on_btnAM_FREQ_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);

        if (rigolDSG->SCPI_SOUR_AM_FREQ_Q(&commandReplyQreal, &commandReplyFreqUnit)) {
            ShowReply(&commandReplyQreal, &commandReplyFreqUnit);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnAM_FREQ_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledNumericValue->text().length() > 0) {
            qreal valueQreal = ui->ledNumericValue->text().toDouble(&convertOK);
            if (convertOK) {
                ShowReply(&Processing);
                commandSendQreal = valueQreal;
                //Is there a frequency unit?
                bool gotValidFreqUnit = false;
                Cass::LXI::SCPI_Commands::FrequencyUnit fUnit;
                if (ui->ledStringValue->text().length() > 0) {
                    QString fUnitStr = ui->ledStringValue->text();
                    fUnit = Cass::LXI::SCPI_Commands::FromFrequencyUnit(&fUnitStr);
                    if (fUnit != Cass::LXI::SCPI_Commands::FrequencyUnit::None) {
                        gotValidFreqUnit = true;
                    }
                }
                if (gotValidFreqUnit) {
                    if (rigolDSG->SCPI_SOUR_AM_FREQ_S(commandSendQreal, fUnit)) {
                        ShowReply(&SENT);
                    } else {
                        ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                    }
                } else {
                    if (rigolDSG->SCPI_SOUR_AM_FREQ_S(commandSendQreal)) {
                        ShowReply(&SENT);
                    } else {
                        ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                    }
                }
            }
        }
    }
}

void MainWindow::on_btnAM_STAT_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);

        commandReplyON_OFF = Cass::LXI::SCPI_Commands::ON_OFF::None;

        if (rigolDSG->SCPI_SOUR_AM_STAT_Q(&commandReplyON_OFF)) {
            ShowReply(&commandReplyON_OFF);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnAM_STAT_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledStringValue->text().length() > 0) {
            ShowReply(&Processing);
            commandSendQString = ui->ledStringValue->text();
            Cass::LXI::SCPI_Commands::ON_OFF on_off = Cass::LXI::SCPI_Commands::FromON_OFF(&commandSendQString);
            if (on_off != Cass::LXI::SCPI_Commands::ON_OFF::None) {
                if (rigolDSG->SCPI_SOUR_AM_STAT_S(on_off)) {
                    ShowReply(&SENT);
                } else {
                    ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                }
            }
        }
    }
}

void MainWindow::on_btnMOD_STAT_Q_clicked()
{
    if (rigolDSG != nullptr) {
        ShowReply(&Processing);

        commandReplyON_OFF = Cass::LXI::SCPI_Commands::ON_OFF::None;

        if (rigolDSG->SCPI_SOUR_MOD_STAT_Q(&commandReplyON_OFF)) {
            ShowReply(&commandReplyON_OFF);
        } else {
            ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
        }
    }
}

void MainWindow::on_btnMOD_STAT_S_clicked()
{
    if (rigolDSG != nullptr) {
        if (ui->ledStringValue->text().length() > 0) {
            ShowReply(&Processing);
            commandSendQString = ui->ledStringValue->text();
            Cass::LXI::SCPI_Commands::ON_OFF on_off = Cass::LXI::SCPI_Commands::FromON_OFF(&commandSendQString);
            if (on_off != Cass::LXI::SCPI_Commands::ON_OFF::None) {
                if (rigolDSG->SCPI_SOUR_MOD_STAT_S(on_off)) {
                    ShowReply(&SENT);
                } else {
                    ShowError(Cass::LXI::I_LXI_Device::GetLastErrorText(rigolDSG->GetLastError()));
                }
            }
        }
    }
}
