#include "lift.h"
#include "errors.h"
#include <QString>
#include <stdio.h>

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
    this->log->append("Лифт ");
    this->st = state;
    QString s;

    switch (state) {
    case going_up:
        s = "поднимается вверх...";
        this->lab->setText("Поднимается наверх");
        break;
    case going_down:
        s = "опускается вниз....";
        this->lab->setText("Опускается вниз");
        break;
    case opening_state:
        s = "открывает двери...";
        this->lab->setText("Открывает двери");
        break;
    case closing_state:
        s = "закрывает двери...";
        this->lab->setText("Закрывает двери");
        break;
    case arrived_state:
        s = "прибыл на место назначения...";
        this->lab->setText("На месте назначения");
        break;
    case wait:
        s = "перешел на ждущий режим...";
        this->lab->setText("Ждущий режим");
        break;
    default:
        s = "изменил свое сотояние на неизвестное!..";
        this->lab->setText("Неизвестное");
        break;
    }

    this->log->insertPlainText(s);
}


void lift::wait_here()
{
    this->set_state(opening_state);
    this->set_state(wait);
    this->orders->remove(this->floor);
    this->queue->dequeue();
}


void lift::to_first_floor()
{
    //this->set_state(wait);
}

void lift::go_up()
{
    emit this->close_doors();
    this->set_state(closing_state);
    this->set_state(going_up);
    this->floor++;

    if(this->floor > this->max_floor)
        throw rangeError();
    if (this->queue->head() == this->floor)
    {
        emit this->arrived();
        emit this->open_doors();
        this->set_state(opening_state);

        this->queue->dequeue();
        this->orders->remove(this->floor);


        if(this->orders->isEmpty())
        {
            this->set_state(wait);
        }
        else
        {
            emit this->close_doors();
            this->set_state(closing_state);
            this->go_to(this->queue->head());
        }

    }
    else
    {
        if(this->floor <= this->max_floor)
            emit this->up();
        else
            emit this->down();
    }

}

void lift::go_down()
{
    emit this->close_doors();
    this->set_state(closing_state);
    this->set_state(going_down);
    this->floor--;

    if(this->floor < this->min_floor)
        throw rangeError();
    if (this->queue->head() == this->floor)
    {
        emit this->arrived();
        emit this->open_doors();
        this->set_state(opening_state);

        this->queue->dequeue();
        this->orders->remove(this->floor);


        if(this->orders->isEmpty())
        {
            this->wait_here();
        }
        else
        {
            emit this->close_doors();
            this->set_state(closing_state);
            this->go_to(this->queue->head());
        }
    }
    else
    {
        if(this->floor >= this->min_floor)
            emit this->down();
        else
            emit this->up();
    }
}

void lift::reorder()
{
    QSet<int>* new_set = new QSet<int>;
    for(QSet<int>::iterator it = this->orders->begin(); it != this->orders->end(); it++)
    {
        new_set->insert(*it);
    }

    while(!this->orders->isEmpty())
    {
        int opt = this->opti_order();
        this->orders->remove(opt);
        this->queue->enqueue(opt);
    }

    this->orders = new_set;
    this->go_to(this->queue->head());


}


void lift::set_log(QTextEdit* log)
{
    this->log =log;
}


int lift::opti_order()
{
    int diff = this->max_floor;
    int opti = this->floor;

    for(QSet<int>::iterator it = this->orders->begin(); it != this->orders->end(); it++)
    {
        if (abs(*it - this->floor) < diff)
        {
            diff = *it - this->floor;
            opti = *it;
        }

    }

    return opti;
}


void lift::go_to(int o)
{
    if (!(this->min_floor < o < this->max_floor))
        throw rangeError();

    if (o < this->floor)
        emit this->down();
    else if (o > this->floor)
        emit this->up();
    else
        this->wait_here();

}


void lift::set_labels(QLabel* doors_l, QLabel* cabin_l)
{
    this->door->set_label(doors_l);
    this->lab = cabin_l;
    this->set_state(wait);

}
