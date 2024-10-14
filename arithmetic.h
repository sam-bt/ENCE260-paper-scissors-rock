/** @file   arithmetic.h
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Header file to define functionality for the arithmetic.c file
*/

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "system.h"

#define ANIMATION_RATE 150
#define NUM_FRAMES 4
#define MAX_ROUNDS 9

extern int animation_delay_counter;
extern int animation_index;
extern int letter;
extern int num_rounds;

void increment_animation_delay(void);
void increment_letter(void);
void decrement_letter(void);
void increment_rounds(void);
void decrement_rounds(void);

#endif
