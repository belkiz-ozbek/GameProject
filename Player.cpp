#include "Player.h"
#include "qbrush.h"
#include "qevent.h"
#include <iostream>
#include <random>


Player::Player(int sceneLengthY , int sceneWidthX, int l=100, int w=100, int posX = 0, int posY =0 ){

    setBrush(QBrush(QColor(255, 255, 255)));
    length = l;
    width = w;
    posX = posX;
    posY = posY;
    sceneLength = sceneLengthY ;
    sceneWidth = sceneWidthX ;
    setRect(0,0,l,w);
    setPos(posX,posY);
}


int Player::getLength() {
    return length;
}

int Player::getWidth() {
    return width;
}

int Player::getArea() {
    return length * width;
}

int Player::getPosX() {
    return posX;
}

int Player::getPosY() {
    return posY;
}

int Player::getSceneLength() {
    return sceneLength;
}

int Player::getSceneWidth() {
    return sceneWidth;
}

int Player::getScore(){
    return score;
}
void Player::setScore(int point){
    this->score = point;
}


void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right ){
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up ){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down ){
        setPos(x(),y()+10);
    }

    if( x()<= 0)
        setPos(sceneWidth + x(),y());
    if( x()>= sceneWidth)
        setPos(x() - sceneWidth ,y());
    if( y()<=0)
        setPos(x(),y() + sceneLength);
    if( y() >= sceneLength)
        setPos(x(),y() - sceneLength );


    posX = x();
    posY = y();
}
