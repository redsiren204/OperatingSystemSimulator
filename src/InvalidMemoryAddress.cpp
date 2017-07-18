#include "InvalidMemoryAddress.h"

const char* InvalidMemoryAddress::what() const throw()
{
    return "Invalid access to memory";
}
