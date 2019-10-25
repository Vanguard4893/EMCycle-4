#include "controllerstat.h"
#include <QtEndian>

namespace Cass {
    namespace SerialIO {
    //Const
    const QChar Space = QLatin1Char(' ');

        //Public
        ControllerSTAT::ControllerSTAT(QObject *parent) : QObject(parent)
        {
            serialParent = parent;
            Clear();
        }

        void ControllerSTAT::Clear() {
            selectInputStatus = 0;
            dI4 = false;
            dI3 = false;
            dI2 = false;
            dI1 = false;
            anIP4Enabled = false;
            anIP3Enabled = false;
            anIP2Enabled = false;
            anIP1Enabled = false;
            anIP0Enabled = false;
            inputScanRate = 0;
            anIP0 = 0;
            anIP1 = 0;
            anIP2 = 0;
            anIP3 = 0;
            anIP4 = 0;
            anOP1Active = false;
            anOP2Active = false;
            relayOP1Active = false;
            relayOP2Active = false;
            ocOP1Active = false;
            ocOP2Active = false;
            outputSweepTime = 0;
            errorCode = 0;
            checksum = 0;
        }

        bool ControllerSTAT::Populate(QByteArray STAT) {
            bool returnValue = true;
            quint8 byte;

            inParts = STAT.split(Space.toLatin1());

            convertOK = false;
            //00 00 00 00 00 00 05 3A 92 49 91 11 00 42 00 00 00 01 FE"

            if (inParts.length() == NumberOfFields) {
                //Once
                int part = 0;
                for (int i = 0; i<1; i++) {
                    selectInputStatus = Bits8FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }

                    byte = Bits8FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    dI4 = IsBitSet(byte, 7);
                    dI3 = IsBitSet(byte, 6);
                    dI2 = IsBitSet(byte, 5);
                    dI1 = IsBitSet(byte, 4);

                    byte = Bits8FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    anIP4Enabled = IsBitSet(byte, 7);
                    anIP3Enabled = IsBitSet(byte, 6);
                    anIP2Enabled = IsBitSet(byte, 5);
                    anIP1Enabled = IsBitSet(byte, 4);
                    anIP0Enabled = IsBitSet(byte, 3);

                    inputScanRate = Bits8FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    anIP0 = Bits16FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    anIP1 = Bits16FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    anIP2 = Bits16FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    anIP3 = Bits16FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    anIP4 = Bits16FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }

                    byte = Bits8FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    anOP1Active  = IsBitSet(byte, 7);
                    anOP2Active = IsBitSet(byte, 6);
                    relayOP1Active = IsBitSet(byte, 5);
                    relayOP2Active = IsBitSet(byte, 4);
                    ocOP1Active = IsBitSet(byte, 3);
                    ocOP2Active = IsBitSet(byte, 2);
                    outputSweepTime = Bits8FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    errorCode = Bits8FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                    checksum = Bits16FromBigEndian(inParts, part, convertOK);
                    if (!convertOK) {
                        returnValue = false;
                        break;
                    }
                }
            } else {
                returnValue = false;
            }

            return returnValue;
        }

        //Properties
        quint8 ControllerSTAT::GetSelectInputStatus() {
            return selectInputStatus;
        }
        bool ControllerSTAT::GetDI4() {
            return dI4;
        }
        bool ControllerSTAT::GetDI3() {
            return dI3;
        }
        bool ControllerSTAT::GetDI2() {
            return dI2;
        }
        bool ControllerSTAT::GetDI1() {
            return dI1;
        }
        bool ControllerSTAT::GetAnIP4Enabled() {
            return anIP4Enabled;
        }
        bool ControllerSTAT::GetAnIP3Enabled() {
            return anIP3Enabled;
        }
        bool ControllerSTAT::GetAnIP2Enabled() {
            return anIP2Enabled;
        }
        bool ControllerSTAT::GetAnIP1Enabled() {
            return anIP1Enabled;
        }
        bool ControllerSTAT::GetAnIP0Enabled() {
            return anIP0Enabled;
        }
        quint8 ControllerSTAT::GetInputScanRate() {
            return inputScanRate;
        }
        quint16 ControllerSTAT::GetAnIP0() {
            return anIP0;
        }
        quint16 ControllerSTAT::GetAnIP1() {
            return anIP1;
        }
        quint16 ControllerSTAT::GetAnIP2() {
            return anIP2;
        }
        quint16 ControllerSTAT::GetAnIP3() {
            return anIP3;
        }
        quint16 ControllerSTAT::GetAnIP4() {
            return anIP4;
        }
        bool ControllerSTAT::GetAnOP1Active() {
            return anOP1Active;
        }
        bool ControllerSTAT::GetAnOP2Active() {
            return anOP2Active;
        }
        bool ControllerSTAT::GetRelayOP1Active() {
            return relayOP1Active;
        }
        bool ControllerSTAT::GetRelayOP2Active() {
            return relayOP2Active;
        }
        bool ControllerSTAT::GetOcOP1Active() {
            return ocOP1Active;
        }
        bool ControllerSTAT::GetOcOP2Active() {
            return ocOP2Active;
        }
        quint8 ControllerSTAT::GetOutputSweepTime() {
            return outputSweepTime;
        }
        quint8 ControllerSTAT::GetErrorCode() {
            return errorCode;
        }
        quint16 ControllerSTAT::GetChecksum() {
            return checksum;
        }

        //Private
        bool ControllerSTAT::IsBitSet(quint8 b, quint8 pos) {
           return ((b & (1 << pos)) != 0);
        }

        quint16 ControllerSTAT::Bits16FromBigEndian(QList<QByteArray> &inParts, int &index, bool &BitsConverted) {
            quint16 twoByteValue = 0;
            QByteArray twoByteHex;

            BitsConverted = false;
            twoByteHex = inParts[index] + inParts[index+1];
            index += 2;
            twoByteValue = static_cast<quint16>(twoByteHex.toUShort(&BitsConverted, Hex));
            if (BitsConverted) {
                twoByteValue = qToLittleEndian(twoByteValue);
            }
            return twoByteValue;
        }

        quint8 ControllerSTAT::Bits8FromBigEndian(QList<QByteArray> &inParts, int &index, bool &BitsConverted) {
            ushort asUShort = 0;
            quint8 asByte = 0;

            BitsConverted = false;
            asUShort = (QString(inParts[index++])).toUShort(&BitsConverted, Hex);

            if (BitsConverted) {
                asByte = static_cast<quint8>(qToLittleEndian(asUShort));
            }

            return asByte;
        }
    }
}

