/** @file   ir_events.h
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Header file to define functionality for the ir_events.c  file
*/

#ifndef IR_EVENTS_H
#define IR_EVENTS_H

#include <stdbool.h>

#define CHAR_MIN 0
#define CHAR_MAX 255

int check_ir_receive(void);

#endif
