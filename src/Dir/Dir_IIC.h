#if !defined(__DIR_IIC_H__)
#define __DIR_IIC_H__

#include "Com_Util.h"

void Dir_IIC_Start();

void Dir_ICC_Stop();

void Dir_IIC_SendByte(u8 byte);

u8 Dir_ICC_ReceiveByte();

bit Dir_ICC_ReceiveAck();

void Dir_ICC_SendAck(bit ack);

#endif // __DIR_IIC_H__
