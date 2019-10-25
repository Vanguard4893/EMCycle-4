#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <casslogging.h>

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

    void on_btnStop_clicked();

    void on_btnWriteEntry_clicked();

private:
    Ui::MainWindow *ui;
    QObject *uiParent;
    void ShowDebugString(const QString newDebug);
    void ShowQFileLastErrorText(const QString newQFileError);
    Cass::FileIO::CassLogging *RFfieldLog;

    QString LogFolder = QStringLiteral("/home/cassdev/Documents/Source/Logging/Logs");
    QString LogFileNameOnly = QStringLiteral("EM9999.txt");
};

#endif // MAINWINDOW_H
