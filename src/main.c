#include "Dir_UART.h"
#include "Com_Util.h"
void main()
{
    Dir_UART_Init();
    while (1) {
        Dir_UART_SendStr("hello\n");
        Com_Delay1s();
    }
}