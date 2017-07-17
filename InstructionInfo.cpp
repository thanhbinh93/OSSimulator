#include "InstructionInfo.h"

using namespace std;

InstructionInfo::InstructionInfo()
{
    //ctor
}

InstructionInfo::InstructionInfo(int code, int num)
{
    this->instructionCode = code;
    this->numOfOperands = num;
}

InstructionInfo::~InstructionInfo()
{
    //dtor
}

int InstructionInfo::getInstructionCode()
{
    return this->instructionCode;
}

void InstructionInfo::setInstructionCode(int code)
{
    this->instructionCode = code;
}

int InstructionInfo::getNumOfOperands()
{
    return this->numOfOperands;
}

void InstructionInfo::setNumOfOperands(int num)
{
    this->numOfOperands = num;
}
