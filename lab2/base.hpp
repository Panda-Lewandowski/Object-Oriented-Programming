#ifndef BASE_H
#define BASE_H

class baseContainer
{
public:
    //virtual size_t size() const     = 0;
    virtual void clear()            = 0;
    virtual bool is_empty() const   = 0;
    virtual size_t length() const   = 0;
};


#endif // BASE_H
