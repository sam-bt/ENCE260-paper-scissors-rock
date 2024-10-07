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

#define PACER_RATE 500
#define MESSAGE_RATE 10

static int letter = 0;

static const char charmap[] =
{
    'P',
    'S',
    'R'
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

int main (void)
{
    system_init (); // extract into init function
    start_tinygl();
    navswitch_init();
    pacer_init (500);

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
           // SEND TO THE OPONENT
        }
        display_character(letter);

    }
}
