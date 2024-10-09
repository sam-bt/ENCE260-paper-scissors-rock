/** @file   game.c
    @author Samuel Beattie, Lachlan McLean
    @date   8 Oct 2024
    @brief  Rock paper scissors game
    
    @defgroup game Game application
*/
#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "pio.h"
#include "navswitch.h"
#include "../fonts/font5x5_1.h"
#include "ir_uart.h"
#include "button.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10

static int letter = 0;
static int letter_recieved = 10;
static int letter_sent = 10;
static int round_over = 0;
static int num_rounds = 3;
static int round = 0;

static char stats[11];

static const char charmap[] =
{
    'P',
    'S',
    'R',
    'T',
    'W',
    'L'
};

void start_tinygl(void) {

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    button_init();

}

void display_character (int char_index)
{
    char character = charmap[char_index];

    char buffer[2];

    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

void increment () 
{
    if (letter == 2) {
        letter = 0;
    } else {
        letter += 1;
    }
}

void decrement () 
{
    if (letter == 0) {
        letter = 2;
    } else {
        letter -= 1;
    }
}


void check_winner() {

        if (letter_sent == letter_recieved) { // same so tie
            letter = 3;
        } else if (letter_sent == 0 && letter_recieved == 1) { // paper < scissors L
                letter = 5;
        } else if (letter_sent == 1 && letter_recieved == 2) { // scissors < rock L
                letter = 5;
        } else if (letter_sent == 2 && letter_recieved == 0) { // rock < paper L
                letter = 5;
        } else if (letter_sent == 2 && letter_recieved == 1) { // rock > scissors W
            letter = 4;
        } else if (letter_sent == 0 && letter_recieved == 2) { // paper > rock W
            letter = 4;
        } else if (letter_sent == 1 && letter_recieved == 0) { // scissors > paper W
            letter = 4;
        }

        stats[round] = charmap[letter];
        round += 1;
        letter_recieved = 10;
        letter_sent = 10;
        round_over = 1;
}

char* build_result_string(int won) {

    char* result_string = malloc(80 * sizeof(char));

    if (result_string == NULL) {
        return NULL;
    }

    int rounds_lost = num_rounds - won;

    if (won > num_rounds / 2) {
        snprintf(result_string, 80, "You Win! Won %d/%d rounds", won, num_rounds);
    } else if (won < num_rounds / 2) {
        snprintf(result_string, 80, "You Lose! Won %d/%d rounds", won, num_rounds);
    } else {
        snprintf(result_string, 80, "You drew! Won %d/%d rounds, Lost %d/%d rounds", won, num_rounds, rounds_lost, num_rounds);
    }
    return result_string;
}

void calculate_game() {

    int wins = 0, losses = 0, ties = 0;

    for (int i = 0; i < 10 && stats[i] != '\0'; i++) {
        if (stats[i] == 'W') {
            wins++;
        } else if (stats[i] == 'L') {
            losses++;
        } else if (stats[i] == 'T') {
            ties++;
        }
    }

    if (wins > losses && wins > ties) {
        letter = 4;
    } else if (losses > wins && losses > ties) {
        letter = 5;
    } else {
        letter = 3;
    }

    char* result_string = build_result_string(wins);
    tinygl_clear();
    tinygl_text(result_string);

    while (1) {
        pacer_wait();
        tinygl_update();

    }
}


int main (void)
{
    system_init (); // extract into init function
    start_tinygl();
    navswitch_init();
    pacer_init (500);
    ir_uart_init();

    while (round < num_rounds) {
        pacer_wait();
        tinygl_update();
        navswitch_update();

        if (!round_over) {

            if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
                increment();
            }	
            if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            decrement();
            }
            if (navswitch_push_event_p (NAVSWITCH_EAST)) {
                decrement();
            }	
            if (navswitch_push_event_p (NAVSWITCH_WEST)) {
            increment();
            }
            if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            ir_uart_putc(letter);
            letter_sent = letter;
            if (letter_recieved != 10) {
                    check_winner();
                }
            }
            if (ir_uart_read_ready_p()) {
                int temp_character = ir_uart_getc();
                if (0 <= temp_character && temp_character <= 255) {
                    letter_recieved = temp_character;
                    if (letter_sent != 10) {
                        check_winner();
                    }
                }
            }
        }

        button_update ();
        if (button_push_event_p(0)) {
            letter = 0;
            letter_recieved = 10;
            letter_sent = 10;
            round_over = 0;
            }

        display_character(letter);

    }

    stats[round+1] = '\0';
    calculate_game();

}
