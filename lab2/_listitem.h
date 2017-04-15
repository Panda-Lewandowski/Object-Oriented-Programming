#ifndef _LISTITEM_H
#define _LISTITEM_H
#include <iostream>

template <typename C>
class listItem
{
public:
    listItem* next;
    C data;
    listItem();
    listItem(C data);
    listItem(listItem<C>& elem);
    ~listItem();
    void set_next(listItem<C>& elem);
    listItem<C>& get_next() const;

    bool operator ==(const listItem<C>& elem) const;
    bool operator >=(const listItem<C>& l) const;
    bool operator <=(const listItem<C>& l) const;
    bool operator !=(const listItem<C>& l) const;
    bool operator >(const listItem<C>& l) const;
    bool operator <(const listItem<C>& l) const;

    //friend std::ostream& operator<<(std::ostream& os, listItem<C>& elem);
};

#endif // _LISTITEM_H
