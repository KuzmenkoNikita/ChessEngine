#include "chess_pieces.h"
#include "chess_board.h"

#define KING_MOVES_CNT  8

static int16_t mKingMoves[KING_MOVES_CNT] = {1, -1, 16, -16, 17, -17, 15, -15};



bool pieces_get_moves_coords(uint16_t z, uint16_t* p_coords, uint16_t* p_moves_cnt)
{
    chess_fig_type piece;

    if(!board_get_figure_type(z, &piece))
        return false;

    switch(piece)
    {
        case FIGURE_TYPE_KING:   
        case FIGURE_TYPE_QUEEN:   
        case FIGURE_TYPE_ROOK:   
        case FIGURE_TYPE_BISHOP:  
        case FIGURE_TYPE_KNIGHT:  
        case FIGURE_TYPE_PAWN:
        default: return false;   
    }
}