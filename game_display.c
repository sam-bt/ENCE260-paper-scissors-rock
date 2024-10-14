/** @file   game_display.c
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Contains functions that put information on the display
*/

#include "game_display.h"
#include "arithmetic.h" 
#include "tinygl.h"
#include "maps.h"

// Function return the bitwise operation for getting the pixel of an animation
int get_bitmap_pixel(const int bitmap[3][7], int animation_index, int y, int x) 
{
    return bitmap[animation_index][y] & (1 << (4 - x));
}

// Function to display the provided bitmap on the display
void tinygl_display_bitmap(const int bitmap[3][7]) {
    tinygl_clear();
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLUMNS; x++) {
            if (get_bitmap_pixel(bitmap, animation_index, y, x)) {
                tinygl_draw_point(tinygl_point(x, y), 1);
            }
        }
    }
    tinygl_update();
}

// Function to display a specific character on the screen
void display_character (const char* map, int char_index)
{
    increment_animation_delay();

    if (map[char_index] == 'R') {
        tinygl_display_bitmap(rock_bitmap);
    } else if (map[char_index] == 'P') {
        tinygl_display_bitmap(paper_bitmap);
    } else if (map[char_index] == 'S') {
        tinygl_display_bitmap(scissors_bitmap);
    } else {

    char character = map[char_index];

    char buffer[2];

    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
    }
}