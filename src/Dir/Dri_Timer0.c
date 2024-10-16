#include <STC89C5xRC.H>
#include "Dri_Timer0.h"
#include "Com_Util.h"
#include <STDIO.H>

#define MAX_CALLBACK_COUNT 4 // ����ָ�����鳤��
static Timer0_Callback s_callbacks[MAX_CALLBACK_COUNT];

void Dri_Timer0_Init()
{
    u8 i;
    // 1. �����ж�
    EA  = 1;
    ET0 = 1;

    // 2. ����ģʽ GATE:0(0��ʱ������,1�������); C/T:0; M1:0; M0:1
    TMOD &= 0xF0;
    TMOD |= 0x01;

    // 3. ���ó�ʼֵ (���Ϊ��8λ�͵�8λ)
    TL0 = 64614 & 0xFF;        // ��8λ
    TH0 = (64614 >> 8) & 0xFF; // ��8λ

    // 4. �����Ĵ���
    TR0 = 1;

    // 5. ��ʼ��ָ������
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        s_callbacks[i] = NULL;
    }
}

/**
 * @brief ע��ص�����
 *
 * @param callback ����ָ��
 * @return bit 1:�ɹ�; 0:ʧ��
 */
bit Dri_Timer0_RegisterCallback(Timer0_Callback callback)
{
    u8 i;
    // �����ظ�ע��
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callbacks[i] == callback) {
            return 1;
        }
    }

    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callbacks[i] == NULL) {
            s_callbacks[i] = callback;
            return 1; // ע��ɹ�������1
        }
    }

    // û�п�λ
    return 0;
}

/**
 * @brief ȡ��ע��ص�����
 *
 * @param callback Ҫɾ���ĺ���
 * @return bit 1:�ɹ�; 0:û���ҵ�Ҫɾ���ĺ���
 */
bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback)
{
    u8 i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callbacks[i] == callback) {
            s_callbacks[i] = NULL;
            return 1;
        }
    }
    return 0;
}

void Dir_Timer0_Handler() interrupt 1
{
    u8 i;
    // 1. ���ó�ʼֵ
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 2. ��������ָ������
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callbacks[i] != NULL) { // ����ָ����ʴ���
            s_callbacks[i]();
        }
    }
}
