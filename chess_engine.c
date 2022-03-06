#include <stdint.h>
#include "chess_engine.h"

/** @brief game cell is 8 bit unsigned integer:
 * bits 0-2 - figure type
 * bit 3 - moving flag
 * bit 4 - black figure flag
 * bit 5 - white figure flag
 * bit 6 - Board border
 * bits 7-10 - index in figures array
*/
typedef uint32_t game_cell;   

#define GAME_BOARD_LINE_SIZE 8
#define PLAYER_MAX_FIGURES_COUNT    16

/** @brief pieces types*/
#define FIGURE_TYPE_KING    1 
#define FIGURE_TYPE_QUEEN   2
#define FIGURE_TYPE_ROOK    3
#define FIGURE_TYPE_BISHOP  4
#define FIGURE_TYPE_KNIGHT  5
#define FIGURE_TYPE_PAWN    6
#define FIGURES_TYPES_COUNT FIGURE_TYPE_PAWN
/* ********************************* */
/** @brief useful masks and macros*/
#define FIGURE_TYPE_MASK    0x07
#define FIGURE_MOVE_MASK    0x08
#define FIGURE_BLACK_MASK   0x10
#define FIGURE_WHITE_MASK   0x20
#define FIGURE_BORDER_MASK  0x40
#define FIGURE_INDEX_MASK   0x780
/* ********************************* */
#define FIGURE_COLOR(f)         ((f) & (FIGURE_BLACK_MASK | FIGURE_WHITE_MASK))
#define FIGURE_TYPE(f)          ((f) & FIGURE_TYPE_MASK)
#define IS_FIGURE_MOVED(f)      ((f) & FIGURE_MOVE_MASK)
#define OUT_BOARD(f)            ((f) & FIGURE_BORDER_MASK)
#define Z_TO_X(z)               (((z) & 15) - 4)
#define Z_TO_Y(z)               (((z) >> 4) - 4)
#define FIGURE_INDEX(f)         (((f) & FIGURE_INDEX_MASK) >> 7)
#define FIGURE_SET_INDEX(f,i)   ((f) | ((i) << 7))
/* ********************************* */
/** @brief  pieces weight */
#define FIGURE_W_PAWN       1000
#define FIGURE_W_BISHOP     3*FIGURE_W_PAWN
#define FIGURE_W_KNIGHT     FIGURE_W_BISHOP
#define FIGURE_W_ROOK       5*FIGURE_W_PAWN
#define FIGURE_W_QUEEN      9*FIGURE_W_ROOK
#define FIGURE_W_INFINITY   10*FIGURE_W_QUEEN
#define FIGURE_W_KING       FIGURE_W_INFINITY
/* ********************************* */
/** @brief  figure type to weight translation array. 
 *          +1 and zeros index aded for easy translation. We can
 *          use in directly for figure type */
static unsigned int m_fig_weigh[FIGURES_TYPES_COUNT+1] = {0, FIGURE_TYPE_KING, FIGURE_TYPE_QUEEN,
                                                            FIGURE_TYPE_ROOK, FIGURE_TYPE_BISHOP,
                                                            FIGURE_TYPE_KNIGHT, FIGURE_TYPE_PAWN};
/* ********************************* */
/** @brief  game board array */ 
#define GAME_BOARD_ARR_SIZE      GAME_BOARD_LINE_SIZE * GAME_BOARD_LINE_SIZE * 2 * 2                                                     
static game_cell m_game_board[GAME_BOARD_ARR_SIZE];

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

/* ********************************* */
/** @brief  arrays with figures coordinates*/ 
static uint8_t m_w_fig_coords[PLAYER_MAX_FIGURES_COUNT];
static uint8_t m_b_fig_coords[PLAYER_MAX_FIGURES_COUNT];


static void engine_init_w_figure(uint8_t figure_type, uint8_t figure_index)
{
    
}


void engine_init_board(void)
{
    for(uint32_t i = 0; i < GAME_BOARD_ARR_SIZE; ++i)
    {
        m_game_board[i] = 0;
        if((Z_TO_X(i) > GAME_BOARD_LINE_SIZE - 1) || (Z_TO_Y(i) >  GAME_BOARD_LINE_SIZE - 1))
            m_game_board[i] |= FIGURE_BORDER_MASK;
    }


    for(uint32_t i = 0; i < PLAYER_MAX_FIGURES_COUNT; ++i)
    {
        if(i + 1 == FIGURE_TYPE_KING)
        {
            m_w_fig_coords[i] = m_xy_to_z[4][0];
            m_b_fig_coords[i] = m_xy_to_z[4][7];

            m_game_board[m_w_fig_coords[i]] |= FIGURE_WHITE_MASK;
            m_game_board[m_b_fig_coords[i]] |= FIGURE_BLACK_MASK;

            FIGURE_SET_INDEX(m_game_board[m_w_fig_coords[i]], i);
            FIGURE_SET_INDEX(m_game_board[m_b_fig_coords[i]], i);
        }

        for(uint8_t j = 0; j < GAME_BOARD_LINE_SIZE; ++j)
        {
            m_w_fig_coords[i]
        }
    }

    

    while(1);
}



















/*
void chess_engine_init(void)
{
    for(uint8_t n = FIGURE_TYPE_PAWN; n >= FIGURE_TYPE_KING; n--)
    {
        for(uint8_t y = 0; y < GAME_DESK_LINE_SIZE; ++y)
        {
            for(uint8_t x = 0; x < GAME_DESK_LINE_SIZE; ++x)
            {

            }
        }
    }
}*/