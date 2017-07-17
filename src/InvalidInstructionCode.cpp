#include "InvalidInstructionCode.h"

const char* InvalidInstructionCode::what() const throw()
{
    return "Invalid instruction code";
}
