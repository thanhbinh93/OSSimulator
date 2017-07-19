#include "OperatingSystem.h"
#include "CPU.h"
#include "Memory.h"

using namespace std;

OperatingSystem::OperatingSystem()
{

}

OperatingSystem::~OperatingSystem()
{
    //dtor
}


void OperatingSystem::loadProgramForMemory(string filePath)
{
    memory.initialize(filePath);
}


void OperatingSystem::start(int tickTime)
{
    cpu = new CPU(memory, tickTime);
    cpu->start();
}
