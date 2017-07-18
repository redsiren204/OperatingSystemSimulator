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
        OperatingSystem(string program, int timeStep);
        /**
         *  Operating System destructor.
         */
        virtual ~OperatingSystem();

        /**
         *  Runs operating system
         */
        void run();

    protected:

    private:
        CPU cpu;
};

#endif // OPERATINGSYSTEM_H
