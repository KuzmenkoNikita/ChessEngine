#ifndef __CHESS_PIECES__
#define __CHESS_PIECES__

#include <stdbool.h>
#include <stdint.h>

/* ********************************* */
/** @brief pieces types */
typedef enum
{
    FIGURE_TYPE_UNDEFINED,
    FIGURE_TYPE_KING,     
    FIGURE_TYPE_QUEEN,   
    FIGURE_TYPE_ROOK,    
    FIGURE_TYPE_BISHOP,  
    FIGURE_TYPE_KNIGHT,  
    FIGURE_TYPE_PAWN,    
}chess_fig_type;

/* ********************************* */
/** @brief figure colors */
typedef enum
{
    FIGURE_COLOR_UNDEFINED,
    FIGURE_COLOR_BLACK,
    FIGURE_COLOR_WHITE
}chess_fig_color;

bool pieces_get_moves_coords(uint16_t z, uint16_t* p_coords, uint16_t* p_moves_cnt);



#endif /* __CHESS_PIECES__ */