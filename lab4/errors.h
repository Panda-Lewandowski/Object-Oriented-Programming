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
        return "Range error";
    }
};


#endif // _ERRORS_H
