#ifndef LISTITEM_H
#define LISTITEM_H
#include "_listitem.h"
#define DEBUG

//-----------------LISTITEM REALISATION-----------------------------
template <typename C>
listItem<C>::listItem()
{
    //this->data = new C;
    this->next = nullptr;
    //TODO обработка ошибки
}

template <typename C>
listItem<C>::listItem(C data)
{
    //this->data = new C;
    this->data = data;
    this->next = nullptr;
}

template<typename C>
listItem<C>::listItem(listItem<C> &elem)
{
    this->data = elem.data;
    this->next = elem.next;
}


template <typename C>
listItem<C>::~listItem()
{
    //delete this->data;
#ifdef DEBUG
    std::cout << "Деструктор класса ListItem!\n";
#endif
    this->next = nullptr;
}

template <typename C>
void listItem<C>::set_next(listItem<C> &elem)
{
    this->next = &elem;
}

template <typename C>
listItem<C>& listItem<C>::get_next() const
{
    return *(this->next);
}

template <typename C>
bool listItem<C>::operator ==(const listItem<C>& elem) const
{
    if(this->data == elem.data)
        return true;
    else
        return false;
}

template <typename C>
bool listItem<C>::operator >=(const listItem<C>& elem) const
{
    if(this->data >= elem.data)
        return true;
    else
        return false;
}

template <typename C>
bool listItem<C>::operator <=(const listItem<C>& elem) const
{
    if(this->data <= elem.data)
        return true;
    else
        return false;
}

template <typename C>
bool listItem<C>::operator !=(const listItem<C>& elem) const
{
    if(this->data != elem.data)
        return true;
    else
        return false;
}

template <typename C>
bool listItem<C>::operator >(const listItem<C>& elem) const
{
    if(this->data > elem.data)
        return true;
    else
        return false;
}

template <typename C>
bool listItem<C>::operator <(const listItem<C>& elem) const
{
    if(this->data < elem.data)
        return true;
    else
        return false;
}

template <typename C>
std::ostream& operator<<(std::ostream& os, listItem<C>& elem)
{
    os << "listItem with data: " << elem.data << "\n";
    os << "Next item at "<< elem.next;
    if (elem.next != nullptr)
        os << " with data: "<< elem.next->data << "\n";
    else
        os << "\n";
    return os;
}

#endif // LISTITEM_H
