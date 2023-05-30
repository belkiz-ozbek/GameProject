#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsRectItem>
#include <QKeyEvent>

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

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
    protected:
    void keyPressEvent(QKeyEvent * event);
    override;

};
#endif // PLAYER_H
