#include "chesswidget.h"

#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>

#define BOARD_CELL_HEIGHT   63
#define BOARD_CELL_WIDTH    63
#define BOARD_X_COORD_START 26
#define BOARD_Y_COORD_START 26
#define BOARD_LINE_CELL_CNT 8


ChessWidget::ChessWidget(QWidget *parent) : QWidget(parent)
{
    selectPen.setBrush(Qt::green);
    selectPen.setWidth(3);
    selectPen.setStyle(Qt::SolidLine);

    selectRect.setHeight(BOARD_CELL_HEIGHT);
    selectRect.setWidth(BOARD_CELL_WIDTH);


    coordinate_t coord;

    coord.x = 5;
    coord.y = 6;


    add_piece_(coord, piece_color_t::PIECE_COLOR_BLACK, piece_type_t::PIECE_TYPE_PAWN);

}

void ChessWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QImage img(":img/IMG/board.png");
    painter.drawImage(0,0,img);

    draw_select_rect(selected_cell, painter);

    draw_pieces(painter);
}
/* ************************************************************************************************************* */
void ChessWidget::mousePressEvent(QMouseEvent *event)
{
    quint8 board_x = 0;
    quint8 board_y = 0;

    coordinate_t widget_coord(event->pos().x(), event->pos().y());
    coordinate_t board_coord;

    if(translate_widget_to_board_coords(board_coord, widget_coord))
    {
        qDebug()<< "x: "<< board_x;
        qDebug()<< "y: "<< board_y;

         selected_cell = board_coord;

        repaint();
    }
    else
    {
        qDebug()<< "FALSE";
    }
}
/* ************************************************************************************************************* */
bool ChessWidget::translate_widget_to_board_coords(coordinate_t& board_coord, coordinate_t& widget_coord)
{
    if(widget_coord.x < BOARD_X_COORD_START || widget_coord.y < BOARD_Y_COORD_START)
        return false;

    board_coord.x = (widget_coord.x - BOARD_X_COORD_START) / BOARD_CELL_WIDTH;
    board_coord.y = (widget_coord.y - BOARD_Y_COORD_START) / BOARD_CELL_HEIGHT;

    if(board_coord.x > BOARD_LINE_CELL_CNT - 1 || board_coord.y > BOARD_LINE_CELL_CNT - 1)
        return false;

    board_coord.y = (BOARD_LINE_CELL_CNT - 1) - board_coord.y;

    return true;
}
/* ************************************************************************************************************* */
void ChessWidget::draw_select_rect(coordinate_t& coordinate, QPainter& painter)
{
    painter.setPen(selectPen);

    quint32 rect_x = 0;
    quint32 rect_y = 0;

    if(!TranslateBoardCoordToRectCoords(coordinate.x, coordinate.y, rect_x, rect_y))
        return;

    selectRect.moveTo(rect_x, rect_y);

    painter.drawRect(selectRect);
}
/* ************************************************************************************************************* */
bool ChessWidget::TranslateBoardCoordToRectCoords(quint8 board_x, quint8 board_y, quint32& rect_x, quint32& rect_y)
{
    if(board_x > BOARD_LINE_CELL_CNT - 1 || board_y > BOARD_LINE_CELL_CNT - 1)
        return false;

    rect_x = BOARD_X_COORD_START + (board_x * BOARD_CELL_WIDTH);
    rect_y = BOARD_Y_COORD_START + ((BOARD_LINE_CELL_CNT - 1 - board_y) * BOARD_CELL_HEIGHT);

    return true;
}
/* ************************************************************************************************************* */
bool ChessWidget::add_piece_(coordinate_t& coordinate, piece_color_t color, piece_type_t type)
{
    if(coordinate.x > BOARD_LINE_CELL_CNT - 1 || coordinate.y > BOARD_LINE_CELL_CNT - 1)
    {
        return false;
    }

    piece_param_t piece(coordinate, color, type);

    QString path;

    switch(color)
    {
        case piece_color_t::PIECE_COLOR_BLACK:
        {
            path = ":black/IMG/black/";
            break;
        }

        case piece_color_t::PIECE_COLOR_WHITE:
        {
            path = ":white/IMG/white/";
            break;
        }

        default:
        {
            return false;
        }
    }

    switch(type)
    {
        case piece_type_t::PIECE_TYPE_PAWN:
        {
            path +="pawn.png";
            break;
        }

        case piece_type_t::PIECE_TYPE_KNIGHT:
        {
            path +="knight.png";
            break;
        }

        case piece_type_t::PIECE_TYPE_BISHOP:
        {
            path +="bishop.png";
            break;
        }

        case piece_type_t::PIECE_TYPE_ROOK:
        {
            break;
        }

        case piece_type_t::PIECE_TYPE_QUEEN:
        {
            path +="queen.png";
            break;
        }

        case piece_type_t::PIECE_TYPE_KING:
        {
            path +="king.png";
            break;
        }

        default:
        {
            return false;
        }
    }

    piece.img.load(path);

    pieces_vec.push_back(piece);

    return true;
}
/* ************************************************************************************************************* */
void ChessWidget::draw_pieces(QPainter& painter)
{
    for(int i = 0; i < pieces_vec.size(); ++i)
    {
        piece_param_t piece = pieces_vec.at(i);

        quint32 img_x = 0;
        quint32 img_y = 0;

        TranslateBoardCoordToRectCoords(piece.coordinate.x, piece.coordinate.y, img_x, img_y);

        painter.drawImage(img_x + 2, img_y + 2, piece.img);
    }
}
/* ************************************************************************************************************* */






























