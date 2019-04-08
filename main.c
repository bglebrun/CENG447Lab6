#define F_CPU 16000000
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "bit_macros.h"

void Init()
{
    // Enable global interrupts
    sei();
}

int main()
{
    Init();
    while (1)
    {

    }
    return 1;
}
