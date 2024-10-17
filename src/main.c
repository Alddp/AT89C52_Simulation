#include "Int_LEDMatrix.h"
#include <STC89C5xRC.H>

void main()
{
    u8 pic[8] = {0x1,
                 0x2,
                 0x4,
                 0x8,
                 0x10,
                 0x20,
                 0x40,
                 0x80};

    Int_LEDMatrix_SetPic(pic);
    while (1) {
        Int_LEDMatrix_Refresh();
    }
}
