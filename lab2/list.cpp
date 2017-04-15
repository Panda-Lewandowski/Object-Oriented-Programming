#include "_list.h"
#define DEBUG

//------------------LIST REALISATION---------------------------------

template <typename C>
list<C>::list()
{
     listItem<C> head;
     this->head = &head;
}

template <typename C>
list<C>::list(const list<C> &l)
{

}

template <typename C>
list<C>::list(list<C> &&l)
{

}

template <typename C>
list<C>::list(size_t n)
{

}


template <typename C>
list<C>::list(C *mass)
{

}

template <typename C>
list<C>::list(listItem<C> data, size_t n)
{

}

template <typename C>
list<C>::list(const list<C> &l, size_t pos, size_t n)
{

}

template <typename C>
list<C>::~list()
{
    //delete this->data;
#ifdef DEBUG
    std::cout << "Деструктор класса List!\n";
#endif

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
listItem<C>& list<C>::operator [](size_t pos)
{

}

template <typename C>
const listItem<C> &list<C>::operator [](size_t pos) const
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

}

template <typename C>
void list<C>::clear()
{

}

template <typename C>
bool list<C>::is_empty() const
{

}

template <typename C>
size_t list<C>::length() const
{

}

template <typename C>
listItem<C>& list<C>::at(size_t pos) const
{

}

template <typename C>
listItem<C>& list<C>::begin() const
{

}

template <typename C>
listItem<C>& list<C>::end() const
{

}

template <typename C>
iterator_list<C>& list<C>::begin()
{

}

template <typename C>
iterator_list<C>& list<C>::end()
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
int list<C>::compare(const list<C>& l)
{

}

template <typename C>
list<C>& list<C>::insert(size_t pos, list<C>& l)
{

}

template <typename C>
list<C>& list<C>::insert(size_t pos, listItem<C>& elem)
{

}

template <typename C>
listItem<C>& list<C>::find(listItem<C>& elem) const
{

}

template <typename C>
size_t list<C>::index(listItem<C>& elem) const
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
list<C>& list<C>::replace(size_t pos, listItem<C>& elem)
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
listItem<C>& list<C>::del(size_t pos)
{

}


template <typename C>
std::ostream& operator<<(std::ostream& os, list<C>& l)
 {

 }

template <typename C>
std::istream& operator>>(std::istream& os, list<C>& l)
 {

 }
