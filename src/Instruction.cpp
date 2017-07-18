#include "Instruction.h"

Instruction::Instruction()
{
    code = 0;
    operand = 0;
}

Instruction::Instruction(int insCode, int insOperand)
{
    code = insCode;
    operand = insOperand;
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

}
