#ifndef _LIST_H
#define _LIST_H
#include <cstddef>
#include <iostream>
#include "_errors.h"
#include "_iteratorlist.h"
#include "_listitem.h"
#include  "base.hpp"


template <typename C> class iterator_list;
template <typename  C> class listItem;


template <typename C>
class list : public baseContainer
{
protected:
    listItem<C>* head;
    listItem<C>* tail;

    list<C>& operator +=(const listItem<C>& data);
    list<C>& operator +(const listItem<C>& data);
    list<C>& operator -(const listItem<C>& data);
    list<C>& operator -=(const listItem<C> &data);

    list<C>& append(const listItem<C>& elem);
    list<C>& insert_front(const listItem<C>& elem);

    list<C>& insert_after(listItem<C>& elem, listItem<C>& after);
    list<C>& insert_after(listItem<C>& elem, C data);
    list<C>& insert_after(listItem<C>& elem, list<C>& after);

    list<C>& insert_before(listItem<C>& elem, listItem<C>& before);
    list<C>& insert_before(listItem<C>& elem, C data);
    list<C>& insert_before(listItem<C>& elem, list<C>& before);

    listItem<C> *find(const listItem<C>& elem) const;
    list<C>& replace(listItem<C>& elem, listItem<C>& temp);
    listItem<C> *del(const listItem<C>& elem);

    list<C>& replace(listItem<C>& elem,C data);
public:

    //Constructors
    list();
    explicit list(const list<C> &l);
    list(list<C> &&l);
    list(size_t n);
    list(C* mass, int n);
    list(C data, size_t n = 1);
    explicit list(const list<C> &l, size_t n);//через итератор


    //Destructor
    ~list();

    //Overload
    list<C>& operator =(const list<C>& l);
    list<C>& operator =(list<C> &&l);

    list<C>& operator +=(const list<C> &l);
    list<C>& operator +=(const C data);
    list<C>& operator -=(const C data);

    list<C>& operator +(const list<C>& l);

    list<C>& operator +(const C data);
    list<C>& operator -(const C data);

    bool operator ==(const list<C> &l) const;
    bool operator !=(const list<C>& l) const;




    //Methods
    size_t size() const;
    void clear();
    bool is_empty() const;
    size_t length() const;
    listItem<C>* get_head() const;
    listItem<C>* get_tail() const;

    iterator_list<C>& begin() const;
    iterator_list<C>& end() const;

    list<C>& append(const list<C>& l);
    list<C>& append(const C data);


    list<C>& insert_front(const list<C>& l);
    list<C>& insert_front(const C data);

    list<C>& insert_after(iterator_list<C>& iter, C data);
    list<C>& insert_after(iterator_list<C>& iter, list<C>& after);

    list<C>& insert_before(iterator_list<C>& iter, C data);
    list<C>& insert_before(iterator_list<C>& iter, list<C>& before);

    int compare(const list<C>& l);

    listItem<C>* find(const C data) const;

    void sort(bool increase=true);
    void reverse();
    C* to_array() const;

    list<C>& replace(iterator_list<C>& iter,C data);
    listItem<C> *del(const C data);

    //friend std::ostream& operator<<(std::ostream& os, list<C>& l);

};

#endif // _LIST_H
