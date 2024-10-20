#if !defined(__INT_EEPROM_H__)
#define __INT_EEPROM_H__

#include "Com_Util.h"

/**
 * @brief ���Ͷ���ֽ�
 *
 * @param addr 16�ֽڵ�ַ
 * @param bytes �����͵�����
 * @param len ���鳤��
 */
void Int_EEPROM_WriteBytes(u8 addr, u8 bytes[], u8 len);

/**
 * @brief ���Ͷ���ֽ�
 *
 * @param addr 16�ֽڵ�ַ
 * @param bytes �����͵�����
 * @param len ���鳤��
 *
 * AT24C512B�ͺ�
 */
void Int_EEPROM_AT24C512B_WritePage(u16 addr, u8 bytes[], u8 len);

/**
 * @brief ���ն���ֽ�
 *
 * @param addr 8�ֽڵ�ַ
 * @param bytes Ҫ��ȡ������
 * @param len Ҫ��ȡ�ĳ���
 */
void Int_EEPROM_ReadBytes(u8 addr, u8 bytes[], u8 len);

/**
 * @brief ���ն���ֽ�
 *
 * @param addr 16�ֽڵ�ַ
 * @param bytes Ҫ��ȡ������
 * @param len Ҫ��ȡ�ĳ���
 *
 * AT24C512B�ͺ�
 */
void Int_EEPROM_AT24C512B_ReadBytes(u16 addr, u8 bytes[], u8 len);

#endif // __INT_EEPROM_H__
