#ifndef PUZZLE_H
#define PUZZLE_H

#include <QLabel>
#include <QGridLayout>
#include <QMouseEvent>
#include <QMainWindow>
#include "puzzlepiece.h"

class Puzzle : public QWidget
{
   Q_OBJECT

public:
    Puzzle(QMainWindow *, uint);
    uint getPuzzleSize();
    bool addPuzzlePiece(PuzzlePiece *piece);
    PuzzlePiece * getPuzzlePiece(uint);
    void movePiece(PuzzlePiece *);
    bool canMove(PuzzlePiece *);
    PuzzlePiece * getLastPiece();
    void setLastPiece(PuzzlePiece *);
    void swap(PuzzlePiece *, PuzzlePiece *);
    void rebuildGrid();
    QGridLayout *getGrid();

public slots:
    void pieceClicked(PuzzlePiece *);

private:
    uint puzzleSize;
    std::vector<PuzzlePiece *> pieces;
    PuzzlePiece *lastPiece;
    QGridLayout *grid;

};

#endif // PUZZLE_H
