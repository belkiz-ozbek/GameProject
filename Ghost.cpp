// Ghost.cpp

#include "Ghost.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Player.h"

Ghost::Ghost(int sceneLength, int sceneWidth, Player& player)
    : sceneLength(sceneLength), sceneWidth(sceneWidth), player(player)
{
    setRect(0, 0, 20, 20);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(randomMove()));
    timer->start(100);
}

void Ghost::randomMove()
{
    int randDirection = rand() % 4; // 0: up, 1: right, 2: down, 3: left

    switch (randDirection) {
    case 0: // Up
        if (y() > 0)
            setPos(x(), y() - 10);
        break;
    case 1: // Right
        if (x() + rect().width() < sceneLength)
            setPos(x() + 10, y());
        break;
    case 2: // Down
        if (y() + rect().height() < sceneWidth)
            setPos(x(), y() + 10);
        break;
    case 3: // Left
        if (x() > 0)
            setPos(x() - 10, y());
        break;
    default:
        break;
    }
}

