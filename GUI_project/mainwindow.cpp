#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wgt = new ChessWidget(this);
    ui->verticalLayout->addWidget(wgt);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    wgt->start_new_game();
}
