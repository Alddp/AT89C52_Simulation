#include "Dri_Timer0.h"
#include "Int_LED.h"
#include "Com_Util.h"

void light()
{
    static u16 count = 0;
    count++;

    if (count >= 500) {
        D2    = ~D2;
        count = 0;
    }
}
void main()
{
    Dri_Timer0_Init();
    Dri_Timer0_RegisterCallback(light);
    while (1) {
    }
}
