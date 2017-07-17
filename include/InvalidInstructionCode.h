/**
 *  Invalid Instruction Code class.
 *  Customize exception for invalid instruction code.
 */
#ifndef INVALIDINSTRUCTIONCODE_H
#define INVALIDINSTRUCTIONCODE_H

#include <exception>

using namespace std;

class InvalidInstructionCode : public exception
{
    public:
        const char* what() const throw();
};

#endif // INVALIDINSTRUCTIONCODE_H
