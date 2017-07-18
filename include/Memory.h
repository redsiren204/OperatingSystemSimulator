/**
 *  Memory class.
 *  It will consist of 2000 integer entries, 0-999 for the user program, 1000-1999 for system code.
 *  It will support two operations:
 *      read(address) -  returns the value at the address
 *      write(address, data) - writes the data to the address
 *  Memory will initialize itself by reading a program file.
 */
#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <fstream>
#include <sstream>
#include "Program.h"

using namespace std;

class Memory
{
    public:
        /**
         *  Memory constructor.
         */
        Memory();
        /**
         *  Memory destructor.
         */
        virtual ~Memory();

        /**
         *  Declares macro USER_PROGRAM_ADDRESS is 999
         *  Declares macro MEMORY_MAXIMUM_SIZE is 2000
         */
        static const int USER_PROGRAM_ADDRESS = 999;
        static const int MEMORY_MAXIMUM_SIZE = 2000;

        /**
         *  Reads value from an address.
         */
        int read(int address);

        /**
         *  Writes a value to an address.
         *  @param address is an integer
         *  @param data is an integer
         */
        void write(int address, int data);

        /**
         *  Loads program from a string
         *  @param program is a string
         */
        void loadProgram(string program);

        /**
         *  Gets program
         *  @return a Program
         */
        Program getProgram();

        /**
         *  Parses instruction
         *  @param parseIt is a string
         */
        int parseInstruction(string parseIt);

        /**
         *  Clean function.
         */
        void clean();

    protected:

    private:
        /**
         *  Declare memory array with MEMORY_MAXIMUM_SIZE elements.
         */
        int memory[MEMORY_MAXIMUM_SIZE];
        int address;
        Program program;
};

#endif // MEMORY_H

