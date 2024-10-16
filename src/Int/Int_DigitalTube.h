#if !defined(__INT_DIGITAL_H__)
#define __INT_DIGITAL_H__

#include <Com_Util.h>
#include <STC89C5xRC.H>

/**
 * @param position Ҫ��ʾ��λ��
 * @param digital Ҫ��ʾ�ĵ�������
 */
void Int_ShowSingleDigital(u8 position, unsigned short digital);

/**
 * @brief ˢ���������ʾ
 *
 * @param digitalsTubes ��������
 */
void Int_DigitalRefresh(u8 digitalsTubes[8]);

/**
 * @param num Ҫ��ʾ�Ķ������, ���8λ
 * @return ���ذ���Ҫ��ʾ�����ֵ�����, ������Ҫ��ʾ��λ��
 */
u8 *Int_GetDisplayMemery(u32 num);

#endif // __INT_DIGITAL_H__
