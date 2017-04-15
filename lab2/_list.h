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
public:
    listItem<C>* head;
    //Constructors
    list();
    list(const list<C> &l);
    list(list<C> &&l);
    list(size_t n);
    list(C* mass, int n);
    list(C data, size_t n = 1);
    list(const list<C> &l, size_t n);


    //Destructor
    ~list();

    //Overload
    list<C>& operator =(const list<C>& l);
    list<C>& operator =(list<C> &&l);

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

    iterator_list<C>& at(size_t pos) const;
    iterator_list<C>& begin() const;
    iterator_list<C>& end() const;

    list<C>& append(const list<C>& l);
    list<C>& append(const C& data);

    list<C>& new_head(const list<C>& l);
    list<C>& new_head(const C& data);

    int compare(const list<C>& l);

    list<C>& insert_after(listItem<C>& elem, list<C>& l);
    list<C>& insert_after(listItem<C>& elem, listItem<C>& after);

    list<C>& insert_before(listItem<C>& elem, list<C>& l);
    list<C>& insert_before(listItem<C>& elem, listItem<C>& before);

    listItem<C>& find(listItem<C>& elem) const;
    listItem<C>& find(C data) const;

    void sort(bool increase=true);
    void reverse();

    list<C>& replace(listItem<C>& elem,C data);
    list<C>& replace(listItem<C>& elem, listItem<C>& temp);

    listItem<C>& del(listItem<C>& elem);
    listItem<C>& del(C data);

     //friend std::ostream& operator<<(std::ostream& os, list<C>& l);



};

#endif // _LIST_H
