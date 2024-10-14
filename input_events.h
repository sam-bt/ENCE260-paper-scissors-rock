/** @file   input_events.h
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Header file to define the functionality for the input_events.c file
*/

#ifndef INPUT_EVENTS_H
#define INPUT_EVENTS_H

#include <stdbool.h>

extern int letter;
extern int letter_sent;
extern int letter_recieved;
extern int num_rounds;

void check_letter_input(void);
bool check_rounds_input(void);
void check_button_pressed(void);

#endif 
