#include <STC89C5xRC.H>
#include "Int_Key.h"
#include "Int_LED.h"

void main()
{
    while (1) {
        if (K1 == 0) {
            Com_Delayms(10);
            if (K1 == 0) {
                while (K1 == 0);
                D1 = ~D1;
            }
        }
        if (K2 == 0) {
            Com_Delayms(10);
            if (K2 == 0) {
                while (K2 == 0);
                D2 = ~D2;
            }
        }
        if (K3 == 0) {
            Com_Delayms(10);
            if (K3 == 0) {
                while (K3 == 0);
                D3 = ~D3;
            }
        }
        if (K4 == 0) {
            Com_Delayms(10);
            if (K4 == 0) {
                while (K4 == 0);
                D4 = ~D4;
            }
        }
    }
}
