/** @file   maps.c
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Contains the char and bitmaps for the game
*/

#include "maps.h"

const char lettermap[] =
{
    'P',
    'S',
    'R',
    'T',
    'W',
    'L'
};

const char roundsmap[] =
{
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9'
};

// Bitmap for the rocks animation
const int rock_bitmap[4][7] = {
    {    
        0b11100,
        0b11110,
        0b11100,
        0b11000,
        0b00000,
        0b00000,
        0b00000

    },
    {    
        0b00000,
        0b01110,
        0b11111,
        0b11110,
        0b01100,
        0b00000,
        0b00000
    },
    {    
        0b00000,
        0b00000,
        0b00000,
        0b11100,
        0b11110,
        0b11100,
        0b11000,
    },
    {    
        0b00000,
        0b00000,
        0b01110,
        0b11111,
        0b11110,
        0b01100,
        0b00000,
    }
};

// Bitmap for the paper animation
const int paper_bitmap[4][7] = {
    {
        0b11111,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b11111
    },
    {
        0b00000,
        0b01110,
        0b01010,
        0b01010,
        0b01010,
        0b01110,
        0b00000
    },
    {
        0b0000,
        0b00000,
        0b00100,
        0b00100,
        0b00100,
        0b00000,
        0b00000
    },
    {
        0b00000,
        0b01110,
        0b01010,
        0b01010,
        0b01010,
        0b01110,
        0b00000
    },
};

// Bitmap for the scissors animation
const int scissors_bitmap[4][7] = {

    {
        0b00100,
        0b01110,
        0b11111,
        0b00100,
        0b01110,
        0b10001,
        0b01110

    },
    {
        0b01010,
        0b01010,
        0b10001,
        0b00100,
        0b01010,
        0b10101,
        0b01010

    },
    {
        0b10001,
        0b01010,
        0b00100,
        0b00100,
        0b01010,
        0b10001,
        0b01110

    },
    {
        0b01010,
        0b01010,
        0b10001,
        0b00100,
        0b01010,
        0b10101,
        0b01010
    },
};