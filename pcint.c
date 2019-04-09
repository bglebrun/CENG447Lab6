#include "pcint.h"

void initPCINT()
{
    PCMSK1 |= PCMSK1_CONFIG;
    PCICR |= PCICR_CONFIG;
}

// Pin change interrupt handler for pins 14-8
// written with a general switch design to
// handle cases where we are listening to more
// than one pin
ISR(PCINT1_vect)
{
    // last state the pins were in
    static unsigned char lastState = 0x00;
    // used to detect whether pcint is going high->low or low->high
    // a value of 0 indicates we are low->high, a value of 1 indicates high->low
    static bool highEdge13 = false;
    // pull current state of PORTC
    unsigned char currState = PINC & 0xFF;
    // changed pins
    unsigned char pcflags = currState ^ lastState;
    lastState = currState;

    // to add handling for a specific set of pin changes, add a case
    // to the switch statement with the bits corresponding to a pin combination
    // set. Note that the specific combination must be available as a case.
    switch (pcflags)
    {
    case 0x00:
        // nothing happened, do nothing
        break;

    case 0x05: // PORTC5 (PCINT13) changed
        if (highEdge13)
        {
            turnoffTimer1();
            timeResponse = receiveUltrasonic();
            responseAvailable = true;
        }
        else
        {
            TIM16_WriteTCNT1(0);
            turnonTimer1();
            responseAvailable = false;
        }

        highEdge13 = !highEdge13;
        break;
    default:
        // a case we weren't expecting occurred, do nothing
        break;
    }
}
