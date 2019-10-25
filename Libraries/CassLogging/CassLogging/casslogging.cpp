#include "casslogging.h"


namespace Cass {
    namespace FileIO {
        //Const
        const QChar CR = QLatin1Char('\r');

        CassLogging::CassLogging(QObject *parent, QString folder, QString fileNameOnly)
        {
            loggingParent = parent;

            logEntryDate = QDateTime::currentDateTime();
            logFrequencyNumber = 0.0;
            logFrequencyUnits.clear();
            logFieldStrengthVPM = 0.0;
            logAmplifierOutputDBM = 0.0;
            logAmplitudeWasMaintained.clear();

            logDir = QDir(folder);
            logPath = folder;
            logQFile = nullptr;
            logFilenameOnly = fileNameOnly;
            lastError = LogErrors::None;
        }

        CassLogging::~CassLogging()
        {
            Close();
        }

        //Public
        bool CassLogging::Write() {
            if (!Open()) {
                return false;
            }

            QTextStream out(logQFile);
            //Date Time
            out << logEntryDate.toString("dd-MMM-yyyy hh:mm:ss\t");
            out.setNumberFlags(QTextStream::NumberFlag::ForcePoint);
            out.setRealNumberNotation(QTextStream::FixedNotation);
            out.setRealNumberPrecision(2);
            //Freq Units
            out << logFrequencyNumber << " " << logFrequencyUnits;
            out << "\t";
            out.setRealNumberPrecision(1);
            //Field Stringth
            out << logFieldStrengthVPM << " V/m";
            out << "\t\t";
            //Amp Output
            out << logAmplifierOutputDBM << " dbm";
            out << "\t";
            //Amplitude was OK
            out << logAmplitudeWasMaintained;
            //Flush too
            out << endl;

            return true;
        }

        QString CassLogging::LogErrorsText(const LogErrors lastErr) {
            switch (lastErr) {
            case CassLogging::LogErrors::None:
                return QStringLiteral("None");
            case CassLogging::LogErrors::FolderCreateFail:
                return QStringLiteral("FolderCreateFail");
            case CassLogging::LogErrors::FileCreateFail:
                return QStringLiteral("FileCreateFail");
            case CassLogging::LogErrors::WriteFail:
                return QStringLiteral("WriteFail");
            case CassLogging::LogErrors::FlushFail:
                return QStringLiteral("FlushFail");
            default:
                return QStringLiteral("**Uncoded LogErrors**");
            }
        }

        //Properties
        QDateTime CassLogging::GetEntryDate() const {
            return logEntryDate;
        }

        void CassLogging::SetEntryDate(const QDateTime dateTime) {
            logEntryDate = dateTime;
        }

        qreal CassLogging::GetFrequencyNumber() const {
            return  logFrequencyNumber;
        }

        void CassLogging::SetFrequencyNumber(const qreal frequencyNumber){
            logFrequencyNumber = frequencyNumber;
        }

        QString CassLogging::GetFrequencyUnits() const {
            return  logFrequencyUnits;
        }

        void CassLogging::SetFrequencyUnits(const QString frequencyUnits){
            logFrequencyUnits = frequencyUnits;
        }

        qreal CassLogging::GetFieldStrengthVPM() const {
            return  logFieldStrengthVPM;
        }

        void CassLogging::SetFieldStrengthVPM(const qreal fieldStrengthVPM){
            logFieldStrengthVPM = fieldStrengthVPM;
        }

        qreal CassLogging::GetAmplifierOutputDBM() const {
            return  logAmplifierOutputDBM;
        }
        void CassLogging::SetAmplifierOutputDBM(const qreal amplifierOutputDBM){
            logAmplifierOutputDBM = amplifierOutputDBM;
        }

        QString CassLogging::GetAmplitudeWasMaintained() const {
            return  logAmplitudeWasMaintained;
        }

        void CassLogging::SetAmplitudeWasMaintained(const QString amplitudeWasMaintained){
            logAmplitudeWasMaintained = amplitudeWasMaintained;
        }

        QString CassLogging::GetPath() const{
            return logPath;
        }

        QString CassLogging::GetFilenameOnly() const{
            return logFilenameOnly;
        }

        CassLogging::LogErrors CassLogging::GetLastError() const {
            return lastError;
        }

        QString CassLogging::GetLastQFileErrorText() const {
            return lastQFileErrorText;
        }

        //Private
        bool CassLogging::Open() {

            if (logQFile == nullptr) {
                ClearLastError();

                //Folder create?
                if (!logDir.exists()) {
                    if (!logDir.mkpath(logPath)) {
                        lastError = CassLogging::LogErrors::FolderCreateFail;
                        return false;
                    }
                }

                //construct the full path
                QString combinedPath = logDir.filePath(logFilenameOnly);

                logQFile = new QFile(combinedPath, loggingParent);

                if (!logQFile->open(QFile::OpenModeFlag::WriteOnly |
                                    QFile::OpenModeFlag::Append |
                                    QFile::OpenModeFlag::Text)) {
                    lastQFileErrorText = logQFile->errorString();
                    lastError = CassLogging::LogErrors::FileCreateFail;
                    return false;
                }

                return true;
            } else {
                if (logQFile->isOpen()) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        bool CassLogging::Close() {
            if (logQFile != nullptr) {
                if (logQFile->isOpen()) {
                    logQFile->flush();
                    logQFile->close();
                    delete logQFile;
                }
                logQFile = nullptr;
            }
            return true;
        }

        void CassLogging::ClearLastError() {
            lastError = CassLogging::LogErrors::None;
            lastQFileErrorText.clear();
        }
    }
}
