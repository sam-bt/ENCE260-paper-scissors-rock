/** @file   game.c
    @author Samuel Beattie, Lachlan McLean
    @date   8 Oct 2024
    @brief  Rock paper scissors game
    
    @defgroup game Game application
*/
#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "pio.h"
#include "navswitch.h"
#include "../fonts/font5x5_1.h"
#include "ir_uart.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10

static int letter = 0;
static int letter_recieved = 10;
static int letter_sent = 10;

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

// void display_waiting() {
//     tinygl_clear();
//     tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
//     tinygl_text("Waiting...");
//     while (1) {
//         tinygl_update();
//         if (ir_uart_read_ready_p()) {
//             int temp_character = ir_uart_getc();
//             if (0 <= temp_character && temp_character <= 255) {
//                 letter_recieved = temp_character;
//                 check_winner();
//             }
//         }
//     }

// }


void check_winner() {
    while (1) {

    if (letter_sent == letter_recieved) {
        letter = 3;
    }

    if (letter_sent == 0 && letter_recieved == 1) {
            letter = 4;
    } else if (letter_sent == 1 && letter_recieved == 2) {
            letter = 4;
    } else if (letter_sent == 2 && letter_recieved == 0) {
            letter = 4;
    } else {
            letter = 5;
    }
    letter_recieved = 10;
    letter_sent = 10;
    display_character(letter);

    }


}

int main (void)
{
    system_init (); // extract into init function
    start_tinygl();
    navswitch_init();
    pacer_init (500);
    ir_uart_init();

    while (1)
    {
        pacer_wait();
        tinygl_update();
        navswitch_update();

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
                break;
           }

        }
        if (ir_uart_read_ready_p()) {
            int temp_character = ir_uart_getc();
            if (0 <= temp_character && temp_character <= 255) {
                letter_recieved = temp_character;
                if (letter_sent != 10) {
                    check_winner();
                    break;
                }
            }
        }
        display_character(letter);

    }
}
