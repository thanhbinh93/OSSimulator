#ifndef NOTSUPPORTEDINSTRUCTIONEXCEPTION_H
#define NOTSUPPORTEDINSTRUCTIONEXCEPTION_H

#include <string>
#include <exception>
using namespace std;

class NotSupportedInstructionException : public exception
{
    public:
        const char* what() const throw();
};

#endif // NOTSUPPORTEDINSTRUCTIONEXCEPTION_H
