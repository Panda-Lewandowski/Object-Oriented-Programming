#ifndef _ERRORS_H
#define _ERRORS_H
#include <exception>

class baseError : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Some error was catched";
    }

};

class memError : public baseError
{
    const char* what()  const throw()
    {
        return "A memory allocation error";
    }
};

class rangeError : public baseError
{
    const char* what()  const throw()
    {
        return "List is out of range";
    }
};

class cmpIterError : public baseError
{
public:

    const char* what()  const throw()
    {
        return "Comparing iterators with different sources";
    }
};

class emptyError : public baseError
{
public:

    const char* what()  const throw()
    {
        return "Attempt to work with empty list or empty element";
    }
};


#endif // _ERRORS_H
