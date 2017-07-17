#include "IllegalAccessMemoryException.h"

const char* IllegalAccessMemoryException::what() const throw()
{
    return "Invalid access to memory";
}
