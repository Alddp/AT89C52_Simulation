#include "Int_LEDMatrix.h"
#include "Dri_Timer0.h"
#include "Int_EEPROM.h"
#include "Com_Util.h"

void main()
{
    // 定义一个用于循环计数的变量i
    u8 i;
    u8 picture[] = {0x08, 0x1C, 0x2A, 0x08, 0x1C, 0x22, 0x42, 0x84, 0x4A, 0x2A, 0x1C, 0x08, 0x1C, 0x22, 0x42, 0x84,
                    0x4A, 0x2A, 0x1C, 0x08, 0x08, 0x1C, 0x1C, 0x36, 0x36, 0x22, 0x00};

    u8 p_len = sizeof(picture) / sizeof(picture[0]);

    // 初始化定时器0，为后续的延时操作做准备
    Dri_Timer0_Init();
    // 初始化LED点阵，准备开始显示图案
    Int_LEDMatrix_Init();

    Int_EEPROM_WriteBytes(0x00, picture, p_len);

    // 清空picture数组
    for (i = 0; i < p_len; i++) {
        picture[i] = 0x00;
    }

    Int_EEPROM_ReadBytes(0x00, picture, p_len);

    while (1) {
        // 遍历图案数组，将每个图案显示在LED点阵上
        for (i = 0; i < p_len; i++) {
            // 将当前图案数据显示到LED点阵上
            Int_LEDMatrix_Shift(picture[i]);
            Com_Delayms(200);
        }
    }
}