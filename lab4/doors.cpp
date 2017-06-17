#include "doors.h"
#include "errors.h"
#include "delay.h"

doors::doors()
{
    this->st = closed_state;
    connect(this, SIGNAL(opening()), this, SLOT(start_open()));
    connect(this, SIGNAL(closing()), this, SLOT(start_close()));

}

void doors::set_state(doors_state state)
{
    this->st = state;
    if(state == opened_state)
        this->lab->setText("Открыты");
    else if(state == closed_state)
        this->lab->setText("Закрыты");
    else if(state == closing_state)
        this->lab->setText("Закрываются");
    else if(state == opening_state)
        this->lab->setText("Открываются");
}


void doors::open()
{
    if(this->st == opened_state)
        return;

    this->set_state(opened_state);
}

void doors::close()
{
    if(this->st == closed_state)
        return;


    this->set_state(closed_state);
}


void doors::start_open()
{
    if(this->st == opening_state)
        return;

    this->set_state(opening_state);
    delay(200);
    this->open();
}

void doors::start_close()
{
    if(this->st == closing_state)
        return;


    this->set_state(closing_state);
    delay(200);
    this->close();
}



void doors::set_label(QLabel* l)
{
    this->lab = l;
    this->set_state(closed_state);
}


bool doors::is_open()
{
    return this->st == opened_state;
}
