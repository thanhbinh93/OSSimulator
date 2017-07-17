#include "CPU.h"

CPU::CPU()
{
    //ctor
}

CPU::~CPU()
{
    //dtor
}

CPU::CPU(Memory memory)
{
    this->memory = memory;
    // set end flag to flase
    isEndProgram = false;
}

void CPU::start()
{
    initFileRegisters();
    // reset system state
    CPUState = USER_MODE;

    while(isEndProgram == false)
    {
        this->fetchInstruction();
        //this->decodeInstruction();
        //executeInstruction(instruction);
    }

}

//void CPU::executeIntruction(InstructionSet instructionSet)
//{
//
//}

void CPU::initFileRegisters()
{
    this->PC = 0;
    this->AC = 0;
    this->X = 0;
    this->Y = 0;
    this->SP = 2000;
}

void CPU::fetchInstruction()
{
    // read next instruction in memory at the address in PC
    // store the instrucion in IR
    this->IR  = this->readMemory(this->PC);
    // increase PC
    this->PC++;
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
    // write value of AC to addr
    this->writeMemory(addr, this->AC);
}

void CPU::get()
{
    // random number from 1 to 100 to AC
    int low = 1;
    int high = 100;
    this->AC = rand() % high + low;
}

void CPU::putPort(int portId)
{

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
    this->memory.write(addr, data);
}

void CPU::processingTimerInterrupt()
{
    if (this->CPUState != SYSTEM_MODE) {
        // push system state
        this->pushRegistersIntoSystemStack();
        // update PC = TIMER_PROCESS_ADDRESS
        this->PC = TIMER_PROCESS_ADDRESS;
        this->CPUState = SYSTEM_MODE;
    }
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
    // write SP to memory at the address of SP - 1 in system memory stack
    // write AC to memory at the address of SP - 2 in system memory stack
    // write X to memory at the address of SP - 3 in system memory stack
    // write Y to memory at the address of SP - 4 in system memory stack
    // SP = SP - 5
    writeSystemStackMemory(this->SP, PC);
    writeSystemStackMemory(this->SP - 1, SP);
    writeSystemStackMemory(this->SP - 2, AC);
    writeSystemStackMemory(this->SP - 3, X);
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
    this->memory.write(addr, data);
}
