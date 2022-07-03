#ifndef CHESSWIDGET_H
#define CHESSWIDGET_H

#include <QPen>
#include <QWidget>
#include <QRect>
#include <QImage>
#include <QVector>
/* **************************************************** */
#define BOARD_LINE_CELL_CNT 8
/* **************************************************** */
typedef struct coordinate_t
{
    quint32 x;
    quint32 y;
    coordinate_t() {};
    coordinate_t(quint32 coord_x, quint32 coord_y)
    {
        x = coord_x;
        y = coord_y;
    }
}coordinate_t;
/* **************************************************** */
enum class piece_color_t
{
    PIECE_COLOR_UNDEFINED,
    PIECE_COLOR_BLACK,
    PIECE_COLOR_WHITE
};
/* **************************************************** */
enum class piece_type_t
{
    PIECE_TYPE_UNDEFINED,
    PIECE_TYPE_PAWN,
    PIECE_TYPE_KNIGHT,
    PIECE_TYPE_BISHOP,
    PIECE_TYPE_ROOK,
    PIECE_TYPE_QUEEN,
    PIECE_TYPE_KING
};
/* **************************************************** */
typedef struct piece_param_t_
{
    piece_color_t   color;
    coordinate_t    coordinate;
    QImage          img;
    piece_type_t    type;
    piece_param_t_() {};

    piece_param_t_(quint32 x, quint32 y)
    {
        coordinate.x = x;
        coordinate.y = y;
    }

    piece_param_t_(quint32 x, quint32 y, piece_color_t init_color, QImage& init_img)
    {
        coordinate.x = x;
        coordinate.y = y;
        color = init_color;
        img = init_img;
    }

    piece_param_t_(coordinate_t init_coordinate, piece_color_t init_color, piece_type_t init_type, QImage& init_img)
    {
        coordinate = init_coordinate;
        color = init_color;
        img = init_img;
        type = init_type;
    }

    piece_param_t_(coordinate_t init_coordinate, piece_color_t init_color, piece_type_t init_type)
    {
        coordinate = init_coordinate;
        color = init_color;
        type = init_type;
    }

}piece_param_t;
/* **************************************************** */

class ChessWidget : public QWidget
{
    Q_OBJECT
private:

    QPen    selectPen;                  /* pen for drawing selected cell */
    QRect   selectRect;                 /* Rectangle for selecting cell */
    bool    isCellSelected;
    coordinate_t selected_cell;         /* User selected cell */
    QVector<piece_param_t> pieces_vec;

    QVector<QVector<piece_param_t*>> board_pieces_vec;

public:
    explicit ChessWidget(QWidget *parent = nullptr);
    void start_new_game();
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent* event);
private:
    bool translate_widget_to_board_coords(coordinate_t& board_coord, coordinate_t& widget_coord);
    void draw_select_rect(coordinate_t& coordinate, QPainter& painter);
    bool TranslateBoardCoordToRectCoords(quint8 board_x, quint8 board_y, quint32& rect_x, quint32& rect_y);
    bool add_piece_(coordinate_t& coordinate, piece_color_t color, piece_type_t type);
    void draw_pieces(QPainter& painter);
    bool add_default_pieces();
    void delete_all_pieces();
signals:

};

#endif // CHESSWIDGET_H
