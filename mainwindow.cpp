#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Change window properties
    this->resize(1000, 800);
    this->setWindowTitle("Puzzle Slider");

    // Add puzzle
    Puzzle *puzzle = new Puzzle(this, 4);
}

MainWindow::~MainWindow()
{
}
