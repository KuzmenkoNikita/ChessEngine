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

    black_pawn_img.load(":img/IMG/black_pawn.png");

}

void ChessWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QImage img(":img/IMG/board.png");
    painter.drawImage(0,0,img);

    draw_select_rect(selected_cell, painter);

    QImage img1(":img/IMG/white_pawn.png");
    painter.drawImage(27+BOARD_CELL_WIDTH*4,26+BOARD_CELL_WIDTH*3,img1);

    quint32 img_x = 0;
    quint32 img_y = 0;

    TranslateBoardCoordToRectCoords(0, 0, img_x, img_y);

    painter.drawImage(img_x+2,img_y+2,black_pawn_img);

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

































