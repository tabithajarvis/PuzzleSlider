#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QLabel *lbl;
    Puzzle *puzzle = new Puzzle();

    ui->setupUi(this);

    puzzle->setPuzzleSize(4);

    for(uint i=0; i<puzzle->getPuzzleSize()*puzzle->getPuzzleSize(); i++)
    {
        lbl = new QLabel(this);
        lbl->resize(50, 50);
        lbl->setText(QString::number(i+1));
        lbl->setFrameStyle(QFrame::Panel | QFrame::Raised);
        lbl->setAlignment(Qt::AlignCenter);
        ui->puzzleGrid->addWidget(lbl, i/puzzle->getPuzzleSize(), i%puzzle->getPuzzleSize(), 1, 1);
    }
    lbl->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
