#ifndef CASSLOGGING_H
#define CASSLOGGING_H

#include <QObject>
#include <qdatetime.h>
#include <qdir.h>
#include <qfile.h>
#include <qtextstream.h>

namespace Cass {
    namespace FileIO {
        class CassLogging : public QObject
        {
            Q_OBJECT
        public:
            CassLogging(QObject *parent, QString folder, QString fileNameOnly);
            QDateTime GetEntryDate() const;
            void SetEntryDate(const QDateTime dateTime);
            qreal GetFrequencyNumber() const;
            void SetFrequencyNumber(const qreal frequencyNumber);
            QString GetFrequencyUnits() const;
            void SetFrequencyUnits(const QString frequencyUnits);
            qreal GetFieldStrengthVPM() const;
            void SetFieldStrengthVPM(const qreal fieldStrengthVPM);
            qreal GetAmplifierOutputDBM() const;
            void SetAmplifierOutputDBM(const qreal amplifierOutputDBM);
            QString GetAmplitudeWasMaintained() const;
            void SetAmplitudeWasMaintained(const QString amplitudeWasMaintained);

            QString GetPath() const;
            QString GetFilenameOnly() const;

            enum class LogErrors {None = 0, FolderCreateFail, FileCreateFail, WriteFail, FlushFail};
            LogErrors GetLastError() const;
            QString GetLastQFileErrorText() const;
            bool Write();
            static QString LogErrorsText(const LogErrors lastErr);

        public:
            ~CassLogging();

        private slots:

        signals:

        private:
            QObject *loggingParent;
            QDateTime logEntryDate;
            qreal logFrequencyNumber;
            QString logFrequencyUnits;
            qreal logFieldStrengthVPM;
            qreal logAmplifierOutputDBM;
            QString logAmplitudeWasMaintained;
            QDir logDir;
            QFile *logQFile;
            QString logPath;
            QString logFilenameOnly;
            bool Open();
            bool Close();
            LogErrors lastError;
            QString lastQFileErrorText;
            void ClearLastError();
        };
    }
}

#endif // CASSLOGGING_H
