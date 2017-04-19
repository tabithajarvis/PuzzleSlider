#include "puzzlepiece.h"

#include <QDebug>

PuzzlePiece::PuzzlePiece(QWidget *p, uint final) : QLabel(p)
{
    QObject::connect(this, SIGNAL(pieceClickEvent(PuzzlePiece *)), this->parent(), SLOT(pieceClicked(PuzzlePiece *)));
    this->finalIndex = final;
    this->currentIndex = final;
}

void PuzzlePiece::mouseReleaseEvent(QMouseEvent *e)
{
    if(e)
    {
        emit pieceClickEvent(this);
    }
}

uint PuzzlePiece::getCurrentIndex()
{
    return this->currentIndex;
}

void PuzzlePiece::setCurrentIndex(uint idx)
{
    this->currentIndex = idx;
}

uint PuzzlePiece::getFinalIndex()
{
    return this->finalIndex;
}
