#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_
#include "bit_macros.h"
#include "pin_map.h"
#include <avr/io.h>

/*
 * Flag for overflow
 * 0 = no overflow
 * 1 = overflow happened in test
 */
volatile unsigned int Overflow = 0;

unsigned int getOverflowStatus();
void initUltrasonic();
void triggerUltrasonic();
void turnoffTimer1();
void turnonTimer1();
unsigned int TIM16_ReadTCNT1();
void TIM16_WriteTCNT1(unsigned int i);
unsigned int receiveUltrasonic();

#endif
