#include "game_display.h"
#include "arithmetic.h" 
#include "tinygl.h"
#include "maps.h"

void tinygl_display_bitmap(const int bitmap[3][7]) {
    tinygl_clear();
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 5; x++) {
            if (bitmap[animation_index][y] & (1 << (4 - x))) {
                tinygl_draw_point(tinygl_point(x, y), 1);
            }
        }
    }
    tinygl_update();
}

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