#include "Int_EEPROM.h"
#include "Dri_IIC.h"
#include "Com_Util.h"
#include <STC89C5xRC.H>

// #include "Dri_UART.h"

#define DEV_ADDR  0xA0
#define PAGE_SIZE 8

void Int_EEPROM_WritePage(u8 addr, u8 bytes[], u8 len)
{
    u8 i;
    Dri_IIC_Start();            // 开始写入
    Dri_IIC_SendByte(DEV_ADDR); // 发送设备地址
    Dri_IIC_ReceiveAck();       // 接收响应
    Dri_IIC_SendByte(addr);     // 起始地址
    Dri_IIC_ReceiveAck();       // 接收响应

    // 发送数据
    for (i = 0; i < len; i++) {
        Dri_IIC_SendByte(bytes[i]);
        Dri_IIC_ReceiveAck();
    }
    // 停止
    Dri_IIC_Stop();
    // 延时写入
    Com_Delayms(5);
}

void Int_EEPROM_WriteBytes(u8 addr, u8 bytes[], u8 len)
{
    u8 page_remain = PAGE_SIZE - addr % PAGE_SIZE;

    if (len > page_remain) {
        // 当前页空间不足
        // 1. 写满当前页
        Int_EEPROM_WritePage(addr, bytes, page_remain);
        // 2. 写剩余nw
        Int_EEPROM_WriteBytes(addr + page_remain, bytes + page_remain, len - page_remain);

    } else {
        // 当前页空间充足
        Int_EEPROM_WritePage(addr, bytes, len);
        P22 = 0;
    }
}

void Int_EEPROM_ReadBytes(u8 addr, u8 bytes[], u8 len)
{
    u8 i;

    Dri_IIC_Start();            // 开始
    Dri_IIC_SendByte(DEV_ADDR); // 发送设备地址
    Dri_IIC_ReceiveAck();       // 接收响应
    Dri_IIC_SendByte(addr);     // 伪写
    Dri_IIC_ReceiveAck();       // 接收响应

    // 读
    Dri_IIC_Start();
    Dri_IIC_SendByte(DEV_ADDR + 1); // 发送设备地址 (读标识)
    Dri_IIC_ReceiveAck();

    for (i = 0; i < len; i++) {
        bytes[i] = Dri_IIC_ReceiveByte();
        // Dri_UART_SendChar(Dri_IIC_ReceiveByte());

        Dri_IIC_SendAck(i == len - 1 ? 1 : 0); // 最后一页时发送停止信号
    }

    Dri_IIC_Stop();
}

void Int_EEPROM_AT24C512B_WritePage(u16 addr, u8 bytes[], u8 len)
{
    u8 i;
    Dri_IIC_Start();             // 开始写入
    Dri_IIC_SendByte(DEV_ADDR);  // 发送设备地址
    Dri_IIC_ReceiveAck();        // 接收响应
    Dri_IIC_SendByte(addr);      // 起始地址1
    Dri_IIC_ReceiveAck();        // 接收响应
    Dri_IIC_SendByte(addr >> 8); // 起始地址2
    Dri_IIC_ReceiveAck();        // 接收响应

    // 发送数据
    for (i = 0; i < len; i++) {
        Dri_IIC_SendByte(bytes[i]);
        Dri_IIC_ReceiveAck();
    }
    // 停止
    Dri_IIC_Stop();
    // 延时写入
    Com_Delayms(5);
}

void Int_EEPROM_AT24C512B_ReadBytes(u16 addr, u8 bytes[], u8 len)
{
    u8 i;
    // 伪写
    Dri_IIC_Start();             // 开始写入
    Dri_IIC_SendByte(DEV_ADDR);  // 发送设备地址
    Dri_IIC_ReceiveAck();        // 接收响应
    Dri_IIC_SendByte(addr);      // 起始地址1
    Dri_IIC_ReceiveAck();        // 接收响应
    Dri_IIC_SendByte(addr >> 8); // 起始地址2
    Dri_IIC_ReceiveAck();        // 接收响应

    // 读
    Dri_IIC_Start();
    Dri_IIC_SendByte(DEV_ADDR + 1); // 发送设备地址 (读标识)
    Dri_IIC_ReceiveAck();           // 接收响应

    for (i = 0; i < len; i++) {
        bytes[i] = Dri_IIC_ReceiveByte();
        Dri_IIC_SendAck(i == len - 1 ? 1 : 0); // 最后一页时发送停止信号
    }

    Dri_IIC_Stop();
}
