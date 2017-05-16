#ifndef _ITERATORLIST_H
#define _ITERATORLIST_H

#include "_errors.h"
#include "_list.h"
#include "_listitem.h"

template <typename C> class list;
template <typename C> class listItem;

template <typename C>
class iteratorBase
{
public:
    virtual void next()              = 0;
    virtual bool inRange()           = 0;
protected:
   C* _current;
};


template <class C>
class iterator_list : public iteratorBase< listItem<C> >
{
public:
    iterator_list(const list<C>& l);
    iterator_list(const iterator_list<C>& it);
    ~iterator_list();

    void next();
    bool inRange();
    const C current();

    iterator_list<C>& operator =(const iterator_list<C>& it);


    const C &operator *();
    C* operator ->();

    iterator_list<C>& operator +=(size_t n);
    iterator_list<C>& operator ++();
    iterator_list<C> operator ++(int);
    iterator_list<C> operator +(size_t n) const;

    bool operator != (const iterator_list<C>& it) const;
    bool operator == (const iterator_list<C>& it) const;

    friend class list<C>;

};


template <class C>
class const_iterator_list : public iteratorBase< listItem<C> >
{
public:
    const_iterator_list(const list<C>& l);
    const_iterator_list(const const_iterator_list<C>& it);
    ~const_iterator_list();

    void next();
    bool inRange();
    const C& current() const;

    const C& operator *() const;
    const C* operator ->() const;

    bool operator != (const const_iterator_list<C>& it) const;
    bool operator == (const const_iterator_list<C>& it) const;

private:
    const list<C>* _list;
};
#endif // _ITERATORLIST_H
