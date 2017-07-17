/**
 *  Invalid Memory Address class.
 *  Customize exception for invalid memory access.
 */
#ifndef INVALIDMEMORYADDRESS_H
#define INVALIDMEMORYADDRESS_H

#include <exception>

using namespace std;

class InvalidMemoryAddress : public exception
{
    public:
        const char* what() const throw();
};

#endif // INVALIDMEMORYADDRESS_H
