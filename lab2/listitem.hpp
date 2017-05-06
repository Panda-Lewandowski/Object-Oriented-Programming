#ifndef LISTITEM_H
#define LISTITEM_H
#include "_listitem.h"
//#define DEBUG

template <typename C>
listItem<C>::listItem()
{
    this->next = nullptr;
}

template <typename C>
listItem<C>::listItem(C data)
{
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
void listItem<C>::destroy_next()
{
    this->next = nullptr;
}


template <typename C>
C listItem<C>::get_data() const
{
    return this->data;
}

template <typename C>
void listItem<C>::set(C data)
{
    this->data = data;
}

template <typename C>
list<C>& listItem<C>::operator +(list<C>& l)
{
    l.insert_front(*this);
    return l;

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
    os << "listItem with data: " << elem.get_data() << "\n";
    os << "Next item at "<< elem.get_next();
    if (elem.get_next() != nullptr)
        os << " with data: "<< elem.get_next()->get_data() << "\n";
    else
        os << "\n";
    return os;
}

#endif // LISTITEM_H
