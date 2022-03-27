#include <stdio.h>
#include <stdint.h>
#include "chess_board.h"
#include "chess_pieces.h"

int main()
{
    uint8_t x = 3;
    uint8_t y = 6;

    uint16_t z = 0;

    board_translate_xy_to_z(x, y, &z);

    bool in_border = board_check_border(z);

    //uint16_t* p_coords = 0;
    //uint16_t moves = 0;
    //pieces_get_moves_coords(z, p_coords, &moves);


    while(1);
}