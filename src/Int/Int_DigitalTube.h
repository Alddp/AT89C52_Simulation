#if !defined(__INT_DIGITAL_H__)
#define __INT_DIGITAL_H__

#include <Com_Util.h>
#include <STC89C5xRC.H>

/**
 * @param position 要显示的位置
 * @param digital 要显示的单个数字
 */
void Int_ShowSingleDigital(u8 position, unsigned short digital);

/**
 * @brief 刷新数码管显示
 *
 * @param digitalsTubes 数字数组
 */
void Int_DigitalRefresh(u8 digitalsTubes[8]);

/**
 * @param num 要显示的多个数字, 最大8位
 * @return 返回包含要显示的数字的数组, 索引是要显示的位置
 */
u8 *Int_GetDisplayMemery(u32 num);

#endif // __INT_DIGITAL_H__
