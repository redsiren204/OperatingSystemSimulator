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
#include "Memory.h"
#include "IOModule.h"

class CPU
{
    public:
        /**
         *  CPU constructor.
         */
        CPU();
        CPU(Memory memory, int timeStep);
        /**
         *  CPU destructor.
         */
        virtual ~CPU();

        void run();

        /**
         *  Gets the next instruction point by PC register
         */
        Instruction getNextIns();

        /**
         *  Executes the instruction by an argument
         *  @param ins an instruction.
         */
        void executeInstruction(Instruction ins);

        /**
         *  Loads the value into the AC
         */
        void loadValue(int value);

        /**
         *  Loads the value at the address into the AC
         */
        void loadAddress(int address);

        /**
         *  Loads the value from the address found in the given address into the AC
         *  (for example, if LoadInd 500, and 500 contains 100, then load from 100).
         */
        void loadInd(int address);

        /**
         *  Loads the value at (address+X) into the AC
         *  (for example, if LoadIdxX 500, and X contains 10, then load from 510).
         */
        void loadIdxX(int address);

        /**
         *  Loads the value at (address+Y) into the AC
         */
        void loadIdxY(int address);

        /**
         *  Loads from (Sp+X) into the AC
         */
        void loadSpX();

        /**
         *  Stores the value in the AC into the address
         */
        void store(int address);

        /**
         *  Gets a random int from 1 to 100 into the AC
         */
        void getRand();

        /**
         *  If port=1, writes AC as an int to the screen
         *  If port=2, writes AC as a char to the screen
         */
        void put(int port);

        /**
         *  Adds the value in X to the AC
         */
        void addX();

        /**
         *  Adds the value in Y to the AC
         */
        void addY();

        /**
         *  Subtracts the value in X from the AC
         */
        void subX();

        /**
         *  Subtracts the value in Y from the AC
         */
        void subY();

        /**
         *  Copies the value in the AC to X
         */
        void copyToX();

        /**
         *  Copies the value in X to the AC
         */
        void copyFromX();

        /**
         *  Copies the value in the AC to Y
         */
        void copyToY();

        /**
         *  Copies the value in Y to the AC
         */
        void copyFromY();

        /**
         *  Copies the value in the AC to SP
         */
        void copyToSP();

        /**
         *  Copies the value in SP to the AC
         */
        void copyFromSP();

        /**
         *  Jumps to the address
         */
        void jump(int address);

        /**
         *  Jumps to the address only if the value in the AC is zero
         */
        void jumpIfEqual(int address);

        /**
         *  Jumps to the address only if the value in the AC is not zero
         */
        void jumpIfNotEqual(int address);

        /**
         *  Pushes return address onto stack, jump to the address
         */
        void call(int address);

        /**
         *  Pops return address from the stack, jump to the address
         */
        void ret(int address);

        /**
         *  Increments the value in X
         */
        void incX();

        /**
         *  Decrements the value in X
         */
        void decX();

        /**
         *  Pushes AC onto stack
         */
        void push();

        /**
         *  Pops from stack into AC
         */
        void pop();

        /**
         *  Sets system mode, switch stack, push SP and PC, set new SP and PC
         */
        void interrupt();

        /**
         *  Restores registers, set user mode
         */
        void returnInterrupt();

        /**
         *  Ends execute
         */
        void endExecute();

    protected:

    private:
        Memory memMgr;

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
         *  Declares timer, userMode, isInterrupt, isFinished
         */
        Timer timer;
        bool userMode;
        bool isInterrupt;

        bool isFinished = false;
};

#endif // CPU_H
