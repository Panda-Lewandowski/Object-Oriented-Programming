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
    virtual void first()             = 0;
    virtual void next()              = 0;
    virtual void last()              = 0;
    virtual bool inRange()           = 0;
protected:
   C* _current;
};


template <class C>
class iterator_list : public iteratorBase< listItem<C> >
{
private:
    const list<C>* _list;
public:
    iterator_list(const list<C>& l);
    iterator_list(const iterator_list<C>& it);
    ~iterator_list();

    void first();
    void next();
    void last();
    bool inRange();
    const C& current() const;

    iterator_list<C>& operator =(const iterator_list<C>& it);

    iterator_list<C>& operator ++();
    iterator_list<C>& operator ++(int);

    listItem<C>& operator *();

    iterator_list<C>& operator +=(size_t n);

    iterator_list<C> operator +(size_t n) const;

    bool operator != (const iterator_list<C>& it) const;
    bool operator == (const iterator_list<C>& it) const;
    bool operator <  (const iterator_list<C>& it) const;
    bool operator >  (const iterator_list<C>& it) const;
    bool operator <= (const iterator_list<C>& it) const;
    bool operator >= (const iterator_list<C>& it) const;

    int difference(const iterator_list<C> &it);
};
#endif // _ITERATORLIST_H
