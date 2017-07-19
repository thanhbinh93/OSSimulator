#ifndef ILLEGALACCESSMEMORYEXCEPTION_H
#define ILLEGALACCESSMEMORYEXCEPTION_H

#include <string>
#include <exception>
using namespace std;

class IllegalAccessMemoryException : public exception
{
    public:
        const char* what() const throw();
};

#endif // ILLEGALACCESSMEMORYEXCEPTION_H
