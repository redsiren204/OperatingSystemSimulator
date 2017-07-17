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
         *  Reads a file
         *  @param filePath is a string
         *  @return list<Instruction> is a list of instructions
         */
        static list<Instruction> readFile(string filePath);
        /**
         *  Print function
         *  @param code is an integer
         *  @param mode is an integer
         */
        static void print(int code, int mode);

    protected:

    private:
};

#endif // IOMODULE_H
