#include <stdio.h>
#include <stdint.h>
#include "chess_board.h"

int main()
{
    uint8_t x = 0;
    uint8_t y = 0;

    board_translate_z_to_xy(257, &x, &y);

    while(1);
}