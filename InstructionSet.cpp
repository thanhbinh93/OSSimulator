#include "InstructionSet.h"

InstructionSet::InstructionSet()
{
    //ctor
}

InstructionSet::InstructionSet(int optCode, int numOfOperand)
{
    this->optCode = optCode;
    this->numOfOperand = numOfOperand;
}

InstructionSet::~InstructionSet()
{
    //dtor
}
