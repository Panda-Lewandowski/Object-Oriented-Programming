#include "lift.h"
#include "errors.h"
#include <QString>

lift::lift()
{
    this->log = nullptr;
    this->min_floor = 1;
    this->max_floor = 5;
    this->floor = 1;
    this->door = new doors;
    this->st = wait;
    this->is_empty = true;
    this->orders = new QSet<int>;
    this->queue = new QQueue<int>;
    connect(this, SIGNAL(arrived()), this->door, SLOT(opening()));
    connect(this, SIGNAL(open_doors()), this->door, SLOT(opening()));
    connect(this, SIGNAL(close_doors()), this->door, SLOT(closing()));
    connect(this, SIGNAL(up()), this, SLOT(go_up()));
    connect(this, SIGNAL(down()), this, SLOT(go_down()));
    connect(this, SIGNAL(change_st(int)), this, SLOT(reorder()));
    connect(this, SIGNAL(floor_changed(int)), this, SLOT(reorder()));

}

void lift::get_order(int o)
{
    this->orders->insert(o);
    this->reorder();
}


void lift::set_state(lift_state state)
{
    this->log->append("Лифт изменил свое состояние ");
    this->st = state;
    QString s;

    switch (state) {
    case going_up:
        s = "и поднимается вверх...";
        break;
    case going_down:
        s = "и опускается вниз....";
        break;
    case opening_state:
        s = "и открывает двери...";
        break;
    case closing_state:
        s = "и закрывает двери...";
        break;
    case arrived_state:
        s = "и прибыл на место назначения...";
        break;
    case wait:
        s = "на ждущий режим...";
        break;
    default:
        s = "на неизвестное!..";
        break;
    }

    this->log->insertPlainText(s);
}


void lift::wait_here(double)
{
    this->set_state(wait);
}


void lift::to_first_floor()
{
    //this->set_state(wait);
}

void lift::go_up()
{
     this->set_state(going_up);
    this->floor++;
    if (this->queue->head() == this->floor)
    {
        this->queue->dequeue();
        this->orders->remove(this->floor);
        if(this->orders->isEmpty())
        {
            this->set_state(wait);
        }
        else
        {
            this->go_to(this->queue->head());
        }
    }

}

void lift::go_down()
{

}

void lift::reorder()
{

}


void lift::set_log(QTextEdit* log)
{
    this->log =log;
}

int lift::opti_order()
{

}


void lift::go_to(int)
{

}
