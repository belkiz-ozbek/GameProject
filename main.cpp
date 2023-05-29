#include <QApplication>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QBrush>
#include <QColor>
#include <QPen>
#include "Player.h"
#include "Ghost.h"
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
    int sceneLength = 500;
    int sceneWidth = 500;

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, sceneLength, sceneWidth);
    scene->setBackgroundBrush(QBrush(QColor(0, 0, 0)));


    // create an item to put into the scene
    Player * rect = new Player(sceneLength, sceneWidth, 100,100,0 ,0  );
    Ghost * ghost = new Ghost(sceneLength, sceneWidth, *rect);




    // add the item to the scene
    scene->addItem(rect);
    scene->addItem(ghost);





    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();

    QThread* thread = new QThread();
    ghost->moveToThread(thread);

    QObject::connect(thread, &QThread::started, ghost, &Ghost::randomMove);
    thread->start();





    return a.exec();
}
