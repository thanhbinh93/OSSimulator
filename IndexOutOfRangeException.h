#ifndef INDEXOUTOFRANGEEXCEPTION_H
#define INDEXOUTOFRANGEEXCEPTION_H

#include <string>
#include <exception>
using namespace std;

class IndexOutOfRangeException : public exception
{
    public:
        const char* what() const throw();
};

#endif // INDEXOUTOFRANGEEXCEPTION_H
