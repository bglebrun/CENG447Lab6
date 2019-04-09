#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_
#include "bit_macros.h"
#include "pin_map.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

/*
 * Flag for overflow
 * false = no overflow
 * true = overflow happened in test
 */
volatile bool Overflow = false;

unsigned int getOverflowStatus();
void initUltrasonic();
void triggerUltrasonic();
void turnoffTimer1();
void turnonTimer1();
unsigned int TIM16_ReadTCNT1();
void TIM16_WriteTCNT1(unsigned int i);
unsigned int receiveUltrasonic();

#endif
