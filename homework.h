#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Homework; }
QT_END_NAMESPACE

class Homework : public QMainWindow
{
    Q_OBJECT

public:
    Homework(QWidget *parent = nullptr);
    ~Homework();

private:
    Ui::Homework *ui;
};
#endif // HOMEWORK_H
