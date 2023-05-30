// Ghost.h

#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Player.h"

class Ghost : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int sceneLength;
    int sceneWidth;
    Player& player;

public:
    Ghost(int sceneLength, int sceneWidth, Player& player);

public slots:
    void randomMove();
};

#endif // GHOST_H
