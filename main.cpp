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
    Player * rect = new Player(sceneLength, sceneWidth, 100,100, 250,250);


    Ghost * ghost = new Ghost(sceneLength, sceneWidth);




    // add the item to the scene
    scene->addItem(rect);
    scene->addItem(ghost);



    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();

    QThread* thread = new QThread();
    ghost->moveToThread(thread);

    QObject::connect(thread, &QThread::started, ghost, &Ghost::randomMove);
    thread->start();

    // Start the thread
    /*  bool boolen = true;

    while (boolen) {
        std::cout << rect->x() << std::endl << ball-> x() << std::endl;
        if (rect->x() < ball->x())
        {thread->quit();
            boolen = false;
        }}

*/


    return a.exec();
}
