#if !defined(__INT_LEDMATRIX_H__)
#define __INT_LEDMATRIX_H__

#include "Com_Util.h"

/**
 * @brief 初始化LED矩阵
 *
 */
void Int_LEDMatrix_Init();

/**
 * @brief 设置LED矩阵的点阵
 *
 * @param pic (P0寄存器状态)
 */
void Int_LEDMatrix_SetPic(u8 pic[]);

/**
 * @brief 刷新点阵LED
 */
void Int_LEDMatrix_Refresh();

#endif // __INT_LEDMATRIX_H__
