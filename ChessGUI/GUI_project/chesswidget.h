#ifndef CHESSWIDGET_H
#define CHESSWIDGET_H

#include <QPen>
#include <QWidget>
#include <QRect>
#include <QImage>

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

class ChessWidget : public QWidget
{
    Q_OBJECT
private:
    QPen    selectPen;          /* pen for drawing selected cell */
    QRect   selectRect;         /* Rectangle for selecting cell */
    bool    isCellSelected;
    coordinate_t selected_cell; /* User selected cell */

    QImage black_pawn_img;
    QImage black_rook_img;
public:
    explicit ChessWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent* event);
private:
    bool translate_widget_to_board_coords(coordinate_t& board_coord, coordinate_t& widget_coord);
    void draw_select_rect(coordinate_t& coordinate, QPainter& painter);
    bool TranslateBoardCoordToRectCoords(quint8 board_x, quint8 board_y, quint32& rect_x, quint32& rect_y);

signals:

};

#endif // CHESSWIDGET_H
