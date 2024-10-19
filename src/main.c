#include <STC89C5xRC.H>
#include "Dir_UART.h"
#include "Com_Util.h"

void main()
{
    char c;
    Dir_UART_Init();

    while (1) {
        if (Dir_UART_ReceiveChar(&c)) {

            switch (c) {
                case 'A':
                    P2 = 0x00;
                    Dir_UART_SendStr("OK: LED is ON");
                    break;
                case 'B':
                    P2 = 0xFF;
                    Dir_UART_SendStr("OK: LED is OFF");
                    break;
                default:
                    Dir_UART_SendStr("UNKNOW COMMAND!");
                    break;
            }
        }
    }
}