#if !defined(__INT_EEPROM_H__)
#define __INT_EEPROM_H__

#include "Com_Util.h"

/**
 * @brief 发送多个字节
 *
 * @param addr 16字节地址
 * @param bytes 待发送的数据
 * @param len 数组长度
 */
void Int_EEPROM_WriteBytes(u8 addr, u8 bytes[], u8 len);

/**
 * @brief 发送多个字节
 *
 * @param addr 16字节地址
 * @param bytes 待发送的数据
 * @param len 数组长度
 *
 * AT24C512B型号
 */
void Int_EEPROM_AT24C512B_WritePage(u16 addr, u8 bytes[], u8 len);

/**
 * @brief 接收多个字节
 *
 * @param addr 8字节地址
 * @param bytes 要读取的数据
 * @param len 要读取的长度
 */
void Int_EEPROM_ReadBytes(u8 addr, u8 bytes[], u8 len);

/**
 * @brief 接收多个字节
 *
 * @param addr 16字节地址
 * @param bytes 要读取的数据
 * @param len 要读取的长度
 *
 * AT24C512B型号
 */
void Int_EEPROM_AT24C512B_ReadBytes(u16 addr, u8 bytes[], u8 len);

#endif // __INT_EEPROM_H__
