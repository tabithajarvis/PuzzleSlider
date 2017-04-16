#ifndef PUZZLE_H
#define PUZZLE_H

#include <QLabel>

class Puzzle
{
public:
    Puzzle();
    void setPuzzleSize(uint size);
    uint getPuzzleSize();
    bool addPuzzlePiece(QLabel *piece);
    std::vector<QLabel *> pieces;

private:
    uint puzzleSize;
};

#endif // PUZZLE_H
