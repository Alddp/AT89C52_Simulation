#if !defined(__DRI_TIMER0_H__)
#define __DRI_TIMER0_H__

typedef void (*Timer0_Callback)(void);

/**
 * @brief ��ʼ����ʱ��0
 *
 */
void Dri_Timer0_Init();

/**
 * @brief ע��ص�����
 *
 * @param callback ����ָ��
 * @return bit 1:�ɹ�; 0:ʧ��
 */
bit Dri_Timer0_RegisterCallback(Timer0_Callback callback);
/**
 * @brief ȡ��ע��ص�����
 *
 * @param callback Ҫɾ���ĺ���
 * @return bit 1:�ɹ�; 0:û���ҵ�Ҫɾ���ĺ���
 */
bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback);

#endif // __DRI_TIMER0_H__
