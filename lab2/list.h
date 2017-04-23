#ifndef LIST_H
#define LIST_H
#include "_list.h"
#include <stdlib.h>
#include <assert.h>
//#define DEBUG
//------------------LIST REALISATION---------------------------------

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
        this->head = nullptr;
    else
    {
        listItem<C>* cur;
        listItem<C>* head = new listItem<C>;
        //if(!head)
            //throw memError();
        head->set(l.head->get_data());
        this->head = head;
        listItem<C>* tmp = head;
        cur = l.head->get_next();

        for(; cur; cur = cur->get_next())
        {
            listItem<C>* item = new listItem<C>;
            //if(!item)
                //throw memError();
            tmp->set_next(*item);
            item->set(cur->get_data());
            tmp = tmp->get_next();
        }
    }


}

template <typename C>
list<C>::list(list<C> &&l)
{
    this->head = l.head;
}

template <typename C>
list<C>::list(size_t n)
{
    assert(n > 0);
    if(n == 0)
        this->head = nullptr;
    else
    {
        listItem<C>* head = new listItem<C>;
        //if(!head)
           // throw memError();
        this->head = head;
        listItem<C>* cur = head;
        for(size_t i = 0; i < n - 1; i++)
        {
            listItem<C>* item = new listItem<C>;
            //if(!item)
                //throw memError();
            cur->set_next(*item);
            cur = item;
        }
    }
}


template <typename C>
list<C>::list(C *mass, int n)
{
    assert(n > 0);
    if(mass == nullptr || n == 0)
        this->head = nullptr;
    else
    {
        listItem<C>* head = new listItem<C>;
        //if(!head)
            //throw memError();
        this->head = head;
        this->head->set(mass[0]);
        listItem<C>* cur = head;

        for(int i = 1; i < n; i++)
        {
            listItem<C>* item = new listItem<C>;
            //if(!item)
                //throw memError();
            item->set(mass[i]);
            cur->set_next(*item);
            cur = item;
        }
    }

}

template <typename C>
list<C>::list(C data, size_t n)
{
    assert(n > 0);
    if(n == 0)
        this->head = nullptr;
    else
    {
        listItem<C>* head = new listItem<C>;
        //if(!head)
            //throw memError();
        head->set(data);
        this->head = head;
        listItem<C>* cur = head;
        for(size_t i = 0; i < n - 1; i++)
        {
            listItem<C>* item = new listItem<C>;
            //if(!item)
                //throw memError();
            item->set(data);
            cur->set_next(*item);
            cur = item;
        }
    }
}

template <typename C>
list<C>::list(const list<C> &l, size_t n)
{

    assert(n > 0);
    if(!l.head || n == 0)
        this->head = nullptr;
    else
    {
        listItem<C>* cur;
        listItem<C>* head = new listItem<C>;
        //if(!head)
            //throw memError();
        head->set(l.head->get_data());
        n--;

        this->head = head;
        listItem<C>* tmp = head;
        cur = l.head->get_next();

        for(; cur && n; cur = cur->get_next())
        {
            listItem<C>* item = new listItem<C>;
            //if(!item)
                //throw memError();
            tmp->set_next(*item);
            item->set(cur->get_data());
            tmp = tmp->get_next();
            n--;
        }
    }
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
            next = this->head->get_next();
            delete this->head;

        }
    }

    this->head = nullptr;
}

template <typename C>
list<C>& list<C>::operator =(const list<C>& l)
{
    if(this->length() <= l.length())
    {
        listItem<C>* curl = l.head;
        listItem<C>* curt = this->head;
        for(; curt; curt = curt->get_next())
        {
            curt->set(curl->get_data());
            curl = curl->get_next();
        }

    }
    else
    {
        listItem<C>* curl = l.head;
        listItem<C>* curt = this->head;
        for(; curt; curt = curt->get_next())
        {

            if(curl)
            {
                curt->set(curl->get_data());
                curl = curl->get_next();
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
list<C> &list<C>::operator -=(const listItem<C> &data)
{
    this->del(data);
    return *this;
}

template <typename C>
list<C> &list<C>::operator -=(const C data)
{
    this->del(data);
    return *this;
}

template <typename C>
list<C>& list<C>::operator +(const list<C>& l)
{
    this->append(l);
    return *this;

}

template <typename C>
list<C>& list<C>::operator +(const listItem<C>& data)
{
    this->append(data);
    return *this;

}

template <typename C>
list<C> &list<C>::operator +(const C data)
{
    this->append(data);
    return *this;
}

template <typename C>
list<C> &list<C>::operator -(const C data)
{
    this->del(data);
    return *this;
}


template <typename C>
list<C>& list<C>::operator -(const listItem<C>& data)
{
    this->del(data);
    return *this;

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
size_t list<C>::size() const
{
    return (this->length() * sizeof(listItem<C>));
}

template <typename C>
void list<C>::clear()
{
    listItem<C>* cur = this->head;
    for(; cur; cur = cur->get_next())
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
    for(; cur; cur = cur->get_next())
    {
        s++;
    }

    return s;
}


template <typename C>
listItem<C>* list<C>::get_head() const
{
    return this->head;
}

template <typename C>
listItem<C>* list<C>::get_tail() const
{
    return this->tail;
}

template <typename C>
iterator_list<C>& list<C>::begin() const
{
    iterator_list<C> it(*this);
    it.first();

    return it;

}

template <typename C>
iterator_list<C>& list<C>::end() const
{
    iterator_list<C> it(*this);
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

    listItem<C>* cur = this->head;
    for(; cur->get_next(); cur = cur->get_next());

    listItem<C>* tmp = l.head;
    for(;tmp;tmp = tmp->get_next())
    {
        listItem<C>* item = new listItem<C>;
        //if(!item)
            //throw memError();
        item->set(tmp->get_data());
        cur->set_next(*item);
        cur = item;
    }

    return *this;



}

template <typename C>
list<C>& list<C>::append(const C data)
{
    if(!this->head)
    {
        listItem<C>* head = new listItem<C>;
        //if(!head)
            //throw memError();
        head->set(data);
        this->head = head;
        return *this;
    }

    listItem<C>* cur = this->head;
    for(; cur->get_next(); cur = cur->get_next());
    listItem<C>* new_item = new listItem<C>;
    //if(!new_item)
        //throw memError();
    new_item->set(data);
    cur->set_next(*new_item);
    return *this;

}


template <typename C>
list<C>& list<C>::append(const listItem<C>& elem)
{
    if(!this->head)
    {
        listItem<C>* head = new listItem<C>;
        //if(!head)
            //throw memError();
        head->data = elem.data;
        this->head = head;
        return *this;
    }

    listItem<C>* cur = this->head;
    for(; cur->next; cur = cur->next);
    listItem<C>* new_item = new listItem<C>;
    //if(!new_item)
        //throw memError();
    new_item->data = elem.data;
    cur->next = new_item;
    return *this;

}

template <typename C>
list<C>& list<C>::insert_front(const list<C>& l)
{
    if(!l.head)
        return *this;

    if(!this->head)
    {
        this->append(l);
        return *this;
    }
    listItem<C>* cur;
    listItem<C>* head = new listItem<C>;
    //if(!head)
        //throw memError();
    head->set(l.head->get_data());

    listItem<C>* tmp = head;
    cur = l.head->get_next();

    for(; cur; cur = cur->get_next())
    {
        listItem<C>* item = new listItem<C>;
        //if(!item)
            //throw memError();
        tmp->set_next(*item);
        item->set(cur->get_data());
        item->set_next(*this->head);
        tmp = tmp->get_next();
    }

    this->head = head;
    return *this;



}

template <typename C>
list<C>& list<C>::insert_front(const C data)
{

    if(!this->head)
    {
        this->append(data);
        return *this;
    }

    listItem<C>* new_head = new listItem<C>;
    //if(!new_head)
        //throw memError();
    new_head->set(data);
    new_head->set_next(*this->head);
    this->head = new_head;
    return *this;

}

template <typename C>
list<C>& list<C>::insert_front(const listItem<C>& elem)
{
    if(!this->head)
    {
        this->append(elem);
        return *this;
    }

    listItem<C>* new_head = new listItem<C>;
    //if(!new_head)
        //throw memError();
    new_head->data = elem.data;
    new_head->next = this->head;
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
list<C>& list<C>::insert_after(listItem<C>& after, C data)
{
    listItem<C>* f = this->find(after);
    listItem<C>* tmp = f->next;
    listItem<C>* item = new listItem<C>;
    //if(!item)
        //throw memError();
    item->data = data;
    f->next = item;
    item->next = tmp;
    return *this;

}

template <typename C>
list<C>& list<C>::insert_after(listItem<C>& after, list<C>&  l)
{
    listItem<C>* f = this->find(after);
    listItem<C>* buf = f->next;
    listItem<C>* cur;
    listItem<C>* head = new listItem<C>;
    //if(!head)
        //throw memError();
    head->data = l.head->data;

    listItem<C>* tmp = head;
    cur = l.head->next;

    for(; cur; cur = cur->next)
    {
        listItem<C>* item = new listItem<C>;
        //if(!item)
            //throw memError();
        tmp->next = item;
        item->data = cur->data;
        item->next = buf;
        tmp = tmp->next;
    }
    f->next = head;
    return *this;


}

template <typename C>
list<C>& list<C>::insert_after(listItem<C>& after, listItem<C>& elem)
{
    listItem<C>* f = this->find(after);
    listItem<C>* tmp = f->next;
    listItem<C>* item = new listItem<C>;
    //if(!item)
        //throw memError();
    item->data = elem.data;
    f->next = item;
    item->next = tmp;
    return *this;

}

template <typename C>
list<C>& list<C>::insert_before(listItem<C>& before, C data)
{
    listItem<C>* cur = this->head;
    listItem<C>* tmp = nullptr;
    while (cur && cur->data != before.data)
    {
        tmp = cur;
        cur = cur->next;
    }

    if (tmp != nullptr)
    {
        listItem<C>* item = new listItem<C>;
        //if(!item)
            //throw memError();
        item->data = data;
        tmp->next = item;
        item->next = cur;
        return *this;
    }
    else
    {
        this->insert_front(data);
        return *this;
    }


}

template <typename C>
list<C>& list<C>::insert_before(listItem<C>& before, list<C>& l)
{
    listItem<C>* cur = this->head;
    listItem<C>* tmp = nullptr;
    while (cur && cur->data != before.data)
    {
        tmp = cur;
        cur = cur->next;
    }

    if (tmp != nullptr)
    {
        listItem<C>* curr;
        listItem<C>* head = new listItem<C>;
        //if(!head)
            //throw memError();
        head->data = l.head->data;

        listItem<C>* buf = head;
        curr = l.head->next;

        for(; curr; curr = curr->next)
        {
            listItem<C>* item = new listItem<C>;
            //if(!item)
                //throw memError();
            buf->next = item;
            item->data = curr->data;
            item->next = cur;
            buf = buf->next;
        }

        tmp->next = head;
        return *this;

    }
    else
    {
        this->insert_front(l);
        return *this;
    }

}

template <typename C>
list<C>& list<C>::insert_before(listItem<C>& before, listItem<C>& elem)
{
    listItem<C>* cur = this->head;
    listItem<C>* tmp = nullptr;
    while (cur && cur->data != before.data)
    {
        tmp = cur;
        cur = cur->next;
    }

    if (tmp != nullptr)
    {
        listItem<C>* item = new listItem<C>;
        //if(!item)
            //throw memError();
        item->data = elem.data;
        tmp->next = item;
        item->next = cur;
        return *this;
    }
    else
    {
        this->insert_front(elem);
        return *this;
    }
}

template <typename C>
listItem<C>* list<C>::find(const listItem<C> &elem) const
{
    //if(!this->head)
        //throw emptyError();
    listItem<C>* cur = this->head;
    while (cur && cur->get_data()!= elem.get_data())
        cur = cur->get_next();

    return cur;

}

template <typename C>
listItem<C> *list<C>::find(const C data) const
{
    //if(!this->head)
        //throw emptyError();
    listItem<C>* cur = this->head;
    while (cur && cur->data != data)
        cur = cur->next;

    return cur;

}


template <typename C>
void list<C>::sort(bool increase)
{
    C* arr = this->to_array();
    if( increase)
        qsort(arr, this->length(), sizeof(C), compfunc::comp_inc<C>);
    else
        qsort(arr, this->length(), sizeof(C), compfunc::comp_dec<C>);

    listItem<C>* tmp = this->head;
    size_t i = 0;
    for(; tmp ; tmp = tmp->get_next())
    {
        tmp->set(arr[i]);
        i++;
    }

    delete [] arr;

}

template <typename C>
void list<C>::reverse()
{
    //if(this->length() < 3)
       // throw rangeError();
    listItem<C>* one = this->head;
    listItem<C>* two = one->get_next();
    listItem<C>* three = two->get_next();
    do
    {
        two->set_next(*one);
        one = two;
        two = three;
        if (three)
        {
            three = three->get_next();
        }
    }
    while(three != nullptr);
    two->set_next(*one);
    this->head->destroy_next();
    this->head = two;

}

template <typename C>
C* list<C>::to_array() const
{
     C* arr = new C[this->length()];
     //if(!arr)
         //throw memError();
     listItem<C>* tmp = this->head;
     for(size_t i  = 0;  i < this->length(); i++)
     {
         arr[i] = tmp->get_data();
         tmp = tmp->get_next();
     }

     return arr;
}

template <typename C>
list<C>& list<C>::replace(listItem<C>& elem,C data)
{
    listItem<C>* f = this->find(elem);
    f->data = data;
    return *this;

}

template <typename C>
list<C>& list<C>::replace(listItem<C>& elem, listItem<C>& temp)
{
    listItem<C>* f = this->find(elem);
    f->data = temp.data;
    return *this;

}

template <typename C>
listItem<C>* list<C>::del(const listItem<C> &elem)
{
    //(!this->head)
        //throw emptyError();
    listItem<C>* f = this->find(elem);
    listItem<C>* cur = this->head;
    if(cur->get_data() == elem.get_data())
    {
        this->head = this->head->get_next();
        return cur;
    }
    for(;cur && cur->get_next() != f; cur = cur->get_next());
    if(cur == nullptr)
        return nullptr;
    cur->set_next(*f->get_next());
    return f;

}

template <typename C>
listItem<C>* list<C>::del(const C data)
{
    //(!this->head)
        //throw emptyError();
    listItem<C>* f = this->find(data);
    listItem<C>* cur = this->head;
    if(cur->data == data)
    {
        this->head = this->head->next;
        return cur;
    }

    for(;cur && cur->next->data != f->data; cur = cur->next);
    if(cur == nullptr)
        return nullptr;
    cur->next = f->next;
    return f;

}


template <typename C>
std::ostream& operator<<(std::ostream& os, list<C>& l)
 {
    os << "List: ";
    listItem<C>* cur = l.get_head();
    if(cur == nullptr)
        os << "empty";
    for(; cur; cur = cur->get_next())
    {
        os << cur->get_data() << " ";
    }
    os << "\n";
    return os;

 }


#endif // LIST_H
