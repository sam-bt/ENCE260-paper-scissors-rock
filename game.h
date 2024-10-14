/** @file   game.h
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Header file to define the functionality for the game.c file
*/

#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#define PACER_RATE 500
#define MESSAGE_RATE 18
#define DEFAULT_NUM_ROUNDS 5
#define DEFAULT_RECEIVE_SENT -1

extern int letter;
extern int animation_index;
extern int animation_delay_counter;
extern int letter_recieved;
extern int letter_sent;
extern bool round_over;
extern int num_rounds;
extern int curr_round;
extern char stats[11];

void game_init(void);
int main(void);

#endif 
