#ifndef _PCINT_H_
#define _PCINT_H_
#include "avr/io.h"

#define PCMSK1_CONFIG                                                          \
    (0 << PCINT14) | (1 << PCINT13) | (0 << PCINT12) | (0 << PCINT11) |        \
        (0 << PCINT10) | (0 << PCINT9) | (0 << PCINT8)

#define PCICR_CONFIG (0 << PCIE2) | (1 << PCIE1) | (0 << PCIE0)

volatile unsigned int timeResponse;

void initPCINT();

#endif
