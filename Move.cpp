#include <QKeyEvent>
#include "player.h"
#include <random>
#include "Ball.h"
#include <QThread>
#include <chrono>
#include <iostream>
#include <QtCore>

void player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);

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
        QThread::msleep(10000);
    }
}
