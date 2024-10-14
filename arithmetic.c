#include "arithmetic.h"

void increment_animation_delay ()
{
    if (animation_delay_counter >= ANIMATION_RATE) {
        animation_index = (animation_index + 1) % NUM_FRAMES;  
        animation_delay_counter = 0;  
    } else {
        animation_delay_counter++;
    }
}

void increment_letter () 
{
    if (letter == 2) {
        letter = 0;
    } else {
        letter += 1;
    }
}

void decrement_letter () 
{
    if (letter == 0) {
        letter = 2;
    } else {
        letter -= 1;
    }
}

void increment_rounds () 
{
    if (num_rounds == 9) {
        num_rounds = 1;
    } else {
        num_rounds += 1;
    }
}

void decrement_rounds () 
{
    if (num_rounds == 1) {
        num_rounds = 9;
    } else {
        num_rounds -= 1;
    }
}
