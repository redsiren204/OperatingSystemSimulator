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
         *  Declare macro USER_PROGRAM_ADDRESS is 1000
         */
        static const int USER_PROGRAM_ADDRESS = 1000;

        /**
         *  Read value from an address.
         */
        int read(int address);

        /**
         *  Write a value to an address.
         */
        void write(int address, int data);

        /**
         *  Clean function.
         */
        void clean();

    protected:

    private:
        /**
         *  Declare memory array with 2000 elements.
         */
        int memory[2000];
};

#endif // MEMORY_H
