#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTextEdit>
#include <QLCDNumber>
#include <QTimer>
#include <QSet>
#include <QQueue>
#include <QLabel>

#include "doors.h"

using namespace std;

class lift : public QObject
{
    Q_OBJECT
    enum lift_state //состояния лифта
    {
        going_up,
        going_down,
        opening_state,
        closing_state,
        arrived_state,
        wait
    };
public:
    lift(); //конструктор лифта
    void set_log(QTextEdit* log);
    void set_labels(QLabel* doors_l, QLabel* cabin_l, QLCDNumber* table);
    void get_order(int o);

private:
    QTextEdit* log;
    QLabel* lab;
    QLCDNumber* table;
    QTimer timer_up;
    QTimer timer_down;
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
    void go_to(int o);        //топать на такой то этаж
    void reorder(); //пересчитать заказы

public slots:
    void go_up();  //топать вверх
    void go_down(); //топать вниз
    void open_doors();  //открыть двери
    void close_doors(); //закрыть двери
    void wait_here();   //ждать столько то секунд

signals:
    void opening_doors();
    void closing_doors();
    void arrived();  //приехал
    void up(); //едет вверх
    void down();  //едет вниз
};

#endif // LIFT_H
