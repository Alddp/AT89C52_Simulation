#include <STC89C5xRC.H>
#include "Dri_Timer0.h"
#include "Com_Util.h"
#include "Int_LED.h"

void Dri_Timer0_Init()
{
    // 1. 启用中断
    EA  = 1;
    ET0 = 1;

    // 2. 工作模式 GATE:0(0定时器计数,1脉冲计数); C/T:0; M1:0; M0:1
    TMOD &= 0xF0;
    TMOD |= 0x01;

    // 3. 设置初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 4. 启动寄存器
    TR0 = 1;
}

void Dir_Timer0_Handler() interrupt 1
{
    static u16 count = 0;
    // 1. 设置初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    count++;
    if (count >= 500) {
        D1    = ~D1;
        count = 0;
    }
}
