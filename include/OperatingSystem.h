/**
 *  OperatingSystem Class.
 *  This class inits and runs operating system.
 */
#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H

#include "CPU.h"
#include "Memory.h"

class OperatingSystem
{
    public:
        /**
         *  Operating System constructor.
         */
        OperatingSystem();
        /**
         *  Operating System destructor.
         */
        virtual ~OperatingSystem();

        /**
         *  Initilizes operating system
         */
        void init();
        /**
         *  Runs operating system
         */
        void run();

    protected:

    private:
        CPU cpu;
        Memory memory;
};

#endif // OPERATINGSYSTEM_H
