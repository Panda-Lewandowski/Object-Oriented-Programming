#ifndef _LIST_H
#define _LIST_H

#include "errors.h"
#include "iteratorlist.h"
#include "listitem.h"
#include "list.h"
#include <cstddef>
#include <iostream>

template <typename C> class iterator_list;
template <typename  C> class listItem;

template <typename C>
class list
{
protected:
    listItem<C>* head;
public:
    //Constructors
    list();
    list(const list<C> &l);
    list(list<C> &&l);
    list(size_t n);
    list(C* mass);
    list(listItem<C> data, size_t n = 1);
    list(const list<C> &l, size_t pos = 0, size_t n = 1);


    //Destructor
    ~list();

    //Overload
    list<C>& operator =(const list<C>& l);
    list<C>& operator =(list<C> &&l);

    listItem<C>& operator [](size_t pos);
    const listItem<C>& operator [](size_t pos) const;

    list<C>& operator +=(const list<C> &l);
    list<C>& operator +=(const listItem<C>& data);

    list<C>& operator +(const list<C>& l);
    list<C>& operator +(const listItem<C>& data);

    bool operator ==(const list<C>& l) const;
    bool operator >=(const list<C>& l) const;
    bool operator <=(const list<C>& l) const;
    bool operator !=(const list<C>& l) const;
    bool operator >(const list<C>& l) const;
    bool operator <(const list<C>& l) const;

    //Methods
    size_t size() const;
    void clear();
    bool is_empty() const;
    size_t length() const;

    listItem<C>& at(size_t pos) const;
    listItem<C>& begin() const;
    listItem<C>& end() const;
    iterator_list<C>& begin();
    iterator_list<C>& end();

    list<C>& append(const list<C>& l);
    list<C>& append(const C& data);

    int compare(const list<C>& l);

    list<C>& insert(size_t pos, list<C>& l);
    list<C>& insert(size_t pos, listItem<C>& elem);

    listItem<C>& find(listItem<C>& elem) const;
    size_t index(listItem<C>& elem) const;

    void sort(bool increase=true);
    void reverse();

    list<C>& replace(size_t pos, listItem<C>& elem);
    list<C>& replace(listItem<C>& elem, listItem<C>& temp);

    listItem<C>& del(listItem<C>& elem);
    listItem<C>& del(size_t pos);

     friend std::ostream& operator<<(std::ostream& os, list<C>& l);
     friend std::istream& operator>>(std::istream& os, list<C>& l);



};

#endif // _LIST_H
