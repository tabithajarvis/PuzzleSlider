#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QButtonGroup>
#include "puzzle.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateTimer();
    void resetTimer();
    void toggleTimerActive();

private:
    QPushButton *newGameButton;
    QPushButton *pauseButton;
    QTimer *tickTimer;
    QLabel *timerLabel;
    uint timer;

};

#endif // MAINWINDOW_H
