#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uiParent = parent;
    RFfieldLog = nullptr;
}

MainWindow::~MainWindow()
{
    if (RFfieldLog != nullptr) {
        delete RFfieldLog;
        RFfieldLog = nullptr;
    }
    delete ui;
}

//Private

void MainWindow::ShowDebugString(const QString newDebug) {
    QListWidgetItem* lastItem;

    lastItem = new QListWidgetItem(QString(newDebug));
    ui->lstReceived->addItem(lastItem);
    ui->lstReceived->setCurrentItem(lastItem);
}

void MainWindow::ShowQFileLastErrorText(const QString newQFileError) {
    ui->lblQFileError->setText(newQFileError);
}


//Handlers

void MainWindow::on_btnStart_clicked()
{
    if (RFfieldLog == nullptr) {
        RFfieldLog = new Cass::FileIO::CassLogging(uiParent, LogFolder, LogFileNameOnly);
        ShowDebugString("Started");
    }
}

void MainWindow::on_btnStop_clicked()
{
    if (RFfieldLog != nullptr) {
        delete RFfieldLog;
        RFfieldLog = nullptr;
        ShowDebugString("Stopped");
    }
}

void MainWindow::on_btnWriteEntry_clicked()
{
    if (RFfieldLog != nullptr) {
        RFfieldLog->SetEntryDate(QDateTime::currentDateTime());
        RFfieldLog->SetFrequencyNumber(0.056789);
        RFfieldLog->SetFrequencyUnits("MHz");
        RFfieldLog->SetFieldStrengthVPM(6.34);
        RFfieldLog->SetAmplifierOutputDBM(2.057);
        RFfieldLog->SetAmplitudeWasMaintained("OK");
        if (RFfieldLog->Write()) {
            ShowDebugString("Written");
        } else {
            ShowDebugString(Cass::FileIO::CassLogging::LogErrorsText(RFfieldLog->GetLastError()));
            ShowQFileLastErrorText(RFfieldLog->GetLastQFileErrorText());
        }
    }
}
