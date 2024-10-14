/** @file   input_events.c
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Contains the functionality that allows users to interact with the navswitch and button
*/

#include "input_events.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "arithmetic.h"
#include "winner.h"
#include "button.h"
#include "game.h"

// Function to check if there is an input on the navswitch and complete the corresponding letter function
void check_letter_input(void) {
    if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
        increment_letter();
    }	
    if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        decrement_letter();
    }
    if (navswitch_push_event_p(NAVSWITCH_EAST)) {
        decrement_letter();
    }	
    if (navswitch_push_event_p(NAVSWITCH_WEST)) {
        increment_letter();
    }
    if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
        ir_uart_putc(letter);
        letter_sent = letter;
        if (letter_recieved != DEFAULT_RECEIVE_SENT) {
            tinygl_clear();
            check_winner();
        }
    }
}

// Function to check if there is an input on the navswitch and complete the corresponding round function
bool check_rounds_input(void) {
    if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
        increment_rounds();
    }	
    if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        decrement_rounds();
    }
    if (navswitch_push_event_p(NAVSWITCH_EAST)) {
        decrement_rounds();
    }	
    if (navswitch_push_event_p(NAVSWITCH_WEST)) {
        increment_rounds();
    }
    if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
        ir_uart_putc(num_rounds);
        num_rounds = num_rounds;
        return true;
    }
    return false;
}

// Function to check if the button has been pressed, if so move to the next round
void check_button_pressed(void) 
{
    button_update ();
    if (button_push_event_p(0)) {
        letter = 0;
        letter_recieved = DEFAULT_RECEIVE_SENT;
        letter_sent = DEFAULT_RECEIVE_SENT;
        round_over = false;
    }
}