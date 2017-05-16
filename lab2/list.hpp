#ifndef LIST_H
#define LIST_H
#include "_list.h"
#include <stdlib.h>
#include <assert.h>
//#include <iostream>
//#define DEBUG

namespace compfunc {

//функция для сортировки по возрастанию
template <typename T>
int comp_inc (const void * a, const void * b)
{
  return ( *(T*)a - *(T*)b );
}

//функция для сортировки по убыванию
template <typename T>
int comp_dec (const void * a, const void * b)
{
  return ( *(T*)b - *(T*)a );
}
}

template <typename C>
list<C>::list()
{
     this->head = nullptr;
     this->tail = nullptr;
}

template <typename C>
list<C>::list(const list<C> &l)
{
    if(!l.head)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        listItem<C>* cur;
        listItem<C>* head = new listItem<C>;
        if(!head)
            throw memError();
        head->set(l.head->get_data());
        this->head = head;
        listItem<C>* tmp = head;
        cur = l.head->next;

        for(; cur; cur = cur->next)
        {
            listItem<C>* item = new listItem<C>;
            if(!item)
                throw memError();
            tmp->set_next(*item);
            item->set(cur->get_data());
            this->tail = item;
            tmp = tmp->next;
        }
    }


}

template <typename C>
list<C>::list(list<C> &&l)
{
    this->head = l.head;
    this->tail = l.tail;
}


template <typename C>
list<C>::list(const C *mass, int n)
{
    assert(n >= 0);
    if(mass == nullptr || n == 0)
        this->head = nullptr;
    else
    {
        listItem<C>* head = new listItem<C>;
        if(!head)
            throw memError();
        this->head = head;
        this->head->set(mass[0]);
        listItem<C>* cur = head;

        for(int i = 1; i < n; i++)
        {
            listItem<C>* item = new listItem<C>;
            if(!item)
                throw memError();

            item->set(mass[i]);
            cur->set_next(*item);
            cur = item;
        }
        this->tail = cur;
    }

}

template <typename C>
list<C>::list(const C& data, size_t n)
{
    assert(n >= 0);
    if(n == 0)
        this->head = nullptr;
    else
    {
        listItem<C>* head = new listItem<C>;
        if(!head)
            throw memError();
        head->set(data);
        this->head = head;
        listItem<C>* cur = head;
        for(size_t i = 0; i < n - 1; i++)
        {
            listItem<C>* item = new listItem<C>;
            if(!item)
                throw memError();
            item->set(data);
            cur->set_next(*item);
            cur = item;
        }
        this->tail = cur;
    }
}

template <typename C>
list<C>::list(iterator_list<C> &first, iterator_list<C> & last)
{
    if(!first.inRange() || !last.inRange())
        throw rangeError();

    iterator_list<C> f(first);
    listItem<C>* head = new listItem<C>;
    if(!head)
        throw memError();
    head->set(f.current());
    this->head = head;
    f++;
    listItem<C>* cur = head;

    for(;f != last; f++)
    {
        listItem<C>* item = new listItem<C>;
        if(!item)
            throw memError();
        item->set(f.current());
        cur->set_next(*item);
        cur = item;
    }
    this->tail = cur;
}

template <typename C>
list<C>::~list()
{

#ifdef DEBUG
    std::cout << "Деструктор класса List!\n";
#endif
    if(this->head)
    {
        listItem<C>* next;
        for(; this->head; this->head = next)
        {
            next = this->head->next;
            delete this->head;

        }
    }

    this->head = nullptr;
    this->tail = nullptr;
}

template <typename C>
list<C>& list<C>::operator =(const list<C>& l)
{
    if(this->length() <= l.length())
    {
        listItem<C>* curl = l.head;
        listItem<C>* curt = this->head;
        for(; curt; curt = curt->next)
        {
            curt->set(curl->get_data());
            curl = curl->next;
        }

    }
    else
    {
        listItem<C>* curl = l.head;
        listItem<C>* curt = this->head;
        for(; curt; curt = curt->next)
        {

            if(curl)
            {
                curt->set(curl->get_data());
                this->tail = curl;
                curl = curl->next;
            }
            else
            {
                this->del(*curt);
            }
        }

    }

    return *this;

}

template <typename C>
list<C>& list<C>::operator =(list<C> &&l)
{
    this->head = l.head;
    this->tail = l.tail;
    return *this;

}

template <typename C>
list<C>& list<C>::operator +=(const list<C>& l)
{
    this->append(l);
    return *this;

}

template <typename C>
list<C> &list<C>::operator +=(const listItem<C> &data)
{
    this->append(data);
    return *this;
}

template <typename C>
list<C> &list<C>::operator +=(const C data)
{
    this->append(data);
    return *this;
}


template <typename C>
list<C> list<C>::operator +(const list<C>& l)
{
    list<C> new_l(this);
    new_l->append(l);
    return new_l;

}

template <typename C>
list<C>& list<C>::operator +(const listItem<C>& data)
{
    this->append(data);
    return *this;

}

template <typename C>
list<C> list<C>::operator +(const C data)
{
    list<C> new_l(this);
    new_l->append(data);
    return new_l;
}


template <typename C>
bool list<C>::operator ==(const list<C>& l) const
{
    listItem<C>* curt = this->head;
    listItem<C>* curl = l.head;
    while (curt && curl && curt->data == curl->data)
    {
        curt = curt->next;
        curl = curl->next;
    }

    if(curt == nullptr && curl == nullptr)
        return true;
    else
        return false;

}


template <typename C>
bool list<C>::operator !=(const list<C>& l) const
{
    return !(*this == l);

}


template <typename C>
void list<C>::clear()
{
    listItem<C>* cur = this->head;
    for(; cur; cur = cur->next)
    {
        cur->set(0);
    }

}

template <typename C>
bool list<C>::is_empty() const
{
    return (this->head == nullptr);
}

template <typename C>
size_t list<C>::length() const
{
    listItem<C>* cur = this->head;
    size_t s = 0;
    for(; cur; cur = cur->next)
    {
        s++;
    }

    return s;
}


template <typename C>
iterator_list<C> list<C>::begin()
{
    iterator_list<C> it(*this);
    it._current = this->head;

    return it;

}

template <typename C>
iterator_list<C> list<C>::end()
{
    iterator_list<C> it(*this);
    it.last();


    return it;

}

template <typename C>
const_iterator_list<C> list<C>::begin() const
{
    const_iterator_list<C> it(*this);
    it.first();

    return it;

}

template <typename C>
const_iterator_list<C> list<C>::end() const
{
    const_iterator_list<C> it(*this);
    it.last();


    return it;

}

template <typename C>
list<C>& list<C>::append(const list<C>& l)
{
    if(!this->head)
    {
        *this = l;
        return *this;
    }

    listItem<C>* tmp = l.head;
    for(;tmp;tmp = tmp->next)
    {
        listItem<C>* item = new listItem<C>;
        if(!item)
            throw memError();
        item->set(tmp->get_data());
        this->append(*item);
    }

    return *this;
}

template <typename C>
list<C>& list<C>::append(C data)
{
    listItem<C>* n = new listItem<C>;
    if(!n)
        throw memError();
    n->set(data);
    this->append(*n);
    return *this;

}


template <typename C>
list<C>& list<C>::append(listItem<C>& elem)
{
    if(!this->head)
    {
        listItem<C>* head = new listItem<C>;
        if(!head)
            throw memError();
        head->data = elem.data;
        this->head = head;
        this->tail = head;
        return *this;
    }

    listItem<C>* cur = this->tail;
    listItem<C>* new_item = new listItem<C>;
    if(!new_item)
        throw memError();
    new_item->data = elem.data;
    cur->set_next(*new_item);
    this->tail = new_item;
    return *this;

}



template <typename C>
list<C> &list<C>::add_to_head(const C &data)
{
    listItem<C>* new_head = new listItem<C>;
    if(!new_head)
        throw memError();
    new_head->set(data);
    this->insert_front(*new_head);
    return *this;

}

template <typename C>
list<C>& list<C>::del_head()
{
    this->head = this->head->next;

    return *this;

}

template <typename C>
list<C>& list<C>::add_to_tail(const C& data)
{
    this->append(data);
    return *this;

}


template <typename C>
list<C>& list<C>::insert_front(listItem<C>& elem)
{
    if(!this->head)
    {
        this->append(elem);
        return *this;
    }

    listItem<C>* new_head = new listItem<C>;
    if(!new_head)
        throw memError();
    new_head->set(elem.data);
    new_head->set_next(*this->head);
    this->head = new_head;
    return *this;

}

template <typename C>
int list<C>::compare(const list<C>& l)
{
    if (*this == l)
        return 0;
    else
    {
        if(this->length() > l.length())
            return 1;
        else
            return -1;
    }
}

template <typename C>
list<C> &list<C>::insert_after(listItem<C>& after, const C& data)
{
    listItem<C>* f = this->find(after);
    listItem<C>* tmp = f->get_next();
    listItem<C>* item = new listItem<C>;
    if(!item)
        throw memError();
    item->set(data);
    f->set_next(*item);
    item->set_next(*tmp);
    if(f == this->tail)
        this->tail = item;
    return *this;

}

template <typename C>
list<C>& list<C>::insert_after(listItem<C>& after, list<C>&  l)
{
    listItem<C>* f = this->find(after);
    listItem<C>* buf = f->get_next();
    listItem<C>* cur;
    listItem<C>* head = new listItem<C>;
    if(!head)
        throw memError();
    head->set(l.head->get_data());

    listItem<C>* tmp = head;
    cur = l.head->get_next();

    for(; cur; cur = cur->get_next())
    {
        listItem<C>* item = new listItem<C>;
        if(!item)
            throw memError();
        tmp->set_next(*item);
        item->set(cur->get_data());
        item->set_next(*buf);
        if(f == this->tail)
            this->tail = item;
        tmp = tmp->get_next();
    }
    f->set_next(*head);

    return *this;


}

template <typename C>
list<C>& list<C>::insert_after(listItem<C>& after, listItem<C>& elem)
{
    listItem<C>* f = &(this->find(after));
    listItem<C>* tmp = f->next;
    listItem<C>* item = new listItem<C>;
    if(!item)
        throw memError();
    item->set(elem.get_data());
    f->set_next(*item);
    item->set_next(*tmp);
    if(f == this->tail)
        this->tail = item;
    return *this;

}


template <typename C>
list<C> &list<C>::insert_after(iterator_list<C>& iter, const C& data)
{
    listItem<C>* f = &(this->find(*iter));
    listItem<C>* item = new listItem<C>;
    if(!item)
        throw memError();
    item->set(data);
    this->insert_after(*f, *item);
    return *this;
}


template <typename C>
list<C> &list<C>::insert_after(iterator_list<C>& iter, const list<C> &l)
{
    listItem<C>* f = &(this->find(*iter));
    listItem<C>* buf = f->next;
    listItem<C>* cur;
    listItem<C>* head = new listItem<C>;
    if(!head)
        throw memError();
    head->set(l.head->get_data());

    listItem<C>* tmp = head;
    cur = l.head->next;

    for(; cur; cur = cur->next)
    {
        listItem<C>* item = new listItem<C>;
        if(!item)
            throw memError();
        tmp->set_next(*item);
        item->set(cur->get_data());
        item->set_next(*buf);
        if(f == this->tail)
            this->tail = item;
        tmp = tmp->next;
    }
    f->set_next(*head);

    return *this;
}

template <typename C>
C* list<C>::to_array() const
{
     C* arr = new C[this->length()];
     if(!arr)
         throw memError();
     listItem<C>* tmp = this->head;
     for(size_t i  = 0;  i < this->length(); i++)
     {
         arr[i] = tmp->get_data();
         tmp = tmp->next;
     }

     return arr;
}


template <typename C>
list<C>& list<C>::reset(listItem<C>& elem, listItem<C>& temp)
{
    listItem<C>* f = this->find(elem);
    f->set(temp.get_data());
    return *this;

}


template <typename C>
C  list<C>::del(const listItem<C> &elem)
{
    if(!this->head)
        throw emptyError();
    listItem<C>* f = &(this->find(elem));


    listItem<C>* cur = this->head;
    if(cur->get_data() == elem.get_data())
    {
        this->head = this->head->next;
        return cur->get_data();
    }
    for(;cur && cur->next != f; cur = cur->next);
    if(cur == nullptr)
        return -1;
    cur->set_next(*f->next);

    if(f == this->tail)
    {
        listItem<C>* tmp = this->head;
        for(; tmp->next; tmp = tmp->next);
        this->tail = tmp;
    }
    return f->get_data();

}

template <typename C>
C list<C>::del(iterator_list<C>& iter)
{
    if(!this->head)
        throw emptyError();
    if(!*iter == this->tail)
        throw rangeError();

    listItem<C>* f = this->find(*iter);

    f = f->get_next();

    this->del(f);

    return f->get_data();

}


template <typename C>
std::ostream& operator<<(std::ostream& os, list<C>& l)
 {
    os << "List: ";
    iterator_list<C> i(l);
    if (!i.inRange())
    {
        os << "empty";
        return os;
    }
    i = l.begin();
    for (; i.inRange(); i++)
    {
        os << i.current() << " ";

    }
    os << "\n";
    return os;

 }


#endif // LIST_H
