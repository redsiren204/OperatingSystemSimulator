#include "InvalidInstructionCode.h"

const char* InvalidInstructionCode::what() const throw()
{
    return "Index out of range";
}
