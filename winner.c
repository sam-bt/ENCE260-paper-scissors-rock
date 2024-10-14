/** @file   winner.c
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Contains functionality to calculate and express the winner of the game or of a round
*/

#include "winner.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arithmetic.h" 
#include "tinygl.h"
#include "pacer.h"
#include "maps.h"    
#include "game.h"

// Function to check the winner of each round
void check_winner() 
{
if (letter_sent == letter_recieved) { // same so tie
    letter = TIE;
} else if (letter_sent == PAPER && letter_recieved == SCISSORS) { // paper < scissors L
    letter = LOSE;
} else if (letter_sent == SCISSORS && letter_recieved == ROCK) { // scissors < rock L
    letter = LOSE;
} else if (letter_sent == ROCK && letter_recieved == PAPER) { // rock < paper L
    letter = LOSE;
} else if (letter_sent == ROCK && letter_recieved == SCISSORS) { // rock > scissors W
    letter = WIN;
} else if (letter_sent == PAPER && letter_recieved == ROCK) { // paper > rock W
    letter = WIN;
} else if (letter_sent == SCISSORS && letter_recieved == PAPER) { // scissors > paper W
    letter = WIN;
}
    stats[curr_round] = lettermap[letter];
    curr_round += 1;
    letter_recieved = DEFAULT_RECEIVE_SENT;
    letter_sent = DEFAULT_RECEIVE_SENT;
    round_over = true;
}

// Function to built the string to display whether the player won, lost or drew overall
char* build_result_string(int rounds_won, int rounds_lost) 
{
    char* result_string = malloc(80 * sizeof(char));

    if (result_string == NULL) {
        return NULL;
    }

    if (rounds_won > rounds_lost) {
        snprintf(result_string, 80, "You Win! Won %d/%d ", rounds_won, num_rounds);
    } else if (rounds_lost > rounds_won) {
        snprintf(result_string, 80, "You Lose! Won %d/%d ", rounds_won, num_rounds);
    } else {
        snprintf(result_string, 80, "You Drew! Won %d/%d Lost %d/%d ", rounds_won, num_rounds, rounds_lost, num_rounds);
    }
    return result_string;
}

// Function to extract the number of wins, losses and ties from the stats string
void calculate_game() 
{
    int wins = 0, losses = 0, ties = 0;

    for (int i = 0; i <= MAX_ROUNDS && stats[i] != '\0'; i++) {
        if (stats[i] == 'W') {
            wins++;
        } else if (stats[i] == 'L') {
            losses++;
        } else if (stats[i] == 'T') {
            ties++;
        }
    }

    char* result_string = build_result_string(wins, losses);
    tinygl_clear();
    tinygl_text(result_string);

    while (1) {
        pacer_wait();
        tinygl_update();

    }
}