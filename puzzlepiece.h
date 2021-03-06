#ifndef PUZZLEPIECE_H
#define PUZZLEPIECE_H

#include <QObject>
#include <QLabel>
#include <QStyle>
#include <QMouseEvent>

class PuzzlePiece : public QLabel
{
Q_OBJECT

public:
    PuzzlePiece(QWidget *, uint);
    uint getCurrentIndex();
    void setCurrentIndex(uint);
    uint getFinalIndex();

protected:
    void mousePressEvent(QMouseEvent *e);

private:
    uint currentIndex;
    uint finalIndex;

signals:
    void pieceClickEvent(PuzzlePiece *);
};

#endif // PUZZLEPIECE_H
