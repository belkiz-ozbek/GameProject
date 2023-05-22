#include <QKeyEvent>
#include "player.h"
#include <random>
#include "Ball.h"
#include <QThread>
#include <chrono>
#include <iostream>
#include <QtCore>

int distance = 10;

void player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        setPos(x()-distance,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+distance,y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-distance);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+distance);

    }
}



void Ball::randomMove(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 3);


    while(true){
        int randomNumber = distribution(gen);




    switch(randomNumber)
    {
    case 0:
        if (x()<=distance || y()<=distance )
            break;
        setPos(x()-distance,y()-distance);
        break;
    case 1:
        if (x()>=490  || y()<=distance )
            break;
        setPos(x()+distance,y()-distance);
        break;
    case 2:
        if (x()>=490  || y() >= 490 )
            break;
        setPos(x()+distance,y()+distance);
        break;
    case 3:
        if (x()<=distance || y() >= 490 )
            break;
        setPos(x()-distance,y()+distance);
        break;
    }
        QThread::msleep(10000);
    }
}
