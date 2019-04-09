#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_
#include <avr/io.h>
#include "bit_macros.h"
#include "pin_map.h"

volatile unsigned int Overflow = 0;

void initUltrasonic();
void triggerUltrasonic();

#endif