#include <STC89C5xRC.H>
#include <STRING.H>
#include "Dir_UART.h"
#include "Com_Util.h"
#include "Dri_Timer0.h"

void main()
{
    char str[16];
    Dri_Timer0_Init();
    Dir_UART_Init();
    while (1) {
        if (Dri_UART_ReceiveStr(str)) {
            if (strcmp(str, "on") == 0) {
                P2 = 0x00;
                Dir_UART_SendStr("OK: LED is NO");
            } else if (strcmp(str, "off") == 0) {
                P2 = 0xFF;
                Dir_UART_SendStr("OK: LED is OFF");
            } else {
                Dir_UART_SendStr("UNKNOW COMMAND!\n");
                Dir_UART_SendStr("your command is : ");
                Dir_UART_SendStr(str);
            }
        }
    }
}