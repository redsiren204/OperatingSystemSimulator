#include "Program.h"

Program::Program()
{
    //ctor
}

int Program::getPid()
{
    return pid;
}

void Program::setPid(int pid)
{
    this->pid = pid;
}

list<Instruction> Program::getInstructions()
{
    return instructions;
}

void Program::setInstructions(list<Instruction> instructions)
{
    this->instructions = instructions;
}

Program::~Program()
{
    //dtor
}
