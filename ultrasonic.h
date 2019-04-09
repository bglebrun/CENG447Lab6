#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_
#include <avr/io.h>
#include "bit_macros.h"
#include "pin_map.h"

/*
 * Flag for overflow
 * 0 = no overflow
 * 1 = overflow happened in test
 */ 
volatile unsigned int Overflow = 0;

unsigned int getOverflowStatus();
void initUltrasonic();
void triggerUltrasonic();
unsigned int recieveUltrasonic();

#endif