// Player.cpp

#include "Player.h"
#include <QKeyEvent>

Player::Player(int l, int w, int posX, int posY, int sceneLength, int sceneWidth, bool isListeningArrowKeys)
    : length(l), width(w), posX(posX), posY(posY), sceneLength(sceneLength), sceneWidth(sceneWidth), score(0), listenArrowKeys(isListeningArrowKeys)
{
    setPixmap(QPixmap(":/images/startIcon.png"));
}

int Player::getLength()
{
    return length;
}

int Player::getWidth()
{
    return width;
}

int Player::getArea()
{
    return length * width;
}

int Player::getPosX()
{
    return posX;
}

int Player::getPosY()
{
    return posY;
}

int Player::getSceneLength()
{
    return sceneLength;
}

int Player::getSceneWidth()
{
    return sceneWidth;
}

int Player::getScore()
{
    return score;
}

void Player::setScore(int point)
{
    score = point;
}

void Player::moveLeft()
{
    if (posX > 0) {
        setPos(x() - 10, y());
        posX -= 10;
    }
}

void Player::moveRight()
{
    if (posX + length < sceneLength) {
        setPos(x() + 10, y());
        posX += 10;
    }
}

void Player::moveUp()
{
    if (posY > 0) {
        setPos(x(), y() - 10);
        posY -= 10;
    }
}

void Player::moveDown()
{
    if (posY + width < sceneWidth) {
        setPos(x(), y() + 10);
        posY += 10;
    }
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if(listenArrowKeys){
        switch (event->key()) {
        case Qt::Key_Left:
            moveLeft();
            break;
        case Qt::Key_Right:
            moveRight();
            break;
        case Qt::Key_Up:
            moveUp();
            break;
        case Qt::Key_Down:
            moveDown();
            break;
        default:
            break;
        }
    }else{


        switch (event->key()) {
        case Qt::Key_A:
            moveLeft();
            break;
        case Qt::Key_D:
            moveRight();
            break;
        case Qt::Key_W:
            moveUp();
            break;
        case Qt::Key_S:
            moveDown();
            break;
        default:
            break;
        }

    }
}
