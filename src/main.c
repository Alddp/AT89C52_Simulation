#include <STC89C5xRC.H>
#include "Int_LED.h"
#include "Com_Util.h"

// �жϷ������
void test() interrupt 0
{
    D1 = ~D1; // �л� LED ״̬
}
void main()
{
    EA  = 1; // ����ȫ���ж�
    EX0 = 1; // ʹ���ⲿ�ж�0
    IT0 = 1; // ����Ϊ��ƽ����ģʽ��IT0 = 0��

    while (1) {
        IE0 = 1;
        D2  = ~D2;
        Com_Delay1s();
        // Com_Delayms(200);
    }
}
