#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chesswidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_clean_board_button_clicked();

    void on_new_game_button_clicked();

private:
    Ui::MainWindow *ui;
    ChessWidget* wgt;
};
#endif // MAINWINDOW_H
