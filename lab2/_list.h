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
    list(C* mass, int n);
    list(C data, size_t n = 1);
    explicit list(iterator_list<C>& first, iterator_list<C>& last);


    //Destructor
    virtual ~list();

    //Overload
    list<C>& operator =(const list<C>& l);
    list<C>& operator =(list<C> &&l);

    list<C>& operator +=(const list<C> &l);
    list<C>& operator +=(const C data);

    list<C>& operator +(const list<C>& l);
    list<C>& operator +(const C data);

    bool operator ==(const list<C> &l) const;
    bool operator !=(const list<C>& l) const;

    //Methods
    size_t size() const;
    virtual void clear();
    virtual bool is_empty() const;//не переопределять
    virtual size_t length() const;

    iterator_list<C>& begin();
    iterator_list<C>& end();
    const_iterator_list<C>& begin() const;
    const_iterator_list<C>& end() const;

    list<C>& append(const list<C>& l);
    list<C>& append(const C data);


    list<C>& insert_front(const list<C>& l);
    list<C>& insert_front(const C data);

    list<C>& insert_after(iterator_list<C>& iter, const C data);
    list<C>& insert_after(iterator_list<C>& iter, const list<C>& after);

    list<C>& insert_before(iterator_list<C>& iter, const C data);
    list<C>& insert_before(iterator_list<C>& iter, const list<C>& before);

    list<C>& insert_before(const_iterator_list<C>& iter, const C data);
    list<C>& insert_before(const_iterator_list<C>& iter, const list<C>& before);

    int compare(const list<C>& l);

    listItem<C>* find(const C data) const;

    void sort(bool increase=true);
    void reverse();
    C* to_array() const;

    list<C>& reset(iterator_list<C>& iter, const C data);
    listItem<C> *del(iterator_list<C>& iter);

    friend class iterator_list<C>;
    friend class const_iterator_list<C>;

protected:

    list<C>& operator +=(const listItem<C>& data);
    list<C>& operator +(const listItem<C>& data);

    list<C> &append(listItem<C> &elem);
    list<C>& insert_front(listItem<C>& elem);

    list<C>& insert_after(listItem<C>& elem, listItem<C>& after);
    list<C>& insert_after(listItem<C>& elem, const C data);
    list<C>& insert_after(listItem<C>& elem, list<C>& after);

    list<C>& insert_before(listItem<C>& elem, listItem<C>& before);
    list<C>& insert_before(listItem<C>& elem, const C data);
    list<C>& insert_before(listItem<C>& elem, list<C>& before);

    listItem<C> *find(const listItem<C>& elem) const;
    list<C>& reset(listItem<C>& elem, listItem<C>& temp);
    listItem<C> *del(const listItem<C>& elem);

    list<C>& reset(listItem<C>& elem,C data);

private:
    listItem<C>* head;
    listItem<C>* tail;
};


#endif // _LIST_H
