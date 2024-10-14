#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "system.h"

void increment_animation_delay();
void increment_letter();
void decrement_letter();
void increment_rounds();
void decrement_rounds();

extern int animation_delay_counter;
extern int animation_index;
extern int letter;
extern int num_rounds;

#define ANIMATION_RATE 150
#define NUM_FRAMES 4

#endif
