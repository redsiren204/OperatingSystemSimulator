#include "CPU.h"
#include "Instruction.h"
#include <cstdlib>
#include "InvalidInstructionCode.h"
#include <iostream>

using namespace std;

CPU::CPU()
{

}

CPU::CPU(Memory memory, int timeStep)
{
    this->memMgr = memory;

    /**
     *  Initializes for all registers
     */
    PC = Register("PC");
    SP = Register("SP");
    SP.setValue(Memory::USER_PROGRAM_ADDRESS);
    IR = Register("IR");
    AC = Register("AC");
    X  = Register("X");
    Y  = Register("Y");

    /**
     *  Initializes the timer and user mode
     */
    timer = Timer(timeStep);
    userMode = false;
    isInterrupt = false;
}

void CPU::run()
{
    PC.setValue(0);

    isFinished = false;
    int count = 1;
    while (!isFinished)
    {
        Instruction ins = getNextIns();
        //cout << "Ins " << count << ": " << ins.getCode() << " --- " << ins.getOperand() << endl;
        //if (ins.getCode() == 23) break;
        executeInstruction(ins);
    }

    memMgr.clean();
}

Instruction CPU::getNextIns()
{
    int insCode = memMgr.read(PC.getValue());
    int insOperand = 0;

    switch (insCode)
	{
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 9:
        case 20:
        case 21:
        case 22:
        case 23:
            insOperand = memMgr.read(PC.getValue() + 1);
            break;

        default:
            break;
	}

	Instruction instruction = Instruction(insCode, insOperand);

	IR.setValue(IR.getValue() + 1);

    return instruction;
}

void CPU::executeInstruction(Instruction instruction)
{
    int insCode = instruction.getCode();
    int insOperand = instruction.getOperand();
    //cout << "Ins: " << insCode << endl;
    //cout << "Operand: " << insOperand << endl;

    switch (insCode)
	{
        case 1:
            loadValue(insOperand);
            break;

        case 2:
            loadAddress(insOperand);
            break;

        case 3:
            loadInd(insOperand);
            break;

        case 4:
            loadIdxX(insOperand);
            break;

        case 5:
            loadIdxY(insOperand);
            break;

        case 6:
            loadSpX();
            break;

        case 7:
            store(insOperand);
            break;

        case 8:
            getRand();
            break;

        case 9:
            put(insOperand);
            break;

        case 10:
            addX();
            break;

        case 11:
            addY();
            break;

        case 12:
            subX();
            break;

        case 13:
            subY();
            break;

        case 14:
            copyToX();
            break;

        case 15:
            copyFromX();
            break;

        case 16:
            copyToY();
            break;

        case 17:
            copyFromY();
            break;

        case 18:
            copyToSP();
            break;

        case 19:
            copyFromSP();
            break;

        case 20:
            jump(insOperand);
            break;

        case 21:
            jumpIfEqual(insOperand);
            break;

        case 22:
            jumpIfNotEqual(insOperand);
            break;

        case 23:
            call(insOperand);
            break;

        case 24:
            ret(insOperand);
            break;

        case 25:
            incX();
            break;

        case 26:
            decX();
            break;

        case 27:
            push();
            break;

        case 28:
            pop();
            break;

        case 29:
            interrupt();
            break;

        case 30:
            returnInterrupt();
            break;

        case 50:
            endExecute();
            break;

        default:
            throw InvalidInstructionCode();
	}
}

/**
 *  Loads the value into the AC
 */
void CPU::loadValue(int value)
{
    /**
     *  Assigns value into register and increase PC register value
     */
    AC.setValue(value);
    PC.setValue(PC.getValue() + 2);
}

/**
 *  Loads the value at the address into the AC
 */
void CPU::loadAddress(int address)
{
    int value = memMgr.read(address);
    AC.setValue(value);

    PC.setValue(PC.getValue() + 2);
}

/**
 *  Loads the value from the address found in the given address into the AC
 *  (for example, if LoadInd 500, and 500 contains 100, then load from 100).
 */
void CPU::loadInd(int address)
{
    int refAddress = memMgr.read(address);
    AC.setValue(memMgr.read(refAddress));

    PC.setValue(PC.getValue() + 2);
}

/**
 *  Loads the value at (address+X) into the AC
 *  (for example, if LoadIdxX 500, and X contains 10, then load from 510).
 */
void CPU::loadIdxX(int address)
{
    int value = memMgr.read(address + X.getValue());
    AC.setValue(value);

    PC.setValue(PC.getValue() + 2);
}

/**
 *  Loads the value at (address+Y) into the AC
 */
void CPU::loadIdxY(int address)
{
    int value = memMgr.read(address + Y.getValue());
    AC.setValue(value);

    PC.setValue(PC.getValue() + 2);
}

/**
 *  Loads from (Sp+X) into the AC
 */
void CPU::loadSpX()
{
    int value = memMgr.read(SP.getValue() + X.getValue());
    AC.setValue(value);

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Stores the value in the AC into the address
 */
void CPU::store(int address)
{
    memMgr.write(address, AC.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Gets a random int from 1 to 100 into the AC
 */
void CPU::getRand()
{
    AC.setValue(rand() % 100 + 1);

    PC.setValue(PC.getValue() + 1);
}

/**
 *  If port=1, writes AC as an int to the screen
 *  If port=2, writes AC as a char to the screen
 */
void CPU::put(int port)
{
    int value = AC.getValue();
    IOModule::display(value, port);

    PC.setValue(PC.getValue() + 2);
}

/**
 *  Adds the value in X to the AC
 */
void CPU::addX()
{
    int val = AC.getValue();
    AC.setValue(val + X.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Adds the value in Y to the AC
 */
void CPU::addY()
{
    int val = AC.getValue();
    AC.setValue(val + Y.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Subtracts the value in X from the AC
 */
void CPU::subX()
{
    int val = AC.getValue();
    AC.setValue(val - X.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Subtracts the value in Y from the AC
 */
void CPU::subY()
{
    int val = AC.getValue();
    AC.setValue(val - Y.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Copies the value in the AC to X
 */
void CPU::copyToX()
{
    X.setValue(AC.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Copies the value in X to the AC
 */
void CPU::copyFromX()
{
    AC.setValue(X.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Copies the value in the AC to Y
 */
void CPU::copyToY()
{
    Y.setValue(AC.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Copies the value in Y to the AC
 */
void CPU::copyFromY()
{
    AC.setValue(Y.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Copies the value in the AC to SP
 */
void CPU::copyToSP()
{
    SP.setValue(AC.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Copies the value in SP to the AC
 */
void CPU::copyFromSP()
{
    AC.setValue(SP.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Jumps to the address
 */
void CPU::jump(int address)
{
    PC.setValue(address);
}

/**
 *  Jumps to the address only if the value in the AC is zero
 */
void CPU::jumpIfEqual(int address)
{
    if (AC.getValue() == 0)
    {
        jump(address);
    }
    else
    {
        PC.setValue(PC.getValue() + 1);
    }
}

/**
 *  Jumps to the address only if the value in the AC is not zero
 */
void CPU::jumpIfNotEqual(int address)
{
    if (AC.getValue() != 0)
    {
        jump(address);
    }
    else
    {
        PC.setValue(PC.getValue() + 1);
    }

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Pushes return address onto stack, jump to the address
 */
void CPU::call(int address)
{
    SP.setValue(memMgr.read(address));
    memMgr.write(SP.getValue(), AC.getValue());

    PC.setValue(PC.getValue() + 1);
    //jump(address);

}

/**
 *  Pops return address from the stack, jump to the address
 */
void CPU::ret(int address)
{
    int value = memMgr.read(memMgr.read(address));

    memMgr.write(value, 0);
    SP.setValue(SP.getValue() + 1);

    PC.setValue(PC.getValue() + 1);
    //jump(address);
}

/**
 *  Increments the value in X
 */
void CPU::incX()
{
    X.setValue(X.getValue() + 1);

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Decrements the value in X
 */
void CPU::decX()
{
    X.setValue(X.getValue() - 1);

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Pushes AC onto stack
 */
void CPU::push()
{
    SP.setValue(SP.getValue() - 1);
    memMgr.write(SP.getValue(), AC.getValue());

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Pops from stack into AC
 */
void CPU::pop()
{
    int value = memMgr.read(SP.getValue());
    AC.setValue(value);

    memMgr.write(SP.getValue(), 0);
    SP.setValue(SP.getValue() + 1);

    PC.setValue(PC.getValue() + 1);
}

/**
 *  Sets system mode, switch stack, push SP and PC, set new SP and PC
 */
void CPU::interrupt()
{
    // TBD
}

/**
 *  Restores registers, set user mode
 */
void CPU::returnInterrupt()
{
    // TBD
}

/**
 *  Ends execute
 */
void CPU::endExecute()
{
    isFinished = true;
}

CPU::~CPU()
{

}
