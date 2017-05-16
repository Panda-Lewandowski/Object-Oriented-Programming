#ifndef BASE_H
#define BASE_H

class baseContainer
{
public:
    virtual void clear()            = 0;
    virtual bool is_empty() const   = 0;
    virtual size_t length() const   = 0;
};


#endif // BASE_H
