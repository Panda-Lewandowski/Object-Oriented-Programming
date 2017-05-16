#ifndef _LIST_H
#define _LIST_H
#include <cstddef>
#include <iostream>
#include "_errors.h"
#include "_iteratorlist.h"
#include "_listitem.h"
#include  "base.hpp"


template <typename C> class iterator_list;
template <typename C> class const_iterator_list;
template <typename  C> class listItem;


template <typename C>
class list : public baseContainer
{
public:
    //Constructors
    list();
    explicit list(const list<C> &l);
    list(list<C> &&l);
    list(const C* mass, int n);
    explicit list(const C& data, size_t n = 1);
    list(iterator_list<C>& first, iterator_list<C>& last);


    //Destructor
    virtual ~list();

    //Overload
    list<C>& operator =(const list<C>& l);
    list<C>& operator =(list<C>&& l);

    list<C>& operator +=(const list<C>& l);
    list<C>& operator +=(const C data);
    list<C> operator +(const list<C>& l);
    list<C> operator +(const C data);
    list<C>& append(const list<C>& l);
    list<C>& append(C data);

    bool operator ==(const list<C>& l) const;
    bool operator !=(const list<C>& l) const;

    //Methods
    virtual void clear();
    virtual bool is_empty() const;
    virtual size_t length() const;

    iterator_list<C> begin();
    iterator_list<C> end();
    const_iterator_list<C> begin() const;
    const_iterator_list<C> end() const;

    list<C>& add_to_head(const C& data);
    list<C>& del_head();
    list<C>& add_to_tail(const C& data);
    list<C>& insert_after(iterator_list<C>& iter, const C& data);
    list<C>& insert_after(iterator_list<C>& iter, const list<C>& after);

    int compare(const list<C>& l);

//    void sort(bool increase=true);
//    void reverse();
    C* to_array() const;

//    list<C>& reset(iterator_list<C>& iter, const C data);
    C del(iterator_list<C>& iter);

    friend class iterator_list<C>;
    friend class const_iterator_list<C>;

protected:

    list<C>& operator +=(const listItem<C>& data);
    list<C>& operator +(const listItem<C>& data);
    list<C>& append(listItem<C>& elem);

    list<C>& insert_front(listItem<C>& elem);
    list<C>& insert_after(listItem<C>& elem, listItem<C>& after);
    list<C>& insert_after(listItem<C>& elem, const C& data);
    list<C>& insert_after(listItem<C>& elem, list<C>& after);

    listItem<C>& find(const C& data) const;
    listItem<C>& find(const listItem<C>& elem) const;
    list<C>& reset(listItem<C>& elem, listItem<C>& temp);
    C  del(const listItem<C>& elem);
    //list<C>& reset(listItem<C>& elem,C data);

private:
    listItem<C>* head;
    listItem<C>* tail;
};


#endif // _LIST_H
