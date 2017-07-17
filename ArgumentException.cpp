#include "ArgumentException.h"

const char* ArgumentException::what() const throw()
{
    return "Invalid Argument";
}
