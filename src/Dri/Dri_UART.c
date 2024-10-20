#include <STC89C5xRC.H>
#include "Dri_UART.h"
#include "Com_Util.h"
#include "Dri_Timer0.h"

// 定义一个静态位变量来表示是否正在发送数据
static bit s_is_sending = 0; // 0: 未在发送; 1: 正在发送
static char s_buffer[16];
static u8 s_index = 0;

static u8 s_idle_count   = 0;
static bit s_is_complete = 0;

void Dri_UART_Timer0Callback()
{
    s_idle_count++;
    if (s_index > 0 && s_idle_count >= 10) {
        // 数据接收完毕
        s_is_complete = 1;
    }
}

void Dri_UART_Init()
{
    // 1. 设置串口工作模式
    SM0 = 0;
    SM1 = 1;

    // 2. 波特率设置
    // 2.1 SMOD设置
    PCON &= 0x7F;

    // 2.2 定时器1设置;
    // 2.2.1 工作模式设置
    TMOD &= 0x0F;
    TMOD |= 0x20;

    // 2.2.2 初始值设置
    TL1 = 253; // 0xFD
    TH1 = 253;

    // 2.2.3 启动定时器
    TR1 = 1;

    // 3.接收数据相关配置
    REN = 1;
    SM2 = 0;

    // 4.串口中断相关配置
    EA = 1;
    ES = 1;
    RI = 0;
    TI = 0;

    // 5. 注册空闲检测函数
    Dri_Timer0_RegisterCallback(Dri_UART_Timer0Callback);
}

void Dri_UART_SendChar(char c)
{
    while (s_is_sending == 1);
    s_is_sending = 1;
    SBUF         = c;
}

void Dri_UART_SendStr(char *str)
{
    while (*str != 0) {
        Dri_UART_SendChar(*str);
        str++;
    }
}

bit Dri_UART_ReceiveStr(char *str)
{
    if (s_is_complete == 1) {
        u8 i;
        for (i = 0; i < s_index; i++) {
            str[i] = s_buffer[i];
        }
        str[s_index]  = '\0';
        s_is_complete = 0;
        s_index       = 0;
        return 1;
    }
    return 0;
}

/**
 * @brief 串口中断处理函数
 *
 * 该函数处理接收和发送中断，根据接收到的数据进行相应操作，并重置发送标志
 */
void Dri_UART_Handler() interrupt 4
{
    if (RI == 1) {
        s_buffer[s_index++] = SBUF;
        s_idle_count        = 0;
        RI                  = 0;
    }
    if (TI == 1) {
        s_is_sending = 0;
        TI           = 0;
    }
}