#if !defined(__INT_DIGITAL_H__)
#define __INT_DIGITAL_H__

#include <Com_Util.h>
#include <STC89C5xRC.H>

void Int_ShowSingleDigital(u8 position, unsigned short digital);
void Int_DigitalRefresh(u8 digitalsTubes[8]);

u8 *Int_GetDisplayMemery(u32 num);

#endif // __INT_DIGITAL_H__
