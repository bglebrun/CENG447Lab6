#define F_CPU 16000000
#include "bit_macros.h"
#include "motor_driver.h"
#include "pcint.h"
#include "robotIo.h"
#include "ultrasonic.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

/* stdout stream */
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

void Init()
{
    // configure UART and I/O
    initUART();

    // configure pin change interrupts
    initPCINT();

    // configure ultrasonic range sensor
    initUltrasonic();

    // configure motors
    initMotor();

    // Enable global interrupts
    sei();
}

int main()
{
    fprintf(&mystdout, "initializing\n");
    Init();
    fprintf(&mystdout, "done initializing\n");
    while (1)
    {
        fprintf(&mystdout, "triggering ultrasonic\n");
        triggerUltrasonic();
        while (!responseAvailable)
        {
        }
        fprintf(&mystdout, "distance: %d cm\n", receiveUltrasonic());
        fprintf(&mystdout, "overflow: %s\n",
                getOverflowStatus() ? "YES" : "NO");
        responseAvailable = false;
        _delay_ms(500);
    }
    return 1;
}
