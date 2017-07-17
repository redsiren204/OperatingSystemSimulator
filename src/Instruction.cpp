#include "Instruction.h"

Instruction::Instruction()
{
    //ctor
}

int Instruction::getCode()
{
    return code;
}

int Instruction::getOperand()
{
    return operand;
}

void Instruction::setCode(int code)
{
    this->code = code;
}

void Instruction::setOperand(int operand)
{
    this->operand = operand;
}

Instruction::~Instruction()
{
    //dtor
}
