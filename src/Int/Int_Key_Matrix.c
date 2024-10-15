#include "Int_Key_Matrix.h"
#include <STC89C5xRC.H>

u8 Int_Key_Matrix_CheckS()
{
    u8 Lines[4] = {0x7F, 0xBF, 0xDf, 0xEF};
    u8 i        = 0;

    for (i; i < 4; i++) {
        P1 = Lines[i];
        if (P13 == 0) {
            Com_Delayms(10);
            if (P13 == 0) {
                while (P13 == 0);
                return 4 * i + 1;
            }
        }
        if (P12 == 0) {
            Com_Delayms(10);
            if (P12 == 0) {
                while (P12 == 0);
                return 4 * i + 2;
            }
        }
        if (P11 == 0) {
            Com_Delayms(10);
            if (P11 == 0) {
                while (P11 == 0);
                return 4 * i + 3;
            }
        }
        if (P10 == 0) {
            Com_Delayms(10);
            if (P10 == 0) {
                while (P10 == 0);
                return 4 * i + 4;
            }
        }
    }
    return 0;
}