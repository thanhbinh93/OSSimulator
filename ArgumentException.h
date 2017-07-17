#ifndef ARGUMENTEXCEPTION_H
#define ARGUMENTEXCEPTION_H
#include <string>
#include <exception>
using namespace std;

class ArgumentException : public exception
{
    public:
        const char* what() const throw();
};

#endif // ARGUMENTEXCEPTION_H
