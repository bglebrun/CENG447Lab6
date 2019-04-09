#include "ultrasonic.h"

/*
 *
 * Ultrasonic sensor: A4 A5 (portc 4 5)
 * Servo Motor: 3 (portd 3)
 */

void initUltrasonic()
{
    // Trig on A5
    setBit(DDRC, US_TRIG);
    // Echo on A4
    clearBit(DDRC, US_RECV);

    PORTC = 0x00;

    /*
     * Timer 1
     * Pins 7:4 zeroes
     * tccr1a high byte zeroes
     * 16 us
     */
    OCR1A = 0;
    OCR1B = 0;
    // Start tcount at 1
    TCNT1 = 0x00;
    // Normal mode
    TCCR1A = 0x00;
    /*
     * Prescaler value goes here
     * 1 - no prescaling
     * 2 - clock /8
     * 3 - clock /64
     * 4 - clock /256 - 16us
     * 5 - clock /1024 - 64us
     * source -
     * https://sites.google.com/site/qeewiki/books/avr-guide/timers-on-the-atmega328
     */
    TCCR1B |= 0x05;
}

void triggerUltrasonic() {
    Overflow = 0;
    setBit(PORTC, US_TRIG);
    _delay_ms(10);
    clearBit(PORTC, US_TRIG);
    // reset counter 1
    TIM16_WriteTCNT1(0);
    // Delay while pulse is sent
    _delay_ms(60);
}

ISR(TIMER1_OVF_vect)
{
    // Timer 1 overflow
    Overflow = 1;
}

unsigned int recieveUltrasonic() {
    unsigned int i = TCNT1;
    // 64 us per count in i
    return ((58*64)/i);
}

unsigned int TIM16_ReadTCNT1()
{
    unsigned char sreg;
    unsigned int i;
    // Save global interrupt flag
    sreg = SREG;
    // Disable interrupts
    _CLI();
    // Read TCNT1 into i
    i = TCNT1;
    // Restore global interrupt flag
    SREG = sreg;
    return i;
}

void TIM16_WriteTCNT1(unsigned int i)
{
    unsigned char sreg;
    unsigned int i;
    // Save global interrupt flag
    sreg = SREG;
    // Disable interrupts
    __disable_interrupt();
    // Set TCNT1  to i
    TCNT1 = i;
    // Restore global interrupt flag
    SREG = sreg;
}
