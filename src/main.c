#include "Int_LEDMatrix.h"
#include "Dri_Timer0.h"

/**
 * 主函数
 *
 * 本函数初始化了LED点阵和定时器，并在一个无限循环中显示一系列图案
 * 通过LED点阵显示的方式，利用定时器延时，实现图案的动态显示效果
 */
void main()
{
    // 定义一个用于循环计数的变量i
    u8 i;
    // 定义一个存储图案数据的数组picture，用于在LED点阵上显示图案
    u8 picture[] = {0x7E, 0x40, 0x40, 0x3C, 0x42, 0x42, 0x3C, 0x02, 0x7E, 0x60, 0x30, 0x1E, 0x00, 0x7E, 0x4A, 0x4A,
                    0x4A, 0x00};

    // 初始化定时器0，为后续的延时操作做准备
    Dri_Timer0_Init();
    // 初始化LED点阵，准备开始显示图案
    Int_LEDMatrix_Init();

    // 进入一个无限循环，用于不断滚动显示图案数组中的图案
    while (1) {
        // 遍历图案数组，将每个图案显示在LED点阵上
        for (i = 0; i < sizeof(picture) / sizeof(picture[0]); i++) {
            // 将当前图案数据显示到LED点阵上
            Int_LEDMatrix_Shift(picture[i]);
            // 延时200毫秒，为的是让人的肉眼可以清晰地看到每个图案
            Com_Delayms(200);
        }
    }
}