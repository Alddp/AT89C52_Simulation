#include <STC89C5xRC.H>
#include "Int_DigitalTube.h"
#include "Int_Key_Matrix.h"

void main()
{
    u8 result;
    u8 *nums = 0;
    while (1) {

        result = Int_Key_Matrix_CheckS(); // 返回按下的按钮的编号

        if (result) {
            nums = Int_GetDisplayMemery(result); // 传入编号让数码管显示
        }

        Int_DigitalRefresh(nums); // 一直刷新数码管
    }
}
