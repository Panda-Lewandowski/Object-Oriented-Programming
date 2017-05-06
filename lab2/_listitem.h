#ifndef _LISTITEM_H
#define _LISTITEM_H
#include <iostream>
#include "_list.h"
#include "_iteratorlist.h"
#include "_errors.h"

template <typename  C> class list;
template <typename C> class iterator_list;

template <typename C>
class listItem
{
private:
    listItem* next;
    C data;
public:

    listItem();
    listItem(C data);
    explicit listItem(listItem<C>& elem);
    ~listItem();

    void set_next(listItem<C>& elem);
    void destroy_next();
    C get_data() const;
    void set(C data);

    list<C>& operator +(list<C> &l);

    bool operator ==(const listItem<C>& elem) const;
    bool operator >=(const listItem<C>& l) const;
    bool operator <=(const listItem<C>& l) const;
    bool operator !=(const listItem<C>& l) const;
    bool operator >(const listItem<C>& l) const;
    bool operator <(const listItem<C>& l) const;

    friend class list<C>;
    friend class iterator_list<C>;
};

#endif // _LISTITEM_H
