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
    Dri_IIC_Start();            // ��ʼд��
    Dri_IIC_SendByte(DEV_ADDR); // �����豸��ַ
    Dri_IIC_ReceiveAck();       // ������Ӧ
    Dri_IIC_SendByte(addr);     // ��ʼ��ַ
    Dri_IIC_ReceiveAck();       // ������Ӧ

    // ��������
    for (i = 0; i < len; i++) {
        Dri_IIC_SendByte(bytes[i]);
        Dri_IIC_ReceiveAck();
    }
    // ֹͣ
    Dri_IIC_Stop();
    // ��ʱд��
    Com_Delayms(5);
}

void Int_EEPROM_WriteBytes(u8 addr, u8 bytes[], u8 len)
{
    u8 page_remain = PAGE_SIZE - addr % PAGE_SIZE;

    if (len > page_remain) {
        // ��ǰҳ�ռ䲻��
        // 1. д����ǰҳ
        Int_EEPROM_WritePage(addr, bytes, page_remain);
        // 2. дʣ��nw
        Int_EEPROM_WriteBytes(addr + page_remain, bytes + page_remain, len - page_remain);

    } else {
        // ��ǰҳ�ռ����
        Int_EEPROM_WritePage(addr, bytes, len);
        P22 = 0;
    }
}

void Int_EEPROM_ReadBytes(u8 addr, u8 bytes[], u8 len)
{
    u8 i;

    Dri_IIC_Start();            // ��ʼ
    Dri_IIC_SendByte(DEV_ADDR); // �����豸��ַ
    Dri_IIC_ReceiveAck();       // ������Ӧ
    Dri_IIC_SendByte(addr);     // αд
    Dri_IIC_ReceiveAck();       // ������Ӧ

    // ��
    Dri_IIC_Start();
    Dri_IIC_SendByte(DEV_ADDR + 1); // �����豸��ַ (����ʶ)
    Dri_IIC_ReceiveAck();

    for (i = 0; i < len; i++) {
        bytes[i] = Dri_IIC_ReceiveByte();
        // Dri_UART_SendChar(Dri_IIC_ReceiveByte());

        Dri_IIC_SendAck(i == len - 1 ? 1 : 0); // ���һҳʱ����ֹͣ�ź�
    }

    Dri_IIC_Stop();
}

void Int_EEPROM_AT24C512B_WritePage(u16 addr, u8 bytes[], u8 len)
{
    u8 i;
    Dri_IIC_Start();             // ��ʼд��
    Dri_IIC_SendByte(DEV_ADDR);  // �����豸��ַ
    Dri_IIC_ReceiveAck();        // ������Ӧ
    Dri_IIC_SendByte(addr);      // ��ʼ��ַ1
    Dri_IIC_ReceiveAck();        // ������Ӧ
    Dri_IIC_SendByte(addr >> 8); // ��ʼ��ַ2
    Dri_IIC_ReceiveAck();        // ������Ӧ

    // ��������
    for (i = 0; i < len; i++) {
        Dri_IIC_SendByte(bytes[i]);
        Dri_IIC_ReceiveAck();
    }
    // ֹͣ
    Dri_IIC_Stop();
    // ��ʱд��
    Com_Delayms(5);
}

void Int_EEPROM_AT24C512B_ReadBytes(u16 addr, u8 bytes[], u8 len)
{
    u8 i;
    // αд
    Dri_IIC_Start();             // ��ʼд��
    Dri_IIC_SendByte(DEV_ADDR);  // �����豸��ַ
    Dri_IIC_ReceiveAck();        // ������Ӧ
    Dri_IIC_SendByte(addr);      // ��ʼ��ַ1
    Dri_IIC_ReceiveAck();        // ������Ӧ
    Dri_IIC_SendByte(addr >> 8); // ��ʼ��ַ2
    Dri_IIC_ReceiveAck();        // ������Ӧ

    // ��
    Dri_IIC_Start();
    Dri_IIC_SendByte(DEV_ADDR + 1); // �����豸��ַ (����ʶ)
    Dri_IIC_ReceiveAck();           // ������Ӧ

    for (i = 0; i < len; i++) {
        bytes[i] = Dri_IIC_ReceiveByte();
        Dri_IIC_SendAck(i == len - 1 ? 1 : 0); // ���һҳʱ����ֹͣ�ź�
    }

    Dri_IIC_Stop();
}
