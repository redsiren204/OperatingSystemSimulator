/**
 *  Program Class.
 */
#ifndef PROGRAM_H
#define PROGRAM_H

#include <list>
#include "Instruction.h"

using namespace std;

class Program
{
    public:
        /**
         *  Program constructor.
         */
        Program();
        /**
         *  Program destructor.
         */
        virtual ~Program();

        /**
         *  Gets program ID
         *  @return an integer is the program ID
         */
        int getPid();
        /**
         *  Sets program ID
         *  @param pid is an integer
         */
        void setPid(int pid);

        /**
         *  Gets instructions
         *  @return list<Instruction> is a list of instructions
         */
        list<Instruction> getInstructions();
        /**
         *  Sets instructions
         *  @param list<Instruction> is a list of instructions
         */
        void setInstructions(list<Instruction> instructions);

    protected:

    private:
        /**
         *  Program ID
         */
        int pid;
        /**
         *  A list of instructions
         */
        list<Instruction> instructions;
};

#endif // PROGRAM_H
