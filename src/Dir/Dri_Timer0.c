#include <STC89C5xRC.H>
#include "Dri_Timer0.h"
#include "Com_Util.h"
#include <STDIO.H>

#define MAX_CALLBACK_COUNT 4 // 函数指针数组长度
static Timer0_Callback s_callbacks[MAX_CALLBACK_COUNT];

void Dri_Timer0_Init()
{
    u8 i;
    // 1. 启用中断
    EA  = 1;
    ET0 = 1;

    // 2. 工作模式 GATE:0(0定时器计数,1脉冲计数); C/T:0; M1:0; M0:1
    TMOD &= 0xF0;
    TMOD |= 0x01;

    // 3. 设置初始值 (拆分为高8位和低8位)
    TL0 = 64614 & 0xFF;        // 低8位
    TH0 = (64614 >> 8) & 0xFF; // 高8位

    // 4. 启动寄存器
    TR0 = 1;

    // 5. 初始化指针数组
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        s_callbacks[i] = NULL;
    }
}

/**
 * @brief 注册回调函数
 *
 * @param callback 函数指针
 * @return bit 1:成功; 0:失败
 */
bit Dri_Timer0_RegisterCallback(Timer0_Callback callback)
{
    u8 i;
    // 避免重复注册
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callbacks[i] == callback) {
            return 1;
        }
    }

    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callbacks[i] == NULL) {
            s_callbacks[i] = callback;
            return 1; // 注册成功，返回1
        }
    }

    // 没有空位
    return 0;
}

/**
 * @brief 取消注册回调函数
 *
 * @param callback 要删除的函数
 * @return bit 1:成功; 0:没有找到要删除的函数
 */
bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback)
{
    u8 i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callbacks[i] == callback) {
            s_callbacks[i] = NULL;
            return 1;
        }
    }
    return 0;
}

void Dir_Timer0_Handler() interrupt 1
{
    u8 i;
    // 1. 设置初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 2. 遍历函数指针数组
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callbacks[i] != NULL) { // 修正指针访问错误
            s_callbacks[i]();
        }
    }
}
