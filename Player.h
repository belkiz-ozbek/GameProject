#ifndef PLAYER_H
#define PLAYER_H


#include <QtCore>
#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem{

private:
    int length;
    int width;
    int posX;
    int posY;
    int sceneLength;
    int sceneWidth;
    int score;

public:
    Player(int l, int w, int posX, int posY, int sceneLength , int sceneWidth);
    int getLength();
    int getWidth();
    int getArea();
    int getPosX();
    int getPosY();
    int getSceneLength();
    int getSceneWidth();
    int getScore();
    void setScore(int point);

    void keyPressEvent(QKeyEvent * event);

};
#endif // PLAYER_H
