#if !defined(__DIR_UART_H__)
#define __DIR_UART_H__

/**
 * @brief 初始化串口设置
 *
 * 该函数配置了串口的工作模式、波特率、接收数据和中断相关设置
 */
void Dir_UART_Init();

/**
 * @brief 发送一个字符
 *
 * @param c 要发送的字符
 *
 * 此函数等待直到上一个字符发送完毕，然后发送新的字符
 */
void Dir_UART_SendChar(char c);

/**
 * @brief 发送一个字符串
 *
 * @param str 要发送的字符串
 *
 * 此函数使用Dir_UART_SendChar函数逐个字符地发送字符串
 */
void Dir_UART_SendStr(char *str);

#endif // __DIR_UART_H__
