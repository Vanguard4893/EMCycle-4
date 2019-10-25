#include "scpi_commands.h"

namespace Cass {
    namespace LXI {

    const QString SCPI_Commands::uHz = QStringLiteral("uHz");
    const QString SCPI_Commands::mHz = QStringLiteral("mHz");
    //Upper
    const QString SCPI_Commands::HZ = QStringLiteral("HZ");
    const QString SCPI_Commands::KHZ = QStringLiteral("KHZ");
    const QString SCPI_Commands::MHZ = QStringLiteral("MHZ");
    const QString SCPI_Commands::GHZ = QStringLiteral("GHZ");
    const QString SCPI_Commands::THZ = QStringLiteral("THZ");
    const QString SCPI_Commands::PHZ = QStringLiteral("PHZ");

    //Top Level
    const QString SCPI_Commands::SYST = QStringLiteral("SYST");
    const QString SCPI_Commands::MMEM = QStringLiteral("MMEM");
    const QString SCPI_Commands::OUTP = QStringLiteral("OUTP");
    const QString SCPI_Commands::SOUR = QStringLiteral("SOUR");

    const QString SCPI_Commands::STAT = QStringLiteral("STAT");
    const QString SCPI_Commands::TRIG = QStringLiteral("TRIG");
    const QString SCPI_Commands::UNIT = QStringLiteral("UNIT");
    const QString SCPI_Commands::FREQ = QStringLiteral("FREQ");

    const QString SCPI_Commands::CALC = QStringLiteral("CALC");
    const QString SCPI_Commands::CONT = QStringLiteral("CONT");
    const QString SCPI_Commands::DIAG = QStringLiteral("DIAG");
    const QString SCPI_Commands::DISP = QStringLiteral("DISP");

    const QString SCPI_Commands::FORM = QStringLiteral("FORM");
    const QString SCPI_Commands::HCOP = QStringLiteral("HCOP");
    const QString SCPI_Commands::PROG = QStringLiteral("PROG");
    const QString SCPI_Commands::ROUT = QStringLiteral("ROUT");

    const QString SCPI_Commands::SENS = QStringLiteral("SENS");
    const QString SCPI_Commands::TEST = QStringLiteral("TEST");
    const QString SCPI_Commands::TRAC = QStringLiteral("TRAC");
    const QString SCPI_Commands::DEPT = QStringLiteral("DEPT");

    //Three letter
    const QString SCPI_Commands::DEF = QStringLiteral("DEF");
    const QString SCPI_Commands::DEL = QStringLiteral("DEL");
    const QString SCPI_Commands::CAT = QStringLiteral("CAT");
    const QString SCPI_Commands::CAL = QStringLiteral("CAL");

    const QString SCPI_Commands::MEM = QStringLiteral("MEM");
    const QString SCPI_Commands::VXI = QStringLiteral("VXI");
    const QString SCPI_Commands::INP = QStringLiteral("INP");
    const QString SCPI_Commands::CLS = QStringLiteral("CLS");

    const QString SCPI_Commands::ESE = QStringLiteral("ESE");
    const QString SCPI_Commands::ESR = QStringLiteral("ESR");
    const QString SCPI_Commands::RST = QStringLiteral("RST");
    const QString SCPI_Commands::SRE = QStringLiteral("SRE");

    const QString SCPI_Commands::TST = QStringLiteral("TST");
    const QString SCPI_Commands::STB = QStringLiteral("STB");
    const QString SCPI_Commands::IDN = QStringLiteral("IDN");
    const QString SCPI_Commands::OPC = QStringLiteral("OPC");

    const QString SCPI_Commands::WAI = QStringLiteral("WAI");
    const QString SCPI_Commands::LEV = QStringLiteral("LEV");
    const QString SCPI_Commands::ATT = QStringLiteral("ATT");
    const QString SCPI_Commands::MOD = QStringLiteral("MOD");

    //Misc
    const QString SCPI_Commands::MODE = QStringLiteral("MODE");

    //Two letter.
    const QString SCPI_Commands::AM = QStringLiteral("AM");

    //ENUMS
    const QString SCPI_Commands::AUTO = QStringLiteral("AUTO");
    const QString SCPI_Commands::FIX = QStringLiteral("FIX");
    const QString SCPI_Commands::ON = QStringLiteral("ON");
    const QString SCPI_Commands::OFF = QStringLiteral("OFF");
    const QString SCPI_Commands::No0 = QStringLiteral("0");
    const QString SCPI_Commands::No1 = QStringLiteral("1");


    //Compound Commands
    const QString SCPI_Commands::SOUR_LEV = SCPI_Commands::Colon + &SCPI_Commands::SOUR +
            SCPI_Commands::Colon + SCPI_Commands::LEV;

    const QString SCPI_Commands::SOUR_LEV_ATT = SCPI_Commands::Colon + &SCPI_Commands::SOUR +
            SCPI_Commands::Colon + SCPI_Commands::LEV +
            SCPI_Commands::Colon + SCPI_Commands::ATT;

    const QString SCPI_Commands::SOUR_LEV_ATT_MODE = SCPI_Commands::Colon + &SCPI_Commands::SOUR +
            SCPI_Commands::Colon + SCPI_Commands::LEV +
            SCPI_Commands::Colon + SCPI_Commands::ATT +
            SCPI_Commands::Colon + SCPI_Commands::MODE;
    //
    const QString SCPI_Commands::SOUR_FREQ = SCPI_Commands::Colon + &SCPI_Commands::SOUR +
            SCPI_Commands::Colon + SCPI_Commands::FREQ;
    //AM
    const QString SCPI_Commands::SOUR_AM_DEPT = SCPI_Commands::Colon + &SCPI_Commands::SOUR +
            SCPI_Commands::Colon + SCPI_Commands::AM +
            SCPI_Commands::Colon + SCPI_Commands::DEPT;
    const QString SCPI_Commands::SOUR_AM_FREQ = SCPI_Commands::Colon + &SCPI_Commands::SOUR +
            SCPI_Commands::Colon + SCPI_Commands::AM +
            SCPI_Commands::Colon + SCPI_Commands::FREQ;
    const QString SCPI_Commands::SOUR_AM_STAT = SCPI_Commands::Colon + &SCPI_Commands::SOUR +
            SCPI_Commands::Colon + SCPI_Commands::AM +
            SCPI_Commands::Colon + SCPI_Commands::STAT;
    //MOD
    const QString SCPI_Commands::SOUR_MOD_STAT = SCPI_Commands::Colon + &SCPI_Commands::SOUR +
            SCPI_Commands::Colon + SCPI_Commands::MOD +
            SCPI_Commands::Colon + SCPI_Commands::STAT;


    //Special chars
    const QChar SCPI_Commands::Question = '?';
    const QChar SCPI_Commands::Star = '*';
    const QChar SCPI_Commands::Colon = ':';
    const QChar SCPI_Commands::Space = ' ';
    const QChar SCPI_Commands::NullChar = QChar::Null;
    const QChar SCPI_Commands::DecimalPoint = '.';
    const QString SCPI_Commands::EmptyString = QStringLiteral("");

    QString SCPI_Commands::Sum = EmptyString;
    QString SCPI_Commands::Value = EmptyString;
    QString SCPI_Commands::FreqUnitStr = EmptyString;
    QString SCPI_Commands::ON_OFFStr = EmptyString;
    bool SCPI_Commands::OK = false;

        SCPI_Commands::SCPI_Commands()
        {
        }

        bool SCPI_Commands::IsQuestion(const QString *command) {
            return (*command).endsWith(Question);
        }

        QString* SCPI_Commands::PostfixQuestion(const QString *command) {
            Sum = *command + Question;
            return  &Sum;
        }

        QString* SCPI_Commands::PrefixColon(const QString *command) {
            Sum = Colon + *command;
            return  &Sum;
        }

        QString* SCPI_Commands::PrefixStar(const QString *command) {
            Sum = Star + *command;
            return  &Sum;
        }

        QString* SCPI_Commands::PostfixSpaceValue(const QString *command, const QString *value) {
            Sum = *command + Space + *value;
            return  &Sum;
        }

        QString* SCPI_Commands::PostfixSpaceValue(const QString *command, const QString *valueOne, const QString *valueUnit) {
            Sum = *command + Space + *valueOne + *valueUnit;
            return  &Sum;
        }

        QString* SCPI_Commands::PostfixSpaceValueFreqUnit(const QString *command, const QString *valueOne, const FrequencyUnit *freqUnit) {
            Sum = *command + Space + *valueOne + *ToString(freqUnit);
            return  &Sum;
        }

        QString* SCPI_Commands::PostfixSpaceON_OFF(const QString *command, const ON_OFF *on_off) {
            Sum = *command + Space + *ToString(on_off);
            return  &Sum;
         }

        QString* SCPI_Commands::CleanNumber(const QString *reply, QString *units) {
            units->clear();
            //Nonsense out, replace with spaces.
            Value = (*reply).simplified();
            QStringList parts = Value.split(Space, QString::SkipEmptyParts);
            if (parts.count() > 0) {
                //Non digit
                QRegExp nonDigit("\\D");
                QRegExp digits("\\d+");
                QStringList endings = parts.last().split(digits, QString::SkipEmptyParts);
                if (endings.count() > 0) {
                    //We have 00GHz or . and Hz.
                    bool hasDecimalPoint = (endings.count() >= 2);
                    QStringList endValue = parts.last().split(nonDigit, QString::SkipEmptyParts);
                    *units = endings.last();
                    parts.last().clear();
                    //Need to rejoin the last part with DP.
                    if (hasDecimalPoint) {
                        QString allEndValues = endValue.join(DecimalPoint);
                        parts.last() = allEndValues;
                    } else {
                        parts.last() = endValue[0];
                    }
                }
            } else {
                //Dont see how we can get here.
            }
            //Assemble it back as a number
            Value = parts.join(EmptyString);
            return &Value;
        }

        //Conversions. Values are often in floating form "44.0" for example.
        bool SCPI_Commands::ToValue(quint8 *byte, const QString *reply) {
            qreal asDouble = (*reply).toDouble(&OK);
            if (OK) {
                *byte = static_cast<quint8>(asDouble);
            }
            return OK;
        }

        QString* SCPI_Commands::ToString(const quint8 *byte) {
            Value = QString("%1").arg(*byte);
            return &Value;
        }

        bool SCPI_Commands::ToValue(qreal *qReal, const QString *reply) {
            *qReal = (*reply).toDouble(&OK);
            return OK;
        }

        QString* SCPI_Commands::ToString(const qreal *qReal) {
            Value = QString("%1").arg(*qReal);
            return &Value;
        }

        bool SCPI_Commands::ToValue(quint64 *quint64, const QString *reply) {
            *quint64 = (*reply).toULongLong(&OK);
            return OK;
        }

        QString* SCPI_Commands::ToString(const quint64 *quint64) {
            Value = QString("%1").arg(*quint64);
            return &Value;
        }

        SCPI_Commands::FrequencyUnit SCPI_Commands::FromFrequencyUnit(const QString *freqUnit) {
            QString asUpper = (*freqUnit).toUpper();

            //uHz, mHz, Hz, KHz, MHz, GHz, THz, PHz
            if (*freqUnit == SCPI_Commands::uHz) {
                return  SCPI_Commands::FrequencyUnit::mHz; }

            if (*freqUnit == SCPI_Commands::mHz) {
                return  SCPI_Commands::FrequencyUnit::mHz; }

            //Upper
            if (asUpper == SCPI_Commands::HZ) {
                return  SCPI_Commands::FrequencyUnit::Hz; }

            if (asUpper == SCPI_Commands::KHZ) {
                return  SCPI_Commands::FrequencyUnit::kHz; }

            if (asUpper == SCPI_Commands::MHZ) {
                return  SCPI_Commands::FrequencyUnit::MHz; }

            if (asUpper == SCPI_Commands::GHZ) {
                return  SCPI_Commands::FrequencyUnit::GHz; }

            if (asUpper == SCPI_Commands::THZ) {
                return  SCPI_Commands::FrequencyUnit::THz; }

            if (asUpper == SCPI_Commands::PHZ) {
                return  SCPI_Commands::FrequencyUnit::PHz; }

            return SCPI_Commands::FrequencyUnit::None;
        }

        QString* SCPI_Commands::ToString(const FrequencyUnit *freqUnit) {

            switch (*freqUnit) {
                case FrequencyUnit::uHz:
                    FreqUnitStr = SCPI_Commands::uHz;
                break;
                case FrequencyUnit::mHz:
                    FreqUnitStr = SCPI_Commands::mHz;
                break;
                case FrequencyUnit::Hz:
                    FreqUnitStr = SCPI_Commands::HZ;
                break;
                case FrequencyUnit::kHz:
                    FreqUnitStr = SCPI_Commands::KHZ;
                break;
                case FrequencyUnit::MHz:
                    FreqUnitStr = SCPI_Commands::MHZ;
                break;
                case FrequencyUnit::GHz:
                    FreqUnitStr = SCPI_Commands::GHZ;
                break;
                case FrequencyUnit::THz:
                    Value = SCPI_Commands::THZ;
                break;
                case FrequencyUnit::PHz:
                    FreqUnitStr = SCPI_Commands::PHZ;
                break;
                default:
                    FreqUnitStr = EmptyString;
            }
            return &FreqUnitStr;
        }

        SCPI_Commands::ON_OFF SCPI_Commands::FromON_OFF(const QString *ON_OFF) {
            QString asUpper = (*ON_OFF).toUpper();

            //None = 0, ON, OFF, reresented by 1 and 0.
            //Upper
            if (asUpper == SCPI_Commands::No1) {
                return  SCPI_Commands::ON_OFF::ON; }

            if (asUpper == SCPI_Commands::No0) {
                return  SCPI_Commands::ON_OFF::OFF; }

            return SCPI_Commands::ON_OFF::None;
        }

        QString* SCPI_Commands::ToString(const ON_OFF *ON_OFF) {

            switch (*ON_OFF) {
                case ON_OFF::ON:
                    ON_OFFStr = SCPI_Commands::ON;
                break;
                case ON_OFF::OFF:
                    ON_OFFStr = SCPI_Commands::OFF;
                break;
                default:
                    ON_OFFStr = EmptyString;
            }
            return &ON_OFFStr;
        }




    }
}

