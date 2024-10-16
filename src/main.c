#include <STC89C5xRC.H>
#include "Int_LED.h"
#include "Com_Util.h"

// 中断服务程序
void test() interrupt 0
{
    D1 = ~D1; // 切换 LED 状态
}
void main()
{
    EA  = 1; // 开启全局中断
    EX0 = 1; // 使能外部中断0
    IT0 = 1; // 设置为电平触发模式（IT0 = 0）

    while (1) {
        IE0 = 1;
        D2  = ~D2;
        Com_Delay1s();
        // Com_Delayms(200);
    }
}
