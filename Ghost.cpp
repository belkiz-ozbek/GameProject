#include "Ghost.h"
#include "qpen.h"
#include "Player.h"


Ghost::Ghost(int sceneLengthY , int sceneWidthX, Player &player ){

    setRect(10,10,10,10);
    setPen(QPen(QColor(255, 0, 0), 2));
    setBrush(QBrush(QColor(15, 144, 2)));
    this->isActive = true;
    this->player = &player;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(0, sceneWidthX);
    int posX = distribution(gen);
    std::uniform_int_distribution<int> dis(0, sceneLengthY);
    int posY = dis(gen);
    setPos(posX,  posY);

    this->posX = posX;
    this->posY = posY;
}


int Ghost::getPosX() {
    return posX;
}

int Ghost::getPosY() {
    return posY;
}

bool Ghost::getIsActive(){
    return (bool) this->isActive;
}
void Ghost::setIsActive(bool control){
    this->isActive = control;
}

bool Ghost::active(){
    bool isActive = true;

//hayaletin durma algoritmasi 
    if (player->getPosX() == this->getPosX()
        ||  player->getPosY() == this->getPosY())
    {
        isActive = false;
    }

    return isActive;
}


void Ghost::randomMove(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 3);

    bool boolen = true ;

    while(boolen){

        if(!this->active()){
            boolen = false;
        }

        int randomNumber = distribution(gen);

        switch(randomNumber)
        {
        case 0:
            if (x()<=10 || y()<=10 )
                break;
            setPos(x()-10,y()-10);
            break;
        case 1:
            if (x()>=490  || y()<=10 )
                break;
            setPos(x()+10,y()-10);
            break;
        case 2:
            if (x()>=490  || y() >= 490 )
                break;
            setPos(x()+10,y()+10);
            break;
        case 3:
            if (x()<=10 || y() >= 490 )
                break;
            setPos(x()-10,y()+10);
            break;
        }
        QThread::msleep(100);

        posX = x();
        posY = y();

    }




}
