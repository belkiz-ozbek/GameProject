#ifndef PLAYER_H
#define PLAYER_H

#endif // PLAYER_H
#include <QGraphicsRectItem>

class Player: public QGraphicsRectItem{

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
