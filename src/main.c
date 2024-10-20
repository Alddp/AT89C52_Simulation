#include "Int_LEDMatrix.h"
#include "Dri_Timer0.h"
#include "Int_EEPROM.h"
#include "Com_Util.h"

// !!!
// #define __AT24C512B__ // ʹ��Proteus����ʱȡ������ע��

void main()
{
    // ����һ������ѭ�������ı���i
    u8 i;
    // ����һ���洢ͼ�����ݵ�����picture��������LED��������ʾͼ��
    u8 picture[] = {0x7E, 0x40, 0x40, 0x3C, 0x42, 0x42, 0x3C, 0x02, 0x7E, 0x60, 0x30, 0x1E,
                    0x00, 0x7E, 0x4A, 0x4A, 0x42, 0x1C, 0x22, 0x42, 0x8C, 0x42, 0x22, 0x1C, 0x00};

    u8 p_len = sizeof(picture) / sizeof(picture[0]);

    // ��ʼ����ʱ��0��Ϊ��������ʱ������׼��
    Dri_Timer0_Init();
    // ��ʼ��LED����׼����ʼ��ʾͼ��
    Int_LEDMatrix_Init();
// ����EEPROM�ͺ�ѡ����ò�ͬ��д�뺯��
// =================================================================
#ifdef __AT24C512B__
    Int_EEPROM_AT24C512B_WritePage(0x0000, picture, p_len);
#else
    Int_EEPROM_WriteBytes(0x00, picture, p_len);
#endif

    // ���picture����
    for (i = 0; i < p_len; i++) {
        picture[i] = 0x00;
    }

    // ��EEPROM��ȡ���ݵ�picture
#ifdef __AT24C512B__
    Int_EEPROM_AT24C512B_ReadBytes(0x0000, picture, p_len);
#else
    Int_EEPROM_ReadBytes(0x00, picture, p_len);
#endif
    // =================================================================

    while (1) {
        // ����ͼ�����飬��ÿ��ͼ����ʾ��LED������
        for (i = 0; i < p_len; i++) {
            // ����ǰͼ��������ʾ��LED������
            Int_LEDMatrix_Shift(picture[i]);
            // ��ʱ200���룬Ϊ�������˵����ۿ��������ؿ���ÿ��ͼ��
            Com_Delayms(200);
        }
    }
}