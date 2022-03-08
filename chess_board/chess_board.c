#include "chess_board.h"
#include <stdint.h>

#define GAME_BOARD_LINE_SIZE        8
#define GAME_BOARD_ARR_SIZE         GAME_BOARD_LINE_SIZE * GAME_BOARD_LINE_SIZE * 2 * 2 

/* ********************************* */
/** @brief useful masks and macros*/
#define FIGURE_TYPE_MASK    0x07
#define FIGURE_MOVE_MASK    0x08
#define FIGURE_BLACK_MASK   0x10
#define FIGURE_WHITE_MASK   0x20
#define FIGURE_BORDER_MASK  0x40
#define FIGURE_INDEX_MASK   0x780
/* ********************************* */

/* ********************************* */
/** @brief  game board array. It is 16x16 game desk with 8x8 real game field in the middle
 *  
 * game cell is 8 bit unsigned integer:
 * bits 0-2 - figure type
 * bit 3 - moving flag
 * bit 4 - black figure flag
 * bit 5 - white figure flag
 * bit 6 - Board border
 * bits 7-10 - index in figures array
*/
static uint32_t m_game_board[GAME_BOARD_ARR_SIZE];

/** 
 * @brief  x_y to z translation array 
 * */ 
const static uint8_t m_xy_to_z[GAME_BOARD_LINE_SIZE][GAME_BOARD_LINE_SIZE] = 
{
    {68, 84, 100, 116, 132, 148, 164, 180},
    {69, 85, 101, 117, 133, 149, 165, 181},
    {70, 86, 102, 118, 134, 150, 166, 182},
    {71, 87, 103, 119, 135, 151, 167, 183},
    {72, 88, 104, 120, 136, 152, 168, 184},
    {73, 89, 105, 121, 137, 153, 169, 185},
    {74, 90, 106, 122, 138, 154, 170, 186},
    {75, 91, 107, 123, 139, 155, 171, 187}
};
/* **************************************************************** */
bool board_translate_xy_to_x(uint8_t x, uint8_t y, uint16_t* p_z)
{
    if(x > GAME_BOARD_LINE_SIZE - 1 || y > GAME_BOARD_LINE_SIZE - 1)
        return false;
    
    if(!p_z)
        return false;

    *p_z = m_xy_to_z[x][y];

    return true;
}