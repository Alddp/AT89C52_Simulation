#include "Int_LEDMatrix.h"
#include "Dri_Timer0.h"
#include "Int_EEPROM.h"
#include "Com_Util.h"

void main()
{
    // ����һ������ѭ�������ı���i
    u8 i;
    u8 picture[] = {0x08, 0x1C, 0x2A, 0x08, 0x1C, 0x22, 0x42, 0x84, 0x4A, 0x2A, 0x1C, 0x08, 0x1C, 0x22, 0x42, 0x84,
                    0x4A, 0x2A, 0x1C, 0x08, 0x08, 0x1C, 0x1C, 0x36, 0x36, 0x22, 0x00};

    u8 p_len = sizeof(picture) / sizeof(picture[0]);

    // ��ʼ����ʱ��0��Ϊ��������ʱ������׼��
    Dri_Timer0_Init();
    // ��ʼ��LED����׼����ʼ��ʾͼ��
    Int_LEDMatrix_Init();

    Int_EEPROM_WriteBytes(0x00, picture, p_len);

    // ���picture����
    for (i = 0; i < p_len; i++) {
        picture[i] = 0x00;
    }

    Int_EEPROM_ReadBytes(0x00, picture, p_len);

    while (1) {
        // ����ͼ�����飬��ÿ��ͼ����ʾ��LED������
        for (i = 0; i < p_len; i++) {
            // ����ǰͼ��������ʾ��LED������
            Int_LEDMatrix_Shift(picture[i]);
            Com_Delayms(200);
        }
    }
}