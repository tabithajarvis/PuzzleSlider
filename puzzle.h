#ifndef PUZZLE_H
#define PUZZLE_H

#include <QTime>
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
    PuzzlePiece * getLastPiece();
    void setLastPiece(PuzzlePiece *);
    QGridLayout *getGrid();
    void startNewGame();

public slots:
    void pieceClicked(PuzzlePiece *);

protected:
    void rebuildGrid();
    void swap(PuzzlePiece *, PuzzlePiece *);
    bool canMove(PuzzlePiece *);
    void checkWin();

private:
    uint puzzleSize;
    std::vector<PuzzlePiece *> pieces;
    PuzzlePiece *lastPiece;
    QGridLayout *grid;

signals:
    void completed();
};

#endif // PUZZLE_H
