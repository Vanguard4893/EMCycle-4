#ifndef SCPI_COMMANDS_H
#define SCPI_COMMANDS_H

#include <qobject.h>

namespace Cass {
    namespace LXI {
        class SCPI_Commands
        {
        public:
            SCPI_Commands();

            //Enum
            enum class FrequencyUnit {None = 0, uHz, mHz, Hz, kHz, MHz, GHz, THz, PHz};
            enum class ON_OFF {None = 0, ON, OFF};

            static bool IsQuestion(const QString *command);
            static QString* PostfixQuestion(const QString *command);
            static QString* PrefixColon(const QString *command);
            static QString* PrefixStar(const QString *command);
            static QString* PostfixSpaceValue(const QString *command, const QString *value);
            static QString* PostfixSpaceValue(const QString *command, const QString *valueOne, const QString *valueUnit);
            //Freq
            static QString* PostfixSpaceValueFreqUnit(const QString *command, const QString *valueOne, const FrequencyUnit *freqUnit);
            static QString* PostfixSpaceON_OFF(const QString *command, const ON_OFF *on_off);


            static QString* CleanNumber(const QString *reply, QString *units);

            //Conversions
            static bool ToValue(quint8 *byte, const QString *reply);
            static QString* ToString(const quint8 *byte);
            static bool ToValue(qreal *qReal, const QString *reply);
            static QString* ToString(const qreal *qReal);
            static bool ToValue(quint64 *quint64, const QString *reply);
            static QString* ToString(const quint64 *quint64);

            static enum FrequencyUnit FromFrequencyUnit(const QString *freqUnit);
            static QString* ToString(const FrequencyUnit *freqUnit);
            static enum ON_OFF FromON_OFF(const QString *ON_OFF);
            static QString* ToString(const ON_OFF *ON_OFF);

            //Exact
            static const QString uHz;
            static const QString mHz;
            //Upper
            static const QString HZ;
            static const QString KHZ;
            static const QString MHZ;
            static const QString GHZ;
            static const QString THZ;
            static const QString PHZ;

            //Top Level
            static const QString SYST;
            static const QString MMEM;
            static const QString OUTP;
            static const QString SOUR;

            static const QString STAT;
            static const QString TRIG;
            static const QString UNIT;
            static const QString FREQ;

            static const QString CALC;
            static const QString CONT;
            static const QString DIAG;
            static const QString DISP;

            static const QString FORM;
            static const QString HCOP;
            static const QString PROG;
            static const QString ROUT;

            static const QString SENS;
            static const QString TEST;
            static const QString TRAC;
            static const QString DEPT;

            //Three letter
            static const QString DEF;
            static const QString DEL;
            static const QString CAT;
            static const QString CAL;

            static const QString MEM;
            static const QString VXI;
            static const QString INP;
            static const QString CLS;

            static const QString ESE;
            static const QString ESR;
            static const QString RST;
            static const QString SRE;

            static const QString TST;
            static const QString STB;
            static const QString IDN;
            static const QString OPC;

            static const QString WAI;
            static const QString LEV;
            static const QString ATT;
            static const QString MOD;

            //Misc
            static const QString MODE;

            //Two letter.
            static const QString AM;

            //ENUMS
            static const QString AUTO;
            static const QString FIX;
            static const QString ON;
            static const QString OFF;
            static const QString No0;
            static const QString No1;

            //Compound Commands
            static const QString SOUR_LEV;
            static const QString SOUR_LEV_ATT;
            static const QString SOUR_LEV_ATT_MODE;
            //FREQ
            static const QString SOUR_FREQ;
            //AM
            static const QString SOUR_AM_DEPT;
            static const QString SOUR_AM_FREQ;
            static const QString SOUR_AM_STAT;
            //MOD
            static const QString SOUR_MOD_STAT;

        private:
            static const QChar Question;
            static const QChar Star;
            static const QChar Colon;
            static const QChar Space;
            static const QChar NullChar;
            static const QChar DecimalPoint;
            static const QString EmptyString;
            //Buffer
            static QString Sum;
            static QString Value;
            static QString FreqUnitStr;
            static QString ON_OFFStr;
            static bool OK;

        };
    }
}

#endif // SCPI_COMMANDS_H
