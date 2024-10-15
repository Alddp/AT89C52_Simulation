#include <STC89C5xRC.H>

#include "Com_Util.h"

void main()
{
    u8 tmp = 0x01; // 0000 0001
    P0     = 0xFE; // 1111 1110
    Com_Delayms(1000);
    while (1) {
        tmp <<= 1;
        if (tmp == 0x00) tmp = 0x01;
        P0 = ~tmp;
        Com_Delayms(1000);
    }
}
