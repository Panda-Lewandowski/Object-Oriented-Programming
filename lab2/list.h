#ifndef LIST_H
#define LIST_H
#include "_list.h"
#include <stdlib.h>
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
    //ошибка выделения памяти
     listItem<C>* head = new listItem<C>;
     this->head = head;
}

template <typename C>
list<C>::list(const list<C> &l)
{
    //если l пустой?
    listItem<C>* cur;
    listItem<C>* head = new listItem<C>;
    head->data = l.head->data;

    this->head = head;
    listItem<C>* tmp = head;
    cur = l.head->next;

    for(; cur; cur = cur->next)
    {
        listItem<C>* item = new listItem<C>;
        tmp->next = item;
        item->data = cur->data;
        tmp = tmp->next;
    }

}

template <typename C>
list<C>::list(list<C> &&l)
{
    //если эль пустой?
    this->head = l.head;

}

template <typename C>
list<C>::list(size_t n)
{
    //если эн равно 0?
    listItem<C>* head = new listItem<C>;
    this->head = head;
    listItem<C>* cur = head;
    for(size_t i = 0; i < n - 1; i++)
    {
        listItem<C>* item = new listItem<C>;
        cur->next = item;
        cur = item;
    }
}


template <typename C>
list<C>::list(C *mass, int n)
{
    //если массив пустой?
    //есои эн равно нулю?
    listItem<C>* head = new listItem<C>;
    this->head = head;
    this->head->data = mass[0];
    listItem<C>* cur = head;

    for(int i = 1; i < n; i++)
    {
        listItem<C>* item = new listItem<C>;
        item->data = mass[i];
        cur->next = item;
        cur = item;
    }

}

template <typename C>
list<C>::list(C data, size_t n)
{
    //если эн равно нулю?
    listItem<C>* head = new listItem<C>;
    head->data = data;
    this->head = head;
    listItem<C>* cur = head;
    for(size_t i = 0; i < n - 1; i++)
    {
        listItem<C>* item = new listItem<C>;
        item->data = data;
        cur->next = item;
        cur = item;
    }
}

template <typename C>
list<C>::list(const list<C> &l, size_t n)
{
    //если список пустой
    //если эн равно нулю
    listItem<C>* cur;
    listItem<C>* head = new listItem<C>;
    head->data = l.head->data;
    n--;

    this->head = head;
    listItem<C>* tmp = head;
    cur = l.head->next;

    for(; cur && n; cur = cur->next)
    {
        listItem<C>* item = new listItem<C>;
        tmp->next = item;
        item->data = cur->data;
        tmp = tmp->next;
        n--;
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
            next = this->head->next;
            delete this->head;

        }
    }

    this->head = nullptr;
}

template <typename C>
list<C>& list<C>::operator =(const list<C>& l)
{

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
    //если список пустой
    listItem<C>* cur = this->head;
    for(; cur; cur = cur->next)
    {
        cur->data = 0;
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
    //если список пустой
    listItem<C>* cur = this->head;
    size_t s = 0;
    for(; cur; cur = cur->next)
    {
        s++;
    }

    return s;
}


template <typename C>
iterator_list<C>& list<C>::begin() const
{

}

template <typename C>
iterator_list<C>& list<C>::end() const
{

}

template <typename C>
list<C>& list<C>::append(const list<C>& l)
{
    listItem<C>* cur = this->head;
    for(; cur->next; cur = cur->next);

    listItem<C>* tmp = l.head;
    for(;tmp;tmp = tmp->next)
    {
        listItem<C>* item = new listItem<C>;
        item->data = tmp->data;
        cur->next = item;
        cur = item;
    }

    return *this;



}

template <typename C>
list<C>& list<C>::append(const C data)
{
    listItem<C>* cur = this->head;
    for(; cur->next; cur = cur->next);
    listItem<C>* new_item = new listItem<C>;
    new_item->data = data;
    cur->next = new_item;
    return *this;

}


template <typename C>
list<C>& list<C>::append(const listItem<C>& elem)
{
    listItem<C>* cur = this->head;
    for(; cur->next; cur = cur->next);
    listItem<C>* new_item = new listItem<C>;
    new_item->data = elem.data;
    cur->next = new_item;
    return *this;

}

template <typename C>
list<C>& list<C>::insert_front(const list<C>& l)
{
    //если эль путсой
    listItem<C>* cur;
    listItem<C>* head = new listItem<C>;
    head->data = l.head->data;

    listItem<C>* tmp = head;
    cur = l.head->next;

    for(; cur; cur = cur->next)
    {
        listItem<C>* item = new listItem<C>;
        tmp->next = item;
        item->data = cur->data;
        item->next = this->head;
        tmp = tmp->next;
    }

    this->head = head;
    return *this;



}

template <typename C>
list<C>& list<C>::insert_front(const C data)
{
    //ошибка выделения памяти
    listItem<C>* new_head = new listItem<C>;
    new_head->data = data;
    new_head->next = this->head;
    this->head = new_head;
    return *this;

}

template <typename C>
list<C>& list<C>::insert_front(const listItem<C>& elem)
{
    //ошибка выделения памяти
    listItem<C>* new_head = new listItem<C>;
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
    //если не найдено?
    listItem<C>* tmp = f->next;
    listItem<C>* item = new listItem<C>;
    item->data = data;
    f->next = item;
    item->next = tmp;
    return *this;

}

template <typename C>
list<C>& list<C>::insert_after(listItem<C>& after, list<C>&  l)
{
    listItem<C>* f = this->find(after);
    //если не найдено?
    listItem<C>* buf = f->next;
    listItem<C>* cur;
    listItem<C>* head = new listItem<C>;
    head->data = l.head->data;

    listItem<C>* tmp = head;
    cur = l.head->next;

    for(; cur; cur = cur->next)
    {
        listItem<C>* item = new listItem<C>;
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
    //если не найдено?
    listItem<C>* tmp = f->next;
    listItem<C>* item = new listItem<C>;
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
    //если не найдено?

    if (tmp != nullptr)
    {
        listItem<C>* item = new listItem<C>;
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
    //если не найдено?

    if (tmp != nullptr)
    {
        listItem<C>* curr;
        listItem<C>* head = new listItem<C>;
        head->data = l.head->data;

        listItem<C>* buf = head;
        curr = l.head->next;

        for(; curr; curr = curr->next)
        {
            listItem<C>* item = new listItem<C>;
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
    //если не найдено?

    if (tmp != nullptr)
    {
        listItem<C>* item = new listItem<C>;
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
    //если елем пустой
    listItem<C>* cur = this->head;
    while (cur && cur->data != elem.data)
        cur = cur->next;

    return cur;

}

template <typename C>
listItem<C> *list<C>::find(const C data) const
{
    //если елем пустой
    listItem<C>* cur = this->head;
    while (cur && cur->data != data)
        cur = cur->next;

    return cur;

}


template <typename C>
void list<C>::sort(bool increase)
{
    /*C* arr = this->to_array();
    if( increase)
        qsort(arr, this->length(), sizeof(C), compfunc::comp_inc);
    else
        qsort(arr, this->length(), sizeof(C), compfunc::comp_dec);

    listItem<C>* tmp = this->head;
    size_t i = 0;
    for(; tmp ; tmp = tmp->next)
    {
        tmp->data = arr[i];
        i++;
    }*/

}

template <typename C>
void list<C>::reverse()
{
    listItem<C>* one = this->head;
    listItem<C>* two = one->next;
    listItem<C>* three = two->next;
    do
    {
        two->next = one;
        one = two;
        two = three;
        three = three->next;
    }
    while(three != nullptr);
    two->next = one;
    this->head->next = nullptr;
    this->head = two;

}

template <typename C>
C* list<C>::to_array() const
{
     C* arr = new C[this->length()];
     listItem<C>* tmp = this->head;
     for(int i  = 0;  i < this->length(); i++)
     {
         arr[i] = tmp->data;
         tmp = tmp->next;
     }

     return arr;
}

template <typename C>
list<C>& list<C>::replace(listItem<C>& elem,C data)
{
    listItem<C>* f = this->find(elem);
    //если не найдено?
    f->data = data;
    return *this;

}

template <typename C>
list<C>& list<C>::replace(listItem<C>& elem, listItem<C>& temp)
{
    listItem<C>* f = this->find(elem);
    //если не найдено?
    f->data = temp.data;
    return *this;

}

template <typename C>
listItem<C>* list<C>::del(const listItem<C> &elem)
{
    listItem<C>* f = this->find(elem);
    //если не найдено?
    listItem<C>* cur = this->head;
    if(cur->data == elem.data)
    {
        this->head = this->head->next;
        return cur;
    }
    for(;cur && cur->next != f; cur = cur->next);
    if(cur == nullptr)
        return nullptr;
    cur->next = f->next;
    return f;

}

template <typename C>
listItem<C>* list<C>::del(const C data)
{
    listItem<C>* f = this->find(data);
    //если не найдено?
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
    listItem<C>* cur = l.head;
    if(cur == nullptr)
        os << "empty";
    for(; cur; cur = cur->next)
    {
        os << cur->data << " ";
    }
    os << "\n";
    return os;

 }


#endif // LIST_H
