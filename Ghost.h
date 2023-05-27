#ifndef GHOST_H
#define GHOST_H



#include <QtCore>
#include <QGraphicsEllipseItem>

class Ghost:public QObject ,  public QGraphicsRectItem{

    Q_OBJECT

private:
    int sceneLength;
    int sceneWidth;
    int posX;
    int posY;
    bool isActive;

public:

    Ghost(int sceneLength, int sceneWidth);
    int getPosX();
    int getPosY();
    bool getIsActive();
    void setIsActive(bool control);







public slots:
    void randomMove();

};


#endif // GHOST_H
