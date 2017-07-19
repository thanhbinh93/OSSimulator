#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H

#include "CPU.h"
#include "Memory.h"

using namespace std;

/**
 * Control communicate between CPU and Memory
 *
 * @author
 */
class OperatingSystem
{
    public:
        OperatingSystem();
        virtual ~OperatingSystem();

        /**
        * Call load data which is read from file to memory
        */
        void loadProgramForMemory (string filePath);

        /**
        * Start process of CPU
        */
        void start(int tickTime);

    protected:

    private:
        Memory memory;
        CPU* cpu;
};

#endif // OPERATINGSYSTEM_H
