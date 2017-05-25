#include "doors.h"
#include "errors.h"

doors::doors()
{
    this->st = closed_state;
    connect(this, SIGNAL(open()), this, SLOT(opening()));
    connect(this, SIGNAL(close()), this, SLOT(closing()));

}

void doors::set_state(doors_state state)
{
    this->st = state;
    if(state == opened_state)
        this->lab->setText("Открыты");
    else if(state == closed_state)
        this->lab->setText("Закрыты");
}


void doors::opening()
{
    if(this->st == opened_state)
        return;

    this->set_state(opened_state);
}

void doors::closing()
{
    if(this->st == closed_state)
        return;

    this->set_state(closed_state);
}


void doors::set_label(QLabel* l)
{
    this->lab = l;
    this->set_state(closed_state);
}
