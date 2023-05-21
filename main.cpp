#include <QApplication>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QBrush>
#include <QColor>
#include <QPen>
#include "player.h"
#include "Ball.h"
#include <QThread>
#include <QTimer>
#include <iostream>
/*
Prereqs:
-basic knowledge of c++ (pointers and memory management)
-VERY basic knowledge of Qt (widgets)
Tutorial Topics:
-QGraphicsScene
-QGraphicsItem (QGraphicsRectItem)
-QGraphicsView
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 500, 500);
    scene->setBackgroundBrush(QBrush(QColor(0, 0, 0)));


    // create an item to put into the scene
    player * rect = new player();
    rect->setRect(0,0,100,100);
    rect->setPen(QPen(QColor(255, 255, 255), 2));
    rect->setBrush(QBrush(QColor(255, 255, 255)));

    Ball * ball = new Ball();
    ball->setRect(10,10,10,10);
    ball->setPen(QPen(QColor(255, 0, 0), 2));
    ball->setBrush(QBrush(QColor(255, 255, 255)));
    ball->setPos(250,  250);



    // add the item to the scene
    scene->addItem(rect);
    scene->addItem(ball);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);


    view->show();

    QThread* thread = new QThread();
    ball->moveToThread(thread);

    QObject::connect(thread, &QThread::started, ball, &Ball::randomMove);

    // Start the thread
    bool boolen = true;
    thread->start();
    while (boolen) {
        std::cout << rect->x() << std::endl << ball-> x() << std::endl;
        if (rect->x() < ball->x())
        {thread->quit();
            boolen = false;
        }}




    return a.exec();
}
