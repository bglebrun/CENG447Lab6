#define F_CPU 16000000
#include "robotIo.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

/* stdout stream */
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

void Init()
{
    initUART();

    // Enable global interrupts
    sei();
}

int main()
{
    Init();
    int i = 0;
    while (1)
    {
        fprintf(&mystdout, "test: %d\n", i);
        i++;
    }
    return 1;
}
