#include "mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Change window properties
    this->resize(1000, 800);
    this->setWindowTitle("Puzzle Slider");

    // Add puzzle
    Puzzle *puzzle = new Puzzle(this, 4);
    puzzle->startNewGame();

    // Add buttons
    newGameButton = new QPushButton("New Game", this);
    pauseButton = new QPushButton("Pause", this);

    // Add timer
    timer = 0;
    tickTimer = new QTimer(this);
    tickTimer->start(1000);
    timerLabel = new QLabel(this);
    timerLabel->setText(QString::number(timer));
    timerLabel->resize(200, 50);

    // Set up Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(newGameButton);
    layout->addWidget(pauseButton);
    layout->addWidget(timerLabel);

    layout->setGeometry(QRect(50, 50, 200, 600));
    layout->update();

    // Connect signals and slots
    connect(newGameButton, SIGNAL(released()), puzzle, SLOT(startNewGame()));
    connect(newGameButton, SIGNAL(released()), this, SLOT(resetTimer()));
    connect(tickTimer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    connect(pauseButton, SIGNAL(released()), this, SLOT(toggleTimerActive()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateTimer()
{
    timer++;
    timerLabel->setText(QString::number(timer));
}

void MainWindow::resetTimer()
{
    timer = 0;
    timerLabel->setText(QString::number(timer));

    // Ensure the timer was not stopped from a pause
    tickTimer->start(1000);
    pauseButton->setText("Pause");
}

void MainWindow::toggleTimerActive()
{
    if(tickTimer->isActive())
    {
        tickTimer->stop();
        pauseButton->setText("Play");
    }
    else
    {
        tickTimer->start(1000);
        pauseButton->setText("Pause");
    }

    // TODO: add shield that hides the current game on pause
}

