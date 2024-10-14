/** @file   arithmetic.c
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Contains methods that perform arithmetic on variables
*/

#include "arithmetic.h"

// Function to increment the animation counter
void increment_animation_delay ()
{
    if (animation_delay_counter >= ANIMATION_RATE) {
        animation_index = (animation_index + 1) % NUM_FRAMES;  
        animation_delay_counter = 0;  
    } else {
        animation_delay_counter++;
    }
}

// Function to scroll upwards (wraps) through the letters
void increment_letter () 
{
    if (letter == 2) {
        letter = 0;
    } else {
        letter += 1;
    }
}

// Function to scroll downwards (wraps) through the letters
void decrement_letter () 
{
    if (letter == 0) {
        letter = 2;
    } else {
        letter -= 1;
    }
}

// Function to increase the number of rounds
void increment_rounds () 
{
    if (num_rounds == MAX_ROUNDS) {
        num_rounds = 1;
    } else {
        num_rounds += 1;
    }
}

// Function to increase the number of rounds
void decrement_rounds () 
{
    if (num_rounds == 1) {
        num_rounds = MAX_ROUNDS;
    } else {
        num_rounds -= 1;
    }
}
