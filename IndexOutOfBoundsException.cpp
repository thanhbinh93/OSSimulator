#include "IndexOutOfBoundsException.h"

const char* IndexOutOfBoundsException::what() const throw()
{
    return "Index out of bound ";
}

