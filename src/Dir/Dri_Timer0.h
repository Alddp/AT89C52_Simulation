#if !defined(__DIR_TIMER0_H__)
#define __DIR_TIMER0_H__

typedef void (*Timer0_Callback)(void);

/**
 * @brief 初始化定时器0
 *
 */
void Dri_Timer0_Init();

/**
 * @brief 注册回调函数
 *
 * @param callback 函数指针
 * @return bit 1:成功; 0:失败
 */
bit Dri_Timer0_RegisterCallback(Timer0_Callback callback);
/**
 * @brief 取消注册回调函数
 *
 * @param callback 要删除的函数
 * @return bit 1:成功; 0:没有找到要删除的函数
 */
bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback);

#endif // __DIR_TIMER0_H__
