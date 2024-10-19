#if !defined(__DIR_UART_H__)
#define __DIR_UART_H__

/**
 * @brief ��ʼ����������
 *
 * �ú��������˴��ڵĹ���ģʽ�������ʡ��������ݺ��ж��������
 */
void Dir_UART_Init();

/**
 * @brief ����һ���ַ�
 *
 * @param c Ҫ���͵��ַ�
 *
 * �˺����ȴ�ֱ����һ���ַ�������ϣ�Ȼ�����µ��ַ�
 */
void Dir_UART_SendChar(char c);

/**
 * @brief ����һ���ַ���
 *
 * @param str Ҫ���͵��ַ���
 *
 * �˺���ʹ��Dir_UART_SendChar��������ַ��ط����ַ���
 */
void Dir_UART_SendStr(char *str);

/**
 * @brief ����һ���ַ���
 *
 * @param str Ҫ���յ��ַ���
 * @return bit 0: ����ʧ�ܣ�1: ���ճɹ�
 */
bit Dri_UART_ReceiveStr(char *str);

#endif // __DIR_UART_H__
