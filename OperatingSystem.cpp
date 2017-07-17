#include "OperatingSystem.h"

OperatingSystem::OperatingSystem()
{
    memory = new Memory(SYSTEM_MEMORY_SIZE);
    cpu = new CPU(memory);
}

OperatingSystem::~OperatingSystem()
{
    //dtor
}

/**
* Load program data which is parsed from file to memory
*/
void OperatingSystem::loadProgramForMemory(List<DataSegement> programData)
{
    memory.load(programData);
}

/**
* Clear program data which is stored in memory
*/
void OperatingSystem::cleanMemory ()
{
    memory.clean();
}

/**
* Set time tick for CPU
*/
void OperatingSystem::setTimerTick (int tickTime)
{
    cpu.setTimerPeriod(tickTime);
}

/**
* Start process for CPU
*/
void OperatingSystem:start()
{
    cpu.start();
}
