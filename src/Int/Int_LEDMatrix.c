#include "Int_LEDMatrix.h"
#include <STC89C5xRC.H>

#define DS    P34 // 串行数据输入口
#define SRCLK P36 // 移位寄存器
#define RCLK  P35 // 存储寄存器

static u8 s_buffer[8]; // 存储显示内容(P0寄存器状态)
void Int_LEDMatrix_SetPic(u8 pic[])
{
    u8 i;
    for (i = 0; i < 8; i++) {
        s_buffer[i] = pic[i];
    }
}

void Int_LEDMatrix_Refresh()
{
    u8 i;

    for (i = 0; i < 8; i++) {
        P0 = 0xFF; // 清空上次的记录
        // 1. 设置显示哪行
        if (i == 0)
            DS = 1;
        else
            DS = 0;

        SRCLK = 0;
        SRCLK = 1;

        RCLK = 0;
        RCLK = 1;

        // 2. 设置显示内容
        P0 = ~s_buffer[i];
        Com_Delayms(2);
    }
}
