#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Change window properties
    this->resize(1000, 800);
    this->setWindowTitle("Puzzle Slider");

    // Add puzzle
    Puzzle *puzzle = new Puzzle(this, 4);
    puzzle->startNewGame();

    QPushButton *newGame = new QPushButton("New Game", this);
    newGame->setGeometry(70, 100, 200, 50);

    QObject::connect(newGame, SIGNAL(released()), puzzle, SLOT(startNewGame()));
}

MainWindow::~MainWindow()
{
}
