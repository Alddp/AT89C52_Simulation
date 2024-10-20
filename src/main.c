#include "Int_LEDMatrix.h"
#include "Dri_Timer0.h"
#include "Int_EEPROM.h"
#include "Com_Util.h"

// !!!
// #define __AT24C512B__ // 使用Proteus仿真时取消此行注释

void main()
{
    // 定义一个用于循环计数的变量i
    u8 i;
    // 定义一个存储图案数据的数组picture，用于在LED点阵上显示图案
    u8 picture[] = {0x7E, 0x40, 0x40, 0x3C, 0x42, 0x42, 0x3C, 0x02, 0x7E, 0x60, 0x30, 0x1E,
                    0x00, 0x7E, 0x4A, 0x4A, 0x42, 0x1C, 0x22, 0x42, 0x8C, 0x42, 0x22, 0x1C, 0x00};

    u8 p_len = sizeof(picture) / sizeof(picture[0]);

    // 初始化定时器0，为后续的延时操作做准备
    Dri_Timer0_Init();
    // 初始化LED点阵，准备开始显示图案
    Int_LEDMatrix_Init();
// 根据EEPROM型号选择调用不同的写入函数
// =================================================================
#ifdef __AT24C512B__
    Int_EEPROM_AT24C512B_WritePage(0x0000, picture, p_len);
#else
    Int_EEPROM_WriteBytes(0x00, picture, p_len);
#endif

    // 清空picture数组
    for (i = 0; i < p_len; i++) {
        picture[i] = 0x00;
    }

    // 从EEPROM读取数据到picture
#ifdef __AT24C512B__
    Int_EEPROM_AT24C512B_ReadBytes(0x0000, picture, p_len);
#else
    Int_EEPROM_ReadBytes(0x00, picture, p_len);
#endif
    // =================================================================

    while (1) {
        // 遍历图案数组，将每个图案显示在LED点阵上
        for (i = 0; i < p_len; i++) {
            // 将当前图案数据显示到LED点阵上
            Int_LEDMatrix_Shift(picture[i]);
            // 延时200毫秒，为的是让人的肉眼可以清晰地看到每个图案
            Com_Delayms(200);
        }
    }
}