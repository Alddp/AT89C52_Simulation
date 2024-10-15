#include "Int_Buzzer.h"
#include <STC89C5xRC.H>
#include "Com_Util.h"

#define BUZZER P25

void Int_Buzzer_Buzz()
{
    u8 count = 100;
    while (count) {
        BUZZER = ~BUZZER;
        Com_Delayms(1);
        count--;
    }
}