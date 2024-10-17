#include "Int_LEDMatrix.h"
#include <STC89C5xRC.H>

#define DS    P34 // �������������
#define SRCLK P36 // ��λ�Ĵ���
#define RCLK  P35 // �洢�Ĵ���

static u8 s_buffer[8]; // �洢��ʾ����(P0�Ĵ���״̬)
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
        P0 = 0xFF; // ����ϴεļ�¼
        // 1. ������ʾ����
        if (i == 0)
            DS = 1;
        else
            DS = 0;

        SRCLK = 0;
        SRCLK = 1;

        RCLK = 0;
        RCLK = 1;

        // 2. ������ʾ����
        P0 = ~s_buffer[i];
        Com_Delayms(2);
    }
}
