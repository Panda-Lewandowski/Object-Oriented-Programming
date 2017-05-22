#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QSet>
#include <QTime>
#include <QTimer>
#include <algorithm>
#include "doors.h"

using namespace std;

class lift : public QObject
{
    Q_OBJECT

public:
    enum lift_state //состояния лифта
    {
        going_up,
        going_down,
        opening_state,
        closing_state,
        opened_state,
        wait
    };
    lift(); //конструктор лифта

private:
    int min_floor;
    int max_floor;
    int floor;  // текущий этаж
    doors door;
    lift_state st;
    bool is_empty;
    QSet<int> orders;   //"заказы"
    int opti_order();
    void set_state(int);

public slots:
    void wait_here(double);   //ждать столько то секунд
    void to_first_floor();  //топать на первый этаж
    void go_to(int);        //топать на такой то этаж


signals:
    void arrived();  //приехал
    void floor_changed(int);  //пункт назначения поменялся
    void change_st(int);      //состояние поменялось
    void open_doors();  //открыть двери
    void close_doors(); //закрыть двери
    void up(); //едет вверх
    void down();  //едет вниз
};

#endif // LIFT_H
