#ifndef MEMORY_H
#define MEMORY_H


#include <string>

using namespace std;
#define SIZE_OF_MEMORY 2000

/**
 * Provide object as memory computer
 *
 * @author : BinhNT
 */
class Memory
{
    public:
        Memory();
        virtual ~Memory();
        int memory[SIZE_OF_MEMORY];

        /**
         * Initiate memory's address.
         * Read data from program file after that write to memory
         * @param filePath program file stored code of instruction
         *
         */
        void initialize(string filePath);

        /**
         * Check user memory if full or not
         * Return state of address in memory
         * @param address memory address
         * @return If user memory is full return true, opposite return false
         */
        bool isFullUserMemory(int address);

        /**
         * Get a instruction from a line
         * @param line will be parser to get instruction information
         * @return code of instruction
         */
        int getInstructionFromLine(string line);

        /**
         * Check line is command line or not
         * @param line will be parser to get instruction information
         * @return statement after check line
         * true if line is a command line
         * false if line is not command line
         */
        bool isCommandLine (string line);

        /**
         * Check line is empty line or not
         * @param line will be parser to get instruction information
         * @return statement after check line
         * true if line is not empty line
         * false if line is empty line
         */
        bool isNotEmptyLine (string line);

        /**
         * Read from memory at specific address and return value
         * @param address will be read
         * @return value is read at specific address
         */
        int read(int address);

        /**
         * Write from memory at specific address and return value
         * @param address will be read
         * @param value is write at specific address
         */
        void write(int address, int value);

        /**
         * Remove whitespace of string (end/begin line)
         *
         */
        string trim (string line);

    protected:

    private:



};

#endif // MEMORY_H
