#if !defined(__INT_LEDMATRIX_H__)
#define __INT_LEDMATRIX_H__

#include "Com_Util.h"

/**
 * @brief 初始化LED点阵模块
 */
void Int_LEDMatrix_Init();

/**
 * @brief 设置要显示的图片
 *
 * @param pic 图片数据数组(P0寄存器状态)
 */
void Int_LEDMatrix_SetPic(u8 pic[]);

/**
 * @brief 滚动显示图片: 将pic放入s_buffer[0]
 * @param pic 新增的图片数据
 */
void Int_LEDMatrix_Shift(u8 pic);

#endif // __INT_LEDMATRIX_H__
