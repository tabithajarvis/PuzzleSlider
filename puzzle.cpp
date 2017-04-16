#include "puzzle.h"

Puzzle::Puzzle()
{

}

void Puzzle::setPuzzleSize(uint size)
{
    this->puzzleSize = size;
}

uint Puzzle::getPuzzleSize()
{
    return this->puzzleSize;
}

bool Puzzle::addPuzzlePiece(QLabel *piece)
{
    if(pieces.size() >= this->getPuzzleSize())
    {
        return false;
    }

    pieces.push_back(piece);

    return true;
}
