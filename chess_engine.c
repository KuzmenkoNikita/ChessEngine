#include <stdint.h>

/** @brief game cell is 8 bit unsigned integer:
 * bits 0-3 - figure type
 * bit 4 - moving flag
 * bit 5 - black figure flag
 * bit 6 - white figure flag
*/
typedef uint8_t game_cell;   

#define GAME_DESK_LINE_SIZE 8
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
#define FIGURE_WHITE_MASK   0x10
/* ********************************* */
#define FIGURE_COLOR(f)     ((f) & (FIGURE_BLACK_MASK | FIGURE_WHITE_MASK))
#define FIGURE_TYPE(f)      ((f) & FIGURE_TYPE_MASK)
#define IS_FIGURE_MOVED(f)  ((f) & FIGURE_MOVE_MASK)
#define OUT_BOARD(x,y)      ((unsigned)(x) >= GAME_DESK_LINE_SIZE || (unsigned)(y) >= GAME_DESK_LINE_SIZE)
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
/** @brief  game desk array */                                                           
game_cell m_game_desk[] = 
{
    255, 255, 255, 255,     255, 255, 255, 255,255, 255, 255, 255,      255, 255, 255, 255,
    255, 255, 255, 255,     255, 255, 255, 255,255, 255, 255, 255,      255, 255, 255, 255,
    255, 255, 255, 255,     255, 255, 255, 255,255, 255, 255, 255,      255, 255, 255, 255,
    255, 255, 255, 255,     255, 255, 255, 255,255, 255, 255, 255,      255, 255, 255, 255,

    255, 255, 255, 255,      0,   0,   0,   0,  0,   0,   0,   0,       255, 255, 255, 255,
    255, 255, 255, 255,      0,   0,   0,   0,  0,   0,   0,   0,       255, 255, 255, 255,
    255, 255, 255, 255,      0,   0,   0,   0,  0,   0,   0,   0,       255, 255, 255, 255,
    255, 255, 255, 255,      0,   0,   0,   0,  0,   0,   0,   0,       255, 255, 255, 255,
    255, 255, 255, 255,      0,   0,   0,   0,  0,   0,   0,   0,       255, 255, 255, 255,
    255, 255, 255, 255,      0,   0,   0,   0,  0,   0,   0,   0,       255, 255, 255, 255,
    255, 255, 255, 255,      0,   0,   0,   0,  0,   0,   0,   0,       255, 255, 255, 255,
    255, 255, 255, 255,      0,   0,   0,   0,  0,   0,   0,   0,       255, 255, 255, 255,

    255, 255, 255, 255,     255, 255, 255, 255,255, 255, 255, 255,      255, 255, 255, 255,
    255, 255, 255, 255,     255, 255, 255, 255,255, 255, 255, 255,      255, 255, 255, 255,
    255, 255, 255, 255,     255, 255, 255, 255,255, 255, 255, 255,      255, 255, 255, 255,
    255, 255, 255, 255,     255, 255, 255, 255,255, 255, 255, 255,      255, 255, 255, 255,
};

/* ********************************* */
/** @brief  struct contains information about figure */  
typedef struct figure_info_
{
    uint8_t figure_code;    
    uint8_t x; 
    uint8_t y;
    struct figure_info_* p_next_fig; /* Pointer to next figure */
}figure_info;

/* ********************************* */
/** @brief  white and black figures info */     
figure_info m_w_figs_info[PLAYER_MAX_FIGURES_COUNT];
figure_info m_b_figs_info[PLAYER_MAX_FIGURES_COUNT];

/* ********************************* */
/** @brief figure move descriptor */ 
typedef struct 
{
    uint8_t figure_code;
    uint8_t x1;
    uint8_t x2;
    uint8_t y1;
    uint8_t y2;
}move_desc;

uint32_t engine_make_move(void)
{

}



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
}