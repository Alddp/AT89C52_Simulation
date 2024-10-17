#if !defined(__INT_LEDMATRIX_H__)
#define __INT_LEDMATRIX_H__

#include "Com_Util.h"

/**
 * @brief ��ʼ��LED����
 *
 */
void Int_LEDMatrix_Init();

/**
 * @brief ����LED����ĵ���
 *
 * @param pic (P0�Ĵ���״̬)
 */
void Int_LEDMatrix_SetPic(u8 pic[]);

/**
 * @brief ˢ�µ���LED
 */
void Int_LEDMatrix_Refresh();

#endif // __INT_LEDMATRIX_H__
