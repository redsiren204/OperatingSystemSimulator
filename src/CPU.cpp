#include "CPU.h"
#include "Instruction.h"

CPU::CPU()
{
    // Initialize for all registers
    PC = Register("PC");
    SP = Register("SP");
    IR = Register("IR");
    AC = Register("AC");
    X  = Register("X");
    Y  = Register("Y");

    // Initialize the timer and user mode
    timer = Timer();
    userMode = false;
    isInterrupt = false;
}

void CPU::executeInstruction(Instruction ins)
{

}

CPU::~CPU()
{

}
