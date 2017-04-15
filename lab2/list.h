#ifndef LIST_H
#define LIST_H
#include "_list.h"
//#define DEBUG

//------------------LIST REALISATION---------------------------------

template <typename C>
list<C>::list()
{
     listItem<C>* head = new listItem<C>;
     this->head = head;
}

template <typename C>
list<C>::list(const list<C> &l)
{
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
    this->head = l.head;

}

template <typename C>
list<C>::list(size_t n)
{
    listItem<C>* head = new listItem<C>;
    this->head = head;
    listItem<C>* cur = head;
    for(int i = 0; i < n - 1; i++)
    {
        listItem<C>* item = new listItem<C>;
        cur->next = item;
        cur = item;
    }
}


template <typename C>
list<C>::list(C *mass, int n)
{
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

}

template <typename C>
list<C>& list<C>::operator +=(const list<C>& l)
{

}

template <typename C>
list<C> &list<C>::operator +=(const listItem<C> &data)
{

}


template <typename C>
list<C>& list<C>::operator +(const list<C>& l)
{

}

template <typename C>
list<C>& list<C>::operator +(const listItem<C>& data)
{

}

template <typename C>
bool list<C>::operator ==(const list<C>& l) const
{

}

template <typename C>
bool list<C>::operator >=(const list<C>& l) const
{

}

template <typename C>
bool list<C>::operator <=(const list<C>& l) const
{

}

template <typename C>
bool list<C>::operator !=(const list<C>& l) const
{

}

template <typename C>
bool list<C>::operator >(const list<C>& l) const
{

}

template <typename C>
bool list<C>::operator <(const list<C>& l) const
{

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
    listItem<C>* cur = this->head;
    size_t s = 0;
    for(; cur; cur = cur->next)
    {
        s++;
    }

    return s;
}

template <typename C>
iterator_list<C>& list<C>::at(size_t pos) const
{

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

}

template <typename C>
list<C>& list<C>::append(const C& data)
{

}

template <typename C>
list<C>& list<C>::new_head(const list<C>& l)
{

}

template <typename C>
list<C>& list<C>::new_head(const C& data)
{

}

template <typename C>
int list<C>::compare(const list<C>& l)
{

}

template <typename C>
list<C>& insert_after(listItem<C>& elem, list<C>& l)
{

}

template <typename C>
list<C>& insert_after(listItem<C>& elem, listItem<C>& after)
{

}


template <typename C>
list<C>& insert_before(listItem<C>& elem, list<C>& l)
{

}

template <typename C>
list<C>& insert_before(listItem<C>& elem, listItem<C>& after)
{

}

template <typename C>
listItem<C>& list<C>::find(listItem<C>& elem) const
{

}

template <typename C>
listItem<C>& list<C>::find(C data) const
{

}


template <typename C>
void list<C>::sort(bool increase)
{

}

template <typename C>
void list<C>::reverse()
{

}

template <typename C>
list<C>& list<C>::replace(listItem<C>& elem,C data)
{

}

template <typename C>
list<C>& list<C>::replace(listItem<C>& elem, listItem<C>& temp)
{

}

template <typename C>
listItem<C>& list<C>::del(listItem<C>& elem)
{

}

template <typename C>
listItem<C>& list<C>::del(C data)
{

}


template <typename C>
std::ostream& operator<<(std::ostream& os, list<C>& l)
 {
    os << "List: ";
    listItem<C>* cur = l.head;
    for(; cur; cur = cur->next)
    {
        os << cur->data << " ";
    }
    os << "\n";
    return os;

 }

#endif // LIST_H
