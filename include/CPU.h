/**
 *  CPU class.
 *  It will have these registers:  PC, SP, IR, AC, X, Y.
 *  It will support the instructions shown on the next page of this document.
 *  It will run the user program at address 0.
 *  Instructions are fetched into the IR from memory.  The operand can be fetched into a local variable.
 *  Each instruction should be executed before the next instruction is fetched.
 *  The user stack resides at the end of user memory and grows down toward address 0.
 *  The system stack resides at the end of system memory and grows down toward address 0.
 *  There is no hardware enforcement of stack size.
 *  The program ends when the End instruction is executed.
 *  The user program cannot access system memory (exits with error message).
 */
#ifndef CPU_H
#define CPU_H

#include "Instruction.h"
#include "Register.h"
#include "Timer.h"

class CPU
{
    public:
        /**
         *  CPU constructor.
         */
        CPU();
        /**
         *  CPU destructor.
         */
        virtual ~CPU();
        /**
         *  Executes the instruction by an argument
         *  @param ins an instruction.
         */
        void executeInstruction(Instruction ins);

    protected:

    private:
        /**
         *  Declares registers: PC, SP, IR, AC, X, Y
         */
        Register PC;
        Register SP;
        Register IR;
        Register AC;
        Register X;
        Register Y;

        /**
         *  Declares timer, userMode, isInterrupt
         */
        Timer timer;
        bool userMode;
        bool isInterrupt;
};

#endif // CPU_H
