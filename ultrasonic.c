#include "ultrasonic.h"

/*
 *
 * Ultrasonic sensor: A4 A5 (portc 4 5)
 * Servo Motor: 3 (portd 3)
 */ 

void
initUltrasonic() {
    // Trig on A5
    setBit(DDRC, US_TRIG);
    // Echo on A4
    clearBit(DDRC, US_RECV);
}

