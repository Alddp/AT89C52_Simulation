#include <STC89C5xRC.H>
#include "Int_DigitalTube.h"
#include "Int_Key_Matrix.h"

void main()
{
    u8 result;
    u8 *nums = 0;
    while (1) {

        result = Int_Key_Matrix_CheckS(); // ���ذ��µİ�ť�ı��

        if (result) {
            nums = Int_GetDisplayMemery(result); // ���������������ʾ
        }

        Int_DigitalRefresh(nums); // һֱˢ�������
    }
}
