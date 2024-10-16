#include "Int_DigitalTube.h"

static unsigned char s_nums[11] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00};

void Int_ShowSingleDigital(u8 position, unsigned short digital)
{

    P0       = 0x00;
    position = (position << 5) >> 3;

    P2 &= 0xE3; // 1110 0011
    P2 |= position;

    P0 = s_nums[digital];
}

u8 *Int_GetDisplayMemery(u32 num)
{

    u8 i;
    static u8 digitals[8]; // 使用静态数组，避免返回局部变量的问题

    for (i = 0; i < 8; i++) {
        digitals[i] = 11;
    }

    if (num == 0) digitals[0] = 0;

    i = 0;
    while (num > 0) {
        digitals[i++] = num % 10;
        num /= 10;
    }
    return digitals;
}

void Int_DigitalRefresh(u8 digitalsTubes[8])
{
    u8 i;
    for (i = 0; i < 8; i++) {
        Int_ShowSingleDigital(i, digitalsTubes[i]); // 显示每个数码管上的数字
        Com_Delayms(1);
    }
}
