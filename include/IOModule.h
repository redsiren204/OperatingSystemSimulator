/**
 *  IOModule Class.
 *  Includes functions likes reading a input file, print on screen
 */
#ifndef IOMODULE_H
#define IOMODULE_H

#include <list>
#include <string>
#include "Instruction.h"

using namespace std;

class IOModule
{
    public:
        /**
         *  IOModule constructor.
         */
        IOModule();
        /**
         *  IOModule destructor.
         */
        virtual ~IOModule();

        /**
         *  Display function
         *  @param code is an integer
         *  @param mode is an integer
         */
        static void display(int code, int mode);

    protected:

    private:
};

#endif // IOMODULE_H
