#include "NotSupportedInstructionException.h"

const char* NotSupportedInstructionException::what() const throw()
{
    return "Not supported instruction";
}

