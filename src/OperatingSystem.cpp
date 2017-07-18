#include "OperatingSystem.h"
#include "Memory.h"
#include "CPU.h"

OperatingSystem::OperatingSystem()
{

}

OperatingSystem::OperatingSystem(string program, int timeStep)
{
    /**
     *  Initializes CPU and memory
     */
    Memory memory;
    memory.loadProgram(program);

    cpu = CPU(memory, timeStep);
}

void OperatingSystem::run()
{
    /**
     *  Runs the operating system
     */
    cpu.run();
}

OperatingSystem::~OperatingSystem()
{

}
