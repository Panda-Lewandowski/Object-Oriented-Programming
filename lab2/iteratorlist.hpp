#ifndef ITERATORLIST_H
#define ITERATORLIST_H
#include "_iteratorlist.h"

template <typename C>
iterator_list<C>::iterator_list(const list<C>& l)
{
    this->_list = &l;
    this->_current = l.head;
}

template <typename C>
iterator_list<C>::iterator_list(const iterator_list<C>& it)
{
    this->_list = it._list;
    this->_current = it._current;
}

template <typename C>
iterator_list<C>::~iterator_list()
{
    this->_list = nullptr;
    this->_current = nullptr;
}

template <typename C>
iterator_list<C>& iterator_list<C>::operator =(const iterator_list<C>& it)
{
    this->_list = it._list;
    this->_current = it._current;
    return *this;
}

template <typename C>
void iterator_list<C>::first()
{
    this->_current = this->_list->head;
}

template <typename C>
void iterator_list<C>::last()
{
    this->_current = this->_list->tail;
}

template <typename C>
void iterator_list<C>::next()
{
    if(!this->inRange())
       throw rangeError();

    this->_current = this->_current->next;
}

template <typename C>
bool iterator_list<C>::inRange()
{
    return !(this->_current == nullptr);
}


template <typename C>
iterator_list<C>& iterator_list<C>::operator ++()
{
    if (!this->inRange())
        throw rangeError();
    this->next();

    return *this;
}

template <typename C>
iterator_list<C> iterator_list<C>::operator ++(int)
{
    if (!this->inRange())
        throw rangeError();

    iterator_list<C> r(*this);
    this->next();

    return r;
}


template <typename C>
const C iterator_list<C>::current()
{
    if(!this->inRange())
        throw emptyError();

    return this->_current->get_data();
}

template <typename C>
listItem<C> &iterator_list<C>::operator *()
{
    return *this->_current;
}

template <typename C>
listItem<C>* iterator_list<C>::operator ->()
{
    return this->_current;
}

template <typename C>
iterator_list<C>& iterator_list<C>::operator +=(size_t n)
{
    while(n--)
    {
        //if(!this->inRange())
            //throw rangeError();
        this->_current = this->_current->next;
    }

    return *this;
}

template <typename C>
iterator_list<C> iterator_list<C>::operator +(size_t n) const
{
    iterator_list<C> it(*this);

    it += n;

    return it;
}


template <typename C>
bool iterator_list<C>::operator != (const iterator_list<C>& it) const
{
    if (this->_list != it._list)
        throw  cmpIterError();

    return this->_current != it._current;
}

template <typename C>
bool iterator_list<C>::operator == (const iterator_list<C>& it) const
{
    if (this->_list != it._list)
       throw  cmpIterError();

    return this->_current == it._current;
}

template <typename C>
bool iterator_list<C>::operator < (const iterator_list<C>& it) const
{
    if (this->_list != it._list)
       throw  cmpIterError();

    return this->_current < it._current;
}

template <typename C>
bool iterator_list<C>::operator > (const iterator_list<C>& it) const
{
    if (this->_list != it._list)
        throw  cmpIterError();

    return this->_current > it._current;
}

template <typename C>
bool iterator_list<C>::operator <= (const iterator_list<C>& it) const
{
    if (this->_list != it._list)
        throw  cmpIterError();

    return this->_current <= it._current;
}

template <typename C>
bool iterator_list<C>::operator >= (const iterator_list<C>& it) const
{
    if (this->_list != it._list)
       throw  cmpIterError();

    return this->_current >= it._current;
}

//––––––––––––––––––––––––––––––––––––––––

template <typename C>
const_iterator_list<C>::const_iterator_list(const list<C>& l)
{
    this->_list = &l;
    this->_current = l.head;
}

template <typename C>
const_iterator_list<C>::const_iterator_list(const const_iterator_list<C>& it)
{
    this->_list = it._list;
    this->_current = it._current;
}

template <typename C>
const_iterator_list<C>::~const_iterator_list()
{
    this->_list = nullptr;
    this->_current = nullptr;
}


template <typename C>
void const_iterator_list<C>::first()
{
    this->_current = this->_list->get_head();
}

template <typename C>
void const_iterator_list<C>::last()
{
    if(this->_list->get_head() == nullptr)
        throw emptyError();

    this->_current = this->_list->get_tail();
}

template <typename C>
void const_iterator_list<C>::next()
{
    if(!this->inRange())
       throw rangeError();

    this->_current = this->_current->get_next();
}

template <typename C>
bool const_iterator_list<C>::inRange()
{
    return this->_current == nullptr;
}


template <typename C>
const C& const_iterator_list<C>::current() const
{
    if(!this->inRange())
        throw emptyError();

    return this->_current->get_data();
}

template <typename C>
const listItem<C> &const_iterator_list<C>::operator *()
{
    return *this->_current;
}

template <typename C>
const listItem<C>* const_iterator_list<C>::operator ->()
{
    return this->_current;
}


template <typename C>
bool const_iterator_list<C>::operator != (const const_iterator_list<C>& it) const
{
    if (this->_list != it._list)
        throw  cmpIterError();

    return this->_current != it._current;
}

template <typename C>
bool const_iterator_list<C>::operator == (const const_iterator_list<C>& it) const
{
    if (this->_list != it._list)
       throw  cmpIterError();

    return this->_current == it._current;
}

template <typename C>
bool const_iterator_list<C>::operator < (const const_iterator_list<C>& it) const
{
    if (this->_list != it._list)
       throw  cmpIterError();

    return this->_current < it._current;
}

template <typename C>
bool const_iterator_list<C>::operator > (const const_iterator_list<C>& it) const
{
    if (this->_list != it._list)
        throw  cmpIterError();

    return this->_current > it._current;
}

template <typename C>
bool const_iterator_list<C>::operator <= (const const_iterator_list<C>& it) const
{
    if (this->_list != it._list)
        throw  cmpIterError();

    return this->_current <= it._current;
}

template <typename C>
bool const_iterator_list<C>::operator >= (const const_iterator_list<C>& it) const
{
    if (this->_list != it._list)
       throw  cmpIterError();

    return this->_current >= it._current;
}

#endif // ITERATORLIST_H
