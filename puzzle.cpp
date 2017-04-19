#include "puzzle.h"

#include <QDebug>


Puzzle::Puzzle(QMainWindow *parent, uint size) : QWidget(parent)
{
    QWidget::setGeometry(
        parent->width()/3,
        parent->height()/10,
        uint(float(parent->width())*0.6f),
        uint(float(parent->height())*0.8f));

    this->puzzleSize = size;
    this->grid = new QGridLayout(this);

    PuzzlePiece *lbl;

    for(uint i=0; i<this->puzzleSize*this->puzzleSize; i++)
    {
        lbl = new PuzzlePiece(this, i);
        this->addPuzzlePiece(lbl);
        lbl->setText(QString::number(lbl->getFinalIndex()+1));
        lbl->setFixedSize(this->width()/this->getPuzzleSize() - this->getPuzzleSize() * 3, this->height()/this->getPuzzleSize() - this->getPuzzleSize() * 3);
        this->grid->addWidget(lbl, i/this->getPuzzleSize(), i%this->getPuzzleSize(), 1, 1, Qt::AlignCenter);
    }

    // Hide the last label.
    lbl->hide();
    this->setLastPiece(lbl);

}

QGridLayout *Puzzle::getGrid()
{
    return grid;
}

uint Puzzle::getPuzzleSize()
{
    return this->puzzleSize;
}

bool Puzzle::addPuzzlePiece(PuzzlePiece *piece)
{
    if(pieces.size() >= this->getPuzzleSize()*this->getPuzzleSize())
    {
        qDebug() << "Cannot add any more pieces to a puzzle of size " << this->getPuzzleSize();
        return false;
    }

    pieces.push_back(piece);

    return true;
}

PuzzlePiece *Puzzle::getPuzzlePiece(uint i)
{
    return pieces.at(i);
}

PuzzlePiece *Puzzle::getLastPiece()
{
    return this->lastPiece;
}

void Puzzle::setLastPiece(PuzzlePiece *piece)
{
    this->lastPiece = piece;
}

void Puzzle::movePiece(PuzzlePiece *piece)
{
    if(canMove(piece))
    {
    // Rebuild the grid
    this->swap(piece, this->getLastPiece());
    }
}

bool Puzzle::canMove(PuzzlePiece *piece)
{
    qDebug() << "canMove entered.";
    uint loc_clicked = piece->getCurrentIndex();
    uint loc_empty = this->getLastPiece()->getCurrentIndex();
    int difference = loc_clicked - loc_empty;

    // Allow a move if the clicked piece is within 1
    // column or row of the empty piece.
    if(difference == 1
    || difference == -1
    || difference == int(this->getPuzzleSize())
    || difference == -int(this->getPuzzleSize()))
    {
        return true;
    }

    return false;

}

void Puzzle::swap(PuzzlePiece *a, PuzzlePiece *b)
{
    // Swap position in vector for reconstruction of grid.
    pieces[a->getCurrentIndex()] = b;
    pieces[b->getCurrentIndex()] = a;

    // Swap current indices
    uint temp = a->getCurrentIndex();
    a->setCurrentIndex(b->getCurrentIndex());
    b->setCurrentIndex(temp);
}

void Puzzle::pieceClicked(PuzzlePiece *piece)
{
    qDebug() << "pieceClicked entered.";
    movePiece(piece);
    rebuildGrid();
}

void Puzzle::rebuildGrid()
{
    while(!this->grid->isEmpty())
    {
        grid->removeItem(grid->itemAt(0));
    }

    for(uint i=0; i<pieces.size(); i++)
    {
        grid->addWidget(pieces[i], i/this->getPuzzleSize(), i%this->getPuzzleSize(), 1, 1, Qt::AlignCenter);
    }

//    grid->update();

}

void Puzzle::startNewGame()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    uint emptyIndex;
    uint shuffleCount = 1000;

    while(shuffleCount > 0)
    {
        emptyIndex = this->getLastPiece()->getCurrentIndex();

        // Get random move value
        uint random = qrand() % 4;

        switch(random)
        {
            case 0:
                // Attempt to swap up.
                if(emptyIndex > this->getPuzzleSize())
                {
                    movePiece(this->pieces[emptyIndex - this->getPuzzleSize()]);
                    shuffleCount--;
                }
                break;
            case 1:
                // Attempt to swap down.
                if(emptyIndex < this->getPuzzleSize() * (this->getPuzzleSize() - 1))
                {
                    movePiece(this->pieces[emptyIndex + this->getPuzzleSize()]);
                    shuffleCount--;
                }
                break;
            case 2:
                // Attempt to swap left
                if(emptyIndex % this->getPuzzleSize() > 0)
                {
                    movePiece(this->pieces[emptyIndex - 1]);
                    shuffleCount--;
                }
                break;
            default:
                // Attempt to swap right
                if(emptyIndex % this->getPuzzleSize() < this->getPuzzleSize() - 1)
                {
                    movePiece(this->pieces[emptyIndex + 1]);
                    shuffleCount--;
                }
                break;
        }
    }

    this->rebuildGrid();
}
