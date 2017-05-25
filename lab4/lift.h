#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTextEdit>
#include <QSet>
#include <QQueue>
#include <QLabel>

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
        arrived_state,
        wait
    };
    lift(); //конструктор лифта
    void set_log(QTextEdit* log);
    void set_labels(QLabel* doors_l, QLabel* cabin_l);
    void get_order(int o);

private:
    QTextEdit* log;
    QLabel* lab;
    int min_floor;
    int max_floor;
    int floor;  // текущий этаж
    doors* door;
    lift_state st;
    bool is_empty;
    QSet<int>* orders;   //"заказы"
    QQueue<int>* queue; //очередь заказов
    int opti_order();
    void set_state(lift_state);
    void wait_here();   //ждать столько то секунд
    void go_to(int o);        //топать на такой то этаж


public slots:
    void to_first_floor();  //топать на первый этаж
    void go_up();  //топать вверх
    void go_down(); //топать вниз
    void reorder(); //пересчитать заказы

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
