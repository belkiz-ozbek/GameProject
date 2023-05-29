#ifndef GHOST_H
#define GHOST_H


#include "Player.h"
#include <QtCore>
#include <QGraphicsEllipseItem>

class Ghost:public QObject ,  public QGraphicsRectItem{

    Q_OBJECT

private:
    int sceneLength;
    int sceneWidth;
    int posX;
    int posY;
    bool isActive;
    Player * player;

public:

    Ghost(int sceneLength, int sceneWidth, Player  &player);
    int getPosX();
    int getPosY();
    bool getIsActive();
    void setIsActive(bool control);
    bool active();







public slots:
    void randomMove();

};


#endif // GHOST_H
