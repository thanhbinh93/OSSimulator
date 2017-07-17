#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include "Memory.h"
//#include "InstructionSet.h"

/**
 * Control unit system class
 * It will have these registers:  PC, SP, IR, AC, X, Y.
 * It will run the user program at address 0.
 * Instructions are fetched into the IR from memory.
 * The operand can be fetched into a local variable.
 * Each instruction will be executed before the next instruction is fetched.
 * The user stack resides at the end of user memory and grows down toward address 0.
 * The system stack resides at the end of system memory and grows down toward address 0.
 * There is no hardware enforcement of stack size.
 * The program ends when the End instruction is executed.
 *
 * @author
 */
class CPU
{
    public:
        CPU();
        virtual ~CPU();

        /**
         * Initial CPU
         *
         */
        CPU(Memory memory);

        /**
         * 1. Initial registers
         * 2. Fetch instruction from memory
         * 3. Decode instruction
         * 4. Execute instruction
         * 5. Set timer after each instruction
         *
         */
         void start();

    protected:

    private:
        /**
         * CPU state
         *
         */
        int USER_MODE = 0;

        /**
         * CPU state
         *
         */
        int SYSTEM_MODE = 1;

        /**
         * User program address start
         *
         */
        int USER_PROGRAM_ADDRESS = 0;

        /**
         * State CPU
         *
         */
        int CPUState;

        /**
         * System program address start
         *
         */
        int SYSTEM_PROGRAM_ADDRESS = 1000;

        /**
         * Start timer process address
         *
         */
        int TIMER_PROCESS_ADDRESS = 1000;

        /**
         * Start interrupt process address
         *
         */
        int INTERUPT_PROCESS_ADDRESS = 1500;

        /**
         * File registers
         *
         */
         int PC, SP, IR, AC, X, Y;

         /**
         * Flag finish a program
         *
         */
         bool isEndProgram;

         /**
         * Instruction and Data memory
         *
         */
         Memory memory;

         /**
         * initial value for registers
         *
         */
         void initFileRegisters();

         /**
         * 1.Fetched instruction from memory and assign into IR register
         * 2. Increase point instruction
         *
         */
         void fetchInstruction();

         /**
         * Execute instruction
         *
         */
         //void execute(InstructionSet instructionSet);

         /**
         * Execute Load Value instruction
         * Load the value into the AC
         *
         */
         void loadValue(int value);

         /**
         * Load the value at the address into the AC
         *
         */
         void loadAddress(int address);

         /**
         * Load the value from the address found
         * in the given address into the AC
         *(for example, if LoadInd 500, and 500 contains 100, then load from 100).
         *
         */
         void loadIndAddr(int indAddr);

         /**
         * Load the value at (address+X) into the AC
         *(for example, if LoadIdxX 500, and X contains 10, then load from 510).
         *
         */
         void loadIdxXAddr(int addr);

         /**
         * Load the value at (address+Y) into the AC
         *
         */
         void loadIdxYAddr(int addr);

         /**
         * Load from (Sp+X) into the AC
         *
         */
         void loadSpx();

         /**
         * Store the value in the AC into the address
         *
         */
         void storeAddr(int addr);

         /**
         * Gets a random int from 1 to 100 into the AC
         *
         */
         void get();

         /**
         * If port=1, writes AC as an int to the screen
         * If port=2, writes AC as a char to the screen
         *
         */
         void putPort(int portID);

         /**
         * Add the value in X to the AC
         *
         */
         void addX();

         /**
         * Add the value in Y to the AC
         *
         */
         void addY();

         /**
         * Subtract the value in X from the AC
         *
         */
         void subX();

         /**
         * Subtract the value in Y from the AC
         *
         */
         void subY();

         /**
         * Copy the value in the AC to X
         *
         */
         void copyToX();

         /**
         * Copy the value in X to the AC
         *
         */
         void copyFromX();

         /**
         * Copy the value in the AC to Y
         *
         */
         void copyToY();

         /**
         * Copy the value in Y to the AC
         *
         */
         void copyFromY();

         /**
         * Copy the value in AC to the SP
         *
         */
         void copyToSp();

         /**
         * Copy the value in SP to the AC
         *
         */
         void copyFromSp();

         /**
         * Jump to the address
         *
         */
         void jumpAddr(int addr);

         /**
         * Jump to the address only if the value in the AC is zero
         *
         */
         void jumpIfEqual(int addr);

         /**
         * Jump to the address only if the value in the AC is not zero
         *
         */
         void jumpIfNotEqual(int addr);

         /**
         * Push return address onto stack, jump to the address
         *
         */
         void callAddr(int addr);

         /**
         * Pop return address from the stack, jump to the address
         *
         */
         void ret();

         /**
         * Increment the value in X
         *
         */
         void incX();

         /**
         * Decrement the value in X
         *
         */
         void decX();

         /**
         * Push AC onto stack
         *
         */
         void executePush();

         /**
         * Pop from stack into AC
         *
         */
         void executePop();

         /**
         * Set system mode, switch stack, push SP and PC, set new SP and PC
         *
         */
         void executeInt();

         /**
         * Restore registers, set user mode
         *
         */
         void executeIret();

         /**
         * End execution
         *
         */
         void executeEnd();

         /**
         * Process timer interrupt
         *
         */
         void processTimerInterrupt();

         /**
         * Process program interrupt
         *
         */
         void processProgramInterrupt();

         /**
         * read from memory
         * @param addr
         */
         int readMemory(int addr);

         /**
         * write to memory for common operation
         * @param addr
         * @param data
         */
         void writeMemory(int addr, int  data);

         /**
         * stop program
         */
         void endProgram();

         /**
         * A timer will interrupt the processor after every X instruction,
         * where X is a command-line parameter.
         *
         */
         void processingTimerInterrupt();

         /**
         * System call using the int instruction.
         *
         */
         void processingProgramInterrupt();

         /**
         * Store system state before interrupt or function call
         *
         */
         void pushRegistersIntoSystemStack();

         /**
         * Restore system state after interrupt or function call
         *
         */
         void popFromSystemStackIntoRegisters();

         /**
         * Return from a interrupt process
         *
         */
         void restoreRegisters();

         /**
         * write to system stack memory
         * @param addr
         * @param data
         */
         void writeSystemStackMemory(int addr, int data);

         /**
         * write to system stack memory
         * @param addr
         * @param data
         */
         //Instruction decodeInstruction();

};

#endif // CPU_H
