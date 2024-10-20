#if !defined(__DRI_IIC_H__)
#define __DRI_IIC_H__

#include "Com_Util.h"

void Dri_IIC_Start();

void Dri_IIC_Stop();

void Dri_IIC_SendByte(u8 byte);

u8 Dri_IIC_ReceiveByte();

bit Dri_IIC_ReceiveAck();

void Dri_IIC_SendAck(bit ack);

#endif // __DRI_IIC_H__
