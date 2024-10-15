#include "Com_Util.h"

void Com_Delay1ms(void) //@11.0592MHz
{
    unsigned char data i, j;

    _nop_();
    i = 2;
    j = 199;
    do {
        while (--j);
    } while (--i);
}

void Com_Delay1s(void) //@11.0592MHz
{
    unsigned char data i, j, k;

    _nop_();
    i = 8;
    j = 1;
    k = 243;
    do {
        do {
            while (--k);
        } while (--j);
    } while (--i);
}

/**
 * @brief —” ±∫Ø ˝
 * @param times ∫¡√Î
 */
void Com_Delayms(int times) //@11.0592MHz
{
    int i;
    for (i = 0; i < times; i++) {
        Com_Delay1ms();
    }
}