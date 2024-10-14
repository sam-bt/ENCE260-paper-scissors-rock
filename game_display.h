#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

#include "system.h"
#include "tinygl.h"

void tinygl_display_bitmap(const int bitmap[3][7]);
void display_character(const char* map, int char_index);

#endif
