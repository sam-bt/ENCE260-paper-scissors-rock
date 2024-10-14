/** @file   game.c
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Contains the functionality to control the game flow
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "pio.h"
#include "navswitch.h"
#include "../fonts/font5x5_1.h"
#include "ir_uart.h"
#include "button.h"
#include "maps.h"
#include "arithmetic.h"
#include "game_display.h"
#include "winner.h"
#include "input_events.h"
#include "ir_events.h"

int letter = 0;
int animation_index = 0;
int animation_delay_counter = 0;
int letter_recieved = DEFAULT_RECEIVE_SENT;
int letter_sent = DEFAULT_RECEIVE_SENT;
bool round_over = false;
int num_rounds = DEFAULT_NUM_ROUNDS;
int curr_round = 0;
char stats[11];

// Function to initialise all the required modules for the game
void game_init() 
{
    system_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    button_init();
    navswitch_init();
    pacer_init (PACER_RATE);
    ir_uart_init();
}

// Main function to run the game
int main (void)
{
    game_init();

    while (1) {

        pacer_wait();
        tinygl_update();
        navswitch_update();

        bool round_selected = check_rounds_input();
        if (round_selected) {
            break;
        }

        int temp_num_rounds = check_ir_receive();
        if (temp_num_rounds != -1) {
            num_rounds = temp_num_rounds;
            break;
        }
        display_character(roundsmap, num_rounds-1);
    }

    while (curr_round < num_rounds) {
        pacer_wait();
        tinygl_update();
        navswitch_update();

        if (!round_over) {

            check_letter_input();

        int temp_char_received = check_ir_receive();

        if (temp_char_received != -1) {
            letter_recieved = temp_char_received;
            if (letter_sent != DEFAULT_RECEIVE_SENT) {
                tinygl_clear();
                check_winner();
            }
        }
        } else {
            check_button_pressed();
        }
        display_character(lettermap, letter);
    }

    stats[curr_round+1] = '\0'; //null terminate the stats string
    calculate_game();
}