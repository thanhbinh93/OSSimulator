#include <iostream>
#include <ctime>

#include "CPU.h"
#include "IllegalAccessMemoryException.h"
#include "IndexOutOfRangeException.h"
#include "NotSupportedInstructionException.h"
#include "Instruction.h"
#include "InstructionSet.h"


using namespace std;

CPU::CPU()
{
    //ctor
}

CPU::~CPU()
{
    //dtor
}

CPU::CPU(Memory memory, int tickTime)
{
    this->memory = memory;
    // initial timer with tick time
    //tickTime = 30;
    this->timer.setTickTime(tickTime);
    this->timer.reset();
    // set end flag to flase
    isEndProgram = false;
}

void CPU::start()
{
    initFileRegisters();
    // reset system state
    CPUState = USER_MODE;

    while(!isEndProgram)
    {
        this->fetchInstruction();
        InstructionSet instructionSet  = this->decodeInstruction();
        executeInstruction(instructionSet);

        // Processing timer interrupt
        timer.updateTimer();
        if(timer.isHandlerTimerInterrupt()){
            processingTimerInterrupt();
            // reset counter
            timer.reset();
        }
    }
}

void CPU::executeInstruction(InstructionSet insSet)
{
    Instruction insInfo;

    switch(insSet.optCode)
    {
        case LOAD_VALUE:
            loadValue(insSet.operands[0]);
            break;
        case LOAD_ADDR:
            loadAddress(insSet.operands[0]);
            break;
        case LOAD_IND_ADDR:
            loadIndAddr(insSet.operands[0]);
            break;
        case LOAD_IDX_X_ADDR:
            loadIdxXAddr(insSet.operands[0]);
            break;
        case LOAD_IDX_Y_ADDR:
            loadIdxYAddr(insSet.operands[0]);
            break;
        case LOAD_SPX:
            loadSpx();
            break;
        case STORE_ADDR:
            storeAddr(insSet.operands[0]);
            break;
        case GET:
            get();
            break;
        case PUT_PORT:
            putPort(insSet.operands[0]);
            break;
        case ADD_X:
            addX();
            break;
        case ADD_Y:
            addY();
            break;
        case SUB_X:
            subX();
            break;
        case SUB_Y:
            subY();
            break;
        case COPY_TO_X:
            copyToX();
            break;
        case COPY_FROM_X:
            copyFromX();
            break;
        case COPY_TO_Y:
            copyToY();
            break;
        case COPY_FROM_Y:
            copyFromY();
            break;
        case COPY_TO_SP:
            copyToSp();
            break;
        case COPY_FROM_SP:
            copyFromSp();
            break;
        case JUMP_ADDR:
            jumpAddr(insSet.operands[0]);
            break;
        case JUMP_IF_EQUAL:
            jumpIfEqual(insSet.operands[0]);
            break;
        case JUMP_IF_NOT_EQUAL:
            jumpIfNotEqual(insSet.operands[0]);
            break;
        case CALL_ADDR:
            callAddr(insSet.operands[0]);
            break;
        case RET:
            ret();
            break;
        case INCX:
            incX();
            break;
        case DECX:
            decX();
            break;
        case PUSH:
            executePush();
            break;
        case POP:
            executePop();
            break;
        case INT:
            executeInt();
            break;
        case IRET:
            executeIret();
            break;
        case END:
            executeEnd();
            break;
        default:
            throw NotSupportedInstructionException();
    }

}

void CPU::initFileRegisters()
{
    this->PC = 0;
    this->AC = 0;
    this->X  = 0;
    this->Y  = 0;
    this->SP = 2000;
}

void CPU::fetchInstruction()
{
    // read next instruction in memory at the address in PC
    // store the instrucion in IR
    this->IR = this->readMemory(this->PC);
    // increase PC
    this->PC++;
}

InstructionSet CPU::detectIntructionSet()
{
    Instruction instructionInfo;
    InstructionSet instructSet;
    bool isDetect = true;
    int i = 0;
    int len =  sizeof(instructionInfo.instructions) / sizeof (instructionInfo.instructions[0]);
    while (isDetect && i < len) {

        int tempCode = instructionInfo.instructions[i].optCode;

        if(tempCode == this->IR)
        {
            instructSet = instructionInfo.instructions[i];
            isDetect = false;
        }

        i++;
    }

    // Not supported instruction
    if (instructSet.optCode <= 0)
    {
        throw NotSupportedInstructionException();
    }
    else
    {
        return instructSet;
    }

}

InstructionSet CPU::decodeInstruction()
{
    InstructionSet instruction;
    instruction = this->detectIntructionSet();

    // Decode instruction
    for(int i = 0; i < instruction.numOfOperand; i++){
        int operand = this->readMemory(this->PC);
        this->PC++;
        instruction.operands[i] = operand;
    }

    return instruction;
}

void CPU::loadValue(int value)
{
    this->AC = value;
}

void CPU::loadAddress(int addr)
{
    this->AC = this->readMemory(addr);
}

void CPU::loadIdxXAddr(int addr)
{
    // read memory at addr + X
    int value = this->readMemory(addr + this->X);
    this->AC = value;
}

void CPU::loadIndAddr(int indAddr)
{
    // read memory at the indAdrr to get the direct addr
    int realAddr = this->readMemory(indAddr);
    // read memory at the direct addr to get the value
    // store the value to AC
    this->AC = this->readMemory(realAddr);
}

void CPU::loadIdxYAddr(int addr)
{
    // read memory at addr + Y
    int value = this->readMemory(addr + this->Y);
    this->AC = value;
}

void CPU::loadSpx()
{
    // read memory at SP + X
    // store the read value to AC
    this->AC = this->readMemory(this->SP - this->X);
}

void CPU::storeAddr(int addr)
{
    if (addr < 0 || addr > SIZE_OF_MEMORY)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        // write value of AC to addr
        this->writeMemory(addr, this->AC);
    }

}

void CPU::get()
{
    // random number from 1 to 100 to AC
    int low = 1;
    int high = 100;
    this->AC = rand() % high + low;
    srand(time(NULL));
}

void CPU::putPort(int portId)
{
     if (portId ==1)
        {
            cout << this->AC << endl;
        }
        else if (portId == 2)
        {
            cout << (char)this->AC << endl;
        }
}

void CPU::addX()
{
    this->AC += this->X;
}

void CPU::addY()
{
    this->AC += this->Y;
}

void CPU::subX()
{
    this->AC -= this->X;
}

void CPU::subY()
{
    this->AC -= this->Y;
}

void CPU::copyToX()
{
    this->X = this->AC;
}

void CPU::copyFromX()
{
    this->AC = this->X;
}

void CPU::copyToY()
{
    this->Y = this->AC;
}

void CPU::copyFromY()
{
    this->AC = this->Y;
}

void CPU::copyToSp()
{
    this->SP = this->AC;
}

void CPU::copyFromSp()
{
    this->AC = this->SP;
}

void CPU::jumpAddr(int addr)
{
    this->PC = addr;
}

void CPU::jumpIfEqual(int addr)
{
    if(this->AC == 0)
    {
        this->PC = addr;
    }
}

void CPU::jumpIfNotEqual(int addr)
{
    if(this->AC != 0)
    {
        this->PC = addr;
    }
}

void CPU::callAddr(int addr)
{
    // Push system state
    // Jump to addr
    this->pushRegistersIntoSystemStack();
    this->PC = addr;
}

void CPU::ret()
{
    // Restore state of file registers
    this->popFromSystemStackIntoRegisters();
}

void CPU::incX()
{
    this->X++;
}

void CPU::decX()
{
    this->X--;
}

void CPU::executePush()
{

    // write AC to memory at address in SP
    this->writeSystemStackMemory(this->SP, this->AC);

    this->SP--;
}

void CPU::executePop()
{
    // SP++
    // read AC from memory at address in SP
    this->SP++;
    this->AC = this->readMemory(this->SP);
}

void CPU::executeInt()
{
    this->processingProgramInterrupt();
}

void CPU::executeIret()
{
    this->restoreRegisters();
}

void CPU::executeEnd()
{
    // set end of program flag to true
    endProgram();
}

void CPU::endProgram()
{
    this->isEndProgram = true;
}

int CPU::readMemory(int addr)
{
    return this->memory.read(addr);
}

void CPU::writeMemory(int addr, int data)
{
    if(addr <0 ) throw IndexOutOfRangeException();
    if(addr >= SYSTEM_PROGRAM_ADDRESS) throw IllegalAccessMemoryException();
    this->memory.write(addr, data);
}

void CPU::processingTimerInterrupt()
{
    if (this->CPUState != SYSTEM_MODE) {
        // push system state
        this->pushRegistersIntoSystemStack();

        // update PC = TIMER_PROCESS_ADDRESS
        this->PC = TIMER_PROCESS_ADDRESS;

        if(this->isNeedRestoreRegister(this->PC)){
            this->popFromSystemStackIntoRegisters();
        }
        this->CPUState = SYSTEM_MODE;
    }
}

bool CPU::isNeedRestoreRegister(int addr)
{
    Instruction instructionInfo;

    int value = this->readMemory(addr);

    bool isValidCode = false;
    for (int i = 0; i < NUMBER_OF_INSTRUCTION; i++)
    {
        isValidCode = instructionInfo.instructions[i].optCode == value;
    }

    return !isValidCode;
}

void CPU::processingProgramInterrupt()
{
    if (this->CPUState != SYSTEM_MODE) {
        // push system state
        this->pushRegistersIntoSystemStack();

        // update PC = TIMER_PROCESS_ADDRESS
        this->PC = INTERUPT_PROCESS_ADDRESS;

        this->CPUState = SYSTEM_MODE;
    }
}

void CPU::pushRegistersIntoSystemStack()
{
    // Switch system stack

    // write PC to memory at the address of SP in system memory stack
    writeSystemStackMemory(this->SP, PC);

    // write SP to memory at the address of SP - 1 in system memory stack
    writeSystemStackMemory(this->SP - 1, SP);

    // write AC to memory at the address of SP - 2 in system memory stack
    writeSystemStackMemory(this->SP - 2, AC);

    // write X to memory at the address of SP - 3 in system memory stack
    writeSystemStackMemory(this->SP - 3, X);

    // write Y to memory at the address of SP - 4 in system memory stack
    writeSystemStackMemory(this->SP - 4, Y);


    this->SP = this->SP - 5;
}

void CPU::popFromSystemStackIntoRegisters()
{
    // Restores state file registers
    // SP = SP + 5
    // read new PC from memory at the address of SP in system memory stack
    // read new SP from memory at the address of SP - 1 in system memory stack
    // read new AC from memory at the address of SP - 2 in system memory stack
    // read new X from memory at the address of SP - 3 in system memory stack
    // read new Y from memory at the address of SP - 4 in system memory stack
    this->SP = this->SP + 5;
    this->PC = readMemory(this->SP);
    this->SP = readMemory(this->SP - 1);
    this->AC = readMemory(this->SP - 2);
    this->X = readMemory(this->SP - 3);
    this->Y = readMemory(this->SP - 4);
}

void CPU::restoreRegisters()
{
    if (this->CPUState == SYSTEM_MODE){
        this->popFromSystemStackIntoRegisters();
        this->CPUState = USER_MODE;
    }
}

void CPU::writeSystemStackMemory(int addr, int data)
{
    if(addr < SYSTEM_PROGRAM_ADDRESS) throw IllegalAccessMemoryException();
    this->memory.write(addr, data);
}
