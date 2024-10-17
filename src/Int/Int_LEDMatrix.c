#include <STC89C5xRC.H>
#include "Int_LEDMatrix.h"
#include "Dri_Timer0.h"

#define DS    P34 // 串行数据输入口
#define SRCLK P36 // 移位寄存器
#define RCLK  P35 // 存储寄存器

static u8 s_buffer[8]; // 存储显示内容(P0寄存器状态)
void Int_LEDMatrix_RefreshByTimer0();

void Int_LEDMatrix_Init()
{
    Dri_Timer0_RegisterCallback(Int_LEDMatrix_RefreshByTimer0);
}

void Int_LEDMatrix_SetPic(u8 pic[])
{
    u8 i;
    for (i = 0; i < 8; i++) {
        s_buffer[i] = pic[i];
    }
}

void Int_LEDMatrix_Shift(u8 pic)
{
    u8 i = 7;
    for (i = 7; i >= 1; i--) {
        s_buffer[i] = s_buffer[i - 1];
    }
    s_buffer[i] = pic;
}

/**
 * @brief 通过定时器0刷新显示;不断显示s_buffer中的内容
 */
void Int_LEDMatrix_RefreshByTimer0()
{
    static u8 i = 0;
    P0          = 0xFF; // 清空上次的记录

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
    if (i++ >= 8) i = 0;
}