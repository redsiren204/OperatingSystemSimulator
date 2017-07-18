#include "Memory.h"
#include "InvalidMemoryAddress.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Memory::Memory()
{
    /**
     *  Initializes memory
     */
    for(int i = 0; i < MEMORY_MAXIMUM_SIZE; i++)
    {
        memory[i] = 0;
    }
}

int Memory::read(int address)
{
    return memory[address];
}

void Memory::write(int address, int data)
{
    /**
     *  Checks the address in user program or not
     *  If it tries to access system memory, throw a Invalid memory address exception
     */
    if (address > USER_PROGRAM_ADDRESS) {
        throw InvalidMemoryAddress();
    }

    memory[address] = data;
}

void Memory::loadProgram(string programName)
{
    program = Program();

    list<Instruction> instructions;

    /**
     *  Loads program from text file to memory
     */
    address = 0;

    int instr;
    char check;
    string unparsed;
    ifstream inputFile;
    inputFile.open(programName.c_str(), ifstream::in);

    if (!inputFile)
    {
        cout << "Error reading file" << endl;
    }

    while (!inputFile.eof())
    {
        /**
         *  Gets a line from file
         */
        getline(inputFile, unparsed);
        check = unparsed[0];

        /**
         *  If string length equal to zero, then move to next line
         */
        if (unparsed.length() == 0)
        {
            continue;
        }

        /**
         *  Parses to integer
         */
        instr = parseInstruction(unparsed);

        /**
         *  Multiple checks to see if instruction is address might be repetitive
         */
        if ((address == instr && check == '.') || instr == -1)
        {
            continue;
        }

        /**
         *  Memory array at address value saves the instruction
         */
        memory[address] = instr;

        /**
         *  Increments address before reading next line in file
         */
        address++;
    }
    cout << endl;

    /**
     *  Instruction list
     */
    program.setInstructions(instructions);
}

int Memory::parseInstruction(string parseIt)
{
    bool flag = true;
    string insStr;
    int insCode;
    int startIdx = 0;
    char check = parseIt[0];

    /**
     *  Checks if it is a space, then return -1
     */
    if (isspace(check) || check == '/')
	{
		return -1;
	}

	/**
	 *  If it is a '.' set flag to false and start read at char[1]
	 */
	if (check == '.')
    {
        flag = false;
        startIdx = 1;
    }

    int endIdx = parseIt.find(" ");
    insStr = parseIt.substr(startIdx, endIdx);

    /**
     *  Converts the string into an integer value
     */
    istringstream convert(insStr);
    convert >> insCode;

    /**
     *  If flag is set to false, set the address to integer value
     */
    if (flag == false)
    {
        address = insCode;
    }

    /**
     *  Returns the integer value to be further processed
     */
    return insCode;
}

Program Memory::getProgram()
{
    return this->program;
}

void Memory::clean()
{
    int memSize = sizeof(MEMORY_MAXIMUM_SIZE);

    for(int i = 0; i < memSize; i++) {
        memory[i] = 0;
    }
}

Memory::~Memory()
{

}
