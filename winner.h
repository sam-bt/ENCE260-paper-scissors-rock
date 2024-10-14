/** @file   winner.h
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Header file to define the functionality for the winner.c file
*/

#ifndef WINNER_H
#define WINNER_H

#include "system.h"
#include "tinygl.h"

#define PAPER 0
#define SCISSORS 1
#define ROCK 2
#define TIE 3
#define WIN 4
#define LOSE 5

extern int letter_sent;
extern int letter_recieved;
extern bool round_over;
extern int curr_round;
extern char stats[11];

void check_winner(void);
char* build_result_string(int rounds_won, int rounds_lost);
void calculate_game(void);

#endif
