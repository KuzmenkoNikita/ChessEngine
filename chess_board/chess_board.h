#ifndef __CHESS_BOARD__
#define __CHESS_BOARD__

#include <stdint.h>
#include <stdbool.h>

/** 
 * @brief game board information
 * 
 * Game board coordinates can be represented by 2 way:
 * 1) 8x8 two-dimensional space (array) with coordinates x and y:
 * 
 *         y  
 *         7 
 *      8    |
 *      7    |
 *      6    |
 *      5    |
 *      4    |
 *      3    |
 *      2    |
 *      1  0 |__ __ __ __ __ __ __ __
 *                                    7 x 
 *            a  b  c  d  e  f  g  h
 * 
 * 2) 16x16 one-dimensional space (array) with one coordinate z and
 *     with the real game space in the sentre
 * 
 *  X X X X      X X X X X X X X     X X X X
 *  X X X X      X X X X X X X X     X X X X
 *  X X X X      X X X X X X X X     X X X X
 *  X X X X      X X X X X X X X     X X X X
 *             __ __ __ __ __ __ x  
 * 
 *  X X X X   |  0 0 0 0 0 0 0 0     X X X X
 *  X X X X   |  0 0 0 0 0 0 0 0     X X X X
 *  X X X X   |  0 0 0 0 0 0 0 0     X X X X
 *  X X X X   |  0 0 0 0 0 0 0 0     X X X X
 *  X X X X   |  0 0 0 0 0 0 0 0     X X X X
 *  X X X X   |  0 0 0 0 0 0 0 0     X X X X
 *  X X X X   |  0 0 0 0 0 0 0 0     X X X X
 *  X X X X   |  0 0 0 0 0 0 0 0     X X X X
 *           y
 *           
 *  X X X X      X X X X X X X X     X X X X
 *  X X X X      X X X X X X X X     X X X X
 *  X X X X      X X X X X X X X     X X X X
 *  X X X X      X X X X X X X X     X X X X
 * 
 * */

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
    FIGURE_COLOR_BLACK,
    FIGURE_COLOR_WHITE
}chess_fig_color;

/**
 * @brief translate x,y coordinates to one dimension
 *          coordinate
 * @param x     x coordinate
 * @param y     y coordinate
 * @param p_z   pointer to result - one dimension coordinate (we call it z coordinate );
 * @return true if OK, false if error
 */
bool board_translate_xy_to_x(uint8_t x, uint8_t y, uint16_t* p_z);








#endif /* __CHESS_BOARD__ */