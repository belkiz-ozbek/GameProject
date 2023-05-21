#ifndef BALL_H
#define BALL_H

#include <QtCore>


#include <QGraphicsEllipseItem>

class Ball:public QObject ,  public QGraphicsRectItem{

        Q_OBJECT

    public:



    public slots:
        void randomMove();

};



#endif // MOVE_H
