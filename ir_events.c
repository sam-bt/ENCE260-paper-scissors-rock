/** @file   ir_events.c
    @author Samuel Beattie, Lachlan McLean
    @date   14 Oct 2024
    @brief  Contains the functionality for receiving an ir transmission from another device
*/

#include "ir_events.h"
#include "ir_uart.h"

// Function to check if a valid character has been received via ir communication
int check_ir_receive(void) {
    if (ir_uart_read_ready_p()) {
        int temp_char = ir_uart_getc();
        if (CHAR_MIN <= temp_char && temp_char <= CHAR_MAX) {
            return temp_char;
        }
    }
    return -1;
}