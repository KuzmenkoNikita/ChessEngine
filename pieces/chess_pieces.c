#include "chess_pieces.h"
#include "chess_board.h"

#define KING_MOVES_CNT  8

static const int8_t mKingMoves[KING_MOVES_CNT] = {1, -1, 16, -16, 17, -17, 15, -15};
/* ************************************************************************** */
static bool is_king_in_check(uint16_t king_z_coord, chess_fig_color king_color);
static bool is_king_in_diagonal_check(uint16_t king_z_coord, chess_fig_color king_color);
static bool is_king_in_line_check(uint16_t king_z_coord, chess_fig_color king_color);
static bool is_king_in_knights_check(int16_t king_z_coord, chess_fig_color king_color);
static bool is_king_in_pawn_check(int16_t king_z_coord, chess_fig_color king_color);
static bool is_king_in_king_check(int16_t king_z_coord, chess_fig_color king_color);
/* ************************************************************************** */

/**
 * @brief function checks is king in check from king
 * @param king_z_coord  king piece coordinate
 * @param king_color    king piece color
 * @return true if king piece in check, false if not
 */
static bool is_king_in_king_check(int16_t king_z_coord, chess_fig_color king_color)
{
    for(uint8_t i = 0; i < KING_MOVES_CNT; ++i)
    {
        uint16_t new_coord = king_z_coord + mKingMoves[i];

        if(board_check_border(new_coord))
        {
            chess_fig_type piece;

            board_get_figure_type(new_coord, &piece);

            if(piece == FIGURE_TYPE_KING)
            {
                chess_fig_color  op_king_color;

                board_get_figure_color(new_coord, &op_king_color);

                if(op_king_color != king_color)
                    return true;
            }
        }
    }

    return false;
}

/**
 * @brief function checks is king in check from pawns
 * @param king_z_coord  king piece coordinate
 * @param king_color    king piece color
 * @return true if king piece in check, false if not
 */
static bool is_king_in_pawn_check(int16_t king_z_coord, chess_fig_color king_color)
{
    int8_t m_delta_coords[2];

    if(king_color == FIGURE_COLOR_BLACK)
    {
        m_delta_coords[0] = -17;
        m_delta_coords[1] = -15; 
    }
    else
    {
        m_delta_coords[0] = 17;
        m_delta_coords[1] = 15;   
    }

    for(uint8_t i = 0; i < 2; ++i)
    {
        uint16_t new_coord = king_z_coord + m_delta_coords[i];

        if(board_check_border(new_coord))
        {
            chess_fig_type piece;

            board_get_figure_type(new_coord, &piece);

            if(piece == FIGURE_TYPE_PAWN)
            {
                chess_fig_color  pawn_color;

                board_get_figure_color(new_coord, &pawn_color);

                if(pawn_color != king_color)
                    return true;
            }
        }
    }

    return false;
}

/**
 * @brief function checks is king in check from knights
 * @param king_z_coord  king piece coordinate
 * @param king_color    king piece color
 * @return true if king piece in check, false if not
 */
static bool is_king_in_knights_check(int16_t king_z_coord, chess_fig_color king_color)
{
    int8_t m_delta_coords[8] = {33, 18, -14, -31, -33, -18, 14, 31};

    for(uint8_t i = 0; i < 8; ++i)
    {
        uint16_t new_coord = king_z_coord + m_delta_coords[i];

        if(board_check_border(new_coord))
        {
            chess_fig_type piece;

            board_get_figure_type(new_coord, &piece);

            if(piece == FIGURE_TYPE_KNIGHT)
            {
                chess_fig_color  knight_color;

                board_get_figure_color(new_coord, &knight_color);

                if(knight_color != king_color)
                    return true;
            }
        }
    }

    return false;
}

/**
 * @brief function checks is king in check from straight lines
 * @param king_z_coord  king piece coordinate
 * @param king_color    king piece color
 * @return true if king piece in check, false if not
 */
static bool is_king_in_line_check(uint16_t king_z_coord, chess_fig_color king_color)
{
    bool end_line = false;

    int8_t m_delta_coords[4] = {1, -1, 16, -16};

    for(uint8_t i = 0; i < 4; ++i)
    {
        uint16_t new_coordinate = king_z_coord;

        do
        {
            new_coordinate += m_delta_coords[i];

            end_line = !board_check_border(new_coordinate);

            if(!end_line)
            {
                chess_fig_type piece;

                board_get_figure_type(new_coordinate, &piece);

                if(piece != FIGURE_TYPE_UNDEFINED)
                {
                    end_line = true;
                    chess_fig_color  new_coord_piece_color;

                    board_get_figure_color(new_coordinate, &new_coord_piece_color);

                    if(new_coord_piece_color != king_color) 
                    {
                        if((piece == FIGURE_TYPE_QUEEN) || (piece == FIGURE_TYPE_ROOK))
                            return true;
                    }
                }
            }
        } while (!end_line);
    }
    
    return false;
}


/**
 * @brief function checks is king in check from diagonals
 * @param king_z_coord  king piece coordinate
 * @param king_color    king piece color
 * @return true if king piece in check, false if not
 */
static bool is_king_in_diagonal_check(uint16_t king_z_coord, chess_fig_color king_color)
{
    bool end_line = false;

    int8_t m_delta_coords[4] = {17, -17, 15, -15};

    for(uint8_t i = 0; i < 4; ++i)
    {
        uint16_t new_coordinate = king_z_coord;

        do
        {
            new_coordinate += m_delta_coords[i];

            end_line = !board_check_border(new_coordinate);

            if(!end_line)
            {
                chess_fig_type piece;

                board_get_figure_type(new_coordinate, &piece);

                if(piece != FIGURE_TYPE_UNDEFINED)
                {
                    end_line = true;
                    chess_fig_color  new_coord_piece_color;

                    board_get_figure_color(new_coordinate, &new_coord_piece_color);

                    if(new_coord_piece_color != king_color) 
                    {
                        if((piece == FIGURE_TYPE_QUEEN) || (piece == FIGURE_TYPE_BISHOP))
                            return true;
                    }
                }
            }
        } while (!end_line);
    }
    
    return false;
}


/**
 * @brief function checks is king in check
 * @param king_z_coord  king piece coordinate
 * @param king_color    king piece color
 * @return true if king piece in check, false if not
 */
static bool is_king_in_check(uint16_t king_z_coord, chess_fig_color king_color)
{
    if(is_king_in_line_check(king_z_coord, king_color))
        return true;

    if(is_king_in_diagonal_check(king_z_coord, king_color))
        return true;

    if(is_king_in_knights_check(king_z_coord, king_color))
        return true;

    if(is_king_in_pawn_check(king_z_coord, king_color))
        return true;

    if(is_king_in_king_check(king_z_coord, king_color))
        return true;
    
    return false;
}


bool pieces_get_moves_coords(uint16_t z, uint16_t* p_coords, uint16_t* p_moves_cnt)
{
    chess_fig_type piece;
    *p_moves_cnt = 0;

    if(!board_get_figure_type(z, &piece))
        return false;

    chess_fig_color eFigColor = FIGURE_COLOR_UNDEFINED;

    if(!board_get_figure_color(z, &eFigColor))
        return false;

    switch(piece)
    {
        case FIGURE_TYPE_KING:
        {
            /* TODO: remove this code to function get_king_moves_coords() */
            for(uint8_t i = 0; i < KING_MOVES_CNT; ++i)
            {
                uint16_t new_coordinate = z + mKingMoves[i];

                if(board_check_border(new_coordinate))
                {
                    chess_fig_type new_coord_piece;
                    if(!board_get_figure_type(new_coordinate, &new_coord_piece))
                        return false;

                    if(new_coord_piece != FIGURE_TYPE_UNDEFINED)
                    {
                        chess_fig_color  new_coord_piece_color;

                        if(!board_get_figure_color(new_coordinate, &new_coord_piece_color))
                            return false;

                        if(new_coord_piece_color != eFigColor)
                        {
                            if(!is_king_in_check(new_coordinate, eFigColor))
                                p_coords[*p_moves_cnt++] = new_coordinate;
                        }
                    }
                    else
                    {
                        if(!is_king_in_check(new_coordinate, eFigColor))
                            p_coords[*p_moves_cnt++] = new_coordinate;
                    }
                }
            }

            break;
        }   
        
        case FIGURE_TYPE_QUEEN:   
        case FIGURE_TYPE_ROOK:   
        case FIGURE_TYPE_BISHOP:  
        case FIGURE_TYPE_KNIGHT:  
        case FIGURE_TYPE_PAWN:
        default: return false;   
    }
}