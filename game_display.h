/** @file   game_display.h
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Header file that describes the functionality for the game_display.c file
*/

#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

#include "system.h"
#include "tinygl.h"

#define COLUMNS 5
#define ROWS 7

int get_bitmap_pixel(const int bitmap[3][7], int animation_index, int y, int x);
void tinygl_display_bitmap(const int bitmap[3][7]);
void display_character(const char* map, int char_index);

#endif
