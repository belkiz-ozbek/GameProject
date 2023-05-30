#include "Ghost.h"
#include "qpen.h"
#include "Player.h"
#include <random>
#include <QTimer>
Ghost::Ghost(int sceneLengthY , int sceneWidthX, Player &player ){
    setPixmap(QPixmap(":/images/ghost.png"));
    this->isActive = true;
    this->sceneLength =sceneLengthY;
    this->sceneWidth = sceneWidthX;
    this->player = &player;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(0, sceneWidthX);
    int posX = distribution(gen);
    std::uniform_int_distribution<int> dis(0, sceneLengthY);
    int posY = dis(gen);
    setPos(posX,  posY);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(randomMove()));
    timer->start(100);

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
    int randDirection = rand() % 4; // 0: up, 1: right, 2: down, 3: left

    switch (randDirection) {
    case 0: // Up
        if (y() > 0)
            setPos(x(), y() - 10);
        break;
    case 1: // Right
        if (x() + 36 < sceneLength)
            setPos(x() + 10, y());
        break;
    case 2: // Down
        if (y() + 36 < sceneWidth)
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
