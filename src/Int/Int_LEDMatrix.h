#if !defined(__INT_LEDMATRIX_H__)
#define __INT_LEDMATRIX_H__

#include "Com_Util.h"

/**
 * @brief ��ʼ��LED����ģ��
 */
void Int_LEDMatrix_Init();

/**
 * @brief ����Ҫ��ʾ��ͼƬ
 *
 * @param pic ͼƬ��������(P0�Ĵ���״̬)
 */
void Int_LEDMatrix_SetPic(u8 pic[]);

/**
 * @brief ������ʾͼƬ: ��pic����s_buffer[0]
 * @param pic ������ͼƬ����
 */
void Int_LEDMatrix_Shift(u8 pic);

#endif // __INT_LEDMATRIX_H__
